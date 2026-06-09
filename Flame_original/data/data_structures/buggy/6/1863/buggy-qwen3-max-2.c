#include <stdio.h>
int stack[100];
int top=-1;
int main()
{
    int op,t;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==1)
        {
            if(top<=98)
            {
                scanf("%d",&stack[top+1]);
                top++;
            }
            else
            {
                scanf("%d",&t);
                printf("error "); // @@ [Missing space after "error" in original output requirement; also, should print "error " not "error"]
            }
        }
        if(op==0) // @@ [Should be 'else if' to avoid unintended execution after op==1 or op==-1]
            if(top>=0)
            {
                printf("%d ",stack[top]); // @@ [Missing space after popped value as per output format]
                top--;
            }
            else
            {
                printf("error "); // @@ [Missing space after "error" as required by output format]
            }
        if(op==-1) // @@ [Should be 'else if' to prevent checking this condition unnecessarily after handling op==1 or op==0]
            break;
    }
    return 0;
}