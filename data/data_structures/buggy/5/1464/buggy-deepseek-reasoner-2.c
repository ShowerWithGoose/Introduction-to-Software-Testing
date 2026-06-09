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
                multi[j].constant=0; // @@ Setting coefficient to zero does not remove the term; it remains and disrupts sorting and printing.
                multi[j].square=0; // @@ Setting exponent to zero is incorrect; better to physically remove or skip zero terms later.
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
    void domultiply(); // @@ This is a function declaration, not a call. To execute the function, remove 'void' and use 'domultiply();'
    if(multi[3].constant==60){ // @@ Hardcoded output for a specific case is incorrect; it bypasses the general algorithm.
        printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
        return 0;
    }
    for(k=0;multi[k].constant!=0;k++) { // @@ The loop assumes non-zero terms appear contiguously from index 0; zeroed entries from merging break this assumption.
        printf("%d %d ",multi[k].constant,multi[k].square);
    }
}