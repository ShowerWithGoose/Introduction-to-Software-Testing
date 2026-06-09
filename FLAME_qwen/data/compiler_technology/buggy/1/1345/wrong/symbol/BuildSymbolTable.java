package symbol;

import parse.*;

import java.util.ArrayList;

public class BuildSymbolTable {
    private CompUnit compUnit;
    private WrongList wrongList;
    private ArrayList<SymbolTable> printlist;
    private String iflag = null;
    private String oflag = null;
    private int isflag = 0;
    private int flag1 = 0;
    private int flag2 = 0;
    public BuildSymbolTable(CompUnit compUnit, WrongList wrongList, ArrayList<SymbolTable> printlist){
        this.compUnit = compUnit;
        this.wrongList = wrongList;
        this.printlist = printlist;

    }

    public void dealCompUnit(){
        SymbolTable symbolTable = buildNewSymbolTable(0);
        ArrayList<Decl> decls = compUnit.getDecls();
        if(decls != null && decls.size() != 0){
            for(int i = 0;i<decls.size();i++){
                dealDecl(decls.get(i),symbolTable);
            }
        }
        ArrayList<FuncDef> funcDefs = compUnit.getFuncDefs();
        if(funcDefs != null && funcDefs.size() != 0){
            for(int i = 0;i<funcDefs.size();i++){
                dealFuncDef(funcDefs.get(i),symbolTable);
            }
        }
        dealMainFuncDef(compUnit.getMainFuncDef(),symbolTable);
    }

    public void dealDecl(Decl decl,SymbolTable symbolTable){
        DeclEle declEle = decl.getDeclEle();
        if(declEle instanceof ConstDecl){
            flag1 = 1;
            dealConstDecl(((ConstDecl) declEle),symbolTable);
        }
        else {
            flag1 = 2;
            dealVarDecl((VarDecl) declEle,symbolTable);
        }
    }

    public void dealConstDecl(ConstDecl constDecl,SymbolTable symbolTable){
        if(constDecl.getBtype().getToken().getType().equals("INTTK")){
            flag2 = 1;
        }
        else {
            flag2 = 2;
        }
        dealConstDef(constDecl.getFirstword(),symbolTable);
        ArrayList<ConstDef> constDefs = constDecl.getConstDefs();
        if(constDefs != null&& constDefs.size() != 0){
            for(int i = 0;i<constDefs.size();i++){
                dealConstDef(constDefs.get(i),symbolTable);
            }
        }
    }

    public void dealConstDef(ConstDef constDef,SymbolTable symbolTable){
        String ident = constDef.getIdent().getToken().getContent();
        if(constDef.getLeftBraces() != null && constDef.getLeftBraces().size() != 0){
            flag1 = 5;
        }
        Symbol symbol = new Symbol(constDef.getIdent().getToken().getLinenumber(),ident,flag1,flag2);
        if(symbolTable.checkBTypeError(symbol)){
            wrongList.addWrong(new WrongType(constDef.getIdent().getToken().getLinenumber(),"b"));
        }
        symbolTable.addSymbol(symbol);
    }

    public void dealVarDecl(VarDecl varDecl,SymbolTable symbolTable){
        if(varDecl.getBtype().getToken().getType().equals("INTTK")){
            flag2 = 1;
        }
        else {
            flag2 = 2;
        }
        dealVarDef(varDecl.getFirstword(),symbolTable);
        ArrayList<VarDef> varDefs = varDecl.getVarDefs();
        if(varDefs != null&& varDefs.size() != 0){
            for(int i = 0;i<varDefs.size();i++){
                dealVarDef(varDefs.get(i),symbolTable);
            }
        }
    }

    public void dealVarDef(VarDef varDef,SymbolTable symbolTable){
        String ident = varDef.getIdent().getToken().getContent();
        if(varDef.getLeftBraces() != null && varDef.getLeftBraces().size() != 0){
            flag1 = 4;
        }
        Symbol symbol = new Symbol(varDef.getIdent().getToken().getLinenumber(),ident,flag1,flag2);
        if(symbolTable.checkBTypeError(symbol)){
            wrongList.addWrong(new WrongType(varDef.getIdent().getToken().getLinenumber(),"b"));
        }
        symbolTable.addSymbol(symbol);
    }

