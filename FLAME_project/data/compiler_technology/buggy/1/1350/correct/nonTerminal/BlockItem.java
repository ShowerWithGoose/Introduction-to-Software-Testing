package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class BlockItem {
    private Decl decl;
    private Stmt stmt;
    private int lineCnt;

    public BlockItem() {
        decl = null;
        stmt = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.CONSTTK ||
                nowType == Token.Type.INTTK ||
                nowType == Token.Type.CHARTK) {
            decl = new Decl();
            decl.parser(lexer, errors);
            lineCnt = decl.getLineCnt();
        } else {
            stmt = new Stmt();
            stmt.parser(lexer, errors);
            lineCnt = stmt.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (decl != null) {
            decl.output(parserResult);
        }
        if (stmt != null) {
            stmt.output(parserResult);
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
