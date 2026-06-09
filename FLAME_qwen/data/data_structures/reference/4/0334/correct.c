#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct art{
	char s[20];
	int cot;
	int len;
}art[200]; 
int main()
{
	int i,leng,j=0,k=0,n,m;
	char a;
	char temp[20] ;
	char txt[10086] ;
	FILE *fp=fopen("article.txt","r");
	i=0;
	a=fgetc(fp) ;
	while(a!=EOF) { //读入
		txt[i]=a;
		i++;
		a=fgetc(fp) ;
	}
	leng=strlen(txt);
	for(i=0; i<leng; i++) { //全转为小写
		if(txt[i]>='A' && txt[i]<='Z')
			txt[i]=txt[i]-'A'+'a';
	}
	for(i=0;i<leng;i++)//转化成单词 
	{
		if(txt[i]>='a' && txt[i]<='z') 
		{
			art[j].s[k]=txt[i] ;
			k+=1;
		}
		else if(txt[i+1]>='a' && txt[i+1]<='z') /*txt[i]==' ' || txt[i]=='\n'*/
		{
			j+=1;//开始读下一个单词 
			k=0;
		}
	}
	for(i=0;i<=j;i++)//遍历，将空的删了 ，wdnmd空一行 
	{
		art[i].len=strlen(art[i].s);
		art[i].cot=1;
		if(art[i].len==0)
		{
			for(k=i;k<=j;k++)
			{
				art[k].len=strlen(art[k+1].s);
				strcpy(art[k].s,art[k+1].s) ;
			}
			j-=1;//不然会漏了一项 
		}
	}
	//j=单词数 
	//上面，这边的时候，输入word（（word，j=1，是正确的 ,但是进不了下面第二个for循环 
	for(i=0;i<j;i++) 
	{
		for(k=i+1;k<=j;k++)
		{
			//如果相同，就把第k个删掉，然后i.cot++ 
				if(strcmp(art[i].s,art[k].s)==0)
				{
					art[i].cot++;
					for(n=k;n<j;n++)
					{
						art[n].len=art[n+1].len;
						strcpy(art[n].s,art[n+1].s) ;
					}
					j--; 
					k--;
				}
		}
	}
	
	for(i=0;i<j;i++)//冒泡排序 
	{
		for(k=0;k<j-i;k++)
		{
			if(strcmp(art[k].s,art[k+1].s)>0)
			{
				strcpy(temp,art[k].s) ;
				strcpy(art[k].s,art[k+1].s) ;
				strcpy(art[k+1].s,temp) ;
				m=art[k].cot;
				art[k].cot=art[k+1].cot;
				art[k+1].cot=m;
			}
		}
	}
	for(i=0;i<=j;i++)
	{
		printf("%s %d\n",art[i].s,art[i].cot) ;
	}
	fclose(fp) ;
	return 0;
}

