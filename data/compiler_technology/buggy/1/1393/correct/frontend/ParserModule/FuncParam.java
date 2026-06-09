package frontend.ParserModule;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;

public class FuncParam {
    private final Lexer bType;
    private final Lexer ident;
    private final boolean isArray;
    private final int errorLocate;//缺中括号

    public FuncParam(Lexer bType, Lexer ident, boolean isArray, int errorLocate) {
        this.bType = bType;
        this.ident = ident;
        this.isArray = isArray;
        this.errorLocate = errorLocate;
    }

    public void printRes() {
        System.out.println(bType);
        System.out.println(ident);
        if (isArray) {
            System.out.println("LBRACK [");
            System.out.println("RBRACK ]");
        }
        System.out.println("<FuncFParam>");
    }

    public void checkGrammarError() {
        if (isArray && errorLocate != -1) {
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'k'));
        }
    }

}
