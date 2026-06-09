package frontend;

import error.Error;
import error.ErrorList;
import error.ErrorType;
import struct.*;
import symbol.*;

import java.util.ArrayList;
import java.util.List;

public class SemanticAnalyzer {
    private static SemanticAnalyzer instance;
    private CompUnit root;
    private List<SymbolTable> symbolTables = new ArrayList<>();
    private SymbolTable curSymTab;
    private int curScope = 1;
    private int totalScope = 0;
    private SymbolType funcType = null;
    private int loopLevel = 0;

    public static SemanticAnalyzer getInstance() {
        if (instance == null) {
            instance = new SemanticAnalyzer();
        }
        return instance;
    }

    public void setRoot(CompUnit root) {
        this.root = root;
    }

    public void semanticAnalysis() {
        /* 从头遍历 AST 每个节点构建符号表并进行错误处理 */
        visitCompUnit(root);
    }

    public String printSymbolTables() {
        StringBuilder sb = new StringBuilder();
        for (SymbolTable symbolTable: symbolTables) {
            int scope = symbolTable.getScope();
            for (Symbol symbol: symbolTable.getSymbols().values()) {
                String name = symbol.getName();
                SymbolType type = symbol.getType();
                if (name.equals("main")) {
                    continue;
                }
                sb.append(scope).append(" ").append(name).append(" ").append(type).append("\n");
            }
        }
        return sb.toString();
    }

    private void initSymbolTables() {
        /* 初始化全局变量符号表 */
        SymbolTable globalTable = new SymbolTable(null, ++totalScope, false);
        symbolTables.add(globalTable);
        curSymTab = globalTable;
    }

    private void createSymbolTable(boolean isInFunc) {
        SymbolTable symbolTable = new SymbolTable(curSymTab, ++totalScope, isInFunc);
        symbolTables.add(symbolTable);
        curSymTab = symbolTable;
        curScope = symbolTable.getScope();
    }

    private void backToFather() {
        curSymTab = curSymTab.getFather();
        curScope = curSymTab.getScope();
    }

    private boolean containsSymbol(String name) {
        for (SymbolTable symbolTable = curSymTab; symbolTable != null; symbolTable = symbolTable.getFather()) {
            if (symbolTable.isExist(name)) {
                return true;
            }
        }
        return false;
    }

    private Symbol getSymbol(String name) {
        for (SymbolTable symbolTable = curSymTab; symbolTable != null; symbolTable = symbolTable.getFather()) {
            if (symbolTable.isExist(name)) {
                return symbolTable.getSymbols().get(name);
            }
        }
        return null;
    }

    private void visitCompUnit(CompUnit compUnit) {
        /* CompUnit → {Decl} {FuncDef} MainFuncDef */
        initSymbolTables();
        for (Decl decl: compUnit.getDecl()) {
            visitDecl(decl);
        }
        for (FuncDef funcDef: compUnit.getFuncDef()) {
            visitFuncDef(funcDef);
        }
        visitMainFuncDef(compUnit.getMainFuncDef());
    }

    private void visitDecl(Decl decl) {
        /* Decl → ConstDecl | VarDecl */
        if (decl.getConstDecl() != null) {
            visitConstDecl(decl.getConstDecl());
        } else {
            visitVarDecl(decl.getVarDecl());
        }
    }

    private void visitConstDecl(ConstDecl constDecl) {
        /* ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' */
        for (ConstDef constDef: constDecl.getConstDef()) {
            visitConstDef(constDef, constDecl.getBtype());
        }
    }

    private void visitConstDef(ConstDef constDef, BType bType) {
        /* ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // b */
        if (curSymTab.isExist(constDef.getIdent().getContent())) {
            ErrorList.getInstance().addError(new Error(constDef.getIdent().getLine(), ErrorType.b));
            return;
        }
        SymbolType type;
        if (constDef.getConstExp() != null) {
            visitConstExp(constDef.getConstExp());
            if (bType.getType().getContent().equals("int")) {
                type = SymbolType.ConstIntArray;
            } else {
                type = SymbolType.ConstCharArray;
            }
            visitConstInitVal(constDef.getConstInitVal());
            curSymTab.addSymbol(new VarSym(constDef.getIdent().getContent(), type, curScope, null, true, true));
        } else {
            visitConstInitVal(constDef.getConstInitVal());
            if (bType.getType().getContent().equals("int")) {
                type = SymbolType.ConstInt;
            } else {
                type = SymbolType.ConstChar;
            }
            curSymTab.addSymbol(new VarSym(constDef.getIdent().getContent(), type, curScope, null, true, false));
        }
    }

