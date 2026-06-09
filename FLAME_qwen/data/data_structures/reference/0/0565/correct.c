#include <stdio.h>
typedef struct str *ps;
struct str{
    char c;
    ps next;
};
ps in;
ps set_empty();
ps add(ps,ps);
void output();
int judge(ps,ps);
int main()
{
    char c;
    in=set_empty();
    ps ptrl=in;
    add(in,in);
    output();
}
ps set_empty()
{
    ps ptrl;
    ptrl=(ps)malloc(sizeof(struct str));
    ptrl->next=NULL;
    return ptrl;
}
ps add(ps last,ps now)
{
    char tmp;
    ps ptrl;
    last->next=now;
    if ((tmp=getchar())!='\n'){
        if (tmp!='\0'&&tmp!=EOF&&tmp!=NULL){
            now->c=tmp;
            ptrl=(ps)malloc(sizeof(struct str));
            return add(now,ptrl);
        }
        else{
            now->c='\0';
            now->next=NULL;
            return;
        }
    }
    else{
        now->c='\0';
        now->next=NULL;
        return;
    }
}
void output()
{
    ps ptrl=in,ptrl1;
    char a;
    while (ptrl->c!='\0'){
        if (ptrl->next->c!='-'){
            printf("%c",ptrl->c);
            ptrl=ptrl->next;
        }
        else{
            ptrl1=ptrl->next->next;
            if (judge(ptrl,ptrl1)){
                for (a=ptrl->c;a<ptrl1->c;a++){
                    printf("%c",a);
                }
                ptrl=ptrl1;
            }
            else{
                printf("%c",ptrl->c);
                ptrl=ptrl->next;
            }
        }
    }
}
int judge(ps x,ps y)
{
    char a=x->c;char b=y->c;
    if (a>='0'&&a<='9'&&b>='0'&&b<='9'&&a<b)
        return 1;
    if (a>='a'&&a<='z'&&b>='a'&&b<='z'&&a<b)
        return 1;
    if (a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&a<b)
        return 1;
    else
        return 0;
}

