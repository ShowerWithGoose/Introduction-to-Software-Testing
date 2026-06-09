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
        printf("error"); // @@ Missing space after "error" and missing newline; should be "error " to match expected output format
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ Missing space after "error" and missing newline; should be "error " to match expected output format
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
                push(STACK,a); // @@ Logic error: pushes the operation code (e.g., 56, 35) directly instead of reading the value after operation 1; should handle operation 1 separately
            }
            else
            {
                printf("%d",pop(STACK)); // @@ Missing space after popped value; should be "%d " to match expected output format
                printf("  "); // @@ Incorrect spacing: prints two spaces instead of one space after each popped element
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}