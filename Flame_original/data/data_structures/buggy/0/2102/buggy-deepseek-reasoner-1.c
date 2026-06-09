#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char st[1000000]={};
    scanf("%s",st);
    for(i=0;i<1000000;i++) // @@ Error: Loop should stop at end of string (e.g., i < strlen(st)) to avoid out-of-bounds access when i=0 and printing null characters beyond input.
    {
        
        if('-'==st[i])
        {
            if((st[i-1]>='0'&&st[i-1]<='9')&&(st[i+1]>='0'&&st[i+1]<='9')&&((st[i+1]-st[i-1])>0)) // @@ Error: When i=0, st[i-1] accesses invalid memory (st[-1]), causing undefined behavior.
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            if((st[i-1]>='a'&&st[i-1]<='z')&&(st[i+1]>='a'&&st[i+1]<='z')&&((st[i+1]-st[i-1])>0)) // @@ Error: Same out-of-bounds issue when i=0.
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            if((st[i-1]>='A'&&st[i-1]<='Z')&&(st[i+1]>='A'&&st[i+1]<='Z')&&((st[i+1]-st[i-1])>0)) // @@ Error: Same out-of-bounds issue when i=0.
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            
            
            
            
            
        }
        
        else
        printf("%c",st[i]);
    }
    
    return 0;
}