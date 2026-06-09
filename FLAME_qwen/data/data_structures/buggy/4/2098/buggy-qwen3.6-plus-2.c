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
    int k; // @@ k is not initialized. If the file starts with a letter, k will contain a garbage value, leading to undefined behavior when used as an array index. It should be initialized to 0.
    int c;
    while((c=fgetc(in))!=EOF)
    {
        if(!isalpha(c))
        {
            cnt++;//单词数量+1
            k=0;
        }
        else if(isalpha(c)) 
        p[cnt].s[k++]=tolower(c); // @@ Strings are not null-terminated after reading characters. Although the global array is zero-initialized, relying on this is unsafe. A '\0' should be explicitly appended to ensure correct behavior for strlen and strcmp.
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
        if(strcmp(p[i].s,p[i+1].s)==0)
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