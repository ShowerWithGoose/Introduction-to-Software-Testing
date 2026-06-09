#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char st[1000000]={};
    scanf("%s",st);
    for(i=0;i<1000000;i++) // @@ The loop iterates up to a fixed large number instead of the actual string length, causing it to print null characters or garbage after the string ends. It should iterate until st[i] == '\0' or use strlen(st).
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
            
            
            
            
            
            
        } // @@ Missing an else clause to print the '-' character when none of the expansion conditions are met. According to requirements, invalid ranges should output the input unchanged.
        
        else
        printf("%c",st[i]);
    }
    
    return 0;
}