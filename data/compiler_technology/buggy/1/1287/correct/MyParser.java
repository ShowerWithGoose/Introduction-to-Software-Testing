import java.util.ArrayList;

public class MyParser {
    private ArrayList<Token> tokens;
    private ArrayList<Error> errors;
    private int pos = 0;

    public MyParser(ArrayList<Token> tokens, ArrayList<Error> errors) {
        this.tokens = tokens;
        this.errors = errors;
    }

    public LexType nowRead() {
        return tokens.get(pos).getLexType();
    }

    public boolean isBType(LexType lexType) {
        return lexType.equals(LexType.INTTK) || lexType.equals(LexType.CHARTK);
    }

    public boolean isExpFirst(LexType lexType) {
        return lexType.equals(LexType.LPARENT) || lexType.equals(LexType.IDENFR)
                || lexType.equals(LexType.INTCON) || lexType.equals(LexType.CHRCON)
                || lexType.equals(LexType.PLUS) || lexType.equals(LexType.MINU)
                || lexType.equals(LexType.NOT);
    }

    public boolean isDeclFirst(LexType lexType) {
        return lexType.equals(LexType.CONSTTK) || isBType(lexType);
    }

    public boolean isStmtFisrt(LexType lexType) {
        return lexType.equals(LexType.IDENFR) || isExpFirst(lexType)
                || lexType.equals(LexType.SEMICN) || lexType.equals(LexType.LBRACE)
                || lexType.equals(LexType.IFTK) || lexType.equals(LexType.FORTK)
                || lexType.equals(LexType.RETURNTK) || lexType.equals(LexType.PRINTFTK)
                || lexType.equals(LexType.BREAKTK) || lexType.equals(LexType.CONTINUETK);
    }

    public boolean isLValAndAssign() {
        int tmp = pos;
        int top1 = errors.size();
        LVal();
        int top2 = errors.size();
        if (top2 > top1) {
            errors.subList(top1, top2).clear();
        }
        boolean flag = nowRead().equals(LexType.ASSIGN);
        pos = tmp;
        return flag;
    }

    public LexType preRead(int n) {
        return tokens.get(pos + n).getLexType();
    }

    public int getPreLineNum() {
        return tokens.get(pos - 1).getLineNum();
    }

    public Node CompUnit() {
        Element root = new Element(ParseType.CompUnit);
        while (pos < tokens.size() && (nowRead().equals(LexType.CONSTTK) ||
                nowRead().equals(LexType.VOIDTK) || isBType(nowRead()))) {
            if (nowRead().equals(LexType.CONSTTK)) {
                root.addNode(ConstDecl());
            }
            else {
                if (preRead(1).equals(LexType.MAINTK)) {
                    root.addNode(MainFuncDef());
                }
                else if (preRead(1).equals(LexType.IDENFR)) {
                    if (preRead(2).equals(LexType.LPARENT)) {
                        root.addNode(FuncDef());
                    }
                    else {
                        root.addNode(VarDecl());
                    }
                }
                else {
                    error();
                }
            }
        }
        return root;
    }

    public Node ConstDecl() {
        Element ret = new Element(ParseType.ConstDecl);
        if (!nowRead().equals(LexType.CONSTTK)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (!isBType(nowRead())) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                ret.addNode(ConstDef());
                while (nowRead().equals(LexType.COMMA)) {
                    ret.addNode(tokens.get(pos++));
                    ret.addNode(ConstDef());
                }
                if (!nowRead().equals(LexType.SEMICN)) {
                    errors.add(new Error(getPreLineNum(), "i"));
                    ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
            }
        }
        return ret;
    }

