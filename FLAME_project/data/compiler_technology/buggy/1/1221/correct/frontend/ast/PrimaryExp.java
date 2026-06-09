package frontend.ast;

import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;

public class PrimaryExp implements AstNode {
    private final AstNode primaryExp;

    public PrimaryExp(Exp exp) {
        primaryExp = exp;
    }

    public PrimaryExp(LVal lVal) {
        primaryExp = lVal;
    }

    public PrimaryExp(Number number) {
        primaryExp = number;
    }

    public PrimaryExp(Character character) {
        primaryExp = character;
    }

    @Override
    public String getSymbol() {
        return "<PrimaryExp>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        if (primaryExp instanceof Exp) {
            bw.write(TokenType.LPARENT + " (\n");
            primaryExp.printToFile(bw);
            bw.write(TokenType.RPARENT + " )\n");
        } else if (primaryExp instanceof LVal) {
            primaryExp.printToFile(bw);
        } else if (primaryExp instanceof Number) {
            primaryExp.printToFile(bw);
        } else if (primaryExp instanceof Character) {
            primaryExp.printToFile(bw);
        }
        bw.write(getSymbol() + "\n");
    }
}
