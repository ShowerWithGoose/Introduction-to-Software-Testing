#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int s[10]={1,2,3,4,5,6,7,8,9,10};

void pop(int a,int b){
    int temp;
    temp=s[b];
    for(int i=b;i>a;i--){
        s[i]=s[i-1];
    }
    s[a]=temp;
}

void repop(int a,int b){
    int temp;
    temp=s[a];
    for(int i=a;i<b;i++){
        s[i]=s[i+1];
    }
    s[b]=temp;
}

void output(int num){
    for(int i=0;i<=num;i++){
        printf("%d ",s[i]);
    }
    putchar('\n');
}

void arrange(int first,int last){
    if(first==last){output(last);return;}
    //升序检查
    for(int i=first;i<=last;i++){
        pop(first, i);
        arrange(first+1,last);
        repop(first, i);
    }
}


int main() {
    int num;
    scanf("%d",&num);
    arrange(0, num-1);
    return 0;
    
}



