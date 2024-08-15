    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    #define INFINITY 999
    clock_t st,end;

    int min(int a,int b){
        return a<b?a:b;
    }

    void floyd(int p[10][10],int n){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
                }
            }
        }
    }

    int main(){
        int n,p[10][10];
        int i,j;
        printf("Enter no of nodes:\n");
        scanf("%d" , &n);

        printf("Enter the matrix\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&p[i][j]);
            }
        }

        st=clock();
        floyd(p,n);
        end=clock();

        printf("The Resultant matrix is:\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                
                    printf("%d\t", p[i][j]);
                }
            
            
        }
    printf("TC:%d",(end-st));
    return 0;
    }
