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
    }while(ch=getchar()!='\n'); // @@ [Assignment in condition without parentheses causes incorrect logic: 'ch=getchar()!='\n'' is parsed as 'ch=(getchar()!='\n')', so ch becomes 0 or 1, not the actual character. Also, first getchar() may read leftover newline from previous input, causing premature loop exit.]

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
    }while(ch=getchar()!='\n'); // @@ [Same error as above: assignment precedence issue leads to incorrect loop termination condition.]

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
        if(c[i][1]==c[i+1][1]) { // @@ [Accessing c[i+1] when i == l2-e-1 leads to out-of-bounds read if e=0 and i=l2-1, which is undefined behavior.]
            c[i][0]+=c[i+1][0];
            for(j=i;j<l2-e;j++){
                c[j+1][0]=c[j+2][0];
                c[j+1][1]=c[j+2][1];
                
            }
            e++;
            i--;
        }
        
    }
    printf("%d\n",i); // @@ [This prints an internal loop variable 'i' which is not part of expected output; problem requires only polynomial terms. Also, after loop, i equals l2-e (or similar), which is meaningless.]

    //输出结果 
    while(i--){ // @@ [After previous loop, 'i' is already at boundary (e.g., l2-e), and this loop runs backward from that value, but merged array size is l2-e, and indices may be invalid. Also, if result is zero polynomial, nothing should print, but this may print garbage. Additionally, output order is ascending due to prior sort, but problem requires descending order.]
        printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}