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
        printf("error"); @@ [Missing space after "error" and no newline; also, should output "error " with a space as per problem requirement]
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); @@ [Missing space after "error"; should output "error " with a space as per problem requirement]
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
        if(a!=1) @@ [Incorrect logic: operation '1' is used to indicate a push, but here it skips processing when a==1. Should handle '1' as a push command followed by reading the next integer.]
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); @@ [If pop() returns nothing in error case (undefined behavior), this prints garbage. Also missing space after popped value as required.]
                printf("  "); @@ [Prints two spaces instead of one; problem requires single space after each output element including last.]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}