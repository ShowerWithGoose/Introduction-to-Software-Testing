#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ The logic for finding the top of the stack is flawed. It assumes 0 means empty, but 0 is a valid integer value that could be pushed (though problem says not 0, -1, 1, the initialization with 0 makes this check unreliable for distinguishing empty slots from pushed zeros if constraints were different, but more importantly, it doesn't track the actual stack top index correctly across pushes and pops. A simple top index variable is needed. Also, if the stack is full, i will be 100, but the loop condition `st[i]!=0` accesses out of bounds if all 100 elements are non-zero.
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); // @@ This reads the value into the found index. However, the previous loop to find 'i' is inefficient and logically fragile for a stack. A dedicated `top` variable is standard.
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ This logic attempts to find the last non-zero element to pop. This is incorrect for a stack. A stack is LIFO, so we must pop the most recently pushed element, regardless of its value. Using 0 as an "empty" marker fails if valid data is 0 (problem says input won't be 0, but the logic is still structurally wrong for a stack implementation which should use a top pointer). More critically, if the stack is empty, `j` becomes -1. If the stack has elements, it finds the highest index with a non-zero value. This simulates a stack only if elements are pushed sequentially into increasing indices and never leave "gaps" of zeros below non-zeros. But combined with the push logic, it's messy. The main error is that it doesn't maintain a proper stack top.
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} // @@ Setting to 0 marks it as empty. This approach relies on 0 being an invalid stack value. While the problem states pushed integers are not 0, -1, or 1, this implementation is fragile and inefficient. The primary issue is the lack of a proper `top` index tracking the current stack size/top position.
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}