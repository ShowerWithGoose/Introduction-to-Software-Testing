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
                for(j=0;j<=(ch[i+1]-ch[i-1]);j++)
                {
                    ch1[j]=ch[i-1]+j;
                }
                ch[i-1]='\0';
                strcat(ch,ch1); // @@ [This modifies the original string `ch` while iterating over it, causing the loop index `i` to become invalid or skip characters. Additionally, it does not check that ch[i+1] > ch[i-1], so expansions like 'u-a' would incorrectly expand.]
                strcat(ch,mid); // @@ [Appending `mid` (the part after the range) reinserts already processed or unprocessed parts of the string, leading to duplication as seen in the buggy output.]
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