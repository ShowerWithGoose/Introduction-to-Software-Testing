#include <stdio.h>
char a[1000],b[1000],c[1000][1000]; // @@ large array on stack may cause stack overflow; consider dynamic allocation
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
    gets(a); // @@ gets is unsafe and deprecated; may cause compilation error in C11
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
    len=strlen(b); // @@ b is not null-terminated; also missing #include <string.h> for strlen
    
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
                d[n]=num(i0,i); // @@ second assignment overwrites with zero; should not be here
                break;
            }
            
            
        }
        
    }
    for(i=0;i<=m;i++) // @@ loop starts at 0, but operators start at index 1; also uses uninitialized c[1][0] and d[0]
    {
        if(c[1][i]=='*') // @@ i=0 accesses uninitialized operator; should start i=1
        {
            d[i+1]=d[i]*d[i+1]; // @@ uses d[0] which is 0; incorrect for first number
            d[i]=0; // @@ sets correct number to zero erroneously
        }
        if(c[1][i]=='/') // @@ same issue with i=0
        {
            d[i+1]=d[i]/d[i+1]; // @@ uses d[0] leading to division by d[1]? Actually d[0]=0, so 0/d[1]=0
            d[i]=0; // @@ sets wrong element to zero
        }
    }
    for(i=0;i<=m;i++) // @@ same issue, i starts at 0; also operators for +- are in c[2]
    {
        if(c[2][i]=='+') // @@ i=0 accesses uninitialized c[2][0]
        {
            while(d[i+1]==0&&i<=m+1) // @@ may cause infinite loop or out-of-bounds; also modifies i inside loop
            {
                d[i+1]+=d[i]; // @@ incorrectly accumulates zero elements
                i++; // @@ modifies loop index incorrectly
            }    
            d[i+1]+=d[i]; // @@ final addition after loop may be incorrect
        }
        if(c[1][i]=='-') // @@ should be c[2][i]=='-'; using wrong array
        {
        while(d[i+1]==0&&i<=m+1) // @@ similar while loop bug
            {
                d[i+1]=d[i]-d[i+1]; // @@ incorrect operation
                i++; // @@ modifies loop index
            }
            d[i+1]=d[i]-d[i+1]; // @@ incorrect final subtraction
        }
    }
    printf("%d",d[i]); // @@ i is modified and may be out of bounds; prints wrong value
    
    
    
    

    return 0;
}