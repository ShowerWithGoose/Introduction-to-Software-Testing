#include <stdio.h>
#include <stdlib.h>

int s[105][4];

int main(){
    int n = 0;
    int x = 0;
    int y = 0;
    int flag1 = 0;
    int flag2 = 1;
    int tmp = 0;
    int x2 = 0;
    int y2 = 0;

    scanf("%d",&n);
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < 4; j++){
            scanf("%d",&s[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        x2 = s[i][2];
        y2 = s[i][3];
        flag2 = 1;
        
            for(j = i + 1; tmp < n; tmp++){
                if(x2 == s[j][0] && y2 == s[j][1]){
                    x2 = s[j][2];
                    y2 = s[j][3];
                    flag2 += 1;
                    tmp = 0;
                }
                j += 1;
                if(j >= n){
                    j = 0;
                }  
            }
        
        if(flag2 > flag1){
            x = s[i][0];
            y = s[i][1];
            flag1 = flag2;
            flag2 = 1;
        }
        tmp = 0;
    }
    printf("%d %d %d\n",flag1,x,y);
    return 0;
}
