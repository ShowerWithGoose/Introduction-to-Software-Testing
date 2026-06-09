package frontend.ast;

import frontend.Token;
import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VarDef implements AstNode {
    private final Token ident;
    private final ConstExp constExp;
    private final InitVal initVal;

    public VarDef(Token ident) {
        this.ident = ident;
        constExp = null;
        initVal = null;
    }

    public VarDef(Token ident, ConstExp constExp) {
        this.ident = ident;
        this.constExp = constExp;
        initVal = null;
    }

    public VarDef(Token ident, InitVal initVal) {
        this.ident = ident;
        constExp = null;
        this.initVal = initVal;
    }

    public VarDef(Token ident, ConstExp constExp, InitVal initVal) {
        this.ident = ident;
        this.constExp = constExp;
        this.initVal = initVal;
    }

    @Override
    public String getSymbol() {
        return "<VarDef>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        bw.write(ident.toString() + "\n");
        if (constExp != null) {
            bw.write(TokenType.LBRACK + " [\n");
            constExp.printToFile(bw);
            bw.write(TokenType.RBRACK + " ]\n");
        }
        if (initVal != null) {
            bw.write(TokenType.ASSIGN + " =\n");
            initVal.printToFile(bw);
        }
        bw.write(getSymbol() + "\n");
    }
}
