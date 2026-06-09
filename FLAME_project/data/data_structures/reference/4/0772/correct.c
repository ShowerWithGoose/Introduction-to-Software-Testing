#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//qsort顺序为数组名，元素数量，元素大小，cmp 
int comp(char s1[],char s2[]){
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0'&&s2[i]!='\0')
	i++;
	if(s1[i]<s2[i])
	return 1;//s1在前面 
	else if(s1[i]>s2[i])
	return 0;//s2在前面 
	else if(s1[i]=='\0'&&s2[i]=='\0')
	return -1;//s1,s2完全一致 
}

void copy_string(char str1[],char str2[]) {
	int i=0;
	while(str2[i]!='\0') {
		str1[i]=str2[i];
		i++;
	}
	str1[i]='\0';//把str2复制到str1 
}

void dele(char *s){
	int i,j;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]>='A'&&s[i]<='Z')
		s[i]+=32;
		if(s[i]>='a'&&s[i]<='z')
		s[j++]=s[i];
	}
	s[j]='\0';
	
}
/*char word(){
	char c;
	int op,i,j;
	i=0;
	j=0;
	while(fscanf(in,"%c",&zi)!=EOF){
		op=0;
		if((zi>='A'&&zi<='Z'||zi>='a'&&zi<='z')&&j==0){
			j=1;
			c[i++]=zi;
			continue;
		}
		else if((zi>='A'&&zi<='Z'||zi>='a'&&zi<='z')&&j==1){
			op=1;
			c[i++]=zi;
		}
		if(op==0&&j==1){
			c[i]='\0';
			break;
		}
	}
	
}*/

int main(){
	FILE *in,*out;
	in=fopen("article.txt","r");
	char c[100],zi;
	int i,j,op;
	typedef struct node{
		char data[100];//要存的数据 
		int num;
		struct node *next;//链接下一个节点 
	}LNode,*LinkList; 
	LinkList p,q,r,first=NULL;
	i=0;
	j=0;
	while(fscanf(in,"%c",&zi)!=EOF){
		op=0;
		if((zi>='A'&&zi<='Z'||zi>='a'&&zi<='z')&&j==0){
			j=1;
			c[i++]=zi;
			continue;
		}
		else if((zi>='A'&&zi<='Z'||zi>='a'&&zi<='z')&&j==1){
			op=1;
			c[i++]=zi;
		}
		if(op==0&&j==1){
			c[i]='\0';
			break;
		}
		
	}
	dele(c);
	p=(LinkList)malloc(sizeof(LNode));//申请新节点
	copy_string(p->data,c);//赋值该节点 
	p->num=1;
	p->next=NULL;
	first=p;
	r=p;
	while(1){
		c[0]='\0';
		i=0;
		j=0;
		while(fscanf(in,"%c",&zi)!=EOF){
			op=0;
			if((zi>='A'&&zi<='Z'||zi>='a'&&zi<='z')&&j==0){
				j=1;
				c[i++]=zi;
				continue;
			}
			else if((zi>='A'&&zi<='Z'||zi>='a'&&zi<='z')&&j==1){
				op=1;
				c[i++]=zi;
			}
			if(op==0&&j==1){
				c[i]='\0';
				break;
			}
		}
		dele(c);
		if(c[0]=='\0')
		break;
		if(comp(c,first->data)==1){
			p=(LinkList)malloc(sizeof(LNode));
			p->num=1;
			copy_string(p->data,c);
			p->next=first;
			first=p;
			continue;//插在最前面 
		}
		else if(comp(c,first->data)==-1){
			first->num++;
			continue;//最前面 ++
		}
		else{
			q=first;
			op=0;
			while(q->next!=NULL){
				if(comp(q->next->data,c)==-1){
					op=1;//出现过
					q->next->num++;
					break;
				}
				else if(comp(c,q->next->data)==1){
					op=2;//插入成功
					p=(LinkList)malloc(sizeof(LNode));
					p->num=1;
					copy_string(p->data,c);
					p->next=q->next;
					q->next=p;
					break;
				}
				q=q->next;
			} 
			if(op==0){
				p=(LinkList)malloc(sizeof(LNode));
				p->num=1;
				copy_string(p->data,c);
				p->next=NULL;
				r->next=p;
				r=p;//插在末尾 
			}
		}
		
	}
	p=first;
	while(p!=NULL){
		printf("%s",p->data);
		printf(" %d\n",p->num);
		p=p->next;
	}
    return 0;
} 

