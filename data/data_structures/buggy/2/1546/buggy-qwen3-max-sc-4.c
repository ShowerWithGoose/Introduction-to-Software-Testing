#include<stdio.h>
#include<string.h>

int main()
{
    char a[1024]={0}, b[1024]={0};
    int d[1024]={0};
    
    int lena, i, j;
    int count;
    int sum=0;
    int flag, ans=0; // @@ [flag is used uninitialized in cases where the first operator is * or /, leading to undefined behavior]
    
    gets(a); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, in many modern environments it's not available, causing compilation error]
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
        else
        {
            b[j]=a[i];
            j++;
        }
    }
    b[j-1]='\0'; // @@ [if input ends with '=', then b[j-1] is '=', but later code treats b as only containing operators +,-,*,/; also, when expression has no operators (e.g., "5="), j becomes 1, so b[0]='=', then b[j-1]='\0' sets b[0]='\0', which breaks logic]
    
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
                flag*=d[i+1]; // @@ [flag may be uninitialized here if the first operator encountered is '*' at the last position]
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
                flag/=d[i+1]; // @@ [same as above: flag may be uninitialized; also division by zero possible but problem states valid input]
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
                flag*=d[i+1];
            }
            else
            {
                flag/=d[i+1];
            }
        }
        else if((b[i]=='*'||b[i]=='/')&&(b[i+1]=='+'||b[i+1]=='-'))
        {
            if(b[i]=='*')
            {
                flag*=d[i+1];
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