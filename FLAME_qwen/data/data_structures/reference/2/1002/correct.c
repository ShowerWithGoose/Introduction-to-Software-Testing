#include <stdio.h>
#include <string.h>
void dspc(char s[]){
    int i,n= strlen(s),j;
    char t[2005];
    for(i=0;i<n;i++) t[i]=s[i];
    for( i=0,j=0;i<n;i++,j++) {
        if (s[i] == ' ' || t[j] == ' ')
        {
            while (t[j] == ' ') j++;
            s[i] = t[j];
        }

        else s[i]=t[j];
}
}
void readnumb( char a[],int b[]){
    int i=0,n= strlen(a),j=0;
    while(i<n)
    {
        if(a[i]<='9'&&a[i]>='0')
        {
        b[j]=a[i]-'0';
        i++;
        while (a[i] <='9'&&a[i] >= '0')
        {
        b[j]=b[j]*10+a[i++]-'0';
        }
         j++;
        }
       else i++;
}
}
int cu(int a,int b,char c) {
    switch (c) {
        case '+' :
            return a + b;
        case '-' :
            return a - b;
        case '*' :
            return a * b;
        case '/' :
            return a / b;
    }
}
int main() {
    char str[2005];
    gets(str);
    dspc(str);
    int numb[2005] = {}, i, k = 0;
    readnumb(str, numb);
    char sign[2005];
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, ans = 0;
    for (i = 0; str[i] != '='; i++) {
        if (str[i] < '0')
            switch (str[i]) {
                case '+' :
                    n1++, sign[k++] = str[i];
                    break;
                case '-' :
                    n2++, sign[k++] = str[i];
                    break;
                case '*' :
                    n3++, sign[k++] = str[i];
                    break;
                case '/' :
                    n4++, sign[k++] = str[i];
                    break;
            }
    }
    if (n3 + n4 == 0) {
        ans = numb[0];
        for (i = 0; i < strlen(sign); i++)
            ans = cu(ans, numb[i + 1], sign[i]);
        printf("%d", ans);
    } else {
        int fg = 0;
        i = 0, k = 0;
        int new[2005] = {};
        char nsign[2005];
        for (i = 0; i < strlen(sign); i++)
        {
            if(sign[i]=='*'||sign[i]=='/')
            {
                if(fg==0) fg=1,new[k]=numb[i];
                new[k]=cu(new[k],numb[i+1],sign[i]);
            }
            else
            {
                nsign[k]=sign[i];
                if(fg==0) new[k]=numb[i],k++;
                else new[++k]=numb[i+1],fg=0;
            }
        }
        ans = new[0];
        for (i = 0; i < strlen(nsign); i++)
            ans = cu(ans, new[i + 1], nsign[i]);
        printf("%d", ans);
    }


    return 0;
}

