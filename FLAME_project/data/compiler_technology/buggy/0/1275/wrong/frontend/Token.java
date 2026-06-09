package frontend;

// Token 类用于存储单词信息
class Token {
    String type; // 单词类别
    String value; // 单词值
    int line; // 所在行号

    public Token(String type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }
    public String getType() {
        return type;
    }

    public String getValue() {
        return value;
    }
    @Override
    public String toString() {
        return type + " " + value;
    }
}
