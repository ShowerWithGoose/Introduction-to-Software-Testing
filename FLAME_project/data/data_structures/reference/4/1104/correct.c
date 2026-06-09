#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[105][20];
void rng(char s[][20],int n)
{
    char c[20];
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (strcmp(s[i], s[j])>0)
            {
                strcpy(c,s[j]);
                strcpy(s[j],s[i]);
                strcpy(s[i],c);
            }
        }
    }
}
int main()
{
    FILE *fo;
    fo=fopen("article.txt","r");
    char ch;
    int i=0,j=0,n=0,t=0,b[105]={0};
    ch=fgetc(fo); 
    while (ch!=EOF)
    {
        if(isalpha(ch))
        {
            s[i][j]=ch;
            j++;
        }
        else if(ispunct(ch)||isspace(ch)) 
        {
            s[i][j]='\0';
            j=0;
            i++;
        }
        ch=fgetc(fo);
    }
    n=i;
    for(i=0;i<n;i++)
    {
        for(j=0;j<strlen(s[i]);j++)
        {
            s[i][j]=tolower(s[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        rng(s,n);
    }
    for (i=0;i<n;i++) 
    {
        t=0;
        b[i]=1;
        for(j=i+1;j<n;j++)
        {
            if(!strcmp(s[i], s[j]))
            {
                b[i]++;
                s[j][0] = '\0';
                t=1;
            }
            if(s[j][0]=='\0')
            {
                continue;
            }
            else
            {
                if(t==1)
                {
                    i=j-1;
                }
                break;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        if(s[i][0]!='\0')
        {
            printf("%s %d\n",s[i],b[i]);
        }
    }
    fclose(fo);
    return 0;
}
