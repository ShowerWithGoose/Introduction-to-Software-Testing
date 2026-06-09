

package frontend;

import java.util.ArrayList;
import java.util.HashSet;

import static frontend.ErrList.errList;

public class Parser {
    ArrayList<Symbol> symbolList;
    FirstSet firstSet;
    int pt;
    boolean shouldPrint = true;

    public Parser(ArrayList<Symbol> symbolList) {
        this.symbolList = symbolList;
        pt = 0;
        firstSet = new FirstSet();
        CompUnit();
    }

    private Symbol nextSymbol() {
        if (pt == symbolList.size()) {
            return new Symbol(SymbolType.None,"",-1);
        } else {
            Symbol ans = symbolList.get(pt);
            ans.print();
            pt++;
            return ans;
        }
    }

    private Symbol peekSymbol(int step) {
        if(pt + step -1 >= symbolList.size()) {
            return new Symbol(SymbolType.None,"",-1);
        } else {
            return symbolList.get(pt + step - 1);
        }
    }

    private void rollBack(int step) {
        if(pt - step >= 0) {
            pt -= step;
        } else {
            error();
        }
    }

    private int getLineNum() {
        if(pt == 0) {
            return 1;
        } else {
            return symbolList.get(pt - 1).getLineNum();
        }

    }

    private void error() {
//        errList.add(new ErrInfo(1,'n'));
//        throw new RuntimeException();
//        pt = symbolList.size();
    }

    private boolean isEOF() {
        return pt >= symbolList.size();
    }

    private void CompUnit() {
        // CompUnit → {Decl} {FuncDef} MainFuncDef
        if(isEOF()) { return; }
        // {Decl}
        while(true) {
            if (peekSymbol(1).getType() == SymbolType.CONSTTK) {
                Decl();
            } else if(peekSymbol(3).getType() != SymbolType.LPARENT && !isEOF()) {
                Decl();
            } else {
                break;
            }
        }
        // {FuncDef}
        while(true) {
            if(peekSymbol(2).getType() != SymbolType.MAINTK && !isEOF()) {
                FuncDef();
            } else {
                break;
            }
        }
        //MainFuncDef
        MainFuncDef();
        if(shouldPrint) System.out.println("<CompUnit>");
    }

    private void Decl() {
        // Decl → ConstDecl | VarDecl
        if(isEOF()) { return; }
        // ConstDecl
        if(peekSymbol(1).getType() == SymbolType.CONSTTK) {
            ConstDecl();
        } else {
            VarDecl();
        }
//        if(shouldPrint) System.out.println("<Decl>");
    }

    private void ConstDecl() {
        // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        if(isEOF()) { return; }
        if (nextSymbol().getType() != SymbolType.CONSTTK) {
            error();
        }
        BType();
        ConstDef();
        while(peekSymbol(1).getType() == SymbolType.COMMA) {
            if (nextSymbol().getType() != SymbolType.COMMA) {
                error();
            }
            ConstDef();
        }
        if(nextSymbol().getType() != SymbolType.SEMICN) {
            rollBack(1);
            errList.add(new ErrInfo(getLineNum(), 'i'));
//            error();
        }
        if(shouldPrint) System.out.println("<ConstDecl>");
    }

    private void BType() {
        // BType → 'int' | 'char'
        if(isEOF()) { return; }
        if(peekSymbol(1).getType() == SymbolType.INTTK) {
            if(nextSymbol().getType() != SymbolType.INTTK) {
                error();
            }
        } else {
            if(nextSymbol().getType() != SymbolType.CHARTK) {
                error();
            }
        }
//        if(shouldPrint) System.out.println("<BType>");
    }

