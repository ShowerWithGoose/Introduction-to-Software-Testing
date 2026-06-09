package fronted.parser.function;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.declaration.BType;

import java.util.ArrayList;

public class FuncFParam {
    //FuncFParam â†’ BType Ident ['[' ']'] // k

    private BType type;

    private Token ident;

    private static final Token leftBrack = new Token(TokenType.Type.LBRACK,"[",1);

    private static final Token rightBrack = new Token(TokenType.Type.RBRACK,"]",1);

    private ArrayList<Token> symbols;

    private static final String name = "<FuncFParam>\n";

    public FuncFParam(BType type,Token ident,ArrayList<Token> symbols) {
        this.type = type;
        this.ident = ident;
        this.symbols = symbols;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(type.toString());
        sb.append(ident.toString());
        for (Token token : symbols) {
            sb.append(token.toString());
        }
        sb.append(name);
        return sb.toString();
    }

    public static FuncFParam parse(TokenList list) {
        BType bType = null;
        Token ident = null;
        ArrayList<Token> symbols = new ArrayList<>();
        bType = BType.parse(list);
        if (list.now().getType().equals(TokenType.Type.IDENFR)) {
            ident = list.now();
            list.next();
        } else {
            System.err.println("Error:FuncDef cannot find ident");
            return null;
        }
        if (list.now().getType().equals(TokenType.Type.LBRACK)) {
            symbols.add(list.now());
            list.next();
            if (list.now().getType().equals(TokenType.Type.RBRACK)) {
                symbols.add(list.now());
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'k');
            }
        }
        return new FuncFParam(bType,ident,symbols);

    }
}
