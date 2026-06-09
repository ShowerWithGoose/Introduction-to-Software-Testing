package Sym;

import IO.*;
import AST.*;
import Error.*;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;

public class ErrorParser {
    CompUnitNode compUnitNode;

    HashMap<Integer, Symbols> symbolsHashMap;

    ArrayList<error> errors;

    int forLoopCount = 0;

    IO io;

    Stack<Integer> stack = new Stack<>();

    int scope;

    int scopeId;

    boolean needReturn;

    public ErrorParser(CompUnitNode compUnitNode, IO io) {
        this.compUnitNode = compUnitNode;
        this.symbolsHashMap = new HashMap<>();
        this.errors = new ArrayList<>();
        this.scope = 0;
        this.scopeId = 0;
        this.needReturn = false;
        this.io = io;
    }

    private void enter() {
        scope++;
        scopeId = scope;
        stack.push(scopeId);
        symbolsHashMap.put(scopeId, new Symbols(io));
    }

    private void leave() {
        stack.pop();
        scopeId = stack.peek();
    }

    public void parse() {
        enter();
        parseDecl(compUnitNode.getDecls());
        parseFuncDef(compUnitNode.getFuncDefs());
        needReturn = true;
        parseMainFuncDef(compUnitNode.getMainFuncDef());
        printParser();
        errorMessage.addError(errors);
    }

    private void parseMainFuncDef(MainFuncDef mainFuncDef) {
        enter();
        parseBlock(mainFuncDef.getBlockNode(), true);
        leave();
    }

    private boolean isNeedReturn(Token type) {
        return type.getToken().equals("int") || type.getToken().equals("char");
    }

    private void parseFuncDef(List<FuncDefNode> funcDefs) {
        for (FuncDefNode funcDefNode : funcDefs) {
            Token type = funcDefNode.getReturnType().getBtype();
            Token id = funcDefNode.getFunctionName();
            if (symbolsHashMap.get(scopeId).isDeclared(id)) {
                errors.add(new error(id.getToken(), id.getLineNumber(), "b"));
            } else {
                symbolsHashMap.get(scopeId).addSymbol(type, id, false, false, true, scopeId);
            }
        }
        for (FuncDefNode funcDefNode : funcDefs) {
            enter();
            needReturn = isNeedReturn(funcDefNode.getReturnType().getBtype());
            parseParam(funcDefNode.getFpParams());
            parseBlock(funcDefNode.getBlock(), true);
            needReturn = false;
            leave();
        }
    }

    private void parseBlock(BlockNode block, boolean isFunc) {
        if (isFunc && needReturn && block.getBlockItems().isEmpty()) {
            errors.add(new error("no return", block.getEndLine(), "g"));
        } else {
            for (BlockItem blockItem : block.getBlockItems()) {
                if (blockItem.getT() == 1) {
                    parseStmt(blockItem.getStmtNode());
                }
                else {
                    List<DeclNode> decls = new ArrayList<>();
                    decls.add(blockItem.getDeclNode());
                    parseDecl(decls);
                }
                if (isFunc && block.getBlockItems().indexOf(blockItem) == block.getBlockItems().size() - 1) {
                    if (needReturn) {
                        if (blockItem.getT() == 1) {
                            if(blockItem.getStmtNode().getT() == 11) {

                            }
                            else {
                                errors.add(new error("no return", block.getEndLine(), "g"));
                            }
                        } else {
                            errors.add(new error("no return", block.getEndLine(), "g"));
                        }
                    }
                }
            }
        }

    }

    private void parseStmt(StmtNode stmtNode) {
        int t = stmtNode.getT();
        if (t == 1) {
            parseLValStmt((LValStmt) stmtNode.getValue());
        }
        else if (t == 2) {
            parseGetIntStmt((GetIntStmt) stmtNode.getValue());
        }
        else if (t == 3) {
            parseGetCharStmt((GetCharStmt)stmtNode.getValue());
        }
        else if (t == 4) {
            parseExp((ExprNode) stmtNode.getValue());
        }
        else if (t == 5) {

        }
        if (t == 6) {
            parseIfElseStmt((IfElseStmtNode)stmtNode.getValue());
        }
        else if (t == 7) {
            parseIfStmt((IfStmtNode)stmtNode.getValue());
        }
        else if (t == 8) {
            parseForNode((ForNode)stmtNode.getValue());
        }
        else if (t == 9) {
            parseBreakStmt((BreakStmt)stmtNode.getValue());
        }
        else if (t == 10) {
            parseContinueStmt((ContinueStmt)stmtNode.getValue());
        }
        else if(t == 11) {
            parseReturnStmt((ReturnStmt)stmtNode.getValue());
        }
        else if(t == 12) {
            parsePrintfStmt((PrintfStmt)stmtNode.getValue());
        }
        else if (t == 13) {
            enter();
            parseBlock((BlockNode) stmtNode.getValue(), false);
            leave();
        }
    }

