#include<stdio.h>
#include<stdlib.h>

int a,b,u,v,i,j,n,ne=1;
int min,mincost=0,adj[10][10],parent[10];

int find(int i){
    while(parent[i])
     i=parent[i];
    return i;
}

int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}



void main(){
    printf("Entere nodes");
    scanf("%d",&n);

    printf("matrix");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
  while(ne<n){
     for(i=1,min=999;i<=n;i++){
        for(j=1;j<=n;j++){
            if(adj[i][j]<min){
                min=adj[i][j];
                a=u=i;
                b=v=j;
            }
        }
     }
    u=find(u);
    v=find(v);
    if(uni(u,v)){
        printf("%d Edge %d,%d cost:%d\n",ne++,a,b,min);
        mincost+=min;
    }
    adj[b][a]=adj[a][b]=999;

  }
  printf("mincost:%d",mincost);
}
