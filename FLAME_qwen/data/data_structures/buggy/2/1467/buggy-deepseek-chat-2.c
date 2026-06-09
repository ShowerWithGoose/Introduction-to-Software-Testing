#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str);
    for (int i=0,j=0,k=0;i<strlen(str);i++)
    {
        if (str[i]>='0' && str[i]<='9')
        {
            num=num*10+(str[i]-'0');
            if (str[i+1]<'0' || str[i+1]>'9')
            {
                b[j]=num;
                 j++;
                num=0;             
            }
        }
        if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            c[k]=str[i];
            k++;
        }
        if (str[i]=='=')
        {
            break;
        }
    }

    for (int i=0;i<=strlen(c);i++) // @@ The loop condition should be i < strlen(c) instead of i <= strlen(c) to avoid accessing out-of-bounds index when i equals strlen(c)
    {
        if (c[i]=='*' || c[i]=='/')
        {
            if (c[i]=='*')
            {
                b[i+1]=b[i]*b[i+1];
                b[i]=0;
            }
            if (c[i]=='/')
            
            {
                b[i+1]=b[i]/b[i+1];
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ The loop condition should be i < strlen(c) instead of i <= strlen(c) to avoid accessing out-of-bounds index when i equals strlen(c)
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i];
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ The loop condition should be i < strlen(op) instead of i <= strlen(op) to avoid accessing out-of-bounds index when i equals strlen(op)
    {
        if (op[i]=='+' || op[i]=='-')
        {
            if (op[i]=='+')
            {
                ans[i+1]=ans[i]+ans[i+1];
                ans[i]=0;
            }
            if (op[i]=='-')
            
            {
                ans[i+1]=ans[i]-ans[i+1];
                ans[i]=0;
            }                
        }
        if (ans[i]!=0)
        {
            printf("%d ",ans[i]); // @@ This prints intermediate results with a space, but the problem expects only the final result without extra spaces
        }
    }
    return 0;
}