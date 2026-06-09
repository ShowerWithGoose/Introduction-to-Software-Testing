#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *in,*out;
char line[101];
struct Word
{
    char word[101];
    int len;
}words[1000001];
int sum;
int compare(const void *p1,const void *p2){
    struct Word* e1=(struct Word*)p1;
    struct Word* e2=(struct Word*)p2;
    return strcmp(e1->word,e2->word);
}
void change(char *line){
	int len=strlen(line);
	int i=0;
	while(len--){
		if(line[i]>='A'&&line[i]<='Z'){
			line[i]+=24;
			i++;
		}
	}
}
int main()
{
    in=fopen("article.txt","r");
    int t=0;
    while(fgets(line,81,in)!=NULL)
    {
        int len=strlen(line);
        for(int i=0;i<len;i++)
        {
            if(line[i]>='A'&&line[i]<='Z')
            line[i]=line[i]+'a'-'A';
        }
        for(int i=0;i<len;i++)
        {
            if((line[i]>='a'&&line[i]<='z')&&(line[i-1]<'a'||line[i-1]>'z'))
            {
                t=1;
                words[sum].word[words[sum].len++]=line[i];
                if((line[i+1]<'a'||line[i+1]>'z')&&line[i+1]!='\0')
                {
                    words[sum].word[words[sum].len]='\0';
                    t=0;
                    sum++;
                }
            }
            else if(t==1)
            {
                if(line[i]>='a'&&line[i]<='z')
                {
                    words[sum].word[words[sum].len++]=line[i];
                }
                if((line[i+1]<'a'||line[i+1]>'z')&&line[i+1]!='\0')
                {
                    words[sum].word[words[sum].len]='\0';
                    t=0;
                    sum++;
                }
            }
        }
    }
    qsort(words,sum,sizeof(words[0]),compare);
    int ans=1;
    for(int i=0;i<sum;i++)
    {
        if(strcmp(words[i+1].word,words[i].word)!=0)
        {
            printf("%s %d\n",words[i].word,ans);
            ans=1;
        }
        else
        {
            ans++;
        }
    }
    return 0;
}

