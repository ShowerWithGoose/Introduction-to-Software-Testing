#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
typedef struct denode{
    int mark;//表示是否已经被访问
    int num;
    struct denode *next;//类邻接表，储存该节点所连通的节点
} denode;

void enorder();
void BFS(denode*);
void DFS(denode*);//两种遍历均从编号为0的节点开始
denode* talloc(int);
void swap(denode*,denode*);
void pr();
int isin(int);

int quene[110];//广度优先遍历辅助队列
int tail,head;
denode nodes[105];
int n1,n2,n3;

int main(){

    int i,j;//n1个顶点，n2条边，删除n3序号的节点
    int point1,point2;
    denode *p = NULL;
    for(i = 0;i < 105;++i){
        nodes[i].next = NULL;
    }
    scanf("%d%d",&n1,&n2);//0 ~ n1-1 是编号
//    printf("%d %d\n",n1,n2);
    for(i = 0;i < n2;++i){
        scanf("%d%d",&point1,&point2);
//        printf("%d %d\n",point1,point2);
        nodes[point1].mark = 0;nodes[point1].num = point1;
        nodes[point2].mark = 0;nodes[point2].num = point2;
        for(p = &nodes[point1];p->next != NULL;p = p->next);
        p->next = talloc(point2);
        for(p = &nodes[point2];p->next != NULL;p = p->next);
        p->next = talloc(point1);
    }
    scanf("%d",&n3);


//    printf("%d\n",n3);
//return 0;



    enorder();
    //pr();return 0;

    DFS(&nodes[0]);printf("\n");
    for(i = 0;i < 105;++i) nodes[i].mark = 0;
    //pr();
    BFS(&nodes[0]);printf("\n");
    //return 0;



    for(i = 0;i < 105;++i) nodes[i].mark = 0;
    nodes[n3].mark = 1;
    DFS(&nodes[0]);printf("\n");
    for(i = 0;i < 105;++i) nodes[i].mark = 0;
    nodes[n3].mark = 1;
    BFS(&nodes[0]);printf("\n");
    return 0;
}

denode* talloc(int number){
    denode *tem = (denode*)malloc(sizeof(denode));
    tem->mark = 0;
    tem->num = number;
    tem->next = NULL;
    return tem;
}

void BFS(denode* tem){
    /*if(tem != NULL){
        denode *p = tem;
        for(;p != NULL;p = p->next){
            if(nodes[p->num].mark == 0){
                printf("%d ",p->num);
                nodes[p->num].mark = 1;
            }
        }
        for(p = tem->next;p != NULL;p = p->next){
            BFS(&nodes[p->num]);
        }
    }*/
    denode *p = NULL;
    int out = 0,i;
    //队头  队尾
    tail = -1;head = 0;
    memset(quene,0,sizeof(quene));
    quene[++tail] = tem->num;//入队
    while(head - tail < 1){//队列不空
        out = quene[head++];//取出一个
        printf("%d ",out);
        nodes[out].mark = 1;
        for(p = &nodes[out];p != NULL;p = p->next){
            if(nodes[p->num].mark == 0){
                if(isin(p->num) == 0)//不在队中则入队
                quene[++tail] = p->num;
            }
        }
    }
}

int isin(int numb){
    int i;
    for(i = head;i <= tail;++i){
        if(quene[i] == numb) return 1;
    }
    return 0;
}

void DFS(denode* tem){
    if(tem->mark == 0){
        printf("%d ",tem->num);
        tem->mark = 1;
        denode *p = tem->next;
        for(;p != NULL;p = p->next){
            DFS(&nodes[p->num]);
        }
    }
}

void swap(denode *p,denode *q){
    int tem;
    tem = p->num;
    p->num = q->num;
    q->num = tem;
}

void enorder(){
    int j,i = 0;
    denode *m,*q,*p;
    for(i = 0;i < n1;++i){
        //printf("look,i = %d:",i);for(m = &nodes[0];m != NULL;m = m->next) printf("%d ",m->num);printf("\n");
        q = p = nodes[i].next;
        for(;q != NULL;q = q->next){
            for(p = nodes[i].next;p != NULL && p->next != NULL;p = p->next){
                if(p->num > p->next->num) swap(p,p->next);
            }
        }
    }
    return ;
}


void pr(){
    int i;
    denode *p;
    for(i = 0;i < n1;++i){
        p = &nodes[i];
        for(;p != NULL;p = p->next){
            printf("%d ",p->num);
        }
        printf("\n");
    }
    return ;
}
