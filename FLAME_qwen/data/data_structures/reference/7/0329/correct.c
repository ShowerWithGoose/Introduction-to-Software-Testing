#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int input() {
    int x = 0; bool f = 1; char ch = getchar();
    for (;!isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return f? x: -x;
}

typedef struct node {
    int val, size;
    struct node *ch[2];
} node;

node* new_node(const int val) {
    node *tmp = (node*)malloc(sizeof(node));
    tmp->val = val; tmp->size = 1;
    tmp->ch[0] = tmp->ch[1] = NULL;
    return tmp;
}

void _update(node *u) {
    u->size = 1;
    if (u->ch[0]) u->size += u->ch[0]->size;
    if (u->ch[1]) u->size += u->ch[1]->size;
}

void _insert(node **u, const int val) {
    if (!*u) {*u = new_node(val); return;}
    bool id = (*u)->val <= val;
    _insert(&(*u)->ch[id], val); _update(*u);
}

typedef struct tree {
    int size;
    struct node *root;
} tree; tree q;

void push(tree *q, const int val) {_insert(&q->root, val);}

void dfs(node *u, int d) {
    if (u->size == 1) {printf("%d %d\n", u->val, d); return;}
    if (u->ch[0]) dfs(u->ch[0], d + 1);
    if (u->ch[1]) dfs(u->ch[1], d + 1);
}

int main() {
    int n = input();
    for (int i = 1; i <= n; i++) push(&q, input());
    dfs(q.root, 1);
    return 0;
}

