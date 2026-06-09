package frontend.ParserModule.exps;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class Lvalue implements UnaryExp {
    private final Lexer ident;
    private final boolean isArray;
    private final AddExp exp;
    private final int errorLocation;
    private final ArrayList<Lexer> ops = new ArrayList<>();

    public Lvalue(Lexer ident, boolean isArray, AddExp exp, int errorLocation, ArrayList<Lexer> ops) {
        this.ident = ident;
        this.isArray = isArray;
        this.exp = exp;
        this.errorLocation = errorLocation;
        this.ops.addAll(ops);
    }

    public void printRes() {
        for (Lexer lexer : ops) {
            System.out.println(lexer);
            System.out.println("<UnaryOp>");
        }
        printForLValue();
        System.out.println("<PrimaryExp>");
        for (int i = 0; i < ops.size() + 1; i++) {
            System.out.println("<UnaryExp>");
        }
    }

    public void printForLValue() {
        System.out.println(ident);
        if (isArray) {
            System.out.println("LBRACK [");
            exp.printRes();
            System.out.println("<Exp>");
            System.out.println("RBRACK ]");
        }
        System.out.println("<LVal>");
    }


    @Override
    public void checkGrammarError() {
        if (isArray) {
            exp.checkGrammarError();
        }
        if (errorLocation != -1) {
            ErrorCollect.addErrorData(new ErrorData(errorLocation,'k'));
        }
    }
}
