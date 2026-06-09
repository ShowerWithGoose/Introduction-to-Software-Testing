package ast;

import error.ParserError;
import error.SemanticError;
import lexical.TokenType;
import semantic.*;

public class FuncDef extends Symbol {

    public static Symbol of(String dir, SymbolTable table) {
        Symbol symbol;
        Symbol funcDef = new FuncDef();
        if ((symbol = FuncType.of()) == null) {
            return null;
        }
        DecType decType = ((FuncType) symbol).getType();
        FuncInfo info;
        funcDef.add(symbol);
        if ((symbol = Ident.of()) == null) {
            return null;
        }
        String ident = ((Ident) symbol).getIdent();
        if (decType.equals(DecType.Void)) {
            info = new VoidFuncInfo(ident);
        } else if (decType.equals(DecType.Int)) {
            info = new IntFuncInfo(ident);
        } else {
            info = new CharFuncInfo(ident);
        }
        String funcDir = SymbolTable.getDir(dir, SymbolTable.SymbolType.Function, ident);
        SymbolTable funcTable = SemanticAnalyser.newSymbolTable(funcDir);
        int line = symbol.getLine();
        funcDef.add(symbol);
        if (!token.getType().equals(TokenType.LPARENT)) {
            return null;
        }
        funcDef.add(token);
        token = lexer.nextToken();
        try {
            SemanticAnalyser.addSymbolToTable(table, ident, info);
        } catch (Exception e) {
            logger.log(new SemanticError(line, "b"));
        }
        if ((symbol = FuncFParams.of(funcTable, info)) != null) {
            funcDef.add(symbol);
            line = symbol.getLine();
        }
        if (!token.getType().equals(TokenType.RPARENT)) {
            logger.log(new ParserError(line, "j"));
        } else {
            funcDef.add(token);
            token = lexer.nextToken();
        }
        if ((symbol = Block.of(funcDir, funcTable, info, false)) == null) {
            return null;
        }
        if (!(info instanceof VoidFuncInfo)) {
            if (!((Block) symbol).isReturned()) {
                logger.log(new SemanticError(((Block) symbol).getTokenLine(), "g"));
            }
        }
        funcDef.add(symbol);
        return funcDef;
    }
}
