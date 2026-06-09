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
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){
                
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
                printf("%c",str[i]); // @@ This prints '-' when expansion condition fails, but the '-' should be printed only if it is not part of a valid expansion; however, the logic here incorrectly prints '-' for cases like '0-A' where the characters are of different types, but the expected output for "a-c-g0-A" is "abcdefg0-A", meaning the '-' between 'g' and '0' should be printed as is. The issue is that when the first condition (lowercase) fails, it prints '-' immediately, but the code should check all three type conditions before deciding to print '-'. In this specific input, after processing 'c-g', the loop continues and when i points to the '-' between 'g' and '0', the lowercase condition fails (since '0' is not lowercase), so it prints '-', which is correct. However, the bug is that for the '-' between '0' and 'A', the digit condition fails (since 'A' is not a digit), and there is no else clause for the digit condition, so the '-' is not printed at all, causing the output to miss it. The expected output includes this '-', so the error is that the digit condition's else branch is missing.
            }
        }
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){
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
                printf("%c",str[i]); // @@ Similar issue: this prints '-' when uppercase condition fails, but for the '-' between '0' and 'A', the uppercase condition also fails (since '0' is not uppercase), so this else would print '-', but the code structure means that after the lowercase condition's else prints '-', the uppercase condition is still checked. For the '-' between '0' and 'A', the lowercase condition fails and prints '-', then the uppercase condition fails and prints '-' again, resulting in two '-' characters. The expected output has only one '-', so the logic is flawed. The correct approach is to check all three type conditions and only print '-' if none of them result in expansion.
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
            // @@ Missing else clause: if the digit condition fails (e.g., for '-' between '0' and 'A'), the '-' should be printed, but there is no else here, so the '-' is not printed, causing the output to miss it.
        }
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}