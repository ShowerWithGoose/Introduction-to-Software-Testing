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
    while((scanf("%d",&n))!=(-1)){ // @@ The loop condition `scanf("%d",&n) != (-1)` is incorrect. `scanf` returns the number of items read (1 on success), not the value read. This will never equal -1, causing an infinite loop. It should check if the input value is -1, e.g., `while(scanf("%d",&n) == 1 && n != -1)`.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ `s[100]` is out-of-bounds array access. The function expects an array argument, but `s[100]` accesses the 101st element (index 100) of an array of size 100. It should be `pop(s)`.
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ Same out-of-bounds issue: `s[100]` should be `s`.
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}