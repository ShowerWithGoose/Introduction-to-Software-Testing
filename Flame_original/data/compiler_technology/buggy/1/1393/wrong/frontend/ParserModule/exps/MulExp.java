package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class MulExp {
    private final ArrayList<UnaryExp> unaryExps = new ArrayList<>();
    private final ArrayList<Lexer> ops = new ArrayList<>();

    public MulExp(UnaryExp exp) {
        unaryExps.add(exp);
    }

    public void addUnaryExp(UnaryExp exp, Lexer op) {
        unaryExps.add(exp);
        ops.add(op);
    }

    public void printRes() {
        unaryExps.get(0).printRes();
        System.out.println("<MulExp>");
        for (int i = 1; i < unaryExps.size(); i++) {
            System.out.println(ops.get(i - 1));
            unaryExps.get(i).printRes();
            System.out.println("<MulExp>");
        }
    }


    public Lvalue toLvalue() {
        return (Lvalue) unaryExps.get(0);
    }

    public void checkGrammarError() {
        for (UnaryExp exp : unaryExps) {
            exp.checkGrammarError();
        }
    }
}
