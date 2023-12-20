#include <stdio.h>
#include <string.h>

int main()
{
    char map[9];
    char sign[9]={'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'};
    int pos;
    int turn=0, win=0;
    
    memset(map, '-', sizeof(map));

    while(turn<9)
    {
        scanf("%d", &pos);
        map[pos]=sign[turn++];

        for(int i=0; i<9; i++)
        {
            printf("%c ", map[i]);
            if(!((i+1)%3))
                printf("\n");
        }

        if(map[0]==map[1] && map[1]==map[2] && map[0]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
        if(map[3]==map[4] && map[4]==map[5] && map[3]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
        if(map[6]==map[7] && map[7]==map[8] && map[6]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
        if(map[0]==map[3] && map[3]==map[6] && map[0]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
        if(map[1]==map[4] && map[4]==map[7] && map[1]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
        if(map[2]==map[5] && map[5]==map[8] && map[2]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
        if(map[0]==map[4] && map[4]==map[8] && map[0]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
        if(map[2]==map[4] && map[4]==map[6] && map[2]!='-')
        {
            printf("\n");
            if(turn%2)
                printf("O ");
            else 
                printf("X ");
            
            printf("is the winner!");
            win=1;
            break;
        }
    }

    if(!win)
        printf("Here come a tie game.");

    return 0;
}