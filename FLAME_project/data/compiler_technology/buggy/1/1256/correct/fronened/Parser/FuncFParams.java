package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;
import java.util.function.Function;

public class FuncFParams {
    private FuncFParam first;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> follows;

    public FuncFParams(FuncFParam first, ArrayList<Token> commas, ArrayList<FuncFParam> follows) {
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
        sb.append("<FuncFParams>\n");
        return sb.toString();
    }

    public static FuncFParams parse(TokenIterator iterator) {
        FuncFParam first = FuncFParam.parse(iterator);
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<FuncFParam> follows = new ArrayList<>();
        Token token = iterator.next();
        while (token.getType().equals(Token.Type.COMMA)) {
            commas.add(token);
            follows.add(FuncFParam.parse(iterator));
            token = iterator.next();
        }
        iterator.back();
        return new FuncFParams(first, commas, follows);
    }
}
