package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class LOrExp {
    private final ArrayList<LAndExp> lAndExps = new ArrayList<>();
    private final ArrayList<Lexer> ops = new ArrayList<>();
    public LOrExp(LAndExp exp){
        lAndExps.add(exp);
    }
    public void addLAndExp(LAndExp exp,Lexer op){
        lAndExps.add(exp);
        ops.add(op);
    }
    public void printRes(){
        lAndExps.get(0).printRes();
        System.out.println("<LOrExp>");
        for(int i=1;i<lAndExps.size();i++) {
            System.out.println(ops.get(i-1));
            lAndExps.get(i).printRes();
            System.out.println("<LOrExp>");
        }
    }

    public void checkGrammarError(){
        for(LAndExp exp:lAndExps){
            exp.checkGrammarError();
        }
    }
}
