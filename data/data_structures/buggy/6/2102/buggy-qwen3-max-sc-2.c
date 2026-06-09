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
        printf("error"); // @@ [Missing space after "error" and no newline; also, should return or handle error properly without continuing]
        //Error("error");
    else
        s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error"); // @@ [Missing space after "error"; also, function is expected to return an int but returns nothing in error case, leading to undefined behavior]
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
        if(a!=1) // @@ [Incorrect logic: operation '1' should trigger reading the next integer to push, but this skips any value that is not 1, treating it as either push (if not 0) or pop (if 0). This misinterprets the input format.]
        {
            if(a!=0)
            {
                push(STACK,a);
            }
            else
            {
                printf("%d",pop(STACK)); // @@ [If pop() prints "error", this will print "error" followed by garbage or undefined value because pop() doesn't return a valid integer in error case. Also, missing space after popped value as per output requirement.]
                printf("  "); // @@ [Prints two spaces instead of one after each popped element; also, if pop fails, this still prints extra spaces.]
            }
        }
    scanf("%d",&a);
    }
    
    return 0;
}