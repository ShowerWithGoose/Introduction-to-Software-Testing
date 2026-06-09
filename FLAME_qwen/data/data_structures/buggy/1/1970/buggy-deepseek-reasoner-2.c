#include<stdio.h>
char list[50];
void Swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Perm(char* list, int k, int m)
{
    if (k == m)                                  
    {
        int i;
        for (i = 0; i <= m; ++i)             
        {
            printf("%c ", list[i]); // @@ 对于 N=10，list[9] 不是数字字符，无法正确输出两位数；且该交换法生成的排列顺序不是字典序
        }
        printf("\n");
        return;
    }
    else
    {
        int i;
        for (i = k; i <= m; i++)
        {
            Swap(&list[k], &list[i]);  
            Perm(list, k + 1, m); // @@ 交换法递归无法保证输出按字典序排列，不符合题目要求
            Swap(&list[k], &list[i]);
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    list[0]='1'; // @@ 只初始化了字符 '1'，对于 N=10 无法表示两位数 '10'
    for(i=1;i<n;i++)
    {
        list[i]=list[i-1]+1; // @@ 当 i=9 时 list[9]='9'+1=':'，不是 '10'，导致输出错误
    }
    Perm(list, 0, n - 1);
    return 0;
}