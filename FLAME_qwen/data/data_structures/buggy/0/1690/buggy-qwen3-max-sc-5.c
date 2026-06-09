#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, 'gets' was removed in C11 standard, leading to compilation error on modern compilers]
    int i,j,k=0; // @@ [Variable 'j' is used uninitialized when writing to str2[j++], leading to undefined behavior; though not a compilation error, it's a critical logical flaw. However, the reported error is compilation-related, so primary issue is 'gets']
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Loop condition should be k <= (str1[i+1] - str1[i-1]) to include the end character; current logic omits the last character. Also, reusing loop variable 'k' conflicts with outer 'k' used for str2 indexing, causing incorrect output. But this is a logical error, not compilation.]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue as above: incorrect loop bound and reuse of 'k']
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue as above: incorrect loop bound and reuse of 'k']
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
        }
        else
        str2[j++]=str1[i]; // @@ [Uninitialized 'j' leads to undefined behavior; should initialize j=0]
        
    }
    puts(str2); // @@ [str2 may not be null-terminated, leading to undefined behavior in puts()]
    
    
    
    return 0;
    
}