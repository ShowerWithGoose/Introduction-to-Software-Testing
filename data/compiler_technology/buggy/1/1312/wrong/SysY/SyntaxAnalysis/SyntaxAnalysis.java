package SysY.SyntaxAnalysis;

import SysY.Error.theError;
import SysY.LexicAnalysis.Token;
import SysY.LexicAnalysis.TokenKey;

import java.util.ArrayList;

public class SyntaxAnalysis {
    private ArrayList<Token> tokenList;
    public ArrayList<String> syntaxArrayList = new ArrayList<>();
    private int cur;

    public ArrayList<theError> SyntaxErrorList=new ArrayList<>();
    private ASTnode CompUnit;
    private ASTnode Curnode;
    private ASTnode tempnode;

    public SyntaxAnalysis(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        cur = -1;//cur从-1开始，这样对于每种情况每次都判断isNext
    }

    private Token nextToken(int i) {
        if (this.cur < tokenList.size() - i) {
            return this.tokenList.get(cur + i);
        } else {
            return null;
        }
    }

    private boolean isNext(int i, TokenKey tokenKey) {
        if (nextToken(i) == null) {
            return false;
        } else {
            return nextToken(i).getTokenKey() == tokenKey;
        }
    }

    private Token getNextToken(String s) {//该方法是唯一使得cur增加的方法
        if (cur + 1 < tokenList.size()) {
            if (s.equals(tokenList.get(cur + 1).getTokenString())
                    || (s.equals("ident") && isNext(1, TokenKey.IDENFR))
                    || (s.equals("intConst") && isNext(1, TokenKey.INTCON))
                    || (s.equals("charConst") && isNext(1, TokenKey.CHRCON))
                    || s.equals("formatString") && isNext(1, TokenKey.STRCON)) {
                this.syntaxArrayList.add(tokenList.get(cur + 1).getTokenKey() + " " + tokenList.get(cur + 1).getTokenString());
                cur += 1;//使得cur增加的地方
                return tokenList.get(cur);
            } else {
                return null;
            }
        }
        return null;
    }

    private boolean isNextLValAssignGetintOrGetchar() {
        int i = 1;
        if (isNext(i, TokenKey.IDENFR)) {
            i++;
            if (isNext(i, TokenKey.LBRACK)) {
                i++;
                while (!isNext(i, TokenKey.ASSIGN) && !isNext(i, TokenKey.SEMICN) && cur + i < tokenList.size()) {
                    if (isNext(i, TokenKey.IDENFR) || isNext(i, TokenKey.INTCON)) {
                        if (isNext(i + 1, TokenKey.IDENFR)
                                || isNext(i + 1, TokenKey.INTCON)
                                || isNext(i + 1, TokenKey.INTTK)
                                || isNext(i+1,TokenKey.CHARTK)
                                || isNext(i + 1, TokenKey.CONSTTK)
                                || isNext(i + 1, TokenKey.INTCON)
                                || isNext(i + 1, TokenKey.LBRACE)
                                || isNext(i + 1, TokenKey.IFTK)
                                || isNext(i + 1, TokenKey.FORTK)
                                || isNext(i + 1, TokenKey.BREAKTK)
                                || isNext(i + 1, TokenKey.CONTINUETK)
                                || isNext(i + 1, TokenKey.RETURNTK)
                                || isNext(i + 1, TokenKey.PRINTFTK)) {
                            return false;
                        }
                    }
                    i++;
                }
                if (isNext(i, TokenKey.SEMICN)) {
                    return false;
                }
            }
            if (isNext(i, TokenKey.ASSIGN)) {
                i++;
                if (isNext(i, TokenKey.GETINTTK) || isNext(i, TokenKey.GETCHARTK)) {
                    return true;
                }
            }
            return false;
        } else {
            return false;
        }
    }

    private boolean isNextLValAssignExp() {
        int i = 1;
        if (isNext(i, TokenKey.IDENFR)) {
            i++;
            if (isNext(i, TokenKey.LBRACK)) {
                i++;
                while (!isNext(i, TokenKey.ASSIGN) && !isNext(i, TokenKey.SEMICN) && cur + i < tokenList.size()) {
                    if (isNext(i, TokenKey.IDENFR) || isNext(i, TokenKey.INTCON)) {
                        if (isNext(i + 1, TokenKey.IDENFR)
                                || isNext(i + 1, TokenKey.INTCON)
                                || isNext(i + 1, TokenKey.INTTK)
                                ||isNext(i+1,TokenKey.CHARTK)
                                || isNext(i + 1, TokenKey.CONSTTK)
                                || isNext(i + 1, TokenKey.INTCON)
                                || isNext(i + 1, TokenKey.LBRACE)
                                || isNext(i + 1, TokenKey.IFTK)
                                || isNext(i + 1, TokenKey.FORTK)
                                || isNext(i + 1, TokenKey.BREAKTK)
                                || isNext(i + 1, TokenKey.CONTINUETK)
                                || isNext(i + 1, TokenKey.RETURNTK)
                                || isNext(i + 1, TokenKey.PRINTFTK)) {
                            return false;
                        }
                    }
                    i++;
                }
                if (isNext(i, TokenKey.SEMICN)) {
                    return false;
                }
            }
            if (isNext(i, TokenKey.ASSIGN)) {
                return true;
            }
            return false;
        } else {
            return false;
        }
    }

