package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;
import frontend.ParserModule.exps.AddExp;

public class SpecialStmt implements BlockItem{
    private Lexer type;
    private AddExp exp;
    private final int errorLocate;
    public SpecialStmt(Lexer type,AddExp exp,int errorLocate){
        this.type = type;
        this.exp = exp;
        this.errorLocate = errorLocate;
    }

    @Override
    public void printRes() {
        System.out.println(type);
        if(exp != null){
            exp.printRes();
            System.out.println("<Exp>");
        }
        System.out.println("SEMICN ;");
        System.out.println("<Stmt>");
    }

    @Override
    public void checkGrammarError() {
        if(exp!=null){
            exp.checkGrammarError();
        }
        if(errorLocate!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'i'));
        }
    }
}