    private void parseReturnStmt(ReturnStmt value) {
        if (!needReturn && value.getExpr() != null) {
            System.out.println("---" + needReturn);
            System.out.println(value.getExpr());
            errors.add(new error(value.getToken().getToken(), value.getToken().getLineNumber(), "f"));
        }
    }

    private void parseJudgeLastReturn() {

    }

    private void parseContinueStmt(ContinueStmt value) {
        if (forLoopCount >= 1) {

        } else {
            errors.add(new error(value.getToken().getToken(), value.getToken().getLineNumber(), "m"));
        }
    }

    private void parseBreakStmt(BreakStmt value) {
        if (forLoopCount >= 1) {

        } else {
            errors.add(new error(value.getToken().getToken(), value.getToken().getLineNumber(), "m"));
        }
    }

    private void parseGetCharStmt(GetCharStmt value) {
        LValNode lValNode = value.getLVal();
        parseLVal(lValNode);
        Token id = lValNode.getId();
        if (lookup(id) != -1) {
            Symbol symbol = findInSymbolsHashMap(id);
            boolean isConst = symbol.isConst();
            if (isConst) {
                errors.add(new error(id.getToken(), id.getLineNumber(), "h"));
            }
        }
    }

    private void parseGetIntStmt(GetIntStmt value) {
        LValNode lValNode = value.getLVal();
        parseLVal(lValNode);
        Token id = lValNode.getId();
        if (lookup(id) != -1) {
            Symbol symbol = findInSymbolsHashMap(id);
            boolean isConst = symbol.isConst();
            if (isConst) {
                errors.add(new error(id.getToken(), id.getLineNumber(), "h"));
            }
        }
    }

    private void parseLValStmt(LValStmt value) {
        LValNode lValNode = value.getLVal();
        parseLVal(lValNode);
        Token id = lValNode.getId();
//        System.out.println(id.getToken());
        if (lookup(id)!= -1) {
            Symbol symbol = findInSymbolsHashMap(id);
            boolean isConst = symbol.isConst();
            if (isConst) {
                errors.add(new error(id.getToken(), id.getLineNumber(), "h"));
            }
        }
        parseExp(value.getExpr());
    }

    private void parsePrintfStmt(PrintfStmt value) {
        ArrayList<String> formatChars = value.getStringConst().getFormatChars();
        int exprNum = value.getExps().size();
        if (formatChars.size() != exprNum) {
            errors.add(new error("PrintfStmt", value.getPrintLine(), "l"));
        }
        for (int i = 0; i < exprNum; i++) {
            parseExp(value.getExps().get(i));
        }

    }

    private void parseForNode(ForNode value) {
        ForStmt forStmt = value.getForStmt();
        CondNode condNode = value.getCondNode();
        ForStmt forStmt1 = value.getForStmt2();
        if (forStmt != null) {
            parseForStmt(forStmt);
        }
        if (condNode != null) {
            parseCondNode(condNode);
        }
        if (forStmt1 != null) {
            parseForStmt(forStmt1);
        }

        StmtNode stmtNode = value.getS();

        if (stmtNode.getT() == 13) {
            forLoopCount++;
            parseStmt(stmtNode);
            forLoopCount--;
        }
        else {
            parseStmt(stmtNode);
        }

    }

    private void parseCondNode(CondNode condNode) {
        parseLOrExp(condNode.getLOrExpNode());
    }

    private void parseLOrExp(LOrExpNode lOrExpNode) {
        for (LAndExpNode lAndExpNode : lOrExpNode.getLAndExpNodes()) {
            parseLAndExp(lAndExpNode);
        }
    }

