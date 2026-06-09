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
    }while(ch=getchar()!='\n'); // @@ [Assignment in condition without parentheses causes incorrect logic; should be (ch=getchar())!='\n'. Also, 'ch' is uninitialized on first use.]
    
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
    }while(ch=getchar()!='\n'); // @@ [Same issue: assignment in condition without parentheses; also reuses 'ch' which may not reflect the actual newline after second polynomial input due to leftover characters.]
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
    for(i=0;i<l2-e;i++){
        if(c[i][1]==c[i+1][1]) { // @@ [Accesses c[i+1] when i == l2-e-1, which may be out of bounds if e==0 and i==l2-1.]
            c[i][0]+=c[i+1][0];
            for(j=i;j<l2-e;j++){
                c[j+1][0]=c[j+2][0];
                c[j+1][1]=c[j+2][1];
                
            }
            e++;
            i--;
        }
        
    }
    printf("%d\n",i); // @@ [Prints debug value 'i' which is not part of expected output format.]
    //输出结果 
    while(i--){ // @@ [Uses 'i' after loop, which is now equal to l2-e (or similar), but should output from highest exponent to lowest; however, array was sorted in ascending order, so printing backwards is correct, but 'i' may be incorrect due to prior loop termination condition and modifications. Also, if all terms cancel out, nothing should be printed, but this may print garbage or negative indices.]
        printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}