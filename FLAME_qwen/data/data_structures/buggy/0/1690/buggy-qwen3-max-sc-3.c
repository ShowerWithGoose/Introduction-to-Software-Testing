#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, 'gets' was removed in C11 standard, leading to compilation error on modern compilers]
    int i,j,k=0; // @@ [Variable 'j' is used uninitialized later in the code, leading to undefined behavior; however, the immediate compilation error is due to 'gets']
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
                        str2[j++]=str1[i-1]+k; // @@ [Using uninitialized variable 'j' leads to undefined behavior, but not a compilation error]
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k; // @@ [Same issue with uninitialized 'j']
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k; // @@ [Same issue with uninitialized 'j']
                    }
                }
            }
        }
        else
        str2[j++]=str1[i]; // @@ [Uninitialized 'j' used here as well]
        
    }
    puts(str2); // @@ ['str2' may not be null-terminated, leading to undefined behavior at runtime, but not a compilation error]
    
    
    
    return 0;
    
}