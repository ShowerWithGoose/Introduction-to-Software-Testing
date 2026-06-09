#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct{
    char p[300];
    int time;
}word[5000];

int main()
{
    FILE *in;
    in = fopen("article.txt","r");

    char a = fgetc(in);
    char doc[5000];
    int i = 0,o;

    while(a!=EOF)
    {
        doc[i++] = a;
        a = fgetc(in);
    }
//char doc[500];
//gets(doc);
//int i = 0,o;

    int num = 0;
    for(i = 0;doc[i]!='\0';i++)
    {
        if((doc[i]>='a'&&doc[i]<='z')||(doc[i]>='A'&&doc[i]<='Z'))
        {
            int k = i;
            for(o = 0;(doc[k+o]>='a'&&doc[k+o]<='z')||(doc[k+o]>='A'&&doc[k+o]<='Z');o++)
            {
                if(doc[k+o]>='a'&&doc[k+o]<='z')
                {
                    word[num].p[o] = doc[k+o];
                }

                else
                    word[num].p[o] = doc[k+o]-'A'+'a';
            }
            i+=o;
            num++;
        }
    }

    for(int y = 0;y<1000;y++)
    {
        word[y].time=1;
        for(int u = y+1;u<1000;u++)
        {
            if(strcmp(word[y].p,word[u].p)==0)
            {
                (word[y].time)++;
                word[u].p[0] = '\0';
            }
        }


    }

    for(int y = 0;y<1000;y++)
    {
        for(int u = y;u<1000;u++)
        {
            if(strcmp(word[y].p,word[u].p)>0)
            {
                char tmp[300];
                int temp;
                strcpy(tmp,word[y].p);
                strcpy(word[y].p,word[u].p);
                strcpy(word[u].p,tmp);
                temp = word[y].time;
                word[y].time = word[u].time;
                word[u].time = temp;
            }
        }
    }
    for(int y = 0;y<1000;y++)
    {
        if(word[y].p[0]!='\0')
        {
        for(int l = 0;word[y].p[l]!='\0';l++)
        {
            printf("%c",word[y].p[l]);
        }
        printf(" %d",word[y].time);
        printf("\n");
        }
    }
    fclose(in);

}



