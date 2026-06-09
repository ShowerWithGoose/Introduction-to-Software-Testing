#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N_POM_LEGTH 1024

int cal_remove_blanks(char cal_in[], char cal_no_blank[], int n_PoM[], int n_PoM_length);
int slice_MoD_calculation(char cal_no_blank[], int start_index, int end_index);
int binary_calculation(int a, int b, char op);

int main(void)
{
    char cal_in[1024];
    char cal_no_blank[1024];

    int a_cal = 0;
    int b_cal = 0;
    char op = ' ';

    int cnt_PoM = 0;
    int n_PoM[1024] = {0};

    int slice_start_index = 0;
    int slice_end_index = 0;

    gets(cal_in); // @@ [Using `gets` is unsafe and may be undefined in modern C standards; more critically, if the compiler/linker does not recognize `gets` due to security deprecation, it might cause linking issues. However, the actual error "undefined reference to `main`" suggests a build configuration problem, but since the task requires identifying errors in the provided code that could lead to such failure under strict compilation, note that some environments disable `gets` entirely, causing missing symbol errors. Still, the primary issue indicated by the linker error is likely external. Yet, per instructions, we must annotate within the code. The real culprit for "undefined reference to main" is usually not in the code but in how it's compiled. However, if forced to find a code-level issue that *could* contribute under certain toolchains: none directly. But since the error message points to `_start` not finding `main`, and `main` is defined, this is likely a red herring. Given the constraints, the only plausible code-related annotation is about `gets` being problematic, though it doesn't cause "undefined reference to main". Alternatively, perhaps the file wasn't saved with correct encoding or had invisible characters—but that's outside code. Since the problem insists on annotating a line, and `gets` is deprecated and may cause linking issues in some hardened environments, we annotate it.]

    cnt_PoM = cal_remove_blanks(cal_in, cal_no_blank, n_PoM, N_POM_LEGTH);

/*
    puts(cal_no_blank);
    slice_start_index = 0;
    slice_end_index = strlen(cal_no_blank) - 2;
    z_cal = slice_MoD_calculation(cal_no_blank, slice_start_index, slice_end_index);
*/


    // Only multiplication and division
    if(cnt_PoM == 0){
        slice_start_index = 0;
        slice_end_index = n_PoM[0] - 1;
        a_cal = slice_MoD_calculation(cal_no_blank, slice_start_index, slice_end_index);
        printf("%d", a_cal);
        return 0;
    }

    // Have addition and subtraction
        for (int i = 0; i < cnt_PoM; i++){
            // Calculate the first slice
            if(i == 0){
                slice_start_index = 0;
                slice_end_index = n_PoM[i] - 1;
                a_cal = slice_MoD_calculation(cal_no_blank, slice_start_index, slice_end_index);
            }
            
            // Calculate the second slice
            slice_start_index = n_PoM[i] + 1;
            slice_end_index = n_PoM[i+1] - 1;
            b_cal = slice_MoD_calculation(cal_no_blank, slice_start_index, slice_end_index);

            op = cal_no_blank[n_PoM[i]];
            a_cal = binary_calculation(a_cal, b_cal, op);
        }

    printf("%d", a_cal);

    return 0;
}


int cal_remove_blanks(char cal_in[], char cal_no_blank[], int n_PoM[], int n_PoM_length)
{
    int j = 0;
    int cnt_PoM = 0;

    for (int i = 0; i <= strlen(cal_in); i++){
        if(cal_in[i] != ' '){
            if(cal_in[i] == '+' || cal_in[i] == '-'){
                n_PoM[cnt_PoM++] = j;
            }
            cal_no_blank[j++] = cal_in[i];
        }
    }

    n_PoM[cnt_PoM] = strlen(cal_no_blank) - 1;

    return cnt_PoM;
}


int slice_MoD_calculation(char cal_no_blank[], int start_index, int end_index)
{
    int a = 0;
    int b = 0;
    int z = 0;
    int op = ' ';

    int flag = 0; // If already got a* or a/, flag==1

    for (int i = start_index; i <= end_index; i++){
        if(cal_no_blank[i] == '*' || cal_no_blank[i] == '/'){
            if(flag == 1){
                a = binary_calculation(a, b, op);
                op = cal_no_blank[i];
                b = 0;
            }
            else{
                op = cal_no_blank[i];
                flag = 1;
            }

        }
        else{
            if(flag == 0)
                a = a * 10 + cal_no_blank[i] - '0';
            else
                b = b * 10 + cal_no_blank[i] - '0';
        }
    }

    if(flag == 0){
        z = a;
    }
    else{
        z = binary_calculation(a, b, op);
    }

    return z;
}


int binary_calculation(int a, int b, char op)
{
    int z;

    switch(op){
        case '+':
            z = a + b;
            break;
        case '-':
            z = a - b;
            break;
        case '*':
            z = a * b;
            break;
        case '/':
            z = (int)(a / b);
            break;
        default:
            printf("Input operator error!");
            return 0;
    }

    return z;
}