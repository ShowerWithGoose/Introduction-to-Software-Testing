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
    int k;
    int c;
    while((c=fgetc(in))!=EOF)
    {
        if(!isalpha(c))
        {
            cnt++;//单词数量+1
            k=0;
        }
        else if(isalpha(c)) 
        p[cnt].s[k++]=tolower(c);
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
        if(strcmp(p[i].s,p[i+1].s)==0) // @@ 当i=cnt-1时p[i+1]越界；缺少花括号导致后续语句无条件执行
        p[i+1].num+=p[i].num; // @@ 越界访问且仅由if控制
        p[i].num=0;//处理相同单词  // @@ 本应仅在if内执行，但缺少花括号导致每次循环都清空当前单词计数
    }
    for(i=0;i<cnt;i++)
    {
        if(p[i].num!=0)
        printf("%s %d\n",p[i].s,p[i].num);    
    } 
    fclose(in);
    return 0;
}