//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a);
    printf("%d ",a);
    return 0;
} // @@ [The program does not implement the required DFS/BFS traversal logic for graph processing; it only reads and prints a single integer. Additionally, the use of `gets()` in the reference program is unsafe and deprecated, but the actual bug here is that the submitted code is completely unrelated to the problem specification—it fails to read graph edges, build adjacency structures, perform traversals, or handle vertex deletion. This leads to incorrect output for all test cases.]