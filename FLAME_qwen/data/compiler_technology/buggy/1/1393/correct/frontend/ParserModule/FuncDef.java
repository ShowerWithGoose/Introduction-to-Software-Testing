package frontend.ParserModule;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;
import frontend.ParserModule.BlockItem.Block;

import java.util.ArrayList;

public class FuncDef {
    private final Lexer funcType;
    private final Lexer ident;
    private final ArrayList<FuncParam> fParams = new ArrayList<>();
    private final Block funcBody;
    private final int errorLocate;//缺小括号

    public FuncDef(Lexer funcType, Lexer ident, ArrayList<FuncParam> fParams, Block funcBody, int errorLocate) {
        this.funcType = funcType;
        this.ident = ident;
        this.fParams.addAll(fParams);
        this.funcBody = funcBody;
        this.errorLocate = errorLocate;
    }

    public void printRes() {
        System.out.println(funcType);
        System.out.println("<FuncType>");
        System.out.println(ident);
        System.out.println("LPARENT (");
        if (!fParams.isEmpty()) {
            int i = 0;
            for (FuncParam fParam : fParams) {
                fParam.printRes();
                if (i == fParams.size() - 1) {
                    break;
                }
                i++;
                System.out.println("COMMA ,");
            }
            System.out.println("<FuncFParams>");
        }
        System.out.println("RPARENT )");
        funcBody.printBlockRes();
        System.out.println("<FuncDef>");
    }

    public void checkGrammarError() {
        for (FuncParam funcParam : fParams) {
            funcParam.checkGrammarError();
        }
        if (errorLocate != -1) {
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'j'));
        }
        funcBody.checkGrammarError();
    }

}
