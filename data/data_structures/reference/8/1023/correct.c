// 1. 图遍历（图-基本题）
// 【问题描述】

// 给定一个无向图和一个图顶点，编程输出该图删除给定顶点前后按深度优先遍历及广度优先遍历方式遍历的图顶点序列。

// 给定的无向图和图顶点满足以下要求：

// 1、无向图的顶点个数n大于等于3，小于等于100，输入时顶点编号用整数0～n-1表示；

// 2、无向图在删除给定顶点前后都是连通的；

// 3、无论何种遍历，都是从编号为0的顶点开始遍历，访问相邻顶点时按照编号从小到大的顺序访问；

// 4、删除的顶点编号不为0。

// 【输入形式】

// 先从标准输入中输入图的顶点个数和边的个数，两整数之间以一个空格分隔，然后从下一行开始分行输入每条边的信息（用边两端的顶点编号表示一条边，
//以一个空格分隔顶点编号，边的输入次序和每条边两端顶点编号的输入次序可以是任意的，但边不会重复输入），最后在新的一行上输入要删除的顶点编号。

// 【输出形式】

// 分行输出各遍历顶点序列，顶点编号之间以一个空格分隔。先输出删除给定顶点前的深度优先遍历顶点序列和广度优先遍历顶点序列，
//再输出删除给定顶点后的深度优先遍历顶点序列和广度优先遍历顶点序列。

// 【样例输入】

// 9 10

// 0 1

// 0 2

// 1 4

// 1 3

// 1 8

// 8 6

// 3 6

// 7 2

// 7 5

// 5 2

// 3

// 【样例输出】

// 0 1 3 6 8 4 2 5 7

// 0 1 2 3 4 8 5 7 6

// 0 1 4 8 6 2 5 7

// 0 1 2 4 8 5 7 6

// 【样例说明】

// 输入的无向图有9个顶点，10条边（如下图所示），要删除的顶点编号为3。

// graph.jpg

// 从顶点0开始，按照深度优先和广度优先遍历的顶点序列分别为：0 1 3 6 8 4 2 5 7和0 1 2 3 4 8 5 7 6。删除编号为3的顶点后，
//按照深度优先和广度优先遍历的顶点序列分别为：0 1 4 8 6 2 5 7和0 1 2 4 8 5 7 6。

// 【评分标准】

// 该题要求按照深度优先和广度优先遍历方式输出删除给定顶点前后的遍历序列，提交程序名为graphSearch.c。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Num_Boarder,Num_Top,Step,Head,Last;
int Line[105][105]={ };
int visited[105],Queue[105];
void insert_Line(int x,int y);
void Deeper_Search(int Num);
void Boarder_Search();
void print();
int main(){
    int i;
    int Boarder_x,Boarder_y,Dele_Num;
    scanf(" %d %d",&Num_Top,&Num_Boarder);
    for(i=0;i<Num_Boarder;i++){
        scanf(" %d %d",&Boarder_x,&Boarder_y);
        Line[Boarder_x][Boarder_y]=1;
        Line[Boarder_y][Boarder_x]=1;
    }
    scanf(" %d",&Dele_Num);
    for(i=0;i<Num_Top;++i)visited[i]=0;
    Step=1;
    Deeper_Search(0);
    print();
    printf("\n");
    for(i=0;i<Num_Top;++i)visited[i]=0;
    Queue[0]=0;
    visited[0]=1;
    Head=0;
    Last=1;
    Boarder_Search();
    print();
    printf("\n");
    for(i=0;i<Num_Top;++i){
        Line[Dele_Num][i]=0;
        Line[i][Dele_Num]=0;
    }
    for(i=0;i<Num_Top;++i)visited[i]=0;
    Step=1;
    Deeper_Search(0);
    print();
    printf("\n");
    for(i=0;i<Num_Top;++i)visited[i]=0;
    Queue[0]=0;
    visited[0]=1;
    Head=0;
    Last=1;
    Boarder_Search();
    print();
    return 0;
}
void Deeper_Search(int Num){
    int i;
    visited[Num]=Step;
    if(Step==Num_Top)return;
    for(i=0;i<Num_Top;++i){
        if(Line[Num][i]!=0){
            if(visited[i]==0){
                ++Step;
                Deeper_Search(i);
            }
        }
    }
    return;
}
void Boarder_Search(){
    int i;
    while(Head<Last){
        for(i=0;i<Num_Top;++i){
            if(Line[Queue[Head]][i]!=0){
                if(visited[i]==0){
                    visited[i]=Last+1;
                    Queue[Last]=i;
                    Last++;
                }
            }
        }
        if(Last==Num_Top)break;
        Head++;
    }
    return;
}
void print(){
    int i,j;
    for(i=1;i<=Num_Top;++i){
        for(j=0;j<Num_Top;++j){
            if(visited[j]==i)printf("%d",j);
        }
        if(i!=Num_Top)printf(" ");
    }
}
