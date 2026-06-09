#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct count{
	char word[100];
	int number;
}point[1000],tmp;
void replace(struct  count point[1000],struct count tmp,int list){
	int i,j;
	for(i=0;i<list;i++){
		for(j=i+1;j<list;j++){
			if(strcmp(point[i].word,point[j].word)>0){
				tmp=point[i];
				point[i]=point[j];
				point[j]=tmp;
			}
		}
	}
}
int main(){
 FILE *fp1;
    fp1=fopen("article.txt","r");
	char dic[100]={0};
	char c;
	int flag=0;
	int list=0;//此时单词表长度为0 
int	i=0;
int	j=0;
int k=0;
	while((c=fgetc(fp1))!=EOF)
	{
		//接下来将读入字母全部转为大写便于判断
		if(c>='a'&&c<='z')
		{
			dic[i]=c;
			i++; 
			
		} 
		else if(c>='A'&&c<='Z')
		{
			c=c+'a'-'A';
			dic[i]=c;
			i++;
		}
		else {//此时说明单词读到空格处 
		  if(strcmp(dic,"\0")!=0){
			//在之前已经建好的单词表中先寻找
              for(j=0;j<list;j++){
              	if(strcmp(dic,point[j].word)==0){
              		point[j].number++;
              		flag=1;
              		break;
				  }
				  else flag=0;
			  } 
			  if(flag==0)//说明这个单词在建立的单词表中没有 
			  {
			  	strcpy(point[list].word,dic);//添加单词到原有的单词表中
				   point[list].number=1;
				     list++;
			  }
			 memset(dic,0,sizeof(dic));
		}
		i=0;
	}
}
     replace(point,tmp,list);
	for(i=0;i<list;i++)
	{
		printf("%s %d\n",point[i].word,point[i].number);
	}
	fclose(fp1);
	return 0;
}


