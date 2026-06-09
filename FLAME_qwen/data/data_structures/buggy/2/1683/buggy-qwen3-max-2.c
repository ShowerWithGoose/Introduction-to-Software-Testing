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
    gets(str1); // @@ [Using `gets` is unsafe and deprecated; many modern compilers (like GCC) may not support it by default, leading to compilation errors. It should be replaced with `fgets`.]
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
                for(j=1;j;j++) // @@ [Infinite loop: `j` starts at 1 and condition is `j`, which is always true. Also, `j` is never updated inside the loop, causing undefined behavior and likely a crash or hang during execution.]
                {
                    if(str[i+j]>='0'&&str[i+j]<='9')
                    temp1=temp1+up(j)*(str[i+j]-'0');
                    else
                    break;
                }
                
                i=i+j; // @@ [`j` is uninitialized here after the inner for-loop breaks; its value is unpredictable, leading to incorrect index updates and potential out-of-bounds access.]
                if(fuhao[count]=='*')
                {
                    temp=temp1*temp;
                    count++;
                }
                else if(fuhao[count]=='/')
                {
                    temp=temp/temp1; // @@ [Division by zero possible if `temp1` remains 0 due to parsing failure; also, integer division truncation is required but logic is flawed due to incorrect parsing.]
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
        answer=answer+sum[u]; // @@ [Uninitialized elements in `sum` array (beyond `w`) are added, leading to garbage values in the result. Only first `w` elements should be summed.]
    }
    printf("%lld",answer);
    return 0;
 }