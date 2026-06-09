#include <stdio.h>
#include <string.h>

char s[9999][9999];
int l[9999]={0};
char d[9999];
char s1[9999][9999];
int l1[9999]={0};


int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char a1;
    int i=0,j=0;
    while((a1=fgetc(in))!=EOF)
    {
        if(('A'<a1)&&(a1<'Z')) // @@ [Condition excludes 'A' and 'Z'; should be <= to include all uppercase letters]
        {
            a1=a1-'A'+'a';
        }
        if(('a'<=a1)&&(a1<='z'))
        {
            s[i][j]=a1;
            j=j+1;
        }
        else if((a1<'a')||(a1>'z'))
        {
            i=i+1;
            j=0;
        }
    }
    int u=0,k=0;
    for(j=0;j<i;j++)
    {
        for(u=j+1;u<i;u++)
        {
            if(strcmp(s[j],s[u])==0)
            {
                s[u][0]=0;
                l[j]=l[j]+1;
            }
        }
    }
    for(j=0;j<i;j++)
    {
        for(u=j+1;u<i;u++)
        {
            if((strcmp(s[j],s[u]))>0)
            {
                strcpy(d,s[j]);
                strcpy(s[j],s[u]);
                strcpy(s[u],d);
                k=l[j];
                l[j]=l[u];
                l[u]=k;
            }
        }
    }
    k=0;
    for(j=0;j<i;j++)
    {
        if(s[j][0]!=0)
        {
            strcpy(s1[k],s[j]);
            l1[k]=l[j];
            k=k+1;
        }
    }
    for(j=0;j<k;j++)
    {
        printf("%s %d\n",s1[j],l1[j]+1);
    }
    printf("\n");
    printf("%s",s1[4]); // @@ [Accesses s1[4] without checking if k > 4, leading to undefined behavior; also violates output format by printing extra newline and extra word]
    
    
    return 0;
}