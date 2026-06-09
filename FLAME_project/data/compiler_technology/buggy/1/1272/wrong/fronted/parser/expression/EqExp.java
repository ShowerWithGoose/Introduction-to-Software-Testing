package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class EqExp {
    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    // EqExp → RelExp {('==' | '!=') RelExp}

    private ArrayList<Token> tokens;

    private ArrayList<RelExp> relExpArrayList;

    //@ensure tokens.length = relExpArrayList.length - 1

    private static final String name = "<EqExp>\n";

    public EqExp(ArrayList<Token> tokens,ArrayList<RelExp> relExpArrayList) {
        this.tokens = tokens;
        this.relExpArrayList = relExpArrayList;
    }

    @Override
    public String toString(){
        int num = relExpArrayList.size();
        StringBuilder sb = new StringBuilder();
        sb.append(relExpArrayList.get(0).toString());
        sb.append(name);
        for (int i = 1;i < num;i = i + 1) {
            sb.append(tokens.get(i-1).toString());
            sb.append(relExpArrayList.get(i).toString());
            sb.append(name);
        }
        return sb.toString();
    }

    public static EqExp parse(TokenList list){
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<RelExp> relExps = new ArrayList<>();
        RelExp exp = RelExp.parse(list);
        relExps.add(exp);
        while (list.now().getType().equals(TokenType.Type.EQL) ||
                list.now().getType().equals(TokenType.Type.NEQ)) {
            tokens.add(list.now());
            list.next();
            relExps.add(RelExp.parse(list));
        }
        return new EqExp(tokens,relExps);
    }
}
