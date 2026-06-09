import os
import json

import chardet

from util.config import BUGGY_PATH, PROBLEM_PATH, PROJECT


def detect_encoding(file_path):
    with open(file_path, "rb") as f:
        raw_data = f.read()
        result = chardet.detect(raw_data)
        return result


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


def generate_file_line_map(language: str, working_dir: str):
    origin_cwd = os.getcwd()
    file_line_map = {}
    file_list = []
    os.chdir(working_dir)
    # cpp
    if language == "cpp" or language == "c":
        file_list = find_all_files(".", "cpp")
        file_list.extend(find_all_files(".", "c"))
        file_list.extend(find_all_files(".", "h"))
        file_list.extend(find_all_files(".", "hpp"))
    # java
    if language == "java":
        file_list = find_all_files(".", "java")
    os.chdir(origin_cwd)  # change working directory back
    file_list.sort()
    start = 0
    for file in file_list:
        with open(os.path.join(working_dir, file), "r", encoding="utf-8", errors="ignore") as f:
            lines = f.readlines()
            line_num = len(lines)
        file_line_map[file[2:]] = {
            "start": start,
            "end": start + line_num,
        }
        start += line_num + 1
    return file_line_map


def generate_complete_fragment():
    for problem in sorted(os.listdir(PROBLEM_PATH)):
        buggy_problem_path = os.path.join(BUGGY_PATH, problem)
        for student in sorted(os.listdir(buggy_problem_path)):
            student_path = os.path.join(buggy_problem_path, student)
            if not os.path.exists(os.path.join(student_path, "file_line_map.json")):
                continue
            with open(os.path.join(student_path, "file_line_map.json"), "r") as f:
                file_line_map = json.load(f)
            fragment_str = ""
            for file in file_line_map:
                fragment_str += f"<{file}>\n"
                fragment_file = os.path.join(student_path, "wrong", file)
                encoding = detect_encoding(fragment_file)["encoding"]
                with open(fragment_file, "r", encoding="utf-8") as f:
                    src = f.read().rstrip()
                fragment_str += src
                fragment_str += "\n"
            with open(os.path.join(student_path, f"buggy.txt"), "w") as f:
                f.write(fragment_str)


def main():
    print(f"Generating file line map and buggy.txt for {PROJECT}...")
    if PROJECT.startswith("compiler_technology"):
        for problem in sorted(os.listdir(BUGGY_PATH)):
            buggy_problem_path = os.path.join(BUGGY_PATH, problem)
            for student in sorted(os.listdir(buggy_problem_path)):
                student_path = os.path.join(buggy_problem_path, student)
                meta_data_file = os.path.join(student_path, "buggy.json")
                if not os.path.exists(meta_data_file):
                    continue
                with open(meta_data_file, "r") as f:
                    metadata = json.load(f)
                language = metadata["language"]
                src_path = os.path.join(student_path, "wrong")
                file_line_map = generate_file_line_map(language, src_path)
                line_map_file = os.path.join(student_path, "file_line_map.json")
                with open(line_map_file, "w") as f:
                    json.dump(file_line_map, f, indent=4)
        generate_complete_fragment()


if __name__ == "__main__":
    main()
