package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class EqExp{
    private final ArrayList<RelExp> relExps = new ArrayList<>();
    private final ArrayList<Lexer> ops = new ArrayList<>();
    public EqExp(RelExp exp){
        relExps.add(exp);
    }
    public void addRelExp(RelExp exp,Lexer op){
        relExps.add(exp);
        ops.add(op);
    }
    public void printRes(){
        relExps.get(0).printRes();
        System.out.println("<EqExp>");
        for(int i=1;i<relExps.size();i++) {
            System.out.println(ops.get(i-1));
            relExps.get(i).printRes();
            System.out.println("<EqExp>");
        }
    }

    public void checkGrammarError(){
        for(RelExp exp:relExps){
            exp.checkGrammarError();
        }
    }
}
