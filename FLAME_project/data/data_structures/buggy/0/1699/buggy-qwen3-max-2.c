#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str);
    int i,j;
    for(i=0,j=0;i<100;i++,j++)
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; @@ // The decrement of j is incorrect here because the previous character was already copied in the last iteration; this leads to overwriting or skipping characters.
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) @@ // Condition str[i+1]-'z'<=0 is wrong: it should check if str[i+1] <= 'z', but written as str[i+1] - 'z' <= 0 which is equivalent, however combined with str[i-1]-'a'>=0 (i.e., str[i-1] >= 'a'), it fails to ensure both are lowercase. Also, does not use islower(), so may misclassify non-letter chars.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) @@ // Loop condition uses < instead of <=, so it omits the last character (e.g., a-d becomes abc, missing 'd').
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) @@ // Same issues: incorrect range checks and missing inclusion of end character.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) @@ // Should be t <= str[i+1] to include the end character.
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) @@ // This should be 'else if' to avoid overlapping with letter cases; also same loop issue. Additionally, condition str[i-1]-'0'>=0 is always true for digits but also true for letters/symbols above '0', so unsafe.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) @@ // Missing end character due to < instead of <=.
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
        }
    }
    puts(str1); @@ // The output string str1 is not null-terminated, leading to undefined behavior when printed with puts().
 }