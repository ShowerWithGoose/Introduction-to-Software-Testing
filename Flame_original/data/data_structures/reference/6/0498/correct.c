#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int stack[100];
int tru[100];
int main()
{
    int i=0,j=0;
    int out[100];
    char *s="error";
    int option;
    while(1)
    {
        scanf("%d",&option);
        if(option==1)
        {
            scanf("%d",&stack[i]);
            if(i<100)
            {
                i++;
            }
            else
            {
                out[j]=0;
                j++;
            }
        }
        else if(option==0)
        {
            i--;
            if(i>=0)
            {
                out[j]=stack[i];
                stack[i]=0;
                j++;
            }
            else
            {
                out[j]=0;
                j++;
                i++;
            }
        }
        else
        {
            break;
        }
    }
    i=0;
    while(i<j)
    {
        if(out[i]!=0)
        {
            printf("%d ",out[i]);
        }
        else
        {
            printf("error ");
        }
        i++;
    }
    return 0;
}
//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）

