import os
import pickle

from tqdm import tqdm
import chardet
import numpy as np

from util.openai_util import generate_embedding
from util.config import BUGGY_PATH, REFERENCE_PATH, PROJECT


def cosine_similarity(embedding1, embedding2):
    dot_product = np.dot(embedding1, embedding2)
    norm_embedding1 = np.linalg.norm(embedding1)
    norm_embedding2 = np.linalg.norm(embedding2)
    return dot_product / (norm_embedding1 * norm_embedding2)


def detect_encoding(file_path):
    with open(file_path, "rb") as f:
        raw_data = f.read()
        result = chardet.detect(raw_data)
        return result


def process_programs(problem, programs, program_path, embedding_path, file_name):
    for program in tqdm(programs):
        save_path = os.path.join(embedding_path, problem, program)
        if os.path.exists(os.path.join(save_path, f"{file_name}-embedding.pkl")):
            continue
        program_file_path = os.path.join(program_path, problem, program, f"{file_name}.c")
        encoding = detect_encoding(program_file_path)["encoding"]
        with open(program_file_path, "r", encoding=encoding, errors="ignore") as f:
            code = f.read()
        MAX_CHARS = 8192
        if len(code) > MAX_CHARS:
            code = code[:MAX_CHARS]
            tqdm.write(f"Warning: Truncated {program_file_path} to {MAX_CHARS} chars")
        embedding = generate_embedding(code)
        if not embedding:
            tqdm.write(f"Failed to generate embedding for {program_file_path}")
            continue
        os.makedirs(save_path, exist_ok=True)
        with open(os.path.join(save_path, f"{file_name}-embedding.pkl"), "wb") as f:
            pickle.dump(embedding, f)


def find_nearest_reference(problem: str, BUGGY_PATH: str):
    reference_programs = os.listdir(os.path.join(REFERENCE_PATH, problem))
    buggy_program_embedding_path = os.path.join(BUGGY_PATH, "buggy-embedding.pkl")
    with open(buggy_program_embedding_path, "rb") as f:
        buggy_embedding = pickle.load(f)
    max_similarity = 0
    for reference_program in reference_programs:
        reference_program_embedding_path = os.path.join(REFERENCE_PATH, problem, reference_program, "correct-embedding.pkl")
        if not os.path.exists(reference_program_embedding_path):
            continue
        with open(reference_program_embedding_path, "rb") as f:
            reference_embedding = pickle.load(f)
        similarity = cosine_similarity(buggy_embedding, reference_embedding)
        if similarity > max_similarity:
            max_similarity = similarity
            most_similar_program = reference_program
    # print(os.path.join(REFERENCE_PATH, problem, most_similar_program, "correct.c"))
    # print(f"Most similar program: {most_similar_program}, similarity: {max_similarity}")
    reference_program_path = os.path.join(REFERENCE_PATH, problem, most_similar_program, "correct.c")
    encoding = detect_encoding(reference_program_path)["encoding"]
    with open(reference_program_path, "r", encoding=encoding, errors="ignore") as f:
        reference_program_src = f.read().lstrip().rstrip()
    return reference_program_src


def find_reference_by_path(problem: str, student_path: str, reference_root: str = REFERENCE_PATH) -> str:
    """
    根据学生错误代码的路径，从 reference 目录下相同子路径获取 correct.c
    :param problem: 问题编号（如 "0"）
    :param student_path: 学生目录的完整路径，例如 `.../buggy/0/1738`
    :param reference_root: 参考代码根目录，默认为 REFERENCE_PATH
    :return: 参考代码的源代码字符串，如果文件不存在则返回空字符串
    """
    student_id = os.path.basename(student_path)          # 获取学生ID，如 "1738"
    ref_c_file = os.path.join(reference_root, problem, student_id, "effective_reference.c")
    if not os.path.exists(ref_c_file):
        print("Error,correct")
        return ""
    encoding = detect_encoding(ref_c_file)["encoding"]
    with open(ref_c_file, "r", encoding=encoding, errors="ignore") as f:
        return f.read().lstrip().rstrip()


def main():
    print("Generating embeddings for buggy and reference programs...")
    if PROJECT.startswith("data_structures"):
        for problem in os.listdir(BUGGY_PATH):
            buggy_programs = os.listdir(os.path.join(BUGGY_PATH, problem))
            reference_programs = os.listdir(os.path.join(REFERENCE_PATH, problem))

            print(f"Problem: {problem}")
            print(f"Buggy programs: {len(buggy_programs)}")
            print(f"Reference programs: {len(reference_programs)}")
            process_programs(problem, buggy_programs, BUGGY_PATH, BUGGY_PATH, "buggy")
            process_programs(problem, reference_programs, REFERENCE_PATH, REFERENCE_PATH, "correct")


if __name__ == "__main__":
    main()