    private void ConstDef() {
        // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        if(isEOF()) { return; }
        if(nextSymbol().getType() != SymbolType.IDENFR) {
            error();
        }
        if(peekSymbol(1).getType() == SymbolType.LBRACK) {
            if(nextSymbol().getType() != SymbolType.LBRACK) {
                error();
            }
            ConstExp();
            if(nextSymbol().getType() != SymbolType.RBRACK) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'k'));
//                error();
            }
        }
        if(nextSymbol().getType() != SymbolType.ASSIGN) {
            error();
        }
        ConstInitVal();
        if(shouldPrint) System.out.println("<ConstDef>");
    }

    private void ConstInitVal() {
        //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        if(isEOF()) { return; }
        if (peekSymbol(1).getType() == SymbolType.LBRACE) {
            if(nextSymbol().getType() != SymbolType.LBRACE) {
                error();
            }
            if(peekSymbol(1).getType() != SymbolType.RBRACE && !isEOF()) {
                ConstExp();
                while(peekSymbol(1).getType() == SymbolType.COMMA) {
                    if(nextSymbol().getType() != SymbolType.COMMA) {
                        error();
                    }
                    ConstExp();
                }
            }
            if(nextSymbol().getType() != SymbolType.RBRACE) {
                error();
            }
        } else if(peekSymbol(1).getType() == SymbolType.STRCON) {
            if(nextSymbol().getType() != SymbolType.STRCON) {
                error();
            }
        } else {
            ConstExp();
        }
        if(shouldPrint) System.out.println("<ConstInitVal>");
    }

    private void VarDecl() {
        // VarDecl → BType VarDef { ',' VarDef } ';'
        if(isEOF()) { return; }
        BType();
        VarDef();
        while(peekSymbol(1).getType() == SymbolType.COMMA) {
            if(nextSymbol().getType() != SymbolType.COMMA) {
                error();
            }
            VarDef();
        }
        if(nextSymbol().getType() != SymbolType.SEMICN) {
            rollBack(1);
            errList.add(new ErrInfo(getLineNum(), 'i'));
//            error();
        }
        if(shouldPrint) System.out.println("<VarDecl>");
    }

    private void VarDef() {
        // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        if(isEOF()) { return; }
        if(nextSymbol().getType() != SymbolType.IDENFR) {
            error();
        }
        if(peekSymbol(1).getType() == SymbolType.LBRACK) {
            if(nextSymbol().getType() != SymbolType.LBRACK) {
                error();
            }
            ConstExp();
            if(nextSymbol().getType() != SymbolType.RBRACK) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'k'));
//                error();
            }
        }

        if(peekSymbol(1).getType() == SymbolType.ASSIGN) {
            if(nextSymbol().getType() != SymbolType.ASSIGN) {
                error();
            }
            InitVal();
        }
        if(shouldPrint) System.out.println("<VarDef>");
    }

    private void InitVal() {
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        if(isEOF()) { return; }
        if(peekSymbol(1).getType() == SymbolType.LBRACE) {
            if(nextSymbol().getType() != SymbolType.LBRACE) {
                error();
            }
            if(peekSymbol(1).getType() != SymbolType.RBRACE && !isEOF()) {
                Exp();
                while(peekSymbol(1).getType() == SymbolType.COMMA) {
                    if(nextSymbol().getType() != SymbolType.COMMA) {
                        error();
                    }
                    Exp();
                }
            }
            if(nextSymbol().getType() != SymbolType.RBRACE) {
                error();
            }
        } else if(peekSymbol(1).getType() == SymbolType.STRCON) {
            if(nextSymbol().getType() != SymbolType.STRCON) {
                error();
            }
        } else {
            Exp();
        }
        if(shouldPrint) System.out.println("<InitVal>");
    }

    private void FuncDef() {
        // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        if(isEOF()) { return; }
        FuncType();
        if(nextSymbol().getType() != SymbolType.IDENFR) {
            error();
        }
        if(nextSymbol().getType() != SymbolType.LPARENT) {
            error();
        }
        if(firstSet.FuncFParamsFirst.contains(peekSymbol(1).getType()) && !isEOF()) {
            FuncFParams();
        }
        if(nextSymbol().getType() != SymbolType.RPARENT) {
            rollBack(1);
            errList.add(new ErrInfo(getLineNum(), 'j'));
//            error();
        }
        Block();
        if(shouldPrint) System.out.println("<FuncDef>");
    }

    private void  MainFuncDef() {
        //  MainFuncDef → 'int' 'main' '(' ')' Block
        if(isEOF()) { return; }
        if(nextSymbol().getType() != SymbolType.INTTK) {
            error();
        }
        if(nextSymbol().getType() != SymbolType.MAINTK) {
            error();
        }
        if(nextSymbol().getType() != SymbolType.LPARENT) {
            error();
        }
        if(nextSymbol().getType() != SymbolType.RPARENT) {
            rollBack(1);
            errList.add(new ErrInfo(getLineNum(), 'j'));
//            error();
        }
        Block();
        if(shouldPrint) System.out.println("<MainFuncDef>");
    }

    private void FuncType() {
        // FuncType → 'void' | 'int' | 'char'
        if(isEOF()) { return; }
        if (peekSymbol(1).getType() == SymbolType.VOIDTK) {
            if (nextSymbol().getType() != SymbolType.VOIDTK) {
                error();
            }
        } else if (peekSymbol(1).getType() == SymbolType.INTTK) {
            if (nextSymbol().getType() != SymbolType.INTTK) {
                error();
            }
        } else {
            if (nextSymbol().getType() != SymbolType.CHARTK) {
                error();
            }
        }
        if(shouldPrint) System.out.println("<FuncType>");
    }

    private void FuncFParams() {
        // FuncFParams → FuncFParam { ',' FuncFParam }
        if(isEOF()) { return; }
        FuncFParam();
        while(peekSymbol(1).getType() == SymbolType.COMMA) {
            if(nextSymbol().getType() != SymbolType.COMMA) {
                error();
            }
            FuncFParam();
        }
        if(shouldPrint) System.out.println("<FuncFParams>");
    }

    private void  FuncFParam() {
        // FuncFParam → BType Ident ['[' ']']
        if(isEOF()) { return; }
        BType();
        if(nextSymbol().getType() != SymbolType.IDENFR) {
            error();
        }
        if(peekSymbol(1).getType() == SymbolType.LBRACK) {
            if(nextSymbol().getType() != SymbolType.LBRACK) {
                error();
            }
            if(nextSymbol().getType() != SymbolType.RBRACK) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'k'));
