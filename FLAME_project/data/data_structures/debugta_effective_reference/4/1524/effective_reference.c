#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	char c[1024];
	int num;
}infor[10010],tmp; 
int cmp(const void* a,const void* b)
{
	struct node* fp1=(struct node*)a;
	struct node* p2=(struct node*)b;
	return strcmp(fp1->c,p2->c);
}
int main()
{
	int i=0,j=0,k=0,flag=0,dcb_len=0;
	char a;
	char map[100]={0};
	FILE *fp1=fopen("article.txt","r");
	while((a=fgetc(fp1))!=EOF)
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
				for(j=0;j<dcb_len;j++)
				{
					if(strcmp(map,infor[j].c)==0)
					{
						flag=1;
						infor[j].num++;
						break;
					}
					else
						flag=0;
				}
				if(flag==0)
				{
					strcpy(infor[dcb_len].c,map);
					infor[dcb_len].num=1;
					dcb_len++;
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
	qsort(infor,dcb_len,sizeof(infor[0]),cmp); 
	for(i=0;i<dcb_len;i++)
	{
		printf("%s %d\n",infor[i].c,infor[i].num); 
	}
	fclose(fp1);
	return 0;
	
	
}

