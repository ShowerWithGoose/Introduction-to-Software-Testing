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
            if(((h[j]>='a'&&h[j]<='z')!=0&&b!=-1)||((h[j]>='a'&&h[j]<='z'))&&h[j+1]==0) // @@ The condition for finalizing a word is flawed. It triggers too early (e.g., on every letter) and also incorrectly checks h[j+1]==0 which may access out-of-bound memory. This causes words to be split or recorded multiple times per character.
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
                    strcat(all[c].s,tword); // @@ all[c].s is uninitialized; using strcat on an uninitialized array leads to undefined behavior. Should use strcpy instead.
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