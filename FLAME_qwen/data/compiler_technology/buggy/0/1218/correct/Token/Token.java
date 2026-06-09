package Token;

public class Token {
    TokenType type;
    String content;
    int lineno;
    public Token(TokenType tokentype, String content, int lineno){
        this.type = tokentype;
        this.content = content;
        this.lineno = lineno;
    }
    @Override
    public String toString(){
        return type.toString() + ' ' + content + '\n';
    }

}
