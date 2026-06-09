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
        printf("error");
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error");
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
                push(STACK,a); // @@ The problem states that '1' followed by an integer is a push operation. Any other number (except 0 and -1) is not explicitly defined as a push operation in the standard sense described, but looking at the reference code, only '1' triggers a push with the next integer. However, the buggy code treats any number that is not 1 and not 0 as a push operation itself. This is logically incorrect based on the problem description "1 followed by an integer... represents a push". But wait, looking at the input: `1 56 1 35...`. The buggy code reads `1`, sees it is 1, so it skips the if/else block and goes to scanf. Then it reads `56`. `56` is not 1 and not 0, so it pushes `56`. This actually mimics the behavior if the input format was just numbers to push unless 0 or -1. BUT the problem says "1 followed by an integer". The buggy code fails to read the second integer for the push operation. It treats the operand itself as the value to push if it's not 1 or 0. This is a fundamental logic error in parsing.
            }
            else
            {
                printf("%d",pop(STACK));
                printf("  "); // @@ The expected output uses a single space separator. The buggy code prints two spaces ("  "). This causes formatting mismatch.
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}