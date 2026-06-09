#include<stdio.h>

int main(){
    char c;
    while((c=getchar())!=EOF){ // @@ This loop reads and echoes input character by character instead of parsing integers and performing graph traversals. The program should read n, m, edges, and delete vertex, then output DFS and BFS sequences.
        printf("%c",c); // @@ This prints each character, causing the output to be the same as input. Should output traversal sequences.
    }
}