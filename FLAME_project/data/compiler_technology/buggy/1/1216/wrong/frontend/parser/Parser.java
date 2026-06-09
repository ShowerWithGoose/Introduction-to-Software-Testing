package frontend.parser;
import frontend.lexer.TokenType;
import frontend.parser.func.*;
import frontend.parser.decl.*;
import frontend.parser.expr.*;
import frontend.parser.stmt.*;

public class Parser {
    public static CompUnit parseCompUnit(TokenHandler handler) {
        setHandler(handler);
        CompUnit compUnit = new CompUnit();
        while (!handler.reachEnd()) {
            switch (handler.getNext().getType()) {
                case INTTK -> {
                    if (handler.getByOffset(1).getType() == TokenType.MAINTK) {
                        compUnit.setMainFunc(FuncParser.parseFuncDef());
                    } else if (handler.getByOffset(2).getType() == TokenType.LPARENT) {
                        compUnit.addFunc(FuncParser.parseFuncDef());
                    } else {
                        compUnit.addDecl(DeclParser.parseDecl());
                    }
                }
                case VOIDTK -> compUnit.addFunc(FuncParser.parseFuncDef());
                case CONSTTK -> compUnit.addDecl(DeclParser.parseDecl());
                case CHARTK -> {
                    if (handler.getByOffset(2).getType() == TokenType.LPARENT) {
                        compUnit.addFunc(FuncParser.parseFuncDef());
                    } else {
                        compUnit.addDecl(DeclParser.parseDecl());
                    }
                }
                default -> System.err.println("error: unhandled token " + handler.getNext() + " at line " + handler.getNextAndMove().getLine());
            }
        }
        return compUnit;
    }
    public static void setHandler(TokenHandler newHandler) {
        ExpParser.setHandler(newHandler);
        StmtParser.setHandler(newHandler);
        DeclParser.setHandler(newHandler);
        FuncParser.setHandler(newHandler);
    }
}
