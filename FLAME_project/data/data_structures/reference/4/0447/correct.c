#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct word{
    char s[100];
    int cnt;
}words[1000];
int compare(const void *a,const void *b);

int main()
{
    int i=0,j=0,k=0,flag=1;//flag=0表示在读到新的字符ch前读到的是非字母字符,1表示读到的是字母字符即是同一个单词
    char ch;
    FILE *fp=fopen("article.txt","r");
    ch=fgetc(fp);
    while(isalpha(ch)==0)
        ch=fgetc(fp);//找到第一个是字母的字符
    while(ch!=EOF)
    {
        if(isalpha(ch)!=0 && flag==0)
        {
            flag=1;
            j=0;
            i++;
            words[i].s[j++]=tolower(ch);
            ch=fgetc(fp);
        }
        else if(isalpha(ch)!=0 && flag==1)
        {
            flag=1;
            words[i].s[j++]=tolower(ch);
            ch=fgetc(fp);
        }
        else if(isalpha(ch)==0)
        {
            flag=0;
            ch=fgetc(fp);
        }
    }
    int all=i;
    for(i=0;i<1000;i++)
        words[i].cnt=1;
    qsort(words,all+1,sizeof(words[0]),compare);
    for(i=0;i<=all;i++)
    {
        if(words[i].cnt==0)
        continue;
        for(j=i+1;j<=all;j++)
        {
            if(strcmp(words[j].s,words[i].s)==0)
            {
                words[i].cnt++;
                words[j].cnt=0;
            }
            
        }
    }
    for(i=0;i<=all;i++)
    {
        if(words[i].cnt>0)
        printf("%s %d\n",words[i].s,words[i].cnt);
    }
    return 0;
}

int compare(void const *a,const void *b)
{
    struct word *c,*d;
    c=(struct word*)a,d=(struct word*)b;
    return strcmp(c->s,d->s);
}
