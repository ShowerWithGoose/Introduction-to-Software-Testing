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
    scanf("%s",ch); // @@ scanf stops at whitespace, potentially truncating input; fgets is safer.
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='-')
        {
            if(((ch[i+1]<='z'&&ch[i+1]>='a')&&(ch[i-1]<='z'&&ch[i-1]>='a'))||((ch[i+1]<='Z'&&ch[i+1]>='A')&&(ch[i-1]<='Z'&&ch[i-1]>='A'))||((ch[i+1]<='9'&&ch[i+1]>='0')&&(ch[i-1]<='9'&&ch[i-1]>='0'))) // @@ Missing check for ch[i+1] > ch[i-1] as required; also ch[i-1] access is out-of-bounds when i=0.
            {
                m=i+2;
                for(k=0;ch[m]!='\0';k++,m++)
                {
                    mid[k]=ch[m];
                } // @@ mid array is not null-terminated after copying, causing strcat to read out of bounds.
                for(j=0;j<=(ch[i+1]-ch[i-1]);j++)
                {
                    ch1[j]=ch[i-1]+j;
                } // @@ ch1 array is not null-terminated after filling, causing strcat to read out of bounds.
                ch[i-1]='\0'; // @@ Modifying the string while iterating corrupts loop traversal and causes undefined behavior.
                strcat(ch,ch1); // @@ strcat expects null-terminated strings, but ch1 lacks one.
                strcat(ch,mid); // @@ strcat expects null-terminated strings, but mid lacks one.
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