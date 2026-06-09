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
        printf("error"); // @@ [Missing space after "error" and no newline or space as required by output format; also, should return or handle error properly without continuing]
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ [Missing space after "error"; also, function is expected to return an ElemType but returns nothing in error case, leading to undefined behavior]
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
        if(a!=1) // @@ [Incorrect logic: operation '1' indicates a push of the next integer, but this code treats any non-1 value as either push (if not 0) or pop (if 0). It never reads the next integer after a '1'.]
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); // @@ [If pop() prints "error", this will print "error" followed by garbage or undefined value because pop() doesn't return a valid integer in error case. Also, missing space after popped value as per output format.]
                printf("  "); // @@ [Prints two spaces instead of one after each popped element or error, violating output format which requires single space after each output token.]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}