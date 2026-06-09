package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class ConstDecl {
    private Token constToken;
    private BType bType;
    private ArrayList<ConstDef> constDefs;
    private ArrayList<Token> commas;
    private Token semicn;

    public ConstDecl(Token constToken, BType bType, ArrayList<ConstDef> constDefs, ArrayList<Token> commas, Token semicn) {
        this.constToken = constToken;
        this.bType = bType;
        this.constDefs = constDefs;
        this.commas = commas;
        this.semicn = semicn;
    }

    public static ConstDecl parser(TokenIterator iterator) {
        Token token = iterator.next();
        Token constToken = null;
        BType bType = null;
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token semicn = null;
        if (token.getType().equals(Token.Type.CONSTTK)) {
            constToken = token;
        }
        else {
            System.out.println("Error: expecting const token");
        }
        bType = BType.parser(iterator);
        constDefs.add(ConstDef.parse(iterator));
        token = iterator.next();
        while (token.getType().equals(Token.Type.COMMA)) {
            commas.add(token);
            constDefs.add(ConstDef.parse(iterator));
            token = iterator.next();
        }
        if (token.getType().equals(Token.Type.SEMICN)) {
            semicn = token;
            return new ConstDecl(constToken, bType, constDefs, commas, semicn);
        }
        else {
            iterator.back();
            Error error = new Error(iterator.now_line(), 'i');
            ErrorList.addError(error);
            return new ConstDecl(constToken, bType, constDefs, commas, semicn);
        }

    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(constToken.print());
        sb.append(bType.print());
        sb.append(constDefs.get(0).print());
        if (!commas.isEmpty()) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).print());
                sb.append(constDefs.get(i+1).print());
            }
        }
        if (semicn != null) {
            sb.append(semicn.print());
        }
        sb.append("<ConstDecl>\n");
        return sb.toString();

    }
}
