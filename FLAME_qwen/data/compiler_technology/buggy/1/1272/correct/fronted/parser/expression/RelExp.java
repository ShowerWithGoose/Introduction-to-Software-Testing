package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class RelExp {
    //RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp

    private ArrayList<AddExp> exps;

    private ArrayList<Token> tokens;

    private static final String name = "<RelExp>\n";

    public RelExp(ArrayList<AddExp> exps,ArrayList<Token> tokens) {
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

    public static RelExp parse(TokenList list){
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<AddExp> exps = new ArrayList<>();
        AddExp exp = AddExp.parse(list);
        exps.add(exp);
        while (list.now().getType().equals(TokenType.Type.LSS)
                ||list.now().getType().equals(TokenType.Type.LEQ)
                ||list.now().getType().equals(TokenType.Type.GRE)
                ||list.now().getType().equals(TokenType.Type.GEQ)) {
            tokens.add(list.now());
            list.next();
            exps.add(AddExp.parse(list));
        }
        return new RelExp(exps,tokens);
    }
}
