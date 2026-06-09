#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
struct term{
	int coefficient;//系数
	int index;//指数
	struct term* back;
	struct term* next;
};
struct term *multiscan();//输入多项式 
struct term *add(struct term *previous,int coefficient,int index);//末尾增加一项
void release(struct term *head);//释放内存 
struct term *calculate(struct term *multinomial_1,struct term *multinomial_2);//多项式顺序相乘 
void array(struct term *result);//排序 
struct term *delete_pi(struct term *address);//删除一项，返回上一个位置 

int main(){
struct term *multinomial_1;//多项式 
struct term *multinomial_2;
struct term *result;//结果多项式 
struct term *pi;
multinomial_1 = multiscan();
multinomial_2 = multiscan();
result = calculate(multinomial_1,multinomial_2);
array(result);
pi = result;
while(1){
	printf("%d %d ",pi->coefficient,pi->index);
	if(pi->next == NULL)break;
	pi = pi->next;
}
release(multinomial_1);
release(multinomial_2);
release(result);
return 0;
} 

struct term *multiscan(){
	struct term *pi, *head;
	int coefficient, index;
	char c;
	head = (struct term *)malloc(sizeof(struct term));
	head->back = NULL;
	pi = head;
	scanf("%d%d",&pi->coefficient,&pi->index);
	while(1){
		c = getchar();
		if(c=='\n'){
			pi->next = NULL;
			return head;
		}
		scanf("%d%d",&coefficient,&index);
		pi = add(pi,coefficient,index);
	}
}

struct term *add(struct term *previous,int coefficient,int index){
	struct term *pi;
	pi = (struct term *)malloc(sizeof(struct term));
	pi->coefficient = coefficient;
	pi->index = index;
	pi->next = NULL;
	previous->next = pi;
	pi->back = previous;
	return pi;
}

void release(struct term *head){
	while(head->next != NULL){
		head = head->next;
		free(head->back);
	}
	free(head);
}

struct term *calculate(struct term *multinomial_1,struct term *multinomial_2){
	int coefficient, index;
	struct term *mul_1, *mul_2, *result, *pi;
	mul_1 = multinomial_1;
	mul_2 = multinomial_2; 
	result = (struct term *)malloc(sizeof(struct term)); 
	pi = result;
	result->coefficient = (mul_1->coefficient) * (mul_2->coefficient);
	result->index = (mul_1->index) + (mul_2->index);
	result->next = NULL;
	if(mul_2->next == NULL && mul_1->next == NULL){
		return result;
	}
	if(mul_2->next == NULL){
		mul_1 = mul_1->next;
	    while(1){
		    coefficient = (mul_1->coefficient) * (mul_2->coefficient);
		    index = (mul_1->index) + (mul_2->index);
		    pi = add(pi,coefficient,index);
	     	if(mul_1->next == NULL)break;
    		mul_1 = mul_1->next;
	}
		return result;
	}
	if(mul_1->next == NULL){
		mul_2 = mul_2->next;
		while(1){
			coefficient = (mul_1->coefficient) * (mul_2->coefficient);
			index = (mul_1->index) + (mul_2->index);
			pi = add(pi,coefficient,index);
			if(mul_2->next == NULL)break;
			mul_2 = mul_2->next;
		}
			return result;
		}
	mul_2 = mul_2->next;
	while(1){
		while(1){
			coefficient = (mul_1->coefficient) * (mul_2->coefficient);
			index = (mul_1->index) + (mul_2->index);
			pi = add(pi,coefficient,index);
			if(mul_2->next == NULL)break;
			mul_2 = mul_2->next;
		}
		if(mul_1->next == NULL)break;
		mul_1 = mul_1->next;
		mul_2 = multinomial_2;
	}
	return result;
}

void array(struct term *result){
	struct term *pi_1, *pi_2;
	pi_1 = result;
	while(pi_1->next != NULL){
		pi_2 = pi_1->next;
		while(1){
			if(pi_1->index == pi_2->index){
				pi_1->coefficient += pi_2->coefficient;
				pi_2 = delete_pi(pi_2);
			}
			else if(pi_1->index < pi_2->index){
				pi_1->coefficient ^= pi_2->coefficient;
				pi_2->coefficient ^= pi_1->coefficient;
				pi_1->coefficient ^= pi_2->coefficient;
				pi_1->index ^= pi_2->index;
				pi_2->index ^= pi_1->index;
				pi_1->index ^= pi_2->index;
			}
			if(pi_2->next == NULL)break;
			pi_2 = pi_2->next;
		}
		pi_1 = pi_1->next;
	}
	pi_1 = result;
	while(1){
		if(pi_1->coefficient == 0){
			pi_1 = delete_pi(pi_1);
		}
		if(pi_1->next == NULL){
			break;
		}
		pi_1 = pi_1->next;
	}
	return;
}

struct term *delete_pi(struct term *address){
	struct term *previous, *latter;
	if(address->back == NULL){
		latter = address->next;
		latter->back = NULL;
		free(address);
		return latter;
	}
	if(address->next == NULL){
		previous = address->back;
		previous->next = NULL;
		free(address);
		return previous;
	}
	else{
		previous = address->back;
		latter = address->next;
		previous->next = latter;
		latter->back = previous;
		free(address);
		return previous;
	}

};

