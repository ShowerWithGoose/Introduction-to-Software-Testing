#include<stdio.h>
#include<string.h>
#include<ctype.h>

void expand(int lenth, int step, int i, char a[]);


int main(){
    char a[200] = {0};
    gets(a);
    int lenth, step;
    //printf("%d\n", lenth);
    int i;
    for(i = 0; a[i] != '\0'; ++i){
        if( a[i] == '-' && a[i-1]<a[i+1] && ((islower(a[i-1])&&islower(a[i+1])) || (isupper(a[i-1])&&isupper(a[i+1]))  || (isdigit(a[i-1])&&isdigit(a[i+1]))) ){
            lenth = strlen(a);
            step = a[i+1] - a[i-1] - 1;     //计算移动距离
            expand(lenth, step, i, a);

        }

    }

    printf("%s\n", a);

    
    return 0;

    //system("pause");
}

void expand(int lenth, int step, int i, char a[]){
    /*a[lenth + step] = a[lenth];
    a[lenth] = '0';*/
    int j;
	for(j = lenth; j >= i + 1; --j){
        a[j + step-1] = a[j];
        //a[j] = '9';
        //printf("%c\n", a[j+step-1]);
    }
	int k, p;
    for(k = i, p = 0;p < step; ++k, ++p){
        a[k] = a[k - 1] + 1;
        //printf("%c\n", a[k]);

    }


}



