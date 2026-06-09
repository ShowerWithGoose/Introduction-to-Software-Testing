#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The condition 'gets(a) != "NULL"' is incorrect. gets() returns a pointer to the string or NULL on EOF/error, not the string "NULL". This causes an infinite loop because the return value is never equal to the string literal "NULL", leading to Time Limit Exceeded. It should be 'while(gets(a) != NULL)'.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1])
            {
                if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')
                {
                    for(j=1;j<a[i+1]-a[i-1];j++)
                    {
                        printf("%c",a[i-1]+j);
                    }
                }
                else if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')
                {
                    for(k=1;k<a[i+1]-a[i-1];k++)
                    {
                        printf("%c",a[i-1]+k);
                    }
                }
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [This line has a typo: 'a[1+i]' should be 'a[i+1]' for consistency and correctness, though it's functionally equivalent. However, the bigger issue is that when expansion conditions are not met (e.g., mixed case like 'uB'), the '-' is printed but the following character is still processed again in the next iteration, causing duplication or incorrect output. But the primary cause of TLE is the while loop condition.]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same typo as above: 'a[1+i]' instead of 'a[i+1]'. While not causing TLE, it's inconsistent and error-prone.]
                    {
                        printf("%c",a[i-1]+l);
                    }
                }
                else printf("%c",a[i]);
            }
            else printf("%c",a[i]);
        }
    }
    
    return 0;
}