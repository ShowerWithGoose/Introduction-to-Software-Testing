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
        printf("error"); // @@ Missing space after "error"; should be "error "
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ Missing space after "error"; should be "error ", and missing return value when stack empty (undefined behavior)
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
    scanf("%d",&a); // @@ Incorrect input parsing; should read command first, then if command is 1, read the value. This logic will misinterpret values that are 1, 0, or -1.
    while(a!=-1)
    {
        //printf("%d",a);
        if(a!=1) // @@ Incorrect condition; should check if a==1 to handle push with two integers.
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK));
                printf("  "); // @@ Should print a single space instead of two spaces, causing double spaces in output.
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}