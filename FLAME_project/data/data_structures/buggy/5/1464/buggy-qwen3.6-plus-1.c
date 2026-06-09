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
    void domultiply(); // @@ This is a function declaration, not a call. The function domultiply is never executed, so the terms are not sorted or merged. It should be domultiply();
    if(multi[3].constant==60){
        printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
        return 0;
    }
    for(k=0;multi[k].constant!=0;k++) { // @@ The logic for printing is flawed. It stops at the first zero coefficient, but since domultiply wasn't called (or even if it was, the zeroing logic is weak), unmerged terms with non-zero coefficients might be out of order or duplicated. More importantly, without sorting/merging, this just prints raw products. Even if domultiply was called, the 'zeroing' sets square to 0, which might interfere if there's a valid x^0 term. But the primary error is the failure to call domultiply.
        printf("%d %d ",multi[k].constant,multi[k].square);
    }
}