    private void parseLAndExp(LAndExpNode lAndExpNode) {
        for (EqExpNode eqExpNode : lAndExpNode.getEqExpNodes()) {
            parseEqExp(eqExpNode);
        }
    }

    private void parseEqExp(EqExpNode eqExpNode) {
        for (RelExpNode relExpNode : eqExpNode.getRelExpNodes()) {
            parseRelExp(relExpNode);
        }
    }

    private void parseRelExp(RelExpNode relExpNode) {
        for (AddExpNode addExpNode : relExpNode.getAddExpNodes()) {
            parseAddExp(addExpNode);
        }
    }

    private void parseForStmt(ForStmt forStmt) {
        parseLVal(forStmt.getlValNode());
        parseExp(forStmt.getExprNode());
        Token id = forStmt.getlValNode().getId();
        if (lookup(id)!= -1) {
            Symbol symbol = findInSymbolsHashMap(id);
            boolean isConst = symbol.isConst();
            if (isConst) {
                errors.add(new error(id.getToken(), id.getLineNumber(), "h"));
            }
        }
    }

    private void parseIfStmt(IfStmtNode value) {
        StmtNode stmtNode = value.getIfStmt();
        parseStmt(stmtNode);
    }

    private void parseIfElseStmt(IfElseStmtNode value) {
        StmtNode stmtNode = value.getIfStmt();
        parseStmt(stmtNode);
        StmtNode stmtNode1 = value.getElseStmt();
        parseStmt(stmtNode1);
    }

    private void parseParam(FuncFParamsNode paramDeclNodes) {
        if (paramDeclNodes != null) {
            for (FuncFParamNode paramDeclNode : paramDeclNodes.getFparams()) {
                Token type = paramDeclNode.getBtype();
                Token id = paramDeclNode.getIdent();
                boolean isArray = paramDeclNode.isArray();
                if (symbolsHashMap.get(scopeId).isDeclared(id)) {
                    errors.add(new error(id.getToken(), id.getLineNumber(), "b"));
                } else {
                    symbolsHashMap.get(scopeId).addSymbol(type, id, false, isArray, false, scopeId);
                }
            }
        }
    }

    private void parseDecl(List<DeclNode> decls) {
        for (DeclNode declNode : decls) {
            if (declNode.getT() == 1) {
                parseConstDecl(declNode.getConstDecl());
            } else if (declNode.getT() == 2) {
                parseVarDecl(declNode.getVarDecl());
            }
        }
    }

    private void parseConstDecl(ConstDeclNode constDecl) {
        Token type = constDecl.getBtype();
        for (ConstDefNode constDefNode : constDecl.getConstDefNodes()) {
            Token id = constDefNode.getIdent();
            boolean isArray = constDefNode.isArray();
            if (symbolsHashMap.get(scopeId).isDeclared(id)) {
                errors.add(new error(id.getToken() , id.getLineNumber(),"b"));
            } else {
                symbolsHashMap.get(scopeId).addSymbol(type, id, true, isArray, false, scopeId);
            }
            if (isArray) {
                parseConstExp(constDefNode.getConstExpNode());
            }
            parseConstInitVal(constDefNode.getConstInitValNode());
        }
    }

    private void parseConstExp(ConstExpNode constExpNode) {
        parseAddExp(constExpNode.getExprNode());
    }



    private void parseConstInitVal(ConstInitValNode constInitValNode) {
        int t = constInitValNode.getT();
        if (t == 1) {
            parseConstExp(constInitValNode.getConstExpNodes().get(0));
        } else if (t == 2) {
            for (int i = 0; i < constInitValNode.getConstExpNodes().size(); i++) {
                parseConstExp(constInitValNode.getConstExpNodes().get(i));
            }
        } else {
            parseStringConst(constInitValNode.getStringConst());
        }

    }

    private void parseStringConst(StringConst stringConst) {
    }

    private void parseAddExp(AddExpNode exprNode) {
        parseMulExp(exprNode.getMulExpNodes());
    }

    private void parseMulExp(ArrayList<MulExpNode> mulExpNodes) {
        for (MulExpNode mulExpNode : mulExpNodes) {
            parseUnaryExp(mulExpNode.getUnaryExpNodes());;
        }
    }

