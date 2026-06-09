#include <stdio.h>
#include <stdlib.h>

struct link{
	int cfc, exp;
	struct link * next;
};

int main() {

	int n, m;
	int Cfc, Exp;
	
	struct link * head1 = NULL;
	struct link * temp1, * temp2;//1：当前节点，2：尾节点
	head1 = (struct link *) malloc(sizeof(struct link));
	temp2 = head1;
	while(scanf("%d%d", &n, &m)) {
		temp1 = (struct link *)malloc(sizeof(struct link));
		temp1 -> cfc = n;
		temp1 -> exp = m;
		temp1 -> next = NULL;
		temp2 -> next = temp1;
		temp2 = temp1;
		
		if (getchar() == '\n') break;
	}
	
	struct link * head2 = NULL;
	struct link * temp3, * temp4;//3：表2中的当前节点，4：表2的尾节点
	struct link * p_to_2;//用来遍历表2（查找指数）
	head2 = (struct link *) malloc(sizeof(struct link));
	head2 -> next = NULL;
	temp4 = head2;
	while(scanf("%d%d", &n, &m)) {
		temp1 = head1 -> next;//用遍历表1（分别计算）
		while(temp1 != NULL) {//遍历表1
		
			Cfc = temp1->cfc * n;
			Exp = temp1->exp + m;
			temp3 = (struct link *) malloc(sizeof(struct link));
			temp3 -> cfc = Cfc;
			temp3 -> exp = Exp;
			temp3 -> next = NULL;//得到这一步乘法的结果
			
			p_to_2 = head2;//从头开始查找??
			int flag = 0;
			while(p_to_2 -> next != NULL) {
				
				if (p_to_2 -> next -> exp == Exp) {//相等了
					p_to_2 -> next -> cfc += Cfc;
					flag = 1;
					break;
				}else if (p_to_2 -> next -> exp < Exp) {//找到a1 > Exp > a2 了,把他放a1后面
					temp3 -> next = p_to_2 -> next;
					p_to_2 -> next = temp3; 
					flag = 1;
					break;	
				}
				p_to_2 = p_to_2 -> next;
				
			}
			
			//如果进??行到这一步，就把他放在最后
			if (flag == 0) {
				temp4 -> next = temp3;
				temp4 = temp3;
				
			}

			temp1 = temp1 -> next;			
		}
		
		if (getchar() == '\n') break;
	}
	
	temp3 = head2 -> next;
	while(temp3 != NULL) {
		printf("%d %d ", temp3->cfc, temp3->exp);
		temp3 = temp3 -> next;
	}
	
	return 0;
}

