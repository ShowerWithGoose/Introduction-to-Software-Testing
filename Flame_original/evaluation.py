import json
import os
import re
import difflib

from tqdm import tqdm

from generate_embedding import detect_encoding
from util.config import BUGGY_PATH, PROJECT

problem_list = os.listdir(BUGGY_PATH)


if PROJECT.startswith("data_structures"):
    file_name_extension = "c"
if PROJECT.startswith("compiler_technology"):
    file_name_extension = "txt"
if PROJECT.startswith("deflects4j"):
    file_name_extension = "txt"


vote_file_tag_list = [
    "buggy-deepseek-chat-1",
    "buggy-deepseek-chat-2",
    "buggy-claude-3-7-sonnet-1",
    "buggy-claude-3-7-sonnet-2",
    "buggy-claude-sonnet-4-6-1",
    "buggy-claude-sonnet-4-6-2",
    "buggy-deepseek-reasoner-1",
    "buggy-deepseek-reasoner-2",
    "buggy-qwen3.6-plus-1",  # 添加 qwen 的第一个副本
    "buggy-qwen3.6-plus-2",  # 添加 qwen 的第二个副本
    "buggy-qwen3-max-1",  # 添加 qwen 的第一个副本
    "buggy-qwen3-max-2",  # 添加 qwen 的第二个副本
]


def calculate_rank(location_results: list, ground_truth: list):
    rank = 0
    for i in location_results:
        rank += 1
        if i in ground_truth:
            return rank
    return None


def calculate_similarity(text1, text2):
    matcher = difflib.SequenceMatcher(None, text1, text2)
    similarity_ratio = matcher.ratio()
    return similarity_ratio


def extract_location_results(buggy_src_file: str, annotated_src_file: str):
    encoding = detect_encoding(buggy_src_file)["encoding"]
    with open(buggy_src_file, "r", encoding=encoding, errors="ignore") as f:
        buggy_src = f.read().rstrip()
    with open(annotated_src_file, "r", errors="ignore") as f:
        annotated_src = f.read().rstrip()
    buggy_src_lines = buggy_src.splitlines()
    annotated_src_lines = annotated_src.splitlines()
    error_lines = {i: line for i, line in enumerate(annotated_src_lines) if "@@" in line}
    location_results = {}
    if len(buggy_src_lines) != len(annotated_src_lines):
        # print(
        #     f"Line number mismatch: {problem} {student}, {len(buggy_src_lines)},{len(annotated_src_lines)}"
        # )
        for line_num in error_lines:
            error_line = error_lines[line_num]
            error_reason = error_line.split("@@")[1]
            error_line = error_line.split("//")[0]
            error_line = error_line.split("@@")[0]
            error_line = error_line.lstrip().rstrip()
            if not error_line:
                continue
            if len(buggy_src_lines) > len(annotated_src_lines):
                for i in range(line_num, len(buggy_src_lines), 1):
                    original_line = buggy_src_lines[i].lstrip().rstrip()
                    if not original_line:
                        continue
                    if calculate_similarity(error_line, original_line) > 0.95:
                        location_results[i] = {"reason": error_reason}
                        break
            else:
                for i in range(min(line_num, len(buggy_src_lines) - 1), -1, -1):
                    original_line = buggy_src_lines[i].lstrip().rstrip()
                    if not original_line:
                        continue
                    if calculate_similarity(error_line, original_line) > 0.95:
                        location_results[i] = {"reason": error_reason}
                        break
    else:
        for line_num in error_lines:
            error_line = error_lines[line_num]
            error_reason = error_line.split("@@")[1]
            location_results[line_num] = {"reason": error_reason}
    return location_results, buggy_src_lines


