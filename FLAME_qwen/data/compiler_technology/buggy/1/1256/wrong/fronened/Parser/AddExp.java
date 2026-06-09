package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class AddExp {
    private MulExp first;
    private ArrayList<Token> operators;
    private ArrayList<MulExp> follows;

    public AddExp(MulExp first, ArrayList<Token> operators, ArrayList<MulExp> follows) {
        this.first = first;
        this.operators = operators;
        this.follows = follows;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print());
        sb.append("<AddExp>\n");
        for (int i = 0; i < operators.size(); i++ ) {
            sb.append(operators.get(i).print());
            sb.append(follows.get(i).print());
            sb.append("<AddExp>\n");
        }
        return sb.toString();
    }

    public static AddExp parse(TokenIterator iterator) {
        MulExp first = MulExp.parse(iterator);
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<MulExp> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.PLUS) || token.getType().equals(Token.Type.MINU)) {
            operators.add(token);
            follows.add(MulExp.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new AddExp(first, operators, follows);
    }
}