    public Node ConstDef() {
        Element ret = new Element(ParseType.ConstDef);
        if (!nowRead().equals(LexType.IDENFR)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (nowRead().equals(LexType.LBRACK)) {
                ret.addNode(tokens.get(pos++));
                ret.addNode(ConstExp());
                if (!nowRead().equals(LexType.RBRACK)) {
                    errors.add(new Error(getPreLineNum(), "k"));
                    ret.addNode(new Token(LexType.RBRACK, "]", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
            }
            if (!nowRead().equals(LexType.ASSIGN)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                ret.addNode(ConstInitVal());
            }
        }
        return ret;
    }

    public Node ConstExp() {
        Element ret = new Element(ParseType.ConstExp);
        ret.addNode(AddExp());
        return ret;
    }

    public Node ConstInitVal() {
        Element ret = new Element(ParseType.ConstInitVal);
        if (isExpFirst(nowRead())) {
            ret.addNode(ConstExp());
        }
        else if (nowRead().equals(LexType.LBRACE)) {
            ret.addNode(tokens.get(pos++));
            if (isExpFirst(nowRead())) {
                ret.addNode(ConstExp());
                while (nowRead().equals(LexType.COMMA)) {
                    ret.addNode(tokens.get(pos++));
                    ret.addNode(ConstExp());
                }
            }
            if (!nowRead().equals(LexType.RBRACE)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
            }
        }
        else if (nowRead().equals(LexType.STRCON)) {
            ret.addNode(tokens.get(pos++));
        }
        else {
            error();
        }
        return ret;
    }

    public Node VarDecl() {
        Element ret = new Element(ParseType.VarDecl);
        if (!isBType(nowRead())) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            ret.addNode(VarDef());
            while (nowRead().equals(LexType.COMMA)) {
                ret.addNode(tokens.get(pos++));
                ret.addNode(VarDef());
            }
            if (!nowRead().equals(LexType.SEMICN)) {
                errors.add(new Error(getPreLineNum(), "i"));
                ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
            }
            else {
                ret.addNode(tokens.get(pos++));
            }
        }
        return ret;
    }

    public Node VarDef() {
        Element ret = new Element(ParseType.VarDef);
        if (!nowRead().equals(LexType.IDENFR)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (nowRead().equals(LexType.LBRACK)) {
                ret.addNode(tokens.get(pos++));
                ret.addNode(ConstExp());
                if (!nowRead().equals(LexType.RBRACK)) {
                    errors.add(new Error(getPreLineNum(), "k"));
                    ret.addNode(new Token(LexType.RBRACK, "]", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
            }
            if (nowRead().equals(LexType.ASSIGN)) {
                ret.addNode(tokens.get(pos++));
                ret.addNode(InitVal());
            }
        }
        return ret;
    }

    public Node InitVal() {
        Element ret = new Element(ParseType.InitVal);
        if (isExpFirst(nowRead())) {
            ret.addNode(Exp());
        }
        else if (nowRead().equals(LexType.LBRACE)) {
            ret.addNode(tokens.get(pos++));
            if (isExpFirst(nowRead())) {
                ret.addNode(Exp());
                while (nowRead().equals(LexType.COMMA)) {
                    ret.addNode(tokens.get(pos++));
                    ret.addNode(Exp());
                }
            }
            if (!nowRead().equals(LexType.RBRACE)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
            }
        }
        else if (nowRead().equals(LexType.STRCON)) {
            ret.addNode(tokens.get(pos++));
        }
        else {
            error();
        }
        return ret;
    }

    public Node FuncDef() {
        Element ret = new Element(ParseType.FuncDef);
        ret.addNode(FuncType());
        if (!nowRead().equals(LexType.IDENFR)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (!nowRead().equals(LexType.LPARENT)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                if (isBType(nowRead())) {
                    ret.addNode(FuncFParams());
                }
                if (!nowRead().equals(LexType.RPARENT)) {
                    errors.add(new Error(getPreLineNum(), "j"));
                    ret.addNode(new Token(LexType.RPARENT, ")", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
                ret.addNode(Block());

            }
        }
        return ret;
    }

    public Node FuncType() {
        Element ret = new Element(ParseType.FuncType);
        if (nowRead().equals(LexType.VOIDTK) || nowRead().equals(LexType.INTTK)
                || nowRead().equals(LexType.CHARTK)) {
            ret.addNode(tokens.get(pos++));
        }
        else {
            error();
        }
        return ret;
    }

    public Node FuncFParams() {
        Element ret = new Element(ParseType.FuncFParams);
        ret.addNode(FuncFParam());
        while (nowRead().equals(LexType.COMMA)) {
            ret.addNode(tokens.get(pos++));
            ret.addNode(FuncFParam());
        }
        return ret;
    }

    public Node FuncFParam() {
        Element ret = new Element(ParseType.FuncFParam);
        if (!isBType(nowRead())) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (!nowRead().equals(LexType.IDENFR)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                if (nowRead().equals(LexType.LBRACK)) {
                    ret.addNode(tokens.get(pos++));
                    if (!nowRead().equals(LexType.RBRACK)) {
                        errors.add(new Error(getPreLineNum(), "k"));
                        ret.addNode(new Token(LexType.RBRACK, "]", getPreLineNum()));
                    }
                    else {
                        ret.addNode(tokens.get(pos++));
                    }
                }
            }
        }
        return ret;
    }

    public Node Block() {
        Element ret = new Element(ParseType.Block);
        if (!nowRead().equals(LexType.LBRACE)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            while (isDeclFirst(nowRead()) || isStmtFisrt(nowRead())) {
                if (isBType(nowRead())) {
                    ret.addNode(VarDecl());
                }
                else if (nowRead().equals(LexType.CONSTTK)) {
                    ret.addNode(ConstDecl());
                }
                else {
                    ret.addNode(Stmt());
                }
            }
            if (!nowRead().equals(LexType.RBRACE)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
            }
        }
        return ret;
    }

    public Node MainFuncDef() {
        Element ret = new Element(ParseType.MainFuncDef);
        if (!nowRead().equals(LexType.INTTK)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (!nowRead().equals(LexType.MAINTK)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                if (!nowRead().equals(LexType.LPARENT)) {
                    error();
                }
                else {
                    ret.addNode(tokens.get(pos++));
                    if (!nowRead().equals(LexType.RPARENT)) {
                        errors.add(new Error(getPreLineNum(), "j"));
                        ret.addNode(new Token(LexType.RPARENT, ")", getPreLineNum()));
                    }
                    else {
                        ret.addNode(tokens.get(pos++));
                    }
                    ret.addNode(Block());
                }
            }
        }
        return ret;
    }

    public Node ForStmt() {
        Element ret = new Element(ParseType.ForStmt);
        ret.addNode(LVal());
        if (!nowRead().equals(LexType.ASSIGN)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            ret.addNode(Exp());
        }
        return ret;
    }

    public Node Stmt() {
        if (nowRead().equals(LexType.IFTK)) {
            return IF();
        }
        else if (nowRead().equals(LexType.FORTK)) {
            return FOR();
        }
        else if (nowRead().equals(LexType.RETURNTK)) {
            return RETURN();
        }
        else if (nowRead().equals(LexType.PRINTFTK)) {
            return OUTPUT();
        }
        else if (nowRead().equals(LexType.BREAKTK) || nowRead().equals(LexType.CONTINUETK)) {
            Element ret = new Element(ParseType.Stmt);
            ret.addNode(tokens.get(pos++));
            if (!nowRead().equals(LexType.SEMICN)) {
                errors.add(new Error(getPreLineNum(), "i"));
                ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
                return ret;
            }
            else {
                ret.addNode(tokens.get(pos++));
                return ret;
            }
        }
        else if (nowRead().equals(LexType.LBRACE)) {
            Element ret = new Element(ParseType.Stmt);
            ret.addNode(Block());
            return ret;
        }
        else if (nowRead().equals(LexType.IDENFR)) {
            if (isLValAndAssign()) {
                return ASSIGN();
            }
            else return EXP();
        }
        else {
            return EXP();
        }
    }

    public Node FOR() {
        Element ret = new Element(ParseType.Stmt);
        if (!nowRead().equals(LexType.FORTK)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (!nowRead().equals(LexType.LPARENT)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                if (nowRead().equals(LexType.IDENFR)) {
                    ret.addNode(ForStmt());
                }
                if (!nowRead().equals(LexType.SEMICN)) {
                    error();
                }
                else {
                    ret.addNode(tokens.get(pos++));
                    if (isExpFirst(nowRead())) {
                        ret.addNode(Cond());
                    }
                    if (!nowRead().equals(LexType.SEMICN)) {
                        error();
                    }
                    else {
                        ret.addNode(tokens.get(pos++));
                        if (nowRead().equals(LexType.IDENFR)) {
                            ret.addNode(ForStmt());
                        }
                        if (!nowRead().equals(LexType.RPARENT)) {
                            error();
                        }
                        else {
                            ret.addNode(tokens.get(pos++));
                            ret.addNode(Stmt());
                        }
                    }
                }
            }
        }
        return ret;
    }

    public Node IF() {
        Element ret = new Element(ParseType.Stmt);
        if (!nowRead().equals(LexType.IFTK)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (!nowRead().equals(LexType.LPARENT)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                ret.addNode(Cond());
                if (!nowRead().equals(LexType.RPARENT)) {
                    errors.add(new Error(getPreLineNum(), "j"));
                    ret.addNode(new Token(LexType.RPARENT, ")", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
                ret.addNode(Stmt());
                if (nowRead().equals(LexType.ELSETK)) {
                    ret.addNode(tokens.get(pos++));
                    ret.addNode(Stmt());
                }
            }
        }
        return ret;
    }

    public Node ASSIGN() {
        Element ret = new Element(ParseType.Stmt);
        ret.addNode(LVal());
        if (!nowRead().equals(LexType.ASSIGN)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (isExpFirst(nowRead())) {
                ret.addNode(Exp());
                if (!nowRead().equals(LexType.SEMICN)) {
                    errors.add(new Error(getPreLineNum(), "i"));
                    ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
            }
            else if (nowRead().equals(LexType.GETINTTK) || nowRead().equals(LexType.GETCHARTK)){
                ret.addNode(tokens.get(pos++));
                if (!nowRead().equals(LexType.LPARENT)) {
                    error();
                }
                else {
                    ret.addNode(tokens.get(pos++));
                    if (!nowRead().equals(LexType.RPARENT)) {
                        errors.add(new Error(getPreLineNum(), "j"));
                        ret.addNode(new Token(LexType.RPARENT, ")", getPreLineNum()));
                    }
                    else {
                        ret.addNode(tokens.get(pos++));
                    }
                    if (!nowRead().equals(LexType.SEMICN)) {
                        errors.add(new Error(getPreLineNum(), "i"));
                        ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
                    }
                    else {
                        ret.addNode(tokens.get(pos++));
                    }
                }
            }
            else {
                error();
            }
        }
        return ret;
    }

    public Node OUTPUT() {
        Element ret = new Element(ParseType.Stmt);
        if (!nowRead().equals(LexType.PRINTFTK)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (!nowRead().equals(LexType.LPARENT)) {
                error();
            }
            else {
                ret.addNode(tokens.get(pos++));
                if (!nowRead().equals(LexType.STRCON)) {
                    error();
                }
                else {
                    ret.addNode(tokens.get(pos++));
                    while (nowRead().equals(LexType.COMMA)) {
                        ret.addNode(tokens.get(pos++));
                        ret.addNode(Exp());
                    }
                    if (!nowRead().equals(LexType.RPARENT)) {
                        errors.add(new Error(getPreLineNum(), "j"));
                        ret.addNode(new Token(LexType.RPARENT, ")", getPreLineNum()));
                    }
                    else {
                        ret.addNode(tokens.get(pos++));
                    }
                    if (!nowRead().equals(LexType.SEMICN)) {
                        errors.add(new Error(getPreLineNum(), "i"));
                        ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
                    }
                    else {
                        ret.addNode(tokens.get(pos++));
                    }
                }
            }
        }
        return ret;
    }

    public Node RETURN() {
        Element ret = new Element(ParseType.Stmt);
        if (!nowRead().equals(LexType.RETURNTK)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            int tmp = pos;
            if (isExpFirst(nowRead())) {
                int top1 = errors.size();
                Exp();
                int top2 = errors.size();
                if (top2 > top1) {
                    errors.subList(top1, top2).clear();
                }
                if (nowRead().equals(LexType.ASSIGN)) {
                    errors.add(new Error(tokens.get(tmp - 1).getLineNum(), "i"));
                    ret.addNode(new Token(LexType.SEMICN, ";", tokens.get(tmp - 1).getLineNum()));
                    pos = tmp;
                    return ret;
                }
                else if (!nowRead().equals(LexType.SEMICN)) {
                    pos = tmp;
                    ret.addNode(Exp());
                    errors.add(new Error(getPreLineNum(), "i"));
                    ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
                    return ret;
                }
                else {
                    pos = tmp;
                    ret.addNode(Exp());
                    ret.addNode(tokens.get(pos++));
                    return ret;
                }
            }
            else if (!nowRead().equals(LexType.SEMICN)) {
                errors.add(new Error(getPreLineNum(), "i"));
                ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
                return ret;
            }
            else {
                ret.addNode(tokens.get(pos++));
                return ret;
            }
        }
        return ret;
    }

    public Node EXP() {
        Element ret = new Element(ParseType.Stmt);
        if (isExpFirst(nowRead())) {
            ret.addNode(Exp());
        }
        if (!nowRead().equals(LexType.SEMICN)) {
            errors.add(new Error(getPreLineNum(), "i"));
            ret.addNode(new Token(LexType.SEMICN, ";", getPreLineNum()));
        }
        else {
            ret.addNode(tokens.get(pos++));
        }
        return ret;
    }

    public Node LOrExp() {
        Element ret = new Element(ParseType.LOrExp);
        ret.addNode(LAndExp());
        while (nowRead().equals(LexType.OR)) {
            Element tmp = new Element(ParseType.LOrExp);
            tmp.addNode(ret);
            tmp.addNode(tokens.get(pos++));
            tmp.addNode(LAndExp());
            ret = tmp;
        }
        return ret;
    }

    public Node LAndExp() {
        Element ret = new Element(ParseType.LAndExp);
        ret.addNode(EqExp());
        while (nowRead().equals(LexType.AND)) {
            Element tmp = new Element(ParseType.LAndExp);
            tmp.addNode(ret);
            tmp.addNode(tokens.get(pos++));
            tmp.addNode(EqExp());
            ret = tmp;
        }
        return ret;
    }

    public Node EqExp() {
        Element ret = new Element(ParseType.EqExp);
        ret.addNode(RelExp());
        while (nowRead().equals(LexType.EQL) || nowRead().equals(LexType.NEQ)) {
            Element tmp = new Element(ParseType.EqExp);
            tmp.addNode(ret);
            tmp.addNode(tokens.get(pos++));
            tmp.addNode(RelExp());
            ret = tmp;
        }
        return ret;
    }

    public Node RelExp() {
        Element ret = new Element(ParseType.RelExp);
        ret.addNode(AddExp());
        while (nowRead().equals(LexType.LSS) || nowRead().equals(LexType.GRE) ||
                nowRead().equals(LexType.LEQ) || nowRead().equals(LexType.GEQ)) {
            Element tmp = new Element(ParseType.RelExp);
            tmp.addNode(ret);
            tmp.addNode(tokens.get(pos++));
            tmp.addNode(AddExp());
            ret = tmp;
        }
        return ret;
    }

    public Node Exp() {
        Element ret = new Element(ParseType.Exp);
        ret.addNode(AddExp());
        return ret;
    }

    public Node Cond() {
        Element ret = new Element(ParseType.Cond);
        ret.addNode(LOrExp());
        return ret;
    }

    public Node AddExp() {
        Element ret = new Element(ParseType.AddExp);
        ret.addNode(MulExp());
        while (nowRead().equals(LexType.PLUS) || nowRead().equals(LexType.MINU)) {
            Element tmp = new Element(ParseType.AddExp);
            tmp.addNode(ret);
            tmp.addNode(tokens.get(pos++));
            tmp.addNode(MulExp());
            ret = tmp;
        }
        return ret;
    }

    public Node MulExp() {
        Element ret = new Element(ParseType.MulExp);
        ret.addNode(UnaryExp());
        while (nowRead().equals(LexType.MULT) ||
                nowRead().equals(LexType.DIV) || nowRead().equals(LexType.MOD)) {
            Element tmp = new Element(ParseType.MulExp);
            tmp.addNode(ret);
            tmp.addNode(tokens.get(pos++));
            tmp.addNode(UnaryExp());
            ret = tmp;
        }
        return ret;
    }

    public Node UnaryExp() {
        Element ret = new Element(ParseType.UnaryExp);
        if (nowRead().equals(LexType.LPARENT) || nowRead().equals(LexType.INTCON)
                || nowRead().equals(LexType.CHRCON)) {
            ret.addNode(PrimaryExp());
        }
        else if (nowRead().equals(LexType.PLUS) || nowRead().equals(LexType.MINU)
                || nowRead().equals(LexType.NOT)) {
            ret.addNode(UnaryOp());
            ret.addNode(UnaryExp());
        }
        else if (nowRead().equals(LexType.IDENFR)) {
            if (preRead(1).equals(LexType.LPARENT)) {
                ret.addNode(tokens.get(pos++));
                ret.addNode(tokens.get(pos++));
                if (isExpFirst(nowRead())) {
                    ret.addNode(FuncRParams());
                }
                if (!nowRead().equals(LexType.RPARENT)) {
                    errors.add(new Error(getPreLineNum(), "j"));
                    ret.addNode(new Token(LexType.RPARENT, ")", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
            }
            else {
                ret.addNode(PrimaryExp());
            }
        }
        else {
            error();
        }
        return ret;
    }

    public Node UnaryOp() {
        Element ret = new Element(ParseType.UnaryOp);
        if (nowRead().equals(LexType.PLUS) || nowRead().equals(LexType.MINU)
                || nowRead().equals(LexType.NOT)) {
            ret.addNode(tokens.get(pos++));
        }
        else {
            error();
        }
        return ret;
    }

    public Node PrimaryExp() {
        Element ret = new Element(ParseType.PrimaryExp);
        if (nowRead().equals(LexType.LPARENT)) {
            ret.addNode(tokens.get(pos++));
            ret.addNode(Exp());
            if (!nowRead().equals(LexType.RPARENT)) {
                errors.add(new Error(getPreLineNum(), "j"));
                ret.addNode(new Token(LexType.RPARENT, ")", getPreLineNum()));
            }
            else {
                ret.addNode(tokens.get(pos++));
            }
        }
        else if (nowRead().equals(LexType.IDENFR)) {
            ret.addNode(LVal());
        }
        else if (nowRead().equals(LexType.INTCON)) {
            ret.addNode(Number());
        }
        else if (nowRead().equals(LexType.CHRCON)) {
            ret.addNode(Character());
        }
        else {
            error();
        }
        return ret;
    }

    public Node LVal() {
        Element ret = new Element(ParseType.LVal);
        if (!nowRead().equals(LexType.IDENFR)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
            if (nowRead().equals(LexType.LBRACK)) {
                ret.addNode(tokens.get(pos++));
                ret.addNode(Exp());
                if (!nowRead().equals(LexType.RBRACK)) {
                    errors.add(new Error(getPreLineNum(), "k"));
                    ret.addNode(new Token(LexType.RBRACK, "]", getPreLineNum()));
                }
                else {
                    ret.addNode(tokens.get(pos++));
                }
            }
        }
        return ret;
    }

    public Node Number() {
        Element ret = new Element(ParseType.Number);
        if (!nowRead().equals(LexType.INTCON)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
        }
        return ret;
    }

    public Node Character() {
        Element ret = new Element(ParseType.Character);
        if (!nowRead().equals(LexType.CHRCON)) {
            error();
        }
        else {
            ret.addNode(tokens.get(pos++));
        }
        return ret;
    }

    public Node FuncRParams() {
        Element ret = new Element(ParseType.FuncRParams);
        ret.addNode(Exp());
        while (nowRead().equals(LexType.COMMA)) {
            ret.addNode(tokens.get(pos++));
            ret.addNode(Exp());
        }
        return ret;
    }

    public void error() {

    }
}
