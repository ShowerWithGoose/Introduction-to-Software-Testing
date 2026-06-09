#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct word{
    char s[1000];
    int num;
}word;
word p[2000];
int cmp(const void*p1,const void*p2)
{
    word *a=(word*)p1;
    word *b=(word*)p2;
    return strcmp(a->s,b->s);//顺序正确则返回-1 
}
int main()
{
    FILE *in=fopen("article.txt","r");
    int cnt=0;
    int k; // @@ [k is used uninitialized; when the first character is alphabetic, k is used before being set to 0]
    int c;
    while((c=fgetc(in))!=EOF)
    {
        if(!isalpha(c))
        {
            cnt++;//单词数量+1
            k=0;
        }
        else if(isalpha(c)) 
        p[cnt].s[k++]=tolower(c); // @@ [if k is uninitialized and the first char is alpha, this writes to arbitrary memory]
    }
    qsort(p,cnt,sizeof(word),cmp);//按字典序排序，可能有空,相同单词都连着 
    int i;
    for(i=0;i<cnt;i++)
    {
        if(strlen(p[i].s))
        {
            p[i].num=1;
        }
        else
        p[i].num=0;    
    } 
    for(i=0;i<cnt;i++)
    {
        if(strcmp(p[i].s,p[i+1].s)==0) // @@ [when i == cnt-1, p[i+1] accesses out-of-bounds memory]
        p[i+1].num+=p[i].num;
        p[i].num=0;//处理相同单词 
    }
    for(i=0;i<cnt;i++)
    {
        if(p[i].num!=0)
        printf("%s %d\n",p[i].s,p[i].num);    
    } 
    fclose(in);
    return 0;
}