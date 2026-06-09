package fronted.parser.expression;

import fronted.lexer.TokenList;

public class Exp {
    //Exp â†’ AddExp

    private AddExp addExp;

    private static final String name = "<Exp>\n";

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString(){
        return addExp.toString() + name;
    }

    public static Exp parse(TokenList list){
        return new Exp(AddExp.parse(list));
    }
}
