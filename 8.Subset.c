#include<stdio.h>
#include<stdlib.h>

int w[20],x[10],n,m;

void sos(int s,int k,int r){
    int i;
    x[k]=1;
    if(s + w[k]==m){
        printf("Sol vector is \n");
        for(i=1;i<=n;i++){
        printf("%d\t",x[i]);
    }
  printf("\n");
}else{
    if(s + w[k]+w[k+1]<=m)
        sos(s+w[k],k+1,r-w[k]);
    
    if(s + r -  w[k]>=m && s + w[k+1]<=m){
        
        x[k]=0;
        sos(s,k+1,r-w[k]);
    }
}
}

int main(){
    int i,sum=0;

    printf("Enter no of elements");
    scanf("%d",&n);

    printf("enetr the set");
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        sum += w[i];
        x[i]=0;
    }
    printf("Enter the max subset");
    scanf("%d",&m);

    sos(0,1,sum);

    return 0;
}
