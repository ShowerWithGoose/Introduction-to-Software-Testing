#include<stdio.h>
#include<string.h>
int main()
{
    char s[105],a[105]={0},b[105]={0};
    int i=0,j=0,k,nc,last,c[105]={0},bnum[105]={0},answer,lena,lenb,sum[105]={0},sumnum[105]={0},ans[105]={0};
    gets(s);
    for(i=0;s[i]!='=';i++)
    {
        if(s[i]!=' ')
            a[j++]=s[i];
    }
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
        {
            b[j]=a[i];
            bnum[j]=i;
            j++;
        }
    }
    if(j==0)
    {
        puts(a);
        return 0;
    }
    lena=strlen(a);lenb=strlen(b);
    j=1;
    for(i=bnum[0]-1;i>=0;i--)
    {
        c[0]+=j*(a[i]-'0');
        j*=10;
    }
    for(i=0;bnum[i]!=0;i++)
    {
        j=1;
        for(k=bnum[i+1]-1;k>bnum[i];k--)
        {
            c[i+1]+=j*(a[k]-'0');
            j*=10;
        }
    }
   last=i;j=1;
    for(i=lena-1;i>=0;i--)
    {
        if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/') break;
        else
        {
            c[last]+=j*(a[i]-'0');
            j*=10;
        }
    }
    for(i=0,j=0;b[i]!=0;i++)
    {
        if(b[i]=='+' || b[i]=='-')
        {
            sum[j]=b[i];
            sumnum[j]=i;
            j++;
        }
    }
    if(j==0)
    {
        answer=c[0];
        for(i=0;i<last;i++)
        {
            if(b[i]=='*') answer*=c[i+1];
            else answer/=c[i+1];
        }
        printf("%d",answer);
        return 0;
    }
    ans[0]=c[0];
    for(k=0;k<sumnum[0];k++)
    {
            if(b[k]=='*') ans[0]*=c[k+1];
            else ans[0]/=c[k+1];
    }
    for(i=0;i<j;i++)
    {
        if(sumnum[i+1]-sumnum[i]!=1)
        {
            ans[i+1]=c[sumnum[i]+1];
            for(k=sumnum[i]+1;k<sumnum[i+1];k++)
            {
                if(b[k]=='*') ans[i+1]*=c[k+1];
                else ans[i+1]/=c[k+1];
            }
        }
        else ans[i+1]=c[sumnum[i]+1];
    }
    ans[i]=c[sumnum[i-1]+1];
    for(k=sumnum[i-1]+1;b[k]!=0;k++)
    {
            if(b[k]=='*') ans[i]*=c[k+1];
            else ans[i]/=c[k+1];
    }
    answer=ans[0];
    for(j=0;j<=i;j++)
    {
        if(sum[j]=='+')
            answer+=ans[j+1];
        else
            answer-=ans[j+1];
    }
        printf("%d",answer);
}

