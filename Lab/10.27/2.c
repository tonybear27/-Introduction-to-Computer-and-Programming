#include <stdio.h>
#include <string.h>

const char key[]="the quick brown fox jumps over the lazy dog";
char sentence[111][88];
char maps[128];

int check(char str[])
{
    if(strlen(key)!=strlen(str))
        return 0;
    
    for(int i=0; str[i]; i++)
        if(key[i]==' ' && str[i]!=' ')
            return 0;
    
    for(int i=0; i<128; i++)
        maps[i]=0;
    
    for(int i=0; str[i]; i++)
        if(maps[str[i]] && maps[str[i]]!=key[i])
            return 0;
        else    
            maps[str[i]]=key[i];
    
    return 1;
}

int main()
{
    int times;
    scanf("%d\n", &times);
    while(times--)
    {
        int size=0;
        while(gets(sentence[size]) && sentence[size][0])
            size++;
        
        int flag=0;

        for(int i=0; i<size; i++)
            if(check(sentence[i]))
            {
                flag=1;
                break;
            }
        
        if(!flag)
            puts("No solution.");
        else
        {
            for(int i=0; i<size; i++)
            {
                for(int j=0; sentence[i][j]; j++)
                    printf("%c", maps[sentence[i][j]]);
                puts("");
            }
        }

        if(times)
            puts("");
    }

    return 0;
}