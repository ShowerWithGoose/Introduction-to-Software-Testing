#include<stdio.h>
int s[100];
int item;
int top=-1;
int flag; // @@ [uninitialized; should be initialized to 0]
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
    while((scanf("%d",&n))!=(-1)){ // @@ [incorrect loop condition: scanf returns number of items read, not the value; should compare n != -1]
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ [s[100] is out‑of‑bounds array element; should be pop(s)]
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ [s[100] is out‑of‑bounds array element; should be push(s,item)]
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}