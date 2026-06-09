#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1);
    int i,j=0,k=0; // @@ [Variable 'j' is used as an index for str2 but was never initialized, leading to undefined behavior and potential runtime errors. It should be initialized to 0.]
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    if (str1[i+1] > str1[i-1]) { // @@ [The problem requires expansion only if the character after '-' is greater than the one before. This check is missing, which could lead to incorrect logic or infinite loops if characters are equal or reversed, though primarily it's a logical error required by the spec.]
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                }
                else { // @@ [If the condition for expansion is not met (e.g., types don't match or order is wrong), the '-' character itself should be output. Currently, it is skipped entirely.]
                    str2[j++] = '-';
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    if (str1[i+1] > str1[i-1]) { // @@ [Missing check that the second character is greater than the first.]
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                }
                else { // @@ [If expansion conditions are not met, the '-' should be preserved.]
                    str2[j++] = '-';
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    if (str1[i+1] > str1[i-1]) { // @@ [Missing check that the second character is greater than the first.]
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    }
                }
                else { // @@ [If expansion conditions are not met, the '-' should be preserved.]
                    str2[j++] = '-';
                }
            }
            else { // @@ [Handles cases where the character before '-' is not alphanumeric. The '-' should be preserved.]
                 str2[j++] = '-';
            }
        }
        else
        str2[j++]=str1[i];
        
    }
    str2[j] = '\0'; // @@ [The string str2 must be null-terminated before printing with puts or printf. Without this, it may print garbage values or cause a runtime error.]
    puts(str2);
    
    
    
    return 0;
    
}