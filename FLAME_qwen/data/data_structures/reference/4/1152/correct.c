#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long

typedef struct node{
    char word[100];
    int num;
    struct node *r;
}list;

int cmp(char *a, int alen, char *b, int blen){//is front longer/bigger?1 0 -1
    for(int i = 1; i <= alen && i <= blen; ++i){
        if(a[i] == b[i])continue;
        if(a[i] > b[i]) return 1;
        else return -1;
    }
    if(alen > blen) return 1;
    if(alen == blen) return 0;
    return -1; 
}

void cre_l(list *head, char *c){
    list *t = (list*)malloc(sizeof(list));
    strcpy(t->word,c);
    t->num = 1;
/*    if(head->r == NULL){
        list *it = head;
        t->r = NULL;
        head->r = t;
        return;
    }
*/    list *it;
    for(it = head; it->r != NULL;  it = it->r){//creat before it->r if it->r is larger
        int flag = cmp(it->r->word, strlen(it->r->word+1), t->word, strlen(t->word+1));
        if(cmp(it->r->word, strlen(it->r->word+1), t->word, strlen(t->word+1)) == -1){//t is smaller than it->r 
            continue;
        }
        if(cmp(it->r->word, strlen(it->r->word+1), t->word, strlen(t->word+1)) == 0){//t == it->r
            free(t);
            it->r->num++;
            return;
        }
        //t is larger than it->r
        //put t behind it;
        t->r = it->r;
        it->r = t;
        return;
    }
    //add in tail
    t->r = it->r;
    it->r = t;
    return;
}

void print(list *head){
    for(list *it = head; it->r != NULL; it = it->r){
        printf("%s %d\n",it->r->word+1,it->r->num);
    }
    return;
}

int main(){
    freopen("article.txt","r",stdin);//article.txt
//    freopen("w.txt","w",stdout);
    char word[20];
    memset(word,'\0',sizeof(word));
    int cnt = 1;
    list *head = (list*)malloc(sizeof(list));
    head->r = NULL;
    while((word[0] = getchar()) != EOF){
        if(word[0] >='a' && word[0] <= 'z'){
            word[cnt] = word[0];
            ++cnt;
            continue;
        }
        if(word[0] >='A' && word[0] <= 'Z'){
            word[0] += 'a'-'A';
            word[cnt] = word[0];
            ++cnt;
            continue;
        }
        if(cnt > 1 && word[cnt-1] >= 'a' && word[cnt-1] <= 'z' && ( !(word[0] >='a' && word[0] <= 'z') || !(word[0] >='A' && word[0] <= 'Z'))){
            cnt = 1;
            cre_l(head, word);
            memset(word,'\0',sizeof(word));
            continue;
        }
    }
    print(head);
    return 0;
}
