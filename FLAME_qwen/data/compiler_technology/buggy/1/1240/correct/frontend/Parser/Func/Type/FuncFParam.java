package frontend.Parser.Func.Type;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class FuncFParam {
    // FuncFParam â†’ BType Ident ['[' ']']
    private final LexType bType;
    private final LexType ident;
    private final ArrayList<LexType> braces;

    public FuncFParam(LexType bType, LexType ident, ArrayList<LexType> braces) {
        this.bType = bType;
        this.ident = ident;
        this.braces = braces;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.toString()).append(ident.toString());
        if (!braces.isEmpty()) {
            sb.append(braces.get(0).toString()).append(braces.get(1).toString());
        }
        sb.append("<FuncFParam>\n");
        return sb.toString();
    }
}
