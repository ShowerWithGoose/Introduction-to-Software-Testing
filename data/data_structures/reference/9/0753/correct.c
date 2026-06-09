#include <stdio.h>

int n;
int coo[205][2];//用于记录线段坐标
int min[205][2];//用于存放每条线段的初始点
int lines[205];//用于记录下了多少层
int line;//用于记录有多少条线段
int flag = -1;
int used[205];

int compare(int i, int j){//线段比较
    if((coo[i][0] == coo[j][0] && coo[i][1] == coo[j][1])||
        (coo[i][0] == coo[j+1][0] && coo[i][1] == coo[j+1][1])||
        (coo[i+1][0] == coo[j][0] && coo[i+1][1] == coo[j][1])||
        (coo[i+1][0] == coo[j+1][0] && coo[i+1][1] == coo[j+1][1])) return 1;
    return 0;
}

void search_com_cho(int node){
    flag++;
    used[node] = 1;

    if(!flag){
        min[line][0] = coo[node][0];
        min[line][1] = coo[node][1];
    }
    
    int i = 0;
    for(; i < 2 * n; i += 2){
        if(compare(node, i)&&!used[i]){
            lines[line]++;
            if(coo[i][0] < min[line][0]){
                min[line][0] = coo[i][0];
                min[line][1] = coo[i][1];
            }
            search_com_cho(i);
            flag--;
            used[i] = 0;
            break;
        }
    }
    return;
}

int main(){
    scanf("%d", &n);
    int i = 0;
    for(; i < 2 * n; i += 2) scanf("%d%d%d%d", &coo[i][0], &coo[i][1], &coo[i+1][0], &coo[i+1][1]);
    for(i = 0; i < 2 * n; i += 2){
        search_com_cho(i);
        used[i] = 0;
        line++;
        flag = -1;
    } 

    int max = 0, max_num = 0;
    for(i = 0; i < line; i++)
        if(lines[i] > max){
            max = lines[i];
            max_num = i;
        } 
    
    printf("%d %d %d", max+1, min[max_num][0], min[max_num][1]);
}


