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
        if(('A'<a1)&&(a1<'Z')) // @@ [Error: The condition should be (a1>='A' && a1<='Z') to include 'A' and 'Z'. Current condition excludes 'A' and 'Z', so uppercase A and Z are not converted to lowercase.]
        {
            a1=a1-'A'+'a';
        }
        if(('a'<=a1)&&(a1<='z')) // @@ [Error: The condition should be (a1>='a' && a1<='z') to include 'z'. Current condition excludes 'z', so lowercase z is not counted as part of a word.]
        {
            s[i][j]=a1;
            j=j+1;
        }
        else if((a1<'a')||(a1>'z')) // @@ [Error: This condition is always true when the previous if fails, but it incorrectly treats characters like newline or space as word separators. However, the main issue is that it increments i even when no word was started (e.g., consecutive separators), leading to empty strings in the array.]
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
        printf("%s %d\n",s1[j],l1[j]+1); // @@ [Error: The count should be l1[j] (the number of occurrences), not l1[j]+1. Adding 1 overcounts each word by one.]
    }
    printf("\n");
    printf("%s",s1[4]); // @@ [Error: This line prints an extra word (the 5th word) and a newline, which is not part of the required output format. It should be removed.]
    
    
    return 0;
}