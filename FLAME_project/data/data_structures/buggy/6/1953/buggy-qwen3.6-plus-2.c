#include<stdio.h>
#define MAXSIZE 100
int  s[MAXSIZE];//全局变量 
int  top=-1;

void push(int e ); //压一个元素进栈
int pop() ;//从栈中弹出一个元素
int empty() ;//判断栈是否为空
int full() ;//判断栈是否已满
int getTop(); //获取栈顶元素


int main()
{
    int e,f,d=0;
    while(scanf("%d",&f)!=-1)
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ The logic `if(d!=0)` is incorrect. If the popped element is actually 0, it will not be printed. Also, this check fails to distinguish between a successful pop of 0 and an error state if `pop` returns 0 on error (though current `pop` doesn't return 0 on error, it prints directly). The main issue is that valid data `0` is suppressed. Furthermore, the problem requires printing "error " on failure, but `pop` handles printing internally. The variable `d` captures the return value, but the printing logic here conflicts with the internal printing of `pop` or suppresses valid zeros. Given the reference implementation prints directly in pop/push, the main function should likely just call pop() without checking return value for printing, or handle the "error" string consistently. However, looking at the buggy output `5 error 6 ...`, the `6` is suspicious. Let's look closer. The input has `1 5 0 0 ...`. Pop 5 -> prints 5. Pop empty -> prints error. Next is `1 8 0`. Push 8, Pop 8 -> should print 8. Buggy output prints `6`. Where does 6 come from? It seems `getTop` returns 0, but isn't used. Wait, looking at `pop`: `s[top]=0;`. This modifies the stack content to 0. This doesn't explain `6`. Let's re-read the buggy output: `5 error 6 8 90 ...`. The expected is `5 error 8 90 ...`. The `6` is extra or wrong. Actually, looking at the code, `pop` returns the value. In `main`, `d=pop()`. If `pop` succeeds, it returns the value. If `pop` fails, it calls `error("error ")` which prints "error ", but what does it return? It falls through to the end of the function without a return statement, which is undefined behavior. In many compilers/contexts, it might return a garbage value or 0. If it returns garbage, `d!=0` might be true, and it prints that garbage. Here it printed `6`. This confirms the missing return statement in the error path of `pop` is a critical error. Additionally, the `if(d!=0)` check prevents printing valid `0`s.
            printf("%d ",d );
             break;
        case -1:
             break;
        default:
             break;
    }
    }

}

int empty( )//测试堆栈是否为空 
{
       return top==-1;
} 
int full(  )//栈满,返回1,否则,返回0
{
      return top==MAXSIZE-1;
}
int getTop()
{
    return 0;
}
void error(char s[])
{
        printf("%s", s);
}

void push(int item )
{
        if( full() )
               error("error ");
        else
        {
            top++;
            s[top]=item;
        }//入栈成功
        
}
int pop()
{
      if(empty())
             error("error "); // @@ Missing return statement. When stack is empty, "error " is printed, but the function continues and returns an undefined value (garbage), which is then printed by main as seen in the buggy output ('6'). It should return a specific value or handle control flow to prevent printing in main.
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}