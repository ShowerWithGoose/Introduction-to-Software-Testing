package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class EqExp {
    private RelExp first;
    private ArrayList<Token> operators;
    private ArrayList<RelExp> follows;

    public EqExp(RelExp first, ArrayList<Token> operators, ArrayList<RelExp> follows) {
        this.first = first;
        this.operators = operators;
        this.follows = follows;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print());
        sb.append("<EqExp>\n");
        for (int i = 0; i < operators.size(); i++ ) {
            sb.append(operators.get(i).print());
            sb.append(follows.get(i).print());
            sb.append("<EqExp>\n");
        }
        return sb.toString();
    }

    public static EqExp parse(TokenIterator iterator) {
        RelExp first = RelExp.parse(iterator);
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<RelExp> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.EQL) || token.getType().equals(Token.Type.NEQ)) {
            operators.add(token);
            follows.add(RelExp.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new EqExp(first, operators, follows);
    }

}
