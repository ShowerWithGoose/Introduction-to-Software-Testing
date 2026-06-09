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
    int k=0; // @@ [Variable 'k' must be initialized to 0 before use in the loop]
    int c;
    while((c=fgetc(in))!=EOF)
    {
        if(!isalpha(c))
        {
            if (k > 0) { // @@ [Only increment word count if a word was actually being formed, to avoid counting leading non-alpha characters or consecutive delimiters as empty words]
                p[cnt].s[k] = '\0'; // @@ [Null-terminate the current word string before moving to the next]
                cnt++;//单词数量+1
                k=0;
            }
        }
        else if(isalpha(c)) 
        p[cnt].s[k++]=tolower(c);
    }
    if (k > 0) { // @@ [Handle the last word in the file if it doesn't end with a non-alpha character]
        p[cnt].s[k] = '\0';
        cnt++;
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
    for(i=0;i<cnt - 1;i++) // @@ [Loop should go up to cnt - 1 to avoid accessing p[cnt] which is out of bounds]
    {
        if(strcmp(p[i].s,p[i+1].s)==0)
        {
            p[i+1].num+=p[i].num;
            p[i].num=0;//处理相同单词 
        }
    }
    for(i=0;i<cnt;i++)
    {
        if(p[i].num!=0)
        printf("%s %d\n",p[i].s,p[i].num);    
    } 
    fclose(in);
    return 0;
}