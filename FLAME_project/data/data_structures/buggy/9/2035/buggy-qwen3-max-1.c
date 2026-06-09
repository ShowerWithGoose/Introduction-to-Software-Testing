#include <stdio.h>
#include <stdlib.h>
struct duandian{
    int shu;
    int leftx;
    int lefty;
    int rightx;
    int righty;
};
struct duandian s[110];
int m[300];

int main()
{
    int i, j, k, n, pos, max, xulie;
    int qidianx=1000000, qidiany=100000;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d%d%d", &s[i].leftx, &s[i].lefty, &s[i].rightx, &s[i].righty);
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(s[j].leftx==s[i].rightx&&s[j].lefty==s[i].righty){
                if(s[i].shu==0&&s[j].shu==0){
                    pos++;
                    s[i].shu=pos;
                    s[j].shu=pos;
                }else if(s[i].shu==0&&s[j].shu!=0){
                    s[i].shu=s[j].shu;
                }else if(s[i].shu!=0&&s[j].shu==0){
                    s[j].shu=s[i].shu;
                }else{
                    for(k=0; k<n; k++){
                        if(s[k].shu==s[i].shu){
                            s[k].shu=s[j].shu;
                        }
                    }
                }
            }else if(s[j].rightx==s[i].leftx&&s[j].righty==s[i].lefty){
                if(s[i].shu==0&&s[j].shu==0){
                    pos++;
                    s[i].shu=pos;
                    s[j].shu=pos;
                }else if(s[i].shu==0&&s[j].shu!=0){
                    s[i].shu=s[j].shu;
                }else if(s[i].shu!=0&&s[j].shu==0){
                    s[j].shu=s[i].shu;
                }else{
                    for(k=0; k<n; k++){
                        if(s[k].shu==s[i].shu){
                            s[k].shu=s[j].shu;
                        }
                    }
                }
            }
        }
    }
    pos++;
    for(i=0; i<n; i++){
        if(s[i].shu==0){
            s[i].shu=pos;
            pos++;
        }
    }
    for(i=0; i<n; i++){
        if(s[i].shu>0){
            m[s[i].shu]++;
        }
    }
    for(i=0; i<n; i++){
        if(m[i]>max){ // @@ max is uninitialized, leading to undefined behavior when comparing
            max=m[i];
            xulie=i;
        }
    }
    for(i=0; i<n; i++){
        if(s[i].shu==xulie){ // @@ xulie may be uninitialized if no m[i] > max (which is garbage)
            if(s[i].leftx<qidianx){
                qidianx=s[i].leftx;
                qidiany=s[i].lefty;
            }
        }
    }
    printf("%d %d %d\n", max, qidianx, qidiany); // @@ max and qidianx/qidiany may be based on uninitialized variables
    return 0;
}