#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char a[100];
long long num[100];
char sym[100];
    gets(a);
    long long length=strlen(a),x=0,m=0,n=0,temp=0,flag=0,ans;
    int i,j,k;
    for(i=0,j=0;i<length;)
        {
        if(a[i]==' ')
        {
            i++;
            x++;
        }
    else
        {
            a[j]=a[i];
            j++;
            i++;
        }
    }
    a[length-x]='\0';
    length=strlen(a);
    for(i=0;i<length;i++)
        {
            if(a[i]<='9'&&a[i]>='0')
            {
                temp+=a[i]-'0';
            if(a[i+1]<='9'&&a[i+1]>='0')
            {
                temp*=10;
            }
            }
            else if(a[i]=='=')
                {
                num[m]=temp;
                m++;
                temp=0;
            }
            else
                {
                num[m]=temp;
                temp=0;
                sym[n]=a[i];
                m++;
                n++;
            }
        }
    for(i=0;i<n;i++)
        {
        if(sym[i]=='*')
        {
            num[i+1]=num[i]*num[i+1];
            num[i]=-1;
        }
    else if(sym[i]=='/')
        {
            num[i+1]=num[i]/num[i+1];
            num[i]=-1;
        }
    }
    for(i=0;i<m;i++)
        {
        if(num[i]==-1)
        {
            for(j=i;j<m;j++)
            {
                num[j]=num[j+1];
            }
            m--;
            i--;
        }
    }
    ans=n;
    for(i=0;i<n;i++)
    {
        if(sym[i]=='*'||sym[i]=='/')
        {
            for(j=i;j<n;j++)
            {
                sym[j]=sym[j+1];
            }
            ans--;
            i--;
        }
    }
    n=ans;
    for(i=0;i<n;i++)
    {
        if(sym[i]=='+')
        {
            num[i+1]=num[i]+num[i+1];
        }
    else if(sym[i]=='-')
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%lld\n",num[m-1]);
    return 0;
}



