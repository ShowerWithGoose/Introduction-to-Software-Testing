#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1);
    int i,j,k=0; // @@ Variable j is uninitialized, causing undefined behavior when used as an array index for str2.
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-')
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9') // @@ Missing condition to check if str1[i+1] > str1[i-1] before expanding; also fails to output '-' when expansion conditions are not met.
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z') // @@ Missing condition to check if str1[i+1] > str1[i-1] before expanding.
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z') // @@ Missing condition to check if str1[i+1] > str1[i-1] before expanding.
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
        }
        else
        str2[j++]=str1[i];

    }
    puts(str2); // @@ str2 is not null-terminated with '\0', causing puts to read out of bounds and trigger a Runtime Error. Additionally, the '-' character is not appended to str2 when expansion conditions are not met.



    return 0;

}