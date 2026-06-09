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
                strcat(ch,ch1);
                strcat(ch,mid);
                for(h=0;mid[h]!='\0';h++)
                {
                    mid[h]=0;
                }
                i = strlen(ch) - strlen(mid) - 1; // @@ [After modifying the string `ch` in place, the loop index `i` is not updated to reflect the new length and content of `ch`. This causes the loop to either skip parts of the newly appended expansion or reprocess already-expanded sections, leading to duplicate or incorrect output.]
            }
            
        }
    }
    
    printf("%s",ch);

    return 0;
    
}