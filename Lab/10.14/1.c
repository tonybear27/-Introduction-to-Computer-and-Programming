#include <stdio.h>

int main()
{
    int ans=0;
    int a, b;
    char c;

    scanf("%d %c %d", &a, &c, &b);

    if(c=='/' && b==0)
        printf("Calculate cannot handle!");
    else
    {
        if(c=='+')
            ans=a+b;
        else if(c=='-')
            ans=a-b;
        else if(c=='*')
            ans=a*b;
        else    
            ans=a/b;
        
        printf("%d", ans);
    }

    return 0;
}