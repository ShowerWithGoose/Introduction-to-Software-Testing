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
        printf("error"); // @@ Missing space after "error" and missing newline; should match expected output format "error " (with a space). Also, the function does not return a value to indicate failure, but the problem expects "error " to be printed and then continue.
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ Missing space after "error" and missing newline; same issue as push. Also, the function returns an undefined value when error occurs (no return statement), which can cause undefined behavior.
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
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); // @@ Missing space after the popped element; should be "%d " to match expected output format. Also, pop() may return garbage when stack is empty, leading to incorrect output.
                printf("  "); // @@ Prints two spaces instead of one; should be a single space to match expected format.
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}