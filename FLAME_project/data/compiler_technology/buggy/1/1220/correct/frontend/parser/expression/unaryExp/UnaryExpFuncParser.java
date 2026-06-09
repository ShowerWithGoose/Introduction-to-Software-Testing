package frontend.parser.expression.unaryExp;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

public class UnaryExpFuncParser {
    private TokenIterator iterator;
    private Token ident;
    private Token leftParent;
    private Token rightParent;
    private FuncRParams funcRParams;

    public UnaryExpFuncParser(TokenIterator iterator) {
        this.iterator =iterator;
    }

    public UnaryExpFunc parseUnaryExpFunc() {
        // Ident '(' [FuncRParams] ')'
        ident = iterator.getNextToken();
        if (ident.getLineNum() == 26) {
            int a = 1;
        }
        leftParent = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        //规避f(;这样的情况
        if (t1.getType() == TokenType.RPARENT) {
            rightParent = t1;
            funcRParams = null;
        }
        //First(FuncRParams) = First(Exp) = Ident,Number,Character,+,-,!,(
        else if (t1.getType()  == TokenType.IDENFR || t1.getType() == TokenType.INTCON ||
        t1.getType() == TokenType.CHRCON || t1.getType() == TokenType.PLUS || t1.getType() == TokenType.MINU
        || t1.getType() == TokenType.NOT || t1.getType() == TokenType.LPARENT){
            iterator.ungetToken(1);
            FuncRParamsParser parser = new FuncRParamsParser(iterator);
            funcRParams = parser.parseFuncRParams();
            Token t2 = iterator.getNextToken();
            if (t2.getType() != TokenType.RPARENT) {
                //缺少）
                iterator.ungetToken(2);
                Token t3 = iterator.getNextToken();
                Error error = new Error(t3.getLineNum(), "j");
                ErrorList.addErrorList(error);
                rightParent = null;
            } else {
                rightParent = t2;
            }
        } else {
            //缺少FuncRParams & )
            funcRParams = null;
            iterator.ungetToken(2);
            Error error = new Error(iterator.getNextToken().getLineNum(), "j");
            ErrorList.addErrorList(error);
        }
        return new UnaryExpFunc(ident, leftParent, rightParent, funcRParams);
    }
}
