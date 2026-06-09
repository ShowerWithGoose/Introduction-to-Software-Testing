#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	char c[1024];
	int num;
}list[10010],tmp; 
int cmp(const void* a,const void* b)
{
	struct node* p1=(struct node*)a;
	struct node* p2=(struct node*)b;
	return strcmp(p1->c,p2->c);
}
int main()
{
	int i=0,j=0,k=0,flag=0,len=0;
	char a;
	char map[100]={0};
	FILE *p1=fopen("article.txt","r");
	while((a=fgetc(p1))!=EOF)
	{
		if(a<=90&&a>=65)
		{
			a=a+'a'-'A';
			map[i++]=a;
		}
		else if(a<=122&&a>=97)
		{
			map[i++]=a;
		}
		else{
			if(strcmp(map,"\0")!=0)
			{
				for(j=0;j<len;j++)
				{
					if(strcmp(map,list[j].c)==0)
					{
						flag=1;
						list[j].num++;
						break;
					}
					else
						flag=0;
				}
				if(flag==0)
				{
					strcpy(list[len].c,map);
					list[len].num=1;
					len++;
				}
				for(k=0;k<100;k++)
				{
					map[k]='\0';
				}
			}
			i=0;
		}
	}
	i=0,j=0;
	flag=0;
	qsort(list,len,sizeof(list[0]),cmp); 
	for(i=0;i<len;i++)
	{
		printf("%s %d\n",list[i].c,list[i].num); 
	}
	fclose(p1);
	return 0;
	
	
}

