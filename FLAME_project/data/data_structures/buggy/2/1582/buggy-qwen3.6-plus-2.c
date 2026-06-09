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
    for(i=1;i<=m;i++) // @@ The loop should start from 1 because operators are stored starting at index 1 in c[1] and c[2], and operands in d start at index 1. Also, the original logic for processing multiplication/division is flawed as it modifies d[i] to 0 which breaks subsequent addition/subtraction logic if not handled carefully, but the primary issue here is the index range and the fact that c[1][0] is uninitialized/garbage.
    {
        if(c[1][i]=='*')
        {
            d[i]=d[i]*d[i+1]; // @@ Update the left operand with the result
            d[i+1]=0; // @@ Mark the right operand as used/zeroed out for later summation
        }
        if(c[1][i]=='/')
        {
            d[i]=d[i]/d[i+1]; // @@ Update the left operand with the result
            d[i+1]=0; // @@ Mark the right operand as used/zeroed out for later summation
        }
    }
    int result = d[1]; // @@ Initialize result with the first number
    for(i=1;i<=m;i++) // @@ Iterate through operators starting from index 1
    {
        if(c[2][i]=='+')
        {
             result += d[i+1]; // @@ Add the next operand
        }
        else if(c[2][i]=='-') // @@ Check for subtraction in c[2], not c[1]
        {
             result -= d[i+1]; // @@ Subtract the next operand
        }
        // Note: Multiplication and division results are already folded into d[i] (the left operand) in the previous loop.
        // The structure of this code is quite messy. The previous loop collapses * and / into the left operand d[i].
        // So for expression 10 + 20 * 30 - 40 / 5
        // d[1]=10, d[2]=20, d[3]=30, d[4]=40, d[5]=5
        // c[2][1]='+', c[1][2]='*', c[2][3]='-', c[1][4]='/'
        // After * loop:
        // i=2: c[1][2]=='*', d[2]=20*30=600, d[3]=0.
        // i=4: c[1][4]=='/', d[4]=40/5=8, d[5]=0.
        // d array: [?, 10, 600, 0, 8, 0]
        // Operators in c[2]: c[2][1]='+', c[2][3]='-'
        // Operators in c[1]: c[1][2]='*', c[1][4]='/'
        
        // The second loop needs to handle + and -.
        // If we just iterate i from 1 to m:
        // i=1: c[2][1]=='+'. result += d[2] (600). result = 10+600=610.
        // i=2: c[2][2] is garbage/empty. c[1][2] is '*'. We should ignore * and / here as they are processed.
        // i=3: c[2][3]=='-'. result -= d[4] (8). result = 610-8=602.
        // i=4: c[2][4] is garbage/empty. c[1][4] is '/'. Ignore.
        
        // The original code's second loop was checking c[1][i]=='-' which is wrong (minus is in c[2]).
        // And it had complex while loops that were incorrect.
    }
    printf("%d",result); // @@ Print the calculated result
    
    

    return 0;
}