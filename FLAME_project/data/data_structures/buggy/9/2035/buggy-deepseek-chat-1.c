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
            m[s[i].shu]++; // @@ [Error: m array index may exceed bounds because s[i].shu can be up to n+pos, but m is only size 300; also m is not initialized to zero, leading to undefined behavior]
        }
    }
    for(i=0; i<n; i++){
        if(m[i]>max){ // @@ [Error: max is uninitialized, so comparison with m[i] is undefined; also i should iterate over possible group IDs, not just up to n]
            max=m[i];
            xulie=i;
        }
    }
    for(i=0; i<n; i++){
        if(s[i].shu==xulie){
            if(s[i].leftx<qidianx){
                qidianx=s[i].leftx;
                qidiany=s[i].lefty;
            }
        }
    }
    printf("%d %d %d\n", max, qidianx, qidiany);
    return 0;
}