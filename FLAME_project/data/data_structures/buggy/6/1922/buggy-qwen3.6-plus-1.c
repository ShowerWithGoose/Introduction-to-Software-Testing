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
    while((scanf("%d",&n))!=(-1)){ // @@ The loop condition checks if the return value of scanf is -1, but scanf returns the number of items successfully read. It should check if the read value 'n' is -1 to break the loop. Also, this logic consumes the -1 terminator incorrectly or fails to stop at the right time depending on input buffering, but the primary issue is the condition logic for stopping.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ Passing s[100] passes a single integer (out of bounds access) instead of the array pointer. It should be pop(s).
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ Passing s[100] passes a single integer (out of bounds access) instead of the array pointer. It should be push(s, item).
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}