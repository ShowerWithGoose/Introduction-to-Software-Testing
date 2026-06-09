package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.SymbolTableItem;
import frontend.Token;

import java.util.ArrayList;

public class FuncDef {
    private FuncType funcType;
    private Token identifier;
    private Token lparent;
    private FuncFParams funcFParams;
    private Token rparent;
    private Block block;
    private int lineCnt;

    public FuncDef() {
        funcType = null;
        identifier = null;
        lparent = null;
        funcFParams = null;
        rparent = null;
        block = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        funcType = new FuncType();
        funcType.parser(lexer);
        identifier = lexer.now();
        lexer.move();
        lparent = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.INTTK ||
                lexer.now().getType() == Token.Type.CHARTK) {
            funcFParams = new FuncFParams();
            funcFParams.parser(lexer);
        }
        if (lexer.now().getType() == Token.Type.RPARENT) {
            rparent = lexer.now();
            lexer.move();
        } else {
            if (funcFParams == null) {
                rparent = new Token(Token.Type.RPARENT, ")", lparent.getLineCnt());
            } else {
                rparent = new Token(Token.Type.RPARENT, ")", funcFParams.getLineCnt());
            }
            rparent.setIsCorrect(false);
        }
        block = new Block();
        block.parser(lexer);
        lineCnt = funcType.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        String name = identifier.getContent();
        String type;
        int domainNum = symbolTable.getDomainNum();
        boolean hasReturn = false;
        if (funcType.getFuncType().getType() == Token.Type.INTTK) {
            type = "IntFunc";
            symbolTable.setReturnFuncType(SymbolTable.ReturnFuncType.INT);
            hasReturn = true;
        } else if (funcType.getFuncType().getType() == Token.Type.CHARTK) {
            type = "CharFunc";
            symbolTable.setReturnFuncType(SymbolTable.ReturnFuncType.CHAR);
            hasReturn = true;
        } else {
            type = "VoidFunc";
        }
        SymbolTableItem item = new SymbolTableItem(name, type, domainNum);
        if (funcFParams != null) {
            item.analyzeFuncPara(funcFParams);
        }
        if (symbolTable.containsName(name, domainNum)) {
            symbolTable.addError(identifier.getLineCnt() + " b");
        } else {
            symbolTable.addItem(item);
        }
        if (!rparent.getIsCorrect()) {
            symbolTable.addError(rparent.getLineCnt() + " j");
        }
        block.analyzeFunc(symbolTable, funcFParams, hasReturn);
        symbolTable.setReturnFuncType(SymbolTable.ReturnFuncType.VOID);
    }
}
