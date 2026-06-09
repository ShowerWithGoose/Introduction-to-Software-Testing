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
                if (ch[i-1] < ch[i+1]) { // @@ [Missing check: expansion should only happen if the character after '-' is greater than the one before it. Without this, ranges like 'u-B' or invalid logical expansions might be processed incorrectly or cause issues in subsequent logic if not strictly filtered by type alone.]
                m=i+2;
                for(k=0;ch[m]!='\0';k++,m++)
                {
                    mid[k]=ch[m];
                }
                for(j=0;j<=(ch[i+1]-ch[i-1]);j++)
                {
                    ch1[j]=ch[i-1]+j;
                }
                ch[i-1]='\0';
                strcat(ch,ch1);
                strcat(ch,mid);
                for(h=0;mid[h]!='\0';h++)
                {
                    mid[h]=0;
                }
                i = strlen(ch) - strlen(mid) - 1; // @@ [Logic Error: After modifying the string `ch` by expanding and concatenating, the index `i` continues from its old position. This causes the loop to re-process parts of the newly inserted string or skip characters, leading to incorrect output like the repeated "fghijklmnopqrstu" in the buggy output. The index needs to be adjusted to point to the end of the newly inserted segment so the next iteration continues correctly.]
                } else {
                     // Do nothing, treat '-' as normal character if start >= end
                }
            }
            
        }
    }
    
    printf("%s",ch);

    return 0;
    
}