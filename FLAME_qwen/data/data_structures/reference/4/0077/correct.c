#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct list{
	char word[30];
	int cnt;
	struct list* next;
}; 
int main()
{
	FILE *in;
	char c;
	int i,j;
	int flag=0,note;
	struct list *p,*q,*first=NULL;
	q=(struct list*)malloc(sizeof(struct list));
	q->next=NULL;
	first=p=q;
	in=fopen("article.txt","r");			
	while((c=fgetc(in))!=EOF){
		if(isalpha(c)){
			q=(struct list*)malloc(sizeof(struct list));
			q->next=NULL;
			q->cnt=1;	
			for(i=0;isalpha(c)!=0;i++){   //把所有连续字母存入一个新结点里 
				q->word[i]=tolower(c);
				c=fgetc(in);
			}  //现在q指向一个新单词结点，p还在q的前一个 
			q->word[i]='\0';
			if(flag==0){
				p->next=q;
			} 
			p=first;
			for(j=0;p->next!=NULL;j++){
				note=0;
				if(flag==0){
					flag=1;
					note=1;
				}
				else if(strcmp(p->next->word,q->word)==0){  //链表里面已经出现过这个单词
					p->next->cnt++; 
					free(q);
					q=NULL;
					note=1;
					break;
				}	
				else if(strcmp(p->next->word,q->word)>0){  //在此结点之前，都没有相同的单词，应把新单词插在p之后 
					q->next=p->next; 
					p->next=q;
					note=1;
					break;
				}
				p=p->next;
			}
			  if(note==0)//找到头了，也没有重复的单词被录入过，此时p指向最后一个结点 
				p->next=q; 	
						
		}
		//else c=fgetc(in);
	}
	p=first->next;	
	while(p->next!=NULL){
		printf("%s %d\n",p->word,p->cnt);
		p=p->next;
	}
	printf("%s %d",p->word,p->cnt);
	fclose(in);
 return 0;
}
/*
打开文件，以字母为首，遇到空格结束，读入字符串，
		一个字符一个字符地读，如果是非字母，就下一个，如果是字母，就继续把后面字母
		读入存到链表的字符数组里面，直到遇到空格或者非字母字符。 
大写全改为小写之后存入链表
新的单词读取后，存入新的结点，从第一个结点开始，
依次strcmp（old，new）内容，如果结果为负，说明此结点小于新结点字母顺序
就继续往后对比 
如果是0，则说明单词再次出现，直接改变原结点的cnt值，然后
删除新的结点
如果是正的，说明这个新单词第一次出现，并且应该插入当前结点的前面 
 
 



*/


