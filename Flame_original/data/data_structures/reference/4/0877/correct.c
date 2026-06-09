#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <ctype.h>

#define MAXWORD  32
#define MAXSIZE  1024

struct countword{
    char word[32];
    int num;
}words[1024];

int cmp ( const void *a , const void *b )
{
return strcmp( ( (struct countword*)a)->word , ( (struct countword*)b)->word );
}
 
int main()
{
    //file in
    FILE *in;
    in=fopen("article.txt","r");
    int num_of_words=0;
    char temp;
    char wordin[32];
    int j=0;
    int flag_cmp=0;
    char fin[1024];
    char temp_fin[1024];
    while(fgets(temp_fin,1024,in)!=NULL)
    {
        strcat(fin,temp_fin);
    }
    int len=strlen(fin);
    memset(wordin,'\0',31);
    
    for(int i=0;i<len;i++)
    {
        temp=fin[i];
        int flag=0;
        if((temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z'))
        {
            wordin[j]=temp;
            j++;
            flag_cmp=1;
            continue;
        }
        else
        {
            if(flag_cmp==1)
            {
                int len_wordin=strlen(wordin);
                for(int i=0;i<len_wordin;i++)
                {
                    wordin[i]=tolower(wordin[i]);
                }
                for(int i=0;i<num_of_words;i++)
                {
                    if(strcmp(words[i].word,wordin)==0)
                    {
                        words[i].num++;
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    strcpy(words[num_of_words].word,wordin);
                    words[num_of_words].num=1;
                    num_of_words++;
                }
                memset(wordin,'\0',strlen(wordin));
                j=0;
            }
            flag_cmp=0;
            continue;
        }
    }
    fclose(in);

    //cmp
    qsort(words,num_of_words,sizeof(words[0]),cmp);

    //output
    for(int i=0;i<num_of_words;i++)
    {
        printf("%s %d\n",words[i].word,words[i].num);
    }
    system("pause");
    return 0;
}
