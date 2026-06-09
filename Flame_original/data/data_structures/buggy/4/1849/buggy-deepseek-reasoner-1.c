#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct Key
{
    char word[20];
    int count;
};
typedef struct Key key;
key keytab[100];
char temp[20];
int cmp(const void*p1,const void*p2);
int Alpha(char ch);

int main()
{
    freopen("article.txt","r",stdin);
    
    char ch;
    int i=0,j=0,k=0;
    while(ch=getchar()!=EOF) // @@ 运算符优先级错误，ch被赋值为比较结果而非字符，应改为 (ch=getchar())!=EOF
    {
        if(Alpha(ch)==1)
        {
            ch=tolower(ch);
            temp[i]=ch;
            i++;
        }
        else
        {
            if(i==0)
            {
                continue;
            }
            else
            {
                for(j=0;j<i;j++)
                {
                    keytab[k].word[j]=temp[j]; // @@ 复制字符后缺少字符串结束符'\0'，应在循环后添加 keytab[k].word[i]='\0';
                }
                k++;
                i=0;
            }
        }
    } // @@ 若文件末尾无分隔符，则最后一个单词未被存储，应在循环后检查 i>0 并保存该单词
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++)
    {
        keytab[i].count++;
        if(strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ 当 i==k-1 时访问 keytab[i+1] 越界，应修改循环条件为 i<k-1 或添加边界检查
        {
            keytab[i+1].count+=keytab[i].count;
            keytab[i].count=0;
        }
    }
    
    for(i=0;i<k;i++)
    {
        if(keytab[i].count!=0)
        {
            printf("%s %d\n",keytab[i].word,keytab[i].count);
        }
    }
    
    return 0;
}

int cmp(const void*p1,const void*p2)
{
    key *a=(key*)p1;
    key *b=(key*)p2;
    return strcmp(a->word,b->word);
}

int Alpha(char ch)
{
    if(ch>='A' && ch<='Z')
    {
        return 1;
    }
    else if(ch>='a' && ch<='z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}