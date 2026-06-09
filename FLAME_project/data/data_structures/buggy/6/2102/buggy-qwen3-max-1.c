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
        printf("error"); // @@ [Missing space after "error" as required by output format]
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ [Missing space after "error" as required by output format]
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
        if(a!=1) // @@ [Incorrect logic: treats any non-1 value (including negative numbers and 0) as a push operation, but only 0 is pop and -1 is end; also fails to read the next integer after 1 for push]
        {
            if(a!=0)
            {
                push(STACK,a); // @@ [Pushes 'a' itself instead of reading a separate integer after 1; according to spec, '1' must be followed by the value to push]
            }
            else
            {
                printf("%d",pop(STACK)); // @@ [Does not handle error case in pop() properly: when stack is empty, pop() prints "error" without space and returns undefined value which is then printed as %d]
                printf("  "); // @@ [Prints two spaces instead of one after each popped element]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}