package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class IntConst implements UnaryExp {
    private final Lexer number;
    private final ArrayList<Lexer> ops = new ArrayList<>();

    public IntConst(Lexer number, ArrayList<Lexer> ops) {
        this.ops.addAll(ops);
        this.number = number;
    }

    public void printRes() {
        for (Lexer lexer : ops) {
            System.out.println(lexer);
            System.out.println("<UnaryOp>");
        }
        System.out.println(number);
        System.out.println("<Number>");
        System.out.println("<PrimaryExp>");
        for (int i = 0; i < ops.size() + 1; i++) {
            System.out.println("<UnaryExp>");
        }
    }


    @Override
    public void checkGrammarError() {

    }
}
