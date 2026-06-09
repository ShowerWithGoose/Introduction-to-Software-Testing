#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>
//#include<stack>  
//using namespace std;  

typedef struct _node1{
    int number;
    struct _node1* next;
}Node1;

typedef struct _node2{
    char f;
    struct _node2* next;
}Node2;

const int MAX = 10000; // @@ [In C, 'const int' is not a compile-time constant usable for array sizes at file scope; use #define instead]
char a[MAX], b[MAX]; // @@ [Because MAX is defined with 'const int', this causes a "variably modified at file scope" error in C]

Node1* createStack1();
Node2* createStack2();
void pushS1(Node1*,int);
void pushS2(Node2*,char);
int topS1(Node1*);
char topS2(Node2*);
void popS1(Node1*);
void popS2(Node2*);
bool emptyS1(Node1*); // @@ [Type 'bool' is not recognized without including <stdbool.h>]
bool emptyS2(Node2*); // @@ [Type 'bool' is not recognized without including <stdbool.h>]
int sizeS1(Node1*);
int sizeS2(Node2*);
void back();
void aes(); 

int main(){  
    back();
    aes();
    return 0;  
}

Node1* createStack1(){
    Node1* head = (Node1*)malloc(sizeof(Node1));
    head->number = -1;
    head->next = NULL;
    
    return head;
}

Node2* createStack2(){
    Node2* head = (Node2*)malloc(sizeof(Node2));
    head->f = ' ';
    head->next = NULL;
    
    return head;
}

void pushS1(Node1* head,int n){
    if(head == NULL) return;
    Node1* p = (Node1*)malloc(sizeof(Node1));
    p->number = n;
    p->next = head->next;
    head->next = p;
}

void pushS2(Node2* head,char a){
    if(head == NULL) return;
    Node2* p = (Node2*)malloc(sizeof(Node2));
    p->f = a;
    p->next = head->next;
    head->next = p;
}

int topS1(Node1* head){
    if(head == NULL) return -1;
    return head->next->number;
}

char topS2(Node2* head){
    if(head == NULL) return ' ';
    return head->next->f;
}

void popS1(Node1* head){
    if(head == NULL) return;
    Node1* p = head->next;
    head->next = p->next;
    free(p);
}

void popS2(Node2* head){
    if(head == NULL) return;
    Node2* p = head->next;
    head->next = p->next;
    free(p);
}

bool emptyS1(Node1* head){ // @@ [Function uses 'bool' without including <stdbool.h>]
    if(head == NULL || head->next == NULL) return true; // @@ ['true' is undeclared without <stdbool.h>]
    else return false; // @@ ['false' is undeclared without <stdbool.h>]
}

bool emptyS2(Node2* head){ // @@ [Function uses 'bool' without including <stdbool.h>]
    if(head == NULL || head->next == NULL) return true; // @@ ['true' is undeclared without <stdbool.h>]
    else return false; // @@ ['false' is undeclared without <stdbool.h>]
}

int sizeS1(Node1* head){
    if(head == NULL) return -1;
    int len = 0;
    Node1* p = head->next;
    while(p){
        len++;
        p = p->next;
    }
    
    return len;
}

int sizeS2(Node2* head){
    if(head == NULL) return -1;
    int len = 0;
    Node2* p = head->next;
    while(p){
        len++;
        p = p->next;
    }
    
    return len;
}

void back(){
    Node2 *head = createStack2();
//    stack<char> fu;  
    fgets(a,sizeof(a),stdin);
    a[strcspn(a,"\n")] = '\0';
    int len = strlen(a);  
    int j = 0;  
    for (int i = 0; i < len; i++) {
        if(a[i] == ' ') continue;  
        if (a[i] >= '0' && a[i] <= '9') {  
            b[j++] = a[i];  
            while(i < MAX-1 && a[i+1] >= '0' && a[i+1] <= '9'){
                i++;
                b[j++] = a[i];
            }
            b[j++] = ' ';
        } else {  
            switch (a[i]) {  
                case '+':  
                case '-':  
                    while (!emptyS2(head) && (topS2(head) == '*' || topS2(head) == '/' || topS2(head) == '-')) {  
                        b[j++] = topS2(head);  
                        popS2(head);  
                    }  
                    pushS2(head,a[i]);  
                    break;  
                case '*':  
                case '/':  
                    while (!emptyS2(head) && (topS2(head) == '*' || topS2(head) == '/')) {  
                        b[j++] = topS2(head);  
                        popS2(head);  
                    }  
                    pushS2(head,a[i]);  
                    break;  
                case '(':  
                    pushS2(head,a[i]);  
                    break;  
                case ')':  
                    while (!emptyS2(head) && topS2(head) != '(') {  
                        b[j++] = topS2(head);  
                        popS2(head);  
                    }  
                    popS2(head); 
                    break;  
            }  
        }  
    }  
    while (!emptyS2(head)) {  
        if (topS2(head) != '(') {
            b[j++] = topS2(head);  
        }  
        popS2(head);  
    }  
    b[j] = '\0'; 
//    puts(b);  
}

void aes(){
    Node1* head = createStack1();
//    stack<int> num;
    int len = strlen(b);
    int digit;
    int result;
    for(int i=0;i<len;i++){
        if(b[i]>='0'&&b[i]<='9'){
            digit = (int)b[i]-48;
            while(i<MAX-1&&b[i+1]>='0'&&b[i+1]<='9'){
                i++;
                digit *= 10;
                digit += (int)b[i]-48;
            }
            pushS1(head,digit);
        }
        if(b[i] == ' ') continue;
        int t;
        switch(b[i]){
            case '+':
                t = topS1(head);
                popS1(head);
                result = topS1(head) + t;
                popS1(head);
                pushS1(head,result);
                break;
            case '-':
                t = topS1(head);
                popS1(head);
                result = topS1(head) - t;
                popS1(head);
                pushS1(head,result);
                break;
            case '*':
                t = topS1(head);
                popS1(head);
                result = topS1(head) * t;
                popS1(head);
                pushS1(head,result);
                break;
            case '/':
                t = topS1(head);
                popS1(head);
                result = topS1(head) / t;
                popS1(head);
                pushS1(head,result);
                break;
        }
    }
    result = topS1(head);
    popS1(head);
    printf("%d",result);
}