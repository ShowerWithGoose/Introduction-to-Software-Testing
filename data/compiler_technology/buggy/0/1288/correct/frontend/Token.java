package frontend;

public class Token {
    private String name;
    private Type type;
    private Long num;   //这里只用Long，防止溢出（int的范围是-2147483648~2147483647，词法分析最小值时就会爆int）

    public Token(String name, Type type) {
        this.name = name;
        this.type = type;
    }

    public Token(String name, Type type, Long num) {
        this.name = name;
        this.type = type;
        this.num = num;
    }

    public String getName() {
        return name;
    }

    public Type getType() {
        return type;
    }
}
