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
    while((scanf("%d",&n))!=(-1)){ // @@ The loop condition is incorrect. scanf returns the number of items read (1 on success), not the value read. It will never equal -1, causing an infinite loop. Should check if n == -1 after reading.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ Incorrect argument. Should pass the array name 's', not 's[100]' which is an element. Change to pop(s).
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ Incorrect argument. Should pass the array name 's', not 's[100]'. Change to push(s, item).
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}