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
    for(i=0;i<=m;i++) // @@ loop starts at 0, but d[0] is 0 and operator indices start at 1, causing incorrect evaluation
    {
        if(c[1][i]=='*') // @@ c[1][0] is uninitialized; also uses wrong index alignment
        {
            d[i+1]=d[i]*d[i+1]; // @@ uses d[0]=0, gives wrong result
            d[i]=0;
        }
        if(c[1][i]=='/') // @@ c[1][0] is uninitialized; also uses wrong index alignment
        {
            d[i+1]=d[i]/d[i+1]; // @@ uses d[0]=0, leads to division by zero or incorrect result
            d[i]=0;
        }
    }
    for(i=0;i<=m;i++) // @@ same issue: loop starts at 0
    {
        if(c[2][i]=='+') // @@ c[2][0] is uninitialized; wrong index alignment
        {
            while(d[i+1]==0&&i<=m+1) // @@ modifies i inside loop, causing skipping of indices
            {
                d[i+1]+=d[i];
                i++;
            }    
            d[i+1]+=d[i];
        }
        if(c[1][i]=='-') // @@ error: should be c[2][i] for subtraction, c[1] is for multiplication/division
        {
        while(d[i+1]==0&&i<=m+1) // @@ modifies i inside loop, causing skipping of indices
            {
                d[i+1]=d[i]-d[i+1];
                i++;
            }
            d[i+1]=d[i]-d[i+1];
        }
    }
    printf("%d",d[i]); // @@ i has been modified in loops and may not point to the final result
    return 0;
}