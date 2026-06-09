//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a); // @@ [The program only reads one integer 'a', but the input format requires reading n (number of vertices) and m (number of edges) first. This causes incorrect parsing of input.]
    printf("%d ",a); // @@ [The output is just a single number followed by a space, which does not match the required output format of four lines containing DFS and BFS traversals before and after deletion. The entire logic for graph construction, traversal (DFS/BFS), and vertex deletion is missing.]
    return 0;
}