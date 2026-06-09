#include <stdio.h>
#include <string.h>
char s[10000],c[10000];
int a[10000],b[10000],d[10000];
int main()
{
    gets(s);
    int i1,j1;
    for(i1=j1=0;s[i1]!='\0';i1++)
    if(s[i1]!=' ')
    s[j1++]=s[i1];
    s[j1]='\0';  
    int len=strlen(s);
    int i2,ci=0,ai=0;
    for(i2=0;i2<len;i2++)
    {
        if(s[i2]=='+'||s[i2]=='-'||s[i2]=='*'||s[i2]=='/')
        {
            c[ci]=s[i2];
            ci++;
        }
        if(s[i2]>='0'&&s[i2]<='9')
        {
            int length=0,i3=i2;
            while(s[i3]>='0'&&s[i3]<='9')
            {
                length++;
                i3++;
            }
            i3=i2;
            for(int i=0;i<length;i++)
            b[i]=s[i3++]-'0';
            for(int i=length-1;i>=0;i--)
            for(int j=0;j<i;j++)
            b[length-i-1]*=10; // @@ [Error: This loop incorrectly multiplies b[length-i-1] by 10 for each j, instead of properly constructing the number from digits. For example, for number 24, it sets b[0]=2, b[1]=4, then for i=1 (length-1=1), it multiplies b[0] by 10 once, giving 20, but for i=0, it does nothing, so b[1] remains 4, and later a[ai] adds b[0]+b[1]=24, which works for this case but fails for multi-digit numbers like 123 because the logic is flawed.]
            for(int i=0;i<length;i++)
            a[ai]+=b[i];
            ai++;
            i2=i3-1;
        }
    }
    if(ci==0)
    printf("%d",a[0]);
    else
    {
        int i4=0;
        if(c[0]=='+'||c[0]=='-')
        {
            d[i4]=a[0];
            i4++;
        }
        for(int i1=0;i1<ci;i1++)
        {
            if((c[i1]=='+'||c[i1]=='-')&&(c[i1+1]=='+'||c[i1+1]=='-'))
            {
                d[i4]=a[i1+1];
                i4++;
            }
            if(c[i1]=='*'||c[i1]=='/')
            {
                int i2=i1,length=0;
                if(c[i1]=='*')
                d[i4]=a[i1]*a[i1+1];
                else
                d[i4]=a[i1]/a[i1+1];
                while(c[i2]=='*'||c[i2]=='/')
                {
                    i2++;
                    length++;
                }
                for(int i3=1;i3<length;i3++)
                {
                    if(c[i1+i3]=='*')
                    d[i4]*=a[i1+i3+1];
                    else
                    d[i4]/=a[i1+i3+1];
                }
                i1=i2-1;
                i4++;
            }
        }
        int sum=0,j=0,k;
        for(int i=0;i<ci;i++)
        {
            if(c[i]=='+'||c[i]=='-')
            {
                k=i;
                break;
            }
        }
        if(c[k]=='+')
        {
            sum=d[0]+d[1];
            j=2;
        }
        if(c[k]=='-')
        {
            sum=d[0]-d[1];
            j=2;
        }
        for(int i=k+1;i<ci;i++)
        {
            if(c[i]=='+')
            {
                sum+=d[j];
                j++;
            }
            if(c[i]=='-')
            {
                sum-=d[j];
                j++;
            }
        }
        if(c[ci-1]=='+')
        sum+=a[ai-1];
        if(c[ci-1]=='-')
        sum-=a[ai-1];
        printf("%d",sum);
    }
    return 0;
}