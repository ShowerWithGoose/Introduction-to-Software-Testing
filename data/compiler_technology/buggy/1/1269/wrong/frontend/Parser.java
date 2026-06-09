package frontend;

import Tree.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Parser {
    private Lexer lexer;
    private Branch compUnit;
    private boolean isError;
    private ArrayList<Integer> errorLine = new ArrayList<>();
    private ArrayList<Character> errorType = new ArrayList<>();
    private int test = 1;
    
    public Parser(Lexer lexer) {
        this.lexer = lexer;
        this.isError = false;
        this.compUnit = CompUnit();
    }
    
    public Branch CompUnit() {
        Branch compUnit = new Branch("CompUnit");
        while (true) {
            while (now() == Lexer.Type.INTTK) {
                if (preRead() == Lexer.Type.MAINTK) {
                    compUnit.add(MainFuncDef());
                    return compUnit;
                }
                if (preRead() == Lexer.Type.IDENFR) {
                    if (prePreRead() == Lexer.Type.LPARENT) {
                        compUnit.add(FuncDef());
                    } else {
                        compUnit.add(VarDecl());
                    }
                }
            }
            while (now() == Lexer.Type.CHARTK) {
                if (preRead() == Lexer.Type.IDENFR) {
                    if (prePreRead() == Lexer.Type.LPARENT) {
                        compUnit.add(FuncDef());
                    } else {
                        compUnit.add(VarDecl());
                    }
                }
            }
            while (now() == Lexer.Type.CONSTTK) {
                compUnit.add(ConstDecl());
                
            }
            while (now() == Lexer.Type.VOIDTK) {
                compUnit.add(FuncDef());
            }
        }
    }
    
    public Branch ConstDecl() {
        Branch constDecl = new Branch("ConstDecl");
        constDecl.add(new Leaf(now(), nowContent())); // 'const'
        next(); // Btype
        constDecl.add(new Leaf(now(), nowContent())); //Btype
        next(); // ConstDef
        constDecl.add(ConstDef());
        while (now() == Lexer.Type.COMMA) {
            constDecl.add(new Leaf(now(), nowContent())); // ','
            next(); //ConstDef
            constDecl.add(ConstDef());
        }
        
        if (now() == Lexer.Type.SEMICN) {
            constDecl.add(new Leaf(now(), nowContent())); // ';'
        } else { // error i
            isError = true;
            back();
            errorLine.add(lineNum());
            errorType.add('i');
        }
        next();
        
        return constDecl;
    }
    
    public Branch ConstDef() {
        Branch constDef = new Branch("ConstDef");
        constDef.add(new Leaf(now(), nowContent())); // Ident;
        next(); // '[' or '='
        if (now() == Lexer.Type.LBRACK) {
            constDef.add(new Leaf(now(), nowContent())); // [
            next(); //ConstExp
            constDef.add(ConstExp());
            if (now() == Lexer.Type.RBRACK) {
                constDef.add(new Leaf(now(), nowContent())); // ']'
            } else { // error k
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('k');
            }
            next();
        }
        constDef.add(new Leaf(now(), nowContent())); // =
        next(); // ConstInitVal
        constDef.add(ConstInitVal());
        return constDef;
    }
    
    public Branch ConstInitVal() {
        Branch constInitVal = new Branch("ConstInitVal");
        if (now() == Lexer.Type.LBRACE) { //'{' [ ConstExp { ',' ConstExp } ] '}'
            constInitVal.add(new Leaf(now(), nowContent())); // '{'
            next(); // constExp or '}'
            if (now() != Lexer.Type.RBRACE) { // constExp
                constInitVal.add(ConstExp());
                while (now() == Lexer.Type.COMMA) {
                    constInitVal.add(new Leaf(now(), nowContent())); // ','
                    next(); //constExp
                    constInitVal.add(ConstExp());
                }
            }
            constInitVal.add(new Leaf(now(), nowContent())); // '}'
            next();
        }
        else if (now() == Lexer.Type.STRCON) {
            constInitVal.add(new Leaf(now(), nowContent())); // StringConst
            next();
        }
        else { // constExp
            constInitVal.add(ConstExp());
        }
        return constInitVal;
    }
    
    public Branch VarDecl() {
        Branch varDecl = new Branch("VarDecl");
        varDecl.add(new Leaf(now(), nowContent())); // Btype
        next(); // VarDef
        varDecl.add(VarDef());
        while (now() == Lexer.Type.COMMA) {
            varDecl.add(new Leaf(now(), nowContent())); // ','
            next(); // VarDef
            varDecl.add(VarDef());
        }
        if (now() == Lexer.Type.SEMICN) {
            varDecl.add(new Leaf(now(), nowContent())); // ';'
        } else { // error i
            isError = true;
            back();
            errorLine.add(lineNum());
            errorType.add('i');
        }
        next();
        return varDecl;
    }
    
    public Branch VarDef() {
        Branch varDef = new Branch("VarDef");
        varDef.add(new Leaf(now(), nowContent())); // Ident
        next(); // '[' or '=' or over
        if (now() == Lexer.Type.LBRACK) {
            varDef.add(new Leaf(now(), nowContent())); // '['
            next(); //ConstExp
            varDef.add(ConstExp());
            if (now() == Lexer.Type.RBRACK) {
                varDef.add(new Leaf(now(), nowContent())); //']'
            } else { // error k
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('k');
            }
            next(); //'=' or over
        }
        if (now() == Lexer.Type.ASSIGN) {
            varDef.add(new Leaf(now(), nowContent())); // '='
            next(); // InitVal
            varDef.add(InitVal()); //InitVal
        }
        return varDef;
    }
    
    public Branch InitVal() {
        Branch initVal = new Branch("InitVal");
        if (now() == Lexer.Type.LBRACE) { //'{' [ Exp { ',' Exp } ] '}'
            initVal.add(new Leaf(now(), nowContent())); // '{'
            next(); // constExp or '}'
            if (now() != Lexer.Type.RBRACE) { // constExp
                initVal.add(Exp());
                while (now() == Lexer.Type.COMMA) {
                    initVal.add(new Leaf(now(), nowContent())); // ','
                    next(); //Exp
                    initVal.add(Exp());
                }
            }
            initVal.add(new Leaf(now(), nowContent())); // '}'
            next();
        }
        else if (now() == Lexer.Type.STRCON) {
            initVal.add(new Leaf(now(), nowContent())); // StringConst
            next();
        }
        else { // Exp
            initVal.add(Exp());
        }
        return initVal;
    }
    
    public Branch FuncDef() {
        Branch funcDef = new Branch("FuncDef");
        funcDef.add(FuncType()); //FuncType
        next(); // Ident
        funcDef.add(new Leaf(now(), nowContent())); // Ident
        next(); // '('
        funcDef.add(new Leaf(now(), nowContent())); // '('
        next(); //FuncFParams or ')'
        if (now() != Lexer.Type.RPARENT) { //error or FuncFParams
            if (now() == Lexer.Type.LBRACE) { //error j
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('j');
                next();
                funcDef.add(Block()); // Block
                return funcDef;
            } else {
                funcDef.add(FuncFParams()); //FuncFParams
            }
        }
        
        if (now() == Lexer.Type.RPARENT) {
            funcDef.add(new Leaf(now(), nowContent())); // ')'
            next(); // Block
            
            funcDef.add(Block()); // Block
        } else {
            isError = true;
            back();
            errorLine.add(lineNum());
            errorType.add('j');
            next();
            funcDef.add(Block()); // Block
        }
        return funcDef;
    }
    
    public Branch MainFuncDef() {
        Branch mainFuncDef = new Branch("MainFuncDef");
        mainFuncDef.add(new Leaf(now(), nowContent())); // 'int'
        next(); // 'main'
        mainFuncDef.add(new Leaf(now(), nowContent())); // 'main'
        next(); // (
        mainFuncDef.add(new Leaf(now(), nowContent())); // '('
        next(); // ) or error
        if (now() != Lexer.Type.RPARENT) {
            isError = true;
            back();
            errorLine.add(lineNum());
            errorType.add('j');
            next();
            mainFuncDef.add(Block()); // Block
        } else {
            mainFuncDef.add(new Leaf(now(), nowContent())); // ')'
            next(); //Block
            mainFuncDef.add(Block()); //Block
        }
        return mainFuncDef;
    }
    
    public Branch FuncType() {
        Branch funcType = new Branch("FuncType");
        funcType.add(new Leaf(now(), nowContent())); // int main void
        return funcType;
    }
    
    public Branch FuncFParams() {
        Branch funcFParams = new Branch("FuncFParams");
        funcFParams.add(FuncFParam()); //FuncFParam
        while (now() == Lexer.Type.COMMA) {
            funcFParams.add(new Leaf(now(), nowContent())); // ','
            next();
            funcFParams.add(FuncFParam()); //FuncFParam
        }
        return funcFParams;
    }
    
    public Branch FuncFParam() {
        Branch funcFParam = new Branch("FuncFParam");
        funcFParam.add(new Leaf(now(), nowContent())); // Btype
        next(); // Ident
        funcFParam.add(new Leaf(now(), nowContent())); // Ident
        next();
        if (now() == Lexer.Type.LBRACK) {
            funcFParam.add(new Leaf(now(), nowContent())); // '['
            next();
            if (now() == Lexer.Type.RBRACK) {
                funcFParam.add(new Leaf(now(), nowContent())); // ']'
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('k');
            }
            next();
        }
        return funcFParam;
    }
    
    public Branch Block() {
        Branch block = new Branch("Block");
        block.add(new Leaf(now(), nowContent())); // '{'
        next();
        while (now() != Lexer.Type.RBRACE) {
            if (now() == Lexer.Type.CONSTTK) {
                block.add(ConstDecl());
            } else if (now() == Lexer.Type.INTTK || now() == Lexer.Type.CHARTK) {
                block.add(VarDecl());
            } else {
                //System.out.println(preRead().name()); /////////////////////////////
                block.add(Stmt());
            }
        }
        //System.out.println(now().name()); //////////////////////////
        block.add(new Leaf(now(), nowContent())); // '}'
        
        next();
        //block.postOrderTraversal();
        return block;
    }
    
    public Branch Stmt() {
        Branch stmt = new Branch("Stmt");
        // LVal
        if (now() == Lexer.Type.IDENFR) {
            int record = lexer.getPosition();
            Branch branch = LVal();
            if (now() == Lexer.Type.ASSIGN) {
                stmt.add(branch);
                stmt.add(new Leaf(now(), nowContent())); // '='
                next(); // getint / getchar / Exp
                if (now() == Lexer.Type.GETINTTK || now() == Lexer.Type.GETCHARTK) {
                    stmt.add(new Leaf(now(), nowContent())); // getint / getchar
                    next(); //'('
                    stmt.add(new Leaf(now(), nowContent())); // '('
                    next(); // ) ; next
                    if (now() == Lexer.Type.RPARENT) {
                        stmt.add(new Leaf(now(), nowContent())); // ')'
                    } else { // ; next
                        isError = true;
                        back();
                        errorLine.add(lineNum());
                        errorType.add('j');
                    }
                    next();
                    if (now() == Lexer.Type.SEMICN) {
                        stmt.add(new Leaf(now(), nowContent())); // ';'
                    } else {
                        isError = true;
                        back();
                        errorLine.add(lineNum());
                        errorType.add('i');
                    }
                    next();
                } else {
                    stmt.add(Exp()); //Exp
                    if (now() == Lexer.Type.SEMICN) {
                        stmt.add(new Leaf(now(), nowContent())); // ';'
                    } else {
                        isError = true;
                        back();
                        errorLine.add(lineNum());
                        errorType.add('i');
                    }
                    next();
                }
                return stmt;
            } else {
                lexer.setPosition(record);
                stmt.add(Exp());
                if (now() == Lexer.Type.SEMICN) {
                    stmt.add(new Leaf(now(), nowContent())); // ;
                } else {
                    isError = true;
                    back();
                    errorLine.add(lineNum());
                    errorType.add('i');
                }
                next();
                return stmt;
            }
        }
        
        // Block
        else if (now() == Lexer.Type.LBRACE) {
            stmt.add(Block());
            return stmt;
        }
        
        // 'if'
        else if (now() == Lexer.Type.IFTK) {
            stmt.add(new Leaf(now(), nowContent())); // 'if'
            next(); // (
            stmt.add(new Leaf(now(), nowContent())); // (
            next(); //Cond
            stmt.add(Cond()); // Cond
            if (now() == Lexer.Type.RPARENT) {
                stmt.add(new Leaf(now(), nowContent())); // )
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('j');
            }
            next(); //Stmt
            stmt.add(Stmt()); //Stmt
            if (now() == Lexer.Type.ELSETK) {
                stmt.add(new Leaf(now(), nowContent())); // else
                next();
                stmt.add(Stmt());
            }
            return stmt;
        }
        
        // 'for'
        else if (now() == Lexer.Type.FORTK) {
            stmt.add(new Leaf(now(), nowContent())); // for
            next(); // (
            stmt.add(new Leaf(now(), nowContent())); // (
            next(); // ForStmt or ;
            if (now() != Lexer.Type.SEMICN) {
                stmt.add(ForStmt());
            }
            stmt.add(new Leaf(now(), nowContent())); // ;
            next(); // Cond or ;
            if (now() != Lexer.Type.SEMICN) {
                stmt.add(Cond());
            }
            stmt.add(new Leaf(now(), nowContent())); // ;
            next(); // ForStmt or )
            if (now() != Lexer.Type.RPARENT) {
                stmt.add(ForStmt());
            }
            stmt.add(new Leaf(now(), nowContent())); // )
            next(); // Stmt
            stmt.add(Stmt());
            return stmt;
        }
        
        // 'break' or 'continue'
        else if (now() == Lexer.Type.BREAKTK || now() == Lexer.Type.CONTINUETK) {
            stmt.add(new Leaf(now(), nowContent())); // break or continue
            next();
            if (now() == Lexer.Type.SEMICN) {
                stmt.add(new Leaf(now(), nowContent())); // ;
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('i');
            }
            next();
            return stmt;
        }
        
        // 'return'
        else if (now() == Lexer.Type.RETURNTK) {
            stmt.add(new Leaf(now(), nowContent())); // return
            next(); // exp or ; or error
            if (now() == Lexer.Type.IDENFR || now() == Lexer.Type.PLUS || now() == Lexer.Type.MINU
            || now() == Lexer.Type.NOT || now() == Lexer.Type.INTCON || now() == Lexer.Type.CHRCON
            || now() == Lexer.Type.LPARENT) {
                stmt.add(Exp());
            }
            if (now() == Lexer.Type.SEMICN) {
                stmt.add(new Leaf(now(), nowContent())); // ;
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('i');
            }
            next();
            //System.out.println(now().name());
            //stmt.postOrderTraversal();
            return stmt;
        }
        
        // 'printf'
        else if (now() == Lexer.Type.PRINTFTK) {
            stmt.add(new Leaf(now(), nowContent())); // printf
            next(); // (
            stmt.add(new Leaf(now(), nowContent())); // (
            next(); // StringConst
            stmt.add(new Leaf(now(), nowContent())); // StringConst
            next(); // , or ) or error
            while (now() == Lexer.Type.COMMA) {
                stmt.add(new Leaf(now(), nowContent())); // ,
                next(); // Exp
                stmt.add(Exp()); // Exp
            }
            if (now() == Lexer.Type.RPARENT) {
                stmt.add(new Leaf(now(), nowContent())); // )
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('j');
            }
            next(); // ; or error
            if (now() == Lexer.Type.SEMICN) {
                stmt.add(new Leaf(now(), nowContent())); // ;
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('i');
            }
            next();
            return stmt;
        }
        
        // [Exp]
        else {
            if (now() == Lexer.Type.IDENFR || now() == Lexer.Type.PLUS || now() == Lexer.Type.MINU
            || now() == Lexer.Type.NOT || now() == Lexer.Type.INTCON || now() == Lexer.Type.CHRCON
            || now() == Lexer.Type.LPARENT) {
                stmt.add(Exp());
            }
            if (now() == Lexer.Type.SEMICN) {
                stmt.add(new Leaf(now(), nowContent())); // ;
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('i');
            }
            next();
            return stmt;
        }
    }
    
    public Branch ForStmt() {
        Branch forStmt = new Branch("ForStmt");
        forStmt.add(LVal()); // LVal
        forStmt.add(new Leaf(now(), nowContent())); // =
        next(); // Exp
        forStmt.add(Exp());
        return forStmt;
    }
    
    public Branch Exp() {
        Branch exp = new Branch("Exp");
        exp.add(AddExp());
        return exp;
    }
    
    public Branch Cond() {
        Branch cond = new Branch("Cond");
        cond.add(LOrExp());
        return cond;
    }
    
    public Branch LVal() {
        Branch lVal = new Branch("LVal");
        lVal.add(new Leaf(now(), nowContent())); // Ident
        next(); // [ or next
        if (now() == Lexer.Type.LBRACK) {
            lVal.add(new Leaf(now(), nowContent())); // [
            next(); // Exp
            lVal.add(Exp());
            if (now() == Lexer.Type.RBRACK) {
                lVal.add(new Leaf(now(), nowContent())); // ]
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('k');
            }
            next();
        }
        return lVal;
    }
    
    public Branch PrimaryExp() {
        Branch primaryExp = new Branch("PrimaryExp");
        // (
        if (now() == Lexer.Type.LPARENT) {
            primaryExp.add(new Leaf(now(), nowContent())); // (
            next(); // Exp
            primaryExp.add(Exp()); // Exp
            if (now() == Lexer.Type.RPARENT) {
                primaryExp.add(new Leaf(now(), nowContent())); // )
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('j');
            }
            next();
            return primaryExp;
        }
        
        // LVal
        else if (now() == Lexer.Type.IDENFR) {
            primaryExp.add(LVal());
            return primaryExp;
        }
        
        // Number
        else if (now() == Lexer.Type.INTCON) {
            primaryExp.add(Number());
            return primaryExp;
        }
        
        // Character
        else {
            primaryExp.add(Character());
            return primaryExp;
        }
    }
    
    public Branch Number() {
        Branch number = new Branch("Number");
        number.add(new Leaf(now(), nowContent()));
        next();
        return number;
    }
    
    public Branch Character() {
        Branch character = new Branch("Character");
        character.add(new Leaf(now(), nowContent()));
        next();
        return character;
    }
    
    public Branch UnaryExp() {
        Branch unaryExp = new Branch("UnaryExp");
        if (now() == Lexer.Type.IDENFR && preRead() == Lexer.Type.LPARENT) {
            unaryExp.add(new Leaf(now(), nowContent())); // Ident
            next(); // (
            unaryExp.add(new Leaf(now(), nowContent())); // (
            next(); // FuncRParams or ) or error
            if (now() == Lexer.Type.IDENFR || now() == Lexer.Type.PLUS || now() == Lexer.Type.MINU
                    || now() == Lexer.Type.NOT || now() == Lexer.Type.INTCON || now() == Lexer.Type.CHRCON) {
                unaryExp.add(FuncRParams());
            }
            if (now() == Lexer.Type.RPARENT) {
                unaryExp.add(new Leaf(now(), nowContent()));
            } else {
                isError = true;
                back();
                errorLine.add(lineNum());
                errorType.add('j');
            }
            next();
            return unaryExp;
        }
        
        // UnaryOp UnaryExp
        else if (now() == Lexer.Type.PLUS || now() == Lexer.Type.MINU || now() == Lexer.Type.NOT) {
            unaryExp.add(UnaryOp()); //UnaryOp
            unaryExp.add(UnaryExp());
            return unaryExp;
        }
        
        // PrimaryExp
        else {
            unaryExp.add(PrimaryExp());
            return unaryExp;
        }
    }
    
    public Branch UnaryOp() {
        Branch unaryOp = new Branch("UnaryOp");
        unaryOp.add(new Leaf(now(), nowContent())); // + / - / !
        next();
        return unaryOp;
    }
    
    public Branch FuncRParams() {
        Branch funcRParams = new Branch("FuncRParams");
        funcRParams.add(Exp());
        while (now() == Lexer.Type.COMMA) {
            funcRParams.add(new Leaf(now(), nowContent())); // ,
            next(); // Exp
            funcRParams.add(Exp());
        }
        return funcRParams;
    }
    
    public Branch MulExp() {
        Branch mulExp = new Branch("MulExp");
        mulExp.add(UnaryExp());
        while (now() == Lexer.Type.MULT || now() == Lexer.Type.DIV || now() == Lexer.Type.MOD) {
            Branch newMulExp = new Branch("MulExp");
            newMulExp.add(mulExp);
            newMulExp.add(new Leaf(now(), nowContent())); // * / / / %
            next(); // UnaryExp
            newMulExp.add(UnaryExp());
            mulExp = newMulExp;
        }
        return mulExp;
    }
    
    public Branch AddExp() {
        Branch addExp = new Branch("AddExp");
        addExp.add(MulExp());
        while (now() == Lexer.Type.PLUS || now() == Lexer.Type.MINU) {
            Branch newAddExp = new Branch("AddExp");
            newAddExp.add(addExp);
            newAddExp.add(new Leaf(now(), nowContent())); // + / -
            next(); // MulExp
            newAddExp.add(MulExp()); // MulExp
            addExp = newAddExp;
        }
        return addExp;
    }
    
    public Branch RelExp() {
        Branch relExp = new Branch("RelExp");
        relExp.add(AddExp());
        while (now() == Lexer.Type.LSS || now() == Lexer.Type.LEQ
                || now() == Lexer.Type.GRE || now() == Lexer.Type.GEQ) {
            Branch newRelExp = new Branch("RelExp");
            newRelExp.add(relExp);
            newRelExp.add(new Leaf(now(), nowContent())); // > < >= <=
            next(); // AddExp
            newRelExp.add(AddExp());
            relExp = newRelExp;
        }
        return relExp;
    }
    
    public Branch EqExp() {
        Branch eqExp = new Branch("EqExp");
        eqExp.add(RelExp());
        while (now() == Lexer.Type.EQL || now() == Lexer.Type.NEQ) {
            Branch newEqExp = new Branch("EqExp");
            newEqExp.add(eqExp);
            newEqExp.add(new Leaf(now(), nowContent())); // == !=
            next(); // RelExp
            newEqExp.add(RelExp());
            eqExp = newEqExp;
        }
        return eqExp;
    }
    
    public Branch LAndExp() {
        Branch lAndExp = new Branch("LAndExp");
        lAndExp.add(EqExp());
        while (now() == Lexer.Type.AND) {
            Branch newLAndExp = new Branch("LAndExp");
            newLAndExp.add(lAndExp);
            newLAndExp.add(new Leaf(now(), nowContent())); // &&
            next(); // EqExp
            newLAndExp.add(EqExp());
            lAndExp = newLAndExp;
        }
        return lAndExp;
    }
    
    public Branch LOrExp() {
        Branch lOrExp = new Branch("LOrExp");
        lOrExp.add(LAndExp());
        while (now() == Lexer.Type.OR) {
            Branch newLOrExp = new Branch("LOrExp");
            newLOrExp.add(lOrExp);
            newLOrExp.add(new Leaf(now(), nowContent())); // ||
            next(); // LAndExp
            newLOrExp.add(LAndExp());
            lOrExp = newLOrExp;
        }
        return lOrExp;
    }
    
    public Branch ConstExp() {
        Branch constExp = new Branch("ConstExp");
        constExp.add(AddExp());
        return constExp;
    }
    
    private void next() {
        lexer.move();
    }
    
    private void back() {
        lexer.back();
    }
    
    private Lexer.Type now() {
        return lexer.getType();
    }
    
    private String nowContent() {
        return lexer.getContent();
    }
    
    private Lexer.Type preRead() {
        return lexer.getType(1);
    }
    
    private Lexer.Type prePreRead() {
        return lexer.getType(2);
    }
    
    private int lineNum() {
        return lexer.getLine();
    }
    
    public void testPrint() {
        if (!isError && lexer.getErrorLine().isEmpty()) {
            this.compUnit.postOrderTraversal();
        } else {
            ArrayList<Integer> lexerErrorLine = lexer.getErrorLine();
            ArrayList<Character> lexerErrorType = lexer.getErrorType();
            int i, j;
            for (i = 0, j = 0; i < errorLine.size() && j < lexerErrorLine.size(); ) {
                if (errorLine.get(i) <= lexerErrorLine.get(j)) {
                    System.out.println(errorLine.get(i) + " " + errorType.get(i));
                    i++;
                } else {
                    System.out.println(lexerErrorLine.get(j) + " " + lexerErrorType.get(j));
                    j++;
                }
            }
            if (i == errorLine.size()) {
                for ( ; j < lexerErrorLine.size(); j++) {
                    System.out.println(lexerErrorLine.get(j) + " " + lexerErrorType.get(j));
                }
            } else {
                for ( ; i < errorLine.size(); i++) {
                    System.out.println(errorLine.get(i) + " " + errorType.get(i));
                }
            }
        }
    }
    
    public void print() {
        try {
            System.out.println("当前工作目录：" + new File(".").getAbsolutePath());
            if (!isError && lexer.getErrorLine().isEmpty()) {
                FileWriter fileWriter = new FileWriter("./parser.txt");
                BufferedWriter writer = new BufferedWriter(fileWriter);
                compUnit.postOrderTraversal(writer);
                writer.close();
            } else {
                FileWriter fileWriter = new FileWriter("./error.txt");
                BufferedWriter writer = new BufferedWriter(fileWriter);
                ArrayList<Integer> lexerErrorLine = lexer.getErrorLine();
                ArrayList<Character> lexerErrorType = lexer.getErrorType();
                int i, j;
                for (i = 0, j = 0; i < errorLine.size() && j < lexerErrorLine.size(); ) {
                    
                    if (errorLine.get(i) <= lexerErrorLine.get(j)) {
                        System.out.println("***********");
                        writer.write(errorLine.get(i).toString());
                        writer.write(" ");
                        writer.write(errorType.get(i));
                        writer.newLine();
                        i++;
                    } else {
                        writer.write(lexerErrorLine.get(j).toString());
                        writer.write(" ");
                        writer.write(lexerErrorType.get(j));
                        writer.newLine();
                        j++;
                    }
                }
                if (i == errorLine.size()) {
                    for ( ; j < lexerErrorLine.size(); j++) {
                        writer.write(lexerErrorLine.get(j).toString());
                        writer.write(" ");
                        writer.write(lexerErrorType.get(j));
                        writer.newLine();
                    }
                } else {
                    for ( ; i < errorLine.size(); i++) {
                        writer.write(errorLine.get(i).toString());
                        writer.write(" ");
                        writer.write(errorType.get(i));
                        writer.newLine();
                    }
                }
                writer.close();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
