#include<stdio.h>
#include<string.h>
struct word
{
    char a[100];
    int b;
}word[100000];
int main(){
     FILE *in;
     int o=0;
     int p=0;
     char d[100];
     char m;
     char n[100000];
     in=fopen("article.txt","r");
     while((m=fgetc(in))!=EOF)
     {
         if(isalpha(m)!=0)
         {
             word[o].a[p]=m;
             p++;
         }
         else if(ispunct(m)!=0||isspace(m)!=0)
         {
             word[o].a[p]='\0';
             o++;
             p=0;
         }
     }
     for(int i=0;i<o;i++)
     {
         for(int j=0;j<strlen(word[i].a);j++)
            word[i].a[j]=tolower(word[i].a[j]);
         word[i].b=1;
     }
     for(int i=0;i<o-1;i++)
     {
         for(int j=0;j<o-1-i;j++)
         {
             if(strcmp(word[j].a,word[j+1].a)>0)
             {
                 strcpy(d,word[j].a);
                 strcpy(word[j].a,word[j+1].a);
                 strcpy(word[j+1].a,d);
             }
         }
     }
     for(int i=0;i<o;i++)
     {
         for(int j=i+1;j<o;j++)
         {
             if(strcmp(word[i].a,word[j].a)==0&&word[i].b!=0&&word[j].b!=0)
             {
                 word[i].b++;
                 word[j].b=0;
             }
         }
     }
     for(int i=1;i<o;i++)
     {
         if(word[i].b!=0)
         {
             printf("%s %d\n",word[i].a,word[i].b);
         }
     }
     fclose(in);
    return 0;
}



