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
    in=fopen("article.txt","r"); // @@ Missing NULL check for file pointer; if file open fails, subsequent fgets calls will cause a segmentation fault.
    char s[10010];
    char Word[50];
    struct word *list=NULL,*p=NULL,*q=NULL,*y=NULL;
    int i,k;
    while(fgets(s,10010,in)!=NULL) // @@ Word finalization only occurs on non-letter characters. If the file ends with a word, the last word remains in the buffer and is never counted.
    {
        for(i=0,k=0;s[i]!='\0';i++)
        {
            if(s[i]<'a'||s[i]>'z') // @@ Incorrectly groups uppercase letters with non-letters. Uppercase letters should be converted to lowercase and appended to the word buffer, not treated as delimiters.
            {
                if(s[i]>='A'&&s[i]<='Z')
                {
                    toupper((int)s[i]); // @@ toupper() returns the converted value but does not modify s[i] in place; the result is discarded. Also, tolower() should be used per problem requirements.
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
    p=list;
    while(p!=NULL)
    {
        printf("%s %d\n",p->WORD,p->shu);
        p=p->link;
    }
    return 0;
}