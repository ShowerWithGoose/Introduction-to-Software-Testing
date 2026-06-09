package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
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

    public void parser(Lexer lexer) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.CONSTTK ||
                nowType == Token.Type.INTTK ||
                nowType == Token.Type.CHARTK) {
            decl = new Decl();
            decl.parser(lexer);
            lineCnt = decl.getLineCnt();
        } else {
            stmt = new Stmt();
            stmt.parser(lexer);
            lineCnt = stmt.getLineCnt();
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symTable) {
        if (decl != null) {
            decl.analyze(symTable);
        } else {
            stmt.analyze(symTable);
        }
    }

    public boolean isReturnStmt() {
        if (stmt != null) {
            return stmt.getStmtType() == Stmt.StmtType.RETURNSTMT;
        } else {
            return false;
        }
    }
}
