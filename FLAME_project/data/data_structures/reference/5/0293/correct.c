#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int time;//系数
    int multi;//幂
    struct elem *link;
}elem;

int main(){
    int i = 0,j = 0,k = 0,a = 0,b = 0,len_1 = 0,len_2 = 0,len_res = 0,tmp_time = 0,tmp_multi = 0;
    char suf;//suf表示每项后的字符
    elem *x1 = NULL,*x2 = NULL,*res = NULL,*p = NULL,*r = NULL;
    elem *ptr_1 = NULL,*ptr_2 = NULL,*ptr_3 = NULL;
    
    //读取第1串数据
    do{
        scanf("%d%d%c",&a,&b,&suf);
        r = (elem *)malloc(sizeof(elem));
        r->time = a;
        r->multi = b;
        r->link = NULL;
        k++;
        if(x1 == NULL){
            x1 = p = r;
        }
        else{
            p->link = r;
            p = p->link;
        }
    }while(suf != '\n');
    len_1 = k;
    k = 0;
    
    //读取第2串数据
    do{
    scanf("%d%d%c",&a,&b,&suf);
        r = (elem *)malloc(sizeof(elem));
        r->time = a;
        r->multi = b;
        r->link = NULL;
        k++;
        if(x2 == NULL){
            x2 = p = r;
        }
        else{
            p->link = r;
            p = p->link;
        }
    }while(suf != '\n');
    len_2 = k;
    k = 0;
    ptr_1 = x1,ptr_2 = x2;

    //开结果链表，首项不留空（因为首项肯定不会被删掉）
    for(i = 0;i < len_1;ptr_1 = ptr_1->link,i++){//把所有两因式之积放进结果链表，先不合并
        for(j = 0;j < len_2;ptr_2 = ptr_2->link,j++,k++){
            r = (elem *)malloc(sizeof(elem));
            r->time = ptr_1->time * ptr_2->time;
            r->multi = ptr_1->multi + ptr_2->multi;
            if(res == NULL){
                res = p = r;
            }
            else{
                p->link = r;
                p = p->link;
            }
        }
        ptr_2 = x2;
    }
    len_res = k;

    //合并同类项
    for(i = 0,ptr_1 = res;i < len_res;ptr_1 = ptr_1->link,i++){
        for(j = i + 1,ptr_3 = ptr_1,ptr_2 = ptr_1->link;j < len_res;ptr_2 = ptr_2->link,ptr_3 = ptr_3->link,j++){
            if(ptr_2->multi == ptr_1->multi){
                ptr_1->time += ptr_2->time;
                ptr_3->link = ptr_2->link;
                len_res--;
                free(ptr_2);
                ptr_2 = ptr_3->link;
            }
            else{}
        }
    }

    //调整为降幂排列
    for(i = 0,ptr_1 = res;i < len_res - 1;ptr_1 = ptr_1->link,i++){
        for(j = 0,ptr_3 = res,ptr_2 = res->link;j < len_res - 1 - i;ptr_2 = ptr_2->link,ptr_3 = ptr_3->link,j++){
            if(ptr_3->multi < ptr_2->multi){//使用了传统的冒泡排序以提高可靠性
                tmp_time = ptr_3->time;
                ptr_3->time = ptr_2->time;
                ptr_2->time = tmp_time;
                tmp_multi = ptr_3->multi;
                ptr_3->multi = ptr_2->multi;
                ptr_2->multi = tmp_multi;
            }
            else {}
        }
    }

    //输出
    for(ptr_1 = res,i = 0;i < len_res;ptr_1 = ptr_1->link,i++){//输出
        if(ptr_1->time != 0){
            printf("%d %d ",ptr_1->time,ptr_1->multi);
        }
    }
    return 0;
}
