#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tolower(c) 	(c>='A'&&c<='Z'?'a'-'A'+ c : c)
struct words
{
    char content[15];
    int n;
};
struct words word[1024];
char all_words[100][20];
void choose_rise(int );
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char txt[1024],txt1[1024],c;
    int i=0,m=0,m1=0,j=0,bef=0,word_num=0,word_length=0,ans_word_num=1,ans_num=0;
    while((c=fgetc(in))!=EOF)
    {
        if(c>=65&&c<=90||c>=97&&c<=122){
            txt1[i++]=tolower(c);
        }
        else
            txt1[i++]=' ';
    }
    m1=i; i=0;
    while(txt1[i]==' ')
        i++;
    for(i;i<m1;i++)
    {
        if(txt1[i]==' '&&txt1[i+1]==' ');
        else txt[m++]=txt1[i];
    }//store txt
    for(i=0;i<m;i++)
    {
        if(txt[i]==' '||txt[i]=='\n')
        {
            word_length=0;
            for(j=bef;j<i;j++)
            {
                all_words[word_num][word_length]=txt[j];
                word_length++;
            }
            all_words[word_num][word_length]='\0';
            bef=i+1;
            word_num++;
        }
    }
    for(i=bef,word_length=0;i<m;i++)
        all_words[word_num][word_length++]=txt[i];
    all_words[word_num][word_length]='\0';//get words
    choose_rise(word_num);//sort
    for(i=0;i<word_num;i++)
    {
        if(!strcmp(all_words[i],all_words[i+1]))
            ans_word_num++;
        else
        {
            strcpy(word[ans_num].content,all_words[i]);
            word[ans_num].n=ans_word_num;
            ans_num++;
            ans_word_num=1;
        }
    }//get ans
    for(i=0;i<ans_num;i++)
        printf("%s %d\n",word[i].content,word[i].n);
    fclose(in);
    return 0;
}
void choose_rise(int word_num)
{
    int i=0,j=0,min=0;
    char buf[20];
    for(i=0;i<word_num;i++)
    {
        min=i;
        for(j=i+1;j<word_num;j++)
            if(strcmp(all_words[min],all_words[j])>0)
                min=j;
        if(min!=i)
        {
            strcpy(buf,all_words[min]);
            strcpy(all_words[min],all_words[i]);
            strcpy(all_words[i],buf);
        }
    }
}
