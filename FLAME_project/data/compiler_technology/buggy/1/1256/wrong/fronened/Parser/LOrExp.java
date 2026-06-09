package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class LOrExp {
    private LAndExp first;
    private ArrayList<Token> operators;
    private ArrayList<LAndExp> follows;


    public LOrExp(LAndExp first, ArrayList<Token> operators, ArrayList<LAndExp> follows) {
        this.first = first;
        this.operators = operators;
        this.follows = follows;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print());
        sb.append("<LOrExp>\n");
        for (int i = 0; i < operators.size(); i++ ) {
            sb.append(operators.get(i).print());
            sb.append(follows.get(i).print());
            sb.append("<LOrExp>\n");
        }
        return sb.toString();
    }

    public static LOrExp parse(TokenIterator iterator) {
        LAndExp first = LAndExp.parse(iterator);
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<LAndExp> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.OR)) {
            operators.add(token);
            follows.add(LAndExp.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new LOrExp(first, operators, follows);
    }
}
