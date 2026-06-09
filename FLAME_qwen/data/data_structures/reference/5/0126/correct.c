/*#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000

typedef struct Lnode{
    int xishu;
    int zhishu;
    struct Lnode *next;
} Lnode , *LinkList;

LinkList insert_head(LinkList l , int xi , int zhi){//头插法
    LinkList ptr;
    ptr = (LinkList)malloc(sizeof(Lnode));
    ptr->xishu = xi;    ptr->zhishu = zhi;
    ptr->next = l->next;
    l->next = ptr;
    return l;
}

void trans(char *s , int *t){//字符串挨个转换成数字
    int j , com;
    j = com = 0;
    for(int i = 0 ; i < strlen(s) ; i++){                               //i计数字符串
        //读入数字(包含多位
        if((s[i]>='0'&&s[i]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')){
            com=(com+(s[i]-'0'))*10;
            continue;
        }
        else if(i>0&&(s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]==' '||s[i+1]=='\0')){
            com=com+s[i]-'0';
            t[j++]=com;                                                        //j计数所有数字
            com=0;//初始化com1
            continue;
        }
        else if(s[i] >= '0' && s[i] <= '9')
            t[j++]=s[i]-'0';
    }
}

int len(LinkList a){//获取链表长度
    int i = 0;
    LinkList b = a ;
    while(b->next->next != NULL){
        i++;
        b = b->next;
    }
    return i + 1;
}

void wtf(LinkList a , int n , int *xishu , int *zhishu){
    LinkList tmp = a;
    while(n--)  tmp = tmp->next;
    *xishu = tmp->xishu;
    *zhishu = tmp->zhishu;
}

//多项式乘法
LinkList multiply(LinkList a , LinkList b ){
    LinkList res;
    res = (LinkList)malloc(sizeof(Lnode));
    for(int i = 0 ; i < len(a) ; i++){
        
    }
    
    
    
    
    
    
    return res;
}

int main(){
    LinkList l , m , result ;
    l = (LinkList)malloc(sizeof(Lnode));
    m = (LinkList)malloc(sizeof(Lnode));
    result = (LinkList)malloc(sizeof(Lnode));
    char *a , *b;
    a = (char*)malloc(sizeof(char) * MAXSIZE);     b = (char*)malloc(sizeof(char)*MAXSIZE);
    int num1[100] , num2[100] , len1 , len2;
    memset( num1 , 1 , sizeof(num1));                             memset( num2 , 1 , sizeof(num2));
    int i , j ;
    i = j = 0;
    gets(a);                  gets(b);
    trans( a , num1);   trans( b , num2);
    //16843009是个神奇的数字,录入链表
    for(i = 0 ; num1[i] != 16843009 ; i += 2)   l = insert_head( l , num1[i] , num1[i+1]);
    for(i = 0 ; num2[i] != 16843009 ; i += 2)   m = insert_head( m , num2[i] , num2[i+1]);
    len1 = len(l);          len2 = len(m);
    int x , y;
    wtf(l, 2, &x, &y);
    result = multiply( l , m );
    
    return 0;
}*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000
typedef struct a{
    int xishu , zhishu;
}dxs;

void trans(char *s , int *t){//字符串挨个转换成数字
    int j , com;
    j = com = 0;
    for(int i = 0 ; i < strlen(s) ; i++){                               //i计数字符串
        //读入数字(包含多位
        if((s[i]>='0'&&s[i]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')){
            com=(com+(s[i]-'0'))*10;
            continue;
        }
        else if(i>0&&(s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]==' '||s[i+1]=='\0')){
            com=com+s[i]-'0';
            t[j++]=com;                                                        //j计数所有数字
            com=0;//初始化com1
            continue;
        }
        else if(s[i] >= '0' && s[i] <= '9')
            t[j++]=s[i]-'0';
    }
}

int cmp(const void *a , const void *b){
    dxs *p1 = (dxs*)a;
    dxs *p2 = (dxs*)b;
    if(p1->zhishu > p2->zhishu) return -1;
    return 1;
}

int main(){
    dxs l[MAXSIZE] , m[MAXSIZE] , result[MAXSIZE];
    memset( l , 0 , sizeof(l));
    memset( m , 0 , sizeof(m));
    memset( result , 0 , sizeof(result));
    char *a , *b;
    a = (char*)malloc(sizeof(char) * MAXSIZE);
    b = (char*)malloc(sizeof(char)*MAXSIZE);
    int num1[100] , num2[100] , len1 , len2 , lenres ;
    len1 = len2 = lenres = 0;
    memset( num1 , 1 , sizeof(num1));
    memset( num2 , 1 , sizeof(num2));
    gets(a);                  gets(b);
    trans( a , num1);   trans( b , num2);
    //16843009是个神奇的数字,录入结构体
    for(int i = 0 ; num1[i] != 16843009 ; i += 2){
        l[len1].xishu = num1[i];
        l[len1].zhishu = num1[i+1];
        len1++;
    }
    for(int i = 0 ; num2[i] != 16843009 ; i += 2){
        m[len2].xishu = num2[i];
        m[len2].zhishu = num2[i+1];
        len2++;
    }
    int flag , i , j , k;
    flag = i = j = k = 0 ;
    for( i = 0 ; i < len1 ; i++)    for( j = 0 ; j < len2 ; j++){
        flag = 0;
        for( k = 0 ; k < lenres ; k++){//检查指数重复
            if(result[k].zhishu != l[i].zhishu + m[j].zhishu)
                flag++;//指数都不等则flag应等于lenres
            else
                break;
        }
        if(flag == lenres){
            result[lenres].xishu = l[i].xishu * m[j].xishu;
            result[lenres].zhishu = l[i].zhishu + m[j].zhishu;
            lenres++;
        }
        else if(flag != lenres)
            result[k].xishu += l[i].xishu * m[j].xishu;
    }
    qsort(result, lenres + 1 , sizeof(dxs) , cmp);
    for( i = 0 ; i < MAXSIZE ; i++){
        if(result[i].xishu == 0 && result[i].zhishu == 0)   continue;
        else if(result[i].xishu != 0 && result[i].zhishu == 0){
            printf("%d %d" , result[i].xishu , result[i].zhishu);
            break;
        }
        printf("%d %d " , result[i].xishu , result[i].zhishu);
    }
    return 0;
}

