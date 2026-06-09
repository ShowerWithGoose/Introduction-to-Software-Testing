#include<stdio.h>              
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int sumword = 0;//表示有几个结构体中存储有key 
struct node{
	char key[1003];
	int sum;
}word[1000003];
void judge(char store[])
{	
	int i,k;
	if(sumword == 0){
		for(i = 0;i <= strlen(store) - 1;i ++){
			word[1].key[i] = store[i];
		}
		word[1].key[i] = '\0';
		word[1].sum = 1;
		sumword ++;
	}
	else {
		for(k = 1;k <= sumword;k ++){//原结构体数组中已经储存
			if(strcmp(word[k].key,store)==0)
			{
				word[k].sum ++;
				break;
			}
		}
		if(k == sumword + 1)//原结构体数组中没有储存
		{
			for(i = 0;i <= strlen(store) - 1;i ++){
				word[k].key[i] = store[i];
			}
			word[k].key[i] = '\0';
			word[k].sum = 1;
			sumword ++;
		} 
	}
}
void quicksort(struct node word[],int left,int right)//key从小到大字典序排序 
{	
	if(left >= right)	return; 
	if(left < right)  
	{
		int j = left - 1,i;
		struct node p = word[right],tmp;
		for(i = left;i <= right - 1;i ++){
			if (strcmp(word[i].key,p.key)<0){
				j ++;
				tmp = word[i];
				word[i] = word[j];
				word[j] = tmp;
			}
		}
	word[right] = word[j + 1];
	word[j + 1] = p;
	quicksort(word,j + 2,right);
	quicksort(word,left,j);
	}
}
int main(void)
{	
	int i,k;
	char line[10003];
	char store[103];
	FILE* in;
	in = fopen("article.txt","r");
	while(fgets(line,1024,in)!=NULL)//在in指向的文件中读一行到line里面 
	{	
		k = 0;
		i = 0;
		while(!(isupper(line[i])||islower(line[i]))){
			i ++;
		}//i指向为字母 
		while(i <= strlen(line) - 1){//删去换行符 
			if(line[i]>=65&&line[i]<=90)	line[i] = line[i] + 32;//均转小写 
			if(islower(line[i])==0&&islower(line[i - 1])!=0){
				store[k] = '\0';
				judge(store);
				k = 0;
				i ++;
				continue;
			}
			if(islower(line[i]))	store[k ++] = line[i];
			i++;
		}
	}
	quicksort(word,1,sumword);
	for(i = 1;i <= sumword;i ++){
		printf("%s %d\n",word[i].key,word[i].sum);
	}
	fclose(in);
	return 0;
}



