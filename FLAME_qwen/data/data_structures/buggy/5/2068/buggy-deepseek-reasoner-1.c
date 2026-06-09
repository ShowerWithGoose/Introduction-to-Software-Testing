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
    }while(ch=getchar()!='\n'); // @@ Operator precedence: '!=' higher than '=', so ch gets boolean (0 or 1) instead of character; getchar character lost, but loop still works for simple newline detection? However, this is error-prone and may cause incorrect input reading if there are spaces.
    
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
    }while(ch=getchar()!='\n'); // @@ Same operator precedence issue as above.
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
        if(c[i][1]==c[i+1][1]) { // @@ Potential out-of-bounds access when i = l2-e-1, because c[i+1] is beyond the valid range.
            c[i][0]+=c[i+1][0];
            for(j=i;j<l2-e;j++){
                c[j+1][0]=c[j+2][0]; // @@ Accessing c[j+2] may go out of bounds when j = l2-e-1 or j = l2-e-2.
                c[j+1][1]=c[j+2][1]; // @@ Same out-of-bounds issue.
                
            }
            e++;
            i--;
        }
        
    }
    printf("%d\n",i); // @@ This prints the loop variable i, which is not the correct number of terms; this is an extra output not expected in the problem.
    //输出结果 
    while(i--){ // @@ i is not set to the number of terms; the loop will likely print incorrect indices.
        printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}