package fronened.Parser;

import fronened.Lexer.TokenIterator;

public class ConstExp {
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.print());
        sb.append("<ConstExp>\n");
        return sb.toString();
    }

    public static ConstExp parse(TokenIterator iterator) {
        AddExp addExp = AddExp.parse(iterator);
        return new ConstExp(addExp);
    }
}
