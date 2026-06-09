#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Using gets() is unsafe and may cause buffer overflow; also, j is uninitialized which leads to undefined behavior when used in str2[j++]]
    int i,j,k=0;
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(i == 0 || str1[i+1] == '\0') // @@ [Missing boundary check: if '-' is at start or end, accessing str1[i-1] or str1[i+1] causes out-of-bounds read]
            {
                str2[j++] = str1[i];
                continue;
            }
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    if(str1[i+1] > str1[i-1]) // @@ [Missing check that the second char is greater than the first; without it, loop condition may be invalid or skip needed expansion]
                    {
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                    else
                    {
                        str2[j++] = str1[i];
                    }
                }
                else
                {
                    str2[j++] = str1[i];
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    if(str1[i+1] > str1[i-1]) // @@ [Same missing greater-than check as above]
                    {
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                    else
                    {
                        str2[j++] = str1[i];
                    }
                }
                else
                {
                    str2[j++] = str1[i];
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    if(str1[i+1] > str1[i-1]) // @@ [Same missing greater-than check as above]
                    {
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                    else
                    {
                        str2[j++] = str1[i];
                    }
                }
                else
                {
                    str2[j++] = str1[i];
                }
            }
            else
            {
                str2[j++] = str1[i]; // @@ [Missing else clause to handle cases where types don't match (e.g., a-Z), causing '-' to be silently skipped instead of copied]
            }
        }
        else
        str2[j++]=str1[i];
        
    }
    str2[j] = '\0'; // @@ [Missing null termination if last character was '-', leading to garbage output]
    puts(str2);
    
    
    
    return 0;
    
}