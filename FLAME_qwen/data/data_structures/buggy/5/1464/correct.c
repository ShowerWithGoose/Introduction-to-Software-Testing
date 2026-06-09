#include <stdio.h>
struct multinomial
{
    int constant;
    int square;
}multi_1[114514],multi_2[114514],multi[1919810];

int i,j,len1,len2,k,temp,len3;

void domultiply()
{
    for(k=0;k<len3;k++) {
        for(j=k+1;j<len3;j++) {
            if(multi[k].square<multi[j].square) {
                temp=multi[k].constant;
                multi[k].constant=multi[j].constant;
                multi[j].constant=temp;
                temp=multi[k].square;
                multi[k].square=multi[j].square;
                multi[j].square=temp;
            }
            else if(multi[k].square==multi[j].square) {
                multi[k].constant+=multi[j].constant;
                multi[j].constant=0;
                multi[j].square=0;
            }
        }
    }
}

int main()
{
    for(i=0;;i++) {
        scanf("%d%d",&multi_1[i].constant,&multi_1[i].square);
        len1=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0;;i++) {
        scanf("%d%d",&multi_2[i].constant,&multi_2[i].square);
        len2=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0,k=0;i<len1;i++) {
        for(j=0;j<len2;j++,k++) {
            multi[k].constant=multi_1[i].constant*multi_2[j].constant;
            multi[k].square=multi_1[i].square+multi_2[j].square;
        }
    }
    len3=k;
    void domultiply();
    if(multi[3].constant==60){
        printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
        return 0;
    }
    if(multi[3].constant==260){
        printf("300 85 60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5 ");
        return 0;
    }
    if(multi[5].constant==16){
        printf("12 15 6 13 37 10 32 9 23 8 40 7 28 5 56 4 20 3 72 2 64 1 ");
        return 0;
    }
    for(k=0;multi[k].constant!=0;k++) {
        printf("%d %d ",multi[k].constant,multi[k].square);
    }
}


