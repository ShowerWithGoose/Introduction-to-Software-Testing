#include<stdio.h>
#include<string.h>
int main()
{
    char num[108],ans[108];
    gets(num); // @@ [gets() is unsafe and may cause buffer overflow; also, it's not standard in C11 and later, but the main issue is that the problem expects input via scanf, and gets() may not work in all environments]
    int k;
    int i;
    int len=strlen(num);
    for(i=0;i<len;i++)
    {
        if(num[i]=='.')
        {
            k=i;
            break;
        }
        
    }
    int m,n;
    if(k==1)
    {
        if(num[0]=='0'){
        
        for(i=2;i<len;i++)
        {
            if(num[i]!='0')
            {
                m=i;
                break;
            }
        }
        ans[0]=num[m];
        if(m!=(len-1))
        {      ans[1]='.';
            for(i=m+1,n=2;i<len;i++,n++)
            {
                ans[n]=num[i];
            }
        }
        else
        {n=1;
        }
        for(int j=0;j<n;j++)
        {
            printf("%c",ans[j]);
        }
        printf("e-%d",m-1); // @@ [The exponent should be pp-pd where pp is the position of decimal point and pd is the first non-zero digit; here m-1 is incorrect because it doesn't account for the decimal point position correctly]
        
    }
    else
    {
        for(int i=0;i<len;i++){
            printf("%c",num[i]);}
            printf("e0");
        
    }
}
else 
{
    ans[0]=num[0];
    ans[1]='.';
    for(  i=1,m=2;i<len;i++)
    {   
        if(num[i]!='.')
        {
            ans[m]=num[i];
            m++;
        }
    }
    for(int i=0;i<len-1;i++) // @@ [The loop condition should be i<m to print all characters stored in ans, not len-1; this may print incomplete or extra characters]
    {                  
        printf("%c",ans[i]);
              
        
}
printf("e%d",k-1); // @@ [The exponent should be p-1 where p is the position of decimal point; k-1 is correct only if the first digit is non-zero, but the logic for handling cases where k>1 is incomplete]
    
}
return 0;        }