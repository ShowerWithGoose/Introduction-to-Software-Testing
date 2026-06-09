package frontend;

import frontend.SymbolPackage.ArraySymbol;
import frontend.SymbolPackage.FuncParam;
import frontend.SymbolPackage.FuncSymbol;
import frontend.SymbolPackage.Symbol;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

public class Visitor {
    private HashMap<Integer, SymbolTable> SymbolTables;//符号表编号，符号表
    private Stack<Integer> stack;//栈，用于存放符号表的编号
    private int now_id;//当前所在符号表的编号
    private int new_id;//最新符号表的编号
    private AbTree mainTree;
    private ArrayList<Error> errors;//存储错误类型
    private int loop;//用于处理循环体之外的continue和break

    public Visitor(AbTree mainTree, ArrayList<Error> errors) {
        this.SymbolTables = new HashMap<>();
        this.stack = new Stack<>();
        this.mainTree = mainTree;
        this.errors = errors;
        this.loop = 0;
        this.now_id = 0;
        this.new_id = 0;
    }

    public void visitCompUnit() {
        this.new_id = 1;
        this.now_id = 1;
        stack.push(new_id);
        SymbolTable symbolTable = new SymbolTable(1, 0);
        this.SymbolTables.put(new_id, symbolTable);

        for (AbTree node : this.mainTree.getNodes()) {
            if (node.getVal().getValue().equals("<Decl>")) {
                visitDecl(node);
            } else if (node.getVal().getValue().equals("<FuncDef>")) {
                visitFuncDef(node);
            } else {
                visitMainFuncDef(node);
            }
        }
    }

    //Decl → ConstDecl | VarDecl
    public void visitDecl(AbTree Decl) {
        AbTree node = Decl.getNodes().get(0);
        if (node.getVal().getValue().equals("<ConstDecl>")) {
            visitConstDecl(node);
        } else {
            visitVarDecl(node);
        }
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block 可能出现b g错误
    public void visitFuncDef(AbTree FuncDef) {
        ArrayList<AbTree> nodes = FuncDef.getNodes();
        String returnType = nodes.get(0).getNodes().get(0).getVal().getValue();
        String name = nodes.get(1).getVal().getValue();
        FuncSymbol funcSymbol = new FuncSymbol(this.now_id, this.new_id + 1, returnType);
        funcSymbol.setName(name);
        if (nodes.get(3).getVal().getValue().equals("<FuncFParams>")) {
            visitFuncFParams(nodes.get(3), funcSymbol);
        }
        if (this.SymbolTables.get(this.now_id).isContainIdent(name)) {
            this.errors.add(new Error(nodes.get(1).getVal().getLine_num(), ErrorType.b));
        }
        this.SymbolTables.get(this.now_id).addSymbol(funcSymbol);
        int isReturn;
        if (returnType.equals("void")) {
            isReturn = 1;
        } else {
            isReturn = 2;
        }
        visitBlock(nodes.get(nodes.size() - 1), isReturn);
    }

    //MainFuncDef → 'int' 'main' '(' ')' Block
    public void visitMainFuncDef(AbTree MainFuncDef) {
        ArrayList<AbTree> nodes = MainFuncDef.getNodes();
        visitBlock(nodes.get(nodes.size() - 1), 2);
    }

    //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    public void visitConstDecl(AbTree ConstDecl) {
        ArrayList<AbTree> nodes = ConstDecl.getNodes();
        String btype = nodes.get(1).getNodes().get(0).getVal().getValue();
        for (int i = 2 ; i < nodes.size(); i += 2) {
            ArraySymbol arraySymbol = new ArraySymbol(btype,true);
            visitConstDef(nodes.get(i), arraySymbol);
        }

    }

    //BType VarDef { ',' VarDef } ';'
    public void visitVarDecl(AbTree VarDecl) {
        ArrayList<AbTree> nodes = VarDecl.getNodes();
        String btype = nodes.get(0).getNodes().get(0).getVal().getValue();
        for (int i = 1; i < nodes.size(); i += 2) {
            ArraySymbol arraySymbol = new ArraySymbol(btype, false);
            visitVarDef(nodes.get(i), arraySymbol);
        }
    }

