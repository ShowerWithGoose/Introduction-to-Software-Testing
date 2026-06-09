package ast;

import error.ParserError;
import error.SemanticError;
import lexical.TokenType;
import semantic.FuncInfo;
import semantic.IntFuncInfo;
import semantic.SymbolTable;

public class MainFuncDef extends Symbol {

    public static Symbol of(String dir, SymbolTable table) {
        Symbol symbol;
        Symbol mainFuncDef = new MainFuncDef();
        if (!token.getType().equals(TokenType.INTTK)) {
            return null;
        }
        mainFuncDef.add(token);
        token = lexer.nextToken();
        if (!token.getType().equals(TokenType.MAINTK)) {
            return null;
        }
        mainFuncDef.add(token);
        token = lexer.nextToken();
        if (!token.getType().equals(TokenType.LPARENT)) {
            return null;
        }
        mainFuncDef.add(token);
        int line = token.getLine();
        token = lexer.nextToken();
        if (!token.getType().equals(TokenType.RPARENT)) {
            logger.log(new ParserError(line, "j"));
        } else {
            mainFuncDef.add(token);
            token = lexer.nextToken();
        }
        if ((symbol = Block.of(dir, table, new IntFuncInfo("main"), false)) == null) {
            return null;
        }
        if (!((Block) symbol).isReturned()) {
            logger.log(new SemanticError(((Block) symbol).getTokenLine(), "g"));
        }
        mainFuncDef.add(symbol);
        return mainFuncDef;
    }
}