def extract_location_results_compile_course(student_path: str, annotated_src_file: str, file_line_map: dict):
    max_end = 0
    for file in file_line_map:
        max_end = max(max_end, file_line_map[file]["end"])
    total_buggy_src_lines = [""] * max_end

    location_results = {}
    with open(annotated_src_file, "r") as f:
        annotated_src = f.read().rstrip()
    annotated_src_lines = annotated_src.splitlines()
    current_file = ""
    current_line = 0
    skip_flag = False
    for line_index, line in enumerate(annotated_src_lines):
        file_pattern = r"<[^>]+\.cpp>|<[^>]+\.java>|<[^>]+\.c>|<[^>]+\.h>"
        file_match = re.search(file_pattern, line)
        if file_match:
            current_file = file_match.group()[1:-1]
            current_line = 0
            if current_file.startswith("/"):
                # illegal file name
                current_file = ""
                continue
            if current_file not in file_line_map:
                # try to fix the LLM error generated path
                current_file_name = current_file.split("/")[-1]
                for file in file_line_map:
                    file_name = file.split("/")[-1]
                    if current_file_name == file_name:
                        current_file = file
                        break
                if len(file_line_map) == 1:
                    current_file = list(file_line_map.keys())[0]
                # fix failed
                if current_file not in file_line_map:
                    current_file = ""
                    continue
            encoding = detect_encoding(os.path.join(student_path, "wrong", current_file))["encoding"]
            with open(os.path.join(student_path, "wrong", current_file), "r", encoding="utf-8") as f:
                buggy_src = f.read().rstrip()
            buggy_src_lines = buggy_src.splitlines()
            continue
        if current_file == "":
            continue
        if line == "```":
            continue
        # detect the case of omitted lines, calculate the number of lines to skip
        if line.rstrip().lstrip() in ["...", "```java", "```c", "```cpp"]:
            skip_flag = True
            continue
        if skip_flag or current_line == 0:
            line_matched = 0
            old_current_line = current_line
            while line_matched < 3:
                if line_index + line_matched + 1 >= len(annotated_src_lines):
                    break
                annotated_src_line = annotated_src_lines[line_index + line_matched].split("@@")[0].lstrip().rstrip()
                if current_line + line_matched >= len(buggy_src_lines):
                    current_line = old_current_line
                    break
                original_line = buggy_src_lines[current_line + line_matched].lstrip().rstrip()
                if calculate_similarity(annotated_src_line, original_line) > 0.95:
                    line_matched += 1
                else:
                    line_matched = 0
                    current_line += 1
            if line_matched < 3:
                current_line = old_current_line
            skip_flag = False
        # detetct the case of error lines
        if "@@" in line:
            error_line = line.split("@@")[0].split("//")[0].lstrip().rstrip()
            error_reason = line.split("@@")[1]
            if not error_line:
                current_line += 1
                continue
            if current_file in file_line_map:
                line_start = file_line_map[current_file]["start"]
                error_line_matched = False
                for i in range(32):
                    next_line = current_line + i
                    if next_line < len(buggy_src_lines) and next_line >= 0:
                        original_line = buggy_src_lines[current_line + i].split("//")[0].lstrip().rstrip()
                        if not original_line:
                            continue
                        if calculate_similarity(error_line, original_line) > 0.95:
                            location_results[current_line + i + line_start] = {
                                "reason": error_reason,
                                "line_num": current_line + i + 1,
                                "file": current_file,
                            }
                            total_buggy_src_lines[current_line + i + line_start] = original_line
                            error_line_matched = True
                            break
                    last_line = current_line - i
                    if last_line >= 0 and last_line < len(buggy_src_lines):
                        original_line = buggy_src_lines[current_line - i].split("//")[0].lstrip().rstrip()
                        if not original_line:
                            continue
                        if error_line == original_line or calculate_similarity(error_line, original_line) > 0.95:
                            location_results[current_line - i + line_start] = {
                                "reason": error_reason,
                                "line_num": current_line - i + 1,
                                "file": current_file,
                            }
                            total_buggy_src_lines[current_line - i + line_start] = original_line
                            error_line_matched = True
                            break
                if not error_line_matched:
                    if current_line < len(buggy_src_lines):
                        location_results[current_line + line_start] = {
                            "reason": error_reason,
                            "file": current_file,
                            "line_num": current_line + 1,
                        }
                        total_buggy_src_lines[current_line + line_start] = buggy_src_lines[current_line].split("//")[0].lstrip().rstrip()
        current_line += 1
    return location_results, total_buggy_src_lines


