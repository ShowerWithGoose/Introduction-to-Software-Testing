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
        printf("error"); // @@ Missing space after "error" and missing newline or space handling; should print "error " to match expected output format.
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ Missing space after "error" and missing newline or space handling; should print "error " to match expected output format.
        //Error("error");
    else         
        {
            //printf("%d",s[Top]);
            return s[Top--]; // @@ The function is declared to return ElemType but does not return a value when Top==-1 (error case), leading to undefined behavior.
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
                printf("%d",pop(STACK)); // @@ Missing space after the popped element; should print "%d " to match expected output format.
                printf("  "); // @@ Prints two spaces instead of one space after each element; should be printf(" "); or combined with previous printf.
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}