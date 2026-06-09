package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;
import frontend.ParserModule.exps.AddExp;

import java.util.ArrayList;

public class PrintBlock implements BlockItem{
    private Lexer stringCon;
    private ArrayList<AddExp> exps = new ArrayList<>();
    private int errorLocate1;//缺小括号
    private int errorLocate2;//缺分号
    private int printLineNumber;//记录了print的行数 用于输出错误l
    public PrintBlock(Lexer stringCon,ArrayList<AddExp> exps,int errorLocate1,int errorLocate2,int printLineNumber){
        this.stringCon = stringCon;
        this.exps.addAll(exps);
        this.errorLocate1 = errorLocate1;
        this.errorLocate2 = errorLocate2;
        this.printLineNumber = printLineNumber;
    }

    @Override
    public void printRes() {
        System.out.println("PRINTFTK printf");
        System.out.println("LPARENT (");
        System.out.println(stringCon);
        for(AddExp exp:exps){
            System.out.println("COMMA ,");
            exp.printRes();
            System.out.println("<Exp>");
        }
        System.out.println("RPARENT )");
        System.out.println("SEMICN ;");
        System.out.println("<Stmt>");
    }

    @Override
    public void checkGrammarError() {
        for(AddExp exp:exps){
            exp.checkGrammarError();
        }
        /*if(getParaCount()!=exps.size()){
            ErrorCollect.addErrorData(new ErrorData(printLineNumber,'l'));
        }*/
        if(errorLocate1!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate1,'j'));
        }
        if(errorLocate2!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate2,'i'));
        }
    }
    public int getParaCount(){
        int res = 0;
        int len = stringCon.getName().length();
        String formatStr = stringCon.getName();
        for (int i=0;i<len-1;){
            if(formatStr.charAt(i) == '%'&&(formatStr.charAt(i) == 'd' || formatStr.charAt(i) == 'c')){
                i+=2;
            }else{
                i+=1;
            }
        }
        return res;
    }

}
