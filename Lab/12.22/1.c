#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char ch;
    struct Node *next, *prev;
}Node;

Node *a, *b, *cur;

void insert(char ch)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->ch=ch;
    newnode->next=newnode->prev=NULL;

    if(!cur)
    {
        a=newnode;
        b=(Node*)malloc(sizeof(Node));
        b->ch='\0';
        a->next=cur=b;
        b->next=NULL;
        b->prev=a;
    }
    else
    {
        if(cur->prev)
        {
            newnode->next=cur;
            newnode->prev=cur->prev;
            cur->prev->next=newnode;
            cur->prev=newnode;
        }
        else
        {
            newnode->next=cur;
            cur->prev=newnode;
            a=newnode;
        }
    }
}

void delete(Node *cur)
{
    if(cur->next)
        delete(cur->next);
    free(cur);
}

int main()
{
    char s[100005];
    while(gets(s))
    {
        a=b=cur=NULL;

        for(int i=0; s[i]!='\0'; i++)
        {
            if(s[i]=='[')
                cur=a;
            else if(s[i]==']')
                cur=b;
            else
                insert(s[i]);
        }

        for(Node *ptr=a; ptr!=b; ptr=ptr->next)
            putchar(ptr->ch);
        puts("");
        delete(a);
    }

    return 0;
}