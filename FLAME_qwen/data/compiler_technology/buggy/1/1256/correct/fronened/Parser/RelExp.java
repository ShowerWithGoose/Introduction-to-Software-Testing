package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class RelExp {
    private AddExp first;
    private ArrayList<Token> operators;
    private ArrayList<AddExp> follows;

    public RelExp(AddExp first, ArrayList<Token> operators, ArrayList<AddExp> follows) {
        this.first = first;
        this.operators = operators;
        this.follows = follows;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print());
        sb.append("<RelExp>\n");
        for (int i = 0; i < operators.size(); i++ ) {
            sb.append(operators.get(i).print());
            sb.append(follows.get(i).print());
            sb.append("<RelExp>\n");
        }
        return sb.toString();
    }

    public static RelExp parse(TokenIterator iterator) {
        AddExp first = AddExp.parse(iterator);
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<AddExp> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.LSS) || token.getType().equals(Token.Type.LEQ) || token.getType().equals(Token.Type.GRE) || token.getType().equals(Token.Type.GEQ)) {
            operators.add(token);
            follows.add(AddExp.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new RelExp(first, operators, follows);
    }
}
