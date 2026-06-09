#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[1001];
char ans[1001][20];
int ans_1[1001];
int cnt;
int main(){
    FILE *in;
    in = fopen("article.txt", "r");
    int i;
    while(fgets(s,1001,in)!=NULL){
            int l = strlen(s);
            int j = 0;
            for (i = 0; i <l ;i++){
                if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
                {
                    ans[cnt][j] = tolower(s[i]);
                    j++;
                    ans_1[cnt] = 1;
                }
                else {
                    if(j!=0)
                        cnt++;
                    j=0;
                }

        }
    }
    int j;
    for(i = 0; i < cnt-1;i++){
        if(ans_1[i]!=0){
            char temp[20];
            int temp_1;
            for (j = i + 1; j < cnt;j++){
            if(strcmp(ans[i],ans[j])>0){
                strcpy(temp, ans[i]);
                strcpy(ans[i], ans[j]);
                strcpy(ans[j], temp);
                temp_1 = ans_1[i];
                ans_1[i] = ans_1[j];
                ans_1[j] = temp_1;
            }else if(strcmp(ans[i],ans[j])==0){
                ans_1[i] += ans_1[j];
                ans_1[j] = 0;
            }
            }
        }
    }
    for (i = 0; i < cnt;i++){
        if(ans_1[i]!=0){
            printf("%s %d\n", ans[i], ans_1[i]);
        }
    }
    return 0;
}
