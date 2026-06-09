#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    char val; // char
    int cnt; // times
    struct _Node* son[26]; // char - 'a'
} Node;
Node head;
int used = 1;

void trie_add(const char* str)
{
    Node* rt = &head;
    while(*str)
    {
        if(rt->son[*str - 'a'] == NULL)
        {
            rt->son[*str - 'a'] = (Node*) calloc(1, sizeof(Node));
            rt->son[*str - 'a']->val = *str;
        }
        rt = rt->son[*str - 'a'];
        str++;
    }
    rt->cnt++;
}

void trie_print(Node* rt, const char* output_str, char* changable)
{
    *changable = rt->val;
    if(rt->cnt)
    {
        printf("%s %d\n", output_str, rt->cnt);
    }
    for(int i = 0; i < 26; i++)
    {
        if(rt->son[i] == NULL) continue;
        trie_print(rt->son[i], output_str, changable + 1);
    }
    *changable = '\0';
}

void trie_delete(Node* rt, int flag)
{
    for(int i = 0; i < 26; i++)
    {
        if(rt->son[i] == NULL) continue;
        trie_delete(rt->son[i], 1);
    }
    if(flag) free(rt);
}

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#else
    freopen("article.txt", "r", stdin);
#endif
    char read[1000];
    char c;
    int p = 0;
    while((c = getchar()) != EOF)
    {
        if(c < 'A' || c > 'Z' && c < 'a' || c > 'z')
        {
            if(p == 0) continue;
            read[p] = '\0';
            p = 0;
            trie_add(read);
        }
        else
        {
            if(c >= 'A' && c <= 'Z') read[p++] = c + 32;
            else read[p++] = c;
        }
    }
    if(p != 0)
    {
        read[p] = '\0';
        p = 0;
        trie_add(read);
    }
    memset(read, 0, sizeof read);
    trie_print(&head, read+1, read);
    trie_delete(&head, 0);
    return 0;
}
