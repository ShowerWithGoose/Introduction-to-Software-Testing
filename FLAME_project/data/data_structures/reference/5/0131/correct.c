#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 32
struct Node{
	int x;
	int y;
	struct Node *link;
};
typedef struct Node *Nodeptr;
typedef struct Node Node;
int main(){
int a,b;
char c;
struct Node *list1,*list2=NULL;
struct Node *p1,*p2,*q1,*q2,*p0=NULL;
list1=p1=NULL;
do{
scanf("%d%d%c",&a,&b,&c);
q1=(Nodeptr)malloc(sizeof(Node));
q1->x=a;
q1->y=b;
q1->link=NULL;	
if(list1==NULL)
list1=p1=q1;
else{
p1->link=q1;
p1=p1->link;
}
}
while(c!='\n');
int a2,b2;
do{ //将第二个多项式的每个项插入到第一个多项式链表中
scanf("%d%d%c",&a,&b,&c);//生成第二个多项式的一个节点
for(p1=list1; p1!=NULL; p1=p1->link) {
//将第二个多项式的每个项与第一个多项式的每个项相乘（系数相乘，指数相加）
a2=a*p1->x;
b2=b+p1->y;   
//然后插入第三个链表的相应位置/排序
q2=(struct Node *)malloc(sizeof(Node));
q2->x=a2; 
q2->y=b2; 
q2->link=NULL;
if(list2==NULL)
list2=p2=q2;//第一次是空链表
else{
for(p2=list2;p2!=NULL;p0=p2,p2=p2->link) {
if(q2->y>p2->y){
if(p2==list2) { 
q2->link=list2; 
list2=q2; 
break; 
}//插入到头节点前
else{ 
q2->link=p2;
p0->link=q2; 
break;
} //将q插入到p前
}
else if(q2->y==p2->y)  
{ 
p2->x+=q2->x; 
break;
}//指数相等，系数相加
}
if(p2==NULL)  
p0->link=q2;   //将q插入到尾节点后    
}
}
} 
while(c!='\n');
int i;
for(p2=list2;p2!=NULL;p2=p2->link){
printf("%d %d ",p2->x,p2->y);
for(i=0;i<100;i++);
}
	return 0;
} 



