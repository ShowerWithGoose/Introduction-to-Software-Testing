#include <stdio.h>

void expandString(char *input, char *output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (input[i] == '-' && i > 0 && input[i + 1] != '\0') {
            char start = input[i - 1];
            char end = input[i + 1];
            
            // Check if both characters surrounding the '-' are valid for expansion
            if (((start >= 'a' && start <= 'z') && (end >= 'a' && end <= 'z') && end > start) ||
                ((start >= 'A' && start <= 'Z') && (end >= 'A' && end <= 'Z') && end > start) ||
                ((start >= '0' && start <= '9') && (end >= '0' && end <= '9') && end > start)) {
                for (char c = start + 1; c < end; ++c) {
                    output[j++] = c;
                }
                ++i; // Increment i to skip the end character@@ [This skips only the '-', but the next character (end) will be processed again in the next loop iteration, causing duplication. The correct approach is to skip both '-' and the end character, but since the loop always increments i at the end, we should not increment i here. Instead, we should let the final ++i handle moving past the '-', and then skip the end character by incrementing i once more. However, in this code, after expanding, it does ++i here and then another ++i at the end of the loop, so it skips two characters: the '-' and the end. But that causes the end character not to be appended, which is correct per problem requirements. However, the real issue is that the end character itself should NOT be output because it's already implied by the range. But in the test case "a-uB-F", after expanding 'a-u', the 'u' should appear as the last character of the expansion. However, the current logic outputs from start+1 to end-1, and does not output the 'end' character anywhere. But according to the example, "a-d" becomes "abcd", meaning the 'd' IS included. So the expansion should include the 'end' character. However, looking at the reference program: it expands a-d by outputting from start+1 up to end-1, and relies on the fact that the 'end' character will be processed later as a normal character. But in this buggy program, after expansion, it skips the end character (by doing ++i here and then ++i again), so the 'end' character is never appended. That's the bug.]
            } else {
                output[j++] = input[i];
            }
        } 
        else 
        {
            output[j++] = input[i];
        }
        ++i; // Increment i for the next character
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char input[100];
    char output[200]; // Assuming the output can be twice the length of input for expansion
    
  
    fgets(input, sizeof(input), stdin); // Read input from the keyboard@@ [fgets includes the newline character in the input string if there's space, which may interfere with processing. The reference program uses gets(), which discards the newline. This could cause issues if the input ends with a newline and there's a trailing '-' or other pattern involving the newline. However, in the given test case "a-uB-F", the newline would be at the end and likely not affect the result. The main bug is in the expansion logic, not the input reading.]

    expandString(input, output);
    
    printf("%s\n", output);

    return 0;
}