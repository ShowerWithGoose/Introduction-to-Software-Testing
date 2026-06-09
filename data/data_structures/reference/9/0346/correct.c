#include<stdio.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct line s[101];
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for (i=0;i<n;i++){
        scanf("%d%d%d%d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
    }
    for (i = 0; i < n-1;i++){
        int j;
        struct line temp;
        for (j = i + 1; j < n;j++){
            if(s[i].x1>s[j].x1){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    int cnt_max = 0;
    int reserve=0;
    int j;
    for (i=0;i<n;i++){
        int cnt = 0;
        int k=i;
        for (j=0;j<n;j++){
            if(j==i||j==k)
                continue;
            if(s[k].x2==s[j].x1&&s[k].y2==s[j].y1){
                cnt++;
                k=j;
                j=0;
            }
        }
        if(cnt>cnt_max){
            cnt_max = cnt;
            reserve = i;
        }
    }
    printf("%d %d %d", cnt_max+1, s[reserve].x1, s[reserve].y1);
    return 0;
}
