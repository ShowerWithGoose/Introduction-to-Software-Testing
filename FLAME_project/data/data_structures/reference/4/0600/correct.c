#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct alphabet{
    char word[50];
    int count;
};
void bubbleSort(struct alphabet dic[],int n)
{
    int i,j,flag;
    struct alphabet hold;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(strcmp(dic[j].word,dic[j+1].word)>0)
            {
                hold=dic[j];
                dic[j]=dic[j+1];
                dic[j+1]=hold;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
int main()
{
    FILE *in;
    in=fopen("article.txt", "r");
    struct alphabet dic[1024];
    char read[10005],ch;
    int i=0,j=0,k=0,flag;
    while(fscanf(in,"%c",&read[i++])!=EOF);
    int len=strlen(read);
    for(i=0;i<len;i++)
    {
        if(isalpha(read[i]))
            dic[j].word[k++]=tolower(read[i]);
        else
        {
            if(dic[j].word[0]!=0) dic[j].count=1;
            else dic[j].count=0;
            j++;
            k=0;
        }
    }
    bubbleSort(dic,j);
    for (i=0;i<j;i++)
        if (strcmp(dic[i].word,dic[i+1].word)==0)
        {
            dic[i+1].count+=dic[i].count;
            dic[i].count=0;
            memset(dic[i].word,0,sizeof(dic[i]));
        }
    for (i=0;i<j;i++)
        if(dic[i].word[0]!=0)
            printf("%s %d\n",dic[i].word,dic[i].count);
    return 0;
}

