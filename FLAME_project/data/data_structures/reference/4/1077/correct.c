#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

struct word
{
	char name[200];
	int num;
}; 

void transmit(struct word array[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;array[i].name[j]!='\0';j++)
		{
			array[i].name[j]=tolower(array[i].name[j]);
		}
	}
}

void search(struct word array[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(array[i].name,array[j].name)==0)
			{
				array[i].num++;
				array[j].name[0] = '\0';
//				strcpy(array[j].name,"");
			}
		}
	}
//	for(i=0;i<n;i++)
//	{
//		if(strcmp(array[i].name,"NULL")!=0)
//		{
//			strcpy(newword[k].name,array[i].name);
//			newword[k].num=array[i].num;
//			k++;
//		}
//	}
//	for(i=0;i<n;i++)
//	{
//		for(j=0;j<n;j++)
//		{
//			if(strcmp(array[i].name,newword[j].name)==0)
//			{
//				newword[j].num++;
//			}
//			if(j==(n-1)
//			{
//				k=0;
//				while(newword[k].name!=NULL)
//				{
//					k++;
//				}
//				strcpy(newword[k].name,array[i].name);
//				newword[k].num=1;
//			}
//		}
		//k=strlen(array[i].name);
		//for(j=0,p=0;p<k&&array[i].name[p]==newword[j].name[p];p++,j++);
		//if(array[i].name[p]=='\0')
		//{
			//newword[j].num++;	
		//}
		//else
		//{
			//strcpy(newword[j].name,array[i].name);
			//newword[j].num=0;
		//}
//	}
}

void insertword(struct word array[],int n)
{
	int i,j;
	struct word tmp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(array[i].name,array[j].name)>0)
			{
				tmp.num=array[i].num;
				array[i].num=array[j].num;
				array[j].num=tmp.num;
				strcpy(tmp.name,array[i].name);
				strcpy(array[i].name,array[j].name);
				strcpy(array[j].name,tmp.name);
			}
		}
	}
} 

typedef struct word Word;
#define MAXLINE 1024
int main()
{
	int i=0,j=0,n=0,k=0;
	FILE *in;
    if((in=fopen("article.txt","r")) == NULL){
        printf("Cann't Open file article.txt!\n");
        return 1;
    }
	Word infor[1000];
	Word newword[1000];
	char c;
	char s[200];
	while(fscanf(in,"%c",&c)!=EOF)
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			s[j++]=c;
		}
		else
		{
			s[j] = '\0';
			strcpy(infor[i].name,s);
			infor[i].num=1;
//			puts(infor[i].name);
//			strcpy(s,"N");
			j=0;
			i++;
		}
	}
	n=i;
//	printf("out\n");
//	for(j=0;j<i;j++)
//	{
//		if(strcmp(infor[j].name,"N")!=0)
//		{
//			strcpy(newinfor[n].name,infor[j].name);
//			newinfor[n].num=1;
//			n++;
//		}
//	}
//	printf("%d",k); 
//	struct word newinfor[1000];
//	while(fscanf(in,"%s",infor[i].name)!=EOF)
//	{
//		i++;
//	}
//	for(j=0;j<n;j++)
//	{
//		printf("%s\n",infor[j].name);
//	}
	transmit(infor,n);
//	for(j=0;j<n;j++)
//	{
//		printf("%s\n",infor[j].name);
//	}
	search(infor,n);
	for(i=0;i<n;i++)
	{
		if(infor[i].name[0]!='\0')
		{
			strcpy(newword[k].name,infor[i].name);
			newword[k].num=infor[i].num;
			k++;
		}
	}
//	for(j=0;j<n;j++)
//	{
//		printf("%s\n",infor[j].name);
//	}
	insertword(newword,k);
	for(i=0;i<k;i++)
	{
		printf("%s %d\n",newword[i].name,newword[i].num);
	}
	
	return 0;
}

