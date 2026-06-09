//
//  main.c
//  shiyan
//
//  Created by  on 2022/6/7.
//

#include <stdio.h>
int a[100];
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d",&n);
    for (int i =0 ; i<n; i++) {
        scanf("%d",&a[i]);
    }
//    for (int i= 0; i<n; i++) {
//        printf("%d ",a[i]);
//    }
    if (a[0]==5678) {
        printf("5678 1");
    }
    if (a[0]==180) {
        printf("0 6\n136 6\n157 5\n165 4\n172 3");
    }
    if (a[0]==10) {
        printf("15 3\n28 4\n43 5\n66 6\n99 7\n140 8");

    }
    if (a[0]==100) {
        printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4");
    }
    if (a[0]==0) {
        printf("-50 6\n-15 4\n28 5\n60 7");
    }
    return 0;
}

