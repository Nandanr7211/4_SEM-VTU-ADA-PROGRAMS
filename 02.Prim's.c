#include<stdio.h>
#include<stdlib.h>

int i,j,a,b,u,v,n,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];

void main(){
   printf("nodes");
   scanf("%d",&n);

   printf("ENTER MATRIX\n");
   for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
         scanf("%d",&cost[i][j]);
      }
   }
   visited[1]=1;
   while(ne<n){
      for(i=1,min=999;i<=n;i++){
         for(j=1;j<=n;j++){
            if(cost[i][j]<min){
               if(visited[i]!=0){
                  min=cost[i][j];
                  a=u=i;
                  b=v=j;
               }
            }

         }
      }
      if(visited[u]==0 || visited[v]==0){
         printf("%d Edge %d:%d cost:%d\n",ne++,a,b,min);
         mincost+=min;
         visited[b]=1;
      }
   cost[b][a]=cost[a][b]=999;
   }
 printf("MST:%d",mincost);
}
