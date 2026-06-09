#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 1000
#define lower(c) (c>='A'&&c<='a'?'a'-'A'+c:c)

typedef struct f__kaaaa
{
    char data[20];
    int frequncy;
}word,*wordptr;

int cmp(wordptr a,wordptr b)
{
    return strcmp(a->data,b->data);
}

word list[M];
int li;

int listword(char *w)
{
    int i=0;
    for(i=0;i<li;i++)
        if(strcmp(w,list[i].data)==0) return i;
    return -1;
}

int main()
{
   FILE *fin;
   fin=fopen("article.txt","r");
   char s,buf[20];
   int wi=0,ch,save=1;
   while((s=fgetc(fin))!=EOF)
   {
       if((s>='a'&&s<='z')||(s<='Z'&&s>='A'))
       {
           save=0;
           buf[wi]=s>='A'&&s<='Z'?'a'-'A'+s:s;
           wi++;
       }
       else
       {
           if(save==1) continue;
           buf[wi]='\0';
           wi=0;
           if(li==0)
           {
               strcpy(list[li].data,buf);
               list[li].frequncy++;
               li++;
               save=1;
           }
           else
           {
               ch=listword(buf);
               if(ch!=-1)
               {
                   list[ch].frequncy++;
                   save=1;
               }
               else
               {
                   strcpy(list[li].data,buf);
                   list[li].frequncy++;
                   li++;
                   save=1;
               }
           }
       }
   }
   qsort(list,li,sizeof(word),cmp);
   for(int i=0;i<li;i++) printf("%s %d\n",list[i].data,list[i].frequncy);
   fclose(fin);
   return 0;
}