//                error();
            }
        }
        if(shouldPrint) System.out.println("<FuncFParam>");
    }

    private void Block() {
        // Block → '{' { BlockItem } '}'
        if(isEOF()) { return; }
        if(nextSymbol().getType() != SymbolType.LBRACE) {
            error();
        }
        while (peekSymbol(1).getType() != SymbolType.RBRACE && !isEOF()) {
            BlockItem();
        }
        if(nextSymbol().getType() != SymbolType.RBRACE) {
            error();
        }
        if(shouldPrint) System.out.println("<Block>");
    }

    private void BlockItem() {
        // BlockItem → Decl | Stmt
        if(isEOF()) { return; }
        if(peekSymbol(1).getType() == SymbolType.CONSTTK
        || peekSymbol(1).getType() == SymbolType.INTTK
        || peekSymbol(1).getType() == SymbolType.CHARTK) {
            Decl();
        } else {
            Stmt();
        }
//        if(shouldPrint) System.out.println("<BlockItem>");
    }

    private void Stmt() {
        //Stmt → LVal '=' Exp ';'
        // | [Exp] ';'
        // | Block
        // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        // | 'break' ';' | 'continue' ';'
        // | 'return' [Exp] ';'
        // | LVal '=' 'getint''('')'';'
        // | LVal '=' 'getchar''('')'';'
        // | 'printf''('StringConst {','Exp}')'';'
        if(isEOF()) { return; }
        if(peekSymbol(1).getType() == SymbolType.SEMICN) { //;
            if(nextSymbol().getType() != SymbolType.SEMICN) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'i'));
//                        error();
            }
        } else if(peekSymbol(1).getType() == SymbolType.LBRACE) {
            Block();
        } else if(peekSymbol(1).getType() == SymbolType.IFTK) { //if
            if(nextSymbol().getType() != SymbolType.IFTK) {
                error();
            }
            if(nextSymbol().getType() != SymbolType.LPARENT) {
                error();
            }
            Cond();
            if(nextSymbol().getType() != SymbolType.RPARENT) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'j'));
//                error();
            }
            Stmt();
            if(peekSymbol(1).getType() == SymbolType.ELSETK) {
                if(nextSymbol().getType() != SymbolType.ELSETK) {
                    error();
                }
                Stmt();
            }
        } else if(peekSymbol(1).getType() == SymbolType.FORTK) { // for
            if(nextSymbol().getType() != SymbolType.FORTK) {
                error();
            }
            if(nextSymbol().getType() != SymbolType.LPARENT) {
                error();
            }
            if(peekSymbol(1).getType() != SymbolType.SEMICN && !isEOF()) {
                ForStmt();
            }
            if(nextSymbol().getType() != SymbolType.SEMICN) {
                error();
            }
            if(peekSymbol(1).getType() != SymbolType.SEMICN && !isEOF()) {
                Cond();
            }
            if(nextSymbol().getType() != SymbolType.SEMICN) {
                error();
            }
            if(peekSymbol(1).getType() != SymbolType.RPARENT && !isEOF()) {
                ForStmt();
            }
            if(nextSymbol().getType() != SymbolType.RPARENT) {
                error();
            }
            Stmt();
        } else if (peekSymbol(1).getType() == SymbolType.BREAKTK) { //break
            if(nextSymbol().getType() != SymbolType.BREAKTK) {
                error();
            }
            if(nextSymbol().getType() != SymbolType.SEMICN) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'i'));
