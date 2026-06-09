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
        if(a!=1)
        {
            if(a!=0)
            {
                push(STACK,a); // @@ [Incorrect logic: treats any non-1, non-0 value as data to push, but according to problem, only '1' is followed by data; here, the operation code itself (e.g., 56) is being pushed instead of waiting for next integer after 1]
            }
            else
            {
                printf("%d",pop(STACK)); // @@ [When stack is empty, pop() prints "error" without space, and this line still tries to print return value which is undefined in error case, leading to undefined behavior or extra output]
                printf("  "); // @@ [Prints two spaces instead of one after each popped element, causing extra spacing in output]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}