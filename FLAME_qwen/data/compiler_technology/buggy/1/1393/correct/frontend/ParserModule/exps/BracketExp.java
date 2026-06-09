package frontend.ParserModule.exps;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class BracketExp implements UnaryExp {
    private final AddExp exp;
    private final int errorLocation;
    private final ArrayList<Lexer> ops = new ArrayList<>();

    public BracketExp(AddExp exp, int errorLocation, ArrayList<Lexer> ops) {
        this.exp = exp;
        this.errorLocation = errorLocation;
        this.ops.addAll(ops);
    }

    public void printRes() {
        for (Lexer lexer : ops) {
            System.out.println(lexer);
            System.out.println("<UnaryOp>");
        }
        System.out.println("LPARENT (");
        exp.printRes();
        System.out.println("<Exp>");
        System.out.println("RPARENT )");
        System.out.println("<PrimaryExp>");
        for (int i = 0; i < ops.size() + 1; i++) {
            System.out.println("<UnaryExp>");
        }
    }

    @Override
    public void checkGrammarError() {
        exp.checkGrammarError();
        if (errorLocation!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocation,'j'));
        }
    }
}