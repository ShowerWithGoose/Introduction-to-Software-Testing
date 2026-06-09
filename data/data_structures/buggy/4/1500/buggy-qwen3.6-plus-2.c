#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct wor wor;
struct wor {
    char item[20];
    int fre;
    wor* next;
};

int main() {
    FILE* fp1;
    fp1 = fopen("article.txt", "r");
    wor* fir = NULL, * cur = NULL, * pre = NULL, * prepre = NULL;
    int i = 0,n=0,j=0,m=0;
    while(1){
    char ch[300] = { '0' };
    if (fgets(ch, 200, fp1) == NULL) {
        break;
    };
    n = strlen(ch);
    for (i = 0; i < n; i++) {
        if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z')) {
            char ch2[20] = { '0' };
            cur = (wor*)malloc(sizeof(wor));
            m++;
            if (fir == NULL) {
                fir = cur;
            }
            if (pre != NULL) {
                pre->next = cur;
            }
            j = 0;
            while (1) {
                ch[i] = tolower(ch[i]);
                ch2[j] = ch[i];
                i++;
                j++;
                if (ch[i] < 'A' || (ch[i] > 'Z' && ch[i] < 'a') || ch[i]>'z') {
                    break;
                }
            }
            strcpy(cur->item, ch2); // @@ 'ch2' is not explicitly null-terminated after the loop, which may cause 'strcpy' to copy garbage or read out of bounds. 'ch2[j] = '\0';' should be added before this line.
            cur->fre = 1;
            pre = cur;
            cur->next = NULL;
        }
    }
    }last = cur; // @@ 'last' is undeclared, causing a compilation error. It should be removed or declared as 'wor* last = cur;'.
    cur = fir;    
    while(1){
    prepre = NULL;
    cur = fir->next; // @@ If 'fir' is NULL (empty file), dereferencing it causes a segmentation fault. Should check 'if (fir == NULL) break;' before this line.
    pre = fir;    
    n = 0;
    for (i = 0; i < m-1 ; i++) {
        if (strcmp(pre->item,cur->item)>0) {
            n = 1;
            if (prepre == NULL) {
                pre->next = cur->next;
                cur->next = pre;
                prepre = cur;
                fir = cur;
                cur = pre->next;

            }
            if (prepre != NULL) {              // @@ This should be 'else if' to prevent executing both swap blocks sequentially when 'prepre' becomes non-NULL after the first block.
                prepre->next = cur;
                pre->next = cur->next;
                cur->next = pre;
                prepre = cur;
                cur = pre->next;
                
            }
        }
        else {

            prepre = pre;
            pre = cur;
            cur = cur->next;
        }
        if (cur == NULL) {
            break;
        }
    }if (n == 0) {
        break;
      }
    }
    cur = fir->next;
    pre = fir;
    while (cur != NULL) {
        if (strcmp(pre->item, cur->item) == 0) {
            pre->next = cur->next;
            pre->fre++;
            cur = cur->next;
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
    cur = fir;
    while (cur!=NULL) {
        printf("%s %d\n", cur->item,cur->fre);
        cur = cur->next;
    }
    return 0;
    
    
    
}