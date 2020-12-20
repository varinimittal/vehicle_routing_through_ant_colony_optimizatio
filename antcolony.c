#include <stdio.h>
#include <math.h>
float calculate_min_dist(int n,int m,float p,float probability[n],float dist_matrix[n][n],float pheromone_matrix[n][n],float visible_matrix[n][n]);
int main()
{
    int n,m;//where m= number of ants and n = no of cities
    printf("enter the no of cities= ");
    scanf("%d",&n);
    m=n;
    float p;//probability
    printf("Enter the probability for rate of evaporation of pheromone = ");
    scanf("%f",&p);
    float t=1;//initial pheromone
    float probability[n];
    float dist_matrix[n][n];
    float pheromone_matrix[n][n];
    float visible_matrix[n][n];
   /*Counter variables for the loop*/
   int i, j,k;
   /*k mean cluster points*/
   float x[n];
float y[n];
for(i=0; i<n; i++)
       {
         printf("Enter value for x[%d]:", i);
         scanf("%f", &x[i]);
      }
   for(i=0; i<n; i++) {
         printf("Enter value for y[%d]:", i);
         scanf("%f", &y[i]);
      }
      int one;

for(i=0;i<n;i++)
{
    one=i;
for(j=i;j<n;j++)
{
if(i==j)
{
dist_matrix[i][j]=0;
}
else
{
    one++;
dist_matrix[i][j]=sqrt((x[i]-x[one])*(x[i]-x[one]) + (y[i]-y[one])*(y[i]-y[one]));
dist_matrix[j][i]=dist_matrix[i][j];
}
}
}
   //Displaying array elements
   printf("Distance Matrix:\n");
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
         printf("%f ", dist_matrix[i][j]);
         if(j==(n-1)){
            printf("\n");
         }
      }
   }

   //Visible matrix
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
          if(i==j)
          {
              visible_matrix[i][j]=0;
          }
          else
         visible_matrix[i][j]=1/dist_matrix[i][j];
      }
   }
   printf("Visibility of edge Matrix:\n");
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
         printf("%f ", visible_matrix[i][j]);
         if(j==(n-1)){
            printf("\n");
         }
      }
   }
   //Pheromone matrix
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
          if(i==j)
          {
              pheromone_matrix[i][j]=0;
          }
          else
         pheromone_matrix[i][j]=1;
      }
   }
   printf("Pheromone Matrix:\n");
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
         printf("%f ", pheromone_matrix[i][j]);
         if(j==(n-1)){
            printf("\n");
         }
      }
   }
   for(int z=0;z<n;z++)
{
    printf("\nIteration %d\n",z+1);
        calculate_min_dist(n,m,p,probability,dist_matrix,pheromone_matrix,visible_matrix);
}

   return 0;
}
float calculate_min_dist(int n,int m,float p,float probability[n],float dist_matrix[n][n],float pheromone_matrix[n][n],float visible_matrix[n][n])
{
    int visited_edge_matrix[n][n];
    float submission;
    float a,b;
    a=0.7,b=0.7;
    int s,i,j,k;
int st=0;//starting position
int path[n][n+1];
float total[n];
for(int z=0;z<n;z++)
    total[z]=0;
   while(st<n)
   {
       s=st;
       printf("\npath for ant %d\n",st);
       int no=0;
       //visited edge matrix
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
          if(i==j)
          {
              visited_edge_matrix[i][j]=0;
          }
          else
         visited_edge_matrix[i][j]=1;
      }
   }
       //for calculating probability
       int position[n];
   int c,co,location,inc=1,f=0;
   float sum,maximum;
    int size;
    size=n;
   path[st][0]=st;
   path[st][n]=st;
       while(f<n)
       {
             size--;
             maximum=0;
             location=0;
           sum=0;
           for(k=0;k<m;k++)
           {
               if(s==k)//condition for the same vertex
               {
                   continue;
               }
               else
               {
                   if(visited_edge_matrix[s][k]!=0 && k!=st)
                   sum+=pow(pheromone_matrix[s][k],a)*pow(visible_matrix[s][k],b);
               }

           }
           c=0;
            for(i=0;i<m;i++)
              {
                  if(s==i)
                  continue;
                  else
                  {
                      if(visited_edge_matrix[s][i]!=0 && i!=st)
                      //afterwards change zero to starting point ehich is the number of ant
                      {
                      probability[c]=pow(pheromone_matrix[s][i],a)*pow(visible_matrix[s][i],b)/sum;
                      position[c]=i;
                      c++;
                      }

                  }

              }
               //for calculating maximum pheromone concentration
              maximum=probability[0];
              for (co = 1; co<size; co++)
               {
                  if (probability[co] > maximum)
                    {
                     maximum = probability[co];
                      location = co;
                     }
                }
                //changing visited_edge _matrix and adding the route in path array
                for(int g=0;g<size;g++)
                {
                    if(g==location)
                    {

                        for(int z=0;z<n;z++)
                        visited_edge_matrix[z][position[location]]=0;
                        s=position[location];
                        path[st][inc]=position[location];
                        inc++;

                    }
                }

                f++;
       }
       for(int z=0;z<=n;z++)
       {
            printf(" %d ",path[st][z]);
       }
       //calculating total distance
      for(int z=1;z<=n;z++)
       {
            total[st]=total[st]+dist_matrix[path[st][z-1]][path[st][z]];
       }
       printf("\nTotal = %f",total[st]);
   st++;

   }
    //updating pheromone matrix
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
          if(i==j)
          {
              pheromone_matrix[i][j]=0;
          }
          else
          {
              submission=0;
                    for(int one=0;one<n;one++)
                    {
                        for(int two=1;two<=n;two++)
                        {
                         if(i==path[one][two-1]&&j==path[one][two]||j==path[one][two-1]&&i==path[one][two])
                         {
                             submission=submission+(1/total[one]);
                         }
                         else
                            submission=submission+0;
                        }
                    }
            pheromone_matrix[i][j]=(1.0-p)*pheromone_matrix[i][j]+submission;
          }
      }
   }
   for(int one=0;one<n;one++)
                    {
                        for(int two=1;two<=n;two++)
                        {
                            path[one][two]=0;
                        }
                    }

}



