#include<stdio.h>
#include<string.h>

int main()
{
    char a[1024]={0}, b[1024]={0};
    int d[1024]={0};
    
    int lena, i, j;
    int count;
    int sum=0;
    int flag, ans=0;
    
    gets(a); // @@ [Using `gets` is unsafe and deprecated; however, the primary error here is logical, not compilation. But note: the reported "Compilation Error" with "gcc: not found" is environmental, not code-related. The real issue is logic errors in parsing and evaluation. However, per instructions, we focus on logical bugs causing wrong output.]
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
    b[j-1]='\0'; // @@ [This assumes the last character is '=', so b[j-1] removes it. But if the expression ends with '=', then the last non-digit is '=', which is stored in b[j], then j is incremented. So b[j-1] is '=', and setting b[j-1]='\0' removes it. This part may work, but the parsing logic fails when numbers have multiple digits because d[j] is reused without resetting for new numbers. Specifically, after an operator, d[j] should start fresh, but it continues from previous value.]
    
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
                flag*=d[i+1]; // @@ [`flag` is used uninitialized here. If the first operator encountered is '*', `flag` has garbage value. Also, this block assumes prior context (ans, flag) is set, but for expressions starting with multiplication (e.g., "2*3+4"), this fails.]
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
                flag/=d[i+1]; // @@ [Same as above: `flag` is uninitialized. Also, integer division is required, but the bigger issue is undefined behavior due to uninitialized `flag`.]
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
            flag = d[i+1]; // @@ [This sets `flag` to the next number, but what if there are consecutive * or / later? The logic tries to handle operator precedence by looking ahead, but it's flawed. Also, `ans` is set to remember sign, but this approach doesn't correctly accumulate chained multiplications/divisions.]
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