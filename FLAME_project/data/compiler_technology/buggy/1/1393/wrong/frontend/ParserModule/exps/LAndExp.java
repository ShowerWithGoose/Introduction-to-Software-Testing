package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class LAndExp {
    private final ArrayList<EqExp> eqExps = new ArrayList<>();
    private final ArrayList<Lexer> ops = new ArrayList<>();
    public LAndExp(EqExp exp){
        eqExps.add(exp);
    }
    public void addEqExp(EqExp exp,Lexer op){
        eqExps.add(exp);
        ops.add(op);
    }
    public void printRes(){
        eqExps.get(0).printRes();
        System.out.println("<LAndExp>");
        for(int i=1;i<eqExps.size();i++) {
            System.out.println(ops.get(i-1));
            eqExps.get(i).printRes();
            System.out.println("<LAndExp>");
        }
    }

    public void checkGrammarError(){
        for (EqExp exp:eqExps){
            exp.checkGrammarError();
        }
    }
}
