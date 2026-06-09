# Utility to compile and run C programs for data structures course
from typing import List
import os
import shutil
import subprocess
import tempfile

import chardet



def compile_run(
    file_path: str, test_cases: List[str], expected_outputs: List[str], input_src="stdin"
):
    """
    Compile and run a C program for data structures course.
    """

    tmp_dir = tempfile.mkdtemp()
    try:
        # 所有原有逻辑不变
        shutil.copy(file_path, tmp_dir)
        file_name = os.path.basename(file_path)
        origin_cwd = os.getcwd()
        os.chdir(tmp_dir)
        command = f"gcc -std=c11  -g -O0 -lm {file_name} -o {tmp_dir}/buggy.out"
        res = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if res.returncode != 0:
            encoding = chardet.detect(res.stderr)["encoding"]
            if encoding is None:
                encoding = "utf-8"
            err_str = res.stderr.decode(encoding=encoding, errors="ignore")
            error_message = ["Compilation Error", err_str]
            os.chdir(origin_cwd)
            return error_message
        for i, test_case in enumerate(test_cases):
            if input_src == "stdin":
                test_case_input = test_case.encode()
            else:
                with open(input_src, "w") as f:
                    f.write(test_case)
                test_case_input = ""
            try:
                res = subprocess.run(
                    [f"./buggy.out"],
                    input=test_case_input,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    timeout=3,
                )
            except subprocess.TimeoutExpired:
                error_message = ["Time Limit Exceeded", test_case, "", expected_outputs[i]]
                break
            if res.returncode != 0:
                encoding = chardet.detect(res.stderr)["encoding"]
                if encoding is None:
                    encoding = "utf-8"
                err_str = res.stderr.decode(encoding=encoding, errors="ignore")
                error_message = [
                    "Runtime Error",
                    test_case,
                    err_str,
                    expected_outputs[i],
                ]
                break
            encoding = chardet.detect(res.stdout)["encoding"]
            if encoding is None:
                encoding = "utf-8"
            output_str = res.stdout.decode(encoding=encoding, errors="ignore").rstrip()
            if output_str != expected_outputs[i].rstrip():
                error_message = [
                    "Wrong Answer",
                    test_case,
                    output_str,
                    expected_outputs[i],
                ]
                break
    finally:
        shutil.rmtree(tmp_dir, ignore_errors=True)

    error_message = None

    os.chdir(origin_cwd)
    return error_message
