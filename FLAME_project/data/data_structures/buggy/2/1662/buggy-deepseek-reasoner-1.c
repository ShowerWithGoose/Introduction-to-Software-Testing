#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal);
    if(cal[1]-'0'==0){ @@ [Hardcoded condition: assumes input starts with two digits and uses specific characters; does not parse the expression.]
        printf("%d",0); @@ [Hardcoded output: returns 0 for specific case instead of computing the expression.]
        return 0; @@ [Premature exit: stops without evaluating the expression correctly.]
    }
    else if(cal[0]-'0'==1){ @@ [Hardcoded condition: assumes first digit is '1' (e.g., "10 + ..."); not general.]
        if(cal[2]-'0'==0){ @@ [Hardcoded condition: assumes third character is '0'; only checks specific input pattern.]
            printf("%d",12000); @@ [Hardcoded output: incorrect for any input except the one guessed.]
            return 0; @@ [Premature exit.]
        }
        else{
            printf("%d",602); @@ [Hardcoded output: matches only a single test case but not all inputs.]
            return 0; @@ [Premature exit.]
        }
    }
    else if(cal[0]-'0'==2){ @@ [Hardcoded condition: assumes first digit is '2'; not general.]
        if(cal[15]=='*'){ @@ [Hardcoded condition: checks a specific character position; not based on actual parsing.]
            printf("%d",24); @@ [Hardcoded output: wrong for most inputs.]
            return 0; @@ [Premature exit.]
        }
        else{
            printf("%d",211); @@ [Hardcoded output: wrong for most inputs.]
            return 0; @@ [Premature exit.]
        }
    }
    
    return 0; @@ [No output for unrecognized inputs; program should compute and print result for any valid expression.]
}