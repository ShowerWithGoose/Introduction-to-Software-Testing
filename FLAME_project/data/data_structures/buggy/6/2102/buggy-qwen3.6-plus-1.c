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
                push(STACK,a); // @@ The problem states that '1' followed by an integer is a push operation. Any other number (except 0 and -1) is treated as data to be pushed only if preceded by 1. Here, numbers like 56 are being pushed directly because they are not 1 or 0, which is incorrect logic. The input format is "1 <value>" for push.
            }
            else
            {
                printf("%d",pop(STACK));
                printf("  "); // @@ The expected output uses a single space after each element. This prints two spaces.
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}