#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10005]; 
char real[10005];
int main ()
{
    gets(str);
    int i,j,k,flag,flag2,flag3=2; // @@ flag and flag2 are uninitialized; using them later leads to undefined behavior
    char c; // @@ c is uninitialized; used in line 33
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
        }printf("%s",real); // @@ real array is not null-terminated – printf prints garbage
        printf("e-%d",flag2-flag3); // @@ exponent calculation is incorrect: should be flag2-1, not flag2-flag3
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
    printf("%s",real); // @@ real array is not null-terminated – printf prints garbage
    printf("e%d",flag-1);
    }

    return 0;
}