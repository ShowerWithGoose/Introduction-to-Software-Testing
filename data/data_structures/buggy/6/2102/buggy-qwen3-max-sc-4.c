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
        printf("error"); // @@ [Missing space after "error" and no newline or space as required by output format; also, should return or handle error consistently]
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ [Missing space after "error"; also, function is expected to return an integer but returns nothing in error case, leading to undefined behavior]
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
        if(a!=1) // @@ [Logic error: According to problem, '1' indicates next number is to be pushed. This condition skips processing when a==1, but doesn't read the next value to push]
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); // @@ [If pop() prints "error", this will print "error" without space and then attempt to print return value (garbage), causing malformed output]
                printf("  "); // @@ [Prints two spaces instead of one after each popped element or error]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}