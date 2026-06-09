import argparse
import concurrent.futures
import difflib
import json
import os
import re
from dataclasses import dataclass

import chardet
from dotenv import load_dotenv
from tqdm import tqdm

load_dotenv()

from util.config import BUGGY_PATH, PROBLEM_PATH, PROJECT  # noqa: E402
from util.prompt_util import (  # noqa: E402
    generate_prompt_compile_json,
    generate_prompt_compile_step_1,
    generate_prompt_compile_step_2,
    generate_prompt_deflects4j,
    generate_prompt_ds,
    generate_prompt_ds_json,
)


MODEL = "qwen3-max"
MODEL_FILE_NAME = "qwen3-max"
TEMPERATURE = 0.1
SINGLE_TAG = f"buggy-{MODEL_FILE_NAME}-single"
SELF_CONSISTENCY_TAG_PREFIX = f"buggy-{MODEL_FILE_NAME}-sc"
SINGLE_RESULT_FILE = "vote_results_qwen_single.json"
SELF_CONSISTENCY_RESULT_FILE = "vote_results_qwen_self_consistency.json"


def detect_encoding(file_path):
    with open(file_path, "rb") as f:
        raw_data = f.read()
    return chardet.detect(raw_data)


def calculate_rank(location_results, ground_truth):
    rank = 0
    for line in location_results:
        rank += 1
        if line in ground_truth:
            return rank
    return None


def calculate_similarity(text1, text2):
    matcher = difflib.SequenceMatcher(None, text1, text2)
    return matcher.ratio()


def extract_code(markdown, language=None):
    try:
        if "```" not in markdown:
            return markdown
        if language is None:
            return markdown.split("```")[1].strip()
        return markdown.split(f"```{language}")[1].split("```")[0].strip()
    except Exception:
        return None


def call_chat_completion(prompt, model, history_messages=None, temperature=0.1):
    try:
        from util.openai_util import chat_completion
    except ModuleNotFoundError as exc:
        raise RuntimeError(
            "The openai package is required for generation. "
            "Install dependencies with: pip install -r requirements.txt"
        ) from exc
    return chat_completion(
        prompt,
        model=model,
        history_messages=history_messages,
        temperature=temperature,
    )


def find_reference(problem, student_path):
    try:
        from generate_embedding import find_nearest_reference
    except ModuleNotFoundError as exc:
        raise RuntimeError(
            "The openai package is required for data_structures reference retrieval. "
            "Install dependencies with: pip install -r requirements.txt"
        ) from exc
    return find_nearest_reference(problem, student_path)


def extract_location_results(buggy_src_file, annotated_src_file):
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


