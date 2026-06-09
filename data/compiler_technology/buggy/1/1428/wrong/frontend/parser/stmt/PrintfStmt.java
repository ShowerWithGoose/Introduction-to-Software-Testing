package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.ArrayList;
import java.util.HashSet;

public class PrintfStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.PRINTFTK);
    }

    private String stringConst;
    private ArrayList<Exp> exps;

    public PrintfStmt(String stringConst, ArrayList<Exp> exps) {
        this.stringConst = stringConst;
        this.exps = exps;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.PRINTFTK + " printf\n");
        string += (TokenType.LPARENT + " (\n");
        string += (TokenType.STRCON + " " + this.stringConst + "\n");
        for (int i = 0; i < this.exps.size(); i++) {
            string += (TokenType.COMMA + " ,\n");
            string += this.exps.get(i).toString();
        }
        string += (TokenType.RPARENT + " )\n");
        string += (TokenType.SEMICN + " ;\n");
        string += "<Stmt>\n";
        return string;
    }
}
