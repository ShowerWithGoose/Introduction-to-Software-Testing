#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *in;
struct Word
{
    char word[200];
    int sum;
};

int getWord(char danci[])
{
    int I=0;
    char ch;
    while((ch=fgetc(in))!=EOF)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            danci[I]=ch;
            if(ch>='A'&&ch<='Z')
                danci[I]=danci[I]-'A'+'a';
            I++;
        }
        else if(I>0)   
            break;
    }
    danci[I]='\0';
    return ch;
}

int main()
{
    char temp[200],danci[200];
    int i=0,n=1,j,k,len;
    struct Word words[200];
    
    in=fopen("article.txt","r");

    while(getWord(temp)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            if(strcmp(temp,words[i].word)==0)
            {
                words[i].sum++;
                break;
            }
            else if(i==n-1)
            {
                strcpy(words[n].word,temp);
                n++;
            }
        }                                       //统计单词个数
    }
    
    char cmp[200];
    int num;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(words[i].word,words[j].word)>0)
            {
                strcpy(cmp,words[i].word);
                strcpy(words[i].word,words[j].word);
                strcpy(words[j].word,cmp);
                num=words[i].sum;
                words[i].sum=words[j].sum;
                words[j].sum=num;
            }
        }
    }

    for(i=1;i<n;i++)
    {
        printf("%s %d\n",words[i].word,words[i].sum);
    }
    fclose(in);
    return 0;
}