    //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public void visitConstDef(AbTree ConstDef , ArraySymbol arraySymbol) {
        ArrayList<AbTree> nodes = ConstDef.getNodes();
        String name = nodes.get(0).getVal().getValue();
        int dimension = 0;
        if (nodes.get(1).getVal().getValue().equals("[")) {
            dimension = 1;
            visitConstExp(nodes.get(2));
        }
        arraySymbol.setName(name);
        arraySymbol.setDimension(dimension);
        if (this.SymbolTables.get(this.now_id).isContainIdent(name)) {
            this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.b));
        }
        this.SymbolTables.get(this.now_id).addSymbol(arraySymbol);
        visitConstInitVal(nodes.get(nodes.size() - 1));
    }

    // VarDef -> Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public void visitVarDef(AbTree VarDef, ArraySymbol arraySymbol) {
        ArrayList<AbTree> nodes = VarDef.getNodes();
        String name = nodes.get(0).getVal().getValue();
        int dimension = 0;
        if (nodes.size() > 1
                && nodes.get(1).getVal().getValue().equals("[")) {
            dimension = 1;
            visitConstExp(nodes.get(2));
        }
        arraySymbol.setName(name);
        arraySymbol.setDimension(dimension);
        if (this.SymbolTables.get(this.now_id).isContainIdent(name)) {
            this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.b));
        }
        this.SymbolTables.get(this.now_id).addSymbol(arraySymbol);
        if (nodes.size() > 1 && nodes.get(nodes.size() - 2).getVal().getValue().equals("=")) {
            visitInitVal(nodes.get(nodes.size() - 1));
        }
    }

    //FuncFParams → FuncFParam { ',' FuncFParam }
    public void visitFuncFParams(AbTree FuncFParams, FuncSymbol funcSymbol) {
        ArrayList<AbTree> nodes = FuncFParams.getNodes();
        if (!this.SymbolTables.containsKey(funcSymbol.getNext_tableId())) {
            this.SymbolTables.put(funcSymbol.getNext_tableId(), new SymbolTable(funcSymbol.getNext_tableId(), funcSymbol.getTableId()));
        }
        SymbolTable symbolTable = this.SymbolTables.get(funcSymbol.getNext_tableId());
        for (int i = 0; i < nodes.size(); i += 2) {
            FuncParam funcParam = visitFuncFParam(nodes.get(i));
            ArraySymbol arraySymbol = new ArraySymbol(funcParam.getBtype(), false);
            arraySymbol.setDimension(funcParam.getDimension());
            arraySymbol.setName(funcParam.getName());
            funcSymbol.addParam(funcParam);
            if (symbolTable.isContainIdent(funcParam.getName())) {
                this.errors.add(new Error(nodes.get(i).getVal().getLine_num(), ErrorType.b));
            }
            symbolTable.addSymbol(arraySymbol);
        }
    }

    // FuncFParam → BType Ident ['[' ']']
    public FuncParam visitFuncFParam(AbTree FuncParam) {
        ArrayList<AbTree> nodes = FuncParam.getNodes();
        String btype = nodes.get(0).getNodes().get(0).getVal().getValue();
        String name = nodes.get(1).getVal().getValue();
        int dimension = 0;
        if (nodes.size() > 2) {
            dimension = 1;
        }
        return new FuncParam(btype, name, dimension);
    }

    //Block → '{' { BlockItem } '}'
    public void visitBlock(AbTree Block, int isReturn) {//isReturn 0->非函数所属Block 1-voidFunc 2->int/charFunc
        ArrayList<AbTree> nodes = Block.getNodes();
        int fatherId = this.now_id;
        this.new_id++;
        this.stack.push(this.new_id);
        this.now_id = this.stack.peek();
        if (!this.SymbolTables.containsKey(now_id)) {
            this.SymbolTables.put(this.now_id, new SymbolTable(this.now_id, fatherId));
        }
        if (nodes.size() == 2) {//判断Block是否为空语句
            if (isReturn == 2) {
                this.errors.add(new Error(nodes.get(nodes.size() - 1).getVal().getLine_num(), ErrorType.g));
            }
        } else {
            for (int i = 1 ; i < nodes.size() - 1; i++) {
                if (isReturn == 0 || isReturn == 1) {
                    visitBlockItem(nodes.get(i), isReturn);
                } else {
                    if (i == nodes.size() - 2) {
                        if (!visitBlockItem(nodes.get(i), isReturn)) {
                            this.errors.add(new Error(nodes.get(nodes.size() - 1).getVal().getLine_num(), ErrorType.g));
                        }
                    } else {
                        visitBlockItem(nodes.get(i), 0);
                    }
                }
            }
        }
        this.stack.pop();
        this.now_id = this.stack.peek();
    }

    // BlockItem → Decl | Stmt
    public boolean visitBlockItem(AbTree BlockItem, int isReturn) {//isReturn 0->不在乎是否为return 1->不能为return 2->为return
        AbTree node = BlockItem.getNodes().get(0);
        if (node.getVal().getValue().equals("<Decl>")) {
            visitDecl(node);
            return false;
        } else {
            return visitStmt(node, isReturn);
        }
    }

    //Stmt → LVal '=' Exp ';' // h
    //| [Exp] ';'
    //| Block
    //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
    //| 'break' ';' | 'continue' ';' // m
    //| 'return' [Exp] ';' // f
    //| LVal '=' 'getint''('')'';' // h
    //| LVal '=' 'getchar''('')'';' // h
    //| 'printf''('StringConst {','Exp}')'';' // l
    public boolean visitStmt(AbTree Stmt, int isReturn) {//isReturn 0->不在乎是否为return 1->不能为return 2->为return 返回值为Block中最后一句是否为return
        ArrayList<AbTree> nodes = Stmt.getNodes();
        if (isReturn == 2) {
            return nodes.get(0).getVal().getValue().equals("return");
        } else {
            if (nodes.get(0).getVal().getValue().equals("<LVal>")) {
                if (visitLVal(nodes.get(0))) {
                    this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.h));
                }
                if (nodes.get(2).getVal().getValue().equals("<Exp>")) {
                    visitExp(nodes.get(2));
                }
            } else if (nodes.get(0).getVal().getValue().equals("<Exp>")) {
                visitExp(nodes.get(0));
            } else if (nodes.get(0).getVal().getValue().equals("<Block>")) {
                visitBlock(nodes.get(0), isReturn);
            } else if (nodes.get(0).getVal().getValue().equals("if")) {
                visitCond(nodes.get(2));
                visitStmt(nodes.get(4), isReturn);
                if (nodes.size() > 5) {
                    visitStmt(nodes.get(6), isReturn);
                }
            } else if (nodes.get(0).getVal().getValue().equals("for")) {
                int first_comma = 0;//记录第一个分号的位置
                int second_comma = 0;//记录第二个分号的位置
                for (int i = 0; i < nodes.size(); i++) {
                    if (nodes.get(i).getVal().getValue().equals(";")) {
                        if (first_comma == 0) {
                            first_comma = i;
                        } else {
                            second_comma = i;
                            break;
                        }
                    }
                }

                if (nodes.get(first_comma - 1).getVal().getValue().equals("<ForStmt>")) {
                    visitForStmt(nodes.get(first_comma - 1));
                }
                if (nodes.get(first_comma + 1).getVal().getValue().equals("<Cond>")) {
                    visitCond(nodes.get(first_comma + 1));
                }
                if (nodes.get(second_comma + 1).getVal().getValue().equals("<ForStmt>")) {
                    visitForStmt(nodes.get(second_comma + 1));
                }
                this.loop++;
                visitStmt(nodes.get(nodes.size() - 1), isReturn);
                this.loop--;
            } else if (nodes.get(0).getVal().getValue().equals("break")) {
                if (this.loop == 0) {
                    this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.m));
                }
            } else if (nodes.get(0).getVal().getValue().equals("continue")) {
                if (this.loop == 0) {
                    this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.m));
                }
            } else if (nodes.get(0).getVal().getValue().equals("return")) {
                if (isReturn == 1 && nodes.size() > 2) {
                    this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.f));
                }
                if (nodes.size() > 2) {
                    visitExp(nodes.get(1));
                }
            } else if (nodes.get(0).getVal().getValue().equals("printf")) {//'printf''('StringConst {','Exp}')'';' // l
                String stringconst = nodes.get(2).getVal().getValue();
                int count = 0;//记录exp数量
                for (int i = 3; i < nodes.size(); i += 2) {
                    if (nodes.get(i).getVal().getValue().equals(",")) {
                        count++;
                        visitExp(nodes.get(i + 1));
                    } else {
                        break;
                    }
                }
                if (count != findVarFromString(stringconst)) {
                    this.errors.add(new Error(nodes.get(2).getVal().getLine_num(), ErrorType.l));
                }
            }
            return false;
        }
        
    }

    //ForStmt → LVal '=' Exp
    public void visitForStmt(AbTree ForStmt) {
        ArrayList<AbTree> nodes = ForStmt.getNodes();
        if (visitLVal(nodes.get(0))) {
            this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.h));
        }
        visitExp(nodes.get(2));
    }

    //Cond → LOrExp
    public void visitCond(AbTree Cond) {
        AbTree node = Cond.getNodes().get(0);
        visitLOrExp(node);
    }

    //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public void visitConstInitVal(AbTree ConstInitVal) {
        ArrayList<AbTree> nodes = ConstInitVal.getNodes();
        if (nodes.get(0).getVal().getValue().equals("<ConstExp>")) {
            visitConstExp(nodes.get(0));
        } else if (nodes.get(0).getVal().getValue().equals("{")) {
            if (nodes.size() > 2) {
                for (int i = 1; i < nodes.size() - 1; i += 2) {
                    visitConstExp(nodes.get(i));
                }
            }
        }
    }

    //InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public void visitInitVal(AbTree InitVal) {
        ArrayList<AbTree> nodes = InitVal.getNodes();
        if (nodes.get(0).getVal().getValue().equals("<Exp>")) {
            visitExp(nodes.get(0));
        } else if (nodes.get(0).getVal().getValue().equals("{")) {
            if (nodes.size() > 2) {
                for (int i = 1; i < nodes.size() - 1; i += 2) {
                    visitExp(nodes.get(i));
                }
            }
        }
    }

    // LOrExp → LAndExp | LOrExp '||' LAndExp
    public void visitLOrExp(AbTree LOrExp) {
        ArrayList<AbTree> nodes = LOrExp.getNodes();
        if (nodes.size() > 1) {
            visitLOrExp(nodes.get(0));
            visitLAndExp(nodes.get(2));
        } else {
            visitLAndExp(nodes.get(0));
        }
    }

    //LAndExp → EqExp | LAndExp '&&' EqExp
    public void visitLAndExp(AbTree LAndExp) {
        ArrayList<AbTree> nodes = LAndExp.getNodes();
        if (nodes.size() > 1) {
            visitLAndExp(nodes.get(0));
            visitEqExp(nodes.get(2));
        } else {
            visitEqExp(nodes.get(0));
        }
    }

    //EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public void visitEqExp(AbTree EqExp) {
        ArrayList<AbTree> nodes = EqExp.getNodes();
        if (nodes.size() > 1) {
            visitEqExp(nodes.get(0));
            visitRelExp(nodes.get(2));
        } else {
            visitRelExp(nodes.get(0));
        }
    }

    //RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public void visitRelExp(AbTree RelExp) {
        ArrayList<AbTree> nodes = RelExp.getNodes();
        if (nodes.size() > 1) {
            visitRelExp(nodes.get(0));
            visitAddExp(nodes.get(2));
        } else {
            visitAddExp(nodes.get(0));
        }
    }

    // ConstExp → AddExp
    public void visitConstExp(AbTree ConstExp) {
        visitAddExp(ConstExp.getNodes().get(0));
    }

    // Exp → AddExp
    public void visitExp(AbTree Exp) {
        visitAddExp(Exp.getNodes().get(0));
    }

    //AddExp → MulExp | AddExp ('+' | '−') MulExp
    public void visitAddExp(AbTree AddExp) {
        ArrayList<AbTree> nodes = AddExp.getNodes();
        if (nodes.size() > 1) {
            visitAddExp(nodes.get(0));
            visitMulExp(nodes.get(2));
        } else {
            visitMulExp(nodes.get(0));
        }
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public void visitMulExp(AbTree MulExp) {
        ArrayList<AbTree> nodes = MulExp.getNodes();
        if (nodes.size() > 1) {
            visitMulExp(nodes.get(0));
            visitUnaryExp(nodes.get(2));
        } else {
            visitUnaryExp(nodes.get(0));
        }
    }

    //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public void visitUnaryExp(AbTree UnaryExp) {
        ArrayList<AbTree> nodes = UnaryExp.getNodes();
        if (nodes.get(0).getVal().getValue().equals("<PrimaryExp>")) {
            visitPrimaryExp(nodes.get(0));
        } else if (nodes.get(0).getVal().getValue().equals("<UnaryOp>")) {
            visitUnaryExp(nodes.get(1));
        } else {
            String name = nodes.get(0).getVal().getValue();
            if (!IdentIsDefined(name, this.now_id)) {
                this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.c));
            } else {
                FuncSymbol funcSymbol = (FuncSymbol) getIndentFromTables(name, this.now_id);
                //todo 解决d e 错误
                if (nodes.size() > 2 && nodes.get(2).getVal().getValue().equals("<FuncRParams>")) {
                    visitFuncRParams(nodes.get(2), funcSymbol, nodes.get(0).getVal().getLine_num());
                }
            }
        }
    }

    //PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public void visitPrimaryExp(AbTree PrimaryExp) {
        ArrayList<AbTree> nodes = PrimaryExp.getNodes();
        if (nodes.get(0).getVal().getValue().equals("<LVal>")) {
            visitLVal(nodes.get(0));
        } else if (nodes.get(0).getVal().getValue().equals("(")) {
            visitExp(nodes.get(1));
        }
    }

    //LVal → Ident ['[' Exp ']'] // c
    public boolean visitLVal(AbTree LVal) {//返回值判断LVal是否为常量
        ArrayList<AbTree> nodes = LVal.getNodes();
        String name = nodes.get(0).getVal().getValue();
        if (!IdentIsDefined(name, this.now_id)) {
            this.errors.add(new Error(nodes.get(0).getVal().getLine_num(), ErrorType.c));
        }
        if (nodes.size() > 1) {
            visitExp(nodes.get(2));
        }
        return IdentIsConst(name, this.now_id);
    }

    //FuncRParams → Exp { ',' Exp }
    public void visitFuncRParams(AbTree FuncRParams, FuncSymbol funcSymbol, int identLine) {
        ArrayList<AbTree> rParams = FuncRParams.getNodes();
        int rcount = 0;//实参的数量
        for (int i = 0; i < rParams.size() ; i += 2) {
            rcount++;
        }
        if (rcount != funcSymbol.getFuncParams().size()) {
            this.errors.add(new Error(identLine, ErrorType.d));
        } else {
            for (int i = 0, j = 0; i < rParams.size() && j < funcSymbol.getFuncParams().size(); i += 2, j++) {
                visitExp(rParams.get(i));
                if (!isMatch(rParams.get(i), funcSymbol.getFuncParams().get(j))) {
                    this.errors.add(new Error(identLine, ErrorType.e));
                    break;
                }
            }
        }
    }

    public boolean isMatch(AbTree rParam, FuncParam fParam) {
        ArrayList<AbTree> nodes = rParam.getNodes();
        for (AbTree rparam : nodes) {
            if (rparam.getVal().getValue().equals("<UnaryExp>") && rparam.getNodes().size() > 2) {
                if (fParam.getDimension() == 1) {
                    return false;
                } else {
                    FuncSymbol funcSymbol = (FuncSymbol) getIndentFromTables(rparam.getNodes().get(0).getVal().getValue(), this.now_id);
                    return !funcSymbol.getReturnFuncType().equals("void");
                }
            } else if (rparam.getVal().getValue().equals("<LVal>")) {//LVal → Ident ['[' Exp ']']
                ArraySymbol arraySymbol = (ArraySymbol) getIndentFromTables(rparam.getNodes().get(0).getVal().getValue(), this.now_id);
                String btype = fParam.getBtype();;
                int dimension = fParam.getDimension();
                if (rparam.getNodes().size() > 1) {
                    return dimension == 0;
                } else {
                    if (dimension != arraySymbol.getDimension()) {
                        return false;
                    } else {
                        if (dimension == 1) {
                            return btype.equals(arraySymbol.getBtype());
                        } else {
                            return true;
                        }
                    }
                }
            } else if (rparam.getVal().getValue().equals("<Number>")) {
                return  fParam.getDimension() == 0;
            } else if (rparam.getVal().getValue().equals("<Character>")) {
                return  fParam.getDimension() == 0;
            } else {
                return isMatch(rparam, fParam);
            }
        }
        return true;//todo
    }

    public boolean IdentIsDefined(String name, int id) {
        SymbolTable symbolTable = this.SymbolTables.get(id);
        ArrayList<Symbol> directory = symbolTable.getDirectory();
        for (Symbol symbol : directory) {
            if (symbol.getName().equals(name)) {
                return true;
            }
        }
        if (symbolTable.getFatherId() == 0) {
            return false;
        } else {
            return IdentIsDefined(name, symbolTable.getFatherId());
        }
    }

    public boolean IdentIsConst(String name, int id) {
        SymbolTable symbolTable = this.SymbolTables.get(id);
        ArrayList<Symbol> directory = symbolTable.getDirectory();
        for (Symbol symbol : directory) {
            if (symbol.getName().equals(name)) {
                return symbol instanceof ArraySymbol && ((ArraySymbol) symbol).isConst();
            }
        }
        if (symbolTable.getFatherId() == 0) {
            return false;
        } else {
            return IdentIsConst(name, symbolTable.getFatherId());
        }
    }

    public Symbol getIndentFromTables(String name, int id) {
        SymbolTable symbolTable = this.SymbolTables.get(id);
        ArrayList<Symbol> directory = symbolTable.getDirectory();
        for (Symbol symbol : directory) {
            if (symbol.getName().equals(name)) {
                return symbol;
            }
        }
        if (symbolTable.getFatherId() == 0) {
            return null;
        } else {
            return getIndentFromTables(name, symbolTable.getFatherId());
        }
    }

    public int findVarFromString(String string) {
        int count = 0;
        int index = 0;
        while ((index = string.indexOf("%d", index)) != -1) {
            count++;
            index += 2;
        }
        index = 0;
        while ((index = string.indexOf("%c", index)) != -1) {
            count++;
            index += 2;
        }
        return count;
    }

    public void Output() {
        String answer = "symbol.txt";
        String error = "error.txt";

        if (errors.isEmpty()) {
            try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(answer))) {
                for (int id : this.SymbolTables.keySet()) {
                    if (!this.SymbolTables.get(id).isEmpty()) {
                        ArrayList<Symbol> directory = this.SymbolTables.get(id).getDirectory();
                        for (Symbol symbol : directory) {
                            String type;
                            if (symbol instanceof ArraySymbol arraySymbol) {
                                if (arraySymbol.getBtype().equals("int")) {
                                    if (arraySymbol.isConst()) {
                                        if (arraySymbol.isArray()) {
                                            type = "ConstIntArray";
                                        } else {
                                            type = "ConstInt";
                                        }
                                    } else {
                                        if (arraySymbol.isArray()) {
                                            type = "IntArray";
                                        } else {
                                            type = "Int";
                                        }
                                    }
                                } else {
                                    if (arraySymbol.isConst()) {
                                        if (arraySymbol.isArray()) {
                                            type = "ConstCharArray";
                                        } else {
                                            type = "ConstChar";
                                        }
                                    } else {
                                        if (arraySymbol.isArray()) {
                                            type = "CharArray";
                                        } else {
                                            type = "Char";
                                        }
                                    }
                                }
                            } else {
                                FuncSymbol funcSymbol = (FuncSymbol) symbol;
                                String returnFuncType = funcSymbol.getReturnFuncType();
                                if (returnFuncType.equals("void")) {
                                    type = "VoidFunc";
                                } else if (returnFuncType.equals("int")) {
                                    type = "IntFunc";
                                } else {
                                    type = "CharFunc";
                                }
                            }
                            bufferedWriter.write(id + " " + symbol.getName() + " " + type);
                            bufferedWriter.newLine();
                        }
                    }
                }
            } catch (IOException e) {
                System.err.println("Can't write " + answer);
            }
        } else {
            try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(error))) {
                TakeErrorsOrdered();
                for (Error item : this.errors) {
                    bufferedWriter.write(item.getRow_line() + " " + item.getErrorType());
                    bufferedWriter.newLine();
                }
            } catch (IOException e) {
                System.err.println("Can't write " + error);
            }
        }
    }

    public void TakeErrorsOrdered() {
        for (int i = 0; i < this.errors.size() - 1; i++) {
            for (int  j = 0 ; j < this.errors.size() - 1 - i; j++) {
                if (this.errors.get(j).getRow_line() > this.errors.get(j + 1).getRow_line()) {
                    Error tmp = this.errors.get(j);
                    this.errors.set(j, this.errors.get(j + 1));
                    this.errors.set(j + 1, tmp);
                }
            }
        }
    }
}
