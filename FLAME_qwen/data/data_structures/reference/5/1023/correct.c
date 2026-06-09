// 3. 多项式相乘
// 【问题描述】（建议用链表实现）

// 编写一个程序实现两个一元多项式相乘。

// 【输入形式】

// 首先输入第一个多项式中系数不为0的项的系数和指数，以一个空格分隔。且该多项式中各项的指数均为0或正整数，系数和最高幂次不会超过int类型的表示范围。
// 对于多项式 anxn +a n-1 x n-1 +......+ a1x1 + a0x0 的输入方法如下：
// an  n  a n-1  n-1 ......  a1  1  a0  0 
// 即相邻两个整数分别表示表达式中一项的系数和指数。在输入中只出现系数不为0的项。最后一项的指数后没有空格，只有一个回车换行符。
// 按照上述方式再输入第二个多项式。

// 【输出形式】

// 将运算结果输出到屏幕。将系数不为0的项按指数从高到低的顺序输出，每次输出其系数和指数，均以一个空格分隔，最后一项的指数后也可以有一个空格。

// 【样例输入】

// 10 80000 2 6000 7 300 5 10 18 0
// 3 6000 5 20 8 10 6 0
// 10 8 10 7
// 10 3 10 1
// 【样例输出】

// 30 86000 50 80020 80 80010 60 80000 6 12000 21 6300 10 6020 31 6010 66 6000 35 320 56 310 42 300 25 30 130 20 174 10 108 0

// 【样例说明】

// 输入的两行分别代表如下表达式：
// 10x80000 + 2x6000 + 7x300 + 5x10 + 18
// 3x6000 + 5x20 + 8x10 + 6
// 相乘结果为：
// 30x86000 + 50x80020 + 80x80010 + 60x80000 + 6x12000 + 21x6300 + 10x6020 + 31x6010 + 66x6000 + 35x320 + 56x310 + 42x300 + 25x30 + 130x20 + 174x10 + 108

// 提示：利用链表存储多项式的系数和指数。

// 【评分标准】

// 该题要求输出相乘后多项式中系数不为0的系数和指数，共有5个测试点。上传C语言文件名为multi.c。
#include<stdio.h>
#include<stdlib.h>
struct multinomial{
    int Power;
    int Num;
    struct multinomial *next;
}*Multinomial_A,*Multinomial_B,*Multinomial_C,*p,*pr;
struct multinomial *Append_Num(struct multinomial *p,struct multinomial *pr){
    struct multinomial *Head;
    Head=p;
    if(p==NULL){
        Head=pr;
        Head->next=NULL;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=pr;
        p=p->next;
        p->next=NULL;
    }
    return Head;
}
struct multinomial *Mult_Num(struct multinomial *pr_1,struct multinomial *pr_2){
    struct multinomial *Final;
    Final=(struct multinomial*)malloc(sizeof(struct multinomial));
    (*Final).Num=(*pr_1).Num*(*pr_2).Num;
    (*Final).Power=(*pr_1).Power+(*pr_2).Power;
    return Final;
}
struct multinomial *Add_Mult_Num(struct multinomial *p,struct multinomial *pr){
    struct multinomial *Head;
    Head=p;
    if(p==NULL){
        return Append_Num(Head,pr);
    }
    else{
        while(p!=NULL){
            if((*p).Power==(*pr).Power){
                (*p).Num+=(*pr).Num;
                return Head;
            }
            if(p->next!=NULL){
                if((*(*p).next).Power<(*pr).Power){
                    Add(p,pr);
                    return Head;
                }
            }
            p=p->next;
        }
        return Append_Num(Head,pr);
    }
}
void Add(struct multinomial *p_1,struct multinomial *p_2){
    struct multinomial *p;
    p=p_1->next;
    p_1->next=p_2;
    p_2->next=p;
}//调换后一位的连结元素，头节点必定最大
void Delete(struct multinomial *p){
    struct multinomial *pr;
    while(p!=NULL){
        pr=p;
        p=p->next;
        free(pr);
    }
}
int main(){
    int Is=0;
    char end;
    struct multinomial *p_1,*p_2,*p_3;
    Multinomial_A=NULL;
    Multinomial_B=NULL;
    Multinomial_C=NULL;
    while(Is==0){
        pr=(struct multinomial*)malloc(sizeof(struct multinomial));
        scanf(" %d %d",&(*pr).Num,&(*pr).Power);
        Multinomial_A=Append_Num(Multinomial_A,pr);
        end=getchar();
        if(end=='\n')Is=1;
    }
    Is=0;
    while(Is==0){
        pr=(struct multinomial*)malloc(sizeof(struct multinomial));
        scanf(" %d %d",&(*pr).Num,&(*pr).Power);
        Multinomial_B=Append_Num(Multinomial_B,pr);
        end=getchar();
        if(end=='\n')Is=1;
    }
    p_1=Multinomial_A;
    while(p_1!=NULL){
        p_2=Multinomial_B;
        while(p_2!=NULL){
            p_3=Mult_Num(p_1,p_2);
            Multinomial_C=Add_Mult_Num(Multinomial_C,p_3);
            p_2=p_2->next;
        }
        p_1=p_1->next;
    }
    p_3=Multinomial_C;
    while(p_3!=NULL){
        printf("%d %d ",(*p_3).Num,(*p_3).Power);
        p_3=p_3->next;
    }
    Delete(Multinomial_A);
    Delete(Multinomial_B);
    Delete(Multinomial_C);
    return 0;
}
