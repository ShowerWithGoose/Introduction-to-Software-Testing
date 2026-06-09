package frontend.Lexer;

import frontend.Parser.GrammarWord;

public class Token implements GrammarWord
{
    protected TokenType type;
    protected String content;
    protected int lineNo;
    public Token(){}

    public Token(TokenType type, String content, int lineNo){
        if(type != null) {
            this.type = type;
        }
        this.content = content;
        this.lineNo = lineNo;
    }


    @Override
    public String toString() {
        return type.toString() + " " + content;
    }


    public TokenType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineNo() {
        return lineNo;
    }
}
