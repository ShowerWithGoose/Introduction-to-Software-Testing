#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ Error: gets() returns NULL (a pointer), not 'NULL' (a character constant). Should be while(gets(a)!=NULL)
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ Error: a[1+i] should be a[i+1] for consistency and correctness
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ Error: a[1+i] should be a[i+1] for consistency and correctness
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