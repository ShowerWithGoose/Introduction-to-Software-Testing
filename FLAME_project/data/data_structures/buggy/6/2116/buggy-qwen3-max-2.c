#include <stdio.h>
#include <stdbool.h>
#define M 100
int stk[M];
int tt;
void init();
bool push(int x);
bool empty();
bool pop();
int main() {
    init();
    int op;
    while(scanf_s("%d",&op)!=EOF) // @@ [The function 'scanf_s' is not available in standard C on Linux/GCC; it's a Microsoft-specific secure version. The correct function to use is 'scanf'.]
    {
        if(op==1){
            int x;
            scanf_s("%d",&x); // @@ [Same issue: 'scanf_s' is not standard in GCC; should use 'scanf'.]
            if(push(x)) continue;
            else printf("error ");
        }else if(op==0)
        {
            if(pop()) continue;
            else printf("error ");
        }else break;
    }

    return 0;
}

void init()
{
    tt=-1;
}

bool push(int x)
{
    if(tt==M-1) return false;
    else{
        stk[++tt]=x;
        return true;
    }
}

bool empty()
{
    if(tt==-1) return true;
    else return false;
}

bool pop()
{
    if(empty()) return false;
    else{
        int res=stk[tt--];
        printf("%d ",res);
        return true;
    }
}