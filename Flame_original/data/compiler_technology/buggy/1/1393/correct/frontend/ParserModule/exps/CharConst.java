package frontend.ParserModule.exps;

import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class CharConst implements UnaryExp {
    private final Lexer charConst;
    private final ArrayList<Lexer> ops = new ArrayList<>();

    public CharConst(Lexer charConst, ArrayList<Lexer> ops) {
        this.ops.addAll(ops);
        this.charConst = charConst;
    }

    public void printRes() {
        for (Lexer lexer : ops) {
            System.out.println(lexer);
            System.out.println("<UnaryOp>");
        }
        System.out.println(charConst);
        System.out.println("<Character>");
        System.out.println("<PrimaryExp>");
        for (int i = 0; i < ops.size() + 1; i++) {
            System.out.println("<UnaryExp>");
        }
    }

    @Override
    public void checkGrammarError() {

    }
}
