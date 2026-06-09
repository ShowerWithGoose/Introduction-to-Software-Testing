#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long
#define ull unsigned long long

struct word
{
    char c[20];
    int n;
} w[50],t1;

int main()
{
    int i,j,k=0,flag=1,num,f1;
    char ch,tem[20];
    FILE *in;
    in=fopen("article.txt","r");
    for ( i = 0; i < 50; i++)
    {
        w[i].c[0]='\0';
        w[i].n=0;
    }
    ch=fgetc(in);
    while (ch!=EOF)
    {
        ch=tolower(ch);
        if (flag)
        {
            if (ch<'a'||ch>'z')
            {
                ch=fgetc(in);
                continue;
            }
            else
            {
                flag=0;
                j=0;
                tem[j++]=ch;
            }
        }
        else
        {
            if (ch>='a'&&ch<='z')
            {
                tem[j++]=ch;
            }
            else
            {
                f1=1;
                tem[j]='\0';
                for ( i = 0; i < k; i++)
                {
                    if (!strcmp(w[i].c,tem))
                    {
                        w[i].n++;
                        f1=0;
                        memset(tem,'\0',19);
                        break;
                    }
                }
                if (f1)
                {
                    strcpy(w[k++].c,tem);
                    w[k-1].n++;
                    memset(tem,'\0',19);
                }
                flag=1;
            }
        }
        ch=fgetc(in);
    }
    fclose(in);
    for ( i = 0; i < k; i++)
    {
        for ( j = i+1; j < k; j++)
        {
            if (strcmp(w[i].c,w[j].c)>0)
            {
                t1=w[i];
                w[i]=w[j];
                w[j]=t1;
            }
        }
    }
    for ( i = 0; i < k; i++)
    {
        printf("%s %d\n",w[i].c,w[i].n);
    }
    return 0;
}
