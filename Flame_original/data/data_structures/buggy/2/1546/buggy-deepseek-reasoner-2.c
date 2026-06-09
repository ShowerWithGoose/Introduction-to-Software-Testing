#include<stdio.h>
#include<string.h>

int main()
{
    char a[1024]={0}, b[1024]={0};
    int d[1024]={0};
    
    int lena, i, j;
    int count;
    int sum=0;
    int flag, ans=0; // @@ flag未初始化，后续使用会导致未定义行为
    gets(a); // @@ 不安全的函数，但非逻辑错误主因
    //去除空格
    lena = strlen(a);
    for(i = 0, j = 0; i<lena; i++)
    {
        if(a[i]!=' ')
        {
            a[j++]=a[i];
        }
    }
    a[j]='\0';
    
    lena = strlen(a);
    for(i = 0, j = 0; i<lena; i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            d[j]=10*d[j]+a[i]-'0';
        }
        else // @@ 应将等号 '=' 忽略，但代码将其当作运算符存入b，导致后续运算错误
        {
            b[j]=a[i];
            j++;
        }
    }
    b[j-1]='\0';
    
    //j-1是运算符的数量 j是数字的数量
    //
    if(j==1)
    {
        printf("%d", d[0]);
        return 0;
    }
    count = j-1;
    sum+=d[0];
    for(i = 0; i<count; i++)
    {
        if(i==count-1)
        {
            if(b[i]=='+')
            {
                sum+=d[i+1];
            }
            else if(b[i]=='-')
            {
                sum-=d[i+1];
            }
            else if(b[i]=='*')
            {
                flag*=d[i+1]; // @@ flag未初始化，且未考虑之前累积的flag值
                if(ans==0)
                {
                    sum+=flag;
                }
                else
                {
                    sum-=flag;
                }
            }
            else
            {
                flag/=d[i+1]; // @@ flag未初始化，同理
                if(ans==0)
                {
                    sum+=flag;
                }
                else
                {
                    sum-=flag;
                }
            }
        }
        if((b[i]=='+'||b[i]=='-')&&(b[i+1]=='+'||b[i+1]=='-'))
        {
            if(b[i]=='+')
            {
                sum+=d[i+1];
            }
            else
            {
                sum-=d[i+1];
            }
        }
        else if((b[i]=='+'||b[i]=='-')&&(b[i+1]=='*'||b[i+1]=='/'))
        {
            flag = d[i+1];
            if(b[i]=='+')
            {
                ans=0;
            }
            else
            {
                ans=1;
            }
        }
        else if((b[i]=='*'||b[i]=='/')&&(b[i+1]=='*'||b[i+1]=='/'))
        {
            if(b[i]=='*')
            {
                flag*=d[i+1]; // @@ 连续乘除时flag累积，但未重置，之前可能已有未合并的flag
            }
            else
            {
                flag/=d[i+1]; // @@ 同上
            }
        }
        else if((b[i]=='*'||b[i]=='/')&&(b[i+1]=='+'||b[i+1]=='-'))
        {
            if(b[i]=='*')
            {
                flag*=d[i+1]; // @@ 乘除后立即与sum合并，但flag可能已有之前乘除的累积，逻辑混乱
            }
            else
            {
                flag/=d[i+1];
            }
            if(ans==0)
            {
                sum+=flag;
            }
            else
            {
                sum-=flag;
            }
        }
        
    }

    printf("\n%d", sum);
    
    return 0;
}