def extract_location_results_compile_course(student_path, annotated_src_file, file_line_map):
    max_end = 0
    for file_name in file_line_map:
        max_end = max(max_end, file_line_map[file_name]["end"])
    total_buggy_src_lines = [""] * max_end

    location_results = {}
    with open(annotated_src_file, "r", encoding="utf-8", errors="ignore") as f:
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
                current_file = ""
                continue
            if current_file not in file_line_map:
                current_file_name = current_file.split("/")[-1]
                for mapped_file in file_line_map:
                    mapped_name = mapped_file.split("/")[-1]
                    if current_file_name == mapped_name:
                        current_file = mapped_file
                        break
                if len(file_line_map) == 1:
                    current_file = list(file_line_map.keys())[0]
                if current_file not in file_line_map:
                    current_file = ""
                    continue
            wrong_file = os.path.join(student_path, "wrong", current_file)
            encoding = detect_encoding(wrong_file)["encoding"]
            with open(wrong_file, "r", encoding=encoding, errors="ignore") as f:
                buggy_src = f.read().rstrip()
            buggy_src_lines = buggy_src.splitlines()
            continue

        if current_file == "":
            continue
        if line == "```":
            continue
        if line.rstrip().lstrip() in ["...", "```java", "```c", "```cpp"]:
            skip_flag = True
            continue

        if skip_flag or current_line == 0:
            line_matched = 0
            old_current_line = current_line
            while line_matched < 3:
                if line_index + line_matched + 1 >= len(annotated_src_lines):
                    break
                annotated_line = annotated_src_lines[line_index + line_matched].split("@@")[0].lstrip().rstrip()
                if current_line + line_matched >= len(buggy_src_lines):
                    current_line = old_current_line
                    break
                original_line = buggy_src_lines[current_line + line_matched].lstrip().rstrip()
                if calculate_similarity(annotated_line, original_line) > 0.95:
                    line_matched += 1
                else:
                    line_matched = 0
                    current_line += 1
            if line_matched < 3:
                current_line = old_current_line
            skip_flag = False

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
                    if 0 <= next_line < len(buggy_src_lines):
                        original_line = buggy_src_lines[next_line].split("//")[0].lstrip().rstrip()
                        if original_line and calculate_similarity(error_line, original_line) > 0.95:
                            location_results[next_line + line_start] = {
                                "reason": error_reason,
                                "line_num": next_line + 1,
                                "file": current_file,
                            }
                            total_buggy_src_lines[next_line + line_start] = original_line
                            error_line_matched = True
                            break
                    last_line = current_line - i
                    if 0 <= last_line < len(buggy_src_lines):
                        original_line = buggy_src_lines[last_line].split("//")[0].lstrip().rstrip()
                        if original_line and (
                            error_line == original_line
                            or calculate_similarity(error_line, original_line) > 0.95
                        ):
                            location_results[last_line + line_start] = {
                                "reason": error_reason,
                                "line_num": last_line + 1,
                                "file": current_file,
                            }
                            total_buggy_src_lines[last_line + line_start] = original_line
                            error_line_matched = True
                            break
                if not error_line_matched and current_line < len(buggy_src_lines):
                    fallback_line = current_line + line_start
                    location_results[fallback_line] = {
                        "reason": error_reason,
                        "file": current_file,
                        "line_num": current_line + 1,
                    }
                    total_buggy_src_lines[fallback_line] = buggy_src_lines[current_line].split("//")[0].lstrip().rstrip()
        current_line += 1

    return location_results, total_buggy_src_lines


@dataclass
class Case:
    problem: str
    student: str
    student_path: str
    buggy_src_file: str


def get_extensions():
    if PROJECT.startswith("data_structures"):
        return "c", "c"
    if PROJECT.startswith("compiler_technology"):
        return "txt", "txt"
    if PROJECT.startswith("deflects4j"):
        return "txt", "txt"
    raise ValueError(f"Unsupported PROJECT: {PROJECT}")


def get_self_consistency_tags(runs):
    return [f"{SELF_CONSISTENCY_TAG_PREFIX}-{i + 1}" for i in range(runs)]


def collect_cases(max_cases=None):
    _, buggy_ext = get_extensions()
    cases = []
    for problem in sorted(os.listdir(BUGGY_PATH)):
        buggy_problem_path = os.path.join(BUGGY_PATH, problem)
        if not os.path.isdir(buggy_problem_path):
            continue
        for student in sorted(os.listdir(buggy_problem_path)):
            student_path = os.path.join(buggy_problem_path, student)
            if not os.path.isdir(student_path):
                continue
            buggy_src_file = os.path.join(student_path, f"buggy.{buggy_ext}")
            if not os.path.exists(buggy_src_file):
                continue
            if not os.path.exists(os.path.join(student_path, "error_message.json")):
                continue
            cases.append(Case(problem, student, student_path, buggy_src_file))
            if max_cases is not None and len(cases) >= max_cases:
                return cases
    return cases


def load_error_message(student_path):
    error_message_file = os.path.join(student_path, "error_message.json")
    with open(error_message_file, "r", encoding="utf-8") as f:
        return json.load(f)


