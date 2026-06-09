package frontend;

import exeptions.ErrorHandler;
import exeptions.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.CompUnit;
import frontend.parser.decl.types.Decl;
import frontend.parser.decl.types.Def;
import frontend.parser.expr.types.*;
import frontend.parser.func.types.FuncDef;
import frontend.parser.func.types.FuncFParam;
import frontend.parser.func.types.FuncFParams;
import frontend.parser.stmt.types.Block;
import frontend.parser.stmt.types.BlockItem;
import frontend.parser.stmt.types.ForStmt;
import frontend.parser.stmt.types.Stmt;
import frontend.symbol.Symbol;
import frontend.symbol.SymbolTable;
import frontend.symbol.SymbolType;

import java.util.ArrayList;
import java.util.Comparator;

public class SymbolTableBuilder {
    private final CompUnit compUnit;
    private int nextScopeId = 1;
    private final ArrayList<SymbolTable> symbolTables = new ArrayList<>();
    private SymbolTable curTable = null;
    private final ErrorList errorList = new ErrorList();

    public SymbolTableBuilder(CompUnit compUnit) {
        this.compUnit = compUnit;
    }
    public CompUnit getCompUnit() {
        return this.compUnit;
    }
    public void buildSymbolTables() {
        // build symbol table
        curTable = new SymbolTable(nextScopeId++, null);
        // 本作用域编号是scopeId=1，本作用域外层作用域编号是0
        symbolTables.add(curTable);
        for (Decl decl: compUnit.getGlobalDecls()) {
            checkDecl(decl);
        }
        for (FuncDef funcDef: compUnit.getFunctions()) {
            checkFunc(funcDef);
        }
        checkFunc(compUnit.getMainFuncDef());
        symbolTables.sort(new Comparator<SymbolTable>() {
            @Override
            public int compare(SymbolTable o1, SymbolTable o2) {
                return o1.getScope() - o2.getScope();
            }
        });
    }
    private void checkDecl(Decl decl) {
        if (decl.getFirstDef() != null) {
            Def firstDef = decl.getFirstDef();
            checkDef(decl, firstDef);
            if (decl.getDefs() != null) {
                for (Def def: decl.getDefs()) {
                    checkDef(decl, def);
                }
            }
        }
    }
    private void checkFunc(FuncDef funcDef) {
        SymbolTable inner = new SymbolTable(SymbolTable.ScopeType.FUNC, nextScopeId++, curTable);
        symbolTables.add(inner);

        if (funcDef.getIdent().getType() == TokenType.MAINTK) {
            curTable = inner;
            curTable.setFuncSymbol(new Symbol(curTable.getScope(), funcDef.getIdent(), SymbolType.IntFunc));
            checkFParams(funcDef);
            checkBlock(SymbolTable.ScopeType.FUNC, funcDef.getBlock());
            curTable = inner.getOuterScope();
            return;
        }
        if (curTable.findSymbol(funcDef.getIdent(), false) != null) {
            errorList.add(ErrorHandler.RedefinedToken(funcDef));
            return;
        }
        SymbolType symType;
        switch (funcDef.getFuncType()) {
            case VOIDTK -> symType = SymbolType.VoidFunc;
            case CHARTK -> symType = SymbolType.CharFunc;
            default -> symType = SymbolType.IntFunc;
        }
        Symbol funcSymbol = new Symbol(curTable.getScope(), funcDef.getIdent(), symType);

        if (funcDef.getFuncFParams() != null) {
            FuncFParam firstParam = funcDef.getFuncFParams().getFirstParam();
            funcSymbol.addParam(firstParam.getSymbolType());
            for (FuncFParam funcFParam: funcDef.getFuncFParams().getParams()) {
                funcSymbol.addParam(funcFParam.getSymbolType());
            }
        }
        curTable.addSymbol(funcSymbol);

        // 将函数参数作为变量存入到函数的作用域内
        curTable = inner;
        // 设置当前作用域所对应的函数符号
        curTable.setFuncSymbol(funcSymbol);
        checkFParams(funcDef);
        checkBlock(SymbolTable.ScopeType.FUNC, funcDef.getBlock());
        curTable = inner.getOuterScope();
    }

    private void checkFParams(FuncDef funcDef) {
        if (funcDef.getFuncFParams() != null) {
            FuncFParams funcFParams = funcDef.getFuncFParams();
            FuncFParam firstParam = funcFParams.getFirstParam();
            if (firstParam != null) {
                curTable.addSymbol(firstParam.getIdent(), firstParam.getSymbolType());
                for (FuncFParam param: funcFParams.getParams()) {
                    if (curTable.findSymbol(param.getIdent(), false) == null)
                        curTable.addSymbol(param.getIdent(), param.getSymbolType());
                    else
                        errorList.add(ErrorHandler.RedefinedToken(param));
                }
            }
        }
    }

