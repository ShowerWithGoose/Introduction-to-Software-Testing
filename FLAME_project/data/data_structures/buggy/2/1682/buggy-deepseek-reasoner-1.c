int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k; // @@ [k is uninitialized; leads to undefined behavior]
    gets(s);
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           // @@ [loop increment conflicts with manual i++ inside while, causing characters to be skipped] //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [k is uninitialized; this uses garbage index]
            while(s[i+1]>='0'&&s[i+1]<='9'){ // @@ [manual i++ inside while causes for loop to skip characters]
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [this line sets num[k] to 0 (as '\0') on every loop iteration, corrupting the array; also uses k after increment]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                // @@ [loop does not skip processed operators and extra i++ inside loop causes skipping] //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [assumes alignment but loop skips operators; also uses num indices that may be out of range]
            num[i]=' '; // @@ [using ASCII space character (32) as sentinel is fragile; numbers can be 32]
            i++; // @@ [extra increment causes the for loop to skip the next operator]
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [assumes alignment but loop skips operators; also uses num indices that may be out of range]
            num[i]=' '; // @@ [using ASCII space character (32) as sentinel is fragile; numbers can be 32]
            i++; // @@ [extra increment causes the for loop to skip the next operator]
        }
    }
    for(j=0,i=0;i<k;i++){           // @@ [k is original number count but array size changed due to sentinel removal; may cause out-of-bounds or missing numbers] //清除空格
        if(num[i]!=' ')
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [setting integer to '\0' is unnecessary and may cause issues]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           // @@ [fuh still contains all operators including * and /; should only process remaining + and -] //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [j is incremented only for + and -, leading to mismatched indices; also num array may not correspond to operator sequence]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [j is incremented only for + and -, leading to mismatched indices; also num array may not correspond to operator sequence]
    }
    printf("%d",an);
    return 0;
}