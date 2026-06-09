import os
import json
import tempfile
import multiprocessing
import shutil


from tqdm import tqdm

from util.program_runner_ds import compile_run
from util.program_runner_ct import gcc_compile, compile_java, run_cpp, run_java

from util.config import BUGGY_PATH, PROBLEM_PATH, PROJECT

problem_list = os.listdir(BUGGY_PATH)
problem_list = sorted(os.listdir(BUGGY_PATH))

def generate_ds():
    print("Generating error messages...")
    for problem in problem_list:
        print(f"Processing {problem}")
        buggy_problem_path = os.path.join(BUGGY_PATH, problem)
        test_case_path = os.path.join(PROBLEM_PATH, problem, "TC")
        info_file = os.path.join(PROBLEM_PATH, problem, "info.json")
        if os.path.exists(info_file):
            problem_info = json.load(open(info_file, "r"))
            if "input" in problem_info:
                input_src = problem_info["input"]
        else:
            input_src = "stdin"
        test_cases = []
        expected_outputs = []
        for test_case in sorted(os.listdir(test_case_path)):
            test_case_in_file = os.path.join(test_case_path, test_case, "in.txt")
            with open(test_case_in_file, "r", encoding="utf-8") as f:
                test_cases.append(f.read())
            test_case_out_file = os.path.join(test_case_path, test_case, "out.txt")
            with open(test_case_out_file, "r", encoding="utf-8") as f:
                expected_outputs.append(f.read())
        for student in tqdm(os.listdir(buggy_problem_path)):
            student_path = os.path.join(buggy_problem_path, student)
            buggy_src_file = os.path.join(student_path, "buggy.c")
            if os.path.exists(os.path.join(student_path, "error_message.json")):
                continue
            error_message = compile_run(buggy_src_file, test_cases, expected_outputs, input_src)
            if error_message is None:
                error_message = ["Compilation Error", "compile_run failed (unknown reason)", "", ""]
            # error_message = []    # 用于消融实验
            with open(os.path.join(student_path, "error_message.json"), "w", encoding="utf-8") as f:
                json.dump(error_message, f, ensure_ascii=False, indent=4)


def run_testcase(
    language: str,
    testcase_input_file: str,
    testcase_output_file: str,
    output_file_name: str,
    working_dir: str,
):
    shutil.copy(testcase_input_file, os.path.join(working_dir, "testfile.txt"))
    with open(os.path.join(working_dir, "testfile.txt"), "r", encoding="utf-8", errors="ignore") as f:
        test_case = f.read().rstrip()
    with open(testcase_output_file, encoding="utf-8") as f:
        expected_output = f.read().rstrip()
    if language == "cpp" or language == "c":
        run_message = run_cpp(working_dir)
    elif language == "java":
        run_message = run_java(working_dir)
    else:
        return ["Unsupported Language", test_case, "", expected_output]
    if run_message == "TLE":
        return ["Time Limit Exceeded", test_case, "", expected_output]
    elif run_message == "RE":
        return ["Runtime Error", test_case, "", expected_output]
    if not os.path.exists(os.path.join(working_dir, output_file_name)):
        return ["Wrong Answer", test_case, "No output file", expected_output]
    else:
        with open(os.path.join(working_dir, output_file_name), errors="ignore") as f:
            output = f.read().rstrip()
        if output != expected_output:
            return ["Wrong Answer", test_case, output, expected_output]
        else:
            return ["Accepted", test_case, output, expected_output]


def run_testcase_wrapper(args):
    language, testcase_input_file, testcase_output_file, output_file_name, working_dir = args
    return run_testcase(language, testcase_input_file, testcase_output_file, output_file_name, working_dir)


def generate_compile():
    print("Generating error messages...")
    pool = multiprocessing.Pool(processes=8)
    for problem in problem_list:
        print(f"Processing {problem}")
        buggy_problem_path = os.path.join(BUGGY_PATH, problem)
        for student in tqdm(sorted(os.listdir(buggy_problem_path))):
            student_path = os.path.join(buggy_problem_path, student)
            if os.path.exists(os.path.join(student_path, "error_message.json")):
                continue
            with open(os.path.join(student_path, "buggy.json"), "r") as f:
                meta_data = json.load(f)
            language = meta_data["language"]
            input_file_list = []
            answer_file_list = []
            output_file_list = []
            with tempfile.TemporaryDirectory() as temp_dir:
                # copy the wrong code to a temporary directory for compilation
                src_dir = os.path.join(student_path, "wrong")
                compile_dir = os.path.join(temp_dir, "compile_dir")
                shutil.copytree(src_dir, compile_dir)
                if language == "c" or language == "cpp":
                    success, _ = gcc_compile(compile_dir, language)
                elif language == "java":
                    success, _ = compile_java(compile_dir)
                if not success:
                    tqdm.write(f"Compile Error: {student}")
                    error_message = ["Compilation Error", _, "", ""]
                    with open(os.path.join(student_path, "error_message.json"), "w", encoding="utf-8") as f:
                        json.dump(error_message, f, ensure_ascii=False, indent=4)
                    continue
                # collect input and output files
                for testcase in os.listdir(os.path.join(PROBLEM_PATH, problem, "TC")):
                    testcase_input_file = os.path.join(PROBLEM_PATH, problem, "TC", testcase, "testfile.txt")
                    testcase_output_file = os.path.join(PROBLEM_PATH, problem, "TC", testcase, "ans.txt")
                    config_file = os.path.join(PROBLEM_PATH, problem, "TC", testcase, "config.json")
                    with open(config_file, "r") as f:
                        config = json.load(f)
                    input_file_list.append(testcase_input_file)
                    answer_file_list.append(testcase_output_file)
                    output_file_list.append(f"{config['type']}.txt")
                working_dirs = []
                for i in range(len(input_file_list)):
                    working_dir = os.path.join(temp_dir, f"working_dir_{i}")
                    shutil.copytree(compile_dir, working_dir)
                    working_dirs.append(working_dir)
                args = zip(
                    [language] * len(input_file_list),
                    input_file_list,
                    answer_file_list,
                    output_file_list,
                    working_dirs,
                )
                # multiprocessing to run test cases
                results = pool.map(run_testcase_wrapper, args)
                # process results
                error_message = ["Accepted", "", "", ""]
                for result in results:
                    if result[0] == "Wrong Answer":
                        if error_message[0] != "Wrong Answer":
                            error_message = result
                        elif len(result[1]) < len(error_message[1]):
                            error_message = result
                    elif result[0] == "Runtime Error" and error_message[0] != "Wrong Answer":
                        error_message = result
                    elif result[0] == "Time Limit Exceeded" and error_message[0] != "Wrong Answer":
                        error_message = result
            if error_message[0] == "Accepted":
                tqdm.write(f"Accepted: {student}")
                continue
            with open(os.path.join(student_path, "error_message.json"), "w") as f:
                json.dump(error_message, f, ensure_ascii=False, indent=4)
    pool.close()


if __name__ == "__main__":
    if PROJECT.startswith("data_structures"):
        generate_ds()
    elif PROJECT.startswith("test_ds"):
        generate_ds()
    elif PROJECT.startswith("compiler_technology"):
        generate_compile()
