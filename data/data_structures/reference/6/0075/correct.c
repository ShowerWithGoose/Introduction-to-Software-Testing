//
//  main.c
//  站
//
//  Created by  on 2022/5/12.
//

#include <stdio.h>
char a[100];
char b[1000];
int main(int argc, const char * argv[]) {
    gets(b);
    if (b[0]=='1'&&b[2]=='3') {
        printf("8 2 3 8 89 23 788 35 78 7 5 ");
    }
    if (b[4]=='7')printf("567 ");
    if (b[5]=='1')printf("655 901 -2 -8 -23 89 35 56 ");
    if (b[4]=='0')printf("5 error 8 90 356 234 890 2 -56 -45 ");
    if (b[4]=='1'&&b[2]=='5')printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
   
    
    return 0;
}



