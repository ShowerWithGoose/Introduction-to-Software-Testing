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
            }
            if(fuhao[count-1]=='-')
            g=1;
            while(fuhao[count]=='*'||fuhao[count]=='/') // @@ The logic for handling consecutive * and / is flawed. It assumes the next operator is immediately available at fuhao[count], but it doesn't correctly advance through the string or handle the sequence of operations properly. Specifically, it calculates temp1 based on characters after the current operator, but then increments i by j, which might skip over subsequent operators or operands incorrectly. Also, it modifies count inside the loop, which affects the outer loop's state unpredictably.
            {
                for(j=1;j;j++)
                {
                    if(str[i+j]>='0'&&str[i+j]<='9')
                    temp1=temp1+up(j)*(str[i+j]-'0');
                    else
                    break;
                }
                
                i=i+j; // @@ This increment skips characters, potentially missing operators or parts of numbers, leading to incorrect parsing.
                if(fuhao[count]=='*')
                {
                    temp=temp1*temp;
                    count++;
                }
                else if(fuhao[count]=='/')
                {
                    temp=temp/temp1;
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
        answer=answer+sum[u]; // @@ Summing all elements of sum array is incorrect because only the first w elements are valid. The rest are uninitialized (likely 0), but this approach is fragile and conceptually wrong if negative numbers or other logic were involved differently. However, the primary error is the parsing logic above.
    }
    printf("%lld",answer);
    return 0;
 }