    private void checkBlock(SymbolTable.ScopeType scopeType, Block block) {
        ArrayList<BlockItem> blockItems = block.getBlockItems();
        for (BlockItem blockItem: blockItems) {
            if (blockItem.getClass().getSimpleName().equals("Stmt")) {
                checkStmt(scopeType, (Stmt)blockItem);
            } else {
                checkDecl((Decl)blockItem);
            }
        }
        // 如果是函数，还需要判断返回值是否对应return
        if (scopeType != SymbolTable.ScopeType.FUNC) return;
        if (curTable.getFuncSymbol().getType() == SymbolType.VoidFunc) return;
        if (blockItems.isEmpty()) {
            errorList.add(ErrorHandler.MissReturn(block));return;
        }
        BlockItem lastBlockItem = blockItems.get(blockItems.size() - 1);
        if (!lastBlockItem.getClass().getSimpleName().equals("Stmt")) {
            errorList.add(ErrorHandler.MissReturn(block));return;
        }
        if (((Stmt)lastBlockItem).getType() != Stmt.StmtType.RETURN)
            errorList.add(ErrorHandler.MissReturn(block));
    }
    private void checkStmt(SymbolTable.ScopeType scopeType, Stmt stmt) {
        switch (stmt.getType()) {
            case ASSIGN_STMT, INPUT -> {
                LVal lVal = stmt.getLVal();
                if (lVal == null) break;
                checkLVal(lVal);
            }
            case EXP_STMT -> {
                if (stmt.getExp() == null) break;
                checkExp(stmt.getExp());
            }
            case BLOCK_STMT -> {
                SymbolTable inner = new SymbolTable(scopeType, nextScopeId++, curTable);
                symbolTables.add(inner);
                curTable = inner;
                checkBlock(scopeType, stmt.getStmtBlock());
                curTable = inner.getOuterScope();
            }
            case IF_ELSE -> {
                if (stmt.getCond() != null)
                    checkCond(stmt.getCond());
                if (stmt.getIfStmt() != null)
                    checkStmt(SymbolTable.ScopeType.IF_ELSE, stmt.getIfStmt());
                if (stmt.getElseStmt() != null) {
                    checkStmt(SymbolTable.ScopeType.IF_ELSE, stmt.getElseStmt());
                }
            }
            case FOR -> {
                if (stmt.getInitStmt() != null)
                    checkForStmt(stmt.getInitStmt());
                if (stmt.getCond() != null)
                    checkCond(stmt.getCond());
                if (stmt.getStepStmt() != null)
                    checkForStmt(stmt.getStepStmt());
                if (stmt.getForLoopBody() != null)
                    checkStmt(SymbolTable.ScopeType.FOR, stmt.getForLoopBody());
            }
            case BREAK_OR_CONTINUE -> {
                if (!curTable.hasOuterScopeOfType(SymbolTable.ScopeType.FOR)) {
                    errorList.add(ErrorHandler.IllegalBreakContinue(stmt));
                }
            }
            case RETURN -> {
                Symbol funcSymbol = curTable.getFuncSymbol();
                if (funcSymbol == null) break;
                if (funcSymbol.getType() == SymbolType.VoidFunc) {
                    if (stmt.getExp() != null)
                        errorList.add(ErrorHandler.IllegalReturn(stmt));
                }
            }
            case PRINTF -> {
                int argNum = 0;
                String outputString = stmt.getStringConst().getName();
                for (int i = 0; i < outputString.length(); i++) {
                    if (outputString.charAt(i) == '%' && i + 1 < outputString.length()) {
                        if (outputString.charAt(i + 1) == 'd' || outputString.charAt(i + 1) == 'c') {
                            argNum++; i++;
                        }
                    }
                }
                if (stmt.getExps().size() != argNum) {
                    errorList.add(ErrorHandler.MisMatchPrintf(stmt));
                }
            }
        }
    }

    private void checkExp(Exp exp) {
        AddExp addExp = exp.getAddExp();
        for (MulExp mulExp: addExp.getMulExps()) {

        }
    }

    private void checkCond(Cond cond) {

    }

    private void checkForStmt(ForStmt forStmt) {
        LVal lVal = forStmt.getLVal();
        if (lVal == null) return;
        checkLVal(lVal);
        Exp exp = forStmt.getExp();
        if (exp != null) checkExp(exp);
    }

    /**
     * 检查左值是否存在未定义、修改const等错误
     * @param lVal 输入左值
     */
    private void checkLVal(LVal lVal) {
        Token lValIdent = lVal.getIdent();
        Symbol definition = curTable.findSymbol(lValIdent, true);
        if (definition == null) {
            errorList.add(ErrorHandler.UndefinedToken(lVal));
        } else if (definition.getType() == SymbolType.ConstChar
                || definition.getType() == SymbolType.ConstInt) {
            errorList.add(ErrorHandler.ModifyConst(lVal));
        }
    }

    private void checkDef(Decl decl, Def def) {
        if (curTable.findSymbol(def.getIdent(), false) != null) {
            errorList.add(ErrorHandler.RedefinedToken(def));
            return;
        }
        SymbolType symbolType;
        if (decl.isConst()) {
            if (decl.getBType() == TokenType.INTTK) {
                if (def.isArray()) {
                    symbolType = SymbolType.ConstIntArray;
                } else {
                    symbolType = SymbolType.ConstInt;
                }
            } else {
                if (def.isArray()) {
                    symbolType = SymbolType.ConstCharArray;
                } else {
                    symbolType = SymbolType.ConstChar;
                }
            }
        } else {
            if (decl.getBType() == TokenType.INTTK) {
                if (def.isArray()) {
                    symbolType = SymbolType.IntArray;
                } else {
                    symbolType = SymbolType.Int;
                }
            } else {
                if (def.isArray()) {
                    symbolType = SymbolType.CharArray;
                } else {
                    symbolType = SymbolType.Char;
                }
            }
        }
        curTable.addSymbol(def.getIdent(), symbolType);
    }
    public ErrorList getErrorList() {
        return this.errorList;
    }
    public ArrayList<SymbolTable> getSymbolTables() {
        return this.symbolTables;
    }
}
