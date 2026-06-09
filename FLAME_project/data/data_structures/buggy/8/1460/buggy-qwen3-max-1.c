//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a; // @@ [The program only reads a single integer 'a', but the input format requires reading number of vertices n and edges m first. This completely ignores graph structure, edge list, and vertex deletion logic.]
    scanf("%d",&a); // @@ [Only reads one integer instead of n and m as required by input format.]
    printf("%d ",a); // @@ [Outputs only the first read integer followed by a space, which does not match expected DFS/BFS traversal outputs at all.]
    return 0;
}