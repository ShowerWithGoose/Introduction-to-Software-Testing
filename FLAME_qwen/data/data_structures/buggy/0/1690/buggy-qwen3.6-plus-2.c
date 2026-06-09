#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1);
    int i,j,k=0; // @@ Variable j is uninitialized, leading to undefined behavior when used as an array index
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9') // @@ Out-of-bounds access when i=0; missing condition str1[i-1] < str1[i+1]
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ Loop condition should be <= to include the end character in the expansion
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z') // @@ Missing condition str1[i-1] < str1[i+1]; fails to output '-' when expansion is invalid
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ Loop condition should be <= to include the end character in the expansion
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z') // @@ Missing condition str1[i-1] < str1[i+1]; fails to output '-' when expansion is invalid
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++) // @@ Loop condition should be <= to include the end character in the expansion
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
        }
        else
        str2[j++]=str1[i];
        
    }
    puts(str2); // @@ str2 is not null-terminated, causing undefined behavior or garbage output
    
    
    
    return 0;
    
}