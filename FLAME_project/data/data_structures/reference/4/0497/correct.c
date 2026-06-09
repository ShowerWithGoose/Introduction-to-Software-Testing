#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
struct search
{
    char word[30];
    int count;
} w[1000]; //单词表结构


int main()
{
    char temp[100],ch[30];
    int i,j,k,n=0;
    int line=0,number;
    FILE *INPUT;
    INPUT = fopen("article.txt", "r");
    while(fgets(temp,100,INPUT)!=NULL)
    {
        /*
                for(i=0; i<strlen(temp); i++)
                {
                    printf("%c",temp[i]);
                }printf("\n");
        */

        for(i=0; temp[i]!='\0'; i++)
        {
            if(isupper(temp[i]))
            {
                temp[i]=tolower(temp[i]);
            }
            else
            {
                continue;
            }
        }//将文本中的大写字母全部转化为小写字母。
        //printf("%s",temp);
        temp[strlen(temp)]='\0';


        for(i=0; temp[i]!='\0'; i++)
        {
            if(islower(temp[i]))
            {
                for(j=0; islower(temp[i]); i++,j++)
                {
                    w[line].word[j]=temp[i];
                }
                n++;
                w[line].count=0;
                w[line].count+=1;
                line++;
            }
        }
        /*
                for(i=0; i<n; i++)
                {
                    //printf("%s\n",w[i].word);
                    printf("%s %d\n",w[i].word,w[i].count);
                }
        */
    }



    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(w[i].word,w[j].word)==0)
            {
                w[i].count+=w[j].count;
                for(k=j; k<n; k++)
                {
                    w[k]=w[k+1];
                }//去重。
                j--;
                n--;
            }
        }
    }


            for(i=0; i<n; i++)
            {
                for(j=0; j<n-1-i; j++)
                {
                    if(strcmp(w[j].word,w[j+1].word)>0)
                    {
                        strcpy(ch,w[j].word);
                        strcpy(w[j].word,w[j+1].word);
                        strcpy(w[j+1].word,ch);

                        number=w[j].count;
                        w[j].count=w[j+1].count;
                        w[j+1].count=number;
                    }
                }
            }



    for(i=0; i<n; i++)
    {
        //printf("%s\n",w[i].word);
        printf("%s %d\n",w[i].word,w[i].count);
    }

    return 0;
}












