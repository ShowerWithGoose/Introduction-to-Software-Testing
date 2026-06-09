package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class LAndExp {
    private EqExp first;
    private ArrayList<Token> operators;
    private ArrayList<EqExp> follows;


    public LAndExp(EqExp first, ArrayList<Token> operators, ArrayList<EqExp> follows) {
        this.first = first;
        this.operators = operators;
        this.follows = follows;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print());
        sb.append("<LAndExp>\n");
        for (int i = 0; i < operators.size(); i++ ) {
            sb.append(operators.get(i).print());
            sb.append(follows.get(i).print());
            sb.append("<LAndExp>\n");
        }
        return sb.toString();
    }

    public static LAndExp parse(TokenIterator iterator) {
        EqExp first = EqExp.parse(iterator);
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<EqExp> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.AND)) {
            operators.add(token);
            follows.add(EqExp.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new LAndExp(first, operators, follows);
    }
}
