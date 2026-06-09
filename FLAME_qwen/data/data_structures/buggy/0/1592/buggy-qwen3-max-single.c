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
                strcat(ch,ch1); // @@ [modifying the input string `ch` while iterating over it leads to undefined behavior and potential buffer overflow; also, the loop index `i` becomes invalid after modifying `ch`]
                strcat(ch,mid); // @@ [same issue: `ch` is being modified during iteration, which breaks loop logic and may cause buffer overflow since `ch` is of fixed size LEN=5000 and concatenated strings may exceed this]
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