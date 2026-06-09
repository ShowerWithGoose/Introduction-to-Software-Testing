public class Token {

    private final TokenType.Type type;
    //the type of it
    private final String value;
    //the specific value of it
    private final int line;
    //the line it belongs to

    private int number;
    //数值

    private boolean ifCorrect;

    public Token(TokenType.Type type,String value,int line){
        this.type = type;
        this.value = value;
        this.line = line;
        if (type == TokenType.Type.INTCON) {
            this.number = Integer.parseInt(value);
        }
        this.ifCorrect = true;
    }

    public TokenType.Type getType() {
        return type;
    }

    public int getNumber() {
        return number;
    }

    public String getValue() {
        return value;
    }

    public int getLine() {
        return line;
    }

    public boolean isIfCorrect() {
        return ifCorrect;
    }

    public void setFalse() {
        this.ifCorrect = false;
    }

    @Override
    public String toString(){
        return type.toString() + " " + value;
    }
}
