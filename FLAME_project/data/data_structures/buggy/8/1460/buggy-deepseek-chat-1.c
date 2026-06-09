//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a); // @@ Error: This program only reads a single integer, but the input format requires reading n, m, edges, and the vertex to delete. It does not implement graph traversal or deletion logic.
    printf("%d ",a); // @@ Error: This prints only one integer, but the expected output requires four lines of vertex sequences for DFS and BFS before and after deletion.
    return 0;
}