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
        printf("error"); // @@ Missing space after "error" as required by the output format.
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ Missing space after "error"; also lacks a return statement on this path, causing a compilation error.
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
        if(a!=1) // @@ Logical error: does not correctly parse the "1 <value>" push command format. Should explicitly check if a==1 and then read the next integer to push.
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK));
                printf("  "); // @@ Prints two spaces instead of one. The problem specifies a single space after each element/error.
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}