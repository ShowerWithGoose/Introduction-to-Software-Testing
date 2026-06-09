#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Num{
	int data;
	struct Num *next;
}num;

typedef struct Flag{
	char data;
	struct Flag *next;
}flag;

int main(){
//	num *n=(num *)malloc(sizeof(num));
//	num *p=n;
	int a,b,count=0;
	int num[100];
	char flag[100]; 
	int i;
	char c;
//	flag *f=(flag *)malloc(sizeof(flag));
//	flag *q=f;
	while(c!='='){
//		num *x=(num *)malloc(sizeof(num));
//		flag *y=(flag *)malloc(sizeof(flag));
		scanf("%d",&a);
		c=getchar();
		while(c==' '){
			c=getchar();
		}
		while(c=='*'||c=='/'){
			if(c=='*'){
				scanf("%d",&b);
				a=a*b;
				c=getchar();
				while(c==' '){
					c=getchar();
				}
			}
			if(c=='/'){
				scanf("%d",&b);
				a=a/b;
				c=getchar();
				while(c==' '){
					c=getchar();
				}
			}
		}
//		x->data = a;
//		x->next = NULL;
//		p->next = x;
//		p = p->next;
//		y->data = c;
//		y->next = NULL;
//		q->next = y;
//		q = q->next;
		flag[count]=c;
		num[count]=a;
		count++;
//		printf("\n");
//		printf("num : %d\n",num[count-1]);
//		printf("flag : %c\n",flag[count-1]);
//		printf("count : %d\n",count);
	}
//	p=n;
//	q=f;
//	a=p->data;
//	p=p->next;
	a=num[0];
	
	for (i=0;i<count;i++){
		if(flag[i]=='+'){
			a=a+num[i+1];
		}
		else if(flag[i]=='-'){
			a=a-num[i+1];
		}
		else if(flag[i]=='='){
			break;
		}
		else{
			printf("error!!!!\n");		
			printf("%c\n",flag[i]);
		}
		
//		if(q->data=='+'){
//			a=a+p->data;
//		}
//		else if(q->data=='-'){
//			a=a-p->data;
//		}
//		else if(q->data=='='){
//			break;
//		}
//		else{
//			printf("error!!!!\n");		
//			printf("%c\n",q->data);
//		}
	}
	printf("%d\n",a);
	return 0;
}