def load_problem_description(problem):
    problem_description_file = os.path.join(PROBLEM_PATH, problem, "description.txt")
    if not os.path.exists(problem_description_file):
        return ""
    with open(problem_description_file, "r", encoding="utf-8") as f:
        return f.read()


def load_buggy_source(buggy_src_file):
    encoding = detect_encoding(buggy_src_file)["encoding"]
    with open(buggy_src_file, "r", encoding=encoding, errors="ignore") as f:
        return f.read().rstrip()


def build_prompt(case, json_output_mode=False):
    problem_description = load_problem_description(case.problem)
    buggy_src = load_buggy_source(case.buggy_src_file)
    error_message = load_error_message(case.student_path)
    if error_message is None:
        return None

    if PROJECT.startswith("data_structures"):
        reference = find_reference(case.problem, case.student_path)
        if json_output_mode:
            prompt = generate_prompt_ds_json(
                problem_description=problem_description,
                reference=reference,
                error_message=error_message,
                src_code=buggy_src,
            )
        else:
            prompt = generate_prompt_ds(
                problem_description=problem_description,
                reference=reference,
                error_message=error_message,
                src_code=buggy_src,
            )
    elif PROJECT.startswith("compiler_technology"):
        if json_output_mode:
            prompt = generate_prompt_compile_json(
                problem_description=problem_description,
                error_message=error_message,
                src_code=buggy_src,
            )
        else:
            prompt = generate_prompt_compile_step_1(
                problem_description=problem_description,
                error_message=error_message,
                src_code=buggy_src,
            )
    elif PROJECT.startswith("deflects4j"):
        description_file = os.path.join(case.student_path, "description.txt")
        with open(description_file, "r", encoding="utf-8") as f:
            function_comment = f.read()
        if json_output_mode:
            return None
        prompt = generate_prompt_deflects4j(
            problem_description=problem_description,
            function_comment=function_comment,
            error_message=error_message,
            src_code=buggy_src,
        )
    else:
        raise ValueError(f"Unsupported PROJECT: {PROJECT}")

    return prompt.replace("\t", "    ")


def generate_one_case(case, tag, temperature, force=False):
    output_ext, _ = get_extensions()
    output_file = os.path.join(case.student_path, f"{tag}.{output_ext}")
    if os.path.exists(output_file) and not force:
        return "skipped"

    prompt = build_prompt(case, json_output_mode=False)
    if not prompt:
        return "no-prompt"

    prompt_file = os.path.join(case.student_path, f"prompt_{tag}.txt")
    with open(prompt_file, "w", encoding="utf-8") as f:
        f.write(prompt)

    res, messages = call_chat_completion(prompt, model=MODEL, temperature=temperature)
    if res is None:
        return f"error: {messages}"

    if PROJECT.startswith("data_structures"):
        annotated_src = extract_code(res, output_ext)
        if annotated_src is None:
            return "error: cannot extract annotated source"
    elif PROJECT.startswith("compiler_technology"):
        wrong_snippet_path = os.path.join(case.student_path, "wrong-snippet")
        os.makedirs(wrong_snippet_path, exist_ok=True)
        with open(os.path.join(wrong_snippet_path, f"{tag}.txt"), "w", encoding="utf-8") as f:
            f.write(res)

        prompt_step_2 = generate_prompt_compile_step_2()
        res, err = call_chat_completion(
            prompt_step_2,
            model=MODEL,
            history_messages=messages,
            temperature=temperature,
        )
        if res is None:
            return f"error: {err}"
        annotated_src = res
    elif PROJECT.startswith("deflects4j"):
        annotated_src = extract_code(res, "java")
        if annotated_src is None:
            return "error: cannot extract annotated source"
    else:
        raise ValueError(f"Unsupported PROJECT: {PROJECT}")

    with open(output_file, "w", encoding="utf-8") as f:
        f.write(annotated_src or "")
    return "generated"


