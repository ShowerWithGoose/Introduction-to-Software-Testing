package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;
import frontend.ParserModule.exps.Lvalue;

public class AssignByFunc implements BlockItem {
    private final Lvalue lVal;
    private final Lexer functionType;
    private final int errorLocate1;//缺小括号
    private final int errorLocate2;//缺分号
    public AssignByFunc(Lvalue lVal,Lexer functionType,int e1,int e2){
        this.lVal = lVal;
        this.functionType = functionType;
        this.errorLocate1 = e1;
        this.errorLocate2 = e2;
    }

    @Override
    public void printRes() {
        lVal.printForLValue();
        System.out.println("ASSIGN =");
        System.out.println(functionType);
        System.out.println("LPARENT (");
        System.out.println("RPARENT )");
        System.out.println("SEMICN ;");
        System.out.println("<Stmt>");
    }

    @Override
    public void checkGrammarError() {
        lVal.checkGrammarError();
        if(errorLocate1!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate1,'j'));
        }
        if(errorLocate2!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate2,'i'));
        }
    }
}
