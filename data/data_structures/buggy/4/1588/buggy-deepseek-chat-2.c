#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct Word{
    int times;
    char word[30];
}worD[10000];

int num=0;
void zhy(char arr[])
{
    int i;
    for(i=0;i<num;i++)
    {
        if(strcmp(worD[i].word,arr)==0)
        {
            worD[i].times++;
            return;
        }
    }
    worD[num].times++;
    strcpy(worD[num].word,arr);
    num++;
    return;
}
int cmp(void const *a,void const *b)
{
    int flag;
    flag=strcmp((*(struct Word *)a).word,(*(struct Word *)b).word);
    //if(flag<0)
    //{
    //    return -1;
    //}
    //else 
    //{
    //    return 1;
    //}
    return flag;
}
int main()
{
    FILE *fp=fopen("article.txt","r");
    char str[30],let;
    strcpy(str,"\0");
    char arr[30];
    strcpy(arr,"\0");
    int i=0;
    while((let=fgetc(fp))!=EOF)
    {
        if(let>='A'&& let<='Z')
        {
            let='a'+let-'A';
            str[i]=let;
            i++;
        }
        else if(let>='a'&& let<='z')
        {
            str[i]=let;
            i++;
        }
        else 
        {
            strcpy(arr,str);
            if(strcmp(arr,"\0")!=0)
            {
                zhy(arr);
            }
            i=0;
            int j=0;
            while(str[j]!='\0')
            {
                str[j]='\0';
                j++;
            }
            
        }        
    }
    qsort(worD,num,sizeof(struct Word),cmp);
    for(i=0;i<num;i++)
    {
        printf("%s %d\n",worD[i].word,worD[i].times);
    }
    fclose(fp);
    return 0;
}