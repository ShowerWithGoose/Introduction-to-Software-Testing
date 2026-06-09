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
                ++i; // Increment i to skip the end character@@ [This skips only the '-', but the next character (end) will be processed again in the next loop iteration, causing duplication. The correct behavior is to skip both '-' and the 'end' character since it's already accounted for in the expansion. However, in this implementation, the 'end' character is never appended because the loop moves past '-' but not past 'end', and then the main loop increments i again, so 'end' gets skipped entirely — which is actually correct for expansion (e.g., a-d becomes abcd, so 'd' must appear). But in the test case "a-uB-F", after expanding 'a-u', the 'u' should appear at the end of that expansion. However, the current code does NOT output the 'end' character at all. The expansion writes from start+1 to end-1, so 'u' is missing. Similarly, after expanding B-F, 'F' is missing. Hence, the bug is that the expanded range excludes the 'end' character, but the original 'end' character is also skipped due to extra i increment, so it never gets added. The fix would be to NOT skip the end character here, or to include it in expansion. But per problem, a-d expands to abcd — so 'd' must be included. However, the expansion loop only goes up to c < end, so 'd' is not written. And because we do ++i here (skipping '-'), and then the main loop does ++i again, we skip the 'end' character entirely. So the 'end' character is lost.]
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
    
  
    fgets(input, sizeof(input), stdin); // Read input from the keyboard@@ [fgets includes the newline character '\n' in the input buffer if there's space, which may interfere with processing. The reference program uses gets(), which discards the newline. This could cause the last character before '\n' to be treated incorrectly if followed by '-', or the '\n' itself might break expansion logic. However, in the given test case "a-uB-F", the newline would be at the end and likely not affect the core issue. The primary error is in the expansion logic, not input reading.]

    expandString(input, output);
    
    printf("%s\n", output);

    return 0;
}