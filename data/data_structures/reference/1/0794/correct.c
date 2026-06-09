#include<stdio.h>
#include<math.h>
#include<string.h>
int n;
int stack[10];

void print_stack();
void qpl(int len);
int find_in_stack(int key, int len);

int main(){
    scanf("%d", &n);
    qpl(0);
return 0;
}
void qpl(int len) {
    if (len==n) {
        print_stack();
        return;
    }
    for (int i=1;i<=n;i++)
        if (!find_in_stack(i,len)) {
            stack[len] = i;
            qpl(len+1);
        }
}
void print_stack() {
    for (int i=0;i<n;i++)
        {printf("%d",stack[i]);
        putchar(32);}
    puts("");
}
int find_in_stack(int key, int len) {
    for(int i=0; i<len; i++)
        if (key==stack[i])
            return 1;
    return 0;
}

