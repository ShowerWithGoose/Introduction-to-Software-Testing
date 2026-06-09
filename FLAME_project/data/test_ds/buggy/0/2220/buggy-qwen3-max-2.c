#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str);
    //printf("%c",str[3]);
    int len=strlen(str);
    //printf("%d",len);
    printf("%c",str[0]); 
    for(int i=1;i<len;i++)
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ @@ [The condition (str[i-1]-'a')<=26 is incorrect; 'z'-'a' is 25, so it should be <=25. Also, this allows non-lowercase chars like '{' to pass.]
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ @@ [Same issue: (str[i+1]-'a')<=26 should be <=25. Additionally, negative values are not properly excluded because (str[i+1]-'a')>=0 alone doesn't guarantee it's a lowercase letter if char is signed and value is negative.]
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            else {
                printf("%c",str[i]); @@ [This prints '-' even when the first condition (lowercase) fails but another type (e.g., digit) might apply later. However, due to separate if blocks, multiple conditions may be checked, leading to duplicate '-' output or missed logic.]
            }
        }
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ @@ [Same error: should be <=25 for uppercase range. Also, doesn't ensure str[i-1] is actually uppercase.]
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ @@ [Same issue with <=26 instead of <=25.]
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            else {
                printf("%c",str[i]); @@ [Again, prints '-' in else block even if previous lowercase condition already handled it or if digit condition might still apply. This causes extra '-' to be printed when multiple type checks fail.]
            }
        }
            if(((str[i-1]-'0')>=0 )&& ((str[i-1]-'0')<=9)){
            if(((str[i+1]-'0')>=0 && (str[i+1]-'0')<=9)&&(str[i+1]>str[i-1])){
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            
        } @@ [Missing else clause here: if digit condition fails, and previous conditions also failed, the '-' should be printed, but it isn't handled here. However, due to earlier else blocks, '-' might have already been printed incorrectly.]
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}