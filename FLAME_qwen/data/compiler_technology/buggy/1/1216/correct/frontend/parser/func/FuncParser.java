package frontend.parser.func;

import exeptions.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.TokenHandler;
import frontend.parser.func.types.FuncDef;
import frontend.parser.func.types.FuncFParam;
import frontend.parser.func.types.FuncFParams;
import frontend.parser.stmt.StmtParser;

public class FuncParser {
    private static TokenHandler handler;
    public static void setHandler(TokenHandler newHandler) {
        handler = newHandler;
    }
    public static FuncDef parseFuncDef() {
        Token funcType = handler.getNextAndMove();
        Token funcIdent = handler.getNextAndMove();
        Token lParent = handler.getNextAndMove();
        FuncFParams params = null;
        Token rParent = null;
        switch (handler.getNext().getType()) {
            case INTTK, CHARTK -> params = parseFuncFParams();
        }
        if (handler.getNext().getType() == TokenType.RPARENT) {
            rParent = handler.getNextAndMove();
        } else {
            handler.addError(ErrorType.MISS_RPARENT);
        }
        return new FuncDef(funcType, funcIdent, lParent, params, rParent, StmtParser.parseBlock());
    }
    public static FuncFParam parseFuncFParam() {
        Token bType = handler.getNextAndMove();
        Token ident = handler.getNextAndMove();
        if (handler.getNext().getType() == TokenType.LBRACK) {
            Token lBrack = handler.getNextAndMove();
            Token rBrack = null;
            if (handler.getNext().getType() == TokenType.RBRACK) {
                rBrack = handler.getNextAndMove();
            } else {
                handler.addError(ErrorType.MISS_RBRACK);
            }
            return new FuncFParam(bType, ident, lBrack, rBrack);
        }
        return new FuncFParam(bType, ident);
    }
    public static FuncFParams parseFuncFParams() {
        FuncFParams funcFParams = new FuncFParams(parseFuncFParam());
        while (handler.getNext().getType() == TokenType.COMMA) {
            funcFParams.addFParam(handler.getNextAndMove(), parseFuncFParam());
        }
        return funcFParams;
    }
}
