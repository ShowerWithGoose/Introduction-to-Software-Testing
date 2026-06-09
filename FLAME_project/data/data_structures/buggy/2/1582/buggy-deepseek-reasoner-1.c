#include <stdio.h>
char a[1000],b[1000],c[1000][1000];
int d[1000]={0};
int num(int i0,int i)
{
    int k1,j=0;
    for(k1=i0+1;k1<i;k1++)
    {
        j=j*10+b[k1]-'0';
    }
    return j;
    
}
int main()
{
    int i,j=0,i0=-1,m=0,n=1,len; // @@ n should be initialized to 0, because the first number should be stored in d[0]; d[0] is currently unused, causing misalignment.
    gets(a); 
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
        {
            continue;
        }
        else
        {
            b[j]=a[i];
            j++;
        }
    }
    //b[j]ÎŞ¿Õ
    len=strlen(b); // @@ b is not null-terminated; strlen(b) may produce incorrect length; should use j as the length instead.
    
    for(i=0;i<len;i++) // @@ Using len from strlen(b) is unsafe; loop may read beyond actual data.
    {
        if(b[i]>='0'&&b[i]<='9')
        {
            continue;
        }
        else
        {
            d[n]=num(i0,i); // @@ First number is stored into d[1] (since n=1), leaving d[0]=0; this causes incorrect results when later loops start from i=0.
            
            i0=i;n++;
    
            if(b[i]=='+'||b[i]=='-')
            {
            m++;    c[2][m]=b[i];//´æ´¢¼Ó¼õ·ûºÅ ,mÊÇ·ûºÅÎ»ÖÃ // @@ Operators are stored starting at index m=1, but later loops start at i=0, so c[2][0] and c[1][0] are uninitialized.

                
            }
            else if(b[i]=='*'||b[i]=='/') 
            {
                m++;c[1][m]=b[i];//´æ³Ë³ı // @@ Same issue: operators stored from index 1.
            }
            else
            {
                d[n]=num(i0,i);
                break;
            }
            
            
        }
        
    }
    for(i=0;i<=m;i++) // @@ Should start from 1 because the first operator is at index 1; starting from 0 uses uninitialized c[1][0] and d[0].
    {
        if(c[1][i]=='*')
        {
            d[i+1]=d[i]*d[i+1];
            d[i]=0;
        }
        if(c[1][i]=='/')
        {
            d[i+1]=d[i]/d[i+1];
            d[i]=0;
        }
    }
    for(i=0;i<=m;i++) // @@ Should start from 1 for the same reason.
    {
        i=0; // @@ This line resets i to 0 every iteration, causing an infinite loop or incorrect behavior.
        if(c[2][i]=='+')
        {
            while(d[i+1]==0&&i<=m+1) // @@ Flawed logic for handling zeros; does not correctly combine results.
            {
                d[i+1]+=d[i];
                i++;
            }    
            d[i+1]+=d[i];
        }
        if(c[1][i]=='-') // @@ Should be c[2][i] because subtraction is stored in c[2]; c[1] holds multiplication/division only.
        {
        while(d[i+1]==0&&i<=m+1) // @@ Same flawed logic.
            {
                d[i+1]=d[i]-d[i+1];
                i++;
            }
            d[i+1]=d[i]-d[i+1];
        }
    }
    printf("%d",d[i]); // @@ i is the loop variable after the last iteration, which is m+1 (or m+2 due to reset); this prints the last number instead of the final result.
    
    
    
    

    return 0;
}