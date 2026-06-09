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
            // @@ The condition for detecting the end of a word is flawed. 
            // 1. It checks if the current character is a letter AND (b != -1 OR next char is null). 
            //    This triggers processing even when we are in the middle of a word (b != -1 is true for any letter after the first).
            //    It should only trigger when the current character is NOT a letter (end of word) or at the end of string.
            // 2. Even if we assume it tries to handle the "last word in line" case via h[j+1]==0, the logic `((h[j]>='a'&&h[j]<='z')!=0&&b!=-1)` is true for every letter after the first one in a word, causing premature and repeated processing of partial words.
            // 3. Correct logic: Process word when `h[j]` is not a letter (and b >= 0), or when `h[j]` is the last character of the string (and it is a letter).
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
                    strcat(all[c].s,tword);
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