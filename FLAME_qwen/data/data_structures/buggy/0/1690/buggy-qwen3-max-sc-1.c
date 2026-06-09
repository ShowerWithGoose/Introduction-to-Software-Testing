#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in some environments this leads to compilation errors or warnings that prevent execution]
    int i,j,k=0;
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k; // @@ [Variable 'j' is used uninitialized; it should be initialized before use (e.g., j=0). Also, loop condition uses '<' instead of '<=', causing incomplete expansion (e.g., a-d expands to abc instead of abcd)]
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k; // @@ [Same issues: 'j' uninitialized and loop condition excludes the last character]
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k; // @@ [Same issues: 'j' uninitialized and loop condition excludes the last character]
                    }
                }
            }
        }
        else
        str2[j++]=str1[i]; // @@ [Variable 'j' is used uninitialized here as well; if the first character is not '-', this will write to an undefined location]
        
    }
    puts(str2); // @@ [str2 is not null-terminated, which may cause undefined behavior when printing with puts]
    
    
    
    return 0;
    
}