package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class LOrExp {
    //LOrExp → LAndExp | LOrExp '||' LAndExp
    //LOrExp → LAndExp {'||' LAndExp}

    private ArrayList<LAndExp> exps;

    private ArrayList<Token> tokens;

    private static final String name = "<LOrExp>\n";

    public LOrExp(ArrayList<LAndExp> exps,ArrayList<Token> tokens) {
        this.exps =exps;
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

    public static LOrExp parse(TokenList list){
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<LAndExp> exps = new ArrayList<>();
        LAndExp exp = LAndExp.parse(list);
        exps.add(exp);
        while (list.now().getType().equals(TokenType.Type.OR)) {
            tokens.add(list.now());
            list.next();
            exps.add(LAndExp.parse(list));
        }
        return new LOrExp(exps,tokens);
    }
}
