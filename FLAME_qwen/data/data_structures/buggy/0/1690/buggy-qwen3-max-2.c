#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Also, 'gets' was removed in C11 standard, leading to compilation errors on modern compilers.]
    int i,j,k=0; // @@ [Variable 'j' is used uninitialized when writing to 'str2[j++]', leading to undefined behavior.]
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Loop condition should be k <= (str1[i+1] - str1[i-1]) to include the end character. Also, reusing 'k' here conflicts with its use as the output index.]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue: loop condition excludes the end character and reuses 'k' incorrectly.]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue: loop condition excludes the end character and reuses 'k' incorrectly.]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            // @@ [Missing 'else' case: when '-' is not part of a valid expansion (e.g., at start, end, or between mismatched types), it should be copied as-is. Current code skips copying '-', causing incorrect output.]
        }
        else
        str2[j++]=str1[i];
        
    }
    puts(str2); // @@ ['str2' is not null-terminated, which leads to undefined behavior when passed to 'puts'.]
    
    
    
    return 0;
    
}