#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1);
    int i,j=0,k=0; // @@ [Variable 'j' is used as an index for str2 but was never initialized, leading to undefined behavior and potential runtime errors.]
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    if (str1[i+1] > str1[i-1]) { // @@ [The problem requires expansion only if the character after '-' is greater than the one before. This check is missing, causing incorrect expansion or infinite loops if equal/reverse, though primarily logic error here it contributes to correctness.]
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    } else { // @@ [If expansion conditions are not met (e.g., reverse order or same char), the '-' should be output as is, along with the surrounding characters which are already handled or need specific handling. The current logic skips outputting '-' entirely when types match but order is wrong, or falls through incorrectly.]
                         str2[j++] = '-';
                    }
                }
                else {
                     str2[j++] = '-'; // @@ [If types don't match (e.g. digit and letter), output '-' unchanged.]
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    if (str1[i+1] > str1[i-1]) { // @@ [Missing check for strict greater than requirement for expansion.]
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    } else {
                         str2[j++] = '-';
                    }
                }
                else {
                     str2[j++] = '-';
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    if (str1[i+1] > str1[i-1]) { // @@ [Missing check for strict greater than requirement for expansion.]
                        for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                        {
                            str2[j++]=str1[i-1]+k;
                        }
                    } else {
                         str2[j++] = '-';
                    }
                }
                else {
                     str2[j++] = '-';
                }
            }
            else {
                 str2[j++] = '-'; // @@ [Handle cases where the character before '-' is not alphanumeric, output '-' unchanged.]
            }
        }
        else
        str2[j++]=str1[i];
        
    }
    str2[j] = '\0'; // @@ [The string str2 is not null-terminated before printing, which causes runtime error or garbage output when using puts/printf.]
    puts(str2);
    
    
    
    return 0;
    
}