package frontend.tree.func;

import frontend.error.ErrorList;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.tree.Node;
import frontend.tree.exp.Exp;
import frontend.tree.exp.LVal;
import frontend.semantic.SymbolManager;

/**
 * 语句 Stmt → LVal '=' Exp ';' // h
 * | [Exp] ';'
 * | Block
 * | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
 * | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
 * | 'break' ';' | 'continue' ';' // m
 * | 'return' [Exp] ';' // f
 * | LVal '=' 'getint''('')'';' // h
 * | LVal '=' 'getchar''('')'';' // h
 * | 'printf''('StringConst {','Exp}')'';' // l
 */
public class Stmt extends Node {
    @Override
    public void semanticAnalysis() {
        if (isReturnValue()) {
            SymbolManager.getInstance().setReturnStmt(true, beginLine);
        }
        Node first = children.get(0);
        Node second = children.size() > 1? children.get(1) : null;
        if (first instanceof Token) {
            Token token = (Token) first;
            if (token.getLexType() == LexType.FORTK) {
                SymbolManager.getInstance().enterLoop();
                super.semanticAnalysis();
                SymbolManager.getInstance().exitLoop();
                return;
            } else if (token.getLexType() == LexType.BREAKTK || token.getLexType() == LexType.CONTINUETK) {
                if (!SymbolManager.getInstance().isInLoop()) { // 在非循环块中使用break和continue语句
                    ErrorList.getInstance().addError("m", token.getLineNum());
                }
            } else if (token.getLexType() == LexType.PRINTFTK) {
                String stringConst = ((Token) children.get(2)).getValue();
                int formatCharCnt = (stringConst.split("%d").length - 1)
                        + (stringConst.split("%c").length - 1)
                        + (stringConst.split("%s").length - 1);
                int expCnt = 0;
                for (int i = 3; i < children.size(); i++) {
                    if (children.get(i) instanceof Exp) {
                        expCnt++;
                    }
                }
                if (formatCharCnt != expCnt) { // 格式化字符串和表达式个数不匹配
                    ErrorList.getInstance().addError("l", token.getLineNum());
                }
            }
        } else if (first instanceof LVal && second instanceof Token && ((Token) second).getLexType() == LexType.ASSIGN) {
            LVal lVal = ((LVal) first);
            if (SymbolManager.getInstance().isConst(lVal.getIdentifierName())) { // 不能改变常量的值
                ErrorList.getInstance().addError("h", lVal.getIdent().getLineNum());
            }
        }
        super.semanticAnalysis();
    }

    public boolean isReturnValue() {
        Node first = children.get(0);
        Node second = children.size() > 1? children.get(1) : null;
        if (first instanceof Token) {
            Token token = (Token) first;
            return token.getLexType() == LexType.RETURNTK && !(second instanceof Token && ((Token) second).getLexType() == LexType.SEMICN);
        }
        return false;
    }
}
