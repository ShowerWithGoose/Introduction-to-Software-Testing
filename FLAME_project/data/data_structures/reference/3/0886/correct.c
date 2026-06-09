//
//  main.c
//  科学计数法
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>
int main() {
    char s[1001];
    int i, j, k, len, p, p1;
    gets(s);
    len = strlen(s);
    for(i=0;i<len;i++){
        if(s[i]=='.')
            p=i;
    }
    if(p==1){
        if(s[0]=='0'){
            for(j=2;j<len;j++){
                if(s[j]!='0'){
                    p1=j;
                    break;
                }
            }
            if(p1==len-1)
                printf("%ce-%d\n", s[p1], p1-p);
            else{
                printf("%c.", s[p1]);
                for(k=p1+1;k<len;k++)
                    printf("%c", s[k]);
                printf("e-%d\n", p1-p);
            }
        }
        else{
            printf("%se0\n", s);
        }
    }
    else{
        printf("%c.", s[0]);
        for(k=1;k<len;k++){
            if(s[k]!='.')
                printf("%c", s[k]);
        }
        printf("e%d\n", p-1);
    }
    return 0;
}

