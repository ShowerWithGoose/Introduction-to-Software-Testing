package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class MulExp {
    private UnaryExp first;
    private ArrayList<Token> operators;
    private ArrayList<UnaryExp> follows;

    public MulExp(UnaryExp first, ArrayList<Token> operators, ArrayList<UnaryExp> follows) {
        this.first = first;
        this.operators = operators;
        this.follows = follows;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print());
        sb.append("<MulExp>\n");
        for (int i = 0; i < operators.size(); i++ ) {
            sb.append(operators.get(i).print());
            sb.append(follows.get(i).print());
            sb.append("<MulExp>\n");
        }
        return sb.toString();
    }

    public static MulExp parse(TokenIterator iterator) {
        UnaryExp first = UnaryExp.parse(iterator);
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<UnaryExp> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.MULT) || token.getType().equals(Token.Type.DIV) || token.getType().equals(Token.Type.MOD)) {
            operators.add(token);
            follows.add(UnaryExp.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new MulExp(first, operators, follows);
    }
}
