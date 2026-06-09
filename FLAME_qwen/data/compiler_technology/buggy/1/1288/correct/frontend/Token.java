package frontend;

public class Token {
    private String name;
    private Type type;
    private Long num;   //这里只用Long，防止溢出（int的范围是-2147483648~2147483647，词法分析最小值时就会爆int）

    private int line;
    public Token(String name, Type type, int line) {
        this.name = name;
        this.type = type;
        this.line = line;
    }

    public Token(String name, Type type, Long num, int line) {
        this.name = name;
        this.type = type;
        this.num = num;
        this.line = line;
    }

    public String getName() {
        return name;
    }

    public Type getType() {
        return type;
    }
    public int getLine() {
        return line;
    }
}
