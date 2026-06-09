#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int len,i,space=0,j=0,k=0,lensymbol,lensenior,lenlower,digit=0,ten=1,lenlast,output=0;;
    char b[100],a[100];
    int symbol[100],lower[100],after[100],senior[100],last[100];
    gets(b);
    len=strlen(b);
    for(i=0;i<100;i++)
    {
        after[i]=0;
    }
    for(i=0;i<len;i++)
    {
        if(b[i]!=32)
        {
            a[j]=b[i];
            j++;
        }
        if(b[i]==32)
        {
            space++;
        }
    }
    len=len-space;
    j=0;
    for(i=0;i<len;i++)
    {
        if(a[i]=='+' || a[i]=='-' || a[i]=='*' ||a[i]=='/'||a[i]=='=')
        {
            for(k=i-1,ten=1;k>i-1-digit;k--)
            {
                after[j]=after[j]+(a[k]-48)*ten;
                ten=ten*10;
            }
            after[j+1]=a[i]-48;
            j=j+2;
            digit=0;
        }
        else
        {
            digit++;
        }
    }
    len=j;
    after[len-1]=-2;
    j=1;
    k=0;

    lower[0]=-1;
    for(i=0;i<len;i++)
    {
        if(after[i]==-5 || after[i]==-3 || after[i]==-2)
        {
            lower[j]=i;
            j++;
        }
    }
    lenlower=j;
    k=0;
    for(i=0;i<lenlower-1;i++)
    {
        last[k]=after[lower[i]+1];
        for(j=lower[i]+2;j<lower[i+1]-1;j=j+2)
        {
            if(after[j]==-6)
            {
                last[k]=last[k]*after[j+1];
            }
            if(after[j]==-1)
            {
                last[k]=last[k]/after[j+1];
            }
        }
        k=k+1;
    }
    lenlast=k;
    k=0;
    for(i=0;i<len;i++)
    {
        if(after[i]==-5 || after[i]==-3 || after[i]==-2)
        {
            senior[k]=after[i];
            k=k+1;
        }
    }
    output=last[0];
    for(i=0;i<lenlast-1;i++)
    {
        if(senior[i]==-5)
        {
            output=output+last[i+1];
        }
        if(senior[i]==-3)
        {
            output=output-last[i+1];
        }
    }
    printf("%d",output);
    return 0;
}
