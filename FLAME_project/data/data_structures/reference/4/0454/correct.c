#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int count;
    char word[50];
    struct node * next;
};

typedef struct node node;
void bubbleSort(node*list){
    node*cur = list;
    node*tail = NULL;
    if(cur == NULL || cur->next == NULL)
    return;

    while(cur != tail){
        while(cur->next != tail){
            if(strcmp(cur->word,cur->next->word) > 0){
                char tmp_word[50];
                memset(tmp_word,0,50);
                strcpy(tmp_word,cur->word);
                strcpy(cur->word,cur->next->word);
                strcpy(cur->next->word,tmp_word);
                int tmp_count;
                tmp_count = cur->count;
                cur->count = cur->next->count;
                cur->next->count =  tmp_count;
            }
            cur = cur -> next;
        }
        tail = cur;
        cur = list;
    }    
}


int main(){
    FILE * fp;
    fp = fopen("article.txt","r");
    char ch;

    node * ans = malloc(sizeof(node));
    ans ->next = NULL;
    node * pos = ans;
    while((ch = fgetc(fp)) != EOF){
        
        if(isalpha(ch)){
            int flag = 1;
            char iword[50];
            for(int i =0;isalpha(ch);i++){
                iword[i] = tolower(ch);
                ch = fgetc(fp);
            }

            node* p = ans->next;
            while(p!=NULL){
                if(strcmp(iword,p->word) == 0){
                    (p->count)++;
                    flag = 0; break;
                }
                p = p->next;
            }
            if(flag){
                node* tmp = malloc(sizeof(node));
                tmp ->count = 1;
                strcpy(tmp->word,iword);
                tmp->next = pos -> next;
                pos->next =tmp;
                pos = tmp;
            }

            if(ch == EOF)
            break;
             memset(iword,0,50);
        }
       
    }


    ans = ans ->next;
    bubbleSort(ans);

    while(ans != NULL){
        printf("%s %d\n",ans->word,ans->count);
        ans = ans->next;
    }

    fclose(fp);
    return 0;
}

