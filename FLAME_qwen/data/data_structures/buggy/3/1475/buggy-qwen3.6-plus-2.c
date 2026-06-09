#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10005]; 
char real[10005];
int main ()
{
    gets(str); // @@ gets() is removed in the C11 standard, which causes a compilation error in modern compilers; use fgets() instead.
    int i,j,k,flag,flag2,flag3=2; // @@ Variable 'flag' is used without initialization, which may cause undefined behavior or a compilation error with strict warning flags.
    char c;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            flag=i;
            break;
        }
        
    }
    if(flag==1)
    {
        if(str[0]=='0')
        {
            for(i=2;i<len;i++)
        {
            if(str[i]!='0')
            {
            flag2=i;    
            c=str[i];
            break;
            }
        }
        real[0]=c;
        if(flag2!=len-1) {
        real[1]='.';}
        else if(flag2==len-1)
        {
            flag3--;
        }
        for(k=flag3,j=flag2+1;j<len;j++,k++)
        {
            real[k]=str[j];
        }printf("%s",real);    // @@ The 'real' array is not explicitly null-terminated, leading to undefined behavior when printed with %s.
        printf("e-%d",flag2-flag3); // @@ Incorrect exponent calculation; the correct exponent should be 'flag2-1' instead of 'flag2-flag3'.
        }        
        else 
        {
        printf("%s",str);
        printf("e0");
        }
    }
        
    else if(flag>1)
    {
        real[0]=str[0];
        real[1]='.';
        
        for(k=2,j=1;j<len;j++,k++)
    {
        if(j!=flag)
        {
        real[k]=str[j];
        }
        else {
        k--;}
    }
    printf("%s",real); // @@ The 'real' array is not explicitly null-terminated, leading to undefined behavior when printed with %s.
    printf("e%d",flag-1);
    }

    return 0;
}