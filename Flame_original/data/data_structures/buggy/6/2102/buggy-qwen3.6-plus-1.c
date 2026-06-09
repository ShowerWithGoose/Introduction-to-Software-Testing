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
        printf("error"); // @@ Missing trailing space. The problem requires outputting "error " with a space after it.
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ Missing trailing space. Also, the function is declared to return ElemType but lacks a return statement on this error path, which causes a compilation error in strict environments.
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
                push(STACK,a); // @@ Logical error: The code ignores the '1' push command and treats the subsequent value as an operation code. It should explicitly check for '1' and read the next integer as the value to push.
            }
            else
            {
                printf("%d",pop(STACK));
                printf("  "); // @@ Prints two spaces instead of one. The problem specifies a single space after each popped element.
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}