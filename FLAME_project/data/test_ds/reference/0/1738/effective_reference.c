#include <stdio.h>
typedef struct str *ps;
struct str{
    char c;
    ps next;
};
ps str;
ps set_empty();
ps add(ps,ps);
void output();
int judge(ps,ps);
int main()
{
    char c;
    str=set_empty();
    ps i=str;
    add(str,str);
    output();
}
ps set_empty()
{
    ps i;
    i=(ps)malloc(sizeof(struct str));
    i->next=NULL;
    return i;
}
ps add(ps last,ps now)
{
    char current;
    ps i;
    last->next=now;
    if ((current=getchar())!='\n'){
        if (current!='\0'&&current!=EOF&&current!=NULL){
            now->c=current;
            i=(ps)malloc(sizeof(struct str));
            return add(now,i);
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
    ps i=str,ptrl1;
    char c;
    while (i->c!='\0'){
        if (i->next->c!='-'){
            printf("%c",i->c);
            i=i->next;
        }
        else{
            ptrl1=i->next->next;
            if (judge(i,ptrl1)){
                for (c=i->c;c<ptrl1->c;c++){
                    printf("%c",c);
                }
                i=ptrl1;
            }
            else{
                printf("%c",i->c);
                i=i->next;
            }
        }
    }
}
int judge(ps prev,ps next)
{
    char c=prev->c;char b=next->c;
    if (c>='0'&&c<='9'&&b>='0'&&b<='9'&&c<b)
        return 1;
    if (c>='a'&&c<='z'&&b>='a'&&b<='z'&&c<b)
        return 1;
    if (c>='A'&&c<='Z'&&b>='A'&&b<='Z'&&c<b)
        return 1;
    else
        return 0;
}