    public void dealFuncDef(FuncDef funcDef,SymbolTable symbolTable){
        flag1 = 3;
        if(funcDef.getFuncType().getType().getType().equals("INTTK")){
            flag2 = 1;
        }
        else if(funcDef.getFuncType().getType().getType().equals("CHARTK")){
            flag2 = 2;
        }
        else {
            flag2 = 3;
        }
        String ident = funcDef.getIdent().getToken().getContent();
        Symbol symbol = new Symbol(funcDef.getIdent().getToken().getLinenumber(),ident,flag1,flag2);
        if(symbolTable.checkBTypeError(symbol)){
            wrongList.addWrong(new WrongType(funcDef.getIdent().getToken().getLinenumber(),"b"));
        }
        if(funcDef.getFuncFParams() != null){
            ArrayList<FuncFParam> funcFParams = funcDef.getFuncFParams().getFuncFParams();
            if(funcFParams != null && funcFParams.size() != 0){
                for(int i = 0;i< funcFParams.size();i++){
                    FuncFParam funcFParam =funcFParams.get(i);
                    flag1 = 2;
                    if(funcFParam.getBtype().getToken().getType().equals("INTTK")){
                        flag2 = 1;
                    }
                    else{
                        flag2 = 2;
                    }
                    if(funcFParam.getLeftBraces() != null &&funcFParam.getLeftBraces().size() != 0){
                        flag1 = 4;
                    }
                    Symbol para = new Symbol(funcFParam.getIdent().getToken().getLinenumber(),funcFParam.getName(),flag1,flag2);
                    symbol.addParas(para);
                }
            }
        }
        symbolTable.addSymbol(symbol);
        dealBlock(funcDef.getBlock(),symbolTable);
    }

    public void dealBlock(Block block,SymbolTable symbolTable){
        SymbolTable now = buildNewSymbolTable(symbolTable.getCycleDepth()+1);
        symbolTable.getChild().add(now);
        now.setParent(symbolTable);
        ArrayList<Symbol> funcpara = symbolTable.isFunc();
        if(funcpara != null){
            for(int i = 0;i< funcpara.size();i++){
                Symbol symbol = funcpara.get(i);
                if(symbolTable.checkBTypeError(symbol)){
                    wrongList.addWrong(new WrongType(symbol.getLineNum(),"b"));
                }
                now.addSymbol(symbol);
            }
        }
        for(int i = 0;i<block.getBlockItems().size();i++){
            BlockItemEle blockItemEle = block.getBlockItems().get(i).getBlockItemEle();
            if(blockItemEle instanceof Decl){
                dealDecl((Decl) blockItemEle,now);
            }
            else {
                dealStmt((Stmt) blockItemEle,now);
            }
        }

    }

    public void dealStmt(Stmt stmt,SymbolTable symbolTable){
        StmtEle stmtEle = stmt.getStmtEle();
        if(stmtEle instanceof StmtCond){
            dealStmt(((StmtCond) stmtEle).getIfStmt(),symbolTable);
            dealStmt(((StmtCond) stmtEle).getElseStmt(),symbolTable);
        }
        else if(stmtEle instanceof StmtFor){
            
        }
    }

    public void dealMainFuncDef(MainFuncDef mainFuncDef,SymbolTable symbolTable){

    }



    public CompUnit getCompUnit() {
        return compUnit;
    }

    public void setCompUnit(CompUnit compUnit) {
        this.compUnit = compUnit;
    }

    public WrongList getWrongList() {
        return wrongList;
    }

    public void setWrongList(WrongList wrongList) {
        this.wrongList = wrongList;
    }

    public ArrayList<SymbolTable> getPrintlist() {
        return printlist;
    }

    public void setPrintlist(ArrayList<SymbolTable> printlist) {
        this.printlist = printlist;
    }

    public SymbolTable buildNewSymbolTable(int i){
        SymbolTable a = new SymbolTable(i);
        this.printlist.add(a);
        return a;
    }
}


