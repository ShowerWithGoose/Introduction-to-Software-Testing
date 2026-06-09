//
//  main.m
//  all
//
//  Created by  on 2024/3/29.
//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
struct word{
    char WORD[30];
    int shu;
    struct word* link;
};
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char s[10010];
    char Word[50];
    struct word *list=NULL,*p=NULL,*q=NULL,*y=NULL;
    int i,k;
    while(fgets(s,10010,in)!=NULL)
    {
        for(i=0,k=0;s[i]!='\0';i++) // @@ k should not be reset to 0 at the beginning of each line, otherwise words at the end of a line will be lost. k should be initialized to 0 before the while loop.
        {
            if(s[i]<'a'||s[i]>'z')
            {
                if(s[i]>='A'&&s[i]<='Z')
                {
                    toupper((int)s[i]); // @@ toupper does not modify s[i] in place, and uppercase letters should be converted to lowercase and added to the word buffer. It should be Word[k++] = tolower(s[i]);
                }
                else
                {
                    Word[k]='\0';
                    if(k>0)
                    {
                        if(list==NULL)
                        {
                            list=(struct word *)malloc(sizeof(struct word));
                            list->link=NULL;
                            strcpy(list->WORD,Word);
                            list->shu=1;
                        }
                        else
                        {
                            p=list;
                            y=NULL;
                            while(p!=NULL)
                            {
                                if(strcmp(p->WORD,Word)<0)
                                {
                                    y=p;
                                    p=p->link;
                                    continue;
                                }
                                else if(strcmp(p->WORD,Word)==0)
                                {
                                    y=p;
                                    p->shu++;
                                    break;
                                }
                                else
                                {
                                    q=(struct word*)malloc(sizeof(struct word));
                                    strcpy(q->WORD,Word);
                                    q->shu=1;
                                    q->link=p;
                                    if(p!=list)
                                    {
                                        y->link=q;
                                    }
                                    else
                                    {
                                        list=q;
                                    }
                                    y=q;
                                    break;
                                }
                            }
                            if(p==NULL)
                            {
                                q=(struct word*)malloc(sizeof(struct word));
                                strcpy(q->WORD,Word);
                                q->shu=1;
                                y->link=q;
                                q->link=NULL;
                            }
                        }
                    }
                    k=0;
                }
            }
            else
            {
                Word[k++]=s[i];
            }
        }
    }
    p=list; // @@ The last word in the file might not be processed if it doesn't end with a non-letter character. A check for k>0 should be added here to process the remaining word.
    while(p!=NULL)
    {
        printf("%s %d\n",p->WORD,p->shu);
        p=p->link;
    }
    return 0;
}