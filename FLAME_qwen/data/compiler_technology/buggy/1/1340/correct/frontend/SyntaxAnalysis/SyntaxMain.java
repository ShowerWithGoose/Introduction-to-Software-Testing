package frontend.SyntaxAnalysis;

import frontend.ERROR.Error;
import frontend.ERROR.ErrorType;
import frontend.LexicalAnalysis.Word;
import frontend.LexicalAnalysis.WordType;
import frontend.SyntaxAnalysis.AST.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class SyntaxMain {
    private ArrayList<String> syntaxRes;
    private ArrayList<Word> wordList;
    private ArrayList<Error> errorList;
    private CompUnit ast;

    private int now;

    public SyntaxMain(ArrayList<Word> wordList,ArrayList<Error> errorList) {
        this.syntaxRes = new ArrayList<>();
        this.wordList = wordList;
        this.errorList = errorList;//词法分析基础上
        this.ast = new CompUnit();
        this.now = 0;
    }

    public void buildAst(){
        this.ast = analyseCompUnit();
    }

    public ArrayList<String> getSyntaxRes() {
        return syntaxRes;
    }

    public CompUnit getAst() {
        return ast;
    }

    public ArrayList<Error> getErrorList() {
        return errorList;
    }

    public ArrayList<Word> getWordList() {
        return wordList;
    }

    /*成分判别*/
    private boolean isEqualWordType(int i, WordType type){
        if(now+i >= wordList.size()) {
            return false;
        }
        else{
            return wordList.get(i+now).getWordType().equals(type);
        }
    }

    /**
     *出现终结符时写入
     * @return 返回写入的终结符Word
     */
    private Word writeWord(){
        Word word = wordList.get(now);
        syntaxRes.add(word.getWordType() + " " + word.getWordName());
        now++;
        return word;
    }
    /*构建语法树*/
    private CompUnit analyseCompUnit(){
        CompUnit compUnit = new CompUnit();
        while(isEqualWordType(0,WordType.CONSTTK)
                    ||!isEqualWordType(2,WordType.LPARENT)){
                compUnit.declList.add(analyseDecl());
        }
        while(isEqualWordType(0,WordType.VOIDTK)
                    ||(isEqualWordType(1,WordType.IDENFR)
                        && isEqualWordType(2,WordType.LPARENT))) {
                compUnit.funcDefList.add(analyseFuncDef());
        }
        if(isEqualWordType(0,WordType.INTTK)
            && isEqualWordType(1,WordType.MAINTK)
            && isEqualWordType(2,WordType.LPARENT)){
            compUnit.mainFuncDef = analyseMainFuncDef();
        }
        syntaxRes.add("<"+SyntaxType.CompUnit+">");
        return compUnit;
    }



    private Decl analyseDecl(){
        // 无需输出<>
        Decl decl = new Decl();
        if(isEqualWordType(0,WordType.CONSTTK)){
            decl.declType = Decl.DeclType.constDecl;
            decl.constDecl = analyseConstDecl();
        }
        else{
            decl.declType = Decl.DeclType.varDecl;
            decl.varDecl = analyseVarDecl();
        }
        return decl;
    }

    private ConstDecl analyseConstDecl() {
        ConstDecl constDecl = new ConstDecl();
        //写入 'const'
        constDecl.const0 = writeWord();

        constDecl.bType = analyseBtype();
        constDecl.constDefList.add(analyseConstDef());

        while(isEqualWordType(0,WordType.COMMA)
                && isEqualWordType(1,WordType.IDENFR)){
            // 写入','
            writeWord();
            constDecl.constDefList.add(analyseConstDef());
        }
        //判断分号是否存在
        if(!isEqualWordType(0,WordType.SEMICN)){
            Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
            errorList.add(error);
        }
        else{
            //写入“;”
            constDecl.semicn = writeWord();
        }
        syntaxRes.add("<"+SyntaxType.ConstDecl+">");
        return constDecl;
    }

    private BType analyseBtype() {
        // 无需输出<>
        BType bType = new BType();
        bType.word = writeWord();
        return bType;
    }

    private ConstDef analyseConstDef() {
        ConstDef constDef = new ConstDef();
        //写入ident
        constDef.ident = writeWord();

        if(isEqualWordType(0,WordType.LBRACK)){
            constDef.haveConstExp = true;
            constDef.lbrack = writeWord();
            constDef.constExp = analyseConstExp();
            //是否缺少右中括号
            if(!isEqualWordType(0,WordType.RBRACK)){
                Error error = new Error(ErrorType.k,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                constDef.rbrack = writeWord();
            }
        }
        constDef.assign = writeWord();
        constDef.constInitVal = analyseConstInitVal();

        syntaxRes.add("<"+SyntaxType.ConstDef+">");
        return constDef;
    }

    private ConstExp analyseConstExp() {
        ConstExp constExp = new ConstExp();
        constExp.addExp = analyseAddExp();
        syntaxRes.add("<"+SyntaxType.ConstExp+">");
        return constExp;
    }

    private ConstInitVal analyseConstInitVal() {
        ConstInitVal constInitVal = new ConstInitVal();
        if(isEqualWordType(0,WordType.LBRACE)){
            constInitVal.type = ConstInitVal.ConstInitValType.constExpList;
            //写入{
            writeWord();
            if((!isEqualWordType(0,WordType.RBRACE))){
                constInitVal.constExpList.add(analyseConstExp());
            }
            while(!isEqualWordType(0,WordType.RBRACE)){
                //write ','
                writeWord();
                constInitVal.constExpList.add(analyseConstExp());
            }
            //write '}'
            writeWord();
        }
        else if(isEqualWordType(0,WordType.STRCON)){
            constInitVal.type = ConstInitVal.ConstInitValType.stringConst;
            constInitVal.stringConst = writeWord();
        }
        else{
            constInitVal.type = ConstInitVal.ConstInitValType.singleConstExp;
            constInitVal.constExpList.add(analyseConstExp());
        }
        syntaxRes.add("<"+SyntaxType.ConstInitVal+">");
        return constInitVal;
    }

    private VarDecl analyseVarDecl(){
        VarDecl varDecl = new VarDecl();
        varDecl.bType = analyseBtype();
        varDecl.varDefList.add(analyseVarDef());
        while(isEqualWordType(0,WordType.COMMA)){
            // write ','
            writeWord();
            varDecl.varDefList.add(analyseVarDef());
        }
        //判断分号是否存在
        if(!isEqualWordType(0,WordType.SEMICN)){
            Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
            errorList.add(error);
        }
        else{
            //写入“;”
            varDecl.semicn = writeWord();
        }
        syntaxRes.add("<"+SyntaxType.VarDecl+">");
        return varDecl;
    }

    private VarDef analyseVarDef() {
        VarDef varDef = new VarDef();
        varDef.ident = writeWord();
        if(isEqualWordType(0, WordType.LBRACK)){
            varDef.lbrack  = writeWord();
            varDef.constExp = analyseConstExp();
            //是否缺少右中括号
            if(!isEqualWordType(0,WordType.RBRACK)){
                Error error = new Error(ErrorType.k,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                varDef.rbrack = writeWord();
            }
        }
        if(isEqualWordType(0,WordType.ASSIGN)){
            varDef.assign = writeWord();
            varDef.haveInitVal = true;
            varDef.initVal = analyseInitVal();
        }
        syntaxRes.add("<"+SyntaxType.VarDef+">");
        return varDef;
    }

    private InitVal analyseInitVal() {
        InitVal initVal = new InitVal();
        if(isEqualWordType(0,WordType.LBRACE)){
            initVal.type = InitVal.InitValType.expList;
            //写入{
            writeWord();
            if((!isEqualWordType(0,WordType.RBRACE))){
                initVal.expList.add(analyseExp());
            }
            while(!isEqualWordType(0,WordType.RBRACE)){
                //write ','
                writeWord();
                initVal.expList.add(analyseExp());
            }
            //write '}'
            writeWord();
        }
        else if(isEqualWordType(0,WordType.STRCON)){
            initVal.type = InitVal.InitValType.stringConst;
            initVal.stringConst = writeWord();
        }
        else{
            initVal.type = InitVal.InitValType.singleExp;
            initVal.expList.add(analyseExp());
        }

        syntaxRes.add("<"+SyntaxType.InitVal+">");
        return initVal;
    }

    private FuncDef analyseFuncDef(){
        FuncDef funcDef = new FuncDef();
        funcDef.funcType = analyseFuncType();
        funcDef.ident = writeWord();
        funcDef.lparent = writeWord();
        //可能缺失右小括号，判断是FuncFParams还是')'还是Block
        if(isEqualWordType(0,WordType.INTTK)
                ||isEqualWordType(0,WordType.CHARTK)){
            funcDef.haveFuncFParams = true;
            funcDef.funcFParams = analyseFuncFParams();
        }
        else{
            funcDef.haveFuncFParams = false;
        }

        if(isEqualWordType(0, WordType.RPARENT)){
            funcDef.rparent = writeWord();
        }
        else{
            Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
            errorList.add(error);
        }
        funcDef.block = analyseBlock();
        syntaxRes.add("<"+SyntaxType.FuncDef+">");
        return funcDef;
    }

    private MainFuncDef analyseMainFuncDef(){
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.inttk = writeWord();
        mainFuncDef.maintk = writeWord();
        mainFuncDef.lparent = writeWord();
        if(isEqualWordType(0,WordType.RPARENT)){
            mainFuncDef.rparent = writeWord();
        }
        else{
            Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
            errorList.add(error);
        }
        mainFuncDef.block = analyseBlock();

        syntaxRes.add("<"+SyntaxType.MainFuncDef+">");
        return mainFuncDef;
    }

    private FuncType analyseFuncType() {
        FuncType funcType = new FuncType(writeWord().getWordType());
        syntaxRes.add("<"+SyntaxType.FuncType+">");
        return funcType;
    }

    private FuncFParams analyseFuncFParams(){
        FuncFParams funcFParams = new FuncFParams();
        funcFParams.funcFParamList.add(analyseFuncFParam());
        while(isEqualWordType(0,WordType.COMMA)){
            // write ','
            writeWord();
            funcFParams.funcFParamList.add(analyseFuncFParam());
        }
        syntaxRes.add("<"+SyntaxType.FuncFParams+">");
        return funcFParams;
    }

    private FuncFParam analyseFuncFParam() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.btype = analyseBtype();
        funcFParam.ident = writeWord();
        if(isEqualWordType(0,WordType.LBRACK)) {
            funcFParam.lbrack = writeWord();
            if (isEqualWordType(0, WordType.RBRACK)) {
                funcFParam.rbrack = writeWord();
            } else {
                Error error = new Error(ErrorType.k, wordList.get(now - 1).getRow());
                errorList.add(error);
            }
        }
        syntaxRes.add("<"+SyntaxType.FuncFParam+">");
        return funcFParam;
    }

    private Block analyseBlock(){
        Block block = new Block();
        block.lbrace = writeWord();
        while(!isEqualWordType(0,WordType.RBRACE)) {
            block.blockItems.add(analyseBlockItem());
        }
        block.rbrace = writeWord();
        syntaxRes.add("<"+SyntaxType.Block+">");
        return block;
    }

    private BlockItem analyseBlockItem() {
        //无需<>
        BlockItem blockItem = new BlockItem();
        if(isEqualWordType(0, WordType.CONSTTK)
        ||isEqualWordType(0, WordType.INTTK)
        ||isEqualWordType(0, WordType.CHARTK)){
            blockItem.type = BlockItem.BlockItemType.Decl;
            blockItem.decl = analyseDecl();
        }
        else{
            blockItem.type = BlockItem.BlockItemType.Stmt;
            blockItem.stmt =analyseStmt();
        }
        return blockItem;
    }

    private Stmt analyseStmt(){
        Stmt stmt = new Stmt();
        if(isEqualWordType(0, WordType.IFTK)){
            stmt.type = Stmt.StmtType._if;
            writeWord();
            writeWord();
            stmt.cond = analyseCond();
            if(isEqualWordType(0, WordType.RPARENT)){
                writeWord();
            }
            else{
                Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            stmt.stmtIf = analyseStmt();
            if(isEqualWordType(0, WordType.ELSETK)){
                writeWord();
                stmt.stmtElse = analyseStmt();
            }
        }
        else if(isEqualWordType(0, WordType.FORTK)){
            stmt.type = Stmt.StmtType._for;
            writeWord();
            writeWord();
            if(!isEqualWordType(0, WordType.SEMICN)){
                stmt.forStmt1 = analyseForStmt();
            }
            writeWord();
            if(!isEqualWordType(0, WordType.SEMICN)){
                stmt.cond = analyseCond();
            }
            writeWord();
            if(!isEqualWordType(0, WordType.RPARENT)){
                stmt.forStmt2 = analyseForStmt();
            }
            writeWord();
            stmt.stmtFor = analyseStmt();
        }
        else if(isEqualWordType(0, WordType.BREAKTK)){
            stmt.type = Stmt.StmtType._break;
            writeWord();
            if(!isEqualWordType(0,WordType.SEMICN)){
                Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                writeWord();
            }
        }
        else if(isEqualWordType(0, WordType.CONTINUETK)){
            stmt.type = Stmt.StmtType._continue;
            writeWord();
            if(!isEqualWordType(0,WordType.SEMICN)){
                Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                writeWord();
            }
        }
        else if(isEqualWordType(0, WordType.RETURNTK)){
            stmt.type = Stmt.StmtType._return;
            writeWord();
            if(isEqualWordType(0, WordType.PLUS)
            ||isEqualWordType(0,WordType.MINU)
            ||isEqualWordType(0,WordType.NOT)
            ||isEqualWordType(0,WordType.LPARENT)
            ||isEqualWordType(0,WordType.IDENFR)
            ||isEqualWordType(0,WordType.INTCON)
            ||isEqualWordType(0,WordType.CHRCON)){
                stmt.exp = analyseExp();
            }
            if(!isEqualWordType(0,WordType.SEMICN)){
                Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                writeWord();
            }
        }
        else if(isEqualWordType(0, WordType.PRINTFTK)){
            stmt.type = Stmt.StmtType._printf;
            writeWord();
            writeWord();
            stmt.stringConst = writeWord();
            while(isEqualWordType(0,WordType.COMMA)){
                // write ','
                writeWord();
                stmt.expsPrintf.add(analyseExp());
            }
            //是否缺失')'
            if(!isEqualWordType(0, WordType.RPARENT)){
                Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                writeWord();
            }
            //是否缺失';'
            if(!isEqualWordType(0,WordType.SEMICN)){
                Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                writeWord();
            }

        }
        else if(isEqualWordType(0,WordType.LBRACE)){
            stmt.type = Stmt.StmtType.block;
            stmt.block = analyseBlock();
        }
        //LVal or Exp;
        else if(isEqualWordType(0,WordType.SEMICN)){
            stmt.type = Stmt.StmtType.expSemicn;
            writeWord();
        }
        else if(isEqualWordType(0, WordType.PLUS)
                    ||isEqualWordType(0,WordType.MINU)
                    ||isEqualWordType(0,WordType.NOT)
                    ||isEqualWordType(0,WordType.LPARENT)
                    ||isEqualWordType(0,WordType.INTCON)
                    ||isEqualWordType(0,WordType.CHRCON)
                    ||(isEqualWordType(0,WordType.IDENFR)
                        &&isEqualWordType(1,WordType.LPARENT))){
            //ident另行考虑
            stmt.type = Stmt.StmtType.expSemicn;
            stmt.exp = analyseExp();
            //是否缺失';'
            if(!isEqualWordType(0,WordType.SEMICN)){
                Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                writeWord();
            }
        }
        else if(isEqualWordType(0,WordType.IDENFR)){
            int tempNow = now;
            ArrayList<String> tempResList = (ArrayList<String>) syntaxRes.clone();
            ArrayList<Error> tempErrorList = (ArrayList<Error>) errorList.clone();
            analyseLVal();
            if(isEqualWordType(0, WordType.ASSIGN)){
                //回溯
                now = tempNow;
                syntaxRes = (ArrayList<String>) tempResList.clone();
                errorList = (ArrayList<Error>) tempErrorList.clone();
                stmt.lval = analyseLVal();
                //write =
                writeWord();

                if(isEqualWordType(0, WordType.GETINTTK)){
                    stmt.type = Stmt.StmtType._getint;
                    writeWord();
                    writeWord();
                    //是否缺失')'
                    if(!isEqualWordType(0, WordType.RPARENT)){
                        Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
                        errorList.add(error);
                    }
                    else{
                        writeWord();
                    }
                    //是否缺失';'
                    if(!isEqualWordType(0,WordType.SEMICN)){
                        Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                        errorList.add(error);
                    }
                    else{
                        writeWord();
                    }
                }
                else if(isEqualWordType(0, WordType.GETCHARTK)){
                    stmt.type = Stmt.StmtType._getchar;
                    writeWord();
                    writeWord();
                    //是否缺失')'
                    if(!isEqualWordType(0, WordType.RPARENT)){
                        Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
                        errorList.add(error);
                    }
                    else{
                        writeWord();
                    }
                    //是否缺失';'
                    if(!isEqualWordType(0,WordType.SEMICN)){
                        Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                        errorList.add(error);
                    }
                    else{
                        writeWord();
                    }
                }
                else{
                    stmt.type = Stmt.StmtType.LValEqualExp;
                    stmt.exp = analyseExp();
                    //是否缺失';'
                    if(!isEqualWordType(0,WordType.SEMICN)){
                        Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                        errorList.add(error);
                    }
                    else{
                        writeWord();
                    }
                }
            }
            else{
                stmt.type = Stmt.StmtType.expSemicn;
                //回溯
                now = tempNow;
                syntaxRes = (ArrayList<String>) tempResList.clone();
                errorList = (ArrayList<Error>) tempErrorList.clone();
                //Ident开头不会缺省exp
                stmt.exp = analyseExp();
                //是否缺失';'
                if(!isEqualWordType(0,WordType.SEMICN)){
                    Error error = new Error(ErrorType.i,wordList.get(now-1).getRow());
                    errorList.add(error);
                }
                else{
                    writeWord();
                }
            }
        }

        syntaxRes.add("<"+SyntaxType.Stmt+">");
        return stmt;
    }

    private ForStmt analyseForStmt(){
        ForStmt forStmt = new ForStmt();
        forStmt.lval = analyseLVal();
        forStmt.assign = writeWord();
        forStmt.exp = analyseExp();

        syntaxRes.add("<"+SyntaxType.ForStmt+">");
        return forStmt;
    }

    private Exp analyseExp() {
        Exp exp = new Exp();
        exp.addExp = analyseAddExp();

        syntaxRes.add("<"+SyntaxType.Exp+">");
        return exp;
    }

    private Cond analyseCond(){
        Cond cond = new Cond();
        cond.lOrExp = analyseLOrExp();
        syntaxRes.add("<"+SyntaxType.Cond+">");
        return cond;
    }

    private LVal analyseLVal(){
        LVal lVal = new LVal();
        lVal.ident = writeWord();
        if(isEqualWordType(0, WordType.LBRACK)){
            writeWord();
            lVal.haveExp = true;
            lVal.exp = analyseExp();
            //是否缺少右中括号
            if(!isEqualWordType(0,WordType.RBRACK)){
                Error error = new Error(ErrorType.k,wordList.get(now-1).getRow());
                errorList.add(error);
            }
            else{
                writeWord();
            }
        }
        syntaxRes.add("<"+SyntaxType.LVal+">");
        return lVal;
    }

    private PrimaryExp analysePrimaryExp(){
        PrimaryExp primaryExp = new PrimaryExp();
        if(isEqualWordType(0, WordType.LPARENT)){
            primaryExp.type = PrimaryExp.PrimaryExpType.exp;
            writeWord();
            primaryExp.exp = analyseExp();
            if(isEqualWordType(0, WordType.RPARENT)){
                writeWord();
            }
            else{
                Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
                errorList.add(error);
            }
        }
        else if(isEqualWordType(0, WordType.INTCON)){
            primaryExp.type = PrimaryExp.PrimaryExpType.Number;
            primaryExp.number = writeWord();
            //没有单独的Number类，但是要输出
            syntaxRes.add("<"+SyntaxType.Number+">");
        }
        else if(isEqualWordType(0, WordType.CHRCON)){
            primaryExp.type = PrimaryExp.PrimaryExpType.Character;
            primaryExp.character = writeWord();
            //同上
            syntaxRes.add("<"+SyntaxType.Character+">");
        }
        else{
            primaryExp.type = PrimaryExp.PrimaryExpType.lVal;
            primaryExp.lVal = analyseLVal();
        }

        syntaxRes.add("<"+SyntaxType.PrimaryExp+">");
        return primaryExp;
    }

    private UnaryExp analyseUnaryExp(){
        UnaryExp unaryExp = new UnaryExp();
        if(isEqualWordType(0,WordType.IDENFR)&&isEqualWordType(1,WordType.LPARENT)){
            unaryExp.type = UnaryExp.UnaryExpType.ident;
            unaryExp.ident = writeWord();
            writeWord();
            if(isEqualWordType(0, WordType.PLUS)
                    ||isEqualWordType(0,WordType.MINU)
                    ||isEqualWordType(0,WordType.NOT)
                    ||isEqualWordType(0,WordType.IDENFR)
                    ||isEqualWordType(0,WordType.INTCON)
                    ||isEqualWordType(0,WordType.CHRCON)
                    ||isEqualWordType(0,WordType.LPARENT)){
                unaryExp.funcRParams = analyseFuncRParams();
            }
            if(isEqualWordType(0, WordType.RPARENT)){
                writeWord();
            }
            else{
                Error error = new Error(ErrorType.j,wordList.get(now-1).getRow());
                errorList.add(error);
            }
        }
        else if(isEqualWordType(0, WordType.PLUS)
                ||isEqualWordType(0,WordType.MINU)
                ||isEqualWordType(0,WordType.NOT)){
            unaryExp.type = UnaryExp.UnaryExpType.UnaryOp;
            unaryExp.unaryOp = analyseUnaryOp();
            unaryExp.unaryExp = analyseUnaryExp();
        }
        else{
            unaryExp.type = UnaryExp.UnaryExpType.primaryExp;
            unaryExp.primaryExp = analysePrimaryExp();
        }
        syntaxRes.add("<"+SyntaxType.UnaryExp+">");
        return unaryExp;
    }

    private UnaryOp analyseUnaryOp() {
        UnaryOp unaryOp = new UnaryOp(writeWord().getWordType());
        syntaxRes.add("<"+SyntaxType.UnaryOp+">");
        return unaryOp;
    }

    private FuncRParams analyseFuncRParams(){
        FuncRParams funcRParams = new FuncRParams();
        funcRParams.expList.add(analyseExp());
        while(isEqualWordType(0,WordType.COMMA)){
            // 写入','
            writeWord();
            funcRParams.expList.add(analyseExp());
        }
        syntaxRes.add("<"+SyntaxType.FuncRParams+">");
        return funcRParams;
    }

    private MulExp analyseMulExp(){
        MulExp mulExp = new MulExp();
        mulExp.unaryExpList.add(analyseUnaryExp());
        while(isEqualWordType(0,WordType.MULT)
                ||isEqualWordType(0,WordType.DIV)
                ||isEqualWordType(0,WordType.MOD)){
            syntaxRes.add("<"+SyntaxType.MulExp+">");
            writeWord();
            mulExp.unaryExpList.add(analyseUnaryExp());
        }
        syntaxRes.add("<"+SyntaxType.MulExp+">");
        return mulExp;
    }

    private AddExp analyseAddExp(){
        AddExp addExp = new AddExp();
        addExp.mulExpList.add(analyseMulExp());
        while(isEqualWordType(0,WordType.PLUS)
                ||isEqualWordType(0,WordType.MINU)){
            syntaxRes.add("<"+SyntaxType.AddExp+">");
            writeWord();
            addExp.mulExpList.add(analyseMulExp());
        }
        syntaxRes.add("<"+SyntaxType.AddExp+">");
        return addExp;
    }

    private RelExp analyseRelExp(){
        RelExp relExp = new RelExp();
        relExp.addExpList.add(analyseAddExp());
        while(isEqualWordType(0,WordType.LSS)
                ||isEqualWordType(0,WordType.LEQ)
                ||isEqualWordType(0,WordType.GRE)
                ||isEqualWordType(0,WordType.GEQ)){
            syntaxRes.add("<"+SyntaxType.RelExp+">");
            writeWord();
            relExp.addExpList.add(analyseAddExp());
        }
        syntaxRes.add("<"+SyntaxType.RelExp+">");
        return relExp;
    }

    private EqExp analyseEqExp(){
        EqExp eqExp= new EqExp();
        eqExp.relExpList.add(analyseRelExp());
        while(isEqualWordType(0,WordType.NEQ)
                ||isEqualWordType(0,WordType.EQL)){
            syntaxRes.add("<"+SyntaxType.EqExp+">");
            writeWord();
            eqExp.relExpList.add(analyseRelExp());
        }
        syntaxRes.add("<"+SyntaxType.EqExp+">");
        return eqExp;
    }

    private LAndExp analyseLAndExp(){
        LAndExp lAndExp= new LAndExp();
        lAndExp.eqExpList.add(analyseEqExp());
        while(isEqualWordType(0,WordType.AND)){
            syntaxRes.add("<"+SyntaxType.LAndExp+">");
            writeWord();
            lAndExp.eqExpList.add(analyseEqExp());
        }
        syntaxRes.add("<"+SyntaxType.LAndExp+">");
        return lAndExp;
    }

    private LOrExp analyseLOrExp(){
        LOrExp lOrExp= new LOrExp();
        lOrExp.lAndExpList.add(analyseLAndExp());
        while(isEqualWordType(0,WordType.OR)){
            syntaxRes.add("<"+SyntaxType.LOrExp+">");
            writeWord();
            lOrExp.lAndExpList.add(analyseLAndExp());
        }
        syntaxRes.add("<"+SyntaxType.LOrExp+">");
        return lOrExp;
    }

    /*输出函数*/
    public void writeResToFile(String filePath) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (String s : syntaxRes) {
                writer.write(s);
                writer.newLine(); // 换行
            }
            System.out.println("写入成功！");
        } catch (IOException e) {
            System.err.println("写入文件时出错: " + e.getMessage());
        }
    }
    public void writeErrorsToFile(String filePath) {
        Collections.sort(errorList, Comparator.comparingInt(Error::getRow));
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (Error error : errorList) {
                writer.write(error.getRow() + " " + error.getErrorType());
                writer.newLine(); // 换行
            }
            System.out.println("写入成功！");
        } catch (IOException e) {
            System.err.println("写入文件时出错: " + e.getMessage());
        }
    }

}
