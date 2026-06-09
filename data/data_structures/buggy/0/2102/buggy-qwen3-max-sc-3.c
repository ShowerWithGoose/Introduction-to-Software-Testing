#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char st[1000000]={};
    scanf("%s",st);
    for(i=0;i<1000000;i++)
    {
        
        if('-'==st[i])
        {
            if((st[i-1]>='0'&&st[i-1]<='9')&&(st[i+1]>='0'&&st[i+1]<='9')&&((st[i+1]-st[i-1])>0))
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            if((st[i-1]>='a'&&st[i-1]<='z')&&(st[i+1]>='a'&&st[i+1]<='z')&&((st[i+1]-st[i-1])>0))
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            if((st[i-1]>='A'&&st[i-1]<='Z')&&(st[i+1]>='A'&&st[i+1]<='Z')&&((st[i+1]-st[i-1])>0))
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            
            
            
            
            
        }
        
        else
        printf("%c",st[i]); @@ [Accessing st[i-1] when i=0 leads to out-of-bounds read (undefined behavior); also, loop runs fixed 1000000 times instead of until end of string, causing unnecessary output of null bytes and potential access beyond input length]
    }
    
    return 0;
}