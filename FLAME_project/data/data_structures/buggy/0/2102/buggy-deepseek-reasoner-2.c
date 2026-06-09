#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char st[1000000]={};
    scanf("%s",st);
    for(i=0;i<1000000;i++) // @@ Error: Loop condition should be i<strlen(st) to avoid printing beyond the string's end, causing null/garbage characters.
    {
        
        if('-'==st[i]) // @@ Error: Inside this block, when none of the expansion conditions are true, the '-' should be printed. Currently, no output is produced for such cases, so '-' is lost.
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
        printf("%c",st[i]);
    }
    
    return 0;
}