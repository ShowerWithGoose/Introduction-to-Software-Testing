#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[90000];
long long a1[1000][3];
long long a2[1000][3];
long long ans[1000][3];

int main()
{
    int num_1 = 0;
    int num_2 = 0;
    int all = 0;
    int i = 0;
    int j;
    
    int num = 0;
    int check = 1;
    gets(s);
    while (1) {
        if (isdigit(s[i]))
            num = num*10+s[i]-'0';
        else {
            if (check) {
                num_1++;
                a1[num_1][1] = num;
                num = 0;
                check = 0;
            } else {
                a1[num_1][2] = num;
                num = 0;
                check = 1;
            }
        }
        if (s[i]=='\0')
            break;
        i++;
    }
    i = 0;
    gets(s);

    check = 1;
    while (1) {
        if (isdigit(s[i]))
            num = num*10+s[i]-'0';
        else {
            if (check) {
                num_2++;
                a2[num_2][1] = num;
                num = 0;
                check = 0;
            } else {
                a2[num_2][2] = num;
                num = 0;
                check = 1;
            }
        }
        if (s[i]=='\0')
            break;
        i++;

    }

    




    for (i=1; i<=num_1; i++) {
        for (j=1; j<=num_2; j++) {
            all++;
            ans[all][1] = a1[i][1]*a2[j][1];
            ans[all][2] = a1[i][2]+a2[j][2];
        }
    }

    for (i=1; i<all; i++) {
        for (j=i+1; j<=all; j++) {
            if (ans[i][2]==ans[j][2]) {
                ans[i][1] = ans[i][1]+ans[j][1];
                for (int t=j; t<all; t++) {
                    ans[t][1] = ans[t+1][1];
                    ans[t][2] = ans[t+1][2];
                }
                all--;
                i--;
                break;
            }
        }
    }


    for (i=1; i<all; i++) {
        for (j=1; j<=all-i; j++) {
            if (ans[j][2]<ans[j+1][2]) {
                long long t = ans[j][1];
                ans[j][1] = ans[j+1][1];
                ans[j+1][1] = t;

                t = ans[j][2];
                ans[j][2] = ans[j+1][2];
                ans[j+1][2] = t;
            }
        }
    }
    for (i=1; i<=all; i++) {
        printf("%lld %lld ", ans[i][1], ans[i][2]);
    }



    
    
    return 0;
}



