#include <stdio.h>
#include<string.h>
int STACK[100];
int Top = -1;
void push(int s[], int item)
{
    if(Top == 99)
        printf("error ");
    else
        s[++Top]=item;
}
void pop(int s[])
{
      if(Top == -1)
          printf("error ");
      else
          printf("%d ", s[Top--]);
}
int main(int argc, const char * argv[]) {
    while (1)
    {
        int sign;
        scanf("%d",&sign);
        if(sign==1)
        {
            int in;
            scanf("%d",&in);
            push(STACK, in);
        }
        else if(sign==0)
        {
            pop(STACK);
        }
        else if(sign==-1) break;
    }
    return 0;
}