def generate_for_tags(tags, workers, force=False, max_cases=None):
    cases = collect_cases(max_cases=max_cases)
    print(f"Project: {PROJECT}")
    print(f"Model: {MODEL}")
    print(f"Cases: {len(cases)}")
    print(f"Temperature: {TEMPERATURE}")

    for tag in tags:
        print(f"Generating annotated outputs for tag: {tag}")
        stats = {}
        with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
            futures = [
                executor.submit(generate_one_case, case, tag, TEMPERATURE, force)
                for case in cases
            ]
            for future in tqdm(concurrent.futures.as_completed(futures), total=len(futures)):
                status = future.result()
                stats[status] = stats.get(status, 0) + 1
        print(json.dumps(stats, indent=2, ensure_ascii=False))


def add_locations_to_vote_results(vote_results, location_results, buggy_src_lines, tag):
    if not location_results:
        return
    weight = 1 / len(location_results)
    for line_index, result in location_results.items():
        if "file" in result:
            file_name = result["file"]
        else:
            file_name = ""
        if "line_num" in result:
            line_num = result["line_num"]
        else:
            line_num = line_index + 1
        code = buggy_src_lines[line_index] if line_index < len(buggy_src_lines) else ""
        reason = result.get("reason", "")

        if line_index not in vote_results:
            vote_results[line_index] = {
                "code": code,
                "weight": weight,
                "file": file_name,
                "line_num": line_num,
                "reason": reason,
                "reason-model": tag,
                "reason_weight": weight,
                "reasons": {
                    tag: f"{weight} , reason: {reason}",
                },
            }
        else:
            vote_results[line_index]["weight"] += weight
            vote_results[line_index]["reasons"][tag] = f"{weight} , reason: {reason}"
            if vote_results[line_index]["reason"] == "" or weight > vote_results[line_index]["reason_weight"]:
                vote_results[line_index]["reason"] = reason
                vote_results[line_index]["reason-model"] = tag
                vote_results[line_index]["reason_weight"] = weight


def aggregate(tags, output_file_name, max_cases=None):
    output_ext, _ = get_extensions()
    cases = collect_cases(max_cases=max_cases)
    print(f"Aggregating {len(tags)} tag(s) into {output_file_name}")

    for case in tqdm(cases):
        if PROJECT.startswith("compiler_technology"):
            file_line_map_file = os.path.join(case.student_path, "file_line_map.json")
            if not os.path.exists(file_line_map_file):
                continue
            with open(file_line_map_file, "r", encoding="utf-8") as f:
                file_line_map = json.load(f)

        vote_results = {}
        for tag in tags:
            annotated_src_file = os.path.join(case.student_path, f"{tag}.{output_ext}")
            if not os.path.exists(annotated_src_file):
                continue
            if PROJECT.startswith("compiler_technology"):
                location_results, buggy_src_lines = extract_location_results_compile_course(
                    case.student_path,
                    annotated_src_file,
                    file_line_map,
                )
            else:
                location_results, buggy_src_lines = extract_location_results(
                    case.buggy_src_file,
                    annotated_src_file,
                )
            add_locations_to_vote_results(vote_results, location_results, buggy_src_lines, tag)

        with open(os.path.join(case.student_path, output_file_name), "w", encoding="utf-8") as f:
            json.dump(vote_results, f, indent=4, ensure_ascii=False)


def load_ground_truth(case):
    with open(os.path.join(case.student_path, "buggy.json"), "r", encoding="utf-8") as f:
        data = json.load(f)

    if PROJECT.startswith("compiler_technology"):
        with open(os.path.join(case.student_path, "file_line_map.json"), "r", encoding="utf-8") as f:
            file_line_map = json.load(f)
        correct_location = []
        for file_name, file_diff_lines in data["ground_truth"].items():
            normalized_file = file_name[2:]
            if normalized_file not in file_line_map:
                continue
            line_start = file_line_map[normalized_file]["start"]
            for line_num in file_diff_lines:
                correct_location.append(line_start + line_num)
        return correct_location

    return data["ground_truth"]


