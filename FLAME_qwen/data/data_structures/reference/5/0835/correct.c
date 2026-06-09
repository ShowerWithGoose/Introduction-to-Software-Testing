//
//  main.c
//  DS3-3
//
//  Created by  on 2022/3/26.
//
//  多项式乘法  链表
//
// 问题：
//1.输入循环用while跳不出去了
//2.对于链表来说，每往后走一个节点，都要用malloc开空间
//3.在计算时，p1、p2不应该从first->next开始，要从first本身开始
//4.不要把几个节点用同一个malloc开空间，他们会指向同一个地址，
//  导致一旦后面的变量赋了新的值，其他变量也会跟着一起变
//5.要考虑只有一个数据的情况（如果不设控制条件，do-while势必会进行一次，倒是后do-while找不到数据，必然会卡住没有输出）
//
//
//
//

#include <stdio.h>
#include <stdlib.h>


struct link{
    int an;  //系数
    int n;   //指数
    struct link *next;  //指针
};

int main() {
    int i=0,j=0,k=0,m=0;
    int b=0,d=0;
    char c = '\0';
    int n1=0,n2=0;
    struct link *first1,*p1;
    struct link *first2,*p2;
    first1=(struct link*)malloc(sizeof(struct link));
    first2=p2=(struct link*)malloc(sizeof(struct link));
    
    scanf("%d%d%c",&first1->an,&first1->n,&c);  //输入第一行数据
    i=1;
    first1->next=(struct link*)malloc(sizeof(struct link));
    p1=first1->next;
    
    if(c!='\n'){
        do{
            scanf("%d%d%c",&b,&d,&c);  //用一个字符处理换行，int判断不了的'\n',char可以
            p1->an=b;
            p1->n=d;
            p1->next=(struct link*)malloc(sizeof(struct link));
            p1=p1->next;
            i++;
        }while(c!='\n');
    }
//    do{
//        scanf("%d%d%c",&b,&d,&c);  //用一个字符处理换行，int判断不了的'\n',char可以
//        p1->an=b;
//        p1->n=d;
//        p1->next=(struct link*)malloc(sizeof(struct link));
//        p1=p1->next;
//        i++;
//    }while(c!='\n');
    n1=i;
    
    scanf("%d%d%c",&first2->an,&first2->n,&c);   //输入第二行数据
    j=1;
    first2->next=(struct link*)malloc(sizeof(struct link));
    p2=first2->next;
    if(c!='\n'){
        do{
            scanf("%d%d%c",&b,&d,&c);
            p2->an=b;
            p2->n=d;
            p2->next=(struct link*)malloc(sizeof(struct link));
            p2=p2->next;
            j++;
        }while(c!='\n');
    }
    n2=j;
    
//    while(scanf("%d%d%c",&b,&d,&c),c!='\n'){
//        p2->an=b;
//        p2->n=d;
//        p2->next=(struct link*)malloc(sizeof(struct link));
//        p2=p2->next;
//        j++;
//    }
//    n2=j;
    
//    while(scanf("%d%d",&b,&d)!=EOF){  //bug:这样就会出现：跳不出去的死亡循环QAQ
//        p2->an=b;
//        p2->n=d;
//        p2->next=(struct link*)malloc(sizeof(struct link));
//        p2=p2->next;
//        j++;
//    }

    
//    scanf("%d%d",&first2->an,&first2->n);   //输入第二行数据
//    j=1;
//    p2=first2->next;
//    while(scanf("%d%d",&p2->an,&p2->n)!=EOF){ //bug:没开内存，每个节点都需要malloc开一遍内存
//        p2=p2->next;
//        j++;
//    }
//    n2=j;
    
    struct link *first,*p,*q,*a;
    first=(struct link*)malloc(sizeof(struct link));
    q=(struct link*)malloc(sizeof(struct link));
    a=(struct link*)malloc(sizeof(struct link));
    
    first->an=(first1->an)*(first2->an);
    first->n=(first1->n)+(first2->n);
    m=1;   //
    
    first->next=(struct link*)malloc(sizeof(struct link)); //给p开空间
    p=first->next;
    
    p1=first1;  //重新挂过来 bug:一定要从first本身开始！！！！
    p2=first2;
    
    p->next=NULL;  //怕p乱指，先挂到null上；???记得给next开空间
    
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            if(i==0&&j==0){
                p2=p2->next;
                continue;
            }
            else{
                q->an=(p1->an)*(p2->an);
                q->n=(p1->n)+(p2->n);
               // printf("%d %d",first->an,first->n);
                a=first;  //用来寻找插入位置的一个结构
                for(k=0;a->next!=NULL;k++){ //bug:无法正确判断空 //将输出链表遍历一遍，看看是否有重复项或者往中间插入
                    if((q->n)==(a->n)){
                        a->an=((a->an)+(q->an));
                        break;
                    }
                    else if((q->n)<(a->n)&&(q->n)>(a->next->n)){//
                        q->next=a->next;
                        a->next=q;
                        m++;
                        break;
                    }
                    a=a->next;
                }
                if(k==m){
                    p->an=q->an;
                    p->n=q->n;
                    p->next=(struct link*)malloc(sizeof(struct link));
                    p=p->next;
                    m++;
                }
            
            }
            p2=p2->next;
            q=(struct link*)malloc(sizeof(struct link));
        }
        p1=p1->next;
        p2=first2;
    }
    p->next=NULL;
    
    printf("%d %d ",first->an,first->n);  //已经把第一个（可能是唯一一个数据输出来了）
    p=first->next;
//    if(m==1){  //
//        printf("%d %d ",p->an,p->n);
//    }
//    else{
//        for(i=0;i<m-1;i++){//
//            printf("%d %d ",p->an,p->n);
//            p=p->next;
//        }
//
//    }
    
    for(i=0;i<m-1;i++){  //因为m的初始值是1，所以不会出现m=1的情况
        printf("%d %d ",p->an,p->n);
        p=p->next;
    }
    
    
    
    return 0;
}

//先开两个链表存储数据，再开一个链表，将相乘后的结果一个个存储下来，！！如果比前面的最后一位小，就直接连在后面，否则遍历，从中间插入（或者，每得到一个新的数据，都从前向后遍历一次，找到重复的就将an更新；否则找到比当前指数小的第一个节点，插在该节点前；
//指数相加，系数相乘；
//得到的结果要排序，如果乘完指数相同，要把两个系数加起来
//
//指数均为0或正整数




