#include <stdio.h>

int main() {

    int a[200][5]= {{0}},b[5]= {0},i,j,k,n,m=0,t[200][4]= {{0}};
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    for(i=0; i<n; i++) {
        b[0]=a[i][0],b[1]=a[i][1],b[2]=a[i][2],b[3]=a[i][3];
        for(j=i+1; j<n; j++) {
            if(a[j][0]==b[2]&&a[j][1]==b[3]) {
                t[i][0]++;
                b[2]=a[j][2],b[3]=a[j][3];
                j=0;
            }
            if(a[j][3]==b[1]&&a[j][2]==b[0]) {
                t[i][0]++;
                b[0]=a[j][0],b[1]=a[j][1];
                j=0;
            }
        }
        t[i][1]=b[0],t[i][2]=b[1];
    }
    for(i=0; i<n; i++) {
        if(t[i][0]>m)
            k=i,m=t[i][0];
    }
    printf("%d %d %d",t[k][0]+1,t[k][1],t[k][2]);

    return 0;
}
