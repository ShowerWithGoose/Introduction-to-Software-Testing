#include <stdio.h>
int stack[100];
int top=-1;
int main(int argc, char const *argv[])
{
    int mark,num;
    while(scanf("%d",&mark)!=EOF)
    {
        if(mark==1)
        {
            scanf("%d",&num);
            if(top==99) printf("error ");
            else
            {
                stack[++top]=num;
            }
        }
        else if(mark==0)
        {
            if(top==-1) printf("error ");
            else
            {
                printf("%d ",stack[top--]);
            }
        }
        else if(mark==-1) break;
    }
    return 0;
}

