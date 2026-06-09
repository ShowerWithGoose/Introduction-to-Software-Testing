#include<stdio.h>
int s[100];
int item;
int top=-1;
int flag;
void push(int s[100],int item){
    if(top==99){
        flag=-1;
    }
    if(flag!=-1)
    s[++top]=item;
     
}
int pop(int s[100]){
    if(top==-1){
        return -1;
    }
    else
    return s[top--];
}
int main(){
    int n,r[500];
    int i=0;
    while((scanf("%d",&n))!=(-1)){ @@ [The condition (scanf(...) != -1) is incorrect. scanf returns the number of successfully read items, not -1 on EOF in all cases; it returns EOF (which is often -1) but comparing directly to -1 is fragile and wrong here because the loop should stop when input ends or when -1 is read as an operation. Also, this loop reads until EOF, but problem says operations end with -1, so it should break when n == -1.]
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); @@ [Passing s[100] is incorrect. s[100] is an integer (out-of-bounds access), but the function expects an array (int*). Should pass 's' instead.]
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); @@ [Same error: passing s[100] (an int) instead of 's' (the array/pointer).]
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}