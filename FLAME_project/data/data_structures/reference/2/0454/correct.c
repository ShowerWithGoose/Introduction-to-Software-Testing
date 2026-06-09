#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct stack{
    int num;
    char s;
    struct stack * next; 
}stack;
typedef stack* Ptrstack;

Ptrstack Initstack(){
    Ptrstack s = NULL;
    return s;
}
void PushSign(Ptrstack*list,char c){
    Ptrstack q;
    q = (Ptrstack)malloc(sizeof(stack));
    q->next = *list;
    q->s= c; 
    *list = q;
}
void PushNum(Ptrstack*list,int c){
    Ptrstack q;
    q = (Ptrstack)malloc(sizeof(stack));
    q->next = *list;
    q->num= c; 
    *list = q;
}
char PopSign(Ptrstack*list){
    Ptrstack q;char c;
    c = (*list)->s;
    q = *list;
    (*list) = (*list) ->next;
    free(q); 
    return  c;
}
int IsEmpty(Ptrstack list){
    if(list == NULL)
    return 1;
    else 
    return 0;
}
Ptrstack Calculation(Ptrstack list,char c){
    Ptrstack q = list;
    Ptrstack p = q->next;
    switch (c)
    {
    case '/':
        p->num = (p->num)/(q->num);
        free(q);
        break;
    case '*':
        p->num = (p->num)*(q->num);
        free(q);
        break;
    case '+':
        p->num = (p->num)+(q->num);
        free(q);
        break;
    case '-':
        p->num = (p->num)-(q->num);
        free(q);
        break;
    default:
        break;
    }
    return p;
}
int OrderJudge(char a,char b){
    int val_a,val_b;
    if(a == '*' || a=='/')
    val_a = 2;
    else
    val_a = 1;

    if(b == '*' || b=='/')
    val_b = 2;
    else
    val_b = 1;
    
    return (val_a>=val_b);
}
char formul[10005];

int main(){
    Ptrstack number,sign;
    number = Initstack();
    sign = Initstack();
    gets(formul);
    
    for(int i=0;formul[i] != '\0';i++){
       if(isdigit(formul[i])){
            int k = 0;
            while(isdigit(formul[i])){
                k = k*10 + (formul[i++] - '0');
            }
            i -= 1;
            PushNum(&number,k);
        }
        else if(formul[i] ==' ')
        continue;
        else{
            if(IsEmpty(sign))
            PushSign(&sign,formul[i]);
            else{
                while(!IsEmpty(sign)&&OrderJudge(sign->s,formul[i])){
                    number = Calculation(number,PopSign(&sign));
                }
                PushSign(&sign,formul[i]);
            }
           
        }               
    }
    printf("%d",number->num);
    return 0;
      
}
