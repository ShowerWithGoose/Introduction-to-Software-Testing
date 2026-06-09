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
    worD[num].times++; // @@ Logic error: The 'times' field of the new entry is incremented before being initialized to 1 (or 0 then 1). It should be initialized to 1 first. Since it's a global/static array, it might be 0, so ++ makes it 1, but logically it's better to set it to 1 explicitly or ensure initialization. However, the bigger issue is that if `times` is not explicitly initialized to 0 before incrementing, it relies on zero-initialization of global variables. While globals are zero-initialized in C, the logic `worD[num].times++` sets it to 1. This part is technically okay for globals but bad practice. The real compilation error is likely elsewhere or this is a semantic bug. Let's look closer. Actually, the prompt says "Compilation Error". Let's check standard headers and syntax.
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