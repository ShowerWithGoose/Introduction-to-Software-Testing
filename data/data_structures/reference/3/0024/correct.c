    /*小数点移动规则
1.首项为0——纯小数，查找首个不为0的数位，移动到第0位，下一个少移动一位（保证留点）
2.首项不为0——找到点的位置，整体右移一位


*/

#include<stdio.h>
#include<string.h>
void move(char a[], int begin, int end, int space);
void moveright(char a[], int begin, int end, int space);

int main(){
    char a[200], s[10];
    int lenth = 0, dotpin = 0, numpin = 0, E = 0;

    gets(a);
    int i = 0;

    //首项为0的纯小数
    if(a[0] == '0'){
        for(i = 2; a[i] == '0'; ++i){
            ;    //找到首个不为0的整数
        }
        lenth = strlen(a);
        numpin = i;
        E = 1 - numpin;
        a[0] = a[numpin];
        move(a, numpin+1, lenth, 2-numpin-1);
        if(numpin == lenth - 1){
            a[1] = '\0';
        }
        sprintf(s, "e%d", E);
        strcat(a, s);
        puts(a);

    }
    else{
        for(i = 1; a[i] != '.'; ++i){
            ;
        }
        dotpin = i;
        E = dotpin - 1;
        moveright(a, 1, dotpin, 1);
        a[1] = '.';
        sprintf(s, "e%d", E);
        strcat(a, s);
        puts(a);

    }






    return 0;
}
/*仅能向左移动，即0.000形式*/
void move(char a[], int begin, int end, int space){
    int j;
    for(j = begin; j <= end; ++j){
        a[j+space] = a[j];
    }
}

/*向右移动*/
void moveright(char a[], int begin, int end, int space){
    int j;
    if(begin == end){
        return;
    }
    for(j = end; j >= begin; --j){
        a[j] = a[j-space];
    }
}
