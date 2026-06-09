package frontend.parser.decl;

import exeptions.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.TokenHandler;
import frontend.parser.decl.types.Decl;
import frontend.parser.decl.types.Def;
import frontend.parser.decl.types.InitVal;
import frontend.parser.expr.ExpParser;
import frontend.parser.expr.types.Exp;

import java.util.ArrayList;

public class DeclParser {
    private static TokenHandler handler;
    public static void setHandler(TokenHandler newHandler) {
        handler = newHandler;
    }
    public static Decl parseDecl() {
        Decl decl;
        boolean isConst;
        if (handler.getNext().getType() == TokenType.CONSTTK) {
            isConst = true;
            Token constTK = handler.getNextAndMove();
            Token bType = handler.getNextAndMove();
            Def firstDef = parseDef(true);
            decl = new Decl(constTK, bType, firstDef);
        } else {
            isConst = false;
            Token bType = handler.getNextAndMove();
            decl = new Decl(bType, parseDef(false));
        }
        while (handler.getNext().getType() == TokenType.COMMA) {
            decl.addSep(handler.getNextAndMove());
            decl.addDef(parseDef(isConst));
        }
        if (handler.getNext().getType() != TokenType.SEMICN) {
            handler.addError(ErrorType.MISS_SEMICN);
        } else {
            decl.addSemicn(handler.getNextAndMove());
        }
        return decl;
    }
    public static Def parseDef(boolean isConst) {
        Token ident = handler.getNextAndMove();
        Exp constExp = null;
        Token lBrack = null, rBrack = null, assign = null;
        InitVal initVal = null;
        if (handler.getNext().getType() == TokenType.LBRACK) {
            lBrack = handler.getNextAndMove();
            constExp = ExpParser.parseExp(true);
            if (handler.getNext().getType() == TokenType.RBRACK) {
                rBrack = handler.getNextAndMove();
            } else {
                handler.addError(ErrorType.MISS_RBRACK);
            }
        }
        if (handler.getNext().getType() == TokenType.ASSIGN) {
            assign = handler.getNextAndMove();
            initVal = parseInitVal(isConst);
        }
        return new Def(ident, lBrack, constExp, rBrack, assign, initVal, isConst);
    }
    public static InitVal parseInitVal(boolean isConst) {
        if (handler.getNext().getType() == TokenType.LBRACE) {
            Token lBrace = handler.getNextAndMove();
            Exp firstExp = null;
            if (handler.getNext().getType() != TokenType.RBRACE) {
                firstExp = ExpParser.parseExp(isConst);
                ArrayList<Exp> exps = new ArrayList<>();
                ArrayList<Token> seps = new ArrayList<>();
                while (handler.getNext().getType() == TokenType.COMMA) {
                    seps.add(handler.getNextAndMove());
                    exps.add(ExpParser.parseExp(isConst));
                }
                Token rBrace = handler.getNextAndMove();
                return new InitVal(lBrace, firstExp, seps, exps, rBrace, isConst);
            }
            Token rBrace = handler.getNextAndMove(); // 空数组
            return new InitVal(lBrace, null, null, null, rBrace, isConst);
        }
        if (handler.getNext().getType() == TokenType.STRCON) {
            return new InitVal(handler.getNextAndMove(), isConst);
        }
        return new InitVal(ExpParser.parseExp(isConst), isConst);
    }
}
