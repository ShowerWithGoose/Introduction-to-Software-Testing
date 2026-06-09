import os
from typing import Tuple, List

from openai import OpenAI


openai_client = OpenAI(
    base_url=os.environ["OPENAI_BASE_URL"],
    api_key=os.environ["OPENAI_API_KEY"],
)
qwen_client = OpenAI(
    base_url=os.environ["QWEN_BASE_URL"],
    api_key=os.environ["QWEN_API_KEY"],
)
claude_client = OpenAI(
    base_url=os.environ["CLAUDE_BASE_URL"],
    api_key=os.environ["CLAUDE_API_KEY"],
)
deepseek_client = OpenAI(
    base_url=os.environ["DEEPSEEK_BASE_URL"],
    api_key=os.environ["DEEPSEEK_API_KEY"],
)


def generate_embedding(code: str, model="text-embedding-v4") -> List[float]:
    try:
        response = qwen_client.embeddings.create(
            input=code,
            model=model,
        )
    except Exception as e:
        print(f'Error: {e}')
        return None
    embedding = response.data[0].embedding
    return embedding


def chat_completion(prompt: str, model: str, history_messages=None, temperature=0.1) -> Tuple[str, list]:
    system_prompt = "You are a highly skilled and knowledgeable programming assistant, focused on helping student debug  assignment code.You should carefully analyze the code for logical and semantic errors."
    if history_messages is None:
        messages = [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": prompt},
        ]
    else:
        messages = history_messages + [
            {"role": "user", "content": prompt},
        ]
    if model.startswith("qwen"):
        client = qwen_client
    elif model.startswith("deepseek"):
        client = deepseek_client
    elif model.startswith("claude"):
        client = claude_client
    else:
        client = qwen_client
    try:
        completion = client.chat.completions.create(
            model=model,
            messages=messages,
            temperature=temperature,
            max_completion_tokens=8192,
        )
    except Exception as e:
        error_msg = f"{type(e).__name__}: {str(e)}"
        print(f"[chat_completion] Error for model {model}: {error_msg}")  # 控制台直接输出
        return None, error_msg
    if completion is None:
        return None, None
    messages.append(
        {
            "role": "assistant",
            "content": completion.choices[0].message.content,
        }
    )
    completion = completion.choices[0].message.content
    return completion, messages


def extract_code(markdown: str, language=None) -> str:
    try:
        if "```" not in markdown:
            return markdown
        if language is None:
            code = markdown.split("```")[1].strip()
        else:
            code = markdown.split(f"```{language}")[1].split("```")[0].strip()
    except Exception as e:
        return None
    return code


def extract_json(markdown: str) -> str:
    code = markdown.split("```json")[1].split("```")[0].strip()
    return code
