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

    gets(cal_in); // @@ [Using `gets` is unsafe and may be undefined in some environments; however, the actual compilation error is due to missing definition of `main` during linking, which suggests the file might not have been compiled correctly or there's a mismatch in function signature. But given the linker error "undefined reference to `main`", it usually means the compiler didn't find a `main` function — however, here `main` is defined. This specific linker error in the test environment likely stems from using `gets` which has been removed in newer C standards (C11+), causing the compilation to fail silently or the object file to be invalid. Replacing `gets` with `fgets` would fix portability and safety, but the immediate cause of the *linker* error is unusual. However, since the error message says "undefined reference to `main`", and `main` is present, the real issue might be that the code wasn't compiled as C (e.g., compiled as C++ where `gets` doesn't exist and causes failure), but per problem context, the use of `gets` is deprecated and may lead to build failures in strict environments.]

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