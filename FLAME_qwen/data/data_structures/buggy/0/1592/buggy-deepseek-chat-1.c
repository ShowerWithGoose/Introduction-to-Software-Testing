#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 5000
int main()
{
    char ch[LEN];
    char ch1[30]={0};
    char mid[5000]={0};
    int i=0,j,k,m,n,h;
    scanf("%s",ch);
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='-')
        {
            if(((ch[i+1]<='z'&&ch[i+1]>='a')&&(ch[i-1]<='z'&&ch[i-1]>='a'))||((ch[i+1]<='Z'&&ch[i+1]>='A')&&(ch[i-1]<='Z'&&ch[i-1]>='A'))||((ch[i+1]<='9'&&ch[i+1]>='0')&&(ch[i-1]<='9'&&ch[i-1]>='0')))
            {
                m=i+2;
                for(k=0;ch[m]!='\0';k++,m++)
                {
                    mid[k]=ch[m];
                }
                for(j=0;j<=(ch[i+1]-ch[i-1]);j++) // @@ [Error: The loop condition should be j < (ch[i+1] - ch[i-1]) to avoid including the ending character twice, and the expansion should not include the ending character if it's already in the string. Also, the logic for handling the expansion and concatenation is flawed because it modifies ch while iterating over it, causing index issues.]
                {
                    ch1[j]=ch[i-1]+j;
                }
                ch[i-1]='\0'; // @@ [Error: Setting ch[i-1] to '\0' truncates the string, losing all characters before the expansion start. This corrupts the original string and leads to incorrect output.]
                strcat(ch,ch1); // @@ [Error: strcat appends to the end of ch, but ch has been truncated and the expansion characters are placed at the wrong position. The expansion should replace the '-' and surrounding characters in-place, not append.]
                strcat(ch,mid); // @@ [Error: Appending the remaining part of the string after the expansion, but due to truncation and previous strcat, the order is wrong. The correct approach is to build the output in a separate buffer.]
                for(h=0;mid[h]!='\0';h++)
                {
                    mid[h]=0;
                }
            }
            
        }
    }
    
    printf("%s",ch);

    return 0;
    
}