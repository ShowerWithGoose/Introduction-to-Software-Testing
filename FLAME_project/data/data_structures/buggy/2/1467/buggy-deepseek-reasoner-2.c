#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000]; // @@ [Arrays c and op are not initialized to zero; uninitialized data will cause strlen to read garbage, leading to undefined behavior and missing output for the test case.]
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

    for (int i=0;i<=strlen(c);i++) // @@ [strlen(c) depends on uninitialized c; also condition i<=strlen(c) may cause out-of-bounds access.]
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
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Same issue: strlen(c) on uninitialized array.]
    {
        if (b[i]!=0) // @@ [When the result is 0 (e.g., input "0 ="), b[0] is 0, so this condition fails and the number is never added to ans, causing no output.]
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [c[i] may be garbage if no operators; op array is not initialized.]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [strlen(op) on uninitialized array; undefined behavior.]
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
            printf("%d ",ans[i]);    
        }
    }
    return 0;
}