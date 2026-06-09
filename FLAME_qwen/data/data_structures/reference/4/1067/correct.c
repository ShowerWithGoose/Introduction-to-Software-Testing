#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define maxn 100
char wordcache[5000][1000];
int N;
typedef struct TreeNode *Tree;// Tree is a pointer
struct TreeNode
{
    char word[100];
    Tree Left, Right;
    int cnt;
};

Tree NewTreeNode(char *Word)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));//not sizeof(Tree)
    strcpy(T -> word, Word);
    T -> cnt = 1;
    T -> Left = T -> Right = NULL;
    return T;
}

/*
int Comp(char *a, char *b)
{
    int la = strlen(a), lb = strlen(b);
    int i = 0;
    for(; i < la && i < lb; i ++)
    {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }
    if(i == la - 1 && i != lb) return -1;
    if(i == lb - 1 && i != la) return 1;
    return 0;
}
*/
Tree InsertTree(Tree T, char *Word)//what about linked list? what about searching?
{
    if(T == NULL) 
        T = NewTreeNode(Word);
    //no need to claim a new Tree t, T is always the root
    //the value of a null pointer might not be 0?                         
    else
    {
        if(strcmp(Word, T -> word) > 0)//what if V == T -> v?
            T -> Right = InsertTree(T -> Right, Word);
        else if(strcmp(Word, T -> word) < 0)
            T -> Left = InsertTree(T -> Left, Word);
        else T -> cnt ++;
    }//T left or right is the sub-root
    return T;
}

Tree MakeTree(char wordcache[][1000], int N)
{
    Tree T = NULL;
    if(isalpha(wordcache[N][0]))
        T = NewTreeNode(&wordcache[N][0]);//double safe
    while (N --)
    {
        if(isalpha(wordcache[N][0]))
            T = InsertTree(T, &wordcache[N][0]);
    }   
    return T;//return the root
}

void HeadTraverse(Tree tmp)
{
    if(tmp == NULL)
        return;
    HeadTraverse(tmp -> Left);
    printf("%s %d\n", tmp -> word, tmp -> cnt);
     HeadTraverse(tmp -> Right);
}

int Input(FILE *in)
{
    int i = 0, j = 0;
    while((wordcache[i][j] = tolower(fgetc(in))) != EOF)
    {
        if(isalpha(wordcache[i][j]))
            j ++;
        else //space remains
        {
            wordcache[i][j] = 0;
            i ++;
            j = 0;
        }
    }
    wordcache[i][j] = 0;
    return i;
}
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    N = Input(in);
    //into cache 2d array
    //tolower
    /*
    for(int i = 0; i < N; i ++)
        puts(wordcache[i]);
    printf("%d", N);
    */
    Tree root = MakeTree(wordcache, N);
    //judge bigger/smaller, if same cnt++
    HeadTraverse(root);
    //traverse
    fclose(in);
    return 0;
}

