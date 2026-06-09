//词频统计链表实现
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Word{
	char word[20];
	int cnt;
	struct Word*next;
};
struct Word *p,*p0,*q,*pf,*head,*t;
char in[20];
char ch;
int cmp;
char a[5]="a";
int main(){
	int i=0;
		FILE *inf;//定义一个指针变量
		char infile[]={"article.txt"};
		if((inf=fopen(infile,"r"))==NULL){
			printf("无法打开此文件\n");
			exit(0);
		}
for(int k=0;k<10000;k++){
//for(;ch!=EOF;){
//while((fscanf(inf,"%c",&ch))!=EOF){
	while(fscanf(inf,"%c",&ch)){
		if(ch>='a'&&ch<='z'){
			in[i]=ch;
		//	printf("%c",in[i]);
			i++;
		}
		else if(ch>='A'&&ch<='Z'){
			in[i]=ch+32;
			i++;
		}
		else{
			in[i]='\0';
			i=0;
			break;
		}
	}//p指向当前结点，q指向新增结点
	q=(struct Word*)malloc(sizeof(struct Word));
	strcpy(q->word,in);
	q->cnt=1;
//	puts(q->word);printf("\n");
	q->next=NULL;
	if(head==NULL){
		head=p=q;
	}
	else{
	//下面需要判断插在中间、开头、末尾、还是给对应的相加
	//都要通过遍历当前的链表，利用p0追踪位置
	//当pf指向的结点单词第一次后于新增单词时，插在p0后面p的前面
		for(pf=head;pf!=NULL;p0=pf,pf=pf->next){
			cmp=strcmp(q->word,pf->word);
		//	printf("比较返回结果为%d\n",cmp);
			if(cmp<0){
				//需要放在这个前面
				if(pf==head){
					head=q;
					q->next=pf;
					break;
				}
				else{
		//			printf("here\n");
					//说明不是最小的，不是插在头部，p0指向pf的上一个结点
					//把q插在p0的后面，pf的前面
		//			printf("此时p0指向%c",p0->word);
					p0->next=q;
					q->next=pf;
					break;
				}
			}
			else if(cmp==0){
				//和p目前值得这个单词完全一样
				pf->cnt++;
				free(q);
				break;
			}
			else ;
			//比这个单词更大，不用插到前面，继续往后找
		}
		if(pf==NULL){
			//说明已经找到最后一个去了，比之前的任何一个字典序都要更大，插在末尾就行
			p->next=q;
			p=q;
		}

	}
	/*	t=head;
		while(t!=NULL){
			puts(t->word);
			printf("%d\n",t->cnt);
			t=t->next;
		}*/
}

	t=head;
	while(t!=NULL){
		if(strcmp(t->word,a)>=0){
			printf("%s ",t->word);
			printf("%d\n",t->cnt);
		}
		t=t->next;
	}
	return 0;
}

