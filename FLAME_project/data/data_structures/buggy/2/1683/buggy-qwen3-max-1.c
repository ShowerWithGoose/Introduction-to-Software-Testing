#include<stdio.h>
#include<string.h>
char str[10000];
char str1[10000];
char fuhao[10000];
long long sum[10000];
int up(int n)
{
    int g=1;
    for(int i=0;i<n-1;i++)
    {
        if(i<n-1)
        g=g*10;
    }
    return g;
    
}
int main()
{
    int i=0,j=1,count=1,g=0,w=0,y=0;
    long long answer=0,temp=0,temp1=0;
    gets(str1);
    for(i=0;i<strlen(str1);i++)
    {
        if(str1[i]!=' ')
        {
            str[y]=str1[i];
            y++;
        }
    }
    str[y]='\0';                                        //È¥¿Õ¸ñ 
    
    j=1;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='=')
        {
            fuhao[j]=str[i];
            j++;
        }
    }                                            //¹éÄÉ·ûºÅ 
    
    
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='=')
        {
            for(j=1;j<=i;j++)
            {
                if(str[i-j]>='0'&&str[i-j]<='9')
                temp=temp+up(j)*(str[i-j]-'0');
                else
                break;
            } @@ [The digit extraction logic is flawed: it processes digits from right to left using up(j), but up(j) computes 10^(j-1), which leads to incorrect place values when multiple digits are involved. For example, "12" would be interpreted as 2*10^1 + 1*10^0 = 21 instead of 12.]
            if(fuhao[count-1]=='-')
            g=1;
            while(fuhao[count]=='*'||fuhao[count]=='/')
            {
                for(j=1;j;j++)
                {
                    if(str[i+j]>='0'&&str[i+j]<='9')
                    temp1=temp1+up(j)*(str[i+j]-'0');
                    else
                    break;
                } @@ [Same digit extraction flaw as above; also, the loop condition 'j;j++' is infinite if j never becomes zero, and j is not reset properly after breaking. Additionally, this inner parsing does not correctly handle multi-digit numbers after operators.]
                
                i=i+j; @@ [This skips characters incorrectly because j may not represent the actual number of digits parsed, leading to misalignment in the string traversal.]
                if(fuhao[count]=='*')
                {
                    temp=temp1*temp;
                    count++;
                }
                else if(fuhao[count]=='/')
                {
                    temp=temp/temp1; @@ [Division order is reversed: should be temp / temp1, but due to earlier parsing errors, both operands may be wrong. Also, integer division truncation is correct per problem, but operands are likely incorrect.]
                    count++;
                }
                temp1=0;
            }
            if(fuhao[count]=='+'||fuhao[count]=='-')
            count++; 
            if(g==1)
            {
                sum[w]=-temp;
                w++;
            }
            else
            {
                sum[w]=temp;
                w++;
            }
            g=0;
            temp=temp1=0;
        }
    }
    for(int u=0;u<10000;u++)
    {
        answer=answer+sum[u];
    } @@ [This sums all 10000 elements of sum[], including uninitialized garbage values beyond index w-1, leading to undefined behavior and incorrect results. Should only sum up to w.]
    printf("%lld",answer);
    return 0;
 }