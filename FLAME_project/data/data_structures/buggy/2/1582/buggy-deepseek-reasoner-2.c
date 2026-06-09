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
    int i,j=0,i0=-1,m=0,n=1,len;
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
    //b[j]ÊÇ¿Õ
    len=strlen(b); // @@ array b is not null-terminated, causing undefined length
    for(i=0;i<len;i++)
    {
        if(b[i]>='0'&&b[i]<='9')
        {
            continue;
        }
        else
        {
            d[n]=num(i0,i);//@@ numbers stored starting at d[1], d[0] remains 0, causing off-by-one in later loops
            i0=i;n++;
            if(b[i]=='+'||b[i]=='-')
            {
            m++;    c[2][m]=b[i];//@@ operator index m starts at 1, later loops use i from 0, misalignment and uninitialized c[2][0]
                
            }
            else if(b[i]=='*'||b[i]=='/') 
            {
                m++;c[1][m]=b[i];//@@ same operator index offset issue
            }
            else
            {
                d[n]=num(i0,i);
                break;
            }
            
            
        }
        
    }
    for(i=0;i<=m;i++) //@@ loop should start from i=1; d[0] is invalid and used here
    {
        if(c[1][i]=='*') //@@ for i=0, c[1][0] is uninitialized, may cause spurious multiplication
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
    for(i=0;i<=m;i++)
    {
        if(c[2][i]=='+')
        {
            while(d[i+1]==0&&i<=m+1) //@@ incorrect logic: zero can be valid, and condition may cause out-of-bounds
            {
                d[i+1]+=d[i];
                i++;
            }    
            d[i+1]+=d[i];
        }
        if(c[1][i]=='-') //@@ should be c[2][i]; '-' is stored in c[2] not c[1]; also uninitialized for i=0
        {
        while(d[i+1]==0&&i<=m+1)
            {
                d[i+1]=d[i]-d[i+1];
                i++;
            }
            d[i+1]=d[i]-d[i+1];
        }
    }
    printf("%d",d[i]); //@@ i is the loop variable after looping, likely d[m+1] not the final result
    
    
    
    

    return 0;
}