#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char a[200][30];
void exchange(char a[200][30],int n)
{
	char x[30];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(a[i],a[j])>0)
			{
				strcpy(x,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],x);
			}
		}
	}
}

int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	int i=0,j=0,n=0;
	int m[110],flag=0;//用于存次数 
	char x;//读入文件 
	x=fgetc(fp);
	while(x!=EOF)
	{
		if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
		{
			a[i][j]=x;
			j++;
		 } 
		 else if(ispunct(x)!=0||isspace(x)!=0)
		 {
		 	a[i][j]='\0';
		 	j=0;
		 	i++;
		 }
		x=fgetc(fp);
	}//将文件的每个单词抽出来 
	n=i;//单词总数 
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(a[i]);j++)
			a[i][j]=tolower(a[i][j]);
	 } //变成小写便于判断 
	 	exchange(a,n);//按字典序排序 
	for(i=0;i<n;i++)
	{
		flag=0;
		m[i]=1;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(a[i],a[j])==0)
			{
				m[i]++;
				flag=1;
				a[j][0]='\0';//将已经存在的清零标记 
			}
			if(a[j][0]=='\0')
				continue;
			else
			{
				if(flag==1)
				{
					i=j-1;//跳到下一个单词 
				}
				break;
			}
		}
		
	 } 
	 for(i=0;i<n;i++)
	 {
	 	if(a[i][0]!='\0')
	 		printf("%s %d\n",a[i],m[i]);
	  } 
	fclose(fp);
	return 0;
}


