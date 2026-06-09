package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class FuncRParams {
    private Exp first;
    private ArrayList<Token> commas;
    private ArrayList<Exp> follows;

    public FuncRParams(Exp first, ArrayList<Token> commas, ArrayList<Exp> follows) {
        this.first = first;
        this.commas = commas;
        this.follows = follows;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print());
        if (!commas.isEmpty()) {
            for(int i = 0;i < commas.size();i++) {
                sb.append(commas.get(i).print());
                sb.append(follows.get(i).print());
            }
        }
        sb.append("<FuncRParams>\n");
        return sb.toString();
    }

    public static FuncRParams parse(TokenIterator iterator) {
        Exp first = Exp.parse(iterator);
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.COMMA)) {
            commas.add(token);
            follows.add(Exp.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new FuncRParams(first, commas, follows);
    }
}
