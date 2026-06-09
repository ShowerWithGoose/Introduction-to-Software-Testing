package frontend.Parser.Exp.Type;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class LVal implements PEinterface{
    // LVal â†’ Ident ['[' Exp ']']
    private final LexType ident;
    private final Exp exp;
    private final ArrayList<LexType> brace;

    public LVal(LexType ident, Exp exp, ArrayList<LexType> brace) {
        this.ident = ident;
        this.exp = exp;
        this.brace = brace;
    }

    public int getLine() {
        return ident.getLine();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (brace == null) {
            sb.append(ident.toString());
        } else if (brace.size() == 1) {
            sb.append(ident.toString()).append(brace.get(0).toString()).append(exp.toString());
        } else {
            sb.append(ident.toString()).append(brace.get(0).toString()).
                    append(exp.toString()).append(brace.get(1).toString());
        }
        sb.append("<LVal>\n");
        return sb.toString();
    }
}
