def generate_prompt_ds(
    problem_description="",
    reference="",
    error_message=[],
    src_code="",
) -> str:
    if reference:
        reference = f"\nReference Program:\n{reference}"
    if error_message:
        error_type = error_message[0]
        if error_type == "Compilation Error":
            test_case = ""
            buggy_output = error_message[1]
            expected_output = ""
        else:
            test_case = error_message[1]
            buggy_output = error_message[2]
            expected_output = error_message[3]
            if len(buggy_output) > len(expected_output) * 4:
                buggy_output = "Buggy output too long, only showing part of it:\n" + buggy_output[: len(expected_output) * 3] + "..."
        error_message_prompt = f"""\nError type:
{error_type}

Test Case Input:
{test_case}

Buggy Output:
{buggy_output}

Expected Output:
{expected_output}
"""
    prompt = f"""Based on the{" problem description," if problem_description else ""}{" the reference program correctly implemented," if reference else ""}{" the test case inputs that the program failed, the program's output, and the expected output," if error_message else ""} identify the location of the errors in the program below. If you think an error may occur on a particular line, add @@ symbol directly after that line and explain the reason for the error.

{problem_description}
{reference}
{error_message_prompt if error_message else ""}

Source Code:
{src_code}

------
Please directly output the complete annotated source code. Ensure that the number of lines in the source code remains unchanged; do not change the original code structure, formatting, or content in any way, do not cut off any part. This means you should not reformat the code, add or remove newlines, modify spacing, or insert additional comments except for the explicit error markers.
Here is an example:
the original line:
        int a = 1;
the annotated line:
        int a = 1; // @@ [the reason for the error]

**Important:** Enclose your entire source code output in a markdown code block with language specifier "c". That is, start with ```c and end with ```. Do not add any extra text before or after the code block.
    """


    return prompt


def generate_prompt_ds_json(
    problem_description="",
    reference="",
    error_message=[],
    src_code="",
) -> str:
    if reference:
        reference = f"\nReference Program:\n{reference}"
    if error_message:
        error_type = error_message[0]
        if error_type == "Compilation Error":
            test_case = ""
            buggy_output = error_message[1]
            expected_output = ""
        else:
            test_case = error_message[1]
            buggy_output = error_message[2]
            expected_output = error_message[3]
            if len(buggy_output) > len(expected_output) * 4:
                buggy_output = "Buggy output too long, only showing part of it:\n" + buggy_output[: len(expected_output) * 3] + "..."
        error_message_prompt = f"""\nError type:
{error_type}

Test Case Input:
{test_case}

Buggy Output:
{buggy_output}

Expected Output:
{expected_output}
"""
    prompt = f"""Based on the{" problem description," if problem_description else ""}{" the reference program correctly implemented," if reference else ""}{" the test case inputs that the program failed, the program's output, and the expected output," if error_message else ""} identify the location of the errors in the program below.

{problem_description}
{reference}
{error_message_prompt if error_message else ""}

Source Code(At the beginning of each line is the line number of the line):
{src_code}

------
Provide the results following this JSON template:
{{
    "[the line number of the error]": "[the reason for the error]",
    "[the line number of the error]": "[the reason for the error]",
}}
The key is the line number of the potential error. The value is your assessed error likelihood score (a number between 0 and 1).
Ensure only output the JSON content.
    """
    return prompt


def generate_prompt_compile_step_1(
    problem_description="",
    error_message=[],
    src_code="",
) -> str:
    if error_message:
        error_type = error_message[0]
        test_case = error_message[1]
        buggy_output = error_message[2]
        expected_output = error_message[3]
        if len(buggy_output) > len(expected_output) * 3:
            buggy_output = "Buggy output too long, only showing part of it:\n" + buggy_output[: len(expected_output) * 2] + "..."
        error_message_prompt = f"""\nError type:
{error_type}

Test Case Input:
{test_case}

Buggy Output:
{buggy_output}

Expected Output:
{expected_output}
"""
    prompt = f"""Based on the{" problem description," if problem_description else ""}{" the test case inputs that the program failed, the program's output, and the expected output," if error_message else ""} identify the location of the errors in the program below. In the first round of the conversation, please first summarize the information above and output the code snippet where the error is likely to be located.
{problem_description}
{error_message_prompt if error_message else ""}

Source Code(The source code may consist of multiple files. At the beginning of each code snippet, the corresponding file name will be provided):
{src_code}

------
Please directly output the code snippet where the error is likely to be located. When presenting the code snippet, ensure the format matches the input exactly. At the beginning, specify the corresponding file name.
Do not change the original code structure, formatting, or content in any way. This means you should not reformat the code, add or remove newlines, modify spacing, or insert additional comments except for the explicit error markers.
You can omit unimportant lines of code in the output and indicate them with "...".
Here is an example of output:
<file path>
...
    int a = 1;
    int b = 2; 
...
    int f = 5;
...

Ensure that when you skip lines of code, mark them with "..."
"""
    return prompt


