#include <stdio.h>
#include <string.h>
struct cipin
{
    char let[30];
    int num;
    struct cipin *next;
    struct cipin *pre;
}
t[1000000],*q;
int i,j;
char c,s[30];
int main()
{
    s[0]='a',s[1]='\0';
    strcpy(t[0].let,s);
    for(j=0;j<29;j++)
    s[j]='z';
    s[29]='\0';
    strcpy(t[999999].let,s);
    t[0].next=&t[999999];
    t[999999].pre=&t[0];
    FILE *in;
    in=fopen("article.txt","r");
    i=1;
    while(fscanf(in,"%c",&c)!=EOF)
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        {
            j=0;
            while((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            {
                if(c>='A'&&c<='Z')
                c+=32;
                s[j]=c;
                j++;
                fscanf(in,"%c",&c);
            }
            s[j]='\0';
            for(q=t;strcmp(s,q->let)>0;
            q=q->next)
            ;
            if(strcmp(s,q->let)==0)
            q->num++;
            else
            {
                strcpy(t[i].let,s);
                t[i].num=1;
                t[i].next=q;
                t[i].pre=q->pre;
                q->pre->next=&t[i];
                q->pre=&t[i];
                i++;
            }
        }
    }
    fclose(in);
    for(q=t;q!=NULL;q=q->next)
    if(q->num!=0)
    printf("%s %d\n",q->let,q->num);
    return 0;
}

