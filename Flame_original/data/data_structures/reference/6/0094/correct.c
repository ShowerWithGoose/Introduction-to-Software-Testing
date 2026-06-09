#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

struct stack{
    int top;
    int num[maxsize];
}s;

void popout(){
    s.top--;
    //return (s.num[s.top + 1]);
}

void popin(int a){
    s.top++;
    s.num[s.top] = a;
}

int judge(int op){
    if ((s.top == -1 && op == 0)||(s.top == maxsize - 1 && op == 1))
        return -1;
    else return 0;
}

int main()
{
    int op,num;
    s.top = -1;
    while ((scanf("%d ",&op)) != -1){
        if (judge(op) == -1){
            printf ("%s ","error");
            continue;
        }
        switch (op){
        case 1:
            scanf("%d",&num);
            popin(num);
            break ;
        case 0:
            printf ("%d ",s.num[s.top]);
            popout();
            break ;
        }
    }

    return 0;
}

