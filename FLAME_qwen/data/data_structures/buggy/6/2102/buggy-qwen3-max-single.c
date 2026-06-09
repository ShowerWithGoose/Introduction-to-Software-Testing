#define MAXSIZE 100
# include <stdio.h> 
typedef int ElemType;
ElemType STACK[MAXSIZE];
int  Top=-1;

void  Error(char s[])
{
        printf("%s", s);
        //exit( -1);
}
void  push( ElemType s[ ], ElemType item )
{
    if( Top==MAXSIZE-1 )
        printf("error"); // @@ [Missing space after "error" and no newline; also, should output "error " with space as per problem requirement]
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ [Missing space after "error"; should output "error " with space as per problem requirement]
        //Error("error");
    else         
        {
            //printf("%d",s[Top]);
            return s[Top--];
        }     
}

int main()
{
    int a;
    scanf("%d",&a);
    while(a!=-1)
    {
        //printf("%d",a);
        if(a!=1) // @@ [Incorrect logic: operation '1' is used to indicate a push, but this condition skips handling when a==1. Should check if a == 1 to read next value for push]
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); // @@ [When stack is empty, pop() prints "error" but still returns garbage/uninitialized value which is printed here, causing undefined behavior or wrong output]
                printf("  "); // @@ [Extra space: problem requires single space between outputs, but this adds two spaces after each popped number]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}