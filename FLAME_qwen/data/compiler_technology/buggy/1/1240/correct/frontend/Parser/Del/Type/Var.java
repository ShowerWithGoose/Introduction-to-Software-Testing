package frontend.Parser.Del.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.constExp;

import java.util.ArrayList;

public class Var {
    // Var -> Ident [ '[' ConstExp ']' ]
    private final LexType ident;
    private final constExp constExp;
    private final ArrayList<LexType> braces;

    public Var(LexType ident, constExp constExp, ArrayList<LexType> braces) {
        this.ident = ident;
        this.constExp = constExp;
        this.braces = braces;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (braces.isEmpty()) {
            sb.append(ident.toString());
        } else if (braces.size() == 1) {
            sb.append(ident.toString()).append(braces.get(0).toString()).append(constExp.toString());
        } else {
            sb.append(ident.toString()).append(braces.get(0).toString()).
                    append(constExp.toString()).append(braces.get(1).toString());
        }
        return sb.toString();
    }
}
