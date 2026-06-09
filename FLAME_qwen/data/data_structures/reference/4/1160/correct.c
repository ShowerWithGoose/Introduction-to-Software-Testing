#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isupper(char a)
{
	return (a >= 65 && a <= 90);
}
int islower(char a)
{
	return (a >= 97 && a <= 122);
}

typedef struct node{
	char word[20];
	int times;
	struct node *link;
} LNode;

int word_count = 0;

LNode *CREATE(int n) // Create a link list with a head node which just hold the first place.
{
	if (n < 0)
	{
		printf("LNode CREAT Error: number of nodes is too small.");
		return NULL;
	}
	LNode *head, *node, *tail;
	head = (LNode*)malloc(sizeof(LNode));
	tail = head;
	for (int i = 0; i < n; i++)
	{
		node = (LNode*)malloc(sizeof(LNode));
		node->times = 0;
		tail->link = node;
		tail = node;
	}
	tail->link = NULL;
	return head;
}

LNode *CREATE_NODE(char new_word[])
{
	LNode *new_node = (LNode*)malloc(sizeof(LNode));
	int len = strlen(new_word);
	for (int i = 0; i <= len; i++)
	{
		new_node->word[i] = new_word[i];
	}
	new_node->times = 1;
	new_node->link = NULL;
	return new_node;
}

void ADD_NODE_BETWEEN(LNode *list, char new_word[])
{
	LNode *step = list->link;
	LNode *follow = list;
	for (int i = 0; step != NULL && strcmp(step->word, new_word) <= 0; i++)
	{
		step = step->link;
		follow = follow->link;
	}
	if (strcmp(follow->word, new_word) == 0)
	{
		follow->times++;
	}
	else
	{
		LNode *new_node = CREATE_NODE(new_word);
		follow->link = new_node;
		new_node->link = step;
		word_count++;
	}
}

int main()
{
	FILE *IN;
	IN = fopen("article.txt","r");
	LNode *word_list = CREATE(0);
	char input[1001];
	while (fgets(input, 1000, IN)!=NULL)
	{
		int input_len = strlen(input);
		int i = 0;
		while (i < input_len)
		{
			char word[20];
			int j = 0;
			while (! (isupper(input[i]) || islower(input[i])) && i < input_len)
			{
				i++;
			}
			while (isupper(input[i]) || islower(input[i]))
			{
				if (isupper(input[i]))
				{
					word[j] = input[i] + 32;
				}
				else
				{
					word[j] = input[i];
				}
				i++;
				j++;
			}
			word[j] = 0;
			ADD_NODE_BETWEEN(word_list, word);
		}
	}
	LNode *op = word_list->link;
	for (int i = 0; i < word_count; i++)
	{
		printf("%s %d\n", op->word, op->times);
		op = op->link;
	}
	

	return 0;
}


