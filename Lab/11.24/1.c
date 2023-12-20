#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int sorting(int* arr, int n)
{
    int cnt=0;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(arr[i]>arr[j])
            {
                cnt++;
                swap(&arr[i], &arr[j]);  
            }
    
    return cnt;
}

int main()
{
    int times;
    scanf("%d", &times);
    while(times--)
    {
        int n;
        scanf("%d", &n);
        int *arr=(int*)(malloc(n*sizeof(int)));
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        printf("%d\n", sorting(arr, n));

        free(arr);
    }

    return 0;
}