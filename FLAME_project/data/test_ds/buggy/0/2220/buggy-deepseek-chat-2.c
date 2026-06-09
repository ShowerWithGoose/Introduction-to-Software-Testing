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
                printf("%c",str[i]); // @@ This prints '-' when expansion condition fails, but the '-' should be printed only if it is not part of a valid expansion; however, the logic here incorrectly prints '-' for cases like '0-A' where the characters are of different types, but the problem requires no expansion and output unchanged, meaning the '-' should be printed. This is actually correct for this case, but the issue is that when expansion is performed, the '-' is not printed, which is correct. The real error is that after expansion, the loop continues and may process the next character incorrectly. The main bug is that when expansion occurs, the program does not skip the expanded characters, so the next character (which was part of the expansion) is printed again. For input "a-c-g0-A", after expanding "a-c" to "abc", the loop index i is at the position of '-', and after printing the expansion, it continues to i+1 which is 'c' (the original next character), but 'c' is already printed as part of expansion, leading to duplicate 'c'. Additionally, the program does not handle the case where '-' is at the end of the string (i+1 out of bounds) or when i+1 is beyond len. The expected output "abcdefg0-A" shows that "a-c-g" should expand to "abcdefg", but the program outputs "abcdefg0A" missing the '-' between '0' and 'A'. This is because when processing the second '-' in "0-A", the condition fails (since '0' and 'A' are different types), so the else branch prints '-', but the program also prints the next character 'A' normally. However, the output shows "0A" without '-', meaning the '-' was not printed. This suggests that the else branch for the digit case is missing, as the digit case does not have an else clause. Indeed, in the digit case, there is no else to print '-', so when the expansion condition fails (e.g., '0' and 'A' are different types), the '-' is simply skipped. That is the primary error: the digit case lacks an else branch to print the '-' when expansion is not performed.
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
                printf("%c",str[i]);
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
            // @@ Missing else clause: when the digit expansion condition fails (e.g., different types or str[i+1] <= str[i-1]), the '-' should be printed, but it is not. This causes the '-' to be omitted in cases like "0-A".
        }
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}