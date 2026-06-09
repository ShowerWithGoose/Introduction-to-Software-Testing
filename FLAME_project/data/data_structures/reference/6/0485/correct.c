//just do it
#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct s {
	int data;
	struct s* next;

}links;
int num = 0;
links* inputs(links* head, int data);
links* outputs(links* head);
int main()
{
	//input num
	int x, data;
	links* head;
	//make stack
	head = (links*)malloc(sizeof(links));	//headnode ,need to point the top
	head->next = NULL;

	while (scanf("%d", &x), x != -1)
	{
		if (x != 1 && x != 0) {
			//protect
			printf("Wrong input!");
			break;
		}
		if (1 == x) {
			//input
			scanf("%d", &data);
			head = inputs(head, data);
		}
		else if (0 == x) {
			//output;
			head = outputs(head);
		}
	}
	return 0;
}
links* inputs(links* head, int data)
{
	num++;
	links * newe;
	if (num <= max) {
		//usual
		newe = (links*)malloc(sizeof(links));
		newe->data = data;
		newe->next = head->next;
		head->next = newe;
	}
	else {
		//exceptional case
		printf("error ");
	}

	return head;
}
links* outputs(links* head)
{
	num--;
	links* dec, * p;

	dec = head->next;
	if (dec != NULL) {
		p = head;
		p->next = dec->next;
		printf("%d ", dec->data);
		free(dec);
	}
	else {
		//exceptional case
		printf("error ");
	}
	return head;
}

