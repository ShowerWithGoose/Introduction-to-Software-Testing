package frontend.Parser.Exp;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class UnaryOpParser {
    private TokenListReader reader;
    public UnaryOpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public UnaryOp parseUnaryOp() {
        Token token = this.reader.getnextToken();
        if(!(token.getType().equals(TokenType.PLUS)||token.getType().equals(TokenType.MINU)||token.getType().equals(TokenType.NOT))){
            System.out.println("Error: invalid UnaryOp");
        }
        UnaryOp unaryOp = new UnaryOp(token);
        return unaryOp;
    }

}
