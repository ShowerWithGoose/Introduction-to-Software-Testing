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
    while((scanf("%d",&n))!=(-1)){ @@ [The condition (scanf(...) != -1) is incorrect. scanf returns the number of successfully read items, not -1 on EOF in all cases; it should check for != 1 or use != EOF properly. Also, -1 is a valid input value per problem, so loop won't terminate correctly when -1 is read as data.]
        r[i]=n;
        i++;
    }
    int w=0;
    int u;
    for(w;w<i;w++){
        if(r[w]==0){
            u=pop(s[100]); @@ [Passing s[100] is wrong: it passes the value of the 101st element (out-of-bounds), not the array. Should pass 's' to pass the array pointer.]
            if(u==-1){
                printf("error ");
            }
            else
            printf("%d ",u);
        }
        if(r[w]==1){
            item=r[w+1];
            w++;
            push(s[100],item); @@ [Same error: passing s[100] instead of 's'. This causes undefined behavior and likely compilation/linker issues due to invalid argument type.]
            if(flag==-1){
                printf("error ");
            }
        }
        
    }
    return 0;
}