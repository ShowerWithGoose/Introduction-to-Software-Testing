#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 200

typedef struct tagValue
{
	int coef;
	int power;
} Value;

typedef struct tagNode
{
	Value val;
	struct tagNode* prev;
	struct tagNode* next;
} Node;

typedef struct tagList
{
	Node* head;
	Node* tail;
	int length;
} List;

// node operations
void node_init(Node* node);
Node* node_create();
Node* node_set_value(Node* node, Value val);
void node_destroy(Node* node);

// list operations
List* list_init(List* list);
List* list_append(List* list, Value value);
List* list_insert(List* list, Value value);
Node* list_find(List* list, Value value);
Node* list_erase(List* list, Node* node);
void list_destroy(List* list);


/********************************************************************
** Custom methods.
*/
int value_compare(const Value* v1, const Value* v2);
void multiply(List* poly1, List* poly2, List* result);
void print_value(const Value* value);
void print_list(List* list);
char* get_int(char* buffer, int* num);
void init_list(List* list, char* buffer);

int main()
{
	List poly1, poly2, result;
	char buffer[BUFFER_SIZE];

	list_init(&poly1);
	list_init(&poly2);
	list_init(&result);

	scanf("%[^\n]", buffer);
	getchar();
	init_list(&poly1, buffer);

	scanf("%[^\n]", buffer);
	getchar();
	init_list(&poly2, buffer);

	multiply(&poly1, &poly2, &result);
	print_list(&result);

	return 0;
}

// node operations
void node_init(Node* node)
{
	node->prev = node->next = NULL;
}

Node* node_create()
{
	return (Node*)malloc(sizeof(Node));
}

Node* node_set_value(Node* node, Value value)
{
	node->val = value;

	return node;
}

void node_destroy(Node* node)
{
	free(node);
}

// list operations
List* list_init(List* list)
{
	list->head = list->tail = node_create();
	list->length = 0;

	return list;
}

List* list_insert(List* list, Value value)
{
	if (list->length == 0)
	{
		Node* new_node = node_set_value(node_create(), value);

		list->head = new_node;

		list->head->prev = NULL;
		list->head->next = list->tail;
		list->tail->prev = list->head;
		list->tail->next = NULL;

		list->length++;

		return list;
	}

	Node* tail;
	int ret;
	for (tail = list->head; tail != list->tail; tail = tail->next)
	{
		ret = value_compare(&tail->val, &value);
		if (ret < 0)
			break;
		else if (ret == 0)
		{
			tail->val.coef += value.coef;
			return list;
		}

	}
	Node* new_node = node_set_value(node_create(), value);
	if (tail == list->head)
	{
		new_node->prev = NULL;
		new_node->next = list->head;
		list->head->prev = new_node;
		list->head = new_node;
	}
	else
	{
		new_node->prev = tail->prev;
		new_node->next = tail;
		tail->prev->next = new_node;
		tail->prev = new_node;
	}

	list->length++;

	return list;
}

List* list_append(List* list, Value value)
{
	Node* new_node = node_set_value(node_create(), value);

	if (list->length == 0)
	{
		list->head = new_node;

		list->head->prev = NULL;
		list->head->next = list->tail;
		list->tail->prev = list->head;
		list->tail->next = NULL;

		list->length++;

		return list;
	}

	Node* tail = list->tail->prev;
	if (tail == list->head)
	{
		new_node->prev = NULL;
		new_node->next = list->head;
		list->head->prev = new_node;
		list->head = new_node;
	}
	else
	{
		new_node->prev = tail->prev;
		new_node->next = tail;
		tail->prev->next = new_node;
		tail->prev = new_node;
	}

	list->length++;

	return list;
}

Node* list_find(List* list, Value value)
{
	for (Node* tail = list->head; tail != list->tail; tail = tail->next)
	{
		if (value_compare(&value, &tail->val) == 0)
			return tail;
	}

	return NULL;
}

Node* list_erase(List* list, Node* node)
{
	if (list->length == 0)
		return list->tail;

	// This node is the list.
	Node* rv = node->next;

	if (node == list->head)
	{
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	node_destroy(node);
	list->length--;

	return rv;
}

void list_destroy(List* list)
{
	Node* tail = list->tail;

	do
	{
		tail = tail->prev;
		node_destroy(list->tail);
		list->tail = tail;
	} while (tail != NULL);
}


// custom methods
int value_compare(const Value* v1, const Value* v2)
{
	return v1->power - v2->power;
}

void multiply(List* poly1, List* poly2, List* result)
{
	Value product;

	for (Node* p1 = poly1->head; p1 != poly1->tail; p1 = p1->next)
	{
		for (Node* p2 = poly2->head; p2 != poly2->tail; p2 = p2->next)
		{
			product.coef = p1->val.coef * p2->val.coef;
			product.power = p1->val.power + p2->val.power;
			list_insert(result, product);
		}
	}
}

void print_value(const Value* value)
{
	printf("%d %d ", value->coef, value->power);
}

void print_list(List* list)
{
	for (Node* tail = list->head; tail != list->tail; tail = tail->next)
		print_value(&tail->val);
	putchar('\n');
}

char* get_int(char* buffer, int* num)
{
	int negative = 0;

	if (*buffer == '\0')
		return NULL;

	while (!isdigit(*buffer))
	{
		if (*buffer == '-')
			negative = !negative;
		buffer++;
		if (*buffer == '\0')
			return NULL;
	}
	*num = 0;
	while (isdigit(*buffer))
	{
		*num = (*num) * 10 + (*buffer) - '0';
		buffer++;
		if (*buffer == '\0')
			break;
	}

	return buffer;
}

void init_list(List* list, char* buffer)
{
	Value value;

	while (1)
	{
		buffer = get_int(buffer, &value.coef);
		if (buffer == NULL)
			break;
		buffer = get_int(buffer, &value.power);
		if (buffer == NULL)
			break;

		list_insert(list, value);
	}
}


