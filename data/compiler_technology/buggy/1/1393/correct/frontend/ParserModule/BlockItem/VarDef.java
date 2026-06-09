package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;
import frontend.ParserModule.exps.AddExp;

import java.util.ArrayList;

public class VarDef {
    public Lexer ident;
    public boolean isArray; //是否为数组
    public AddExp arrayExp; //数组内的表达式
    public int errorLocate; //这里指数组缺少右中括号
    public boolean hasIniValue; //是否存在初始值
    public Lexer stringCon;
    public boolean hasBrace; //是否存在大括号
    public ArrayList<AddExp> iniValues = new ArrayList<>();

    public VarDef(Lexer ident, boolean isArray, AddExp arrayExp, int errorLocate, boolean hasIniValue,
                  Lexer stringCon, boolean hasBrace, ArrayList<AddExp> iniValues) {
        this.ident = ident;
        this.isArray = isArray;
        this.errorLocate = errorLocate;
        this.arrayExp = arrayExp;
        this.hasIniValue = hasIniValue;
        this.stringCon = stringCon;
        this.hasBrace = hasBrace;
        this.iniValues.addAll(iniValues);
    }

    public void printRes(boolean isConst) {
        System.out.println(ident);
        if (isArray) {
            System.out.println("LBRACK [");
            arrayExp.printRes();
            System.out.println("<ConstExp>");
            System.out.println("RBRACK ]");
        }
        if(!hasIniValue){
            if(isConst){
                System.out.println("<ConstDef>");
            }else{
                System.out.println("<VarDef>");
            }
            return;
        }
        System.out.println("ASSIGN =");
        if (stringCon == null) {
            if (hasBrace) {
                System.out.println("LBRACE {");
                if (!iniValues.isEmpty()) {
                    int i = 0;
                    for (AddExp iniValue : iniValues) {
                        iniValue.printRes();
                        if (isConst) {
                            System.out.println("<ConstExp>");
                        } else {
                            System.out.println("<Exp>");
                        }
                        if (i == iniValues.size() - 1) {
                            break;
                        }
                        i++;
                        System.out.println("COMMA ,");
                    }
                }
                System.out.println("RBRACE }");
            } else {
                iniValues.get(0).printRes();
                if (isConst) {
                    System.out.println("<ConstExp>");
                } else {
                    System.out.println("<Exp>");
                }
            }
        } else {
            System.out.println(stringCon);
        }
        if (isConst) {
            System.out.println("<ConstInitVal>");
            System.out.println("<ConstDef>");
        } else {
            System.out.println("<InitVal>");
            System.out.println("<VarDef>");
        }
    }

    public void checkGrammarError() {
        if (arrayExp != null && isArray) {
            arrayExp.checkGrammarError();
        }
        if (errorLocate != -1) {
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'k'));
        }
        if (!iniValues.isEmpty()) {
            for (AddExp exp : iniValues) {
                exp.checkGrammarError();
            }
        }

    }
}
