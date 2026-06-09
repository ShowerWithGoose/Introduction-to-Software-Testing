#include<stdio.h>
int s[100];
int item;
int top=-1;
int flag; // @@ uninitialized, may cause undefined behavior
void push(int s[100],int item){ // @@ parameter name shadows global array, but functional; however, flag logic is flawed
    if(top==99){
        flag=-1; // @@ after setting flag, it is never reset; subsequent pushes will fail incorrectly
    }
    if(flag!=-1)
    s[++top]=item;
     
}
int pop(int s[100]){ // @@ parameter name shadows global array, but works
    if(top==-1){
        return -1;
    }
    else
    return s[top--];
}
int main(){
    int n,r[500];
    int i=0;
    while((scanf("%d",&n))!=(-1)){
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); // @@ s[100] is out-of-bounds; should be pop(s)
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); // @@ s[100] is out-of-bounds; should be push(s,item)
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}