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
                printf("%c",str[i]); // @@ This prints '-' when expansion condition fails, but the '-' should be printed only if it is not part of a valid expansion; however, the logic here prints '-' even when the character after '-' is not greater or not same type, which is correct for this case. The actual error is that when the expansion is valid, the '-' itself is not printed, but the expected output includes the '-' for the second '-' in "a-c-g". The code prints the expanded characters but skips printing the '-' that separates the two expansions. The issue is that after processing a valid expansion, the loop continues and the '-' is not output, but the expected output includes it. The code should print the '-' when it is not part of a valid expansion, but here it prints it in the else branch. However, for the input "a-c-g0-A", the first '-' between 'a' and 'c' is expanded correctly, but the second '-' between 'c' and 'g' is also expanded, and the code prints the expanded characters for both, but the expected output "abcdefg0-A" shows that the second '-' should remain as '-' because 'g' is not greater than 'c'? Wait, 'g' > 'c', so it should be expanded. Let's re-analyze: Input "a-c-g0-A": characters: a, -, c, -, g, 0, -, A. The first '-' between a and c: a < c, both lowercase, expand to b. The second '-' between c and g: c < g, both lowercase, expand to d, e, f. The third '-' between 0 and A: 0 is digit, A is uppercase, different types, so no expansion, output '-'. Expected output: "abcdefg0-A". The code's output: "abcdefg0A" (missing the '-'). The bug is that when the second '-' is processed, the code prints the expanded characters but does not print the '-' itself. However, the '-' should not be printed because it is replaced by the expansion. But the expected output includes a '-' after 'g'? Wait, expected output is "abcdefg0-A", which has a '-' between '0' and 'A'. That means the third '-' is not expanded and should be printed. The code's output "abcdefg0A" is missing that '-'. So the error is that the code does not print the '-' when the expansion condition fails for the third '-'. In the else branch for the third '-', the code should print '-', but it does not because the else branch is inside the if block for lowercase, and the third '-' does not satisfy the lowercase condition, so it goes to the next if for uppercase? Actually, the third '-' has str[i-1]='0' and str[i+1]='A'. The first if checks lowercase: str[i-1]-'a' is negative, so condition fails. The second if checks uppercase: str[i-1]-'A' is negative, fails. The third if checks digits: str[i-1]-'0' is 0, condition passes, but then the inner if checks str[i+1]-'0' which is negative because 'A' is not a digit, so the inner condition fails, and there is no else branch for the digit case! So the code does nothing for the third '-', meaning it neither prints the expansion nor the '-'. That's why the '-' is missing. The fix would be to add an else branch for the digit case to print the '-', or restructure the logic. The error is on the line where the digit case's inner if has no else.
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
            // @@ Missing else branch: when the digit case condition fails (e.g., str[i+1] is not a digit or not greater), the '-' should be printed, but it is not handled here.
        }
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}