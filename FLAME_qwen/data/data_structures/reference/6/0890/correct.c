#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 105
int STACK[MAXSIZE];
int top = -1;
void push(int s[], int item);
void pop(int s[]);

int main(int argc, const char * argv[]) {
    while (1){
        int flag;
        scanf("%d",&flag);
        if(flag==1){
            int in;
            scanf("%d",&in);
            push(STACK, in);
        }
        else if(flag==0){
            pop(STACK);
        }
        else if(flag==-1) break;
    }
    return 0;
}

void push(int s[], int item)
{
    if(top == MAXSIZE-1)
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


