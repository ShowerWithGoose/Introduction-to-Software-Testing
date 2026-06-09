//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a); // @@ [Error: The program only reads a single integer, but the input format requires reading the number of vertices n, number of edges m, then m edge pairs, and finally the vertex to delete. This does not correctly parse the input.]
    printf("%d ",a); // @@ [Error: The program only prints the first integer read, but the expected output requires four lines: DFS and BFS before deletion, then DFS and BFS after deletion. This output is incomplete and incorrect.]
    return 0;
}