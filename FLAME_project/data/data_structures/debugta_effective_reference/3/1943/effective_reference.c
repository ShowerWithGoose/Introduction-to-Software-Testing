#include <stdio.h>
typedef struct str *ps;
struct str{
    char c;
    ps next;
};
ps c;
ps set_empty();
ps add(ps,ps);
void output();
void judge();
int main()
{
    char c;
    c=set_empty();
    ps i=c;
    add(c,c);
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
    char tmp;
    ps i;
    last->next=now;
    if ((tmp=getchar())!='\n'){
        if (tmp!='\0'&&tmp!=EOF&&tmp!=NULL){
            now->c=tmp;
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
    ps i=c,flag=c,tmp;
    int num;
    if (i->c=='0'){
        i=i->next->next;
        num=1;
        while (i->c=='0'){
            i=i->next;
            num++;
        }
        printf("%c",i->c);
        if (i->next->c!='\0')
            printf(".");
        i=i->next;
        while (i->c!='\0'){
            printf("%c",i->c);
            i=i->next;
        }
        printf("e-%d",num);
    }
    else if (i->next->c=='.'){
        while (i->c!='\0'){
            printf("%c",i->c);
            i=i->next;
        }
        printf("e0");
    }
    else{
        num=-1;
        while (flag->c!='.'){
            flag=flag->next;
            num++;
        }
        printf("%c.",i->c);
        i=i->next;
        while (i->c!='\0'){
            if (i->c=='.'){
                i=i->next;
            }
            else{
                printf("%c",i->c);
                i=i->next;
            }
        }
        printf("e%d",num);
    }

}

