package frontend;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Parser {
    private final AbTree mainTree;
    private int lineNum;//当前行号
    private int colNum;//当前的token索引
    private final HashMap<Integer, ArrayList<Pair>> tokens;
    private final ArrayList<Error> errors;

    public Parser(HashMap<Integer, ArrayList<Pair>> tokens) {
        for (int lineNum : tokens.keySet()) {
            if (!tokens.get(lineNum).isEmpty()) {
                this.lineNum = lineNum;
                break;
            }
        }
        this.colNum = 0;
        this.tokens = tokens;
        this.errors = new ArrayList<>();
        this.mainTree = new AbTree();
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }

    public AbTree getMainTree() {
        return mainTree;
    }

    public Pair getToken(int lineNum, int colNum) {
        ArrayList<Pair> pairs = tokens.get(lineNum);
        return pairs.get(colNum);
    }

    // 将伪指针移动到下一个单词处
    public void moveToNextWord() {
        this.colNum ++;
        while (this.colNum >= this.tokens.get(this.lineNum).size()) {
            if (this.lineNum == this.tokens.size()) {
                return;
            }
            this.lineNum++;
            this.colNum = 0;
        }
    }

    //CompUnit → {Decl} {FuncDef} MainFuncDef
    public void CompUnit() {
        if (tokens.isEmpty()) {
            return;
        }
        this.mainTree.setVal(new Pair(this.lineNum, "<CompUnit>"));
        while (isDecl(lineNum, colNum)) {
            this.mainTree.addNode(Decl());
        }
        while (isFuncDef(lineNum, colNum)) {
            this.mainTree.addNode(FuncDef());
        }
        AbTree MainFuncDef = MainFuncDef();
        if (MainFuncDef != null) {
            this.mainTree.addNode(MainFuncDef);
        }
    }

    // Decl → ConstDecl | VarDecl
    public AbTree Decl() {
        AbTree Decl = new AbTree();
        Decl.setVal(new Pair(this.lineNum, "<Decl>"));
        String now = getToken(this.lineNum, this.colNum).getValue();
        if (now.equals("const")) {
            Decl.addNode(ConstDecl());
        } else {
            Decl.addNode(VarDecl());
        }
        return Decl;
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    public AbTree FuncDef() {
        int error_line = 0;
        AbTree FuncDef = new AbTree();
        FuncDef.setVal(new Pair(this.lineNum, "<FuncDef>"));

        error_line = this.lineNum;
        FuncDef.addNode(FuncType());

        AbTree node2 = new AbTree();
        node2.setVal(new Pair(this.lineNum, LexType.IDENFR, getToken(this.lineNum, this.colNum).getValue()));
        moveToNextWord();
        FuncDef.addNode(node2);

        AbTree item1 = new AbTree();
        item1.setVal(new Pair(this.lineNum, LexType.LPARENT, getToken(this.lineNum, this.colNum).getValue()));
        moveToNextWord();
        FuncDef.addNode(item1);

        if (isFuncFParams(getToken(this.lineNum, this.colNum).getValue())) {
            error_line = this.lineNum;
            FuncDef.addNode(FuncFParams());
        }

        if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
            AbTree item2 = new AbTree();
            item2.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
            moveToNextWord();
            FuncDef.addNode(item2);
        } else {
            this.errors.add(new Error(error_line, ErrorType.j));
        }

        FuncDef.addNode(Block());
        return FuncDef;
    }

    //MainFuncDef → 'int' 'main' '(' ')' Block
    public AbTree MainFuncDef() {
        if (getToken(this.lineNum, this.colNum).getKey().equals(LexType.nothing)) {
            return null;
        }
        AbTree MainFuncDef = new AbTree();
        MainFuncDef.setVal(new Pair(this.lineNum, "<MainFuncDef>"));

        AbTree node1 = new AbTree();
        node1.setVal(new Pair(this.lineNum, LexType.INTTK, "int"));
        moveToNextWord();
        MainFuncDef.addNode(node1);

        AbTree node2 = new AbTree();
        node2.setVal(new Pair(this.lineNum, LexType.MAINTK, "main"));
        moveToNextWord();
        MainFuncDef.addNode(node2);

        AbTree item1 = new AbTree();
        item1.setVal(new Pair(this.lineNum, LexType.LPARENT, "("));
        moveToNextWord();
        MainFuncDef.addNode(item1);

        if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
            AbTree item2 = new AbTree();
            item2.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
            moveToNextWord();
            MainFuncDef.addNode(item2);
        } else {
            this.errors.add(new Error(this.lineNum, ErrorType.j));
        }

        MainFuncDef.addNode(Block());

        return MainFuncDef;
    }

    //Block → '{' { BlockItem } '}'
    public AbTree Block() {
        AbTree Block = new AbTree();
        Block.setVal(new Pair(this.lineNum, "<Block>"));

        AbTree item1 = new AbTree();
        item1.setVal(new Pair(this.lineNum, LexType.LBRACE, "{"));
        moveToNextWord();
        Block.addNode(item1);

        while (!getToken(this.lineNum, this.colNum).getValue().equals("}")) {
            Block.addNode(BlockItem());
        }

        AbTree item2 = new AbTree();
        item2.setVal(new Pair(this.lineNum, LexType.RBRACE, "}"));
        moveToNextWord();
        Block.addNode(item2);

        return Block;
    }

    //BlockItem → Decl | Stmt
    public AbTree BlockItem() {
        AbTree BlockItem = new AbTree();
        BlockItem.setVal(new Pair(this.lineNum, "<BlockItem>"));

        if (isDecl(this.lineNum, this.colNum)) {
            BlockItem.addNode(Decl());
        } else {
            BlockItem.addNode(Stmt());
        }

        return BlockItem;
    }

    // Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
    //| [Exp] ';' //有无Exp两种情况
    //| Block
    //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
    //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
    //ForStmt与Cond中缺省一个，3种情况 3. ForStmt与Cond中缺省两个，3种情况 4. ForStmt与Cond全部
    //缺省，1种情况
    //| 'break' ';' | 'continue' ';'
    //| 'return' [Exp] ';' // 1.有Exp 2.无Exp
    //| LVal '=' 'getint''('')'';'
    //| LVal '=' 'getchar''('')'';'
    //| 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
    public AbTree Stmt() {
        int error_line = 0;
        AbTree Stmt = new AbTree();
        Stmt.setVal(new Pair(this.lineNum, "<Stmt>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        if (isLValAndEqual(this.lineNum, this.colNum)) {
            error_line = this.lineNum;
            Stmt.addNode(LVal());

            AbTree node1 = new AbTree();
            node1.setVal(new Pair(this.lineNum, LexType.ASSIGN, "="));
            moveToNextWord();
            Stmt.addNode(node1);

            if (getToken(this.lineNum, this.colNum).getValue().equals("getint")) {//LVal '=' 'getint''('')'';'
                AbTree node2 = new AbTree();
                node2.setVal(new Pair(this.lineNum, LexType.GETINTTK, "getint"));
                moveToNextWord();
                Stmt.addNode(node2);

                if (getToken(this.lineNum, this.colNum).getValue().equals("(")) {
                    AbTree item1 = new AbTree();
                    item1.setVal(new Pair(this.lineNum, LexType.LPARENT, "("));
                    moveToNextWord();
                    Stmt.addNode(item1);

                    if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
                        AbTree item2 = new AbTree();
                        item2.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
                        moveToNextWord();
                        Stmt.addNode(item2);
                    } else {
                        this.errors.add(new Error(error_line, ErrorType.j));
                    }
                }
            } else if (getToken(this.lineNum, this.colNum).getValue().equals("getchar")) {//LVal '=' 'getchar''('')'';'
                AbTree node2 = new AbTree();
                node2.setVal(new Pair(this.lineNum, LexType.GETCHARTK, "getchar"));
                moveToNextWord();
                Stmt.addNode(node2);

                if (getToken(this.lineNum, this.colNum).getValue().equals("(")) {
                    AbTree item1 = new AbTree();
                    item1.setVal(new Pair(this.lineNum, LexType.LPARENT, "("));
                    moveToNextWord();
                    Stmt.addNode(item1);

                    if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
                        AbTree item2 = new AbTree();
                        item2.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
                        moveToNextWord();
                        Stmt.addNode(item2);
                    } else {
                        this.errors.add(new Error(error_line, ErrorType.j));
                    }
                }
            } else {//LVal '=' Exp ';'
                error_line = this.lineNum;
                Stmt.addNode(Exp());
            }

            if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
                AbTree item = new AbTree();
                item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
                moveToNextWord();
                Stmt.addNode(item);
            } else {
                this.errors.add(new Error(error_line, ErrorType.i));
            }
        } else if (pair.getValue().equals("{")) {//Block
            Stmt.addNode(Block());
        } else if (pair.getValue().equals("if")) {// 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            AbTree node1 = new AbTree();
            node1.setVal(new Pair(this.lineNum, LexType.IFTK, "if"));
            moveToNextWord();
            Stmt.addNode(node1);

            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LPARENT, "("));
            moveToNextWord();
            Stmt.addNode(item1);

            error_line = this.lineNum;
            Stmt.addNode(Cond());

            if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
                moveToNextWord();
                Stmt.addNode(item2);
            } else {
                this.errors.add(new Error(error_line, ErrorType.j));
            }

            Stmt.addNode(Stmt());

            if (getToken(this.lineNum, this.colNum).getValue().equals("else")) {
                AbTree node4 = new AbTree();
                node4.setVal(new Pair(this.lineNum, LexType.ELSETK, "else"));
                moveToNextWord();
                Stmt.addNode(node4);

                Stmt.addNode(Stmt());
            }
        } else if (getToken(this.lineNum, this.colNum).getValue().equals("for")) {// 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            AbTree node1 = new AbTree();
            node1.setVal(new Pair(this.lineNum, LexType.FORTK, "for"));
            moveToNextWord();
            Stmt.addNode(node1);

            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LPARENT, "("));
            moveToNextWord();
            Stmt.addNode(item1);

            if (getToken(this.lineNum, this.colNum).getKey().equals(LexType.IDENFR)) {
                Stmt.addNode(ForStmt());
            }

            AbTree item2 = new AbTree();
            item2.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
            moveToNextWord();
            Stmt.addNode(item2);

            if (isCond(getToken(this.lineNum, this.colNum))) {
                Stmt.addNode(Cond());
            }

            AbTree item3 = new AbTree();
            item3.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
            moveToNextWord();
            Stmt.addNode(item3);

            if (getToken(this.lineNum, this.colNum).getKey().equals(LexType.IDENFR)) {
                Stmt.addNode(ForStmt());
            }

            AbTree item4 = new AbTree();
            item4.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
            moveToNextWord();
            Stmt.addNode(item4);

            Stmt.addNode(Stmt());
        } else if (getToken(this.lineNum, this.colNum).getValue().equals("break")) {// 'break' ';'
            AbTree node = new AbTree();
            node.setVal(new Pair(this.lineNum, LexType.BREAKTK, "break"));
            error_line = this.lineNum;
            moveToNextWord();
            Stmt.addNode(node);

            if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
                AbTree item = new AbTree();
                item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
                moveToNextWord();
                Stmt.addNode(item);
            } else {
                this.errors.add(new Error(error_line, ErrorType.i));
            }
        } else if (getToken(this.lineNum, this.colNum).getValue().equals("continue")) {// 'continue' ';'
            AbTree node = new AbTree();
            node.setVal(new Pair(this.lineNum, LexType.CONTINUETK, "continue"));
            error_line = this.lineNum;
            moveToNextWord();
            Stmt.addNode(node);

            if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
                AbTree item = new AbTree();
                item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
                moveToNextWord();
                Stmt.addNode(item);
            } else {
                this.errors.add(new Error(error_line, ErrorType.i));
            }
        } else if (getToken(this.lineNum, this.colNum).getValue().equals("return")) {// 'return' [Exp] ';'
            AbTree node1 = new AbTree();
            node1.setVal(new Pair(this.lineNum, LexType.RETURNTK, "return"));
            error_line = this.lineNum;
            moveToNextWord();
            Stmt.addNode(node1);

            if (isExp(getToken(this.lineNum, this.colNum))) {
                error_line = this.lineNum;
                Stmt.addNode(Exp());
            }

            if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
                AbTree item = new AbTree();
                item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
                moveToNextWord();
                Stmt.addNode(item);
            } else {
                this.errors.add(new Error(error_line, ErrorType.i));
            }
        } else if (getToken(this.lineNum, this.colNum).getValue().equals("printf")) {// 'printf''('StringConst {','Exp}')'';'
            AbTree node1 = new AbTree();
            node1.setVal(new Pair(this.lineNum, LexType.PRINTFTK, "printf"));
            moveToNextWord();
            Stmt.addNode(node1);

            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LPARENT, "("));
            moveToNextWord();
            Stmt.addNode(item1);

            AbTree node2 = new AbTree();
            node2.setVal(new Pair(this.lineNum, LexType.STRCON, getToken(this.lineNum, this.colNum).getValue()));
            error_line = this.lineNum;
            moveToNextWord();
            Stmt.addNode(node2);

            while (getToken(this.lineNum, this.colNum).getValue().equals(",")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.COMMA, ","));
                moveToNextWord();
                Stmt.addNode(item2);

                error_line = this.lineNum;
                Stmt.addNode(Exp());
            }

            if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
                AbTree item3 = new AbTree();
                item3.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
                moveToNextWord();
                Stmt.addNode(item3);
            } else {
                this.errors.add(new Error(error_line, ErrorType.j));
            }

            if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
                AbTree item4 = new AbTree();
                item4.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
                moveToNextWord();
                Stmt.addNode(item4);
            } else {
                this.errors.add(new Error(error_line, ErrorType.i));
            }
        } else {//[Exp] ';'
            if (isExp(getToken(this.lineNum, this.colNum))) {
                error_line = this.lineNum;
                Stmt.addNode(Exp());
                if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
                    AbTree item = new AbTree();
                    item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
                    moveToNextWord();
                    Stmt.addNode(item);
                } else {
                    this.errors.add(new Error(error_line, ErrorType.i));
                }
            } else {
                if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
                    AbTree item = new AbTree();
                    item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
                    moveToNextWord();
                    Stmt.addNode(item);
                }
            }
        }
        return Stmt;
    }

    // ForStmt → LVal '=' Exp
    public AbTree ForStmt() {
        AbTree ForStmt = new AbTree();
        ForStmt.setVal(new Pair(this.lineNum, "<ForStmt>"));

        ForStmt.addNode(LVal());

        AbTree item = new AbTree();
        item.setVal(new Pair(this.lineNum, LexType.ASSIGN, "="));
        moveToNextWord();
        ForStmt.addNode(item);

        ForStmt.addNode(Exp());

        return ForStmt;
    }

    //LVal → Ident ['[' Exp ']']
    public AbTree LVal() {
        int error_line = 0;
        AbTree LVal = new AbTree();
        LVal.setVal(new Pair(this.lineNum, "<LVal>"));

        AbTree node1 = new AbTree();
        node1.setVal(new Pair(this.lineNum, LexType.IDENFR, getToken(this.lineNum, this.colNum).getValue()));
        moveToNextWord();
        LVal.addNode(node1);

        if (getToken(this.lineNum, this.colNum).getValue().equals("[")) {
            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LBRACK, "["));
            moveToNextWord();
            LVal.addNode(item1);

            error_line = this.lineNum;
            LVal.addNode(Exp());

            if (getToken(this.lineNum, this.colNum).getValue().equals("]")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.RBRACK, "]"));
                moveToNextWord();
                LVal.addNode(item2);
            } else {
                this.errors.add(new Error(error_line, ErrorType.k));
            }
        }
        return LVal;
    }

    //Cond → LOrExp
    public AbTree Cond() {
        AbTree Cond = new AbTree();
        Cond.setVal(new Pair(this.lineNum, "<Cond>"));

        Cond.addNode(LOrExp());

        return Cond;
    }

    //LOrExp → LAndExp | LOrExp '||' LAndExp
    public AbTree LOrExp() {
        AbTree LOrExp = new AbTree();
        LOrExp.setVal(new Pair(this.lineNum, "<LOrExp>"));

        LOrExp.addNode(LAndExp());

        while (getToken(this.lineNum, this.colNum).getKey().equals(LexType.OR)) {
            Pair pair = getToken(this.lineNum, this.colNum);
            AbTree item = new AbTree();
            if (pair.getValue().equals("|")) {
                this.errors.add(new Error(this.lineNum, ErrorType.a));
            }
            item.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
            moveToNextWord();

            AbTree new_LOrExp = new AbTree();
            new_LOrExp.setVal(new Pair(this.lineNum, "<LOrExp>"));
            new_LOrExp.addNode(LOrExp);
            new_LOrExp.addNode(item);
            new_LOrExp.addNode(LAndExp());

            LOrExp = new_LOrExp;
        }
        return LOrExp;
    }

    // LAndExp → EqExp | LAndExp '&&' EqExp
    public AbTree LAndExp() {
        AbTree LAndExp = new AbTree();
        LAndExp.setVal(new Pair(this.lineNum, "<LAndExp>"));

        LAndExp.addNode(EqExp());

        while (getToken(this.lineNum, this.colNum).getKey().equals(LexType.AND)) {
            Pair pair = getToken(this.lineNum, this.colNum);
            AbTree item = new AbTree();
            if (pair.getValue().equals("&")) {
                this.errors.add(new Error(this.lineNum, ErrorType.a));
            }
            item.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
            moveToNextWord();

            AbTree new_LAndExp = new AbTree();
            new_LAndExp.setVal(new Pair(this.lineNum, "<LAndExp>"));
            new_LAndExp.addNode(LAndExp);
            new_LAndExp.addNode(item);
            new_LAndExp.addNode(EqExp());

            LAndExp = new_LAndExp;
        }
        return LAndExp;
    }

    //EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public AbTree EqExp() {
        AbTree EqExp = new AbTree();
        EqExp.setVal(new Pair(this.lineNum, "<EqExp>"));

        EqExp.addNode(RelExp());

        while (getToken(this.lineNum, this.colNum).getValue().equals("==")
                || getToken(this.lineNum, this.colNum).getValue().equals("!=")) {
            Pair pair = getToken(this.lineNum, this.colNum);
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
            moveToNextWord();

            AbTree new_EqExp = new AbTree();
            new_EqExp.setVal(new Pair(this.lineNum, "<EqExp>"));
            new_EqExp.addNode(EqExp);
            new_EqExp.addNode(item);
            new_EqExp.addNode(RelExp());

            EqExp = new_EqExp;
        }
        return EqExp;
    }

    //RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public AbTree RelExp() {
        AbTree RelExp = new AbTree();
        RelExp.setVal(new Pair(this.lineNum, "<RelExp>"));

        RelExp.addNode(AddExp());

        while (getToken(this.lineNum, this.colNum).getValue().equals("<")
                || getToken(this.lineNum, this.colNum).getValue().equals(">")
                || getToken(this.lineNum, this.colNum).getValue().equals("<=")
                || getToken(this.lineNum, this.colNum).getValue().equals(">=")) {
            Pair pair = getToken(this.lineNum, this.colNum);
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
            moveToNextWord();

            AbTree new_RelExp = new AbTree();
            new_RelExp.setVal(new Pair(this.lineNum, "<RelExp>"));
            new_RelExp.addNode(RelExp);
            new_RelExp.addNode(item);
            new_RelExp.addNode(AddExp());

            RelExp = new_RelExp;
        }
        return RelExp;
    }

    //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    public AbTree ConstDecl() {
        int error_line = 0;
        AbTree ConstDecl = new AbTree();
        ConstDecl.setVal(new Pair(this.lineNum, "<ConstDecl>"));

        String token = getToken(this.lineNum, this.colNum).getValue();
        AbTree node1 = new AbTree();
        node1.setVal(new Pair(this.lineNum, LexType.CONSTTK, token));
        moveToNextWord();
        ConstDecl.addNode(node1);

        ConstDecl.addNode(BType());

        error_line = this.lineNum;
        ConstDecl.addNode(ConstDef());

        while (getToken(this.lineNum, this.colNum).getValue().equals(",")) {
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, LexType.COMMA, ","));
            moveToNextWord();
            ConstDecl.addNode(item);

            error_line = this.lineNum;
            ConstDecl.addNode(ConstDef());
        }

        if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
            moveToNextWord();
            ConstDecl.addNode(item);
        } else {
            this.errors.add(new Error(error_line, ErrorType.i));
        }
        return ConstDecl;
    }

    //VarDecl → BType VarDef { ',' VarDef } ';'
    public AbTree VarDecl() {
        int error_line = 0;
        AbTree VarDecl = new AbTree();
        VarDecl.setVal(new Pair(this.lineNum, "<VarDecl>"));

        VarDecl.addNode(BType());

        error_line = this.lineNum;
        VarDecl.addNode(VarDef());

        while (getToken(this.lineNum, this.colNum).getValue().equals(",")) {
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, LexType.COMMA, ","));
            moveToNextWord();
            VarDecl.addNode(item);

            error_line = this.lineNum;
            VarDecl.addNode(VarDef());
        }

        if (getToken(this.lineNum, this.colNum).getValue().equals(";")) {
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, LexType.SEMICN, ";"));
            moveToNextWord();
            VarDecl.addNode(item);
        } else {
            this.errors.add(new Error(error_line, ErrorType.i));
        }
        return VarDecl;
    }

    //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public AbTree ConstDef() {
        int error_line = 0;
        AbTree ConstDef = new AbTree();
        ConstDef.setVal(new Pair(this.lineNum, "<ConstDef>"));

        AbTree node1 = new AbTree();
        node1.setVal(new Pair(this.lineNum, LexType.IDENFR, getToken(this.lineNum, this.colNum).getValue()));
        moveToNextWord();
        ConstDef.addNode(node1);

        if (getToken(this.lineNum, this.colNum).getValue().equals("[")) {
            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LBRACK, "["));
            moveToNextWord();
            ConstDef.addNode(item1);

            error_line = this.lineNum;
            ConstDef.addNode(ConstExp());

            if (getToken(this.lineNum, this.colNum).getValue().equals("]")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.RBRACK, "]"));
                moveToNextWord();
                ConstDef.addNode(item2);
            } else {
                this.errors.add(new Error(error_line, ErrorType.k));
            }
        }

        AbTree node2 = new AbTree();
        node2.setVal(new Pair(this.lineNum, LexType.ASSIGN, "="));
        moveToNextWord();
        ConstDef.addNode(node2);

        ConstDef.addNode(ConstInitVal());

        return ConstDef;
    }

    //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public AbTree VarDef() {
        int error_line = 0;
        AbTree VarDef = new AbTree();
        VarDef.setVal(new Pair(this.lineNum, "<VarDef>"));

        AbTree node1 = new AbTree();
        node1.setVal(new Pair(this.lineNum, LexType.IDENFR, getToken(this.lineNum, this.colNum).getValue()));
        moveToNextWord();
        VarDef.addNode(node1);

        if (getToken(this.lineNum, this.colNum).getValue().equals("[")) {
            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LBRACK, "["));
            moveToNextWord();
            VarDef.addNode(item1);

            error_line = this.lineNum;
            VarDef.addNode(ConstExp());

            if (getToken(this.lineNum, this.colNum).getValue().equals("]")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.RBRACK, "]"));
                moveToNextWord();
                VarDef.addNode(item2);
            } else {
                this.errors.add(new Error(error_line, ErrorType.k));
            }
        }
        if (getToken(this.lineNum, this.colNum).getValue().equals("=")) {
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, LexType.ASSIGN, "="));
            moveToNextWord();
            VarDef.addNode(item);

            VarDef.addNode(InitVal());
        }
        return VarDef;
    }

    //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public AbTree ConstInitVal() {
        AbTree ConstInitVal = new AbTree();
        ConstInitVal.setVal(new Pair(this.lineNum, "<ConstInitVal>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        String now = pair.getValue();
        LexType lexType = pair.getKey();
        if (now.equals("{")) {
            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LBRACE, "{"));
            moveToNextWord();
            ConstInitVal.addNode(item1);

            if (!getToken(this.lineNum, this.colNum).getValue().equals("}")) {
                ConstInitVal.addNode(ConstExp());
                while (getToken(this.lineNum, this.colNum).getValue().equals(",")) {
                    AbTree item = new AbTree();
                    item.setVal(new Pair(this.lineNum, LexType.COMMA, ","));
                    moveToNextWord();
                    ConstInitVal.addNode(item);

                    ConstInitVal.addNode(ConstExp());
                }
            }

            AbTree item2 = new AbTree();
            item2.setVal(new Pair(this.lineNum, LexType.RBRACE, "}"));
            moveToNextWord();
            ConstInitVal.addNode(item2);
        } else if (lexType.equals(LexType.STRCON)) {
            AbTree node = new AbTree();
            node.setVal(new Pair(this.lineNum, lexType, now));
            moveToNextWord();
            ConstInitVal.addNode(node);
        } else {
            ConstInitVal.addNode(ConstExp());
        }
        return ConstInitVal;
    }

    //InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public AbTree InitVal() {
        AbTree InitVal = new AbTree();
        InitVal.setVal(new Pair(this.lineNum, "<InitVal>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        String now = pair.getValue();
        LexType lexType = pair.getKey();
        if (now.equals("{")) {
            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LBRACE, "{"));
            moveToNextWord();
            InitVal.addNode(item1);

            if (!getToken(this.lineNum, this.colNum).getValue().equals("}")) {
                InitVal.addNode(Exp());
                while (getToken(this.lineNum, this.colNum).getValue().equals(",")) {
                    AbTree item = new AbTree();
                    item.setVal(new Pair(this.lineNum, LexType.COMMA, ","));
                    moveToNextWord();
                    InitVal.addNode(item);

                    InitVal.addNode(Exp());
                }
            }

            AbTree item2 = new AbTree();
            item2.setVal(new Pair(this.lineNum, LexType.RBRACE, "}"));
            moveToNextWord();
            InitVal.addNode(item2);
        } else if (lexType.equals(LexType.STRCON)) {
            AbTree node = new AbTree();
            node.setVal(new Pair(this.lineNum, lexType, now));
            moveToNextWord();
            InitVal.addNode(node);
        } else {
            InitVal.addNode(Exp());
        }
        return InitVal;
    }

    // ConstExp → AddExp
    public AbTree ConstExp() {
        AbTree ConstExp = new AbTree();
        ConstExp.setVal(new Pair(this.lineNum, "<ConstExp>"));

        ConstExp.addNode(AddExp());

        return ConstExp;
    }

    //AddExp → MulExp | AddExp ('+' | '−') MulExp
    public AbTree AddExp() {
        AbTree AddExp = new AbTree();
        AddExp.setVal(new Pair(this.lineNum, "<AddExp>"));

        AddExp.addNode(MulExp());

        while (getToken(this.lineNum, this.colNum).getValue().equals("+")
                || getToken(this.lineNum, this.colNum).getValue().equals("-")) {
            String now = getToken(this.lineNum, this.colNum).getValue();
            AbTree item = new AbTree();
            if (now.equals("+")) {
                item.setVal(new Pair(this.lineNum, LexType.PLUS, now));
            } else {
                item.setVal(new Pair(this.lineNum, LexType.MINU, now));
            }
            moveToNextWord();

            AbTree new_AddExp = new AbTree();
            new_AddExp.setVal(new Pair(this.lineNum, "<AddExp>"));
            new_AddExp.addNode(AddExp);
            new_AddExp.addNode(item);
            new_AddExp.addNode(MulExp());

            AddExp = new_AddExp;
        }
        return AddExp;
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public AbTree MulExp() {
        AbTree MulExp = new AbTree();
        MulExp.setVal(new Pair(this.lineNum, "<MulExp>"));

        MulExp.addNode(UnaryExp());

        while (getToken(this.lineNum, this.colNum).getValue().equals("*")
                || getToken(this.lineNum, this.colNum).getValue().equals("/")
                || getToken(this.lineNum, this.colNum).getValue().equals("%")) {
            String now = getToken(this.lineNum, this.colNum).getValue();
            AbTree item = new AbTree();
            if (now.equals("*")) {
                item.setVal(new Pair(this.lineNum, LexType.MULT, now));
            } else if (now.equals("/")) {
                item.setVal(new Pair(this.lineNum, LexType.DIV, now));
            } else {
                item.setVal(new Pair(this.lineNum, LexType.MOD, now));
            }
            moveToNextWord();

            AbTree new_MulExp = new AbTree();
            new_MulExp.setVal(new Pair(this.lineNum, "<MulExp>"));
            new_MulExp.addNode(MulExp);
            new_MulExp.addNode(item);
            new_MulExp.addNode(UnaryExp());

            MulExp = new_MulExp;
        }
        return MulExp;
    }

    //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public AbTree UnaryExp() {
        int error_line = 0;
        AbTree UnaryExp = new AbTree();
        UnaryExp.setVal(new Pair(this.lineNum, "<UnaryExp>"));

        String now = getToken(this.lineNum, this.colNum).getValue();
        if (isUnaryExpSecond(this.lineNum, this.colNum)) {
            AbTree node1 = new AbTree();
            node1.setVal(new Pair(this.lineNum, LexType.IDENFR, now));
            moveToNextWord();
            UnaryExp.addNode(node1);

            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LPARENT, "("));
            error_line = this.lineNum;
            moveToNextWord();
            UnaryExp.addNode(item1);

            if (isFuncRParams(getToken(this.lineNum, this.colNum))) {
                error_line = this.lineNum;
                UnaryExp.addNode(FuncRParams());
            }

            if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
                moveToNextWord();
                UnaryExp.addNode(item2);
            } else {
                this.errors.add(new Error(error_line, ErrorType.j));
            }
        } else if (isUnaryOp(now)) {
            UnaryExp.addNode(UnaryOp());

            UnaryExp.addNode(UnaryExp());
        } else {
            UnaryExp.addNode(PrimaryExp());
        }
        return UnaryExp;
    }

    //PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public AbTree PrimaryExp() {
        int error_line = 0;
        AbTree PrimaryExp = new AbTree();
        PrimaryExp.setVal(new Pair(this.lineNum, "<PrimaryExp>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        String now = pair.getValue();
        LexType lexType = pair.getKey();
        if (now.equals("(")) {
            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, lexType, now));
            moveToNextWord();
            PrimaryExp.addNode(item1);

            error_line = this.lineNum;
            PrimaryExp.addNode(Exp());

            if (getToken(this.lineNum, this.colNum).getValue().equals(")")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.RPARENT, ")"));
                moveToNextWord();
                PrimaryExp.addNode(item2);
            } else {
                this.errors.add(new Error(error_line, ErrorType.j));
            }
        } else if (lexType.equals(LexType.IDENFR)) {
            PrimaryExp.addNode(LVal());
        } else if (lexType.equals(LexType.INTCON)) {
            PrimaryExp.addNode(parseNumber());
        } else if (lexType.equals(LexType.CHRCON)) {
            PrimaryExp.addNode(parseCharacter());
        }
        return PrimaryExp;
    }

    //FuncFParams → FuncFParam { ',' FuncFParam }
    public AbTree FuncFParams() {
        AbTree FuncFParams = new AbTree();
        FuncFParams.setVal(new Pair(this.lineNum, "<FuncFParams>"));

        FuncFParams.addNode(FuncFParam());

        while (getToken(this.lineNum, this.colNum).getValue().equals(",")) {
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, LexType.COMMA, ","));
            moveToNextWord();
            FuncFParams.addNode(item);

            FuncFParams.addNode(FuncFParam());
        }
        return FuncFParams;
    }

    //FuncRParams → Exp { ',' Exp }
    public AbTree FuncRParams() {
        AbTree FuncRParams = new AbTree();
        FuncRParams.setVal(new Pair(this.lineNum, "<FuncRParams>"));

        FuncRParams.addNode(Exp());

        while (getToken(this.lineNum, this.colNum).getValue().equals(",")) {
            AbTree item = new AbTree();
            item.setVal(new Pair(this.lineNum, LexType.COMMA, ","));
            moveToNextWord();
            FuncRParams.addNode(item);

            FuncRParams.addNode(Exp());
        }
        return FuncRParams;
    }

    //FuncFParam → BType Ident ['[' ']']
    public AbTree FuncFParam() {
        int error_line = 0;
        AbTree FuncFParam = new AbTree();
        FuncFParam.setVal(new Pair(this.lineNum, "<FuncFParam>"));

        FuncFParam.addNode(BType());

        AbTree node2 = new AbTree();
        node2.setVal(new Pair(this.lineNum, LexType.IDENFR, getToken(this.lineNum, this.colNum).getValue()));
        moveToNextWord();
        FuncFParam.addNode(node2);

        if (getToken(this.lineNum, this.colNum).getValue().equals("[")) {
            AbTree item1 = new AbTree();
            item1.setVal(new Pair(this.lineNum, LexType.LBRACK, "["));
            error_line = this.lineNum;
            moveToNextWord();
            FuncFParam.addNode(item1);

            if (getToken(this.lineNum, this.colNum).getValue().equals("]")) {
                AbTree item2 = new AbTree();
                item2.setVal(new Pair(this.lineNum, LexType.RBRACK, "]"));
                moveToNextWord();
                FuncFParam.addNode(item2);
            } else {
                this.errors.add(new Error(error_line, ErrorType.k));
            }
        }
        return FuncFParam;
    }

    // Exp → AddExp
    public AbTree Exp() {
        AbTree Exp = new AbTree();
        Exp.setVal(new Pair(this.lineNum, "<Exp>"));

        Exp.addNode(AddExp());

        return Exp;
    }

    // FuncType → 'void' | 'int' | 'char'
    public AbTree FuncType() {
        AbTree FuncType = new AbTree();
        FuncType.setVal(new Pair(this.lineNum, "<FuncType>"));

        String token = getToken(this.lineNum, this.colNum).getValue();
        AbTree node = new AbTree();
        if (token.equals("void")) {
            node.setVal(new Pair(this.lineNum, LexType.VOIDTK, token));
        } else if (token.equals("int")) {
            node.setVal(new Pair(this.lineNum, LexType.INTTK, token));
        } else {
            node.setVal(new Pair(this.lineNum, LexType.CHARTK, token));
        }
        moveToNextWord();
        FuncType.addNode(node);

        return FuncType;
    }

    //UnaryOp → '+' | '−' | '!'
    public AbTree UnaryOp() {
        AbTree UnaryOp = new AbTree();
        UnaryOp.setVal(new Pair(this.lineNum, "<UnaryOp>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        AbTree node = new AbTree();
        node.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
        moveToNextWord();
        UnaryOp.addNode(node);

        return UnaryOp;
    }

    public AbTree parseNumber() {
        AbTree Number = new AbTree();
        Number.setVal(new Pair(this.lineNum, "<Number>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        AbTree node = new AbTree();
        node.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
        moveToNextWord();
        Number.addNode(node);

        return Number;
    }

    public AbTree parseCharacter() {
        AbTree Character = new AbTree();
        Character.setVal(new Pair(this.lineNum, "<Character>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        AbTree node = new AbTree();
        node.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
        moveToNextWord();
        Character.addNode(node);

        return Character;
    }

    //BType → 'int' | 'char'
    public AbTree BType() {
        AbTree BType = new AbTree();
        BType.setVal(new Pair(this.lineNum, "<BType>"));

        Pair pair = getToken(this.lineNum, this.colNum);
        AbTree node = new AbTree();
        node.setVal(new Pair(this.lineNum, pair.getKey(), pair.getValue()));
        moveToNextWord();
        BType.addNode(node);

        return BType;
    }

    public boolean isLValAndEqual(int lineNum, int colNum) {
        Pair pair = getToken(lineNum, colNum);
        if (pair.getKey().equals(LexType.IDENFR)) {
            colNum++;
            boolean flag = false;
            while (colNum < this.tokens.get(lineNum).size()) {
                if (getToken(lineNum, colNum).getValue().equals("=")) {
                    flag = true;
                }
                colNum++;
            }
            return flag;
        }
        return false;
    }

    public boolean isFuncFParams(String string) {
        return isBType(string);
    }

    public boolean isExp(Pair pair) {
        String string = pair.getValue();
        LexType lexType = pair.getKey();
        return string.equals("(") || lexType.equals(LexType.IDENFR) || lexType.equals(LexType.INTCON)
                || lexType.equals(LexType.CHRCON) || isUnaryOp(string);
    }

    public boolean isFuncRParams(Pair pair) {
        String string = pair.getValue();
        LexType lexType = pair.getKey();
        return string.equals("(") || lexType.equals(LexType.IDENFR) || lexType.equals(LexType.INTCON)
                || lexType.equals(LexType.CHRCON) || isUnaryOp(string);
    }

    public boolean isCond(Pair pair) {
        String string = pair.getValue();
        LexType lexType = pair.getKey();
        return string.equals("(") || lexType.equals(LexType.IDENFR) || lexType.equals(LexType.INTCON)
                || lexType.equals(LexType.CHRCON) || isUnaryOp(string);
    }

    public boolean isUnaryOp(String string) {
        return string.equals("+") || string.equals("-") || string.equals("!");
    }

    public boolean isUnaryExpSecond(int lineNum, int colNum) {
        Pair pair = getToken(lineNum, colNum);
        LexType lexType = pair.getKey();
        if (lexType.equals(LexType.IDENFR)) {
            colNum++;
            if (colNum >= this.tokens.get(lineNum).size()) {
                return false;
            }
            return getToken(lineNum, colNum).getValue().equals("(");
        }
        return false;
    }

    public boolean isFuncDef(int lineNum, int colNum) {
        String now = getToken(lineNum, colNum).getValue();
        if (now.equals("void")) {
            return true;
        } else if (now.equals("int") || now.equals("char")) {
            colNum++;
            LexType lexType = getToken(lineNum, colNum).getKey();
            if (lexType.equals(LexType.IDENFR)) {
                colNum++;
                return getToken(lineNum, colNum).getValue().equals("(");
            }
        }
        return false;
    }

    public boolean isDecl(int lineNum, int colNum) {
        String now = getToken(lineNum, colNum).getValue();
        if (now.equals("const")) {
            return true;
        } else {
            return isVarDecl(lineNum, colNum);
        }
    }

    public boolean isVarDecl(int lineNum, int colNum) {
        String now = getToken(lineNum, colNum).getValue();
        if (isBType(now)) {
            colNum++;// 加上空格
            return isVarDef(lineNum, colNum);
        }
        return false;
    }

    public boolean isVarDef(int lineNum, int colNum) {
        LexType lexType = getToken(lineNum, colNum).getKey();
        if (lexType.equals(LexType.IDENFR)) {
            colNum++;
            if (colNum >= this.tokens.get(lineNum).size()) {
                return true;
            }
            return !getToken(lineNum, colNum).getValue().equals("(");
        }
        return false;
    }

    public boolean isBType(String string) {
        return string.equals("int") || string.equals("char");
    }

    public void OutPut() {
        String answer = "parser.txt";
        String error = "error.txt";
        if (this.errors.isEmpty()) {
            try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(answer))) {
                for (Pair item : postOrder(this.mainTree)) {
                    if (item.getKey() != null) {
                        bufferedWriter.write(item.getKey().toString() + " " + item.getValue());
                        bufferedWriter.newLine();
                    } else {
                        if (!(item.getValue().equals("<BlockItem>")
                                || item.getValue().equals("<Decl>")
                                || item.getValue().equals("<BType>"))) {
                            bufferedWriter.write(item.getValue());
                            bufferedWriter.newLine();
                        }
                    }
                }
            } catch (IOException e) {
                System.err.println("Can't write " + answer);
            }
        } else {
            try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(error))) {
                for (int i = 0; i < this.errors.size(); i++) {
                    bufferedWriter.write(this.errors.get(i).getRow_line() + " " + this.errors.get(i).getErrorType());
                    bufferedWriter.newLine();
                }
            } catch (IOException e) {
                System.err.println("Can't write " + error);
            }
        }
    }

    public ArrayList<Pair> postOrder(AbTree root) {
        ArrayList<Pair> result = new ArrayList<>();
        postOrderHelper(root, result);
        return result;
    }

    public void postOrderHelper(AbTree node, ArrayList<Pair> result) {
        if (node == null) {
            return;
        }

        for (AbTree child : node.getNodes()) {
            postOrderHelper(child, result);
        }

        result.add(node.getVal());
    }
}
