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
    while((scanf("%d",&n))!=(-1)){ // @@ The loop condition is incorrect. scanf returns the number of items read (1) or EOF, not -1. The input ends with -1 as a value, not as a signal to stop reading. This loop will never terminate properly.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ Incorrect argument. Should be `pop(s)` to pass the array, not `s[100]` which is an out-of-bounds element.
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ Incorrect argument. Should be `push(s, item)` to pass the array, not `s[100]`.
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}