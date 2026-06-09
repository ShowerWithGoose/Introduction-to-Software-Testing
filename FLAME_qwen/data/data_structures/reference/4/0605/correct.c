#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct word{
    char str[100];
    int num;
    struct word* next;
} WORD;

void print(WORD* head);

int main()
{     FILE *fp = fopen("article.txt","r");
if(fp==NULL) printf("NO\n");
      WORD *head = (struct word*)malloc(sizeof(struct word));
      WORD *p = (struct word*)malloc(sizeof(struct word));
      head->next = NULL;
       char c;
       char temp[100];
       int cnt = 0;
       while((c = fgetc(fp))!=EOF){
           if(isalpha(c)){
               temp[cnt++] = tolower(c);
           }
           else{
               if(cnt!=0){
                   temp[cnt] = '\0';
                    if(head->next==NULL){
                        WORD *new = (struct word*)malloc(sizeof(WORD));
                       strcpy(new->str,temp);
                       new->next = NULL;
                       new->num = 1;
                      head->next = new;
                      
                  }
                  else {
                      for(p = head;p->next;p = p->next){
                          if(strcmp(p->next->str,temp)>0){
                              WORD *new = (struct word*)malloc(sizeof(struct word));
                              strcpy(new->str,temp);
                              new->num = 1;
                              new->next = p->next;
                              p->next = new;
                              break;
                          }
                         else if(strcmp(p->next->str,temp)==0){
                             p->next->num++;
                             break;
                         }
                      }
                      if(p->next==NULL){
                              WORD *new = (struct word*)malloc(sizeof(struct word));
                              strcpy(new->str,temp);
                              new->num = 1;
                              new->next = NULL;
                              p->next = new;
                      }
                  }
                  cnt = 0;
               }
           }
       }
       fclose(fp);
       print(head);
       return 0;
}

void print(WORD* head)
{   WORD *p = head->next;
for(p;p;p = p->next){
    printf("%s %d\n",p->str,p->num);
}

}


