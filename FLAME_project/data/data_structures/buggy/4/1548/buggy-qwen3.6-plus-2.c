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
        for(i=0,k=0;s[i]!='\0';i++)
        {
            if(s[i]<'a'||s[i]>'z') // @@ The condition incorrectly treats lowercase letters as delimiters and fails to convert uppercase letters to lowercase properly. It should check if the character is NOT a letter (either upper or lower) to act as a delimiter, and handle uppercase conversion.
            {
                if(s[i]>='A'&&s[i]<='Z')
                {
                    toupper((int)s[i]); // @@ toupper returns the converted value but does not modify the argument in place. The result is ignored, so uppercase letters are not converted to lowercase. Also, this block is inside the 'else' of a check that already excluded lowercase, but the logic flow is flawed because it doesn't add the character to the word buffer.
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