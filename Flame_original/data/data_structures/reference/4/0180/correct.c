#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
	char word[100];
	int num;
}LIST,*pp;
LIST list[10000];
int cmp(const void *a , const void *b)
{	
pp c1=(pp)a;pp c2=(pp)b;
return strcmp(c1->word,c2->word); 
}
int main(){
int i=0,j=0,k=0,lenlist=0,flag=0;
char a;char compare[100];
FILE *fp;
fp=fopen("article.txt","r");
while((a=fgetc(fp))!=EOF)
{
if(a>='A'&&a<='Z')
{
a='a'+a-'A';
compare[i]=a;
i++;
}
else if(a>='a'&&a<='z')
{
compare[i]=a;
i++;
}
else
{
compare[i]='\0';	
if(strlen(compare)){
        for(j=0;j<lenlist;j++)
            {
        if(strcmp(compare,list[j].word)==0)
            {
            flag=1;
            list[j].num++;//找到就加1
            break;
        }
        else
        flag=0;
        }//在已有的单词表里进行寻找
        if(flag==0)
        {
        strcpy(list[lenlist].word,compare);
        list[lenlist].num=1;
        lenlist++;
    }
    for(k=0;k<100;k++)
        compare[k]='\0';
}
i=0;
}
}
qsort(list,lenlist,sizeof(LIST),cmp);
for(i=0;i<lenlist;i++)
{
printf("%s %d\n",list[i].word,list[i].num);
}
fclose(fp);
return 0;
}

