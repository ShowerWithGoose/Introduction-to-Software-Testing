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
    
    gets(a);
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
    b[j-1]='\0'; @@ [This line incorrectly truncates the operator array by setting b[j-1] to '\0', but j was incremented after storing the '=', so b[j-1] is '=', and this removes it. However, the loop above stores every non-digit (including '=') into b, and j becomes the count of operators INCLUDING '='. Later logic assumes b contains only '+', '-', '*', '/', but now '=' is removed improperly, and more critically, the number of operators is misaligned with numbers. Also, d[j] is never reset when moving to next number, so multi-digit numbers overwrite previous ones incorrectly.]

    
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
                flag*=d[i+1]; @@ [flag is used uninitialized here. If the last operator is '*' or '/', and it's the first time encountering such an operator at the end, flag has garbage value.]
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
                flag/=d[i+1]; @@ [Same issue: flag is uninitialized. Also, division by zero not checked, though problem says expression is valid.]
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
                flag*=d[i+1]; @@ [flag may be uninitialized if this is the first multiplication/division sequence. For example, if expression starts with "10 * 20 * 30", then at i=0, flag is used before being set in a prior '+'/'-' branch.]
            }
            else
            {
                flag/=d[i+1]; @@ [Same uninitialized flag issue.]
            }
        }
        else if((b[i]=='*'||b[i]=='/')&&(b[i+1]=='+'||b[i+1]=='-'))
        {
            if(b[i]=='*')
            {
                flag*=d[i+1]; @@ [Again, flag might not have been initialized if the expression starts with multiplication, e.g., "20 * 30 - ...", then at i=0, flag is used uninitialized.]
            }
            else
            {
                flag/=d[i+1]; @@ [Uninitialized flag.]
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

    printf("\n%d", sum); @@ [The output format should not have a newline before the number. Expected output is just the integer, but this prints "\n602". However, the test case shows expected output as 602 and buggy output as 602, so maybe the judge ignores whitespace? But the bigger issue is logic errors causing wrong computation in general cases.]

    
    return 0;
}