package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class AddExp {
    private final ArrayList<MulExp> mulExps = new ArrayList<>();
    private final ArrayList<Lexer> ops = new ArrayList<>();

    public AddExp(MulExp exp) {
        mulExps.add(exp);
    }

    public void addMulExp(MulExp exp, Lexer op) {
        mulExps.add(exp);
        ops.add(op);
    }

    public void printRes() {
        mulExps.get(0).printRes();
        System.out.println("<AddExp>");
        for (int i = 1; i < mulExps.size(); i++) {
            System.out.println(ops.get(i - 1));
            mulExps.get(i).printRes();
            System.out.println("<AddExp>");
        }
    }


    public void checkGrammarError() {
        for (MulExp exp : mulExps) {
            exp.checkGrammarError();
        }
    }

    public Lvalue toLvalue() {
        return mulExps.get(0).toLvalue();
    }
}
