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
            // @@ The condition for detecting the end of a word is flawed. It attempts to handle the end of string but fails to correctly identify word boundaries when followed by non-alpha characters (like space, punctuation). Specifically, `h[j+1]==0` only checks for null terminator, not other delimiters. Also, the logic `((h[j]>='a'&&h[j]<='z')!=0&&b!=-1)` is always true inside this block if we are in the `if` above, but the `else` part or subsequent check is missing for non-alpha chars that terminate a word. The current structure only processes when the current char IS alpha. It needs to process when the current char is NOT alpha (and we were building a word) OR when it's the last char.
            if(((h[j]>='a'&&h[j]<='z')!=0&&b!=-1)||((h[j]>='a'&&h[j]<='z'))&&h[j+1]==0)
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
                    strcat(all[c].s,tword); // @@ Using strcat on uninitialized memory or relying on previous state is dangerous. all[c].s should be cleared or assigned using strcpy. Since all is global, it's zero-initialized, so strcat works for the first time, but logically strcpy is safer and clearer for assignment. However, the bigger issue is the logic flow.
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