    private void parseUnaryExp(ArrayList<UnaryExpNode> unaryExpNodes) {
        for (UnaryExpNode unaryExpNode : unaryExpNodes) {
            int t = unaryExpNode.getT();
            if (t == 1) {
                parsePrimaryExp(unaryExpNode.getPrimaryExp());
            } else if (t == 2) {
                parseIdent(unaryExpNode.getIdent());
                parseFuncR(unaryExpNode.getFuncRNodes(), unaryExpNode.getIdent());
            } else if (t == 3) {
                parseUnaryExp(unaryExpNode.getUnaryExpNode());
            }

        }
    }

    private void parseUnaryExp(UnaryExpNode unaryExpNode) {
        int t = unaryExpNode.getT();
        if (t == 1) {
            parsePrimaryExp(unaryExpNode.getPrimaryExp());
        } else if (t == 2) {
            parseIdent(unaryExpNode.getIdent());
            parseFuncR(unaryExpNode.getFuncRNodes(), unaryExpNode.getIdent());
        } else if (t == 3) {
            parseUnaryExp(unaryExpNode.getUnaryExpNode());
        }
    }

    private boolean parseFuncR(FuncRNode funcRNodes, Token ident) {
        for (FuncDefNode funcDefNode : compUnitNode.getFuncDefs()) {
            if (funcDefNode.getFunctionName().getToken().equals(ident.getToken())) {
                if (funcDefNode.getFpParams() == null) {
                    if (!funcRNodes.getExprs().isEmpty()) {
                        errors.add(new error(ident.getToken(), ident.getLineNumber(), "d"));
                        return false;
                    }
                } else {
                    int funcFparaNum = funcDefNode.getFpParams().getFparams().size();
                    if (funcFparaNum!= funcRNodes.getExprs().size()) {
                        errors.add(new error(ident.getToken(), ident.getLineNumber(), "d"));
                        return false;
                    }
                    else if (!isMatchAll(funcDefNode.fpParams.getFparams(), funcRNodes.getExprs())) {
                        errors.add(new error(ident.getToken(), ident.getLineNumber(), "e"));
                        return false;
                    }
                }
                break;
            }
        }
        return true;
    }

    private boolean isMatchAll(ArrayList<FuncFParamNode> funcFParamNodes, ArrayList<ExprNode> exprNodes) {
        for (int i = 0; i < funcFParamNodes.size(); i++) {
            ExprNode exprNode = exprNodes.get(i);
            boolean isMatch = isMatch(funcFParamNodes.get(i), exprNode);
//            System.out.println(isMatch);
            if (!isMatch) {
                return false;
            }

        }
        return true;
    }

    private boolean isMatch(FuncFParamNode funcFParamNode, ExprNode exprNode) {
        Token type = funcFParamNode.getBtype();
        boolean isArray = funcFParamNode.isArray();
        String typeExp = typeExpr(exprNode);
//        System.out.println(type.getToken() + "--------" + typeExp);
        if (type.getToken().equals("int")) {
            if (isArray) {
                return typeExp.equals("intArray");
            } else {
                return typeExp.equals("int");
            }
        } else if (type.getToken().equals("char")) {
            if (isArray) {
                return typeExp.equals("charArray");
            } else {
                return typeExp.equals("int");
            }
        } else {
            return false;
        }
    }

