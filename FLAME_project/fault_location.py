import json
import os
import concurrent.futures

from tqdm import tqdm

from generate_embedding import detect_encoding, find_nearest_reference, find_reference_by_path
from util.openai_util import chat_completion, extract_code
from util.config import BUGGY_PATH, PROBLEM_PATH, PROJECT
from util.prompt_util import (
    generate_prompt_ds,
    generate_prompt_ds_json,
    generate_prompt_compile_step_1,
    generate_prompt_compile_step_2,
    generate_prompt_compile_json,
    generate_prompt_deflects4j,
)


problem_list = os.listdir(BUGGY_PATH)

model_file_name = {
    "deepseek-chat": "deepseek-chat",
    "deepseek-reasoner": "deepseek-reasoner",
    "qwen3.6-plus": "qwen3.6-plus",
    "qwen3-max": "qwen3-max",
}

model = "qwen3-max"
with_problem_description = True
with_reference = True
with_TC = True
extra_tag = "-1"
json_output_mode = False

file_tag = f"buggy-{model_file_name[model]}{'' if with_reference else '-nr'}{'' if with_problem_description else '-npd'}{'' if with_TC else '-ntc'}{extra_tag}"

if PROJECT.startswith("data_structures"):
    output_file_name_extension = "c"
    buggy_file_name_extension = "c"
if PROJECT.startswith("compiler_technology"):
    output_file_name_extension = "txt"
    buggy_file_name_extension = "txt"
if PROJECT.startswith("test_ds"):
    output_file_name_extension = "c"
    buggy_file_name_extension = "c"
if PROJECT.startswith("deflects4j"):
    output_file_name_extension = "txt"
    buggy_file_name_extension = "txt"
if json_output_mode:
    output_file_name_extension = "json"

concurrent_mode = True
max_workers = 8


def process_and_save(prompt: str, student_path: str):
    res, messages = chat_completion(prompt, model=model)
    if res is None:
        tqdm.write(f"Error: {student_path}, Exception: {messages}")
        return
    if PROJECT.startswith("data_structures"):
        annotated_src = extract_code(res, output_file_name_extension)
        if annotated_src is None:
            tqdm.write(f"Error: {student_path}")
            return
    if PROJECT.startswith("compiler_technology"):
        if json_output_mode:
            annotated_src = extract_code(res, output_file_name_extension)
            if annotated_src is None:
                tqdm.write(f"Error: {student_path}")
                return
        else:
            # save the wrong snippet for further debugging
            wrong_snippet_path = os.path.join(student_path, "wrong-snippet")
            os.makedirs(wrong_snippet_path, exist_ok=True)
            with open(os.path.join(wrong_snippet_path, f"{file_tag}.txt"), "w") as f:
                f.write(res)
            # generate the second step prompt
            prompt_step_2 = generate_prompt_compile_step_2()
            res, e = chat_completion(prompt_step_2, model=model, history_messages=messages)
            if res is None:
                tqdm.write(f"Error: {student_path}, Exception: {e}")
                return
            annotated_src = res
    if PROJECT.startswith("test_ds"):
        annotated_src = extract_code(res, output_file_name_extension)
        if annotated_src is None:
            tqdm.write(f"Error: {student_path}")
            return
    if PROJECT.startswith("deflects4j"):
        annotated_src = extract_code(res, "java")
        if annotated_src is None:
            tqdm.write(f"Error: {student_path}")
            return
    with open(os.path.join(student_path, f"{file_tag}.{output_file_name_extension}"), "w", encoding="utf-8") as f:
        if annotated_src:
            f.write(annotated_src)


def generate_answer():
    executor = concurrent.futures.ThreadPoolExecutor(max_workers=max_workers)
    for problem in sorted(problem_list):
        futures = []
        buggy_problem_path = os.path.join(BUGGY_PATH, problem)
        if with_problem_description:
            problem_description_file = os.path.join(PROBLEM_PATH, problem, "description.txt")
            with open(problem_description_file, "r", encoding="utf-8") as f:
                problem_description = f.read()
        else:
            problem_description = ""
        for student in tqdm(sorted(os.listdir(buggy_problem_path))):
            if os.path.exists(os.path.join(buggy_problem_path, student, f"{file_tag}.{output_file_name_extension}")):
                continue
            student_path = os.path.join(buggy_problem_path, student)
            buggy_src_file = os.path.join(student_path, f"buggy.{buggy_file_name_extension}")
            if not os.path.exists(buggy_src_file):
                continue
            encoding = detect_encoding(buggy_src_file)["encoding"]
            with open(buggy_src_file, "r", encoding=encoding, errors="ignore") as f:
                buggy_src = f.read().rstrip()
            if with_TC:
                if not os.path.exists(os.path.join(student_path, "error_message.json")):
                    continue
                error_message_file = os.path.join(student_path, "error_message.json")
                with open(error_message_file, "r", encoding="utf-8") as f:
                    error_message = json.load(f)
                if error_message is None:
                    continue
            else:
                error_message = []
            if PROJECT.startswith("data_structures") and with_reference:
                reference = find_reference_by_path(problem, student_path, reference_root="data/data_structures/debugta_effective_reference")
            elif PROJECT.startswith("test_ds") and with_reference:
                reference = find_reference_by_path(problem, student_path)
            else:
                reference = ""
            if PROJECT.startswith("data_structures") or PROJECT.startswith("test_ds"):
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
            if PROJECT.startswith("compiler_technology"):
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
            if PROJECT.startswith("deflects4j"):
                with open(os.path.join(student_path, "description.txt"), "r") as f:
                    function_comment = f.read()
                if json_output_mode:
                    continue
                else:
                    prompt = generate_prompt_deflects4j(
                        problem_description=problem_description,
                        function_comment=function_comment,
                        error_message=error_message,
                        src_code=buggy_src,
                    )
            # replace tabs with spaces for better formatting
            prompt = prompt.replace("\t", "    ")
            with open(os.path.join(student_path, "prompt.txt"), "w", encoding="utf-8") as f:
                f.write(prompt)
            if concurrent_mode:
                future = executor.submit(process_and_save, prompt, student_path)
                futures.append(future)
            else:
                process_and_save(prompt, student_path)
        # wait for all futures to complete
        if concurrent_mode:
            for future in tqdm(concurrent.futures.as_completed(futures), total=len(futures)):
                future.result()
    executor.shutdown()


def main():
    # note that different models may need different BASE_URL and API_KEY
    print(f"Running fault location...")
    model_list = ["deepseek-chat", "deepseek-reasoner", "qwen3.6-plus", "qwen3-max"]
    model_duplicate = 2
    global model, file_tag, extra_tag
    print("number of model : ", len(model_list))
    for model in model_list:
        print("model name: ", model)
        for i in range(model_duplicate):
            extra_tag = f"-{i + 1}"
            file_tag = f"buggy-{model_file_name[model]}{'' if with_reference else '-nr'}{'' if with_problem_description else '-npd'}{'' if with_TC else '-ntc'}{extra_tag}"
            generate_answer()


if __name__ == "__main__":
    main()
