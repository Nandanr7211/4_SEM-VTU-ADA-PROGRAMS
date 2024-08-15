#include<stdio.h>
#include<stdlib.h>

int indeg[10],flag[10],a[10][10],n;

void topology(){
  int i,j,m=0,cnt=0;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            indeg[i]=0;
            flag[i]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            indeg[j]+=a[i][j];
        }
    }

    while(cnt<n){

        for(i=0;i<n;i++){
            if(indeg[i]==0 && flag[i]==0){
                printf("\n%d",i+1);
                cnt++;
                flag[i]=1;
                for(j=0;j<n;j++){
                    if(a[i][j]==1){
                        indeg[j]--;
                    }
                }
            }
        }
    }
}

int main(){
    
int i,j;
    printf("Enter no of nodes");
    scanf("%d",&n);

    printf("Enetr the adaj matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    topology();
 return 0;
}
