package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.stmt.DeclStmt;

import java.util.ArrayList;
import java.util.HashSet;

public class VarDecl extends DeclStmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.INTTK);
        FIRST.add(TokenType.CHARTK);
    }

    private TokenType BType;
    private ArrayList<VarDef> varDefs;

    public VarDecl(TokenType BType, ArrayList<VarDef> varDefs) {
        this.BType = BType;
        this.varDefs = varDefs;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.BType;
        if (this.BType == TokenType.CHARTK) {
            string += " char\n";
        } else {
            string += " int\n";
        }
        string += this.varDefs.get(0).toString();
        for (int i = 1; i < this.varDefs.size(); i++) {
            string += (TokenType.COMMA + " ,\n");
            string += this.varDefs.get(i).toString();
        }
        string += (TokenType.SEMICN + " ;\n");
        string += "<VarDecl>\n";
        return string;
    }
}
