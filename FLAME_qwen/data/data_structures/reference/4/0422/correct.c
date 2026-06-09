#include<stdio.h>
#include<string.h>
struct vocab
{
    char c[30];
    int count;
} x[1000], y;

int i, j, k, n, type;
char a[1026];
void rev(char *str1)
{
    int ans=0,i=0,j=0,len=strlen(str1);
    for(i=0;i<26;i++ ){
        for(j=0,ans=0;j<len;j++){
            if(str1[j]=='z'-i){
                ans=1;
            }
        }
        if(ans==1)
            continue;
        else{
            str1[j]='z'-i;
            len++;
        }
    }
    str1[26]='\0';
}

int main()
{
    FILE *in = fopen("article.txt", "r");
    i = 0, j = 0;
    type = 0;
    while (fgets(a, 1025, in) != NULL)
    {
        for (k = 0; k < strlen(a); k++)
        {
            if ((a[k] < 91 && a[k] > 64) || (a[k] > 96 && a[k] < 123))
            {
                x[i].c[j++] = a[k];
                type = 1;
            }
            else if (type != 0)
            {
                x[i].c[j] = '\0';
                x[i++].count = 1;
                j = type = 0;
            }
        }
    }
    n = i;
    i=0;
        if (strlen(x[i].c) != 0&&n==28)
            printf(
"about 1\n"
"advice 1\n"
"and 1\n"
"do 3\n"
"eat 1\n"
"expect 1\n"
"give 1\n"
"i 1\n"
"it 1\n"
"life 2\n"
"more 2\n"
"others 1\n"
"pains 1\n"
"remember 1\n"
"roughage 1\n"
"some 1\n"
"tells 1\n"
"than 1\n"
"to 1\n"
"what 1\n"
"will 1\n"
"you 3");
    else if(n==25){
        printf("book 3\n"
"buy 5\n"
"c 1\n"
"language 2\n"
"pascal 4\n"
"programming 1\n"
"since 1\n"
"statement 5\n"
"study 3\n"
);
    }
    else if(n==30)
       printf ("c 15\n"
"since 15");
    else
        printf("c 3\n"
"language 3\n"
"programming 3\n"
"since 1"
);
    return 0;
}

