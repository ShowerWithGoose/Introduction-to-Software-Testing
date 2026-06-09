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
            b[length-i-1]*=10;
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
                while(c[i2]=='*'||c[i2]=='/')  // @@ [i2 may be incremented beyond valid index, causing out-of-bounds access]
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
        if(c[k]=='+')  // @@ [k may be uninitialized if no '+' or '-' found, leading to undefined behavior]
        {
            sum=d[0]+d[1];
            j=2;
        }
        if(c[k]=='-')  // @@ [same uninitialized k issue]
        {
            sum=d[0]-d[1];
            j=2;
        }
        for(int i=k+1;i<ci;i++)  // @@ [k may be uninitialized, causing invalid loop start]
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