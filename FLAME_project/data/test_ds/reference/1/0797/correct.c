#include <stdio.h>
#include <string.h>

char out[100];
int main() {
    char in[100];
    scanf("%s", in);
    char *p;
    int start, stop, cnt, k;

    int i = 0;
    for(p = in; (*p)!='\0'; p++){
        if(*(p+1)=='-'){
            if((*p >= '0' && *p <= '9')&&(*(p+2) >= '0' && *(p+2) <= '9')&&(*(p+2) > *p)){
                char num[10];
                start = *p, stop = *(p+2);
                cnt = stop - start;
                for(k = 0; k < cnt; k++)
                    num[k] = k+start;
                num[k] = '\0';
                strcat(out, num);
                i+=cnt;
                p++;
            }
            else if((*p >= 'a' && *p <= 'z')&&(*(p+2) >= 'a' && *(p+2) <= 'z')&&(*(p+2) > *p)){
                char lowercase[30];
                start = *p, stop = *(p+2);
                cnt = stop - start;
                for(k = 0; k < cnt; k++)
                    lowercase[k] = k+start;
                lowercase[k] = '\0';
                strcat(out, lowercase);
                i+=cnt;
                p++;
            }
            else if((*p >= 'A' && *p <= 'Z')&&(*(p+2) >= 'A' && *(p+2) <= 'Z')&&(*(p+2) > *p)) {
                char cap[30];
                start = *p, stop = *(p+2);
                cnt = stop - start;
                for(k = 0; k < cnt; k++)
                    cap[k] = k+start;
                cap[k] = '\0';
                strcat(out, cap);
                i+=cnt;
                p++;
            }
            else
                out[i++] = *p;
        }
        else
            out[i++] = *p;
    }
    printf("%s", out);
    return 0;
}



