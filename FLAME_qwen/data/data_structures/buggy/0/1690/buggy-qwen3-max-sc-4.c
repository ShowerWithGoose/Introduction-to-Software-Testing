#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Also, in many modern compilers/environments, 'gets' is removed entirely, leading to a compilation error.]
    int i,j,k=0; // @@ [Variable 'j' is used uninitialized later when writing to str2[j++], which leads to undefined behavior.]
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
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue: loop condition excludes the last character and reuses 'k', corrupting output index.]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ [Same issue: incorrect loop bound and variable reuse.]
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
        }
        else
        str2[j++]=str1[i]; // @@ ['j' is uninitialized; this leads to writing at an arbitrary memory location.]
        
    }
    puts(str2); // @@ [str2 is not null-terminated, so 'puts' may print garbage beyond intended output.]
    
    
    
    return 0;
    
}