def generate_prompt_compile_step_2() -> str:
    prompt = f"""
Based on the code snippet you provided, please identify the location of the error in the code. If you think an error may occur on a particular line, add @@ symbol directly after that line and explain the reason for the error.
Please directly output the complete annotated code snippet you provided. Do not change the original code structure, formatting, or content in any way. This means you should not reformat the code, add or remove newlines, modify spacing, or insert additional comments except for the explicit error markers. Even if a line of code is very long, do not add extra line breaks.
Ensure the format matches the input exactly: At the beginning, specify the corresponding file name.
Do not generate adding additional explanation at the beginning or end.
Here is an example of output:
<file path>
...
    int a = 1; // @@ [the reason for the error]
    int b = 2; 
...
    int f = 5;
...
    """
    return prompt

def generate_prompt_compile_json(
    problem_description="",
    error_message=[],
    src_code="",
) -> str:
    if error_message:
        error_type = error_message[0]
        test_case = error_message[1]
        buggy_output = error_message[2]
        expected_output = error_message[3]
        if len(buggy_output) > len(expected_output) * 3:
            buggy_output = "Buggy output too long, only showing part of it:\n" + buggy_output[: len(expected_output) * 2] + "..."
        error_message_prompt = f"""\nError type:
{error_type}

Test Case Input:
{test_case}

Buggy Output:
{buggy_output}

Expected Output:
{expected_output}
"""
    prompt = f"""Based on the{" problem description," if problem_description else ""}{" the test case inputs that the program failed, the program's output, and the expected output," if error_message else ""} identify the location of the errors in the program below.
{problem_description}
{error_message_prompt if error_message else ""}

Source Code(The source code may consist of multiple files. At the beginning of each code snippet, the corresponding file name will be provided.At the beginning of each line is the line number of the line):
{src_code}

------
Provide the results following this JSON template(Prioritizing lines with the highest likelihood of error first):
{{
    "[file path]": {{
        "[the line number of the error]": "[the reason for the error]",
        "[the line number of the error]": "[the reason for the error]",
    }},
    "[file path]": {{
        "[the line number of the error]": "[the reason for the error]",
        "[the line number of the error]": "[the reason for the error]",
    }},
}}
Ensure only output the JSON content.
"""
    return prompt


def generate_prompt_deflects4j(
    problem_description="",
    function_comment="",
    error_message=[],
    src_code="",
) -> str:
    if error_message:
        test_case = error_message[0]
        error_log = error_message[1]
        if len(error_log) > 8000:
            error_log = "error log  too long, only showing part of it:\n" + error_log[:8000] + "..."
        error_message_prompt = f"""\nError type:
Unit Test Case Content:
{test_case}

Error Log:
{error_log}
"""
    prompt = f"""Based on the{" function_comment," if function_comment else ""}{" the unit test case contents that the program failed, and error log message" if error_message else ""} identify the location of the errors in the code snippet below. If you think an error may occur on a particular line, add @@ symbol directly after that line and explain the reason for the error.

the code snippet comes from the large-scale open-source Java project {problem_description}, and here is the function comment the snippet belongs to. 
{function_comment}
{error_message_prompt if error_message else ""}

Source Code snippet:
{src_code}

------
Please directly output the complete annotated source code. Ensure that the number of lines in the source code remains unchanged; do not change the original code structure, formatting, or content in any way, do not cut off any part. This means you should not reformat the code, add or remove newlines, modify spacing, or insert additional comments except for the explicit error markers.
Here is an example:
the original line:
        int a = 1;
the annotated line:
        int a = 1; // @@ [the reason for the error];
    
**Important:** Enclose your entire source code output in a markdown code block with language specifier "java". That is, start with ```java and end with ```. Do not add any extra text before or after the code block.
    """
    return prompt
