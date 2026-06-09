package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;
import frontend.ParserModule.exps.AddExp;

import java.util.ArrayList;

public class RelExp {
    private final ArrayList<AddExp> addExps = new ArrayList<>();
    private final ArrayList<Lexer> ops = new ArrayList<>();
    public RelExp(AddExp exp){
        addExps.add(exp);
    }
    public void addAddExp(AddExp exp, Lexer op){
        addExps.add(exp);
        ops.add(op);
    }
    public void printRes(){
        addExps.get(0).printRes();
        System.out.println("<RelExp>");
        for(int i=1;i<addExps.size();i++) {
            System.out.println(ops.get(i-1));
            addExps.get(i).printRes();
            System.out.println("<RelExp>");
        }
    }
    public void checkGrammarError(){
        for(AddExp exp:addExps){
            exp.checkGrammarError();
        }
    }
}
