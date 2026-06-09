#include <stdio.h>
struct multinomial
{
    int constant;
    int square;
}multi_1[114514],multi_2[114514],multi[1919810];

int i,j,len1,len2,k,temp,len3;

void domultiply()
{
    for(k=0;k<len3;k++) { // @@ The outer loop uses 'k' which is also used as index in main; the algorithm is flawed.
        for(j=k+1;j<len3;j++) {
            if(multi[k].square<multi[j].square) { // @@ This swapping attempts to sort but is incomplete and interferes with combination.
                temp=multi[k].constant;
                multi[k].constant=multi[j].constant;
                multi[j].constant=temp;
                temp=multi[k].square;
                multi[k].square=multi[j].square;
                multi[j].square=temp;
            }
            else if(multi[k].square==multi[j].square) { // @@ Combining like terms but leaving zero entries that are not removed, and the loop may miss later combinations.
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
    void domultiply(); // @@ This is a function declaration, not a call. The function is never executed.
    if(multi[3].constant==60){ // @@ Hardcoded condition for a specific case, not a general solution.
        printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 "); // @@ Hardcoded output, incorrect for general input.
        return 0;
    }
    for(k=0;multi[k].constant!=0;k++) { // @@ Loop stops at first zero coefficient, missing later non-zero terms if any; also assumes no zeros from combination.
        printf("%d %d ",multi[k].constant,multi[k].square);
    }
}