#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1005
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
// scanf记得变量要加&，循环变量记得初始化，break语句写在最后，读清题意，看看变量开int还是longlong
// switchcase记得加break,while循环看看会不会死循环，函数看看是不是一定能返回值。
int read();
struct in
{
    char s[500];
    int num;
} a[100000];
char ss[100000], s[10000],subs[100];
int cmp(const void *p, const void *q)
{
    struct in c = *(struct in *)p;
    struct in d = *(struct in *)q;
    return strcmp(c.s, d.s);
}
void toolower(char subs[], char sub[])
{
    int i = 0;
    while (subs[i] != '\0')
        if (subs[i] >= 'A' && subs[i] <= 'Z')
        {
            sub[i] = subs[i] - 'A' + 'a';
            i++;
        }
        else
           { sub[i] = subs[i];
           i++;}
    sub[i]='\0';
}
int ispha(char c){
    if(c>='a'&&c<='z'){
        return 1;
    }
    else return 0;
}
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    int cnt = 1;
    int op = 0;
    while (fgets(ss, 10245, in) != NULL)
    {
        toolower(ss,s);
        int len=strlen(s);
        for (int i = 0; i<len-1; ++i)
        {
            int j = i, k = 0;
            for (; ispha(s[j]); j++)
            {
                subs[k++] = s[j];
            }
            while (!ispha(s[j]))
            {
                i = j; //把i指向下一个单词的位置
                subs[k] = '\0';
                j++;
            }
            for (int p = 1; p <= cnt; p++) //遍历结构体找有无重复的单词
            {
                if (!strcmp(subs, a[p].s)) //找到相等的之后让op=1
                {
                    a[p].num++;
                    op = 1;
                }
            }
            if (!op)
            { //没有找到相等的
                strcpy(a[cnt].s, subs);
                a[cnt].num++;
                cnt++;
            }
            op = 0;
        }
    }
    qsort(a+1,cnt-1,sizeof(a[1]),cmp);
    for(int i=1;i<cnt-1;++i){
        printf("%s %d\n",a[i].s,a[i].num);
    }
    printf("%s %d",a[cnt-1].s,a[cnt-1].num);
    fclose(in);
    return 0;
}
int read()
{
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9')
        (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}
