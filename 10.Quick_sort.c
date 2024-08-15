#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
int part(int a[], int low, int high)
{
    int i, temp, key;
    key=a[low];
    i=low;
    for(int j=low+1; j<=high; j++){
        if(a[j]<key){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[i];
    a[i]=temp;
    return i;
}
void qs(int a[], int low, int high)
{
    int mid;
    if(low<high){
        mid=part(a, low, high);
        qs(a, low, mid-1);
        qs(a, mid+1, high);
    }
}
int main()
{
    int a[MAX], n;
    printf("Enter the no of elements\n");
    scanf(" %d", &n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
        a[i]=rand()%1000;
    printf("Entered array is\n");
    for(int i=0; i<n; i++)
        printf(" %d", a[i]);
    qs(a, 0, n-1);
    printf("\nsorted array is\n");
    for(int i=0; i<n; i++)
        printf(" %d", a[i]);
}
