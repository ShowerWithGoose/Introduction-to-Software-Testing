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
    FILE *fp=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fp will be NULL, and subsequent fgets() will cause undefined behavior. The program should check if fp is NULL and handle the error.]
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
            if(((h[j]>='a'&&h[j]<='z')!=0&&b!=-1)||((h[j]>='a'&&h[j]<='z'))&&h[j+1]==0) // @@ [The condition is logically flawed and may trigger word processing at incorrect times. Specifically, the second part `((h[j]>='a'&&h[j]<='z'))&&h[j+1]==0` incorrectly assumes that a null byte follows the last character in the buffer, but fgets() includes newline characters and only null-terminates the string; h[j+1] might be out of bounds or not reflect end-of-word correctly. This can lead to missed words or double-counting.]
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
                    strcat(all[c].s,tword); // @@ [all[c].s is uninitialized (contains garbage), so strcat() appends tword to garbage, leading to undefined behavior. It should use strcpy() instead.]
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