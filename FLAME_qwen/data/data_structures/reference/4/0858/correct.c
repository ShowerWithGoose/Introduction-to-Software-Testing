#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[8192];
struct wordcount
{
    char word[32];
    int num;
};
struct wordcount aptr[256];
char temp[64];
void EmptyArray(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = '\0';
    }
}
void sortbyName(struct wordcount s[], int n)
{
    int i, j;
    struct wordcount temp;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            if(strcmp(s[i].word,s[j].word)>0)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
}
int main()
{
    int c, i, j, k;
    int j0 = 0;
    int flag = 0;
    FILE *IN;
    IN = fopen("article.txt", "r");
    i = 0;
    while((c=fgetc(IN))!=EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            a[i] = c;
            i++;
        }
        else if(c>='A'&&c<='Z')
        {
            a[i] = c + 32;
            i++;
        }
        else
        {
            a[i] = ' ';
            i++;
        }
    }
    /*while((c=fgetc(IN))!=EOF)
    {
        a[i] = c;
        i++;
    }*/
    //printf("%s\n", a);

    i = j = k = 0;
    while(a[i]!='\0')
    {
        if(a[i]!=' ')
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        if(a[i]==' ')
        {
            //printf("temp = \"%s\"\n", temp);
            flag = 0;
            for (j = 0; j < j0; j++)
            {
                if(strcmp(temp,aptr[j].word)==0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                strcpy(aptr[j0].word, temp);
                j0++;
            }
            EmptyArray(temp);
            k = 0;
            i++;
        }
        while(a[i]==' ')
        {
            EmptyArray(temp);
            k = 0;
            i++;
        }
    }
    if(a[i]=='\0')
    {
        //printf("temp = \"%s\"\n", temp);
        if(temp[0]!='\0')
        {flag = 0;
        for (j = 0; j < j0; j++)
        {
            if(strcmp(temp,aptr[j].word)==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            strcpy(aptr[j0].word, temp);
            j0++;
        }}
        EmptyArray(temp);
    }
    
    //printf("\n");
    /*for (j = 0; j < j0; j++)
    {
        printf("%d:%s\n", j, aptr[j].word);
    }*/

    sortbyName(aptr, j0);
    //printf("\n");
    i = j = k = 0;
    while(a[i]!='\0')
    {
        if(a[i]!=' ')
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        if(a[i]==' ')
        {
            //printf("temp = \"%s\"\n", temp);
            for (j = 0; j < j0; j++)
            {
                if(strcmp(aptr[j].word,temp)==0)
                {
                    aptr[j].num++;
                    break;
                }
            }
            EmptyArray(temp);
            k = 0;
            i++;
        }
        while(a[i]==' ')
        {
            EmptyArray(temp);
            k = 0;
            i++;
        }
    }
    if(a[i]=='\0')
    {
        //printf("temp = \"%s\"\n", temp);
        for (j = 0; j < j0; j++)
        {
            if(strcmp(aptr[j].word,temp)==0)
            {
                aptr[j].num++;
                break;
            }
        }
        EmptyArray(temp);
    }
    for (j = 0; j < j0; j++)
    {
        printf("%s %d\n", aptr[j].word, aptr[j].num);
    }

    system("pause");
    return 0;
}