//                error();
            }
        } else if (peekSymbol(1).getType() == SymbolType.CONTINUETK) { //continue
            if(nextSymbol().getType() != SymbolType.CONTINUETK) {
                error();
            }
            if(nextSymbol().getType() != SymbolType.SEMICN) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'i'));
//                error();
            }
        } else if (peekSymbol(1).getType() == SymbolType.RETURNTK) { // return
            if (nextSymbol().getType() != SymbolType.RETURNTK) {
                error();
            }
            if(firstSet.ExpFirst.contains(peekSymbol(1).getType())&& !isEOF()) {
                Exp();
            }
            if (nextSymbol().getType() != SymbolType.SEMICN) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'i'));
//                error();
            }
        } else if(peekSymbol(1).getType() == SymbolType.PRINTFTK) { // printf
            if (nextSymbol().getType() != SymbolType.PRINTFTK) {
                error();
            }
            if (nextSymbol().getType() != SymbolType.LPARENT) {
                error();
            }
            if (nextSymbol().getType() != SymbolType.STRCON) {
                error();
            }
            while(peekSymbol(1).getType() == SymbolType.COMMA) {
                if (nextSymbol().getType() != SymbolType.COMMA) {
                    error();
                }
                Exp();
            }
            if (nextSymbol().getType() != SymbolType.RPARENT) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'j'));
//                error();
            }
            if (nextSymbol().getType() != SymbolType.SEMICN) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'i'));
//                error();
            }
        } else {
            // check LVal
            boolean isLVal = false;
            int curLineNum = peekSymbol(1).getLineNum();
            for (int i = 1;;i++) {
                if(peekSymbol(i).getType() == SymbolType.ASSIGN) {
                    isLVal = true;
                    break;
                }
                if(peekSymbol(i).getType() == SymbolType.SEMICN) {
                    break;
                }
                if(peekSymbol(i).getType() == SymbolType.None) {
                    break;
                }
            }
            // Exp
            if(!isLVal) { // exp
                Exp();
                if(nextSymbol().getType() != SymbolType.SEMICN) {
                    rollBack(1);
                    errList.add(new ErrInfo(getLineNum(), 'i'));
//                    error();
                }
            } else {
                LVal();
                if (nextSymbol().getType() != SymbolType.ASSIGN) {
                    error();
                }
                if(peekSymbol(1).getType() == SymbolType.GETCHARTK) { // getchar
                    if(nextSymbol().getType() != SymbolType.GETCHARTK) {
                        error();
                    }
                    if(nextSymbol().getType() != SymbolType.LPARENT) {
                        error();
                    }
                    if(nextSymbol().getType() != SymbolType.RPARENT) {
                        rollBack(1);
                        errList.add(new ErrInfo(getLineNum(), 'j'));
//                        error();
                    }
                    if(nextSymbol().getType() != SymbolType.SEMICN) {
                        rollBack(1);
                        errList.add(new ErrInfo(getLineNum(), 'i'));
//                        error();
                    }
                } else if(peekSymbol(1).getType() == SymbolType.GETINTTK) { // getint
                    if(nextSymbol().getType() != SymbolType.GETINTTK) {
                        error();
                    }
                    if(nextSymbol().getType() != SymbolType.LPARENT) {
                        error();
                    }
                    if(nextSymbol().getType() != SymbolType.RPARENT) {
                        rollBack(1);
                        errList.add(new ErrInfo(getLineNum(), 'j'));
//                        error();
                    }
                    if(nextSymbol().getType() != SymbolType.SEMICN) {
                        rollBack(1);
                        errList.add(new ErrInfo(getLineNum(), 'i'));
//                        error();
                    }
                } else { // LVal = exp
                    Exp();
                    if(nextSymbol().getType() != SymbolType.SEMICN) {
                        rollBack(1);
                        errList.add(new ErrInfo(getLineNum(), 'i'));
//                        error();
                    }
                }
            }
        }
        if(shouldPrint) System.out.println("<Stmt>");
    }

    private void ForStmt() {
        // ForStmt → LVal '=' Exp
        if(isEOF()) { return; }
        LVal();
        if(nextSymbol().getType() != SymbolType.ASSIGN) {
            error();
        }
        Exp();
        if(shouldPrint) System.out.println("<ForStmt>");
    }

    private void Exp() {
        // Exp → AddExp
        if(isEOF()) { return; }
        AddExp();
        if(shouldPrint) System.out.println("<Exp>");
    }

    private void Cond() {
        // Cond → LOrExp
        if(isEOF()) { return; }
        LOrExp();
        if(shouldPrint) System.out.println("<Cond>");
    }

    private void LVal() {
        // LVal → Ident ['[' Exp ']']
        if(isEOF()) { return; }
        if(nextSymbol().getType() != SymbolType.IDENFR) {
            error();
        }
        if(peekSymbol(1).getType() == SymbolType.LBRACK) {
            if(nextSymbol().getType() != SymbolType.LBRACK) {
                error();
            }
            Exp();
            if(nextSymbol().getType() != SymbolType.RBRACK) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'k'));
