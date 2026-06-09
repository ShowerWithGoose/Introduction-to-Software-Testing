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
    }while(ch=getchar()!='\n'); // @@ [The condition `ch=getchar()!='\n'` assigns the result of comparison to `ch`, not the character. Should be `(ch=getchar())!='\n'`. This causes incorrect loop termination and may skip or misread input.]
    
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
    }while(ch=getchar()!='\n'); // @@ [Same error as above: missing parentheses around assignment. Causes incorrect input reading for second polynomial.]
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
        if(c[i][1]==c[i+1][1]) { // @@ [When `i == l2 - e - 1`, `c[i+1]` accesses out-of-bounds memory, leading to undefined behavior. Loop condition should be `i < l2 - e - 1`.]
            c[i][0]+=c[i+1][0];
            for(j=i;j<l2-e;j++){
                c[j+1][0]=c[j+2][0];
                c[j+1][1]=c[j+2][1];
                
            }
            e++;
            i--;
        }
        
    }
    printf("%d\n",i); // @@ [This prints an unintended debug value `i` which is not part of expected output, causing Wrong Answer. Should be removed.]
    //输出结果 
    while(i--){ // @@ [`i` here is the loop variable from previous block, which ends at `l2 - e` (or similar), not the number of terms after merging. Also, output should be in descending order, but array was sorted in ascending order, so printing backwards is correct in intent, but `i` is wrong. Should use `e` or proper term count. Moreover, if no terms remain, this may print nothing or garbage.]
        printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}