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
    gets(a); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to compilation error.]
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
    len=strlen(b); // @@ [Missing #include <string.h> for `strlen`, which causes a compilation error.]

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
        if(c[1][i]=='-') // @@ [This should check `c[2][i]` for '-', not `c[1][i]`. This is a logical error but not the cause of compilation failure. However, note that the compilation errors are due to missing headers and use of `gets`.]
        {
        while(d[i+1]==0&&i<=m+1)
            {
                d[i+1]=d[i]-d[i+1];
                i++;
            }
            d[i+1]=d[i]-d[i+1];
        }
    }
    printf("%d",d[i]); // @@ [At this point, `i` has been incremented beyond valid indices in previous loops, leading to undefined behavior. But again, the immediate issue preventing compilation is missing headers and `gets`.]
    
    
    
    

    return 0;
}