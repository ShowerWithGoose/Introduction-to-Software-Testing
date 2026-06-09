//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a); // @@ [The program only reads one integer 'a' and prints it, but the problem requires reading a full graph (n, m, edges, and a vertex to delete) and performing DFS/BFS traversals before and after deletion. This implementation is completely incomplete and does not address the problem requirements. Additionally, the use of `scanf` without including proper headers for required data structures (like adjacency lists) and traversal logic leads to functional failure. However, the reported error is "Compilation Error: gcc: not found", which is actually an environment issue, not a code error. But given the context, the real issue is that this code is not even attempting to solve the described problem—it's a minimal placeholder that cannot produce the expected output for any valid test case.]
    printf("%d ",a);
    return 0;
}