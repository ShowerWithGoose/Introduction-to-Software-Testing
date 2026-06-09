package frontend;

public class Token {
    private StringBuilder name;
    private Type type;
    private int num;

    public Token() {
        name = new StringBuilder();
        num = 0;
    }
    public Token(Type t){
        type = t;
    }

    public void append(char c) {
        name.append(c);
    }

    public void enNum(int num) {
        this.num = num;
    }

    public void enType(Type t) {
        type = t;
    }

    public String getName() {
        return name.toString();
    }

    public Type getType() {
        return type;
    }

    public int getNum() {
        return num;
    }

    /*public void changeName(String s){
        name = new StringBuilder(s);
    }*/
    public void clone(Token t) {
        name = new StringBuilder(t.getName());
        type = t.getType();
        num = t.getNum();
    }
}
