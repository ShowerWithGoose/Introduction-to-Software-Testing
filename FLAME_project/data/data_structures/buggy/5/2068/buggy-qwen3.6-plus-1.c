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
    }while((ch=getchar())!='\n'); // @@ Same precedence error as above. Also, this loop structure assumes the input format allows reading pairs inside the loop condition check correctly, but the primary bug is the precedence.
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
            if(c[j][1]>c[j+1][1]){ // @@ The problem requires output in *descending* order of exponents. This sort is ascending (smaller exponents bubble to the top/lower indices). It should be `c[j][1] < c[j+1][1]` to sort descending, or the output logic needs to reverse. Given the later output loop counts down, let's look at the output.
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
    printf("%d\n",i); // @@ This line prints an integer (the index `i` from the previous loop) which is not part of the required output format. It causes Wrong Answer. It should be removed or commented out.
    //输出结果 
    while(i--){ // @@ The variable `i` here retains its value from the merging loop. If the merge loop finished normally, `i` might not represent the count of terms. The number of terms is `l2 - e`. Also, since the sort was ascending, iterating backwards `i--` would print descending. However, `i` is unreliable here. It should use the correct count of terms.
        printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}