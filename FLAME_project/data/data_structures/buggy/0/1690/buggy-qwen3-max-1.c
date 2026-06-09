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
            if(i == 0 || str1[i+1] == '\0') { str2[j++] = str1[i]; continue; } // @@ [Missing boundary check: when '-' is at start or end, accessing str1[i-1] or str1[i+1] leads to undefined behavior]
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    if(str1[i+1] <= str1[i-1]) { str2[j++] = '-'; continue; } // @@ [Missing check that second char > first char; expansion should only happen if str1[i+1] > str1[i-1]]
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
                else
                {
                    str2[j++] = '-'; // @@ [If types don't match, '-' should be copied as-is, but this else block is missing]
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    if(str1[i+1] <= str1[i-1]) { str2[j++] = '-'; continue; } // @@ [Same missing check for ordering]
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
                else
                {
                    str2[j++] = '-'; // @@ [Missing else to handle type mismatch]
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    if(str1[i+1] <= str1[i-1]) { str2[j++] = '-'; continue; } // @@ [Same missing check]
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
                else
                {
                    str2[j++] = '-'; // @@ [Missing else for type mismatch]
                }
            }
            else
            {
                str2[j++] = '-'; // @@ [If none of the valid types, '-' should be output as-is, but this case is not handled in original logic]
            }
        }
        else
        str2[j++]=str1[i];
        
    }
    puts(str2);
    
    
    
    return 0;
    
}