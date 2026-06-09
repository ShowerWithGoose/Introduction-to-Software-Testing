#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char c;

struct s
{
    char word[20];
    int num;
}temp,s[10000];

int main()
{
    int n=0;
    FILE *fp;
    fp=fopen("article.txt","r");


    c=fgetc(fp);
    while(c!=EOF){
            while(isalpha(c)){
            for(int i=0;isalpha(c);i++){
            if(c<='Z'&&c>='A')
                c=c+32;
            s[n].word[i]=c;
            s[n].num=1;
            c=fgetc(fp);
        }
        n++;}
        c=fgetc(fp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(strcmp(s[i].word,s[j].word) > 0){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(strcmp(s[i].word, s[j].word)==0){
                s[j].word[0]='\0';
                s[i].num=s[i].num+1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i].word[0]!='\0')
        {
            printf("%s %d\n",s[i].word,s[i].num);
        }
    }

    fclose(fp);
}


