#include <stdio.h>//结构体做法 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 
struct dic{
    char name[25];
    int cnt;
}a[40005];
char empty[25];//输入情况考虑齐全 并不一定以空白字符分割单词 
char s[200], s[200], c; // @@ duplicate declaration of array 's' (compilation error)
int n, i, k, k; // @@ duplicate declaration of variable 'k' (compilation error)
int cmp(const void*, const void*);
int main()
{
    FILE *fp1 = fopen("article.txt", "r");
    while (~(c = fgetc(fp1)))
    {
        //if (isalpha(c))
        //{
            s[i] = c;
            i++;
        //}不能只读字母 
    }
    int len = strlen(s); 
    for(i = 0;i < len;i++)
    {
        if(isalpha(s[i])) s[i]=tolower(s[i]); //全部转化为小写 
    }
    for(i=0;i<len;i++)
    {
        if(isalpha(s[i])) //如果是字母，确定为单词开头 
        {
            for(k=i;k<len;k++)
            {
                if(!isalpha(s[k])) //遇到非字母的元素 
                {
                    break;
                }
            }
            memset(s,0,sizeof(s)); // @@ clears the entire array, destroying the word being built
            for(k=0;k<k-i;k++) // @@ uses 'k' as both loop variable and in condition, leading to undefined behavior
            {
                s[k]=s[i+k];   //存储单词 
            }
            strcpy(a[n].name,s); // @@ copies empty string (because 's' was zeroed)
            n++;
            i=k;
        }
        else    continue;
    }
    qsort(a,n,sizeof(struct dic),cmp); //排序 
    for(i=0;i<n;i++) a[i].cnt=1;
    
    for(i=0;i<n;i++)
    {
        if(strcmp(a[i].name,a[i+1].name)==0) // @@ out-of-bounds access when i = n-1
        {
            a[i+1].cnt+=a[i].cnt;//频率加一 
            a[i].cnt=0;
        }
    }
    qsort(a,n,sizeof(struct dic),cmp);
    
    for(i=0;i<n;i++)
    {
        if(a[i].cnt==0)
        {
            continue;
        }
        else
        {
            printf("%s %d\n",a[i].word,a[i].cnt);
        }
    }
     
    fclose(fp1);//do不对劲 
    return 0;
}
int cmp(const void* p1, const void* p2)
{
    struct dic* a = (struct dic*)p1;
    struct dic* b = (struct dic*)p2;
    return strcmp(a->name, b->name);
}