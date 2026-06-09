package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class MulExp {
    //MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    //MulExp → UnaryExp{('*' | '/' | '%') UnaryExp}

    private ArrayList<UnaryExp> exps;

    private ArrayList<Token> tokens;

    private static final String name = "<MulExp>\n";

    public MulExp(ArrayList<UnaryExp> exps,ArrayList<Token> tokens) {
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

    public static MulExp parse(TokenList list){
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<UnaryExp> exps = new ArrayList<>();
        UnaryExp exp = UnaryExp.parse(list);
        exps.add(exp);
        while (list.now().getType().equals(TokenType.Type.MULT)
                ||list.now().getType().equals(TokenType.Type.DIV)
                ||list.now().getType().equals(TokenType.Type.MOD)) {
            tokens.add(list.now());
            list.next();
            exps.add(UnaryExp.parse(list));
        }
        return new MulExp(exps,tokens);
    }
}
