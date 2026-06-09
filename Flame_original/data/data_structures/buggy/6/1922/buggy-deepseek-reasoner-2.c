#include<stdio.h>
int s[100];
int item;
int top=-1;
int flag; // @@ Consider initializing to 0 to avoid undefined behavior, though global zeros it.
void push(int s[100],int item){
    if(top==99){
        flag=-1; // @@ Logical error: flag is not reset when stack is no longer full, causing subsequent pushes to be incorrectly blocked.
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
    while((scanf("%d",&n))!=(-1)){ // @@ Condition compares scanf return to -1; intended to stop when -1 is read, but actually stops only on EOF. This may work but is not robust.
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ Compilation error: s[100] is out-of-bounds and type mismatch; should be pop(s).
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ Compilation error: s[100] is out-of-bounds and type mismatch; should be push(s,item).
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}