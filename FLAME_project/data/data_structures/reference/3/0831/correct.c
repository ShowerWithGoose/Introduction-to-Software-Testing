#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8

int main() {
    char in[250], tmp1[250], tmp2[250];
    char *p;
    int len = 0;
    int where0 = 0;
    int point = 0;

    scanf("%s", in);
    len = strlen(in);
    for (int i = 0; i < len; ++i){  //记录第一个有效数字出现的位置{
        if (in[i] != '0'&&in[i]!='.'){
            where0 = i;
            break;
        }
    }
    for (int j = 0; j < len; ++j)
        if (in[j] == '.') point = j;//记录小数点出现的位置
    len= strlen(in);
    for (int i = 0; i < len; ++i)
        tmp1[i]='\0';
    strncpy(tmp1, in, point);//
    p = &in[point + 1];
    strcpy(tmp2, p);
    strcat(tmp1, tmp2);
    len=strlen(tmp1);
    p=tmp1;
    for (int i = 0; i < len; ++i)   if(p[0]=='0') p++;

    if(strlen(p)==1) {
        printf("%ce%d\n", p[0], point - where0);
        return 0;
    }
    else if(point>where0)
        printf("%c.%se%d\n",p[0],p+1,point-where0-1);
    else if(point<where0)
        printf("%c.%se%d\n",p[0],p+1,point-where0);
    return 0;
}