    private void visitConstExp(ConstExp constExp) {
        /* ConstExp → AddExp 注：使用的 Ident 必须是常量 */
        visitAddExp(constExp.getAddExp());
    }

    private void visitAddExp(AddExp addExp) {
        /* AddExp → MulExp { ('+' | '-') MulExp } */
        for (MulExp mulExp: addExp.getMulExp()) {
            visitMulExp(mulExp);
        }
    }

    private void visitMulExp(MulExp mulExp) {
        /* MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp } */
        for (UnaryExp unaryExp: mulExp.getUnaryExp()) {
            visitUnaryExp(unaryExp);
        }
    }

    private void visitUnaryExp(UnaryExp unaryExp) {
        /* UnaryExp → PrimaryExp
        * | Ident '(' [FuncRParams] ')' // c d e
        * | UnaryOp UnaryExp */
        if (unaryExp.getPrimaryExp() != null) {
            visitPrimaryExp(unaryExp.getPrimaryExp());
        } else if (unaryExp.getUnaryExp() != null) {
            visitUnaryExp(unaryExp.getUnaryExp());
        } else {
            if (!containsSymbol(unaryExp.getIdent().getContent())) {
                ErrorList.getInstance().addError(new Error(unaryExp.getIdent().getLine(), ErrorType.c));
                return;
            }
            FuncSym funcSym = (FuncSym) getSymbol(unaryExp.getIdent().getContent());
            if (funcSym == null) {
                throw new RuntimeException("FuncSym " + unaryExp.getIdent().getContent() + " is not found");
            }

            if (unaryExp.getFuncRParams() == null) {
                if (!funcSym.getArgs().isEmpty()) {
                    ErrorList.getInstance().addError(new Error(unaryExp.getIdent().getLine(), ErrorType.d));
                }
            } else if (funcSym.getArgs() == null || funcSym.getArgs().isEmpty()) {
                if (unaryExp.getFuncRParams() != null) {
                    ErrorList.getInstance().addError(new Error(unaryExp.getIdent().getLine(), ErrorType.d));
                }
            } else {
                int paramNum = unaryExp.getFuncRParams().getExp().size();
                int argNum = funcSym.getArgs().size();
                if (paramNum != argNum) {
                    ErrorList.getInstance().addError(new Error(unaryExp.getIdent().getLine(), ErrorType.d));
                    return;
                } else if (!matchParams(funcSym.getArgs(), unaryExp.getFuncRParams().getExp())) {
                    ErrorList.getInstance().addError(new Error(unaryExp.getIdent().getLine(), ErrorType.e));
                    return;
                }
                visitFuncRParams(unaryExp.getFuncRParams());
            }
        }
    }

