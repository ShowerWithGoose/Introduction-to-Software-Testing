#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, 'gets' was removed in C11 standard, leading to compilation error on modern compilers]
    int i,j,k=0; // @@ [Variable 'j' is used uninitialized, leading to undefined behavior when accessing str2[j++]]
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Loop condition should be k <= (str1[i+1] - str1[i-1]) to include the end character; current logic skips the last character]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue: loop condition excludes the end character]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue: loop condition excludes the end character]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
        }
        else
        str2[j++]=str1[i]; // @@ [If previous branch didn't run, 'j' is still uninitialized, causing undefined behavior]
        
    }
    puts(str2); // @@ [str2 is not null-terminated, leading to undefined behavior when printed with puts]
    
    
    
    return 0;
    
}