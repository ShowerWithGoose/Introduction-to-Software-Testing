#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 200

const char FILE_IN[] = "article.txt";

typedef struct tagValue
{
	char* word;
	int count;
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

// value operations
int value_compare(const Value* v1, const Value* v2);
Value* value_merge(Value* dest, Value* src);
void value_destroy(Value* value);

// node operations
void node_init(Node* node);
Node* node_create();
Node* node_set_value(Node* node, Value val);
void node_destroy(Node* node);

// list operations
List* list_init(List* list);
List* list_append(List* list, Value value);
List* list_insert(List* list, Value value);
List* list_merge_insert(List* list, Value value);
Node* list_find(List* list, Value value);
Node* list_erase(List* list, Node* node);
void list_destroy(List* list);


/********************************************************************
** Custom methods.
*/
Value get_value(char* word);
void print_value(const Value* value);
char* get_word(FILE* fp, char* word);
void print_list(List* list);

int main()
{
	FILE* fp;
	List list;
	char buffer[BUFFER_SIZE];

	list_init(&list);

	fp = fopen(FILE_IN, "r");
	while (get_word(fp, buffer) != NULL)
		list_merge_insert(&list, get_value(buffer));
	fclose(fp);

	print_list(&list);
	
	list_destroy(&list);

	return 0;
}

// value operations
int value_compare(const Value* v1, const Value* v2)
{
	return -strcmp(v1->word, v2->word);
}

Value* value_merge(Value* dest, Value* src)
{
	dest->count += src->count;
	value_destroy(src);
}

void value_destroy(Value* value)
{
	free(value->word);
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

	Node* it;
	for (it = list->head; it != list->tail; it = it->next)
	{
		if (value_compare(&it->val, &value) < 0)
			break;
	}
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

List* list_merge_insert(List* list, Value value)
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

	Node* new_node = node_set_value(node_create(), value);
	Node* it;
	int ret;
	for (it = list->head; it != list->tail; it = it->next)
	{
		ret = value_compare(&it->val, &value);
		if (ret < 0)
			break;
		else if (ret == 0)
		{
			value_merge(&it->val, &value);
			return list;
		}

	}
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


/********************************************************************
** Custom methods.
*/
Value get_value(char* word)
{
	Value rv;

	rv.word = (char*)malloc(strlen(word) + 1);
	strcpy(rv.word, word);
	rv.count = 1;

	return rv;
}

void print_value(const Value* value)
{
	printf("%s %d\n", value->word, value->count);
}


char* get_word(FILE* fp, char* word)
{
	char ch;

	ch = getc(fp);
	if (ch == EOF)
		return NULL;
	while (!isalpha(ch))
	{
		ch = getc(fp);
		if (ch == EOF)
			return NULL;
	}

	char* p = word;
	while (isalpha(ch))
	{
		*p = tolower(ch);
		p++;
		ch = getc(fp);
		if (ch == EOF)
		{
			*p = '\0';
			return word;
		}
	}
	*p = '\0';
	return word;
}

void print_list(List* list)
{
	for (Node* it = list->head; it != list->tail; it = it->next)
		print_value(&it->val);
}