    private boolean matchParams(List<Symbol> args, List<Exp> exps) {
        for (int i = 0; i < exps.size(); i++) {
            SymbolType argType = args.get(i).getType();
            String name = getTypeInExp(exps.get(i));
            /* argType 只有 Int, Char, IntArray, CharArray 四种 */
            if (name.equals("notArray")) {
                /* 传递变量给数组 */
                if (argType == SymbolType.IntArray || argType == SymbolType.CharArray) {
                    return false;
                }
            } else {
                Symbol param = getSymbol(name);
                if (param == null) {
                    throw new RuntimeException("Symbol " + name + " is not found");
                }
                SymbolType paramType = param.getType();
                if (argType == SymbolType.Int || argType == SymbolType.Char) {
                    /* 传递数组给变量 */
                    if (paramType == SymbolType.IntArray || paramType == SymbolType.CharArray ||
                            paramType == SymbolType.ConstIntArray || paramType == SymbolType.ConstCharArray) {
                        return false;
                    }
                } else if (argType == SymbolType.IntArray) {
                    /* 传递 char 型数组给 int 型数组 && 传递变量给数组 */
                    if (paramType != SymbolType.IntArray && paramType != SymbolType.ConstIntArray) {
                        return false;
                    }
                } else if (argType == SymbolType.CharArray) {
                    /* 传递 int 型数组给 char 型数组 && 传递变量给数组 */
                    if (paramType != SymbolType.CharArray && paramType != SymbolType.ConstCharArray) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    private String getTypeInExp(Exp exp) {
        return getTypeInAddExp(exp.getAddExp());
    }

    private String getTypeInAddExp(AddExp addExp) {
        /* 有运算符号的一定不是数组，只需判断对应的参数是否是数组即可 */
        if (!addExp.getOperater().isEmpty()) {
            return "notArray";
        }
        return getTypeInMulExp(addExp.getMulExp().get(0));
    }

    private String getTypeInMulExp(MulExp mulExp) {
        if (!mulExp.getOperater().isEmpty()) {
            return "notArray";
        }
        return getTypeInUnaryExp(mulExp.getUnaryExp().get(0));
    }

    private String getTypeInUnaryExp(UnaryExp unaryExp) {
        if (unaryExp.getPrimaryExp() != null) {
            return getTypeInPrimaryExp(unaryExp.getPrimaryExp());
        } else {
            return "notArray";
        }
    }

    private String getTypeInPrimaryExp(PrimaryExp primaryExp) {
        if (primaryExp.getLVal() != null) {
            return getTypeInLVal(primaryExp.getLVal());
        } else {
            return "notArray";
        }
    }

    private String getTypeInLVal(LVal lVal) {
        if (lVal.getlBrackToken() != null) {
            return "notArray";
        } else {
            return lVal.getIdent().getContent();
        }
    }

    private void visitFuncRParams(FuncRParams funcRParams) {
        /* FuncRParams → Exp { ',' Exp } */
        for (Exp exp: funcRParams.getExp()) {
            visitExp(exp);
        }
    }

    private void visitPrimaryExp(PrimaryExp primaryExp) {
        /* PrimaryExp → '(' Exp ')' | LVal | Number | Character */
        if (primaryExp.getExp() != null) {
            visitExp(primaryExp.getExp());
        } else if (primaryExp.getLVal() != null) {
            visitLVal(primaryExp.getLVal());
        }
    }

    private void visitExp(Exp exp) {
        /* Exp → AddExp */
        visitAddExp(exp.getAddExp());
    }

    private void visitLVal(LVal lval) {
        /* LVal → Ident ['[' Exp ']'] // c */
        if (!containsSymbol(lval.getIdent().getContent())) {
            ErrorList.getInstance().addError(new Error(lval.getIdent().getLine(), ErrorType.c));
            return;
        }
        if (lval.getExp() != null) {
            visitExp(lval.getExp());
        }
    }

    private void visitConstInitVal(ConstInitVal constInitVal) {
        /* ConstInitVal → ConstExp
         * | '{' [ ConstExp { ',' ConstExp } ] '}'
         * | StringConst
         */
        if (constInitVal.getConstExp() != null) {
            for (ConstExp constExp: constInitVal.getConstExp()) {
                visitConstExp(constExp);
            }
        }
    }

    private void visitVarDecl(VarDecl varDecl) {
        /* VarDecl → BType VarDef { ',' VarDef } ';' */
        for (VarDef varDef: varDecl.getVarDef()) {
            visitVarDef(varDef, varDecl.getBType());
        }
    }

    private void visitVarDef(VarDef varDef, BType bType) {
        /* VarDef → Ident [ '[' ConstExp ']' ] // b
         * | Ident [ '[' ConstExp ']' ] '=' InitVal // b
         */
        if (curSymTab.isExist(varDef.getIdent().getContent())) {
            ErrorList.getInstance().addError(new Error(varDef.getIdent().getLine(), ErrorType.b));
            return;
        }
        SymbolType type;
        if (varDef.getConstExp() != null) {
            visitConstExp(varDef.getConstExp());
            if (bType.getType().getContent().equals("int")) {
                type = SymbolType.IntArray;
            } else {
                type = SymbolType.CharArray;
            }
            if (varDef.getInitVal() != null) {
                visitInitVal(varDef.getInitVal());
            }
            curSymTab.addSymbol(new VarSym(varDef.getIdent().getContent(), type, curScope, null, false, true));
        } else {
            if (bType.getType().getContent().equals("int")) {
                type = SymbolType.Int;
            } else {
                type = SymbolType.Char;
            }
            if (varDef.getInitVal() != null) {
                visitInitVal(varDef.getInitVal());
            }
            curSymTab.addSymbol(new VarSym(varDef.getIdent().getContent(), type, curScope, null, false, false));
        }
    }

    private void visitInitVal(InitVal initVal) {
        /* InitVal → Exp
         * | '{' [ Exp { ',' Exp } ] '}'
         * | StringConst
         */
        if (initVal.getExp() != null) {
            for (Exp exp: initVal.getExp()) {
                visitExp(exp);
            }
        }
    }

    private void visitFuncDef(FuncDef funcDef) {
        /* FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // b g */
        if (curSymTab.isExist(funcDef.getIdent().getContent())) {
            ErrorList.getInstance().addError(new Error(funcDef.getIdent().getLine(), ErrorType.b));
        }
        funcType = switch (funcDef.getFuncType().getType().getContent()) {
            case "void" -> SymbolType.VoidFunc;
            case "int" -> SymbolType.IntFunc;
            default -> SymbolType.CharFunc;
        };
        FuncSym funcSym = new FuncSym(funcDef.getIdent().getContent(), funcType, curScope);
        if (!curSymTab.isExist(funcDef.getIdent().getContent())) {
            curSymTab.addSymbol(funcSym);
        }

        createSymbolTable(true);
        if (funcDef.getFuncFParams() != null) {
            visitFuncFParams(funcDef.getFuncFParams(), funcSym);
        }
        visitBlock(funcDef.getBlock());
        backToFather();
    }

    private void visitFuncFParams(FuncFParams funcFParams, FuncSym funcSym) {
        /* FuncFParams → FuncFParam { ',' FuncFParam } */
        for (FuncFParam funcFParam: funcFParams.getFuncFParam()) {
            visitFuncFParam(funcFParam, funcSym);
        }
    }

    private void visitFuncFParam(FuncFParam funcFParam, FuncSym funcSym) {
        /* FuncFParam → BType Ident ['[' ']'] // b */
        if (curSymTab.isExist(funcFParam.getIdent().getContent())) {
            ErrorList.getInstance().addError(new Error(funcFParam.getIdent().getLine(), ErrorType.b));
            return;
        }
        SymbolType type;
        VarSym varSym;
        if (funcFParam.getlBrackToken() != null) {
            if (funcFParam.getBType().getType().getContent().equals("int")) {
                type = SymbolType.IntArray;
            } else {
                type = SymbolType.CharArray;
            }
            varSym = new VarSym(funcFParam.getIdent().getContent(), type, curScope, null, false, true);
        } else {
            if (funcFParam.getBType().getType().getContent().equals("int")) {
                type = SymbolType.Int;
            } else {
                type = SymbolType.Char;
            }
            varSym = new VarSym(funcFParam.getIdent().getContent(), type, curScope, null, false, false);
        }
        curSymTab.addSymbol(varSym);
        funcSym.addArg(varSym);
    }

    private void visitBlock(Block block) {
        /* Block → '{' { BlockItem } '}' */
        for (BlockItem blockItem: block.getBlockItem()) {
            visitBlockItem(blockItem);
        }
        if (curSymTab.isInFunc()) {
            if (funcType == SymbolType.IntFunc || funcType == SymbolType.CharFunc) {
                if (block.getBlockItem().isEmpty() ||
                        block.getBlockItem().get(block.getBlockItem().size() - 1).getStmt() == null ||
                        block.getBlockItem().get(block.getBlockItem().size() - 1).getStmt().getReturnToken() == null) {
                    ErrorList.getInstance().addError(new Error(block.getRBraceToken().getLine(), ErrorType.g));
                }
            }
        }
    }

    private void visitBlockItem(BlockItem blockItem) {
        /* BlockItem → Decl | Stmt */
        if (blockItem.getDecl() != null) {
            visitDecl(blockItem.getDecl());
        } else {
            visitStmt(blockItem.getStmt());
        }
    }

    private void visitStmt(Stmt stmt) {
        /* Stmt → LVal '=' Exp ';' // h
         * | LVal '=' 'getint' '(' ')' ';' // h
         * | LVal '=' 'getchar' '(' ')' ';' // h
         * | [ Exp ] ';'
         * | Block
         * | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
         * | 'for' '(' [ ForStmt ] ';' [ Cond ] ';' [ ForStmt ] ')' Stmt // h
         * | 'break' ';' // m
         * | 'continue' ';' // m
         * | 'return' [ Exp ] ';' // f
         * | 'printf' '(' StringConst { ',' Exp } ')' ';' // l
         */
        if (stmt.getBlock() != null) {
            createSymbolTable(false);
            visitBlock(stmt.getBlock());
            backToFather();
        } else if (stmt.getIfToken() != null) {
            visitCond(stmt.getCond());
            visitStmt(stmt.getStmt().get(0));
            if (stmt.getElseToken() != null) {
                visitStmt(stmt.getStmt().get(1));
            }
        } else if (stmt.getForToken() != null) {
            loopLevel++;
            if (stmt.getForStmt_1() != null) {
                visitForStmt(stmt.getForStmt_1());
            }
            if (stmt.getCond() != null) {
                visitCond(stmt.getCond());
            }
            if (stmt.getForStmt_2() != null) {
                visitForStmt(stmt.getForStmt_2());
            }
            visitStmt(stmt.getStmt().get(0));
            loopLevel--;
        } else if (stmt.getBreakToken() != null) {
            if (loopLevel == 0) {
                ErrorList.getInstance().addError(new Error(stmt.getBreakToken().getLine(), ErrorType.m));
            }
        } else if (stmt.getContinueToken() != null) {
            if (loopLevel == 0) {
                ErrorList.getInstance().addError(new Error(stmt.getContinueToken().getLine(), ErrorType.m));
            }
        } else if (stmt.getReturnToken() != null) {
            if (funcType == SymbolType.VoidFunc) {
                if (stmt.getExp() != null && !stmt.getExp().isEmpty()){
                    ErrorList.getInstance().addError(new Error(stmt.getReturnToken().getLine(), ErrorType.f));
                }
            }
            if (stmt.getExp() != null && !stmt.getExp().isEmpty()) {
                visitExp(stmt.getExp().get(0));
            }
        } else if (stmt.getPrintfToken() != null) {
            String stringConst = stmt.getStringConst().getContent();
            int formatNum = 0;
            int expNum = stmt.getExp().size();
            for (int i = 0; i < stringConst.length() - 1; i++) {
                if (stringConst.charAt(i) == '%') {
                    if (stringConst.charAt(i + 1) == 'c' || stringConst.charAt(i + 1) == 'd') {
                        formatNum++;
                    }
                }
            }
            if (formatNum != expNum) {
                ErrorList.getInstance().addError(new Error(stmt.getPrintfToken().getLine(), ErrorType.l));
            }
            for (Exp exp: stmt.getExp()) {
                visitExp(exp);
            }
        } else if (stmt.getGetintToken() != null || stmt.getGetcharToken() != null) {
            visitLVal(stmt.getLVal());
            VarSym lVal = (VarSym) getSymbol(stmt.getLVal().getIdent().getContent());
            if (lVal != null) {
                if (lVal.isConst()) {
                    ErrorList.getInstance().addError(new Error(stmt.getLVal().getIdent().getLine(), ErrorType.h));
                }
            }
        } else {
            if (stmt.getLVal() != null) {
                visitLVal(stmt.getLVal());
                VarSym lVal = (VarSym) getSymbol(stmt.getLVal().getIdent().getContent());
                if (lVal != null) {
                    if (lVal.isConst()) {
                        ErrorList.getInstance().addError(new Error(stmt.getLVal().getIdent().getLine(), ErrorType.h));
                    }
                }
                visitExp(stmt.getExp().get(0));
            } else {
                if (stmt.getExp() != null && !stmt.getExp().isEmpty()) {
                    visitExp(stmt.getExp().get(0));
                }
            }
        }
    }

    private void visitCond(Cond cond) {
        /* Cond → LOrExp */
        visitLOrExp(cond.getLOrExp());
    }

    private void visitLOrExp(LOrExp lOrExp) {
        /* LOrExp → LAndExp { '||' LAndExp } */
        for (LAndExp lAndExp: lOrExp.getLAndExp()) {
            visitLAndExp(lAndExp);
        }
    }

    private void visitLAndExp(LAndExp lAndExp) {
        /* LAndExp → EqExp { '&&' EqExp } */
        for (EqExp eqExp: lAndExp.getEqExp()) {
            visitEqExp(eqExp);
        }
    }

    private void visitEqExp(EqExp eqExp) {
        /* EqExp → RelExp { ('==' | '!=') RelExp } */
        for (RelExp relExp: eqExp.getRelExp()) {
            visitRelExp(relExp);
        }
    }

    private void visitRelExp(RelExp relExp) {
        /* RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp } */
        for (AddExp addExp: relExp.getAddExp()) {
            visitAddExp(addExp);
        }
    }

    private void visitForStmt(ForStmt forStmt) {
        /* ForStmt → LVal '=' Exp // h */
        visitLVal(forStmt.getLVal());
        VarSym lVal = (VarSym) getSymbol(forStmt.getLVal().getIdent().getContent());
        if (lVal != null) {
            if (lVal.isConst()) {
                ErrorList.getInstance().addError(new Error(forStmt.getLVal().getIdent().getLine(), ErrorType.h));
            }
            visitExp(forStmt.getExp());
        }
    }

    private void visitMainFuncDef(MainFuncDef mainFuncDef) {
        /* MainFuncDef → 'int' 'main' '(' ')' Block // g */
        funcType = SymbolType.IntFunc;
        curSymTab.addSymbol(new FuncSym("main", funcType, curScope));
        createSymbolTable(true);
        visitBlock(mainFuncDef.getBlock());
        backToFather();
    }
}
