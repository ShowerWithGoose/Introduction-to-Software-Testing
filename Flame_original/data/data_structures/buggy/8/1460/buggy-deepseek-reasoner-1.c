//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a); // @@ The program only reads a single integer, but the problem requires reading n, m, edges, and a delete vertex. This does not process the graph or perform DFS/BFS, so it cannot produce the correct output.
    printf("%d ",a); // @@ This prints only one integer with a trailing space, whereas the expected output consists of multiple lines of vertex sequences.
    return 0;
}