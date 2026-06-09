#include <stdio.h>
int top=-1;
int stack[105]={0};
typedef Maxnum 100; @@ [Incorrect typedef syntax: 'typedef' requires a type name before the alias, but 'Maxnum 100' is invalid. Should use '#define Maxnum 100' or 'const int Maxnum = 100;' instead.]
void pushin(){
    int num;
    scanf("%d",&num);
    if(top==Maxnum-1){ @@ [Using undeclared identifier 'Maxnum' due to incorrect typedef above.]
    printf("error ");
    }else{
        stack[++top]=num;
    }
    return ;
}
void popout(){
    if(top==-1){
    printf("error ");
    }else{
        printf("%d ",stack[top--]);
    }
    return ;
}
int main(){
 int op;
 scanf("%d",&op);
 while (1)
 {
    if(op==1){
        pushin();
    }else if(op==0){
        popout();
    }
    scanf("%d",&op);
    if(op==-1){
        break;
    }
 }
 return 0;
}