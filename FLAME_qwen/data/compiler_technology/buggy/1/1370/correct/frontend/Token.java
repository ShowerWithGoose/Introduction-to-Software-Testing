package frontend;

public class Token implements Node{
    private TokenType tokenType;
    private String content;
    private int lineno;
    private String message;

    public Token(TokenType tokenType,String content,int lineno,String message){
        this.tokenType = tokenType;
        this.content = content;
        this.lineno = lineno;
        this.message= message;
    }
    public Token parser(Token token){
        return null;
    }

    @Override
    public String toString(){
        return content;
    }

    public TokenType getTokenType(){
        return this.tokenType;
    }

    public int getLineno(){
        return this.lineno;
    }

    public void printToFile(){
        WriteIntoF.getInstance().writeToFile(true,this.message);
    }

}
