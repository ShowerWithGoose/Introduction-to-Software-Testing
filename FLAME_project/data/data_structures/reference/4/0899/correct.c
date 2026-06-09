#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
   char word[100];
   int num;
};
struct node line[1000],temp;
char s[2000];
int flag;
int main(int argc, char const *argv[])
{
    int i=0,j=0,k=0,n;
    FILE *in;
    in =fopen("article.txt","r");
    if((in =fopen("article.txt","r")) == NULL){ 
        printf("Can't open file article.txt!\n");
        return -1;
    }
    while(fgets(s,1025,in)!=NULL)
    {   
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                line[j].word[k++]=s[i]-'A'+'a';
                flag++;
            }
            else if(s[i]>='a'&&s[i]<='z')
            {
                line[j].word[k++]=s[i];
                flag++;
            }
            else if(flag!=0)
            {
                line[j].word[k]='\0';
                line[j++].num=1;
                k=flag=0;
            }
        }
    }
    n=j;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (strcmp(line[i].word,line[j].word) == 0)
            {
                strcpy(line[j].word, "\0");
                line[i].num+=line[j].num;
            }
            if (strcmp(line[i].word,line[j].word) > 0)
            {
                temp = line[i];
                line[i] =line[j];
                line[j] =temp;
            }
        }
    }
    i=0;
    while(i<n)
    {
       if(strlen(line[i].word)!=0)
        printf("%s %d\n",line[i].word,line[i].num);
        i++;
    }

    return 0;
}



