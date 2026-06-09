#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
    int count;
    char word[26];
    struct node *lchild, *rchild;  //建立节点的时候 每个节点有左孩子和右孩子 
}BTNode, *BTREE; 
int times = 0;
int get_word(char *temp_word, FILE *in); // @@ This function is declared but never used; also expects a FILE* but program does not open any file.
BTREE insert(BTREE T, char temp_word[]); // @@ The insert function is never called; the program does not read words from a file.
void inorder(BTREE root); // @@ inorder is never called; the program does not traverse any tree.
int main()
{
    char a[1000];
    int i=0;
    gets(a); // @@ gets is unsafe and deprecated; but more importantly, this program is supposed to read graph edges and a vertex to delete, not a single string.
    while(!isdigit(a[i]))
    i++; 
    if(a[i]=='3')    {
        printf("0 1 2\n\
0 1 2\n\
0 2\n\
0 2"); // @@ The program outputs hardcoded sequences for specific vertex counts instead of computing DFS/BFS. This does not solve the general problem.
    }
    else if(a[i]=='4'){
        printf("0 1 2 3\n\
0 1 2 3\n\
0 1 3\n\
0 1 3"); // @@ Same issue: hardcoded output.
    }    
    else if(a[i]=='9'){
        printf("0 1 2 3 4 6 5 7 8\n\
0 1 5 2 6 3 7 4 8\n\
0 5 6 2 3 4 7 8\n\
0 5 6 2 7 3 8 4"); // @@ Hardcoded.
    }    
    else if(a[i]=='1'){
        printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n\
0 8 9 12 2 1 7 4 10 3 5 11 6\n\
0 9 1 7 3 4 2 5 6 11 10 12\n\
0 9 12 1 7 10 3 5 11 4 6 2"); // @@ Hardcoded.
    }    
    else if(a[i]=='2'){
        printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n\
0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n\
0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n\
0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16"); // @@ Hardcoded.
    }    
 return 0;
}

int get_word(char *temp_word, FILE *in) // @@ This function is defined but never used.
{
    int i = 0; 
    char temp = '0';
    temp = fgetc(in);
    while( !isalpha(temp) )
    {
        temp = fgetc(in);
        if(temp==EOF)
        return 1;
    }
 
    while(isalpha(temp) && !isspace(temp) )    
    {
        temp = tolower(temp);
        temp_word[i] = temp;
        i++;
        temp = fgetc(in);
    }
 
    return 0;
}
 
 
BTREE insert(BTREE p, char temp_word[]) // @@ Missing #include <stdlib.h> for malloc.
{
    int cond;
    if(p == NULL)
    {
        p = (BTREE)malloc(sizeof(BTNode)); // @@ malloc used without including <stdlib.h>. Also this insert is never called.
        strcpy(p->word, temp_word);
        p->count = 1;
        p->lchild = p->rchild = NULL;
    }
 
    else if( (cond  = strcmp(temp_word, p->word)) == 0)
    {
        p->count++;
    }
    else if( cond<0 )
    {
        p->lchild = insert(p->lchild, temp_word);
    }
    else 
    {
        p->rchild = insert(p->rchild, temp_word);
    }
    return (p);
}
 
void inorder(BTREE T)  /*using inorder*/ // @@ This function is never called.
{
     if(T!= NULL)
    {    
        inorder(T->lchild);
        if( strlen(T->word) >0 )
        printf("%s %d\n", T->word, T->count);
        inorder(T->rchild);
    }
}