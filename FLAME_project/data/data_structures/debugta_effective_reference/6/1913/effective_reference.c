#include <stdio.h>
#define maxsize 100
int s[maxsize];
int top = -1;                
void push(int s[], int item);
void pop(int s[]);            

int main(int argc, const char * argv[]) {
    while (1)
    {
        int sign;
        scanf("%d",&sign);
        
        if(sign==1)//ÈëÕ»²Ù×÷
        {
            int num;
            scanf("%d",&num);
            push(s, num);
        }
        else if(sign==0)
        {
            pop(s);
        }
        else if(sign==-1) break;
    }
    return 0;
}

void push(int s[], int item)
{
    if(top == maxsize-1)
        printf("error ");
    else
        s[++top]=item;
}

void pop(int s[])
{
      if(top == -1)
          printf("error ");
      else
          printf("%d ", s[top--]);
}



