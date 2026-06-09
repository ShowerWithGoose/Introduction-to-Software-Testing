#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){
    gets(s)    ; // @@ [The program uses gets() which is unsafe and not suitable for the problem; more critically, the entire logic is wrong—it just echoes input lines instead of implementing graph traversal. It does not read n, m, edges, or the vertex to delete, nor does it perform DFS/BFS before/after deletion.]
    puts(s);//TODO
    }return 0;
}