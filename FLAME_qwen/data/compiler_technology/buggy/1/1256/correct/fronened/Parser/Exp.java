package fronened.Parser;

import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class Exp {
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.print());
        sb.append("<Exp>\n");
        return sb.toString();
    }

    public static Exp parse(TokenIterator iterator) {
        AddExp addExp = AddExp.parse(iterator);
        return new Exp(addExp);
    }
}
