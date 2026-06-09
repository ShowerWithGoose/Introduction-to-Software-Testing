#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct words{
	char vol[30];
	int num;
	struct words *link;
}; 
typedef struct words words; 

void sort(words *head){//从大到小排序 
	words *r=NULL, *tail=NULL;
	r = head;
	tail = NULL;
	if (r == NULL || r->link == NULL){
		return;
	}//这个链表里没有东西 ；或者这个链表里只有一个东西，所以不需要排序了
	while (r != tail){//这个r==tail意味着从已经排完了所有的 
		while (r->link != tail){//至少还有两个才到最后一个，有得排 
			if (strcmp(r->vol,r->link->vol) >0){//把词汇从小到大排 
				char temp[30];                    
				strcpy(temp,r->vol);
				strcpy(r->vol,r->link->vol);
				strcpy(r->link->vol,temp);//交换
			}//确定链表最后一个是最小的，下一步是把前n-1个再排序，让前n-1个数的最后一位是最小的 
			r = r->link;//r++ 
		}//把当前最小的移到了最后 
		tail = r;//tail指最后一个 
		r = head;//把找到的最小值从下一轮排序里面剔除；从第一个开始排，r指向第一个 
	}
}

int main(){
	FILE *fp;
	char l[11005];//读"Do not take to heart every thing you hear.""Do not take to heart every thing you hear."入一行字line
    fp=fopen("article.txt","r");//只读入
    if(fp==NULL){
    	printf("error");
    	return 0;
	}
    else if(fp!= NULL){
	//gets(l);
	int i;
	words *t=NULL,*list=NULL,*p=NULL;
	int count=0;
	char word[11105][30];
	int j=0,k=0,n=0;
	//if(fgets(l,11000,fp)==NULL){
	//	printf("haven't read");
	//}
	while(fgets(l,11000,fp)!=NULL){//每次只读入一行，放进了l里
		int length=strlen(l);
		l[length]='\0';
		i=1;
		k=0;//每句话的第一个词从编号1开始 
		//"Do not take to heart every thing you hear."
		while(l[k]!='\0'){//最后一位是EOF
			if(l[k]>='a'&&l[k]<='z'){
				word[i][j]=l[k];
				j++;
			}
			else if(l[k]>='A'&&l[k]<='Z'){
				l[k]+='a'-'A';
				word[i][j]=l[k];
				j++;
			}
			else{//不是字母 
				if(k>=1&&((l[k-1]>='a'&&l[k-1]<='z')||(l[k-1]>='A'&&l[k-1]<='Z'))){
					word[i][j]='\0';
					j=0;
					//printf("%s\n",word[i]);
					i++;
				}
			}
			k++;
			//printf("%d\n",i);
		}//从句子读成一个一个单词
		word[i][j]='\0';//最后一个词后面不是空格，用这个补 
		//一行话有i个词
		int m; 
		for(m=1;m<i;m++){
			t=(words *)malloc(sizeof(words));
			strcpy(t->vol,word[m]);
			if(list==NULL){
				list=p=t;
			}
			else{
				p->link=t;
				p=p->link; 
			}
			t->link=NULL;//删除这个t
		}
	}
	
	/*printf("---------------------1\n");
	
	for(p=list;p!=NULL;p=p->link){
		printf("%s\n",p->vol);
	}
	printf("---------------------2\n");*/
	sort(list);//给单词排序
	
	/*for(p=list;p!=NULL;p=p->link){
		printf("%s\n",p->vol);
	}
	printf("---------------------3\n");*/
	for (p = list; p != NULL; p = p->link){
		p->num=1;
	}//每一个词出现一次 
	for (p = list; p != NULL; p = p->link){//p = p->link与i++差不多
		words *r1 = p, *r2 = NULL;
		for (r2 = p->link; r2 != NULL; r2 = r2->link){//r2永远在r1后面 
			if (strcmp(r2->vol,p->vol)==0){//相同的项 
				p->num++;
				r1->link = r2->link;
				free(r2);//再删掉 
				r2 = r1;
			}
			else{
				r1 = r2;//从加起来的后面一个再开始
			} 
		}
	}//把后面相同的单词删了，个数加在前面 
	
	for(p=list;p!=NULL;p=p->link){
		printf("%s %d\n",p->vol,p->num);
	}
	return 0;
	}
}

