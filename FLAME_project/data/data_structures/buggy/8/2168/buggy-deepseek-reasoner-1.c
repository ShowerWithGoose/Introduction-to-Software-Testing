#include<stdio.h>

int main(){
    char c; // @@ [Error: The program does not implement the required graph traversal logic. It merely echoes input character by character. It should instead read integers for n, m, edges, and k, store an adjacency matrix, and perform DFS and BFS before and after deletion.]
    while((c=getchar())!=EOF){ // @@ [Error: This loop reads all input as characters and outputs them, which does not solve the problem. The program should parse the input as integers and edges, then output the traversal sequences.]
        printf("%c",c); // @@ [Error: This prints the input characters, not the required output. The output should be the DFS and BFS sequences, not the input.]
    }
}