package parser_part.function;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.Ident;
import parser_part.IdentParser;
import parser_part.block.Block;
import parser_part.block.BlockItem;
import parser_part.block.BlockItemComponent;
import parser_part.block.BlockParser;
import parser_part.function.funcType.FuncType;
import parser_part.function.funcType.FuncTypeParser;
import parser_part.statement.Stmt;
import parser_part.statement.StmtComponent.StmtFor;
import parser_part.statement.StmtComponent.StmtIf;
import parser_part.statement.StmtComponent.StmtReturn;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public class FuncDefParser {
    private TokenList tokenList;
    private SymbolList symbolList;
    private Symbol symbol;

    public FuncDefParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
        this.symbol = null;
    }

    public FuncDef parseFuncDef() {
        FuncTypeParser funcTypeParser = new FuncTypeParser(tokenList);
        IdentParser identParser = new IdentParser(tokenList);
        FuncType funcType = funcTypeParser.parseFuncType();
        Ident ident = identParser.parseIdent();
        Token leftParent = tokenList.getNextToken();
        FuncFParams funcFParams = null;
        Token rightParent = tokenList.getNextToken();
        // check b error and add symbol
        addFuncNameSymbol(funcType, ident);
        symbolList = new SymbolList(SymbolList.sharedSymbolList);
        if (rightParent.getType() == Token.TokenType.LBRACE) {
            // check error without param
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_PARENT));
            rightParent = new Token(Token.TokenType.RPARENT, ")", leftParent.getLineIndex());
        }
        if (rightParent.getType() != Token.TokenType.RPARENT) {
            tokenList.moveBack(1);
            FuncFParamsParser funcFParamsParser = new FuncFParamsParser(tokenList, symbolList);
            funcFParams = funcFParamsParser.parseFuncFParams();
            rightParent = tokenList.getNextToken();
            if (rightParent.getType() == Token.TokenType.LBRACE) {
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_PARENT));
                rightParent = new Token(Token.TokenType.RPARENT, ")", leftParent.getLineIndex());
            }
            for (Symbol symbol1 : funcFParamsParser.getParamSymbols()) {
                symbol.addFuncParamSymbol(symbol1);
            }
        }
        // check j error

        BlockParser blockParser = new BlockParser(tokenList, symbolList);
        blockParser.setFuncBlock(true);
        Block block = blockParser.parseBlock();
        // check f and g error
        if (funcType.getType() == Token.TokenType.VOIDTK) {
            // check f
            if (block.haveReturn() && Debug.status) {
                for (BlockItem blockItem : block.getBlockItems()) {
                    BlockItemComponent blockItemComponent = blockItem.getBlockItemComponent();
                    if (blockItemComponent instanceof Stmt stmt1 && stmt1.getStmtComponent() instanceof StmtReturn stmtReturn && stmtReturn.checkReturn() == 1) {
                        ErrorList.addError(new Error(stmtReturn.getLineIndex(), Error.ErrorType.EXCESSIVE_RETURN));
                    } else if (blockItemComponent instanceof Stmt stmt1 && stmt1.getStmtComponent() instanceof StmtIf stmtIf) {
                        Stmt stmtInIf = stmtIf.getStmt();
                        Stmt stmtInElse = stmtIf.getElseStmt();
                        addRedundantReturnError(stmtInIf);
                        if (stmtInElse != null) {
                            addRedundantReturnError(stmtInElse);
                        }
                    } else if (blockItemComponent instanceof Stmt stmt1 && stmt1.getStmtComponent() instanceof StmtFor stmtFor) {
                        Stmt stmtInFor = stmtFor.getStmt();
                        addRedundantReturnError(stmtInFor);
                    }
                }
            }
        } else {
            if (block.getLastBlockItem() == null || !(block.getLastBlockItem().getBlockItemComponent() instanceof Stmt stmt && stmt.getStmtComponent() instanceof StmtReturn) /*blockParser.checkReturn() != 1 && Debug.status*/) {
                ErrorList.addError(new Error(block.getRightBraceLineIndex(), Error.ErrorType.LACK_RETURN));
            }
        }
        return new FuncDef(funcType, ident, leftParent, funcFParams, rightParent, block);
    }

    public void addFuncNameSymbol(FuncType funcType, Ident ident) {
        int array = funcType.getType() == Token.TokenType.VOIDTK ? -1 : 0;
        Symbol.SymbolType symbolType = funcType.isVoid() ? Symbol.SymbolType.VoidFunc :
                funcType.isChar() ? Symbol.SymbolType.CharFunc : Symbol.SymbolType.IntFunc;
        this.symbol = new Symbol(ident.getLineIndex(), ident.getName(), symbolType, array);
        symbol.setFieldNumber(symbolList.getFieldNumber());
        if (symbolList.containSymbol(symbol) && Debug.status) {
            ErrorList.addError(new Error(ident.getLineIndex(), Error.ErrorType.REPEAT_DECLARE));
        } else {
            symbolList.addSymbol(symbol);
        }
    }

    public void addRedundantReturnError(Stmt stmt) {
        if (stmt.getStmtComponent() instanceof StmtReturn stmtReturn) {
            ErrorList.addError(new Error(stmtReturn.getLineIndex(), Error.ErrorType.EXCESSIVE_RETURN));
        } else if (stmt.getStmtComponent() instanceof Block block) {
            for (BlockItem blockItem : block.getBlockItems()) {
                BlockItemComponent blockItemComponent = blockItem.getBlockItemComponent();
                if (blockItemComponent instanceof Stmt stmt1 && stmt1.getStmtComponent() instanceof StmtReturn stmtReturn && stmtReturn.checkReturn() == 1) {
                    ErrorList.addError(new Error(stmtReturn.getLineIndex(), Error.ErrorType.EXCESSIVE_RETURN));
                } else if (blockItemComponent instanceof Stmt stmt1 && stmt1.getStmtComponent() instanceof StmtIf stmtIf) {
                    Stmt stmtInIf = stmtIf.getStmt();
                    Stmt stmtInElse = stmtIf.getElseStmt();
                    addRedundantReturnError(stmtInIf);
                    if (stmtInElse != null) {
                        addRedundantReturnError(stmtInElse);
                    }
                } else if (blockItemComponent instanceof Stmt stmt1 && stmt1.getStmtComponent() instanceof StmtFor stmtFor) {
                    Stmt stmtInFor = stmtFor.getStmt();
                    addRedundantReturnError(stmtInFor);
                }
            }
        }
    }
}
