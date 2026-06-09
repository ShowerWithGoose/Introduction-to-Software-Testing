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
    int i, j, k, n, pos, max, xulie; // @@ uninitialized variables pos and max will cause undefined behavior later
    int qidianx=1000000, qidiany=100000;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d%d%d", &s[i].leftx, &s[i].lefty, &s[i].rightx, &s[i].righty);
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(s[j].leftx==s[i].rightx&&s[j].lefty==s[i].righty){
                if(s[i].shu==0&&s[j].shu==0){
                    pos++; // @@ pos may be garbage; incrementing garbage leads to undefined behavior
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
                    pos++; // @@ same issue with uninitialized pos
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
    pos++; // @@ pos still uninitialized; incrementing garbage
    for(i=0; i<n; i++){
        if(s[i].shu==0){
            s[i].shu=pos;
            pos++; // @@ pos may be out-of-bounds when used as index in m array (m size 300)
        }
    }
    for(i=0; i<n; i++){
        if(s[i].shu>0){
            m[s[i].shu]++; // @@ potential index out-of-bounds if s[i].shu >= 300
        }
    }
    for(i=0; i<n; i++){
        if(m[i]>max){ // @@ max is uninitialized; comparison with garbage
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