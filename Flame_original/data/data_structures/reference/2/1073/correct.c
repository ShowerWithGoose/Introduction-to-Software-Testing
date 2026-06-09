#include<stdio.h>

char fml[1000];

int signal (int sig)
{
	int sig1 = 0;
	if (sig == '+') sig1 = 1 ;
    else if (sig == '-') sig1 = 2 ;
    else if (sig == '*') sig1 = 3 ;
    else if (sig == '/') sig1 = 4 ;
    return sig1 ;
} 

int main()
{
    
    int i = 0 , k = 0 , j = 0 , flag = 0 , flag1 = 0 , sign = -1;
    int num = 0 , num1 = 0 , num2 = 0;
    gets(fml);
    while (fml[k] != '=') {//ееЁЩ©у╦Я 
        if (fml[k] != ' ') fml[j++] = fml[k];
        k++;
    }
    fml[j] = '=';
	fml[j+1] = '\0';
    while (fml[i] <= '9' && fml[i] >= '0') {
            num *= 10;
            num += fml[i] -'0';
            i++;
    }
    flag = signal (fml[i]) ;
    if (fml[i] == '=') {
        printf ("%d" , num) ;
        return 0 ;
    }
    if (flag == 1 || flag == 2) sign = 2;
    if (flag == 3 || flag == 4) sign = 4;
    i++;
    while (fml[i] <= '9' && fml[i] >= '0') {
        num1 *= 10;
        num1 += fml[i] -'0';
        i++;
    }
	flag1 = signal (fml[i]) ;
    if (fml[i] == '=') {
        switch (flag) {
            case 1: 
                num += num1;
                break;
            case 2: 
                num -= num1;
                break;
            case 3: 
                num *= num1;
                break;
            case 4: 
                num /= num1;
                break;
        }
        printf ("%d", num) ;
        return 0 ;
    }
    i++;
    while (fml[i] != '=') {
        while (fml[i] <= '9' && fml[i] >= '0') {
            num2 *= 10;
            num2 += fml[i] - '0';
            i++;
        }
        if (fml[i] == '=') break;
        if (flag1 <= sign) {
            switch (flag) {
                case 1: 
                    num += num1 ;
                    break ;
                case 2: 
                    num -= num1 ;
                    break ;
                case 3: 
                    num *= num1 ;
                    break ;
                case 4: 
                    num /= num1 ;
                    break ;
            }
            num1 = num2 ;
            flag = flag1 ;
            if (flag == 1 || flag == 2) sign = 2 ;
        	if (flag == 3 || flag == 4) sign = 4 ;
        }
        else switch (flag1) {
            case 3: 
                num1 *= num2 ;
                break;
            case 4: 
                num1 /= num2 ;
                break;
        }
        num2 = 0 ;
        flag1 = signal (fml[i]) ;
        i++;
    }
    if (flag == 1 || flag == 2) sign = 2;
    if (flag == 3 || flag == 4) sign = 4;
    if (flag1 <= sign){
    	switch (flag) {
        	case 1: 
				num += num1;
				break;
            case 2: 
				num -= num1;
				break;
            case 3: 
				num *= num1;
				break;
            case 4: 
				num /= num1;
				break;
        }
        switch (flag1) {
            case 1: 
				num += num2;
				break;
            case 2: 
				num -= num2;
				break;
            case 3: 
				num *= num2;
				break;
            case 4: 
				num /= num2;
				break;
        }
            
    }
	else {
       	switch (flag1) {
           	case 3: 
				num1 *= num2;
				break;
        	case 4: 
				num1 /= num2;
				break;
        }
        switch (flag) {
            case 1: 
				num += num1;
				break;
        	case 2: 
				num -= num1;
				break;
    	}
	}
    printf ("%d", num);
    return 0 ;
}

