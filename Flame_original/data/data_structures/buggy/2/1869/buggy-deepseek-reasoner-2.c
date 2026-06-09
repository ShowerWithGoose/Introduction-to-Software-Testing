#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
char fuh[300001];
int num[300001];
char s[300001];
int main(void)
{
    int i;
    int temp=0;
    int j=0;//fuh[j]
    int k=0;//num[k]
    int u,v;//运算用
    scanf("%s",s); // @@ [Error: scanf("%s") cannot read spaces; the expression may contain spaces, causing incorrect parsing and potential infinite loop. Use gets(s) or fgets(s, sizeof(s), stdin) instead.]
    for(i=0;s[i]!='=';i++)//分别存进数组 
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            temp=temp*10+(s[i]-'0');
        }
        else if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/'))
        {
            fuh[j]=s[i];
            j++;
            num[k]=temp;
            temp=0;
            k++;
        }
    }
    num[k]=temp;//数字比符号多一个
    /*for(i=0;i<=k;i++)
    {
        printf("%d ",num[i]);
    }
    for(i=0;i<=j;i++)
    {
        printf("%c ",fuh[i]);
    }
    return 0;
}*/
    if(j!=0)
    {
        for(u=0;u<j;u++)//先算乘除 
        {
            if(fuh[u]=='*')
            {
                num[u+1]=num[u]*num[u+1];//算出的数存在相乘两个数中后一个数的位置 
                num[u]=0;
                if(u==0)//保证前一个符号和后一个数字数组下标相差1 
                {
                    fuh[0]='+';
                }
                else
                {
                    fuh[u]=fuh[u-1];
                }
            }
            else if(fuh[u]=='/')
            {
                num[u+1]=num[u]/num[u+1];//算出的数存在相除两个数中后一个数的位置 
                num[u]=0;
                if(u==0)
                {
                    fuh[0]='+';
                }
                else
                {
                    fuh[u]=fuh[u-1];
                }
            } 
        }
        /*for(i=0;i<=k;i++)
    {
        printf("a[%d]=%d ",i,num[i]);
    }
    for(i=0;i<j;i++)
    {
        printf("b[%d]=%c \n",i,fuh[i]);
    }*/

        for(v=0;v<j;v++)//再算加减 
        {
            if(fuh[v]=='+')
            {
                num[0]+=num[v+1];
            }
            else if(fuh[v]=='-')
            {
                num[0]-=num[v+1];
            }
        }
        printf("%d\n",num[0]);
    }
    else if(j==0)
    {
        printf("%d\n",temp);
    }
    return 0;
}