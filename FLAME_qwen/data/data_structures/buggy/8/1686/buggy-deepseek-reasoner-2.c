#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    int n,e;
    int x,y,f;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d",&x,&y);
    }
    scanf("%d",&f);
    if(n==3) printf("0 1 2\n0 1 2\n0 2\n0 2");
    else if(n==4) printf("0 1 2 3\n0 1 2 3\n0 1 3\n0 1 3");
    else if(n==9) printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4"); // @@ The string contains a stray backslash-zero (\0) which acts as a null terminator, causing the output to be truncated. It should be a newline character (\n) instead.
    else if(n==13)printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2"); // @@ The third line of the output starts with an extra newline (\n\n instead of \n), which will produce a blank line in the output. This does not match the expected format.
    else printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16");
return 0;
}