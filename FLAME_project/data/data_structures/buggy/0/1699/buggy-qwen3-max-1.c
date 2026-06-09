#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; more critically, the loop condition 'i<100' may not process the full input string if it's longer than 100 characters or shorter but null-terminated earlier. Also, the logic fails to handle cases where '-' appears at the start or end of string, leading to out-of-bound access like str[i-1] or str[i+1].]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [Loop bound 'i<100' is arbitrary and doesn't consider actual string length; should use strlen or check for '\0'. Also, j is incremented even when '-' is encountered and then decremented, which can cause misalignment and overwriting.]
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [Decrementing j here assumes that the previous character was written to str1[j], but if multiple '-' are processed or edge cases occur, this leads to incorrect indexing and potential buffer underflow.]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [Condition str[i-1]-'a'>=0 checks if str[i-1] >= 'a', but doesn't ensure it's <= 'z'; similarly, str[i+1]-'z'<=0 means str[i+1] <= 'z', but doesn't ensure it's >= 'a'. So it may incorrectly accept non-lowercase chars like '{' (ASCII 123) which satisfies <= 'z' (122)? Actually 'z' is 122, so '{' is 123 → 123-122=1>0 → condition fails. But more importantly, this logic allows mixed-type expansions like 'A-d' if by chance both conditions pass partially. Also, accessing str[i-1] when i=0 causes undefined behavior.]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) // @@ [This loop expands from str[i-1]+1 to str[i+1]-1, missing the endpoints. According to problem, a-d should become abcd, meaning include both 'a' and 'd'. But original 'a' was already printed before '-', and 'd' will be printed later? However, in this code, the '-' replaces the range, but the original characters around '-' are not properly handled: the left char was already copied, then j-- removes it, and only middle chars are added, and right char is never added. So expansion is incomplete.]
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [Same issues as lowercase: incorrect bounds checking (doesn't verify both ends are uppercase), and unsafe access to str[i-1]/str[i+1].]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [This should be 'else if' to avoid overlapping with letter cases. As written, a digit expansion might be attempted even after a letter condition passed, causing duplication or corruption. Also, same boundary and safety issues.]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
        }
    }
    puts(str1); // @@ [str1 is not null-terminated, so puts() may print garbage beyond intended output.]
 }