def evaluate_result_file(result_file_name, max_cases=None):
    cases = collect_cases(max_cases=max_cases)
    cnt = 0
    top_1 = 0
    top_3 = 0
    top_5 = 0
    top_10 = 0

    for case in tqdm(cases):
        result_file = os.path.join(case.student_path, result_file_name)
        if not os.path.exists(result_file):
            continue
        cnt += 1
        with open(result_file, "r", encoding="utf-8") as f:
            vote_results = json.load(f)
        location_results = sorted(
            vote_results,
            key=lambda line: vote_results[line]["weight"],
            reverse=True,
        )
        location_results = [int(line) + 1 for line in location_results]
        correct_location = load_ground_truth(case)
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

    print(f"Evaluation results for {PROJECT}: {result_file_name}")
    print(f"{'Count':<7}{'Top-1':<7}{'Top-3':<7}{'Top-5':<7}{'Top-10':<7}")
    print(f"{cnt:<7}{top_1:<7}{top_3:<7}{top_5:<7}{top_10:<7}")
    if cnt:
        print(
            f"Rate   {top_1 / cnt:<7.3f}{top_3 / cnt:<7.3f}"
            f"{top_5 / cnt:<7.3f}{top_10 / cnt:<7.3f}"
        )


def resolve_experiment(experiment, runs):
    if experiment == "single":
        return [SINGLE_TAG], SINGLE_RESULT_FILE
    if experiment == "self_consistency":
        return get_self_consistency_tags(runs), SELF_CONSISTENCY_RESULT_FILE
    raise ValueError(f"Unsupported experiment: {experiment}")


def run_command(args):
    experiments = ["single", "self_consistency"] if args.experiment == "both" else [args.experiment]
    custom_tags = [tag.strip() for tag in args.tags.split(",")] if args.tags else None
    if custom_tags and args.experiment == "both":
        raise ValueError("--tags can only be used with one experiment at a time.")
    for experiment in experiments:
        tags, result_file = resolve_experiment(experiment, args.runs)
        if custom_tags:
            tags = custom_tags
        if args.command in ["generate", "run"]:
            generate_for_tags(
                tags,
                workers=args.workers,
                force=args.force,
                max_cases=args.max_cases,
            )
        if args.command in ["aggregate", "run"]:
            aggregate(tags, result_file, max_cases=args.max_cases)
        if args.command in ["evaluate", "run"]:
            evaluate_result_file(result_file, max_cases=args.max_cases)


def parse_args():
    parser = argparse.ArgumentParser(
        description="Run qwen3-max single and self-consistency baselines for FLAME."
    )
    parser.add_argument(
        "command",
        choices=["generate", "aggregate", "evaluate", "run"],
        help="generate calls the model, aggregate builds vote result files, evaluate reports Top-k, run does all three.",
    )
    parser.add_argument(
        "--experiment",
        choices=["single", "self_consistency", "both"],
        default="single",
        help="Baseline to run.",
    )
    parser.add_argument(
        "--runs",
        type=int,
        default=5,
        help="Number of qwen3-max samples for self_consistency.",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=4,
        help="Concurrent API calls.",
    )
    parser.add_argument(
        "--max-cases",
        type=int,
        default=None,
        help="Only run the first N cases, useful for smoke tests.",
    )
    parser.add_argument(
        "--force",
        action="store_true",
        help="Regenerate outputs even if annotated files already exist.",
    )
    parser.add_argument(
        "--tags",
        default=None,
        help="Comma-separated annotated-output tags to aggregate/evaluate, for example buggy-qwen3-max-1,buggy-qwen3-max-2.",
    )
    return parser.parse_args()


if __name__ == "__main__":
    run_command(parse_args())
