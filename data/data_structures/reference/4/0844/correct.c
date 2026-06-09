#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define INF 0x3f3f3f3f

typedef struct Node* Node;
struct Node{
    int Size,Priority;
    int Num;
    char* Word;
    Node Left,Right;
};

Node NullNode;
void Initialize();
Node CreateNode(char *Item);

void UpdateSize(Node T);
int MaxNode(Node T);
int MinNode(Node T);

Node Merge(Node L,Node R);
Node FindNode(char *key,Node T);
void SplitInValue(Node T,Node *L,Node *R,char *key);
void SplitInSize(Node T,Node *L,Node *R,char *key);

Node Insert(char *Item,Node T);
// Node Remove(char *Item,Node T);

void MakeEmpty(Node T);
void PrintTreap(Node T);

char *getWord(FILE *in){
    char ch;
    char word[5005];
    int ptr=0;
    while(!isalpha(ch=fgetc(in))){
        if(ch==EOF)return NULL;
    }
    while(isalpha(ch)){
        word[ptr++]=tolower(ch);
        ch=fgetc(in);
    }
    word[ptr]='\0';
    char *s=malloc(sizeof(char)*(strlen(word)+2));
    strcpy(s,word);
    return s;
}

int main(void){
    Initialize();
    Node T=NullNode;

    FILE *in=freopen("article.txt","r",stdin);
    
    char *s;
    while((s=getWord(in))!=NULL){
        Node Tmp=FindNode(s,T);
        if(Tmp==NullNode){
            T=Insert(s,T);
        }
        else{
            Tmp->Num++;
        }
    }
    PrintTreap(T);
    //do something
    fclose(in);

    MakeEmpty(T);
    free(NullNode);
    return 0;
}

void PrintTreap(Node T){
    if(T==NullNode)return;
    PrintTreap(T->Left);
    printf("%s %d\n",T->Word,T->Num);
    PrintTreap(T->Right);
}


Node CreateNode(char *Item){
    Node New=malloc(sizeof(struct Node));
    New->Size=New->Num=1,New->Priority=rand();
    New->Left=New->Right=NullNode;
    New->Word=Item;
    return New;
}

Node FindNode(char *key,Node T){
    Node Ptr=T;
    while(1){
        if(Ptr==NullNode)return NullNode;
        else if(strcmp(key,Ptr->Word)<0){
            Ptr=Ptr->Left;
        }
        else if(strcmp(key,Ptr->Word)>0){
            Ptr=Ptr->Right;
        }
        else{
            return Ptr;
        }
    }
}

void Initialize(){
    NullNode=malloc(sizeof(struct Node));
    NullNode->Left=NullNode->Right=NullNode;
    NullNode->Priority=INF,NullNode->Size=0;
}

void UpdateSize(Node T){
    T->Size=T->Left->Size+T->Right->Size+1;
}

Node Merge(Node L,Node R){
    if(L==NullNode)
        return R;
    else if(R==NullNode)
        return L;
    else if(L->Priority<R->Priority){
        Node Tmp=Merge(L->Right,R);
        L->Right=Tmp;
        UpdateSize(L);
        return L;
    }
    else{
        Node Tmp=Merge(L,R->Left);
        R->Left=Tmp;
        UpdateSize(R);
        return R;
    }
}

void SplitInValue(Node T,Node *L,Node *R,char *key){
    Node nL,nR;
    if(T==NullNode){
        *L=*R=NullNode;
    }
    else if(strcmp(T->Word,key)<=0){
        SplitInValue(T->Right,&nL,&nR,key);
        T->Right=nL;
        UpdateSize(T);
        *L=T;*R=nR;
    }
    else{
        SplitInValue(T->Left,&nL,&nR,key);
        T->Left=nR;
        UpdateSize(T);
        *R=T;*L=nL;
    }
}

Node Insert(char *Item,Node T){
    Node New=CreateNode(Item);

    Node L,R;
    SplitInValue(T,&L,&R,Item);
    return Merge(Merge(L,New),R); 
}

void MakeEmpty(Node T){
    if(T->Left!=NullNode)MakeEmpty(T->Left);
    if(T->Right!=NullNode)MakeEmpty(T->Right);
    free(T);
}




