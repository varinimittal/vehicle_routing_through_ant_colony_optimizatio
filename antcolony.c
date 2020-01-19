#include <stdio.h>
#include <math.h>

int main()
{
    int n,m,t,pos;//where m= number of ants and n = no of cities
    printf("enter the no of cities= ");
    scanf("%d",&n);
    m=n;
    t=1;//intial pheromone
    float a,b;
    a=0.7,b=0.7,pos=0;
    float probability[n];
    float dist_matrix[n][n];
    float pheromone_matrix[n][n];
    float visible_matrix[n][n];
    float visited_edge_matrix[n][n];
   /*Counter variables for the loop*/
   int i, j,k;
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
         printf("Enter value for disp[%d][%d]:", i, j);
         scanf("%f", &dist_matrix[i][j]);
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
         pheromone_matrix[i][j]=t;
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
       int path[n];
   int c,s,co,location=1,inc=0,f=0;
   float sum,maximum;
   c=0;
   s=0;
   for(int g=0;g<n;g++)
                 probability[g]=0;
       while(f<n)
       {
           //change 0 to starting point
           sum=0;
           for(k=0;k<m;k++)
           {
               if(s==k)
               {
                   continue;
               }
               else
               {
                   if(visited_edge_matrix[s][k]!=0 && k!=0) //afterwards change zero to starting point ehich is the number of ant
                   sum+=pow(pheromone_matrix[s][k],a)*pow(visible_matrix[s][k],b);
               }

           }
            for(i=0;i<m;i++)
              {
                  if(s==i)
                  continue;
                  else
                  {
                      if(visited_edge_matrix[s][i]!=0 && i!=0)
                      //afterwards change zero to starting point ehich is the number of ant
                      {
                      probability[c]=pow(pheromone_matrix[s][i],a)*pow(visible_matrix[s][i],b)/sum;
                      position[c]=i;
                      printf("%d ",position[c]);
                      }
                  }
                  printf("\n %f probability",probability[c]);
                  c++;
              }
              //for calculating maximum pheromone concentration
             maximum = probability[0];
              for (co = 1; co <n; co++)
               {
                  if (probability[co] > maximum)
                    {
                     maximum = probability[co];
                      location = co;
                     }
                }

                printf("\nlocation %d",location);
                for(int g=0;g<n;g++)
                {
                    if(g==location)
                    {
                     int l=position[location];
                        visited_edge_matrix[s][l]=0;
                        printf("%d",l);
                        s=position[location];
                        path[inc]=position[location];
                    }
                }
                 for(int g=0;g<n;g++)
                 probability[g]=0;
                f++;


       }


   return 0;
}



