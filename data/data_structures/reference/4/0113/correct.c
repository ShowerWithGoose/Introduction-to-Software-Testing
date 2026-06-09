#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct wordlist{
    char word[30];
    int num;
};
int notinlist(char word[],struct wordlist wordlist[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(word,wordlist[i].word)==0)
        {
            return 0;
        }
    }
    return 1;
}
int findword(char word[],struct wordlist wordlist[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(word,wordlist[i].word)==0)
        {
            return i;
        }
    }
}
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    struct wordlist wordlist[1005]={};
    int n=0;
    while(!feof(in))
    {
        int sign=1,i=0;
        char c,word[30]={};
        while(1)
        {
            c=fgetc(in);
            if(isalpha(c))
            {
                if(isupper(c))
                {
                c=tolower(c);
                }
                word[i++]=c;
            }
            else{
                break;
            }
        }
        if(i==0) sign=0;
        if(sign)
        { 
            if(notinlist(word,wordlist,n))
        {
            strcpy(wordlist[n].word,word);
            wordlist[n].num=1;
            n++;
        }
        else
        {
            int k;
            k=findword(word,wordlist,n);
            wordlist[k].num++;
        }
        } 
    }
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            struct wordlist temp;
            if(strcmp(wordlist[j].word,wordlist[j+1].word)>0)
            {
                temp=wordlist[j];
                wordlist[j]=wordlist[j+1];
                wordlist[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",wordlist[i].word,wordlist[i].num);
    }
    fclose(in);
}


