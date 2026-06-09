#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct link{
	char word[50];
	int time;
	struct link* next;
};
char the_word[50],cha;
char wo_rd[100000][100],frequency[100000];
int counter;
int main(){
	struct link* first=NULL,*p,*q,*r;
	FILE *in;
	in=fopen("article.txt","r");
	if(in==NULL){
		printf("fail to open file\n");
	}
	int i=0;
	while((cha=fgetc(in))!=EOF){//逐个读取字符，到非字母处上一个单词结束 
		if(('a'<=cha&&cha<='z')||(cha<='Z'&&cha>='A')){//并且单词还在继续读入 
			if(cha<='Z'&&cha>='A'){
				cha=cha+32;//大写均转换成小写
			}
			the_word[i]=cha;
			i++;
		}
		else{//此时字符不是字母，说明是特殊符号或者单词结束 
			if(strlen(the_word)==0){//上一个单词为空 
				continue;
			}//此时说明上一个词已经结束	
			i=0;
			r=first;
			while(r!=NULL){
				if(strcmp(r->word,the_word)==0){//在链表里查找判断这个词有没有出现过 
					r->time++;
					goto out1;////
				}
				r=r->next;//
			}
			q=(struct link*)malloc(sizeof(struct link));//第一个r=NULL,创建一个链结点 
			memset(q,0,sizeof(q)); 
			q->next=NULL;
			if(first==NULL){
				first=p=q;//首个指针赋值 
			}
			else{
				p->next=q;
				p=p->next;
			}

			for(int j=0;j<strlen(the_word);j++){//把字符串放入链表元素中 
				q->word[j]=the_word[j];
			} 
			q->time=1;
			out1:;
			memset(the_word,0,sizeof(the_word));
		}	
	}
	r=first;//把链表的东西放到数组里 
	counter=0;
	int l=0;
	while(r!=NULL){
		frequency[counter]=r->time;
		for(int i=0;i<strlen(r->word);i++){
			wo_rd[l][i]=r->word[i];	
		}
		r=r->next;
		counter++;
		l++;
	}
	char temp_wo_rd[100];
	int temp_t;
	for(int i=0;i<counter;i++){//排序 
		for(int j=i;j<counter;j++){
			if(strcmp(wo_rd[i],wo_rd[j])>0){
				strcpy(temp_wo_rd,wo_rd[i]);
				temp_t=frequency[i];
				frequency[i]=frequency[j];
				frequency[j]=temp_t;
				strcpy(wo_rd[i],wo_rd[j]);
				strcpy(wo_rd[j],temp_wo_rd);
				memset(temp_wo_rd,0,sizeof(temp_wo_rd));
			}
		}
	}
	for(int i=0;i<counter-1;i++){
		if(strlen(wo_rd[i])==0){
			continue;
		}
		printf("%s %d\n",wo_rd[i],frequency[i]);
	}
	printf("%s %d",wo_rd[counter-1],frequency[counter-1]);
	return 0;
}

