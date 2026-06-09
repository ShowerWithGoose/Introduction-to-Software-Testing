package fronted.parser.expression;

import fronted.lexer.TokenList;

public class Cond {
    // Cond â†’ LOrExp

    private LOrExp exp;

    private static final String name = "<Cond>\n";

    public Cond(LOrExp exp) {
        this.exp = exp;
    }

    @Override
    public String toString(){
        return exp.toString() + name;
    }

    public static Cond parse(TokenList list){
       return new Cond(LOrExp.parse(list));
    }
}
