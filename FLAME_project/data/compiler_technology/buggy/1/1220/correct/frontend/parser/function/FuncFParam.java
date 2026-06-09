package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.declaration.BType;

public class FuncFParam implements SyntaxUnit {
    // FuncFParam → BType Ident ['[' ']']
    private String name = "<FuncFParam>";
    private BType bType;
    private Token ident;
    private Token leftBracket;
    private Token rightBracket;

    public FuncFParam(BType bType, Token ident,
                      Token leftBracket, Token rightBracket) {
        this.bType = bType;
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
    }

    @Override
    public String syntaxPrint() {
        //FuncFParam → BType Ident ['[' ']']
        StringBuilder sb = new StringBuilder();
        sb.append(bType.syntaxPrint());
        sb.append(ident.syntaxPrint());
        if (leftBracket != null) {
            sb.append(leftBracket.syntaxPrint());
        }
        if (rightBracket != null) {
            sb.append(rightBracket.syntaxPrint());
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}