//                error();
            }
        }
        if(shouldPrint) System.out.println("<LVal>");
    }

    private void PrimaryExp() { // include  Number & Character
        // PrimaryExp → '(' Exp ')' | LVal | Number | Character
        if(isEOF()) { return; }
        if(peekSymbol(1).getType() == SymbolType.LPARENT) {
            if(nextSymbol().getType() != SymbolType.LPARENT) {
                error();
            }
            Exp();
            if(nextSymbol().getType() != SymbolType.RPARENT) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'j'));
//                error();
            }
        } else if(peekSymbol(1).getType() == SymbolType.INTCON) {
            Number();
        } else if(peekSymbol(1).getType() == SymbolType.CHRCON) {
            Character();
        } else if (firstSet.LValFirst.contains(peekSymbol(1).getType())){
            LVal();
        }
        if(shouldPrint) System.out.println("<PrimaryExp>");
    }

    private void Number() {
        if(isEOF()) { return; }
        if(nextSymbol().getType() != SymbolType.INTCON) {
            error();
        }
        if(shouldPrint) System.out.println("<Number>");
    }

    private void Character() {
        if(isEOF()) { return; }
        if(nextSymbol().getType() != SymbolType.CHRCON) {
            error();
        }
        if(shouldPrint) System.out.println("<Character>");
    }

    private void UnaryExp() {
        // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        if(isEOF()) { return; }
        if(peekSymbol(1).getType() == SymbolType.IDENFR && peekSymbol(2).getType() == SymbolType.LPARENT) {
            if(nextSymbol().getType() != SymbolType.IDENFR) {
                error();
            }
            if(nextSymbol().getType() != SymbolType.LPARENT) {
                error();
            }
            if(firstSet.FuncRParamsFirst.contains(peekSymbol(1).getType())) {
                FuncRParams();
            }
            if(nextSymbol().getType() != SymbolType.RPARENT) {
                rollBack(1);
                errList.add(new ErrInfo(getLineNum(), 'j'));
//                error();
            }
        } else if(firstSet.UnaryOpFirst.contains(peekSymbol(1).getType())) {
            UnaryOp();
            UnaryExp();
        } else if (firstSet.PrimaryExpFirst.contains(peekSymbol(1).getType())){
            PrimaryExp();
        }
        if(shouldPrint) System.out.println("<UnaryExp>");
    }

    private void UnaryOp() {
        // UnaryOp → '+' | '−' | '!'
        if(isEOF()) { return; }
        if(peekSymbol(1).getType() == SymbolType.PLUS) {
            if(nextSymbol().getType() != SymbolType.PLUS) {
                error();
            }
        } else if(peekSymbol(1).getType() == SymbolType.MINU) {
            if(nextSymbol().getType() != SymbolType.MINU) {
                error();
            }
        } else {
            if(nextSymbol().getType() != SymbolType.NOT) {
                error();
            }
        }
        if(shouldPrint) System.out.println("<UnaryOp>");
    }

    private void FuncRParams() {
        if(isEOF()) { return; }
        Exp();
        while (peekSymbol(1).getType() == SymbolType.COMMA) {
            if(nextSymbol().getType() != SymbolType.COMMA) {
                error();
            }
            Exp();
        }
        if(shouldPrint) System.out.println("<FuncRParams>");
    }

    public void MulExp() {
        //  MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        if(isEOF()) { return; }
        UnaryExp();
        if(shouldPrint) System.out.println("<MulExp>");
        while (true) {
            if(peekSymbol(1).getType() == SymbolType.MULT) {
                if(nextSymbol().getType() != SymbolType.MULT) {
                    error();
                }
                UnaryExp();
                if(shouldPrint) System.out.println("<MulExp>");
                continue;
            }
            if(peekSymbol(1).getType() == SymbolType.DIV) {
                if(nextSymbol().getType() != SymbolType.DIV) {
                    error();
                }
                UnaryExp();
                if(shouldPrint) System.out.println("<MulExp>");
                continue;
            }
            if(peekSymbol(1).getType() == SymbolType.MOD) {
                if(nextSymbol().getType() != SymbolType.MOD) {
                    error();
                }
                UnaryExp();
                if(shouldPrint) System.out.println("<MulExp>");
                continue;
            }
            break;
        }

    }

    private void AddExp() {
        // AddExp → MulExp | AddExp ('+' | '−') MulExp
        if(isEOF()) { return; }
        MulExp();
        if(shouldPrint) System.out.println("<AddExp>");
        while(true) {
            if(peekSymbol(1).getType() == SymbolType.PLUS) {
                if(nextSymbol().getType() != SymbolType.PLUS) {
                    error();
                }
                MulExp();
                if(shouldPrint) System.out.println("<AddExp>");
                continue;
            }
            if(peekSymbol(1).getType() == SymbolType.MINU) {
                if(nextSymbol().getType() != SymbolType.MINU) {
                    error();
                }
                MulExp();
                if(shouldPrint) System.out.println("<AddExp>");
                continue;
            }
            break;
        }

    }

    private void RelExp() {
        // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        if(isEOF()) { return; }
        AddExp();
        if(shouldPrint) System.out.println("<RelExp>");
        while(true) {
            if(peekSymbol(1).getType() == SymbolType.LSS) {
                if(nextSymbol().getType() != SymbolType.LSS) {
                    error();
                }
                AddExp();
                if(shouldPrint) System.out.println("<RelExp>");
                continue;
            }
            if(peekSymbol(1).getType() == SymbolType.GRE) {
                if(nextSymbol().getType() != SymbolType.GRE) {
                    error();
                }
                AddExp();
                if(shouldPrint) System.out.println("<RelExp>");
                continue;
            }
            if(peekSymbol(1).getType() == SymbolType.LEQ) {
                if(nextSymbol().getType() != SymbolType.LEQ) {
                    error();
                }
                AddExp();
                if(shouldPrint) System.out.println("<RelExp>");
                continue;
            }
            if(peekSymbol(1).getType() == SymbolType.GEQ) {
                if(nextSymbol().getType() != SymbolType.GEQ) {
                    error();
                }
                AddExp();
                if(shouldPrint) System.out.println("<RelExp>");
                continue;
            }
            break;
        }

    }

    private void EqExp() {
        // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        if(isEOF()) { return; }
        RelExp();
        if(shouldPrint) System.out.println("<EqExp>");
        while(true) {
            if(peekSymbol(1).getType() == SymbolType.EQL) {
                if(nextSymbol().getType() != SymbolType.EQL) {
                    error();
                }
                RelExp();
                if(shouldPrint) System.out.println("<EqExp>");
                continue;
            }
            if(peekSymbol(1).getType() == SymbolType.NEQ) {
                if(nextSymbol().getType() != SymbolType.NEQ) {
                    error();
                }
                RelExp();
                if(shouldPrint) System.out.println("<EqExp>");
                continue;
            }
            break;
        }

    }

    private void LAndExp() {
        // LAndExp → EqExp | LAndExp '&&' EqExp
        if(isEOF()) { return; }
        EqExp();
        if(shouldPrint) System.out.println("<LAndExp>");
        while(true) {
            if(peekSymbol(1).getType() == SymbolType.AND) {
                if(nextSymbol().getType() != SymbolType.AND) {
                    error();
                }
                EqExp();
                if(shouldPrint) System.out.println("<LAndExp>");
                continue;
            }
            break;
        }

    }

    private void LOrExp() {
        // LOrExp → LAndExp | LOrExp '||' LAndExp
        if(isEOF()) { return; }
        LAndExp();
        if(shouldPrint) System.out.println("<LOrExp>");
        while(true) {
            if(peekSymbol(1).getType() == SymbolType.OR) {
                if(nextSymbol().getType() != SymbolType.OR) {
                    error();
                }
                LAndExp();
                if(shouldPrint) System.out.println("<LOrExp>");
                continue;
            }
            break;
        }
    }

    private void ConstExp() {
        if(isEOF()) { return; }
        AddExp();
        if(shouldPrint) System.out.println("<ConstExp>");
    }


    // FIRST SET



}
