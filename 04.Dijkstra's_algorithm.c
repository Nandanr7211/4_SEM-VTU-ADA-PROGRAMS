#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void dijkstra(int n,int cost[10][10],int s,int dist[10]){
    int i,v,min,count=1,visited[10];
    
        for(i=1;i<=n;i++){
            visited[i]=0;
            dist[i]=cost[s][i];
        }
        visited[s]=1;
        dist[s]=0;
    while(count<n){
        min=999;
        for(i=1;i<=n;i++)
           if(dist[i]<min && visited[i]==0){
              min=dist[i];
              v=i;
           }
           visited[v]=1;
           count++;
        for(i=1;i<=n;i++){
            if(dist[i]>dist[v]+cost[v][i]){
                dist[i]=dist[v]+cost[v][i];
            }
        }
    }
}

int  main(){
    int i,j,n,cost[10][10],dist[10],s;

    printf(" Enter the no of nodes:\n");
    scanf("%d",&n);

    printf(" Enter the adj matrix\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
        scanf("%d",&cost[i][j]);
            }
        }
    printf("Enter s source vertex:\n");
    scanf("%d",&s);

    dijkstra(n,cost,s,dist);

    printf(" Shortest path vertex is:\n%d ",s);
    for(i=1;i<=n;i++)
       if(s!=i)
        printf("%d--->%d=%d\n",s,i,dist[i]);

return 0;
}

