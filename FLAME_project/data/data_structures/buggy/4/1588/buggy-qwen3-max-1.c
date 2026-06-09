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
    worD[num].times++; // @@ [The 'times' field is incremented without being initialized to 1. It should be set to 1 for a new word, not incremented from an uninitialized (garbage) value.]
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
    return flag; // @@ [The comparison function for qsort must return negative, zero, or positive values correctly. While strcmp does that, the commented-out logic suggests uncertainty. However, this line is actually correct. But note: the real issue is elsewhere.]
}
int main()
{
    FILE *fp=fopen("article.txt","r");
    char str[30],let; // @@ [The variable 'let' is declared as char, but fgetc() returns int. Using char may cause EOF comparison to fail on systems where char is unsigned, leading to infinite loops or missed EOF.]
    strcpy(str,"\0");
    char arr[30];
    strcpy(arr,"\0");
    int i=0;
    while((let=fgetc(fp))!=EOF) // @@ [Because 'let' is char, not int, the comparison with EOF (which is -1) can fail if char is unsigned, causing the loop to never terminate or process incorrectly.]
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