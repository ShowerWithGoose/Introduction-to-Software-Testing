package frontend.ast;

import frontend.Token;
import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;

public class LVal implements AstNode {
    private final Token ident;
    private final Exp exp;

    public LVal(Token ident, Exp exp) {
        this.exp = exp;
        this.ident = ident;
    }

    public LVal(Token ident) {
        this.exp = null;
        this.ident = ident;
    }

    @Override
    public String getSymbol() {
        return "<LVal>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        bw.write(ident + "\n");
        if (exp != null) {
            bw.write(TokenType.LBRACK + " [\n");
            exp.printToFile(bw);
            bw.write(TokenType.RBRACK + " ]\n");
        }
        bw.write(getSymbol() + "\n");
    }
}
