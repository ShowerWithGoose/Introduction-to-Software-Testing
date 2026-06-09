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
    char a1; // @@ a1 should be declared as int to correctly handle EOF; char may cause infinite loop or misdetection.
    int i=0,j=0;
    while((a1=fgetc(in))!=EOF) // @@ a1 is char; fgetc returns int, must store in int to distinguish EOF from valid char.
    {
        if(('A'<a1)&&(a1<'Z')) // @@ Condition incorrectly excludes 'A' and 'Z'; should be (a1>='A' && a1<='Z')
        {
            a1=a1-'A'+'a';
        }
        if(('a'<=a1)&&(a1<='z'))
        {
            s[i][j]=a1;
            j=j+1;
        }
        else if((a1<'a')||(a1>'z')) // @@ Missing null-termination of s[i]; should add s[i][j]='\0'; before i=i+1 to make string valid.
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
            if(strcmp(s[j],s[u])==0) // @@ s[j] and s[u] may not be null-terminated, leading to undefined behavior.
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
            if((strcmp(s[j],s[u]))>0) // @@ Same as above: undetermined due to missing null terminators.
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
            strcpy(s1[k],s[j]); // @@ strcpy relies on null-terminated source; s[j] may not be null-terminated.
            l1[k]=l[j];
            k=k+1;
        }
    }
    for(j=0;j<k;j++)
    {
        printf("%s %d\n",s1[j],l1[j]+1);
    }
    printf("\n");
    printf("%s",s1[4]); // @@ Accessing s1[4] without ensuring k>4; may read out-of-bounds if k<=4.
    
    
    return 0;
}