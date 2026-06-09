from dotenv import load_dotenv
load_dotenv()

from openai import OpenAI

# 使用你提供的 base_url 和 api_key（请将 sk- 替换为真实密钥）
client = OpenAI(
    base_url="https://yunwu.ai/v1",
    api_key="sk-elt2aqVXBZIwjeC7KLcFknz5eIdWbV6ZG2yA5kjfbiiFW8d3"   # 请替换为你的实际 API Key
)

# 测试 chat 模型（claude-sonnet-4-6）
try:
    response = client.chat.completions.create(
        model="claude-sonnet-4-6",  # 根据网关实际支持的模型名调整
        messages=[
            {"role": "user", "content": "Hello, are you Claude? Please respond with a short greeting."}
        ],
        temperature=0.7,
        max_tokens=50
    )
    print("✅ 调用成功！")
    print("回复内容:", response.choices[0].message.content)
except Exception as e:
    print("❌ 调用失败:")
    print(f"错误类型: {type(e).__name__}")
    print(f"错误详情: {e}")