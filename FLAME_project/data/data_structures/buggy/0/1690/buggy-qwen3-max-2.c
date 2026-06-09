#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Using gets() is unsafe and may cause buffer overflow; also, j is uninitialized which leads to undefined behavior]
    int i,j,k=0;
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(i == 0 || str1[i+1] == '\0') // @@ [Missing boundary check: when '-' is at start or end, accessing str1[i-1] or str1[i+1] is invalid]
            {
                str2[j++] = str1[i];
                continue;
            }
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    if(str1[i+1] <= str1[i-1]) // @@ [Missing check that second char must be greater than first; otherwise should output '-' as-is]
                    {
                        str2[j++] = '-';
                        continue;
                    }
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
                else
                {
                    str2[j++] = '-'; // @@ [If types don't match, '-' should be copied as-is, but current code skips it]
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    if(str1[i+1] <= str1[i-1]) // @@ [Missing check that second char must be greater than first]
                    {
                        str2[j++] = '-';
                        continue;
                    }
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
                else
                {
                    str2[j++] = '-'; // @@ [Mismatched type: should output '-' unchanged]
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    if(str1[i+1] <= str1[i-1]) // @@ [Missing check that second char must be greater than first]
                    {
                        str2[j++] = '-';
                        continue;
                    }
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
                else
                {
                    str2[j++] = '-'; // @@ [Mismatched type: should output '-' unchanged]
                }
            }
            else
            {
                str2[j++] = '-'; // @@ [If the character before '-' is not in any valid range, '-' should still be output]
            }
        }
        else
        str2[j++]=str1[i];
        
    }
    str2[j] = '\0'; // @@ [Missing null termination if j was never initialized or updated correctly]
    puts(str2);
    
    
    
    return 0;
    
}