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
    }while(ch=getchar()!='\n'); // @@ Operator precedence error: should be (ch=getchar())!='\n'; also this may read spaces instead of newline incorrectly.
    
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
    }while(ch=getchar()!='\n'); // @@ Same operator precedence error. Also the loop logic may cause extra iterations due to spaces.
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
            if(c[j][1]>c[j+1][1]){
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
    for(i=0;i<l2-e;i++){ // @@ Loop bound and shifting logic are incorrect. The array size changes during merging, and the shifting code accesses out-of-bounds indices (c[j+2]).
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
    printf("%d\n",i); // @@ This prints the loop variable i which after the loop is not the correct number of terms; it prints the value that caused loop termination, which is l2-e. But after merging, the correct count is l2-e, but printing it is redundant and may cause confusion.
    //输出结果 
    while(i--){ // @@ The while loop uses the value of i from the previous printf, which is l2-e, but the merging loop may have skipped some terms due to faulty shifting. Also the loop prints terms from index i-1 down to 0, which assumes the array is contiguous and correctly sized, but due to errors in merging it may not be.
        printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}