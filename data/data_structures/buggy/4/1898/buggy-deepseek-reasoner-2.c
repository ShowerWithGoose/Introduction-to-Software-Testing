#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
typedef struct word{
    char s[20];
    int x;
}word;
int cmp(const void *a, const void *b);
int main()
{
    struct word tj[100];
    freopen("article.txt","r",stdin);
    int i=0,j=0;
    char ch;
    while(scanf("%c",&ch)!=EOF)
    {
        if(isalpha(ch))
        {
            if(ch>='A'&&ch<='Z')
            {
                ch=ch+'a'-'A';
            }
            tj[i].s[j]=ch;
            tj[i].x=1;
            j++;
        }
        else if(ch==' '||ch=='\n'||ch=='.'||ch==';'||ch=='\"') // @@ 分隔符集合不完整，应包含所有非字母字符（如逗号、括号、数字等），否则会导致单词粘连。
        {
            tj[i].x=1;
            tj[i].s[j]='\0'; // @@ 当j==0时会产生空单词，应添加条件跳过空单词。
            i++;
            j=0;
        }
    } // @@ 缺少对最后一个单词的处理：如果文件末尾没有分隔符，最后一个单词未被存入数组。
    qsort(tj,i,sizeof(word),cmp);
    int n=0;
    while(n<i) // @@ 循环条件错误，应改为 while(n<i-1) 或内部特殊处理最后一个单词，否则访问 tj[n+1] 会越界。
    {
        if(strcmp(tj[n].s,tj[n+1].s)!=0)
        {
            if(strlen(tj[n].s)>=1)
            {
                printf("%s %d\n",tj[n].s,tj[n].x);
            } 
        }
        else
        {
            tj[n+1].x=tj[n].x+tj[n+1].x;
        }
        n++;
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    word *a1=(word *)a;
    word *b1=(word *)b;
    return(strcmp(a1->s,b1->s));
}