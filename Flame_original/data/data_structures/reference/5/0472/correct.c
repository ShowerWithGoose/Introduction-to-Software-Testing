#include <stdio.h>
#include <stdlib.h>

struct  Node { //一个多项式节点结构
    int coe; //系数
    int pow; //幂
    struct Node *next;
}; 
int main()
{
    int a,n,i=0,j,k;
    int temp1,temp2;
    int b[50][2];
    char c;
    struct Node *head,*p,*q,*p0;
    head = p = NULL;
    do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a, &n, &c);
        if( head == NULL) //当前链表为空
             head = p = (struct Node *)malloc(sizeof(struct Node));
       else {//当前不是空链表，把该节点加入到链尾
            p->next = (struct Node *)malloc(sizeof(struct Node));
            p = p->next;
       }
       p->coe = a; p->pow = n; p->next = NULL;
     } while ( c !='\n');
do { //将第二个多项式的每个项插入到第一个多项式链表中
        scanf("%d%d%c", &a, &n, &c);//生成第二个多项式的一个节点
        q = (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        for(p=head; p!=NULL;p=p->next,i++){
        	b[i][0]=p->coe*q->coe;
        	b[i][1]=p->pow+q->pow;
		}

   } while ( c != '\n');
   j=i;
   for(i=0;i<j;i++){
   	for(k=i+1;k<j;k++){
   		if(b[i][1]==b[k][1]){
   			b[i][0]+=b[k][0];
   			b[k][0]=0;
   			b[k][1]=0;
		   }
	   }
   }
   for(i=1;i<j;i++){
   	if(b[i][1]>b[i-1][1]){
   		temp1=b[i][0];
   		temp2=b[i][1];
   	
   		b[i][0]=b[i-1][0];
   		b[i][1]=b[i-1][1];
   		b[i-1][0]=temp1;
   		b[i-1][1]=temp2;
   		i-=2;
	   }
   }
   for(i=1;i<j;i++){
   	if(b[i][1]>b[i-1][1]){
   		temp1=b[i][0];
   		temp2=b[i][1];
   	
   		b[i][0]=b[i-1][0];
   		b[i][1]=b[i-1][1];
   		b[i-1][0]=temp1;
   		b[i-1][1]=temp2;
   		//i-=2;
	   }
   }
   for(i=1;i<j;i++){
   	if(b[i][1]>b[i-1][1]){
   		temp1=b[i][0];
   		temp2=b[i][1];
   	
   		b[i][0]=b[i-1][0];
   		b[i][1]=b[i-1][1];
   		b[i-1][0]=temp1;
   		b[i-1][1]=temp2;
   		//i-=2;
	   }
   }
   for(i=0;i<j;i++){
   	if(b[i][0]!=0){
   		printf("%d %d ",b[i][0],b[i][1]);
	   }
   	
   }

    return 0;
}
//        for(p=head; p!=NULL; p0=p,p=p->next) {
//            if(q->pow > p->pow) { //找到一个结点p，其指数是第一个比当前项指数小的项，q应该插入到p之前
//                 if(p==head) { q->next = head; head = q; break; }//插入第一个节点前
//                 else { q->next = p; p0->next = q; break;} //将q插入到p前
//            }
//            else if(q->pow == p->pow)  { p->coe += q->coe; free(q); break;}//指数相等，系数相加(如果系数可以不是正整数， 这里其实还需要判断相加后系数是否为0 ）
//         }
//         if(p== NULL)  p0->next = q;   //没有找到比当前项指数小的项，将q插入到尾节点后

//    for(p=head; p!=NULL; p=p->next)//输出求和后的表达式各项
//         printf("%d  %d  ", p->coe,p->pow);