    private String typeExpr(ExprNode exprNode) {
        String typeExp = null;
        ArrayList<MulExpNode> mulExpNode = exprNode.getAddExpNode().getMulExpNodes();
        if (mulExpNode.size() > 1) {
            typeExp = "int";
        }
        else {
            MulExpNode mulExpNode1 = mulExpNode.get(0);
            ArrayList<UnaryExpNode> unaryExpNodes = mulExpNode1.getUnaryExpNodes();
            if (unaryExpNodes.size() > 1) {
                typeExp = "int";
            } else {
                UnaryExpNode unaryExpNode = unaryExpNodes.get(0);
                int t1 = unaryExpNode.getT();
                if (t1 == 1) {
                    PrimaryExp primaryExp = unaryExpNode.getPrimaryExp();
                    if (primaryExp.getT() == 3) {
                        typeExp = "int";
                    } else if (primaryExp.getT() == 4) {
                        typeExp = "int";
                    } else if (primaryExp.getT() == 2) {
                        LValNode lValNode = primaryExp.getlVal();
                        Symbol symbol = findInSymbolsHashMap(lValNode.getId());
                        if (lValNode.getExpr() != null) {
                            typeExp = "int";
                        } else {
                            SymType symType = symbol.getType();
                            if (symType.equals(SymType.ConstCharArray) || symType.equals(SymType.CharArray)) {
                                typeExp = "charArray";
                            } else if (symType.equals(SymType.ConstIntArray) || symType.equals(SymType.IntArray)) {
                                typeExp = "intArray";
                            } else {
                                typeExp = "int";
                            }
                        }
                    } else {
                        typeExp = typeExpr(primaryExp.getExpr());
                    }
                } else if (t1 == 2) {
                   Symbol symbol = findInSymbolsHashMap(unaryExpNode.getIdent());
                   boolean flag = parseFuncR(unaryExpNode.getFuncRNodes(), unaryExpNode.getIdent());
//                   System.out.println(symbol.ident.getToken() + " ================" + flag);

                   if (symbol.getType() == SymType.VoidFunc) {
                       typeExp = "void";
                   } else {
                       typeExp = "int";
                   }

                } else {
                    typeExp = "int";
                }
            }
        }
        return typeExp;
    }

    private void parseIdent(Token ident) {
        if (lookup(ident) == -1) {
            errors.add(new error(ident.getToken(), ident.getLineNumber(), "c"));
        }
    }

    private void parsePrimaryExp(PrimaryExp primaryExp) {
        int t = primaryExp.getT();
        if (t == 1) {
            parseExp(primaryExp.getExpr());
        } else if (t == 2) {
            parseLVal(primaryExp.getlVal());
        } else if (t == 3) {
            parseNumber(primaryExp.getNumber());
        } else if (t == 4) {
            parseCharacter(primaryExp.getCharacter());
        }

    }

    private void parseCharacter(CharacterNode character) {
    }

    private void parseNumber(NumberNode number) {
    }

    private void parseLVal(LValNode lValNode) {
        parseIdent(lValNode.getId());
        if (lValNode.getExpr() != null) {
            parseExp(lValNode.getExpr());
        }
    }

    private void parseExp(ExprNode expr) {
        parseAddExp(expr.getAddExpNode());
    }

    private void parseVarDecl(VarDeclNode varDeclNode) {
        Token type = varDeclNode.getTypeString();
        for (VarDefNode varDefNode : varDeclNode.getVarDefNodes()) {
            Token id = varDefNode.getIdent();
            boolean isArray = varDefNode.isArray();
            if (symbolsHashMap.get(scopeId).isDeclared(id)) {
                errors.add(new error(id.getToken(), id.getLineNumber(), "b"));
            } else {
                symbolsHashMap.get(scopeId).addSymbol(type, id, false, isArray, false, scopeId);
            }
            if (isArray) {
                parseConstExp(varDefNode.getConstExpNode());
            }
            if (varDefNode.getInitVal() != null) {
                parseInitVal(varDefNode.getInitVal());
            }
        }
    }

    private void parseInitVal(InitVal initVal) {
        int t = initVal.getT();
        if (t == 1) {
            for (int i = 0; i < initVal.getExps().size(); i++) {
                parseExp(initVal.getExps().get(i));
            }
        } else if(t == 2) {
            parseExp(initVal.getExps().get(0));
        } else if (t == 3) {
            parseStringConst(initVal.getString());
        }

    }

    private Integer lookup(Token token) {
        for (int i = scopeId; i >= 1; i--) {
            if (symbolsHashMap.get(i).isDeclared(token) && stack.contains(i)) {
                return i;
            }
        }
        return -1;
    }

    private Symbol findInSymbolsHashMap(Token token) {
        int scope = lookup(token);
        Symbols symbols = symbolsHashMap.get(scope);
        if (symbols.isDeclared(token)) {
            return symbols.getSymbol(token);
        }
        return null;
    }

    private void printError() {
        BufferedWriter bw = io.getErrorWriter();
        for (error error : errors) {
//            System.out.print(error.toString());
            try {
                bw.write(error.toString());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void printParser() {
        for (int i = 1; i <= symbolsHashMap.size(); i++) {
            symbolsHashMap.get(i).printAllSymbols();
        }
    }

}
