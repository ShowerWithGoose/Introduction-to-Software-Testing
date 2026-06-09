#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ 错误：&a类型为char (*)[200]，与scanf期望的char*不匹配，应改为scanf("%s", a);
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){ // @@ 错误：未考虑输入无小数点的情况，若没有小数点，循环会越界或死循环
        zheng++;
    }
    printf("%d.",a[0]-'0');
    
    for(int i=1;i!=strlen(a);i++){
        if(a[i]!='.'){
            printf("%d",a[i]-'0');
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ 错误：缺少循环终止条件，可能越界；应添加字符串结束判断
            if(a[i]==0){ // @@ 错误：用a[i]==0检测字符串结束符，但目的是跳过前导零，应改为a[i]=='0'；且逻辑错误，若遇'\0'不应增加xiao
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0');
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){
            printf("%d",a[j]-'0'); // @@ 错误：应输出a[i]而非a[j]，导致重复输出同一数字
        }
        printf("e-%d",xiao);
    }
    

    return 1;
 }