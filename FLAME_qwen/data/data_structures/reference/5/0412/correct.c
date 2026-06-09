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
void multiply(List* a, List* b, List* ans);
void print_value(const Value* value);
void print_list(List* list);
char* get_int(char* buffer, int* num);
void init_list(List* list, char* buffer);

int main()
{
	List a, b, ans;
	char buffer[BUFFER_SIZE];

	list_init(&a);
	list_init(&b);
	list_init(&ans);

	scanf("%[^\n]", buffer);
	getchar();
	init_list(&a, buffer);

	scanf("%[^\n]", buffer);
	getchar();
	init_list(&b, buffer);

	multiply(&a, &b, &ans);
	print_list(&ans);

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

	Node* it;
	int ret;
	for (it = list->head; it != list->tail; it = it->next)
	{
		ret = value_compare(&it->val, &value);
		if (ret < 0)
			break;
		else if (ret == 0)
		{
			it->val.coef += value.coef;
			return list;
		}

	}
	Node* new_node = node_set_value(node_create(), value);
	if (it == list->head)
	{
		new_node->prev = NULL;
		new_node->next = list->head;
		list->head->prev = new_node;
		list->head = new_node;
	}
	else
	{
		new_node->prev = it->prev;
		new_node->next = it;
		it->prev->next = new_node;
		it->prev = new_node;
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

	Node* it = list->tail->prev;
	if (it == list->head)
	{
		new_node->prev = NULL;
		new_node->next = list->head;
		list->head->prev = new_node;
		list->head = new_node;
	}
	else
	{
		new_node->prev = it->prev;
		new_node->next = it;
		it->prev->next = new_node;
		it->prev = new_node;
	}

	list->length++;

	return list;
}

Node* list_find(List* list, Value value)
{
	for (Node* it = list->head; it != list->tail; it = it->next)
	{
		if (value_compare(&value, &it->val) == 0)
			return it;
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
	Node* it = list->tail;

	do
	{
		it = it->prev;
		node_destroy(list->tail);
		list->tail = it;
	} while (it != NULL);
}


// custom methods
int value_compare(const Value* v1, const Value* v2)
{
	return v1->power - v2->power;
}

void multiply(List* a, List* b, List* ans)
{
	Value product;

	for (Node* i = a->head; i != a->tail; i = i->next)
	{
		for (Node* j = b->head; j != b->tail; j = j->next)
		{
			product.coef = i->val.coef * j->val.coef;
			product.power = i->val.power + j->val.power;
			list_insert(ans, product);
		}
	}
}

void print_value(const Value* value)
{
	printf("%d %d ", value->coef, value->power);
}

void print_list(List* list)
{
	for (Node* it = list->head; it != list->tail; it = it->next)
		print_value(&it->val);
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


