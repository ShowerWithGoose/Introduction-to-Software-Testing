#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; more critically, the loop condition 'i<100' may not process the full input string if it's longer or shorter than 100 characters. Also, the logic fails to handle cases where '-' appears at the start or end of string, leading to out-of-bound access like str[i-1] or str[i+1].]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [Loop runs only 100 times regardless of actual string length; should run until end of string (e.g., while str[i] != '\0'). This causes truncation or incomplete processing.]
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [Decrementing j here assumes that the previous character was already added to str1, but if multiple '-' are processed or edge cases occur, this can lead to overwriting or incorrect indexing. Also, if '-' is the first character (i=0), str[i-1] is invalid.]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [Condition is logically flawed: 'str[i-1]-'a'>=0' checks if char >= 'a', but doesn't ensure it's <= 'z'. Similarly, 'str[i+1]-'z'<=0' means str[i+1] <= 'z', but doesn't ensure it's >= 'a'. So it may accept non-lowercase chars like '{' (ASCII > 'z') as valid. Should use islower() or explicit range check like (ch >= 'a' && ch <= 'z'). Also, accessing str[i+1] when i is near end of string causes buffer overread.]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) // @@ [This loop expands from str[i-1]+1 to str[i+1]-1, which omits the starting character (already printed) but also omits the ending character. However, the problem expects inclusive expansion (e.g., a-d → abcd). But note: the original character before '-' was already copied in the 'if(str[i]!='-')' block, so this tries to fill the middle. However, due to j-- above, it overwrites the last written char. Moreover, if expansion shouldn't happen (like B-e), this block shouldn't run, but the flawed condition may allow it or skip incorrectly.]
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [Same logical flaw as lowercase check: doesn't properly validate that both chars are uppercase letters. For example, '[' - 'A' >= 0 is true, but '[' is not uppercase. Also, no handling for mixed-type like B-e (uppercase followed by lowercase), which should NOT expand — but this condition might not catch it correctly due to improper bounds.]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [Again, flawed digit check: 'str[i-1]-'0'>=0' allows any char >= '0', including letters and symbols. Should check (ch >= '0' && ch <= '9'). Also, this is an 'if' instead of 'else if', so if a digit range matches after a failed letter range, it could incorrectly expand. But more importantly, for input "B-e", none of the conditions should trigger, but due to incorrect bounds, it might skip expansion correctly — however, the bigger issue is that the '-' itself is never appended when expansion doesn't occur. In this code, when str[i]=='-', it does j-- and then only adds expansion chars; if no expansion happens, the '-' is lost and the previous char may be duplicated or overwritten. For "B-e", it sees '-', does j--, then none of the conditions match (because 'B' is uppercase, 'e' is lowercase → mixed type), so it doesn't add anything, and the '-' is never output. Hence output becomes "Be" instead of "B-e".]
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
    puts(str1); // @@ [str1 is not null-terminated, so puts() may print garbage beyond the intended output. Also, because the loop runs fixed 100 times and doesn't track actual end, str1 may contain uninitialized data.]
 }