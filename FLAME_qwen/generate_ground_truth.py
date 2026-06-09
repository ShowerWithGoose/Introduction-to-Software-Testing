import json
import os
import difflib

from util.config import BUGGY_PATH, PROJECT

from tqdm import tqdm

problem_list = os.listdir(BUGGY_PATH)


def detect_language(src_path: str):
    for root, dirs, files in os.walk(src_path):
        for f in files:
            if f.endswith(".java"):
                return "java"
            if f.endswith(".c"):
                return "c"
            if f.endswith(".cpp"):
                return "cpp"
    return "other"


def find_java_src_dir(compile_dir: str):
    for root, dirs, files in os.walk(compile_dir):
        for f in files:
            if f == "Compiler.java":
                return root


def find_all_files(path: str, suffix: str = "cpp"):
    """
    Find all files in the given path with the given suffix.
    """
    if not os.path.isdir(path):
        return []
    files = []
    for file in os.listdir(path):
        file_path = os.path.join(path, file)
        if os.path.isfile(file_path):
            if suffix is None or file_path.endswith(suffix):
                files.append(file_path)
        else:
            files += find_all_files(file_path, suffix)
    return files


def get_diff_result_ct(src_path, language: str):
    origin_cwd = os.getcwd()
    file_dict = {}
    os.chdir(os.path.join(src_path, "wrong"))
    # cpp
    if language == "c" or language == "cpp":
        wrong_file_list = find_all_files(".", "cpp")
        wrong_file_list.extend(find_all_files(".", "c"))
        wrong_file_list.extend(find_all_files(".", "h"))
        wrong_file_list.extend(find_all_files(".", "hpp"))
    # java
    elif language == "java":
        wrong_file_list = find_all_files(".", "java")
    wrong_file_list.sort()
    for file in wrong_file_list:
        correct_file = os.path.join("..", "correct", file)
        if os.path.exists(correct_file):
            d = difflib.Differ()
            diffs = d.compare(
                open(file, errors="ignore").readlines(),
                open(correct_file, errors="ignore").readlines(),
            )
            lineNum = 0
            diff_lines = []
            has_delete = False
            for line in diffs:
                # split off the code
                code = line[:2]
                if code == "  ":
                    lineNum += 1
                    has_delete = False
                if code == "- ":
                    lineNum += 1
                    diff_lines.append(lineNum)
                    has_delete = True
                if code == "+ ":
                    if len(diff_lines) == 0 or lineNum != diff_lines[-1]:
                        if lineNum not in diff_lines:
                            diff_lines.append(lineNum)
                        if not has_delete and lineNum + 1 not in diff_lines:
                            diff_lines.append(lineNum + 1)
            file_dict[file] = diff_lines
    os.chdir(origin_cwd)  # change working directory back
    return file_dict


def get_diff_result_ds(correct_file, wrong_file):
    if os.path.exists(correct_file):
        d = difflib.Differ()
        diffs = d.compare(
            open(wrong_file, errors="ignore").readlines(),
            open(correct_file, errors="ignore").readlines(),
        )
        lineNum = 0
        diff_lines = []
        has_delete = False
        for line in diffs:
            # split off the code
            code = line[:2]
            if code == "  ":
                lineNum += 1
                has_delete = False
            if code == "- ":
                lineNum += 1
                diff_lines.append(lineNum)
                has_delete = True
            if code == "+ ":
                if len(diff_lines) == 0 or lineNum != diff_lines[-1]:
                    if lineNum not in diff_lines:
                        diff_lines.append(lineNum)
                    if not has_delete and lineNum + 1 not in diff_lines:
                        diff_lines.append(lineNum + 1)
        return diff_lines


def main():
    print("Generating ground truth for buggy programs...")
    if PROJECT.startswith("compiler_technology"):
        for problem in sorted(problem_list):
            buggy_problem_path = os.path.join(BUGGY_PATH, problem)
            for student in tqdm(sorted(os.listdir(buggy_problem_path))):
                student_path = os.path.join(buggy_problem_path, student)
                buggy_info = {}
                language = detect_language(os.path.join(student_path, "wrong"))
                if language == "other":
                    raise ValueError(f"Cannot detect language for {student_path}")
                buggy_info["language"] = language
                correct_location_dict = get_diff_result_ct(student_path, buggy_info["language"])
                buggy_info["ground_truth"] = correct_location_dict
                with open(os.path.join(BUGGY_PATH, problem, student, "buggy.json"), "w") as f:
                    json.dump(buggy_info, f, indent=4)
    if PROJECT.startswith("data_structures"):
        for problem in sorted(problem_list):
            buggy_problem_path = os.path.join(BUGGY_PATH, problem)
            for student in tqdm(sorted(os.listdir(buggy_problem_path))):
                student_path = os.path.join(buggy_problem_path, student)
                buggy_info = {}
                correct_location_dict = get_diff_result_ds(
                    os.path.join(BUGGY_PATH, problem, student, "correct.c"),
                    os.path.join(BUGGY_PATH, problem, student, "buggy.c"),
                )
                buggy_info["ground_truth"] = correct_location_dict
                with open(os.path.join(BUGGY_PATH, problem, student, "buggy.json"), "w") as f:
                    json.dump(buggy_info, f, indent=4)


if __name__ == "__main__":
    main()
