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
        printf("error"); // @@ missing space after "error" (should be "error ") from expected output format
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ missing space after "error" (should be "error ") AND missing return statement (function expects ElemType return)
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
        if(a!=1) // @@ logical error: should handle operation 1 by reading next integer as push value, not treat 1 as irrelevant
        {
            if(a!=0)
            {
                push(STACK,a); // @@ push value a, but if a is actually an operation code (1 or 0) this is wrong; also fails when push value is 0 or 1
            }
            else
            {
                printf("%d",pop(STACK));
                printf("  "); // @@ expected single space after each popped element, not two spaces
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}