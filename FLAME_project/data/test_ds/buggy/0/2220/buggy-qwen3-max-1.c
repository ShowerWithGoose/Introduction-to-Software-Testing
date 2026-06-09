#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logical error is elsewhere.]
    //printf("%c",str[3]);
    int len=strlen(str);
    //printf("%d",len);
    printf("%c",str[0]); 
    for(int i=1;i<len;i++)
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ [Condition (str[i-1]-'a')<=26 is incorrect; 'z'-'a'=25, so should be <=25. Also, this allows non-lowercase chars like '{' to pass.]
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ [Same issue: (str[i+1]-'a')<=26 should be <=25. This causes invalid ranges like a-{ to be expanded.]
                
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
                printf("%c",str[i]); // @@ [This prints '-' even when the next character is not of the same type or invalid, but it should print '-' only if expansion condition fails. However, the bigger issue is that after printing expanded chars, the next character (after '-') is skipped in output.]
            }
        }
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ [Same error: should be <=25 for uppercase letters ('Z'-'A'=25).]
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ // @@ [Same error: should be <=25.]
                
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
                printf("%c",str[i]); // @@ [Same issue: may print '-' unnecessarily, and fails to handle cases where first condition (lowercase) fails but second (uppercase) might apply — but due to separate ifs, both could trigger incorrectly. Also, after expanding, the character after '-' is never printed because loop moves forward.]
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
            
        } // @@ [Missing else clause to print '-' when digit expansion fails. So for cases like 0-A, the '-' is not printed at all, leading to missing '-'.]
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}