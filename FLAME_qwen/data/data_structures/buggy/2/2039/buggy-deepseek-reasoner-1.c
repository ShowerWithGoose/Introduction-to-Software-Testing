#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char c[1002];
int result,po,i,resultre;
int findop_a(int po, int ii) {
    for (po += 1; c[po] != '\0'; po++) {
        if (c[po] == '*' && po == ii) { // @@ the condition is logically flawed; it compares the index of the operator with the end index of the second number, which will never be true, causing the function to never handle consecutive operators correctly.
            int after = 0;
            for ( ii = po + 1; c[ii] > '0' - 1 && c[ii] < '9' + 1; ii++) {
                after = after * 10 + c[ii] - '0';
                c[ii] = ' ';
            }result =result* after;
            c[po] = ' ';
            i = ii;
            return 1;
        }
        else if (c[po]=='/'&&po==ii) { // @@ same flawed condition as above; prevents correct chaining of division operations.
            int after = 0;
            for (ii = po + 1; c[ii] > '0' - 1 && c[ii] < '9' + 1; ii++) {
                after = after * 10 + c[ii] - '0';
                c[ii] = ' ';
            }result = result / after;
            c[po] = ' ';
            i = ii;
            return 1;
        }
    }return 0;
}
int findop(char operator,char c[]) {
    po = 0, i = 0,result=0;
    int before = 0, after = 0, k, flag = 0,lo;
    for (; c[po] != '\0'; po++) {
        if (c[po] == operator) { flag=1; break; }
    }if (flag) {
        for (i = po + 1; c[i] > '0' - 1 && c[i] < '9' + 1; i++) {
            after = after * 10 + c[i] - '0';
            c[i] = ' ';
        }for ( k = po - 1, lo=0; c[k] > '0' - 1 && c[k] < '9' + 1; k--,lo++) { // @@ after decrementing k, it may become negative and access c[-1] (out‑of‑bounds), causing undefined behavior.
            if (k == po - 1)before = before + (c[k] - '0');
            else before = before + (c[k] - '0') * pow(10,lo);
            c[k] = ' ';
        }c[po] = ' ';
        if (operator=='*') {
            result = before * after;
            if (c[k] == '-')result*= -1; // @@ k now points before the first digit; it may be an invalid index or a non‑sign character, leading to incorrect negation.
            c[k] = ' ';
            while (findop_a(po, i));    
            resultre += result;
            return 1;
        }
        else if (operator=='/') {
            result = before / after;
            if (c[k] == '-')result*= -1; // @@ same invalid index issue as above.
            c[k] = ' ';
            while (findop_a(po, i));
            resultre += result;
            return 1;
        }
    }
    else return 0;
}

int main() {
        int i = 0;
        do {
            scanf("%c", &c[i++]);
            if (c[i - 1] == ' ')i--;
            else if (c[i - 1] == '=')break;
        } while (1);
        c[i] == '\0'; // @@ uses comparison instead of assignment; the string is not null‑terminated, causing subsequent loops to read beyond the input.
        while(findop('*', c));
        while (findop('/', c));
        for (int i = 0; c[i] != '='; i++) {
            int add = 0;
            if (c[i] == ' ')continue;
            else if (c[i] == '-') {
                for (int k = i + 1; c[k] > '0' - 1 && c[k] < '9'+1; k++) {
                    
                        if (c[k] == '='){
                            i++;
                            break;
                    }
                    add = add * 10 + c[k] - '0';
                    c[k] = ' ';
                    i++;
                }resultre += (-1) * add;
            }
            else if (i == 0) {
                for (int k = i ; c[k] < '9' + 1 && c[k]>'0' - 1 ; k++) {
                    if (c[k] == '=') {
                        i++;
                        break;
                    }
                    add = add * 10 + c[k] - '0';
                    c[k] = ' ';
                    i++;
                }resultre += add;
            }
            else {
                for (int k = i + 1; c[k] < '9' + 1 && c[k]>'0' - 1 ; k++) {
                    if (c[k] == '=') {
                        i++;
                        break;
                    }
                    add = add * 10 + c[k] - '0';
                    c[k] = ' ';
                    i++;
                }resultre += add;
            }i--;
        }
        printf("%d", resultre);
        return 0;
}