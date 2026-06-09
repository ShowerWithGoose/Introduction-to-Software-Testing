#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    char a[1024];
    int b;
}word[2048],mid;

int judge(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return 1;
    else
        return 0;
}

char tolow(char c)
{
    if(c>='A'&&c<='Z')
        return c+=32;
    else
        return c;
}

void sort(int j)
{
    for(int y=0;y<j;y++)
    {
        for(int h=y+1;h<j;h++)
        {
                if(strcmp(word[y].a,word[h].a)>0)
                {
                    mid=word[y];
                    word[y]=word[h];
                    word[h]=mid;
                }
        }
    }
}

int main()
{
FILE*article;
article=fopen("article.txt","r");
char s[10005];
char ch;
int k=0,m=0,j=0;
while((ch=fgetc(article))!=EOF)
{
    s[k]=ch;
    k++;
}
for(int i=0;i<k;i++)
{
    if(judge(s[i]))
    {
        word[j].a[m]=tolow(s[i]);
        m++;
    }
    else if(judge(s[i])==0)
    {
        j++;
        m=0;
    }
}
for(int u=0;u<j;u++)
{
    if(strlen(word[u].a)!=0)
     word[u].b=1;
}
sort(j);
for(int y=0;y<j;y++)
{
      if(strcmp(word[y].a,word[y+1].a)==0)
      {
          word[y+1].b+=word[y].b;
          word[y].b=0;
      }
}

for(int u=0;u<j;u++)
{
    if(word[u].b!=0)
        printf("%s %d\n",word[u].a,word[u].b);
}
fclose(article);
  return 0;
}



