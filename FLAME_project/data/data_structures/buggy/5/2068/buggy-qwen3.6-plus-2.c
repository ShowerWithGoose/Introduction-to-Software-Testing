#include <stdio.h>
int a[1005][2]={0},b[1005][2]={0},c[1005][2]={0};
int main()
{
    //输入a 
    char ch;
    int i=0,j=0,k=0;
    do{
        scanf("%d%d",&a[i][0],&a[i][1]);
        i++;
    }while((ch=getchar())!='\n'); // @@ The original code `ch=getchar()!='\n'` has incorrect operator precedence. It evaluates `getchar() != '\n'` first (resulting in 0 or 1) and assigns that to `ch`. It should be `(ch=getchar()) != '\n'`.
    
    //输入b 
    int l1=i;
/*    printf("\n");
    for(j=0;j<i;j++){
        printf("%d %d ",a[j][0],a[j][1]);
    }
    printf("\n");*/
    i=0;
    do{
        scanf("%d%d",&b[i][0],&b[i][1]);
        for(j=0;j<l1;j++){
            c[k][0]=a[j][0]*b[i][0];
            c[k][1]=a[j][1]+b[i][1];
            k++;
        }
        i++;
    }while((ch=getchar())!='\n'); // @@ Same precedence error as above. Also, `ch` retains its value from the previous loop if not updated correctly, but the main issue is precedence.
/*    printf("\n");
    for(j=0;j<i;j++){
        printf("%d %d ",b[j][0],b[j][1]);
    }
    printf("\n");
*/
    //冒泡排序
    int t,l2=k;
    for(i=0;i<l2-1;i++){
        for(j=0;j<l2-i-1;j++){
            if(c[j][1]>c[j+1][1]){ // @@ The problem requires output in descending order of exponents. This sort is ascending (smaller exponents first). It should be `c[j][1] < c[j+1][1]` to sort in descending order.
                t=c[j][1];
                c[j][1]=c[j+1][1];
                c[j+1][1]=t;
                t=c[j][0];
                c[j][0]=c[j+1][0];
                c[j+1][0]=t;
            }
        }
    }
    
    //合并同类项
    int e=0;
    for(i=0;i<l2-e;i++){
        if(c[i][1]==c[i+1][1]) {
            c[i][0]+=c[i+1][0];
            for(j=i;j<l2-e;j++){
                c[j+1][0]=c[j+2][0];
                c[j+1][1]=c[j+2][1];
                
            }
            e++;
            i--;
        }
        
    }
    printf("%d\n",i); // @@ This line prints an extra integer (the loop index `i`) which is not part of the expected output format. It should be removed.
    //输出结果 
    while(i--){ // @@ Since `i` was modified by the merge loop and then printed, its value is likely incorrect for iterating through the final result array `c` which has `l2-e` terms. It should iterate based on the actual number of terms remaining.
        printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}