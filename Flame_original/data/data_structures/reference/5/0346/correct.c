//非链表
#include<stdio.h>
#include<string.h>
char s1[1001];
char s2[1001];
char temp[1001];
struct number{
    int xishu;
    int mi;
};
int cnt;
int n1;
int n2;
struct number x1[101];
struct number x2[101];
struct number ans[10001];
int main(){
    char c;
    int i = 0;
    do{
        scanf("%d%d%c", &x1[i].xishu, &x1[i].mi, &c);
        i++;
    } while (c != '\n');
    n1 = i ;
    i = 0;
    do{
        scanf("%d%d%c", &x2[i].xishu, &x2[i].mi, &c);
        i++;
    } while (c != '\n');
    n2 = i ;
    int j;
    for (i = 0; i < n1-1;i++){
        for (j = i+1; j < n1; j++)
        {
            struct number temp;
            if(x1[i].mi < x1[j].mi){
                temp = x1[i];
                x1[i] = x1[j];
                x1[j] = temp;
            }
        }
    }
    for (i = 0; i < n2-1;i++){
        for (j = i+1; j < n2; j++)
        {
            struct number temp;
            if(x2[i].mi < x2[j].mi){
                temp = x2[i];
                x2[i] = x2[j];
                x2[j] = temp;
            }
        }
    }
    for (i = 0; i < n1;i++){
        for (j = 0; j < n2;j++){
            ans[cnt].xishu = x1[i].xishu * x2[j].xishu;
            ans[cnt].mi = x1[i].mi+x2[j].mi;
            cnt++;
        }
    }
    for (i = 0; i < cnt-1;i++){
        for (j = i+1; j < cnt; j++)
        {
            struct number temp;
            if(ans[i].mi < ans[j].mi){
                temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
    }
    for (i = 0; i < cnt-1;i++){
        if(ans[i].mi==ans[i+1].mi){
            ans[i + 1].xishu+=ans[i].xishu;
            ans[i].xishu = 0;
        }
    }
    for (i = 0; i < cnt;i++){
        if(ans[i].xishu!=0)
        printf("%d %d ", ans[i].xishu, ans[i].mi);
    }
    return 0;
}
