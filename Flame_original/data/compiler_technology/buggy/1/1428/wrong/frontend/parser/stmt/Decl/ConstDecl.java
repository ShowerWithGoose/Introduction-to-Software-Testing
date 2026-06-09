package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.stmt.DeclStmt;

import java.util.ArrayList;
import java.util.HashSet;

public class ConstDecl extends DeclStmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.CONSTTK);
    }

    private TokenType BType;
    private ArrayList<ConstDef> constDefs;

    public ConstDecl(TokenType BType, ArrayList<ConstDef> constDefs) {
        this.BType = BType;
        this.constDefs = constDefs;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.CONSTTK + " const\n");
        string += this.BType;
        if (this.BType == TokenType.CHARTK) {
            string += " char\n";
        } else {
            string += " int\n";
        }
        string += this.constDefs.get(0).toString();
        for (int i = 1; i < this.constDefs.size(); i++) {
            string += (TokenType.COMMA + " ,\n");
            string += this.constDefs.get(i).toString();
        }
        string += (TokenType.SEMICN + " ;\n");
        string += "<ConstDecl>\n";
        return string;
    }
}
