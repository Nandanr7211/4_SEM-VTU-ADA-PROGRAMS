    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    #define INFINITY 999
    clock_t st,end;

int i,j;

    void floyd(int p[10][10],int n){

      for(int k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                
                    p[i][j]=p[i][j]||(p[i][k]&&p[k][j]);
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
