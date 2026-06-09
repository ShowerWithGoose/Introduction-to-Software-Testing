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
        if(a!=1) // @@ [Incorrect logic: according to problem, '1' indicates next integer is to be pushed; this code treats any non-1 as either push (if not 0) or pop (if 0), which misinterprets the input format]
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); // @@ [When stack is empty, pop() prints "error" but still returns garbage/uninitialized value which is printed here, leading to undefined behavior and incorrect output format]
                printf("  "); // @@ [Extra space; should be single space after each popped element or error, not two spaces]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}