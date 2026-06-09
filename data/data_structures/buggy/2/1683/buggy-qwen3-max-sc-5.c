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
    gets(str1); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11+), 'gets' is removed entirely, leading to compilation error if compiler enforces standard compliance.]
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
            while(fuhao[count]=='*'||fuhao[count]=='/')
            {
                for(j=1;j;j++) // @@ [Infinite loop: 'j' is never updated inside the loop body, so condition 'j' (which is always true for j>=1) never becomes false.]
                {
                    if(str[i+j]>='0'&&str[i+j]<='9')
                    temp1=temp1+up(j)*(str[i+j]-'0');
                    else
                    break;
                }
                
                i=i+j; // @@ [Undefined behavior: 'j' may be uninitialized or unchanged from previous loops, leading to unpredictable index access. Also, after breaking from inner loop, 'j' retains its last value which may be beyond valid digits.]
                if(fuhao[count]=='*')
                {
                    temp=temp1*temp;
                    count++;
                }
                else if(fuhao[count]=='/')
                {
                    temp=temp/temp1; // @@ [Division by zero risk: if temp1 is 0 (e.g., due to parsing error or empty number), this causes undefined behavior. Also, integer division truncates toward zero, but logic here may not correctly parse numbers.]
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
        answer=answer+sum[u]; // @@ [Incorrect summation: 'sum' array is only partially filled (up to 'w'), but this sums all 10000 elements, including uninitialized garbage values.]
    }
    printf("%lld",answer);
    return 0;
 }