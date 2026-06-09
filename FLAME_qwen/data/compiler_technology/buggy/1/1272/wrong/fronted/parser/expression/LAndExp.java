package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class LAndExp {
    // LAndExp → EqExp | LAndExp '&&' EqExp
    // LAndExp → EqExp {'&&' EqExp }

    private ArrayList<EqExp> exps;

    private ArrayList<Token> tokens;

    private static final String name = "<LAndExp>\n";

    public LAndExp(ArrayList<EqExp> exps, ArrayList<Token> tokens) {
        this.exps = exps;
        this.tokens = tokens;
    }

    @Override
    public String toString(){
        int num = exps.size();
        StringBuilder sb = new StringBuilder();
        sb.append(exps.get(0).toString());
        sb.append(name);
        for (int i = 1;i < num;i = i + 1) {
            sb.append(tokens.get(i-1).toString());
            sb.append(exps.get(i).toString());
            sb.append(name);
        }
        return sb.toString();
    }

    public static LAndExp parse(TokenList list){
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<EqExp> exps = new ArrayList<>();
        EqExp exp = EqExp.parse(list);
        exps.add(exp);
        while (list.now().getType().equals(TokenType.Type.AND)) {
            tokens.add(list.now());
            list.next();
            exps.add(EqExp.parse(list));
        }
        return new LAndExp(exps,tokens);
    }
}
