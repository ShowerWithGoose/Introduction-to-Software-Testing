#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char st[1000000]={};
    scanf("%s",st);
    for(i=0;i<1000000;i++) @@ [Loop bound should be strlen(st) to avoid reading out-of-bounds and printing garbage. Also, need to ensure i>0 and i<len-1 when accessing st[i-1] and st[i+1].]
    {
        
        if('-'==st[i])
        {
            if((st[i-1]>='0'&&st[i-1]<='9')&&(st[i+1]>='0'&&st[i+1]<='9')&&((st[i+1]-st[i-1])>0)) @@ [Potential out-of-bounds access at i=0 or i=len-1; add boundary checks.]
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            if((st[i-1]>='a'&&st[i-1]<='z')&&(st[i+1]>='a'&&st[i+1]<='z')&&((st[i+1]-st[i-1])>0)) @@ [Same out-of-bounds issue.]
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            }
            
            if((st[i-1]>='A'&&st[i-1]<='Z')&&(st[i+1]>='A'&&st[i+1]<='Z')&&((st[i+1]-st[i-1])>0)) @@ [Same out-of-bounds issue.]
            {
                for(j=0;j<st[i+1]-st[i-1]-1;j++)
                {
                    printf("%c",st[i-1]+j+1);
                }
            } @@ [Missing else: when none of the expansion conditions are met, the dash '-' should be printed. Currently it is omitted.]
            
            
            
            
            
            
        }
        
        else
        printf("%c",st[i]);
    }
    
    return 0;
}