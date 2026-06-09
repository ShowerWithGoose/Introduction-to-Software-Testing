from openai import OpenAI

client = OpenAI(
  api_key="sk-6271fd7deee4455d934d9e17f53cf0c8",
  base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
)

response = client.responses.create(
  model="deepseek-v3",
  input="write a haiku about ai",
  store=True,
)

print(response.output_text);
