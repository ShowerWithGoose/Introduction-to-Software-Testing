#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1); // @@ [Using gets() is unsafe and may cause buffer overflow; also, j is uninitialized which leads to undefined behavior]
    int i,j,k=0;
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    if(str1[i+1] > str1[i-1]) // @@ [Missing check that the character after '-' is greater than the one before it]
                    {
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                    else
                    {
                        str2[j++]='-'; // @@ [If not expandable, '-' should be copied to output]
                    }
                }
                else
                {
                    str2[j++]='-'; // @@ [If types don't match, '-' should be copied to output]
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    if(str1[i+1] > str1[i-1]) // @@ [Missing check that the character after '-' is greater than the one before it]
                    {
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                    else
                    {
                        str2[j++]='-'; // @@ [If not expandable, '-' should be copied to output]
                    }
                }
                else
                {
                    str2[j++]='-'; // @@ [If types don't match, '-' should be copied to output]
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    if(str1[i+1] > str1[i-1]) // @@ [Missing check that the character after '-' is greater than the one before it]
                    {
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                    else
                    {
                        str2[j++]='-'; // @@ [If not expandable, '-' should be copied to output]
                    }
                }
                else
                {
                    str2[j++]='-'; // @@ [If types don't match, '-' should be copied to output]
                }
            }
            else
            {
                str2[j++]='-'; // @@ [If the character before '-' is not in valid range, '-' should still be copied]
            }
        }
        else
        str2[j++]=str1[i];
        
    }
    str2[j]='\0'; // @@ [Missing null termination of output string]
    puts(str2);
    
    
    
    return 0;
    
}