    private boolean isNextExp() {
        if (isNext(1, TokenKey.IDENFR)
                || isNext(1, TokenKey.LPARENT)
                || isNext(1, TokenKey.PLUS)
                || isNext(1, TokenKey.MINU)
                || isNext(1, TokenKey.NOT)
                || isNext(1, TokenKey.INTCON)
                || isNext(1,TokenKey.CHRCON)
        ) {
            return true;
        } else {
            return false;
        }
    }

    public void analysis() {
        CompUnit = new ASTnode("CompUnit", null);
        analysisCompUnit(CompUnit);
    }

    public void analysisCompUnit(ASTnode CompUnit) {
        Curnode = CompUnit;
        if (isNext(1, TokenKey.CONSTTK)
                || ((isNext(1, TokenKey.INTTK)||isNext(1, TokenKey.CHARTK))
                && isNext(2, TokenKey.IDENFR)
                && !isNext(3, TokenKey.LPARENT))) {
            tempnode = new ASTnode("Decl", CompUnit);
            CompUnit.sons.add(tempnode);
            analyseDecl(tempnode);//走到Decl的最后，isNext()是FuncDef
        }

        if (isNext(1, TokenKey.VOIDTK)
                || ((isNext(1, TokenKey.INTTK)||isNext(1, TokenKey.CHARTK))
                && isNext(2, TokenKey.IDENFR)
                && isNext(3, TokenKey.LPARENT))) {
            tempnode = new ASTnode("FuncDef", CompUnit);
            CompUnit.sons.add(tempnode);
            analyseFuncDef(tempnode);
        }
        if (isNext(1, TokenKey.INTTK)) {
            tempnode = new ASTnode("MainFuncDef", CompUnit);
            CompUnit.sons.add(tempnode);
            analyseMainFuncDef(tempnode);

        }
        this.syntaxArrayList.add("<" + "CompUnit" + ">");
    }

    private void analyseDecl(ASTnode Decl) {
        Curnode = Decl;
        while (isNext(1, TokenKey.CONSTTK)
                || ((isNext(1, TokenKey.INTTK)||isNext(1, TokenKey.CHARTK))
                && isNext(2, TokenKey.IDENFR)
                && !isNext(3, TokenKey.LPARENT))) {//这里循环遍历了，把所有的都弄完
            if (isNext(1, TokenKey.CONSTTK)) {
                tempnode = new ASTnode("ConstDecl", Curnode);
                Curnode.sons.add(tempnode);
                analyseConstDecl(tempnode);
            } else if (isNext(1, TokenKey.INTTK)||isNext(1, TokenKey.CHARTK)) {
                tempnode = new ASTnode("VarDecl", Curnode);
                Curnode.sons.add(tempnode);
                analyseVarDecl(tempnode);
            } else {
                System.out.println("Decl wrong!");
            }


        }

        //this.syntaxList.add("<" + SysY.SyntaxAnalysis.SyntaxType.Decl + ">");

    }

    private void analyseConstDecl(ASTnode ConstDecl) {
        Curnode = ConstDecl;
        if (getNextToken("const") != null) {//前进
            tempnode = new ASTnode("const", Curnode);
            Curnode.sons.add(tempnode);
        }
        if (isNext(1, TokenKey.INTTK) || isNext(1, TokenKey.CHARTK)) {
            tempnode = new ASTnode("Btype", Curnode);
            Curnode.sons.add(tempnode);
            analyseBType(tempnode);//getToken了一次
        }
        tempnode = new ASTnode("ConstDef", Curnode);
        Curnode.sons.add(tempnode);
        analyseConstDef(tempnode);
        while (getNextToken(",") != null) {
            tempnode = new ASTnode(",", Curnode);
            Curnode.sons.add(tempnode);

            tempnode = new ASTnode("ConstDef", Curnode);
            Curnode.sons.add(tempnode);
            analyseConstDef(tempnode);
        }
        if (getNextToken(";") != null) {
            tempnode = new ASTnode(";", Curnode);
            Curnode.sons.add(tempnode);
        } else {
            //i
            SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
            tempnode = new ASTnode(";", Curnode);
            Curnode.sons.add(tempnode);
        }
        this.syntaxArrayList.add("<" + "ConstDecl" + ">");
    }

