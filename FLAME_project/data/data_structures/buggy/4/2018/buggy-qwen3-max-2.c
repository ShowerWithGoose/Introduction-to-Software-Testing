#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    char s[32];
    int num;
}all[1314],a;
char h[1024];
char tword[32];
int main()
{
    int i,j,k=0;
    int b,c=0,d=0;
    FILE *fp=fopen("article.txt","r");
    while(fgets(h,1024,fp)!=NULL)
    {
        for(i=0;i<strlen(h);i++)
        {
            if(h[i]>='A'&&h[i]<='Z')
            {
                h[i]+='a'-'A';
            }
        }
        b=-1;
        for(j=0;j<strlen(h);j++)
        {
            if(h[j]>='a'&&h[j]<='z')
            {
                tword[++b]=h[j];
            }
            if(((h[j]>='a'&&h[j]<='z')!=0&&b!=-1)||((h[j]>='a'&&h[j]<='z'))&&h[j+1]==0) // @@ [The condition is flawed: it triggers word processing too early (e.g., on every letter), and the second part `h[j+1]==0` doesn't correctly detect end-of-string or non-letter boundaries. This causes single letters to be treated as words and duplicates due to repeated processing of partial words.]
            {
                for(k=0;k<c;k++)
                {
                    if(strcmp(tword,all[k].s)==0)
                    {
                        d=1;
                        break;
                    }
                }
                if(d==0)
                {
                    strcat(all[c].s,tword); // @@ [`strcat` is used on uninitialized `all[c].s`, which may contain garbage; should use `strcpy` instead. Also, `tword` may not be null-terminated properly if `memset` wasn't called before first use, though it is later—still risky.]
                    all[c++].num=1;
                }
                else if(d==1)
                {
                    all[k].num++;
                    d=0;
                }
                memset(tword,0,sizeof(tword));
                b=-1;
            }
        }
    }
    for(i=c-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(strcmp(all[j].s,all[j+1].s)>0)
            {
                a=all[j];
                all[j]=all[j+1];
                all[j+1]=a;
            }
        }
    }
    for(i=0;i<c;i++)
    {
        printf("%s %d\n",all[i].s,all[i].num);
    }
    return 0;
}