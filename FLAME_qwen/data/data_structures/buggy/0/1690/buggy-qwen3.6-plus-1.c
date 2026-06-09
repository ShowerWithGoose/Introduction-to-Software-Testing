#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1);
    int i,j,k=0; // @@ Variable j is uninitialized, causing undefined behavior when used as an index for str2.
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-') // @@ Missing check for i!=0, which leads to out-of-bounds access of str1[i-1] when i=0.
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ Loop condition uses < instead of <=, missing the end character, and lacks a check for str1[i-1] < str1[i+1].
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ Same error: should use <= and check str1[i-1] < str1[i+1].
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ Same error: should use <= and check str1[i-1] < str1[i+1].
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
        } // @@ Missing an else clause inside this block to output str1[i] ('-') when expansion conditions are not met.
        else
        str2[j++]=str1[i];
        
    }
    puts(str2); // @@ str2 is not null-terminated, which may cause puts to print garbage or crash.
    
    
    
    return 0;
    
}