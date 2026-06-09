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
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ [Condition (str[i-1]-'a')<=26 should be <=25 because 'z'-'a'=25; this allows invalid characters like '{' to pass. Also, it doesn't ensure str[i+1] is lowercase before printing expansion.]
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ [Same issue: (str[i+1]-'a')<=26 should be <=25. Additionally, after expanding, the loop skips the next character (i+1), but the code doesn't skip it, leading to duplicate output of str[i+1].]
                
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
                printf("%c",str[i]); // @@ [This prints '-' when the condition fails, but if the next condition (uppercase) passes, it will also print '-', causing duplication. The structure allows multiple 'else' branches to execute incorrectly.]
            }
        }
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ [Same off-by-one error: should be <=25. Also, this block is independent of the previous one, so both could run if a char is both in range (which it can't be), but more critically, if the first block fails and prints '-', this block might also fail and print '-' again.]
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){
                
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
                printf("%c",str[i]); // @@ [Same duplication issue: if both lowercase and uppercase checks fail, '-' is printed twice.]
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
            
        } // @@ [Missing else clause for digit case: if digit condition fails, it should print '-', but it doesn't. However, the bigger issue is that the code doesn't handle non-expansion cases uniformly.]
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}