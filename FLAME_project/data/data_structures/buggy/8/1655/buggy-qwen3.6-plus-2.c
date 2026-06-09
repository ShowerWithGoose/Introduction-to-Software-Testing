#include<stdio.h>
#include<string.h>
int main(){
    int n,m;
    scanf("%d%d",&m,&n); // @@ The input format specifies "number of vertices n and number of edges m", but the code reads into m then n, swapping their values. Additionally, the subsequent logic relies on hardcoded outputs based on specific edge counts (m), which is an incorrect approach for a general graph problem. The program should implement actual DFS and BFS algorithms instead of using hardcoded if-else blocks.
    if(m==3){
        printf("0 1 2\n0 1 2\n0 2\n0 2\n");
    }
    else if(m==4){
        printf("0 1 2 \n0 1 2 3\n0 1 3\n0 1 3\n"); // @@ This branch is triggered when the swapped 'm' (actually n, number of vertices) is 4. However, the output "0 1 2 " has a trailing space and is missing vertex 3 in the first line, causing a Wrong Answer. More fundamentally, the entire approach of hardcoding outputs is incorrect.
    }
    else if(m==9){
        printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4\n");
    }
    else if(m==13){
        printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2\n");
    }
    else{
        printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16");
    }
}