def generate_vote_results():
    print(f"Generating vote results for {PROJECT}...")
    for problem in sorted(problem_list):
        buggy_problem_path = os.path.join(BUGGY_PATH, problem)
        for student in tqdm(sorted(os.listdir(buggy_problem_path))):
            student_path = os.path.join(buggy_problem_path, student)
            if PROJECT.startswith("compiler_technology"):
                if not os.path.exists(os.path.join(student_path, "file_line_map.json")):
                    continue
                if not os.path.exists(os.path.join(student_path, "error_message.json")):
                    continue
                with open(os.path.join(student_path, "file_line_map.json"), "r") as f:
                    file_line_map = json.load(f)
            buggy_src_file = os.path.join(student_path, f"buggy.{file_name_extension}")
            vote_results = {}
            for i_vote_file, vote_file_tag in enumerate(vote_file_tag_list):
                vote_annotated_src_file = os.path.join(student_path, f"{vote_file_tag}.{file_name_extension}")
                if not os.path.exists(vote_annotated_src_file):
                    continue
                if PROJECT.startswith("compiler_technology"):
                    location_results, buggy_src_lines = extract_location_results_compile_course(student_path, vote_annotated_src_file, file_line_map)
                else:
                    location_results, buggy_src_lines = extract_location_results(buggy_src_file, vote_annotated_src_file)
                for i in location_results:
                    weight = 1 / len(location_results)
                    if i not in vote_results:
                        if "file" in location_results[i]:
                            file = location_results[i]["file"]  # ct course
                        else:
                            file = ""  # ds course
                        if "line_num" in location_results[i]:
                            line_num = location_results[i]["line_num"]  # ct course
                        else:
                            line_num = i + 1  # ds course
                        vote_results[i] = {
                            "code": buggy_src_lines[i],
                            "weight": weight,
                            "file": file,
                            "line_num": line_num,
                            "reason": location_results[i]["reason"],
                            "reason-model": vote_file_tag,
                            "reason_weight": weight,
                            "reasons": {
                                vote_file_tag: f"{weight} , reason: {location_results[i]['reason']}",
                            },
                        }
                    else:
                        vote_results[i]["weight"] += weight
                        vote_results[i]["reasons"][vote_file_tag] = f"{weight} , reason: {location_results[i]['reason']}"
                        if vote_results[i]["reason"] == "" or weight > vote_results[i]["reason_weight"]:
                            vote_results[i]["reason"] = location_results[i]["reason"]
                            vote_results[i]["reason-model"] = vote_file_tag
                            vote_results[i]["reason_weight"] = weight
            with open(os.path.join(student_path, f"vote_results.json"), "w", encoding="utf-8") as f:
                json.dump(vote_results, f, indent=4, ensure_ascii=False)


def evaluate():
    print(f"Evaluating {PROJECT}...")
    cnt = 0
    top_1 = 0
    top_3 = 0
    top_5 = 0
    top_10 = 0
    for problem in sorted(problem_list):
        buggy_problem_path = os.path.join(BUGGY_PATH, problem)
        for student in tqdm(sorted(os.listdir(buggy_problem_path))):
            student_path = os.path.join(buggy_problem_path, student)
            vote_file = os.path.join(student_path, "vote_results.json")
            if not os.path.exists(vote_file):
                continue
            cnt += 1
            with open(vote_file, "r") as f:
                vote_results = json.load(f)
            # oreder by weight
            location_results = sorted(vote_results, key=lambda x: vote_results[x]["weight"], reverse=True)
            # convert to 1-based index
            location_results = [int(i) + 1 for i in location_results]
            # load the ground truth
            if PROJECT.startswith("compiler_technology"):
                with open(os.path.join(BUGGY_PATH, problem, student, "buggy.json"), "r") as f:
                    data = json.load(f)
                with open(os.path.join(student_path, "file_line_map.json"), "r") as f:
                    file_line_map = json.load(f)
                correct_location_dict = data["ground_truth"]
                correct_location = []
                # convert the line numbers
                for file in correct_location_dict:
                    file_diff_lines = correct_location_dict[file]
                    file_name = file[2:]
                    if file_name in file_line_map:
                        line_start = file_line_map[file_name]["start"]
                        for line_num in file_diff_lines:
                            correct_location.append(line_start + line_num)
            else:
                with open(os.path.join(BUGGY_PATH, problem, student, "buggy.json"), "r") as f:
                    data = json.load(f)
                correct_location = data["ground_truth"]
            rank = calculate_rank(location_results, correct_location)
            if rank:
                if rank == 1:
                    top_1 += 1
                if rank <= 3:
                    top_3 += 1
                if rank <= 5:
                    top_5 += 1
                if rank <= 10:
                    top_10 += 1
    print(f"Evaluation results for {PROJECT}:")
    print(f"{'Count':<7}{'Top-1':<7}{'Top-3':<7}{'Top-5':<7}{'Top-10':<7}")
    print(f"{cnt:<7}{top_1:<7}{top_3:<7}{top_5:<7}{top_10:<7}")


if __name__ == "__main__":
    evaluate()
