#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct wordnum
{
	char wo[30];
	int num;
}word[600];
int cmp(const void *a,const void *b){
    struct wordnum c = *(struct wordnum*)a;
    struct wordnum d = *(struct wordnum*)b;
    if(strcmp(c.wo,d.wo)>0)
	     return 1;
    else
    	return -1;
}
int main(int argc, char *argv[]) {
	FILE *ART=fopen("article.txt","r");
	char str[1024]={0},wo[30]={0};
	int i=0,j=0,len=0,t=0,allnum=0,flag=0;
	fgets(str,1024,ART);
	while(feof(ART)==0/*gets(str)!=NULL*/)
	{
		
		len=strlen(str);
		for(i=0;i<len;i++)
			if(str[i]>='A'&&str[i]<='Z')
			str[i]=str[i]-'A'+'a';
		for(i=0;i<len;i++)
		{
			while((str[i]<'a'||str[i]>'z')&&i<len)
			i++;
			while(str[i]<='z'&&str[i]>='a')
				wo[j++]=str[i++];
			i--;
			int allnum1=allnum;
			if(wo[0]<='z'&&wo[0]>='a')
			{
					for(t=0;t<=allnum1;t++)
			{
				if(strcmp(wo,word[t].wo)==0)
				{
					word[t].num++;
					flag=1;
					break;
				}
			}	
			if(flag==0)
				{
					strcpy(word[allnum].wo,wo);
					word[allnum].num=1;
					allnum++;
				}
			}
			memset(wo,0,sizeof(wo));
			j=0;
			flag=0;
		}
		fgets(str,1024,ART);
	}
	qsort(word,allnum,sizeof(word[0]),cmp);
	for(i=0;i<allnum;i++)
	printf("%s %d\n",word[i].wo,word[i].num);
	fclose(ART);
	return 0;
}

