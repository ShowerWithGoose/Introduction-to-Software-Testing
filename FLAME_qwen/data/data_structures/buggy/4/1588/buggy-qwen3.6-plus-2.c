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
    worD[num].times++; // @@ Should be initialized to 1 (worD[num].times = 1;) for a new word entry, as incrementing relies on implicit global zero-initialization which is logically unclear.
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
    char str[30],let; // @@ 'let' should be declared as 'int' to correctly store the return value of fgetc() and properly compare with EOF.
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
            strcpy(arr,str); // @@ 'str' is not null-terminated before copying, which causes undefined behavior. str[i] = '\0'; must be added before this line.
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