#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int cft;
	int index;
	struct node *link;
}NODE,*LinkList;
int main()
{
	int  scan_cft=0,scan_index=0;                       //储存输入参数 
	LinkList mul1,mul2,p,q,c,n,r,end,y;
	int i=0,len;
	char *line1,*line2;
	
	line1=(char *)malloc(sizeof(char)*500);
	line2=(char *)malloc(sizeof(char)*500);
	
	gets(line1);
	gets(line2);                                     //输入多项式 
	
	len=strlen(line1);
	mul1= p =(LinkList)malloc(sizeof(NODE));              //多项式一申请空间 
	for(i=0;i<len;i++){
		int ch=0;
		q=(LinkList)malloc(sizeof(NODE));
		while(line1[i]!=' '&&i<len){
			if(line1[i]=='-'){
				ch=1;
				i++;
			}else{
				scan_cft=scan_cft*10+(line1[i]-'0');
				i++;
			}
			
		}
		i++;
		if(ch==0)
			q->cft=scan_cft;
		else
			q->cft=~scan_cft+1;
		while(line1[i]!=' '&&i<len){
			scan_index=scan_index*10+(line1[i]-'0');
			i++;
		}
		q->index=scan_index;
		p->link=q;
		p=p->link;
		scan_cft=0;
		scan_index=0;
	}
	p->link=NULL; 
//	q=mul1->link;
//	while(q!=NULL){
//		printf("%d %d ",q->cft,q->index );
//		q=q->link;
//	}
//	printf("\n");
	
	mul2=p=(LinkList)malloc(sizeof(NODE));       //多项式二申请空间 
	len=strlen(line2);
	for(i=0;i<len;i++){
		int ch=0;
		q=(LinkList)malloc(sizeof(NODE));
		while(line2[i]!=' '&&i<len){
			if(line2[i]=='-'){
				ch=1;
				i++;
			}else{
				scan_cft=scan_cft*10+(line2[i]-'0');
				i++;
			}
			
		}
		i++;
		if(ch==0)
			q->cft=scan_cft;
		else
			q->cft=~scan_cft+1;
			
			
		while(line2[i]!=' '&&i<len){
			scan_index=scan_index*10+(line2[i]-'0');
			i++;
		}
		q->index=scan_index;
		p->link=q;
		p=p->link;
		scan_cft=0;
		scan_index=0;
	}
	p->link=NULL;
//	q=mul2->link;
//	while(q!=NULL){
//		printf("%d %d ",q->cft,q->index );
//		q=q->link;
//	}

         //此时，仅有两个链表，头指针分别为mul1，mul2                                                                 
	end=(LinkList)malloc(sizeof(NODE));      //申请结果头指针                 
//	end->index=-1;
	end->link=NULL;
	p=mul1->link;
	y=q=mul2->link;                            //将p，q分别指向两个多项式的第一项 

	while(p!=NULL){
		while(q!=NULL){
			int temp=2;
			c=(LinkList)malloc(sizeof(NODE));         //申请一个临时结点 
			c->cft=p->cft*q->cft;                      //进行运算 
			c->index=p->index+q->index;
			c->link=NULL;
			if(end->link==NULL){   //将运算结果插入end链表中    ，  如果还没插入过，直接连在end后面 
				end->link=c;
			}else{                                                //否则，从头节点往后比，如果没到 NULL，遇到比他小的，就差在小的前面 ,遇到相等的就合并 
				n=end->link;        //n 用于 遍历end链表
				r=n; 
				while(n!=NULL&&c->index<=n->index){
					temp=0;
					if(c->index == n->index ){            //如果相等 
						n->cft +=c->cft ;
						temp=1;
						break;
					}
					r=n;
					n=n->link;
					
				}
				if(temp==1){
					
				}else if(temp==2){
					end->link=c;
					c->link=n;
				}else{
//					printf("123\n");
					r->link=c;
					c->link=n;
				}
			}
//			printf("124\n"); 
			q=q->link;
		}
		q=y;
		p=p->link;
	}
	
	p=end->link;
	while(p!=NULL){
		printf("%d %d ",p->cft ,p->index);
		p=p->link;
	}
	return 0;
} 