    private void analyseBType(ASTnode BType) {//get一次
        Curnode = BType;
        if (getNextToken("int") != null) {
            tempnode = new ASTnode("int", Curnode);
            Curnode.sons.add(tempnode);
        } else if (getNextToken("char") != null) {
            tempnode = new ASTnode("char", Curnode);
            Curnode.sons.add(tempnode);
        } else {
            System.out.println("Btypewrong");
        }

    }

    private void analyseConstDef(ASTnode Constdef) {
        Curnode = Constdef;
        tempnode = new ASTnode("Ident", Curnode);
        Curnode.sons.add(tempnode);
        analyseIdent(tempnode);

        while (isNext(1, TokenKey.LBRACK)) {
            if (getNextToken("[") != null) {
                tempnode = new ASTnode("[", Curnode);
                Curnode.sons.add(tempnode);
            }
            ;
            tempnode = new ASTnode("ConstExp", Curnode);
            analyseConstExp(tempnode);
            if (getNextToken("]")!=null) {
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }else{
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'k'));
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }
        }
        if (getNextToken("=") != null) {
            tempnode = new ASTnode("=", Curnode);
            Curnode.sons.add(tempnode);
            analyseConstInitVal(tempnode);

        }
        this.syntaxArrayList.add("<" + "ConstDef" + ">");
    }

    private void analyseConstInitVal(ASTnode ConstInitVal) {
        Curnode = ConstInitVal;

        if (isNext(1, TokenKey.LBRACE)) {
            if (getNextToken("{") != null) {
                tempnode = new ASTnode("{", Curnode);
                Curnode.sons.add(tempnode);
            }

            if (!isNext(1, TokenKey.RBRACE)) {
                tempnode = new ASTnode("ConstExp", Curnode);
                Curnode.sons.add(tempnode);
                analyseConstExp(tempnode);

                while (getNextToken(",")!=null) {
                    tempnode = new ASTnode(",", Curnode);
                    Curnode.sons.add(tempnode);
                    tempnode = new ASTnode("ConstExp", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseConstExp(tempnode);
                }
                if (getNextToken("}") != null) {
                    tempnode = new ASTnode("}", Curnode);
                    Curnode.sons.add(tempnode);
                }
            }else{
                if (getNextToken("}") != null) {
                    tempnode = new ASTnode("}", Curnode);
                    Curnode.sons.add(tempnode);
                }

            }
        } else if (isNext(1, TokenKey.STRCON)) {
            tempnode = new ASTnode("STRCON", Curnode);
            Curnode.sons.add(tempnode);
            analyseStringConst(tempnode);
        } else {
            tempnode = new ASTnode("ConstExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseConstExp(tempnode);
        }
        this.syntaxArrayList.add("<" + "ConstInitVal" + ">");
    }




    private void analyseVarDecl(ASTnode VarDecl) {
        if (isNext(1, TokenKey.INTTK) || isNext(1, TokenKey.CHARTK)) {
            tempnode = new ASTnode("Btype", Curnode);
            Curnode.sons.add(tempnode);
            analyseBType(tempnode);//getToken了一次
        }
        tempnode = new ASTnode("VarDef", Curnode);
        Curnode.sons.add(tempnode);
        analyseVarDef(tempnode);
        while (getNextToken(",") != null) {
            tempnode = new ASTnode(",", Curnode);
            Curnode.sons.add(tempnode);

            tempnode = new ASTnode("VarDef", Curnode);
            Curnode.sons.add(tempnode);
            analyseVarDef(tempnode);
        }
        if (getNextToken(";") != null) {
            tempnode = new ASTnode(";", Curnode);
            Curnode.sons.add(tempnode);
        } else {
            //i
            SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
            tempnode = new ASTnode(";", Curnode);
            Curnode.sons.add(tempnode);
        }
        this.syntaxArrayList.add("<" + "VarDecl" + ">");
    }


    private void analyseVarDef(ASTnode VarDef) {
        Curnode = VarDef;
        tempnode = new ASTnode("Ident", Curnode);
        Curnode.sons.add(tempnode);
        analyseIdent(tempnode);

        while (isNext(1, TokenKey.LBRACK)) {
            if (getNextToken("[") != null) {
                tempnode = new ASTnode("[", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("ConstExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseConstExp(tempnode);
            if (getNextToken("]")!=null) {
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }else{
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'k'));
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }
        }
        if (getNextToken("=") != null) {
            tempnode = new ASTnode("=", Curnode);
            Curnode.sons.add(tempnode);
            analyseInitVal(tempnode);
        }
        this.syntaxArrayList.add("<" + "VarDef" + ">");
    }

    private void analyseInitVal(ASTnode InitVal) {
        Curnode = InitVal;
        if (isNext(1, TokenKey.LBRACE)) {
            if (getNextToken("{") != null) {
                tempnode = new ASTnode("{", Curnode);
                Curnode.sons.add(tempnode);
            }
            if (!isNext(1, TokenKey.RBRACE)) {
                tempnode = new ASTnode("Exp", Curnode);
                Curnode.sons.add(tempnode);
                analyseExp(tempnode);
                while (getNextToken(",")!=null) {
                    tempnode = new ASTnode(",", Curnode);
                    Curnode.sons.add(tempnode);
                    tempnode = new ASTnode("Exp", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseExp(tempnode);
                }
                if (getNextToken("}") != null) {
                    tempnode = new ASTnode("}", Curnode);
                    Curnode.sons.add(tempnode);
                }
            }else{
                if (getNextToken("}") != null) {
                    tempnode = new ASTnode("}", Curnode);
                    Curnode.sons.add(tempnode);
                }

            }
        } else if (isNext(1, TokenKey.STRCON)) {

            tempnode = new ASTnode("STRCON", Curnode);
            Curnode.sons.add(tempnode);
            analyseStringConst(tempnode);
        }
        else {
            tempnode = new ASTnode("Exp", Curnode);
            Curnode.sons.add(tempnode);
            analyseExp(tempnode);
        }
        this.syntaxArrayList.add("<" + "InitVal" + ">");
    }

    private void analyseFuncDef(ASTnode FuncDef) {
        while((isNext(1,TokenKey.INTTK)||isNext(1,TokenKey.CHARTK)||isNext(1,TokenKey.VOIDTK))
                &&isNext(2,TokenKey.IDENFR)
                &&isNext(3,TokenKey.LPARENT)){
            Curnode = FuncDef;
            tempnode = new ASTnode("FuncType", Curnode);
            Curnode.sons.add(tempnode);
            analyseFuncType(tempnode);
            tempnode = new ASTnode("Ident", Curnode);
            Curnode.sons.add(tempnode);
            analyseIdent(tempnode);
            if (getNextToken("(") != null) {
                tempnode = new ASTnode("(", Curnode);
                Curnode.sons.add(tempnode);
                if (!isNext(1, TokenKey.RPARENT)) {
                    tempnode = new ASTnode("FuncFParams", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseFuncFParams(tempnode);
                }
                if (getNextToken(")") != null) {
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }else{
                    SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'j'));
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }
            }
            tempnode = new ASTnode("Block", Curnode);
            Curnode.sons.add(tempnode);
            analyseBlock(tempnode);
            this.syntaxArrayList.add("<" + "FuncDef" + ">");

        }


    }

    private void analyseMainFuncDef(ASTnode MainFuncDef) {
        Curnode = MainFuncDef;
        if (getNextToken("int") != null) {
            tempnode = new ASTnode("int", Curnode);
            Curnode.sons.add(tempnode);
        }
        if (getNextToken("main") != null) {
            tempnode = new ASTnode("main", Curnode);
            Curnode.sons.add(tempnode);
        }
        if (getNextToken("(") != null) {
            tempnode = new ASTnode("(", Curnode);
            Curnode.sons.add(tempnode);
        }
        if (getNextToken(")") != null) {
            tempnode = new ASTnode(")", Curnode);
            Curnode.sons.add(tempnode);
        }else{
            SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'j'));
            tempnode = new ASTnode(")", Curnode);
            Curnode.sons.add(tempnode);
        }
        tempnode = new ASTnode("Block", Curnode);
        Curnode.sons.add(tempnode);
        analyseBlock(tempnode);
        this.syntaxArrayList.add("<" + "MainFuncDef" + ">");
    }

    private void analyseFuncType(ASTnode FuncType) {
        Curnode = FuncType;
        if (getNextToken("void") != null) {
            tempnode = new ASTnode("void", Curnode);
            Curnode.sons.add(tempnode);
        } else if (getNextToken("int") != null) {
            tempnode = new ASTnode("int", Curnode);
            Curnode.sons.add(tempnode);
        } else if (getNextToken("char") != null) {
            tempnode = new ASTnode("char", Curnode);
            Curnode.sons.add(tempnode);
        } else {
            System.out.println("FuncType wrong!");
        }
        this.syntaxArrayList.add("<" + "FuncType" + ">");
    }

    private void analyseFuncFParams(ASTnode FuncFParams) {
        Curnode = FuncFParams;
        tempnode = new ASTnode("FuncFParam", Curnode);
        Curnode.sons.add(tempnode);
        analyseFuncFParam(tempnode);

        while (isNext(1, TokenKey.COMMA)) {
            if (getNextToken(",") != null) {
                tempnode = new ASTnode(",", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("FuncFParam", Curnode);
            Curnode.sons.add(tempnode);
            analyseFuncFParam(tempnode);
        }
        this.syntaxArrayList.add("<" + "FuncFParams" + ">");
    }

    private void analyseFuncFParam(ASTnode FuncFParam) {
        Curnode = FuncFParam;
        tempnode = new ASTnode("BType", Curnode);
        Curnode.sons.add(tempnode);
        analyseBType(tempnode);

        tempnode = new ASTnode("Ident", Curnode);
        Curnode.sons.add(tempnode);
        analyseIdent(tempnode);

        if (isNext(1, TokenKey.LBRACK) && isNext(2, TokenKey.RBRACK)) {
            if (getNextToken("[") != null) {
                tempnode = new ASTnode("[", Curnode);
                Curnode.sons.add(tempnode);
            }
            if (getNextToken("]")!=null) {
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }else{
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'k'));
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }
        }
        this.syntaxArrayList.add("<" + "FuncFParam" + ">");
    }

    private void analyseBlock(ASTnode Block) {
        Curnode = Block;
        if (getNextToken("{") != null) {
            tempnode = new ASTnode("{", Curnode);
            Curnode.sons.add(tempnode);
            while (!isNext(1, TokenKey.RBRACE)) {
                tempnode = new ASTnode("BlockItem", Curnode);
                Curnode.sons.add(tempnode);
                analyseBlockItem(tempnode);
            }
            if (getNextToken("}") != null) {
                tempnode = new ASTnode("}", Curnode);
                Curnode.sons.add(tempnode);
            }
        }
        this.syntaxArrayList.add("<" + "Block" + ">");
    }

    private void analyseBlockItem(ASTnode BlockItem) {
        Curnode = BlockItem;
        if (isNext(1, TokenKey.CONSTTK) || ((isNext(1, TokenKey.INTTK)||isNext(1, TokenKey.CHARTK)) && isNext(2, TokenKey.IDENFR) && !isNext(3, TokenKey.LPARENT))) {
            tempnode = new ASTnode("Decl", Curnode);
            Curnode.sons.add(tempnode);
            analyseDecl(tempnode);
        } else {
            tempnode = new ASTnode("Stmt", Curnode);
            Curnode.sons.add(tempnode);
            analyseStmt(tempnode);
        }
        //this.syntaxArrayList.add("<" + "BlockItem" + ">");
    }


    private void analyseStmt(ASTnode Stmt) {
        Curnode = Stmt;
        if (isNext(1, TokenKey.LBRACE)) {
            tempnode = new ASTnode("Block", Curnode);
            Curnode.sons.add(tempnode);
            analyseBlock(tempnode);
        } else if (isNext(1, TokenKey.IFTK)) {
            if (getNextToken("if") != null) {
                getNextToken("(");
                tempnode = new ASTnode("Cond", Curnode);
                Curnode.sons.add(tempnode);
                analyseCond(tempnode);
                if (getNextToken(")") != null) {
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }else{
                    SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'j'));
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }
                tempnode = new ASTnode("Stmt", Curnode);
                Curnode.sons.add(tempnode);
                analyseStmt(tempnode);
            }

            if (isNext(1, TokenKey.ELSETK)) {
                if (getNextToken("else") != null) {
                    tempnode = new ASTnode("Stmt", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseStmt(tempnode);
                }
            }
        } else if (isNext(1, TokenKey.FORTK)) {
            if (getNextToken("for") != null) {
                getNextToken("(");
                if (!isNext(1, TokenKey.SEMICN)) {
                    tempnode = new ASTnode("ForStmt", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseForStmt(tempnode);
                }
                getNextToken(";");
                if (!isNext(1, TokenKey.SEMICN)) {
                    tempnode = new ASTnode("Cond", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseCond(tempnode);
                }
                getNextToken(";");
                if (!isNext(1, TokenKey.RPARENT)) {
                    tempnode = new ASTnode("ForStmt", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseForStmt(tempnode);
                }
                getNextToken(")");
                tempnode = new ASTnode("Stmt", Curnode);
                Curnode.sons.add(tempnode);
                analyseStmt(tempnode);
            }
            ;
        } else if (isNext(1, TokenKey.BREAKTK)) {
            tempnode = new ASTnode("break", Curnode);
            Curnode.sons.add(tempnode);
            getNextToken("break");
            tempnode = new ASTnode(";", Curnode);
            Curnode.sons.add(tempnode);
            if (getNextToken(";") != null) {
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            } else {
                //i
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            }

        } else if (isNext(1, TokenKey.CONTINUETK)) {
            tempnode = new ASTnode("continue", Curnode);
            Curnode.sons.add(tempnode);
            getNextToken("continue");
            tempnode = new ASTnode(";", Curnode);
            Curnode.sons.add(tempnode);
            if (getNextToken(";") != null) {
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            } else {
                //i
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            }
        } else if (isNext(1, TokenKey.RETURNTK)) {
            if (getNextToken("return") != null) {
                if (isNextExp()) {
                    tempnode = new ASTnode("Exp", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseExp(tempnode);
                }
            }
            if (getNextToken(";") != null) {
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            } else {
                //i
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            }
        } else if (isNext(1, TokenKey.PRINTFTK)) {
            if (getNextToken("printf") != null) {
                getNextToken("(");
                tempnode = new ASTnode("StringConst", Curnode);
                Curnode.sons.add(tempnode);
                analyseStringConst(tempnode);
                while (isNext(1, TokenKey.COMMA)) {
                    getNextToken(",");
                    tempnode = new ASTnode("StringConst", Curnode);
                    Curnode.sons.add(tempnode);
                    analyseExp(tempnode);
                }

                if (getNextToken(")") != null) {
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }else{
                    SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'j'));
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }

                if (getNextToken(";") != null) {
                    tempnode = new ASTnode(";", Curnode);
                    Curnode.sons.add(tempnode);
                } else {
                    //i
                    SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                    tempnode = new ASTnode(";", Curnode);
                    Curnode.sons.add(tempnode);
                }
            }

        } else if (isNextLValAssignGetintOrGetchar()) {
            tempnode = new ASTnode("LVal", Curnode);
            Curnode.sons.add(tempnode);
            analyseLVal(tempnode);

            getNextToken("=");
            if (getNextToken("getint") == null) {
                getNextToken("getchar");
            }
            getNextToken("(");
            if (getNextToken(")") != null) {
                tempnode = new ASTnode(")", Curnode);
                Curnode.sons.add(tempnode);
            }else{
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'j'));
                tempnode = new ASTnode(")", Curnode);
                Curnode.sons.add(tempnode);
            }
            if (getNextToken(";") != null) {
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            } else {
                //i
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            }
        } else if (isNextLValAssignExp()) {
            tempnode = new ASTnode("LVal", Curnode);
            Curnode.sons.add(tempnode);
            analyseLVal(tempnode);
            getNextToken("=");
            tempnode = new ASTnode("Exp", Curnode);
            Curnode.sons.add(tempnode);
            analyseExp(tempnode);
            if (getNextToken(";") != null) {
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            } else {
                //i
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            }
        } else if (isNextExp()) {
            if (!isNext(1, TokenKey.SEMICN)) {
                tempnode = new ASTnode("Exp", Curnode);
                Curnode.sons.add(tempnode);
                analyseExp(tempnode);
            }
            if (getNextToken(";") != null) {
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            } else {
                //i
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            }

        } else {
            if (getNextToken(";") != null) {
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            } else {
                //i
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'i'));
                tempnode = new ASTnode(";", Curnode);
                Curnode.sons.add(tempnode);
            }
        }
        this.syntaxArrayList.add("<" + "Stmt" + ">");
    }


    private void analyseForStmt(ASTnode ForStmt) {
        Curnode = ForStmt;
        tempnode = new ASTnode("LVal", Curnode);
        Curnode.sons.add(tempnode);
        analyseLVal(tempnode);
        if (getNextToken("=") != null) {
            tempnode = new ASTnode("=", Curnode);
            Curnode.sons.add(tempnode);
            tempnode = new ASTnode("Exp", Curnode);
            Curnode.sons.add(tempnode);
            analyseExp(tempnode);
        }
        this.syntaxArrayList.add("<" + "ForStmt" + ">");
    }


    private void analyseExp(ASTnode Exp) {
        Curnode = Exp;
        tempnode = new ASTnode("AddExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseAddExp(tempnode);
        this.syntaxArrayList.add("<" + "Exp" + ">");
    }

    private void analyseCond(ASTnode Cond) {
        Curnode = Cond;
        tempnode = new ASTnode("LOrExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseLOrExp(tempnode);
        this.syntaxArrayList.add("<" + "Cond" + ">");
    }

    private void analyseLVal(ASTnode LVal) {
        Curnode = LVal;
        tempnode = new ASTnode("Ident", Curnode);
        Curnode.sons.add(tempnode);
        analyseIdent(tempnode);

        while (isNext(1, TokenKey.LBRACK)) {
            if (getNextToken("[") != null) {
                tempnode = new ASTnode("[", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("Exp", Curnode);
            Curnode.sons.add(tempnode);
            analyseExp(tempnode);
            if (getNextToken("]")!=null) {
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }else{
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'k'));
                tempnode = new ASTnode("]", Curnode);
                Curnode.sons.add(tempnode);
            }
        }
        this.syntaxArrayList.add("<" + "LVal" + ">");
    }

    private void analysePrimaryExp(ASTnode PrimaryExp) {
        Curnode = PrimaryExp;
        if (isNext(1, TokenKey.LPARENT)) {
            if (getNextToken("(") != null) {
                tempnode = new ASTnode("(", Curnode);
                Curnode.sons.add(tempnode);
                tempnode = new ASTnode("Exp", Curnode);
                Curnode.sons.add(tempnode);
                analyseExp(tempnode);
                if (getNextToken(")") != null) {
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }else{
                    SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'j'));
                    tempnode = new ASTnode(")", Curnode);
                    Curnode.sons.add(tempnode);
                }
            }
        } else if (isNext(1, TokenKey.IDENFR)) {
            tempnode = new ASTnode("LVal", Curnode);
            Curnode.sons.add(tempnode);
            analyseLVal(tempnode);
        } else if (isNext(1, TokenKey.INTCON)) {
            tempnode = new ASTnode("Number", Curnode);
            Curnode.sons.add(tempnode);
            analyseNumber(tempnode);
        } else if (isNext(1, TokenKey.CHRCON)) {
            tempnode = new ASTnode("Character", Curnode);
            Curnode.sons.add(tempnode);
            analyseCharacter(tempnode);
        } else {
            System.out.println("PrimaryExp wrong!");
        }
        this.syntaxArrayList.add("<" + "PrimaryExp" + ">");
    }

    private void analyseNumber(ASTnode Number) {
        Curnode = Number;
        if (isNext(1, TokenKey.INTCON)) {
            getNextToken("intConst");
        } else {
            System.out.println("Number wrong!");
        }
        this.syntaxArrayList.add("<" + "Number" + ">");
    }

    private void analyseCharacter(ASTnode Character) {
        Curnode = Character;
        if (isNext(1, TokenKey.CHRCON)) {
            getNextToken("charConst");
        } else {
            System.out.println("Character wrong!");
        }
        this.syntaxArrayList.add("<" + "Character" + ">");
    }


    private void analyseUnaryExp(ASTnode UnaryExp) {


        if (isNext(1, TokenKey.LPARENT)
                || (isNext(1, TokenKey.IDENFR) && (!isNext(2, TokenKey.LPARENT)))
                || isNext(1, TokenKey.INTCON)
                || isNext(1, TokenKey.CHRCON)) {

            tempnode = new ASTnode("PrimaryExp", Curnode);
            Curnode.sons.add(tempnode);
            analysePrimaryExp(tempnode);
        } else if (isNext(1, TokenKey.IDENFR) && isNext(2, TokenKey.LPARENT)) {
            tempnode = new ASTnode("Ident", Curnode);
            Curnode.sons.add(tempnode);
            analyseIdent(tempnode);

            getNextToken("(");
            if (isNextExp()) {
                tempnode = new ASTnode("FunRParams", Curnode);
                Curnode.sons.add(tempnode);
                analyseFuncRParams(tempnode);
            }
            if (getNextToken(")") != null) {
                tempnode = new ASTnode(")", Curnode);
                Curnode.sons.add(tempnode);
            }else{
                SyntaxErrorList.add(new theError(tokenList.get(cur).getTokenPos().getRow(),'j'));
                tempnode = new ASTnode(")", Curnode);
                Curnode.sons.add(tempnode);
            }

        } else if (isNext(1, TokenKey.PLUS) || isNext(1, TokenKey.MINU) || isNext(1, TokenKey.NOT)) {
            tempnode = new ASTnode("UnaryOP", Curnode);
            Curnode.sons.add(tempnode);
            analyseUnaryOp(tempnode);
            tempnode = new ASTnode("UnaryExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseUnaryExp(tempnode);
        } else {
            System.out.println("unaryExp wrong");
            System.out.println(tokenList.get(cur).getTokenPos().getRow());
            System.out.println(tokenList.get(cur).getTokenString());
            System.out.println(tokenList.get(cur).getTokenKey());


        }

        this.syntaxArrayList.add("<" + "UnaryExp" + ">");

    }
    private void analyseUnaryOp(ASTnode UnaryOp) {
        Curnode = UnaryOp;
        if (getNextToken("+") != null) {
            tempnode = new ASTnode("+", Curnode);
            Curnode.sons.add(tempnode);
        } else if (getNextToken("-") != null) {
            tempnode = new ASTnode("-", Curnode);
            Curnode.sons.add(tempnode);
        } else if (getNextToken("!") != null) {
            tempnode = new ASTnode("!", Curnode);
            Curnode.sons.add(tempnode);
        }else {
            System.out.println("wrong");
        }
        this.syntaxArrayList.add("<" + "UnaryOp" + ">");

    }

    private void analyseFuncRParams(ASTnode FuncRParams) {
        Curnode = FuncRParams;
        tempnode = new ASTnode("Exp", Curnode);
        Curnode.sons.add(tempnode);
        analyseExp(tempnode);

        while (isNext(1, TokenKey.COMMA)) {
            if (getNextToken(",") != null) {
                tempnode = new ASTnode(",", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("Exp", Curnode);
            Curnode.sons.add(tempnode);
            analyseExp(tempnode);
        }
        this.syntaxArrayList.add("<" + "FuncRParams" + ">");
    }

    private void analyseMulExp(ASTnode MulExp) {
        Curnode = MulExp;
        tempnode = new ASTnode("UnaryExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseUnaryExp(tempnode);
        this.syntaxArrayList.add("<" + "MulExp" + ">");

        while (isNext(1, TokenKey.MULT) || isNext(1, TokenKey.DIV) || isNext(1, TokenKey.MOD)) {
            if (getNextToken("*") != null) {
                tempnode = new ASTnode("*", Curnode);
                Curnode.sons.add(tempnode);
            } else if (getNextToken("/") != null) {
                tempnode = new ASTnode("/", Curnode);
                Curnode.sons.add(tempnode);
            } else if (getNextToken("%") != null) {
                tempnode = new ASTnode("%", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("UnaryExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseUnaryExp(tempnode);
            this.syntaxArrayList.add("<" + "MulExp" + ">");
        }

    }


    private void analyseAddExp(ASTnode AddExp) {
        Curnode = AddExp;
        tempnode = new ASTnode("MulExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseMulExp(tempnode);
        this.syntaxArrayList.add("<" + "AddExp" + ">");
        while (isNext(1, TokenKey.PLUS) || isNext(1, TokenKey.MINU)) {
            if (getNextToken("+") != null) {
                tempnode = new ASTnode("+", Curnode);
                Curnode.sons.add(tempnode);
            } else if (getNextToken("-") != null) {
                tempnode = new ASTnode("-", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("MulExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseMulExp(tempnode);
            this.syntaxArrayList.add("<" + "AddExp" + ">");
        }

    }

    private void analyseRelExp(ASTnode RelExp) {
        Curnode = RelExp;
        tempnode = new ASTnode("AddExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseAddExp(tempnode);
        this.syntaxArrayList.add("<" + "RelExp" + ">");

        while (isNext(1, TokenKey.LSS) || isNext(1, TokenKey.GRE) || isNext(1, TokenKey.LEQ) || isNext(1, TokenKey.GEQ)) {
            if (getNextToken("<") != null) {
                tempnode = new ASTnode("<", Curnode);
                Curnode.sons.add(tempnode);
            } else if (getNextToken(">") != null) {
                tempnode = new ASTnode(">", Curnode);
                Curnode.sons.add(tempnode);
            } else if (getNextToken("<=") != null) {
                tempnode = new ASTnode("<=", Curnode);
                Curnode.sons.add(tempnode);
            } else if (getNextToken(">=") != null) {
                tempnode = new ASTnode(">=", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("AddExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseAddExp(tempnode);
            this.syntaxArrayList.add("<" + "RelExp" + ">");
        }

    }


    private void analyseEqExp(ASTnode EqExp) {
        Curnode = EqExp;
        tempnode = new ASTnode("RelExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseRelExp(tempnode);
        this.syntaxArrayList.add("<" + "EqExp" + ">");
        while (isNext(1, TokenKey.EQL) || isNext(1, TokenKey.NEQ)) {
            if (getNextToken("==") != null) {
                tempnode = new ASTnode("==", Curnode);
                Curnode.sons.add(tempnode);
            } else if (getNextToken("!=") != null) {
                tempnode = new ASTnode("!=", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("RelExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseRelExp(tempnode);
            this.syntaxArrayList.add("<" + "EqExp" + ">");
        }

    }

    private void analyseLAndExp(ASTnode LAndExp) {
        Curnode = LAndExp;
        tempnode = new ASTnode("EqExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseEqExp(tempnode);
        this.syntaxArrayList.add("<" + "LAndExp" + ">");
        while (isNext(1, TokenKey.AND)) {
            if (getNextToken("&&") != null) {
                tempnode = new ASTnode("&&", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("EqExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseEqExp(tempnode);
            this.syntaxArrayList.add("<" + "LAndExp" + ">");
        }

    }

    private void analyseLOrExp(ASTnode LOrExp) {
        Curnode = LOrExp;
        tempnode = new ASTnode("LAndExp", Curnode);
        Curnode.sons.add(tempnode);
        analyseLAndExp(tempnode);
        this.syntaxArrayList.add("<" + "LOrExp" + ">");
        while (isNext(1, TokenKey.OR)) {
            if (getNextToken("||") != null) {
                tempnode = new ASTnode("||", Curnode);
                Curnode.sons.add(tempnode);
            }
            tempnode = new ASTnode("LAndExp", Curnode);
            Curnode.sons.add(tempnode);
            analyseLAndExp(tempnode);
            this.syntaxArrayList.add("<" + "LOrExp" + ">");
        }

    }



    private void analyseIdent(ASTnode Ident) {
        Curnode = Ident;
        if (isNext(1, TokenKey.IDENFR)) {
            getNextToken("ident");
        } else {
            System.out.println("ident wrong!");
        }

    }

    private void analyseConstExp(ASTnode ConstExp) {
        Curnode = ConstExp;
        tempnode = new ASTnode("AddExp", Curnode);
        analyseAddExp(tempnode);
        this.syntaxArrayList.add("<" + "ConstExp" + ">");

    }

    private void analyseStringConst(ASTnode StringConst) {
        Curnode = StringConst;
        if (isNext(1, TokenKey.STRCON)) {
            getNextToken("formatString");
        } else {
            System.out.println("StringConst wrong!");
        }
    }


}










