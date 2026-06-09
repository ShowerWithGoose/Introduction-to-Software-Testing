#include<stdio.h>
#include<string.h>
struct statistic{
	char word[100];
	int num;
};
struct statistic index[1000];
char line[300];
char buf[100];
int check(char buf[])
{
	int i=0,j=0,flag=0,out=0;
	for(i=0;index[i].word[0]!='\0';i++)
	{
		for(j=0;index[i].word[j]!='\0';j++)
		{
		    if(index[i].word[j]==buf[j]&&strlen(index[i].word)==strlen(buf))
		        flag=1;
		    else
		        flag=0;
		    if(flag==0)
		        break;
		}
		if(flag==1)
		{
		    index[i].num++;
		    out=1;
		    break;
		}
	}
	if(out==1)
	    return 1;
	else
	    return 0;
}
void swap(int a,int b)//两行交换函数 
{
	char temp;
	int tempi;
	for(int i=0;i<50;i++)
	{
		temp=index[a].word[i];
		index[a].word[i]=index[b].word[i];
		index[b].word[i]=temp;
	}
	tempi=index[a].num;
	index[a].num=index[b].num;
	index[b].num=tempi;
}
void sort()//排序函数 
{
	int min=0;
	for(int i=0;index[i].word[0]!='\0';i++)
	{
		min=i;
		for(int j=i;index[j].word[0]!='\0';j++)
		    if(strcmp(index[min].word,index[j].word)>0)
			    min=j;  
		if(min!=i)
		    swap(i,min); 
	}	   
}
int main()
{
	int input,letter,indexnum=0,clear,output=0;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(line,1024,in)!=NULL)
	{
		input=0;
		while(line[input]!='\0')
		{
			if(line[input]==' ')
			{
				input++;
				continue;
			}
			for(letter=0;line[input]!=' '&&line[input]!='\0';input++)
			{
				if((line[input]>='A'&&line[input]<='Z')||(line[input]>='a'&&line[input]<='z'))
				{
					if(line[input]>='A'&&line[input]<='Z')
					    buf[letter]=line[input]+'a'-'A';
					else 
				        buf[letter]=line[input];
				    letter++;
				}
				else
				{
				    input++;
				    break;
				}
			}
			if(check(buf)==0&&buf[0]!='\0')
			{
			    strcpy(index[indexnum].word,buf);
			    index[indexnum].num=1;
			    indexnum++;
			}
			for(clear=0;buf[clear]!='\0';clear++)
		        buf[clear]='\0';
		}
		for(clear=0;line[clear]!='\0';clear++)
		    line[clear]='\0';
	}
	sort();
	for(output=0;index[output].num!=0;output++)
	    printf("%s %d\n",index[output].word,index[output].num);
	return 0;
}

