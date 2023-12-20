#include <stdio.h>
#include <stdlib.h>

int getMinindex(int* arr, int n)
{
    int res=0;
    for(int i=1; i<n; i++)
        if(arr[res]>arr[i])
            res=i;
    
    return res;
}


int main() 
{
    int testCase;
    int n, k;
    char **ingredient;
    int *frequency;
    scanf("%d", &testCase);
    while (testCase--) 
    {
        scanf("%d %d", &n, &k);

        //Allocate memory
        int* tmp=(int*)malloc(n*sizeof(int));
        frequency=(int*)malloc(n*sizeof(int));
        ingredient=(char**)malloc(n*sizeof(char*));
        for(int i=0; i<n; i++)
        {
            ingredient[i]=(char*)malloc(200*sizeof(char));
            
            //Initialize
            tmp[i]=0;
        }

        //Input data
        for(int i=0; i<n; i++)
        {
            scanf("%s %d", ingredient[i], &frequency[i]);
            tmp[i]=frequency[i];
        }

        //Output
        for(int i=0; i<k; i++)
        {
            int index=getMinindex(frequency, n);
            printf("%d %s\n", frequency[index], ingredient[index]);
            frequency[index]+=tmp[index];          
        }

        //free memory
        free(tmp);
        free(frequency);
        for(int i=0; i<n; i++)
            free(ingredient[i]);
        free(ingredient);
    }
  
  
    return 0;
}