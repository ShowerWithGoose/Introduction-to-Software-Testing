#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1024
#define	MAX(A,B)   ((A)>(B)?(A):(B))
#define	MIN(A,B)   ((A)<(B)?(A):(B))
#define MAX_WORDS 100
#define MAX_WORD_LEN 50
struct link {
int xisu;
int zhisu;
struct link *next;
};

int extractWords(const char* str, char words[MAX_WORDS][MAX_WORD_LEN]) {
    int i = 0, j = 0, k = 0;
    int num=0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {num++;
            words[j][k] = '\0'; // 结束当前单词
            j++; // 移动到下一个单词
            k = 0; // 重置单词索引
        } else {
            words[j][k] = str[i]; // 将字符存入当前单词中
            k++; // 移动到单词的下一个字符
        }
        i++; // 移动到字符串的下一个字符
    }
    num++;
    words[j][k] = '\0'; // 结束最后一个单词
    return num;
}


// 交换节点数据
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}




// 对链表进行降序排列
void bubbleSortLinkedList(struct link *head) {
    struct link * current;
    struct link * nextNode = NULL;
    int swapped;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;

        while (current->next != nextNode) {
            if (current->zhisu < current->next->zhisu) {
                swap(&current->zhisu, &current->next->zhisu);
                swap(&current->xisu, &current->next->xisu);
                swapped = 1;
            }
            current = current->next;
        }
        nextNode = current;
    } while (swapped);
}




int main()
{
	char str1[100];
	char str2[100];
	gets(str1);
	gets(str2);
	char words1[MAX_WORDS][MAX_WORD_LEN];
	
	
	
	int num1=extractWords(str1, words1);
	int i;
	struct link *first1=NULL, *p,*q;
	
	for(i=1; i<=(num1/2); i++){
	q = (struct link *)malloc(sizeof(struct link));
	q->xisu =  atoi(words1[2*i-2]); 
	q->zhisu=  atoi(words1[2*i-1]); 
	q->next = NULL;
	if(first1 == NULL)
	    first1 = p = q;
	else {
	    p->next = q;
	    p = p->next;    
	}
	}
	//printf("%d\n",num1);
	
	
		char words2[MAX_WORDS][MAX_WORD_LEN];
		int num2=extractWords(str2, words2);
		struct link *first2=NULL	;
	for(i=1; i<=(num2/2); i++){
	q = (struct link *)malloc(sizeof(struct link));
	q->xisu =  atoi(words2[2*i-2]); 
	q->zhisu=  atoi(words2[2*i-1]); 
	q->next = NULL;
	if(first2 == NULL)
	    first2 = p = q;
	else {
	    p->next = q;
	    p = p->next;    
	}
	}
	
	
//	printf("%d %d",num1,num2);
	int j;
	struct link* first=NULL	;
	for(i=1;i<=num1/2;i++)
	 {
	 
	 for(j=1;j<=num2/2;j++)
{
		q = (struct link *)malloc(sizeof(struct link));
	q->xisu =  atoi(words1[2*i-2])*atoi(words2[2*j-2]); 
	q->zhisu=  atoi(words1[2*i-1])+atoi(words2[2*j-1]); 
	q->next = NULL;
	if(first == NULL)
	    first = p = q;
	else {
	    p->next = q;
	    p = p->next;    
     	}	 
		 }	 	

	}
	 	
		bubbleSortLinkedList(first);
		
	 struct link *current=first;
	while(current->next!=NULL)
	{
		if(current->zhisu==current->next->zhisu)
		{current->xisu+=current->next->xisu;
		p=current;
		q = p->next;
        p->next = p->next->next;
        free(q);
		}
		current=current->next;
	}
	
	 current=first;
		while(current->next!=NULL)
	{
		if(current->zhisu==current->next->zhisu)
		{current->xisu+=current->next->xisu;
		p=current;
		q = p->next;
        p->next = p->next->next;
        free(q);
		}
		current=current->next;
	}
	
	
	
	  current=first;
	  while (current != NULL) {
        printf("%d %d ", current->xisu,current->zhisu);
        // 在这里可以引用当前节点的值或其他属性
        // 例如：int value = current->data;
        current = current->next;
    }
	
	
	
	
	
	return 0;
	
}

