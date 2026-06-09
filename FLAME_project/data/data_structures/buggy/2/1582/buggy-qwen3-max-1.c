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
    //b[j]ÎŞ¿Õ
    len=strlen(b);
    
    for(i=0;i<len;i++)
    {
        if(b[i]>='0'&&b[i]<='9')
        {
            continue;
        }
        else
        {
            d[n]=num(i0,i);//»¹Ô­Êı×Ö 
            
            i0=i;n++;
    
            if(b[i]=='+'||b[i]=='-')
            {
            m++;    c[2][m]=b[i];//´æ´¢¼Ó¼õ·ûºÅ ,mÊÇ·ûºÅÎ»ÖÃ 
    
                
            }
            else if(b[i]=='*'||b[i]=='/') 
            {
                m++;c[1][m]=b[i];//´æ³Ë³ı 
            }
            else
            {
                d[n]=num(i0,i);
                break;
            }
            
            
        }
        
    }
    for(i=0;i<=m;i++)
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
    for(i=0;i<=m;i++)
    {
        if(c[2][i]=='+')
        {
            while(d[i+1]==0&&i<=m+1)
            {
                d[i+1]+=d[i];
                i++;
            }    
            d[i+1]+=d[i];
        }
        if(c[1][i]=='-') // @@ [This condition checks c[1][i] (multiplication/division array) for '-', but '-' is stored in c[2][i]. Should be c[2][i]=='-'.]
        {
        while(d[i+1]==0&&i<=m+1)
            {
                d[i+1]=d[i]-d[i+1]; // @@ [Incorrect logic: when d[i+1] is 0, this sets d[i+1] = d[i] - 0 = d[i], but then later overwrites it. Also, the loop condition and increment interfere with outer loop.]
                i++;
            }
            d[i+1]=d[i]-d[i+1]; // @@ [After handling multiplication/division, d[i] might be zero, leading to wrong subtraction. Also, indices are misaligned because d[0] was never set.]
        }
    }
    printf("%d",d[i]); // @@ [At this point, i equals m+1 due to loop termination, but d[i] may be out of valid range or not the final result. The result should be accumulated in a specific index like d[1] or a running total.]
    
    
    
    

    return 0;
}