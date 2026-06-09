public class Token {
    private TokenType tokenType;
    private String content;
    private int lineno;

    public Token(TokenType tokenType,String content,int lineno){
        this.tokenType = tokenType;
        this.content = content;
        this.lineno = lineno;
    }

    @Override
    public String toString(){
        return content;
    }


}
