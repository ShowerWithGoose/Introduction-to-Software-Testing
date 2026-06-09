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
void judge();
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
    ps ptrl=in,ptrl1=in,tmp;
    int num;
    if (ptrl->c=='0'){
        ptrl=ptrl->next->next;
        num=1;
        while (ptrl->c=='0'){
            ptrl=ptrl->next;
            num++;
        }
        printf("%c",ptrl->c);
        if (ptrl->next->c!='\0')
            printf(".");
        ptrl=ptrl->next;
        while (ptrl->c!='\0'){
            printf("%c",ptrl->c);
            ptrl=ptrl->next;
        }
        printf("e-%d",num);
    }
    else if (ptrl->next->c=='.'){
        while (ptrl->c!='\0'){
            printf("%c",ptrl->c);
            ptrl=ptrl->next;
        }
        printf("e0");
    }
    else{
        num=-1;
        while (ptrl1->c!='.'){
            ptrl1=ptrl1->next;
            num++;
        }
        printf("%c.",ptrl->c);
        ptrl=ptrl->next;
        while (ptrl->c!='\0'){
            if (ptrl->c=='.'){
                ptrl=ptrl->next;
            }
            else{
                printf("%c",ptrl->c);
                ptrl=ptrl->next;
            }
        }
        printf("e%d",num);
    }

}

