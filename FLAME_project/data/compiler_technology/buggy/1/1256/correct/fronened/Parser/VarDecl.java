package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class VarDecl {
    private BType bType;
    private VarDef first;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> follows;
    private Token semicn;

    public VarDecl(BType bType, VarDef first, ArrayList<Token> commas, ArrayList<VarDef> follows, Token semicn) {
        this.bType = bType;
        this.first = first;
        this.commas = commas;
        this.follows = follows;
        this.semicn = semicn;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.print());
        sb.append(first.print());
        if (!commas.isEmpty()) {
            for(int i = 0;i < commas.size();i++) {
                sb.append(commas.get(i).print());
                sb.append(follows.get(i).print());
            }
        }
        if (semicn != null) {
            sb.append(semicn.print());
        }
        sb.append("<VarDecl>\n");
        return sb.toString();
    }

    public static VarDecl parse(TokenIterator iterator) {
        BType bType = BType.parser(iterator);
        VarDef first = VarDef.parse(iterator);
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<VarDef> follows = new ArrayList<>();
        Token semicn = null;
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.COMMA)) {
            commas.add(token);
            follows.add(VarDef.parse(iterator));
            token = iterator.next();
        }
        if (token.getType().equals(Token.Type.SEMICN)) {
            semicn = token;
        }
        else {
            iterator.back();
            Error error = new Error(iterator.now_line(), 'i');
            ErrorList.addError(error);
        }
        return new VarDecl(bType, first, commas, follows, semicn);
    }

}
