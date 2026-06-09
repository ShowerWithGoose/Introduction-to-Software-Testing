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
    
    gets(a); // @@ [Using `gets` is unsafe and deprecated; however, the immediate error is not here. The real issue is logic errors in parsing and evaluation.]
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
    b[j-1]='\0'; // @@ [This assumes the last character is '=', but it overwrites the last operator with '\0', potentially dropping the final operator or mishandling the '='. Also, if expression ends with '=', then b[j] should be set to '\0' at index j, not j-1, because the loop increments j after storing the operator (including '='). This corrupts operator array.]
    
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
                flag*=d[i+1]; // @@ [`flag` is used uninitialized here. If the first operator encountered is '*' at the last position, `flag` has no defined value.]
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
                flag/=d[i+1]; // @@ [Same as above: `flag` is uninitialized. Also, division by zero is possible but problem states valid input, so maybe not the issue.]
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