#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[1000];
    gets(str1);
    int i,j,k=0; // @@ j is uninitialized; should be initialized to 0
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]=='-') // @@ missing check i>0 to avoid out‑of‑bounds access to str1[i-1] when i==0
        {
            if(str1[i-1]>='0'&&str1[i-1]<='9')
            {
                if(str1[i+1]>='0'&&str1[i+1]<='9')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='a'&&str1[i-1]<='z')
            {
                if(str1[i+1]>='a'&&str1[i+1]<='z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            }
            else if(str1[i-1]>='A'&&str1[i-1]<='Z')
            {
                if(str1[i+1]>='A'&&str1[i+1]<='Z')
                {
                    for(k=1;k<(str1[i+1]-str1[i-1]);k++)
                    {
                        str2[j++]=str1[i-1]+k;
                    }
                }
            } // @@ missing else branch to output the dash when none of the expansion conditions hold; the dash is lost
        }
        else
        str2[j++]=str1[i];
        
    }
    puts(str2);
    
    return 0;
    
}