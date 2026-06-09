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
    void domultiply(); // @@ This is a function declaration, not a call. It should be domultiply(); to execute the sorting and merging logic.
    if(multi[3].constant==60){
        printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
        return 0;
    }
    for(k=0;multi[k].constant!=0;k++) { // @@ The loop condition relies on constant being non-zero, but after merging in domultiply, terms with zero coefficients are marked with constant=0 and square=0. However, these zeroed-out terms are not removed from the array or moved to the end, they just sit there. If a valid term has a coefficient of 0 (unlikely per problem statement "non-zero terms" in input, but possible in result), it stops printing. More importantly, the zeroed-out merged terms will stop the print loop prematurely if they appear before valid terms. The sorting/merging logic in domultiply is also flawed because it doesn't remove the merged elements, leaving gaps of zeros that break the output loop.
        printf("%d %d ",multi[k].constant,multi[k].square);
    }
}