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
            if(((ch[i+1]<='z'&&ch[i+1]>='a')&&(ch[i-1]<='z'&&ch[i-1]>='a'))||((ch[i+1]<='Z'&&ch[i+1]>='A')&&(ch[i-1]<='Z'&&ch[i-1]>='A'))||((ch[i+1]<='9'&&ch[i+1]>='0')&&(ch[i-1]<='9'&&ch[i-1]>='0'))) @@ Missing check for `ch[i+1] > ch[i-1]` and potential out-of-bounds access when `i=0`.
            {
                m=i+2;
                for(k=0;ch[m]!='\0';k++,m++)
                {
                    mid[k]=ch[m]; @@ `mid` is not null-terminated after copying, causing `strcat` to read garbage.
                }
                for(j=0;j<=(ch[i+1]-ch[i-1]);j++) @@ Does not verify `ch[i+1] > ch[i-1]`; if false, `ch1` retains old data and is not null-terminated.
                {
                    ch1[j]=ch[i-1]+j; @@ `ch1` is not null-terminated after the loop, leading to undefined behavior in `strcat`.
                }
                ch[i-1]='\0'; @@ Modifying the string during iteration invalidates the loop index `i` and corrupts subsequent processing.
                strcat(ch,ch1); @@ `ch1` lacks null terminator, causing `strcat` to append unintended characters.
                strcat(ch,mid); @@ `mid` lacks null terminator, causing `strcat` to append unintended characters.
                for(h=0;mid[h]!='\0';h++) @@ `mid` is not null-terminated, so loop condition may never be met, causing infinite loop or crash.
                {
                    mid[h]=0;
                }
            }
            
        }
    }
    
    printf("%s",ch);

    return 0;
    
}