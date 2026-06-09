#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char st[10000],cpy[10000];
    int i,j=0,k;
    gets(st);
    for(i=0; st[i]!='\0'; i++)
    {
        if(st[i]=='-')
        {
            if((((st[i-1]>='a'&&st[i-1]<='z')&&(st[i+1]>='a'&&st[i+1]<='z'))||((st[i-1]>='A'&&st[i-1]<='Z')&&(st[i+1]>='A'&&st[i+1]<='Z'))||((st[i-1]>='0'&&st[i-1]<='9')&&(st[i+1]>='0'&&st[i+1]<='9')))&&st[i-1]<st[i+1])
            {
                for(k=1;; k++)
                {
                    cpy[j]=st[i-1]+k;
                    j++;
                    if(cpy[j-1]==st[i+1])
                    {
                        i++;
                        break;
                    }
                }
            }
            else
            {
                cpy[j]=st[i];
                j++;
            }

        }
        else
        {
            cpy[j]=st[i];
            j++;
        }


    }
    cpy[j]='\0';
    puts(cpy);
    return 0;
}



