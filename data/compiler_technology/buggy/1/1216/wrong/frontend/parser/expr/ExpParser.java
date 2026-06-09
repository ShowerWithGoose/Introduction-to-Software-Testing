package frontend.parser.expr;

import exeptions.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.TokenHandler;
import frontend.parser.expr.types.*;

// 表达式 Expression
public class ExpParser {
    private static TokenHandler handler;
    public static void setHandler(TokenHandler newHandler) {
        handler = newHandler;
    }
//    Exp → AddExp
    public static Exp parseExp(boolean isConst) {
        return new Exp(parseAddExp(), isConst);
    }
//    AddExp → MulExp | AddExp ('+' | '−') MulExp
    public static AddExp parseAddExp() {
        AddExp addExp = new AddExp(parseMulExp());
        while (AddExp.isSep(handler.getNext())) {
            addExp.appendMulExp(handler.getNextAndMove(), parseMulExp());
        }
        return addExp;
    }
//    MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public static MulExp parseMulExp() {
        MulExp mulExp = new MulExp(parseUnaryExp());
        while (MulExp.isSep(handler.getNext())) {
            mulExp.appendUnaryExp(handler.getNextAndMove(), parseUnaryExp());
        }
        return mulExp;
    }
//    UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    public static UnaryExp parseUnaryExp() {
        Token nextToken = handler.getNext();
        if (nextToken.getType() == TokenType.IDENFR && handler.getByOffset(1).getType() == TokenType.LPARENT) {
            Token ident = handler.getNextAndMove();
            Token lParent = handler.getNextAndMove();
            FuncRParams funcRParams = null;
            Token rParent = null;
            if (FuncRParams.inFirst(handler.getNext())) {
                funcRParams = parseFuncRParams();
            }
            if (handler.getNext().getType() == TokenType.RPARENT) {
                rParent = handler.getNextAndMove();
            } else {
                handler.addError(ErrorType.MISS_RPARENT);
            }
            return new UnaryExp(ident, lParent, funcRParams, rParent);
        } else if (PrimaryExp.inFirst(nextToken)) {
            return new UnaryExp(parsePrimaryExp());
        }
        return new UnaryExp(handler.getNextAndMove(), parseUnaryExp());
    }
    public static Cond parseCond() {
        return new Cond(parseLOrExp());
    }
    public static LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp(parseLAndExp());
        while (handler.getNext().getType() == TokenType.OR) {
            lOrExp.appendLAndExp(handler.getNextAndMove(), parseLAndExp());
        }
        return lOrExp;
    }
    public static LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp(parseEqExp());
        while (handler.getNext().getType() == TokenType.AND) {
            lAndExp.appendEqExp(handler.getNextAndMove(), parseEqExp());
        }
        return lAndExp;
    }
    public static EqExp parseEqExp() {
        EqExp eqExp = new EqExp(parseRelExp());
        while (handler.getNext().getType() == TokenType.EQL ||
                handler.getNext().getType() == TokenType.NEQ) {
            eqExp.appendRelExp(handler.getNextAndMove(), parseRelExp());
        }
        return eqExp;
    }
    public static RelExp parseRelExp() {
        RelExp relExpExp = new RelExp(parseAddExp());
        while (RelExp.isSep(handler.getNext())) {
            relExpExp.appendAddExp(handler.getNextAndMove(), parseAddExp());
        }
        return relExpExp;
    }
    public static PrimaryExp parsePrimaryExp() {
        TokenType nextType = handler.getNext().getType();
        switch (nextType) {
            case LPARENT -> {
                Token lParent = handler.getNextAndMove();
                Exp exp = parseExp(false);
                Token rParent = null;
                if (handler.getNext().getType() == TokenType.RPARENT) {
                    rParent = handler.getNextAndMove();
                } else {
                    handler.addError(ErrorType.MISS_RPARENT);
                }
                return new PrimaryExp(lParent, exp, rParent);
            }
            case INTCON, CHRCON -> {
                return new PrimaryExp(handler.getNextAndMove());
            }
            default -> {
                return new PrimaryExp(parseLVal());
            }
        }
    }
    public static LVal parseLVal() {
        Token ident = handler.getNextAndMove();
        TokenType nextType = handler.getNext().getType();
        if (nextType == TokenType.LBRACK) {
            Token lBrack = handler.getNextAndMove();
            Exp exp = parseExp(false);
            Token rBrack = null;
            if (handler.getNext().getType() == TokenType.RBRACK) {
                rBrack = handler.getNextAndMove();
            } else {
                handler.addError(ErrorType.MISS_RBRACK);
            }
            return new LVal(ident, lBrack, exp, rBrack);
        } else {
            return new LVal(ident);
        }
    }
    public static FuncRParams parseFuncRParams() {
        FuncRParams funcRParams = new FuncRParams(parseExp(false));
        while (handler.getNext().getType() == TokenType.COMMA) {
            funcRParams.addExp(handler.getNextAndMove(), parseExp(false));
        }
        return funcRParams;
    }
}