#include<stdio.h>
#include<string.h>

int gra[105][105] = {0};//邻接矩阵
int n_l = 0, n_v = 0;//n_l为原始边个数， n_v为原始顶点数
int rea = 0, reb = 0;//暂存边的端点 
int vvt[105] = {0};
int n_c = -1;//删除点的序号
int mem_p[105] = {0};
int bbfss[105] = {0};//广度遍历队
int feer = 0, rear = 0;//rear指向队尾后的第一个空格

void dfs1();
void bfs1();
void dfs2();
void bfs2();
void Dfs1(int i);
void Dfs2(int i);
void Bfs1(int i);
void Bfs2(int i);
void visit1(int i);
void visit2(int i);

int main() {
    int k = 0;//生成bbfss计次
    scanf("%d%d", &n_v, &n_l);
    for(int i_red = 0; i_red < n_l; i_red ++) {
        scanf("%d%d", &rea, &reb);
        gra[rea][reb] = 1;
        gra[reb][rea] = 1;
    }
    dfs1();
    printf("\n");
    memset(mem_p, 0, sizeof(mem_p));
    bfs1();
    printf("\n");
    memset(mem_p, 0, sizeof(mem_p));
    
    scanf("%d", &n_c);

    dfs2();
    printf("\n");
    memset(mem_p, 0, sizeof(mem_p));
    bfs2();
    printf("\n");
    memset(mem_p, 0, sizeof(mem_p));
    return 0;
}

void dfs1() {
    int i;
    for(i = 0; i < n_v; i ++) {
        vvt[i] = 0;
    }
    for(i = 0; i < n_v; i ++) {
        if(! vvt[i]) {
            Dfs1(i);
        }
    }
    return;
}

void dfs2() {
    int i;
    for(i = 0; i < n_v; i ++) {
        vvt[i] = 0;
    }
    for(i = 0; i < n_v; i ++) {
        if((! vvt[i]) && i != n_c) {
            Dfs2(i);
        }
    }
    return;
}

void Dfs1(int i) {
    vvt[i] = 1;//标记访问
    printf("%d ", i);//访问操作
    for(int i_t = 0; i_t < n_v; i_t ++) {
        if((! vvt[i_t]) && gra[i][i_t]) {
            Dfs1(i_t);
        }
    }
    return;
}

void Dfs2(int i) {
    vvt[i] = 1;//标记访问
    printf("%d ", i);//访问操作
    for(int i_t = 0; i_t < n_v; i_t ++) {
        if((! vvt[i_t]) && i_t != n_c && gra[i][i_t]) {
            Dfs2(i_t);
        }
    }
    return;
}

void bfs1() {
    int i;
    for(i = 0; i < n_v; i ++) {
        vvt[i] = 0;
    }
    for(i = 0; i < n_v; i ++) {
        if(! vvt[i]) {
            Bfs1(i);
        }
    }
    return;
}

void Bfs1(int i) {
    vvt[i] = 1;
    visit1(i);
    if(i > 0 && feer == rear) {
        return;
    } else {
        Bfs1(bbfss[feer ++]);//同时出队，visit中不再需要出队
    }
    return;
}

void visit1(int i) {
    printf("%d ", i);//打印
    //白邻点进队
    for(int i_s = 0; i_s < n_v; i_s ++) {
        if(gra[i][i_s] && !vvt[i_s]) {
            bbfss[rear ++] = i_s;
            vvt[i_s] = 1;
        }
    }
    return;
}

void visit2(int i) {
    printf("%d ", i);//打印
    //白邻点进队
    for(int i_s = 0; i_s < n_v; i_s ++) {
        if(gra[i][i_s] && !vvt[i_s] && i_s != n_c) {
            bbfss[rear ++] = i_s;
            vvt[i_s] = 1;
        }
    }
    return;
}

void bfs2() {
    int i;
    for(i = 0; i < n_v; i ++) {
        vvt[i] = 0;
    }
    for(i = 0; i < n_v; i ++) {
        if((! vvt[i]) && i != n_c) {
            Bfs2(i);
        }
    }
    return;
}

void Bfs2(int i) {
    vvt[i] = 1;
    visit2(i);
    if(i > 0 && feer == rear) {
        return;
    } else {
        Bfs2(bbfss[feer ++]);//同时出队，visit中不再需要出队
    }
    return;
}
