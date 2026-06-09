#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, 'gets' was removed in C11 standard, leading to compilation error on modern compilers]
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
                        str2[j++]=str1[i-1]+k; // @@ [Variable 'j' is used uninitialized; this leads to undefined behavior and potential runtime crash or garbage output]
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k; // @@ [Variable 'j' is used uninitialized; this leads to undefined behavior and potential runtime crash or garbage output]
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k; // @@ [Variable 'j' is used uninitialized; this leads to undefined behavior and potential runtime crash or garbage output]
                    }
                }
            }
        }
        else
        str2[j++]=str1[i]; // @@ [Variable 'j' is used uninitialized; this leads to undefined behavior and potential runtime crash or garbage output]
        
    }
    puts(str2); // @@ [str2 may not be null-terminated because 'j' is uninitialized and no '\0' is explicitly added at the end, leading to undefined behavior when printing]
    
    
    
    return 0;
    
}