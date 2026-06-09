package Error;

import Lexer.Token;
import Nonterminal.*;
import Symbol.Symboltable;
import Symbol.Symbol;
import Symbol.FuncParam;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;

/**
 * <p>Project: Compiler - Error
 * <p>Powered by berry On 2024-10-11
 *
 * @author
 * @version 1.0
 */
public class Error {
    public List<Errortype> errors = new ArrayList<>();
    public List<Symboltable> SymboltableList=new ArrayList<>();
    public Map<Integer,Symboltable> SymboltableSave=new HashMap<Integer, Symboltable>();//scope-Symboltable
    public int scope;
    public int loop;
    private static Error error=new Error();
    private Error(){
        System.out.println("单例模式");
    }
    public static Error getError(){
        return error;
    }
    public void outputErrors(BufferedWriter writer) throws IOException {
        errors.sort(Errortype::compareTo);
        for (Errortype error : errors) {
            writer.write(error.toString());
            System.out.print(error);
        }
    }

    //工具类
    public void addSymbolTable(int scope,boolean isFunc, String funcType) {
        SymboltableList.add(new Symboltable(new ArrayList<>(),scope,isFunc,funcType));
    }
    public void removeSymbolTable() {
        SymboltableSave.put(SymboltableList.get(SymboltableList.size() - 1).scope,SymboltableList.get(SymboltableList.size() - 1));
        SymboltableList.remove(SymboltableList.size() - 1);
    }
    public void putSymbol(String name,Symbol symbol){//当前层添加Symbol
        SymboltableList.get(SymboltableList.size()-1).symbolMap.add(symbol);
    }
    public Symbol symbolMapContains(List<Symbol> list,String name){
        for(Symbol s:list){
            if(s.name.equals(name)){
                return s;
            }
        }
        return null;
    }
    public Symbol getSymbol(String name){//所有层获取name对应的Symbol实例，没有返回null
        for(int i=SymboltableList.size()-1;i>=0;i--){
            if(symbolMapContains(SymboltableList.get(i).symbolMap,name)!=null){
                return symbolMapContains(SymboltableList.get(i).symbolMap,name);
            }
        }
        return null;
    }
    public boolean containsNow(String name){//符号是否在本层符号表内
        return symbolMapContains(SymboltableList.get(SymboltableList.size()-1).symbolMap,name)!=null;
    }
    private boolean containsAll(String name) {//符号是否在所有层中
        for (int i = SymboltableList.size() - 1; i >= 0; i--) {
            if (symbolMapContains(SymboltableList.get(i).symbolMap,name)!=null) {
                return true;
            }
        }
        return false;
    }
    public boolean blockWithoutReturn(Block block){
        return block.blockItem.size()==0||
                block.blockItem.get(block.blockItem.size()-1).stmt==null||
                block.blockItem.get(block.blockItem.size()-1).stmt.type!=8;
    }
    public boolean isInFunc(){//当前是否在函数层次内
        for(int i=SymboltableList.size()-1;i>=0;i--){
            if(SymboltableList.get(i).isFunc){
                return true;
            }
        }
        return false;
    }
    public String getNearestFuncType() {//找到最近层次的函数类型
        for(int i=SymboltableList.size()-1;i>=0;i--){
            if(SymboltableList.get(i).isFunc){
                return SymboltableList.get(i).funcType;
            }
        }
        return null;
    }
    public boolean isConst(Symbol s){//判断符号是否是常量
        return s.type==Symbol.Type.ConstInt||
                s.type==Symbol.Type.ConstChar||
                s.type==Symbol.Type.ConstCharArray||
                s.type==Symbol.Type.ConstIntArray;
    }
    public boolean isArray(Symbol s){//判断符号是否是常量
        return s.type==Symbol.Type.CharArray||
                s.type==Symbol.Type.ConstCharArray||
                s.type==Symbol.Type.ConstIntArray||
                s.type==Symbol.Type.IntArray;
    }
    //错误分析
    public void compUnitError(CompUnit compUnit){
        //{Decl} {FuncDef} MainFuncDef
        addSymbolTable(++scope,false,null);
        for(Decl decl:compUnit.decl){
            declError(decl);
        }
        for(FuncDef funcDef:compUnit.funcDef){
            funcDefError(funcDef);
        }
        mainFuncDefError(compUnit.mainFuncDef);
    }
    public void declError(Decl decl){
        //ConstDecl | VarDecl
        if(decl.constDecl!=null) constDeclError(decl.constDecl);
        else varDeclError(decl.varDecl);
    }
    public void constDeclError(ConstDecl constDecl){
        //'const' BType ConstDef { ',' ConstDef } ';'
        for(ConstDef constDef:constDecl.constDef){
            constDefError(constDef);
        }
    }
    public void constDefError(ConstDef constDef){

        //Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        //查看Ident是否重复定义，如果否加入本层符号表
        if(containsNow(constDef.IdentToken.content)){//报错
            errors.add(new Errortype(constDef.IdentToken.lineno,'b'));
        }
        else{
            if(constDef.constExp!=null) {//是数组
                constExpError(constDef.constExp);
                if(constDef.type=="int") putSymbol(constDef.IdentToken.content,new Symbol(Symbol.Type.ConstIntArray,constDef.IdentToken.content,"int",null));
                else putSymbol(constDef.IdentToken.content,new Symbol(Symbol.Type.ConstCharArray,constDef.IdentToken.content,"char",null));
            }
            else{
                if(constDef.type=="int") putSymbol(constDef.IdentToken.content,new Symbol(Symbol.Type.ConstInt,constDef.IdentToken.content,"int",null));
                else putSymbol(constDef.IdentToken.content,new Symbol(Symbol.Type.ConstChar,constDef.IdentToken.content,"char",null));
            }
            constInitValError(constDef.constInitVal);
        }
    }
    public void constInitValError(ConstInitVal constInitVal){
        //ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        if(constInitVal.constExp.size()>0){
            for(ConstExp constExp:constInitVal.constExp){
                constExpError(constExp);
            }
        }
    }
    public void varDeclError(VarDecl varDecl){
        //BType VarDef { ',' VarDef } ';'
        for(VarDef varDef:varDecl.varDef){
            varDefError(varDef);
        }
    }
    public void varDefError(VarDef varDef){
        //Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        if(containsNow(varDef.IdentToken.content)){//报错
            errors.add(new Errortype(varDef.IdentToken.lineno,'b'));
        }
        else{
            if(varDef.constExp!=null){//是数组
                constExpError(varDef.constExp);
                if(varDef.type=="int") putSymbol(varDef.IdentToken.content,new Symbol(Symbol.Type.IntArray,varDef.IdentToken.content,"int",null));
                else putSymbol(varDef.IdentToken.content,new Symbol(Symbol.Type.CharArray,varDef.IdentToken.content,"char",null));
            }
            else{
                if(varDef.type=="int") putSymbol(varDef.IdentToken.content,new Symbol(Symbol.Type.Int,varDef.IdentToken.content,"int",null));
                else putSymbol(varDef.IdentToken.content,new Symbol(Symbol.Type.Char,varDef.IdentToken.content,"char",null));
            }
            if(varDef.initVal!=null) initValError(varDef.initVal);
        }
    }
    public void initValError(InitVal initVal){//可以赋初值也可以不
        //Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        if(initVal.exp.size()>0){
            for(Exp exp:initVal.exp){
                expError(exp);
            }
        }
    }
    public void funcDefError(FuncDef funcDef){//函数定义
        //FuncType Ident '(' [FuncFParams] ')' Block
        if(containsNow(funcDef.IdentToken.content)){
            errors.add(new Errortype(funcDef.IdentToken.lineno,'b'));
        }
        else{
            if(funcDef.funcFParams==null){//没有函数形参
                if(funcDef.funcType.type==1)  putSymbol(funcDef.IdentToken.content,new Symbol(Symbol.Type.VoidFunc,funcDef.IdentToken.content,"void",new ArrayList<>()));
                else if(funcDef.funcType.type==2) putSymbol(funcDef.IdentToken.content,new Symbol(Symbol.Type.IntFunc,funcDef.IdentToken.content,"int",new ArrayList<>()));
                else putSymbol(funcDef.IdentToken.content,new Symbol(Symbol.Type.CharFunc,funcDef.IdentToken.content,"char",new ArrayList<>()));
            }
            else{//有函数形参
                List<FuncParam> funcParamList=new ArrayList<>();
                for(FuncFParam funcFParam:funcDef.funcFParams.funcFParam){
                    if(funcFParam.IdentToken.content.equals("a")){
                        System.out.println("1");
                    }
                    funcParamList.add(new FuncParam(funcFParam.IdentToken.content,funcFParam.hasNext,funcFParam.bType.isInt?"int":"char"));
                    //System.out.println(getSymbol(funcFParam.IdentToken.content).stringType);
                }
                if(funcDef.funcType.type==1)  putSymbol(funcDef.IdentToken.content,new Symbol(Symbol.Type.VoidFunc,funcDef.IdentToken.content,"void",funcParamList));
                else if(funcDef.funcType.type==2) putSymbol(funcDef.IdentToken.content,new Symbol(Symbol.Type.IntFunc,funcDef.IdentToken.content,"int",funcParamList));
                else putSymbol(funcDef.IdentToken.content,new Symbol(Symbol.Type.CharFunc,funcDef.IdentToken.content,"char",funcParamList));
            }
            if(funcDef.funcType.type==1) addSymbolTable(++scope,true,"void");
            else if(funcDef.funcType.type==2) addSymbolTable(++scope,true,"int");
            else addSymbolTable(++scope,true,"char");
            if(funcDef.funcFParams!=null){
                funcFParamsError(funcDef.funcFParams);
            }
            blockError(funcDef.block);
            removeSymbolTable();//scope的累计问题
        }
    }
    public void mainFuncDefError(MainFuncDef mainFuncDef){
        //'int' 'main' '(' ')' Block
        addSymbolTable(++scope,true,"int");
        blockError(mainFuncDef.block);
        removeSymbolTable();
    }
    public void funcFParamsError(FuncFParams funcFParams){
        // FuncFParam { ',' FuncFParam }
        for(FuncFParam funcFParam:funcFParams.funcFParam){
            funcFParamError(funcFParam);
        }
    }
    public void funcFParamError(FuncFParam funcFParam){
        //BType Ident ['[' ']']形参
        if(containsNow(funcFParam.IdentToken.content)){
            errors.add(new Errortype(funcFParam.IdentToken.lineno,'b'));
        }
        //出错也加入符号表吗？
        if(funcFParam.bType.isInt){
            putSymbol(funcFParam.IdentToken.content,new Symbol(funcFParam.hasNext?Symbol.Type.IntArray:Symbol.Type.Int,funcFParam.IdentToken.content,"int",null));
        }else{
            putSymbol(funcFParam.IdentToken.content,new Symbol(funcFParam.hasNext?Symbol.Type.CharArray:Symbol.Type.Char,funcFParam.IdentToken.content,"char",null));
        }
    }
    public void blockError(Block block){
        //'{' { BlockItem } '}'
        //}代表函数（这一层）结束，是否缺少返回值(g)
        for(int i=0;i<block.blockItem.size();i++){
            blockItemError(block.blockItem.get(i));
        }
        if(SymboltableList.get(SymboltableList.size()-1).isFunc){
            if(!SymboltableList.get(SymboltableList.size()-1).funcType.equals("void")){
                if(blockWithoutReturn(block)){
                    //完辣，重构吧
                    errors.add(new Errortype(block.rbToken.lineno,'g'));
                }
            }
        }
    }
    public void blockItemError(BlockItem blockItem){
        //Decl | Stmt
        if(blockItem.decl!=null){
            declError(blockItem.decl);
        }else{
            stmtError(blockItem.stmt);
        }
    }
    public void stmtError(Stmt stmt){
        //Stmt → LVal '=' Exp ';'
        //| [Exp] ';'
        //| Block
        //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        //| 'break' ';' | 'continue' ';'
        //| 'return' [Exp] ';'
        //| LVal '=' 'getint''('')'';'
        //| LVal '=' 'getchar''('')'';'
        //| 'printf''('StringConst {','Exp}')'';'
        switch(stmt.type){
            case 1:
                //LVal '=' Exp ';'
                lValError(stmt.lVal);
                expError(stmt.exp.get(0));
                if(getSymbol(stmt.lVal.IdentToken.content)!=null){
                    if(isConst(getSymbol(stmt.lVal.IdentToken.content))){
                        errors.add(new Errortype(stmt.lVal.IdentToken.lineno,'h'));
                    }
                }
                break;
            case 2:
                //[Exp] ';'
                if(stmt.exp.size()>0) expError(stmt.exp.get(0));
                break;
            case 3:
                //Block
                addSymbolTable(++scope,false,null);
                blockError(stmt.block);
                removeSymbolTable();
                break;
            case 4:
                //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                condError(stmt.cond);
                stmtError(stmt.stmt.get(0));
                if(stmt.stmt.size()>1){
                    stmtError(stmt.stmt.get(1));
                }
                break;
            case 5:
                //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                if(stmt.forStmt1!=null){
                    forStmtError(stmt.forStmt1);
                }
                if(stmt.cond!=null){
                    condError(stmt.cond);
                }
                if(stmt.forStmt2!=null){
                    forStmtError(stmt.forStmt2);
                }
                loop++;
                stmtError(stmt.stmt.get(0));
                loop--;
                break;
            case 6, 7:
                //'break' ';'|continue
                if(loop==0){
                    errors.add(new Errortype(stmt.BCToken.lineno,'m'));
                }
                break;
            case 8:
                //'return' [Exp] ';'
                if(isInFunc()){
                    if(getNearestFuncType().equals("void")&&stmt.exp.size()>0){
                        errors.add(new Errortype(stmt.reToken.lineno,'f'));
                    }
                    if(stmt.exp.size()>0){
                        expError(stmt.exp.get(0));
                    }
                }
                break;
            case 9,10:
                //LVal '=' 'getint''('')'';'
                lValError(stmt.lVal);
                if(getSymbol(stmt.lVal.IdentToken.content)!=null){
                    if(isConst(getSymbol(stmt.lVal.IdentToken.content))){
                        errors.add(new Errortype(stmt.lVal.IdentToken.lineno,'h'));
                    }
                }
                break;
            case 11:
                //'printf''('StringConst {','Exp}')'';'
                int expCnt=stmt.exp.size();
                int strCnt=0;
                for(int i=0;i<stmt.StringConst.content.length()-1;i++){
                    if(stmt.StringConst.content.charAt(i)=='%'){
                        if(stmt.StringConst.content.charAt(i+1)=='d'||stmt.StringConst.content.charAt(i+1)=='c'){
                            strCnt++;
                        }
                    }
                }
                if(expCnt!=strCnt){
                    //System.out.println(expCnt+" "+strCnt);
                    errors.add(new Errortype(stmt.StringConst.lineno,'l'));
                }
                for(Exp e:stmt.exp){
                    expError(e);
                }
                break;
        }
    }
    public void forStmtError(ForStmt forStmt){
        //LVal '=' Exp
        lValError(forStmt.lVal);

        if(isConst(getSymbol(forStmt.lVal.IdentToken.content))){
            errors.add(new Errortype(forStmt.lVal.IdentToken.lineno,'h'));
        }
        expError(forStmt.exp);
    }
    //表达式处理
    //Exp → AddExp
    public void expError(Exp exp){
        addExpError(exp.addExp);
    }
    public FuncParam getInExp(Exp exp){//是获取实参吗？
        return getInAddExp(exp.addExp);
    }
    //Cond → LOrExp
    public void condError(Cond cond){
        lOrExpError(cond.lOrExp);
    }
    //LVal → Ident ['[' Exp ']'],未定义的名字
    public void lValError(LVal lVal){
        //System.out.println(lVal.IdentToken.lineno);
        if(!containsAll(lVal.IdentToken.content)){
            errors.add(new Errortype(lVal.IdentToken.lineno,'c'));
        }
        if(lVal.exp!=null){
            expError(lVal.exp);
        }
    }
    public FuncParam getInlVal(LVal lVal){
        //System.out.println("lVal "+lVal.IdentToken.content);
        boolean isArray=false;
        if(isArray(getSymbol(lVal.IdentToken.content))&&lVal.exp==null){
            isArray=true;
        }
        //System.out.println(getSymbol(lVal.IdentToken.content).type);
        return new FuncParam(lVal.IdentToken.content,isArray,getSymbol(lVal.IdentToken.content).stringType);
    }
    //PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public void primaryExpError(PrimaryExp primaryExp){
        if(primaryExp.exp!=null){
            expError(primaryExp.exp);
        }else if(primaryExp.lVal!=null){
            lValError(primaryExp.lVal);
        }
    }
    public FuncParam getInPrimaryExp(PrimaryExp primaryExp){
        if(primaryExp.exp!=null){
            return getInExp(primaryExp.exp);
        }else if(primaryExp.lVal!=null){
            return getInlVal(primaryExp.lVal);
        }else{
            //立即数Number | Character
            return new FuncParam(null,false,null);
        }
    }
    //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public void unaryExpError(UnaryExp unaryExp){
        if(unaryExp.primaryExp!=null){
            primaryExpError(unaryExp.primaryExp);
        }else if(unaryExp.unaryExp!=null){
            unaryExpError(unaryExp.unaryExp);
        }else{
            //函数调用
            if(!containsAll(unaryExp.IdentToken.content)){
                //System.out.println(unaryExp.IdentToken.content);
                errors.add(new Errortype(unaryExp.IdentToken.lineno,'c'));
                return;
            }
            Symbol s=getSymbol(unaryExp.IdentToken.content);//函数名
            if(unaryExp.funcRParams==null){//没有实参
                if(s.funcParamList.size()>0){//形参
                    errors.add(new Errortype(unaryExp.IdentToken.lineno,'d'));
                }
            }
            else{
                if(unaryExp.funcRParams.exp.size()!=s.funcParamList.size()){
                    errors.add(new Errortype(unaryExp.IdentToken.lineno,'d'));
                    return;
                }
                List<Boolean> fdims=new ArrayList<>();
                for(int i=0;i<s.funcParamList.size();i++){//形参
                    fdims.add(s.funcParamList.get(i).isArray);//FuncParam的isArray何时定义？
                }
                //实参出问题啦
                List<Boolean> rdims=new ArrayList<>();
                funcRParamsError(unaryExp.funcRParams);
                for(Exp exp:unaryExp.funcRParams.exp){//遍历实参
                    FuncParam funcParam = getInExp(exp);//获取的实参是什么格式？
                    if(funcParam!=null){
                        //System.out.println("name:"+funcParam.name+" "+"isArray:"+funcParam.isArray);
                        if(funcParam.name==null){
                            //立即数Number | Character，都是false
                            rdims.add(false);
                        }
                        else{
                            Symbol s1=getSymbol(funcParam.name);
                            if(s1.funcParamList==null){//变量
                                //System.out.println(funcParam.name+" "+funcParam.isArray);
                                rdims.add(funcParam.isArray);//如何界定实参的isArray？
                            }else{//函数返回值
                                //System.out.println(funcParam.type);
                                if(s1.stringType.equals("void")){

                                    errors.add(new Errortype(unaryExp.IdentToken.lineno,'e'));
                                    return;
                                }else{
                                    rdims.add(false);
                                }
                            }
                        }
                        //这里
                    }
                }

                //变量-数组
                if(!Objects.equals(fdims,rdims)){
                    System.out.println("end "+unaryExp.IdentToken.lineno);
                    errors.add(new Errortype(unaryExp.IdentToken.lineno,'e'));
                    return;
                }
                for(int i=0;i<unaryExp.funcRParams.exp.size();i++){//实参
                    FuncParam funcParamr = getInExp(unaryExp.funcRParams.exp.get(i));
                    if(funcParamr.isArray&&!funcParamr.type.equals(s.funcParamList.get(i).type)){//实参是char array->int array
                        //System.out.println("end");
                        //System.out.println(funcParamr.name+" "+funcParamr.type);//函数名+实参类型+形参类型,实参类型错啦
                        errors.add(new Errortype(unaryExp.IdentToken.lineno,'e'));
                        return;
                    }
                }
            }
        }
    }
    public FuncParam getInUnaryExp(UnaryExp unaryExp){
        //PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        if(unaryExp.primaryExp!=null){
            return getInPrimaryExp(unaryExp.primaryExp);
        }else if(unaryExp.IdentToken!=null){
            Symbol s=getSymbol(unaryExp.IdentToken.content);
            return s.funcParamList!=null?new FuncParam(unaryExp.IdentToken.content,false,s.stringType):null;
        }else{
            return getInUnaryExp(unaryExp.unaryExp);
        }
    }
    public void funcRParamsError(FuncRParams funcRParams){
        //Exp { ',' Exp }
        for(Exp exp:funcRParams.exp){
            expError(exp);
        }
    }
    //MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    //UnaryExp{('*' | '/' | '%') UnaryExp}
    public void mulExpError(MulExp mulExp){
        for(UnaryExp unaryExp:mulExp.unaryExp){
            unaryExpError(unaryExp);
        }
    }
    public FuncParam getInMulExp(MulExp mulExp){
        return getInUnaryExp(mulExp.unaryExp.get(0));//只要第一个就行吗?
    }
    //AddExp → MulExp | AddExp ('+' | '−') MulExp
    //MulExp{('+' | '−') MulExp}
    public void addExpError(AddExp addExp){
        for(MulExp mulExp:addExp.mulExp){
            mulExpError(mulExp);
        }
    }
    public FuncParam getInAddExp(AddExp addExp){
        return getInMulExp(addExp.mulExp.get(0));//只要第一个就行吗?
    }
    //RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    //RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp }
    public void relExpError(RelExp relExp){
        for(AddExp addExp:relExp.addExp){
            addExpError(addExp);
        }
    }
    public void eqExpError(EqExp eqExp){
        //RelExp{('==' | '!=') RelExp}
        for(RelExp relExp:eqExp.relExp){
            relExpError(relExp);
        }
    }
    public void lAndExpError(LAndExp lAndExp){
        //EqExp{'&&' EqExp}
        for(EqExp eqExp: lAndExp.eqExp){
            eqExpError(eqExp);
        }
    }
    public void lOrExpError(LOrExp lOrExp){
        //LAndExp{||' LAndExp}
        for(LAndExp lAndExp: lOrExp.lAndExp){
            lAndExpError(lAndExp);
        }
    }
    public void constExpError(ConstExp constExp){
        addExpError(constExp.addExp);
    }
    public static void main(String[] args){


    }
}
