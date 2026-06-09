package frontend.ParserModule.exps;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class FunctionRPrams implements UnaryExp {
    private final Lexer ident;
    private final ArrayList<AddExp> rParams = new ArrayList<>();

    private final int errorLocation;
    private final ArrayList<Lexer> ops = new ArrayList<>();

    public FunctionRPrams(Lexer ident, ArrayList<AddExp> rParams, int errorLocation, ArrayList<Lexer> ops) {
        this.ident = ident;
        this.rParams.addAll(rParams);
        this.errorLocation = errorLocation;
        this.ops.addAll(ops);
    }

    public void printRes() {
        for (Lexer lexer : ops) {
            System.out.println(lexer);
            System.out.println("<UnaryOp>");
        }
        System.out.println(ident);
        System.out.println("LPARENT (");
        if (!rParams.isEmpty()) {
            int i = 0;
            for (AddExp rParam : rParams) {
                rParam.printRes();
                System.out.println("<Exp>");
                if (i == rParams.size() - 1) {
                    break;
                }
                i++;
                System.out.println("COMMA ,");
            }
            System.out.println("<FuncRParams>");
        }
        System.out.println("RPARENT )");
        for (int i = 0; i < ops.size() + 1; i++) {
            System.out.println("<UnaryExp>");
        }
    }



    @Override
    public void checkGrammarError() {
        for(AddExp rParam:rParams){
            rParam.checkGrammarError();
        }
        if (errorLocation!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocation,'j'));
        }
    }
}
