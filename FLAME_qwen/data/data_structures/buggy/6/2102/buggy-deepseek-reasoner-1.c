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
        printf("error"); // @@ should print "error " with a space after error
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ should print "error " with a space after error; also missing return value (undefined behavior)
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
        if(a!=1) // @@ logic error: when a==1, should read next integer and push it, but this condition skips it
        {
            if(a!=0) // @@ logic error: any non-1 non-0 integer is incorrectly treated as a push value; should only push when preceded by command 1
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); // @@ pop function may print "error" without space; this prints garbage on error; also should print space after value
                printf("  "); // @@ should print a single space, not two spaces; also should not print here if pop already prints "error"
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}