package frontend;

import java.util.ArrayList;

public class Parser {
    private Errorlist errors;
    private ArrayList<Token> tokens;
    private int pos;
    private int errcnt;
    private ArrayList<String> outlist;

    public Parser(ArrayList<Token> tokens, Errorlist errors) {
        this.tokens = tokens;
        this.errors = errors;
        pos = 0;
        errcnt = 0;
        outlist = new ArrayList<>();
    }

    public void printall() {
        for (int i = 0;i < outlist.size();i++) {
            System.out.println(outlist.get(i));
        }
    }

    public void compileunit() {
        while (isdecl()) decl();
        while (isfuncdef()) Funcdef();
        Mainfuncdef();
        outlist.add("<CompUnit>");
    }

    public Token gettoken(int p) {
        if (p < 0 || p >= tokens.size()) {
            // System.err.println("invalid gettoken in p = " + p + "!");
            return null;
        }
        return tokens.get(p);
    }

    public boolean consume(Token token,Tokentype type, String value) {
        if (value == null) return token.gettype().equals(type);

        return token.getvalue().equals(value) && token.gettype().equals(type);
    }

    public void step() {
        outlist.add(gettoken(pos).toString());
        pos++;
    }

    public void consume_step(Tokentype type, String value) {
        Token token = gettoken(pos);
        if (consume(token, type, value)) step();
        else {
            String err = type.equals(Tokentype.RPARENT) ? "j" : 
                type.equals(Tokentype.RBRACK) ? "k" : 
                type.equals(Tokentype.SEMICN) ? "i" : null;
            errcnt ++;
            int line = gettoken(pos - 1).getline();
            if (errcnt == 1 && gettoken(pos).getline() - line == 2) {
                if (err.equals("i")) {
                }
            }

            Error e = new Error(err, line);
            errors.adderror(e);
        }
    }
    
    public boolean isBtype(Token t) {
        Tokentype ty = t.gettype();
        return ty.equals(Tokentype.INTTK) || ty.equals(Tokentype.CHARTK);
    }

    public void consume_Btype() {
        Token now = gettoken(pos);
        if (isBtype(now)) step();
    }

    public void consume_Functype() {
        Token now = gettoken(pos);
        if (isFunctype(now)) {
            step();
            outlist.add("<FuncType>");
        }
    }

    public boolean isdecl() {//pos too large?
        Token next1 = gettoken(pos);
        boolean x1 = next1.gettype().equals(Tokentype.INTTK) || next1.gettype().equals(Tokentype.CHARTK);
        if (!x1 && !next1.gettype().equals(Tokentype.CONSTTK)) return false;

        Token next2 = gettoken(pos + 1);
        Tokentype type2 = gettoken(pos + 1).gettype();
        boolean x2 = type2.equals(Tokentype.IDENFR);
        if (!x2 && !(isBtype(next2))) return false;

        Token next3 = gettoken(pos + 2);
        Tokentype type3 = next3.gettype();
        boolean x3 = !type3.equals(Tokentype.LPARENT);
        
        if (pos + 3 < tokens.size()) {
            Tokentype type4 = gettoken(pos + 3).gettype();
            if (consume(next1, Tokentype.CONSTTK, null)) {
                boolean y1 = type2.equals(Tokentype.INTTK) || type2.equals(Tokentype.CHARTK);
                boolean y2 = type3.equals(Tokentype.IDENFR);
                boolean y3 = !type4.equals(Tokentype.LPARENT);
                return y1 && y2 && y3;
            }
        }
        
        return x1 && x2 && x3;
    }

    public void decl() {
        if (gettoken(pos).gettype().equals(Tokentype.CONSTTK)) Constdecl();
        else Vardecl();
    }

    public void Constdecl() {
        consume_step(Tokentype.CONSTTK, null);
        consume_Btype();
        Tokentype now;
        do {
            Constdef();
            now = gettoken(pos).gettype();
            if (now.equals(Tokentype.COMMA)) {
                step();
            }
        } while (now.equals(Tokentype.COMMA));

        consume_step(Tokentype.SEMICN, null);
        outlist.add("<ConstDecl>");
    }

    public void Constdef() {
        consume_step(Tokentype.IDENFR, null);
        
        if (gettoken(pos).gettype().equals(Tokentype.LBRACK)) {
            step();
            ConstExp();
            consume_step(Tokentype.RBRACK, null);
        }
        consume_step(Tokentype.ASSIGN, null);

        ConstInitval();
        outlist.add("<ConstDef>");
    }

    public void Vardecl() {
        consume_Btype();

        Tokentype now;
        do {
            Vardef();
            now = gettoken(pos).gettype();
            if (now.equals(Tokentype.COMMA)) {
                step();
            }
        } while (now.equals(Tokentype.COMMA));
        consume_step(Tokentype.SEMICN, null);
        outlist.add("<VarDecl>");
    }

    public void Vardef() {
        consume_step(Tokentype.IDENFR, null);
        if (gettoken(pos).gettype().equals(Tokentype.LBRACK)) {
            consume_step(Tokentype.LBRACK, null);
            ConstExp();
            consume_step(Tokentype.RBRACK, null);
        }
        if (gettoken(pos).gettype().equals(Tokentype.ASSIGN)) {
            step();
            Initval();
        }
        outlist.add("<VarDef>");
    }

    public boolean isFunctype(Token t) {
        Tokentype ty = t.gettype();
        return ty.equals(Tokentype.VOIDTK) || ty.equals(Tokentype.CHARTK)
            || ty.equals(Tokentype.INTTK);
    }

    public boolean isfuncdef() {
        Token now = gettoken(pos);
        Tokentype ty1 = gettoken(pos + 1).gettype();
        
        if (pos + 2 >= tokens.size()) return false;

        Tokentype ty2 = gettoken(pos + 2).gettype();
        return isFunctype(now) && ty1.equals(Tokentype.IDENFR) && ty2.equals(Tokentype.LPARENT);
    }

    public void Funcdef() {
        consume_Functype();
        consume_step(Tokentype.IDENFR, null);
        consume_step(Tokentype.LPARENT, null);
        FuncFParams();
        consume_step(Tokentype.RPARENT, null);
        Block();
        outlist.add("<FuncDef>");
    }

    public void FuncFParams() {
        int sum = 0;
        while (FuncFParam() == 1) {sum++;}
        if (sum > 0) outlist.add("<FuncFParams>");
    }

    public int FuncFParam() {
        Token now = gettoken(pos);
        if (isBtype(now)) {
            consume_Btype();
            consume_step(Tokentype.IDENFR, null);
            Token iflbk = gettoken(pos);
            if (iflbk.gettype().equals(Tokentype.LBRACK)) {
                consume_step(Tokentype.LBRACK, null);
                consume_step(Tokentype.RBRACK, null);
            }
            Token next = gettoken(pos);
            outlist.add("<FuncFParam>"); 
            if (next.gettype().equals(Tokentype.COMMA)) {        
                step();    
            }
            return 1;
        }
        else {
            return 0;
        }
    }

    public void Exp() {
        Addexp();
        outlist.add("<Exp>");    
    }

    public boolean isExp() {
        return isAddexp();
    }

    public int consume_addop_andout() {
        Tokentype ty = gettoken(pos).gettype();
        if (ty.equals(Tokentype.PLUS) || ty.equals(Tokentype.MINU)) {
            outlist.add("<AddExp>");  
            step();
            return 0;
        }
        else return 1;
    }

    public void Addexp() {
        while (isMulexp()) {
            Mulexp();
            int end = consume_addop_andout();
            if(end == 1) break;
        }
        outlist.add("<AddExp>");  
    }

    public boolean isAddexp() {
        return isMulexp();
    }

    public boolean isMulexp() {
        return isUnaryexp();
    }

    public void Mulexp() {
        while (isUnaryexp()) {
            Unaryexp();
            int end = consume_mulop_andout();
            if (end == 1) break;     
        }
        outlist.add("<MulExp>");  
    }

    public int consume_mulop_andout() {
        Tokentype ty = gettoken(pos).gettype();
        if (ty.equals(Tokentype.MULT) || ty.equals(Tokentype.MOD) || ty.equals(Tokentype.DIV)) {
            outlist.add("<MulExp>"); 
            step();
            return 0;
        }
        return 1;
    }

    public boolean isUnaryexp() {
        if (isPrimaryExp()) return true;
        if (isFunc()) return true;
        return isunaryop();
    }

    public void Unaryexp() {
        if (isPrimaryExp()) {
            Primaryexp();
        }
        else if (isFunc()) {
            Func();
        }
        else {
            consume_unaryop();
            Unaryexp();
        }
        outlist.add("<UnaryExp>");  
    }

    public boolean isunaryop() {
        Tokentype ty = gettoken(pos).gettype();
        return ty.equals(Tokentype.PLUS) || ty.equals(Tokentype.MINU) 
            || ty.equals(Tokentype.NOT);
    }

    public void consume_unaryop() {
        Tokentype ty = gettoken(pos).gettype();
        if (ty.equals(Tokentype.PLUS) || ty.equals(Tokentype.MINU) || ty.equals(Tokentype.NOT)) {
            step();
            outlist.add("<UnaryOp>");
        }
    }
    
    public boolean isPrimaryExp() {
        Tokentype ty = gettoken(pos).gettype();
        boolean isexp = ty.equals(Tokentype.LPARENT);
        if(isexp) return true;
        boolean isLval = isLval();
        if(isLval) return true;
        boolean isnum = ty.equals(Tokentype.INTCON);
        boolean ischar = ty.equals(Tokentype.CHRCON);
        return isnum || ischar;
    }

    public void Primaryexp() {
        Tokentype ty = gettoken(pos).gettype();
        boolean isexp = ty.equals(Tokentype.LPARENT);
        if (isexp) {
            consume_step(Tokentype.LPARENT, null);
            Exp();
            consume_step(Tokentype.RPARENT, null);
            outlist.add("<PrimaryExp>");   
            return;
        }
        boolean isLval = isLval();
        if (isLval) {
            Lval();
            outlist.add("<PrimaryExp>");  
            return;
        }
        boolean isnum = ty.equals(Tokentype.INTCON);
        boolean ischar = ty.equals(Tokentype.CHRCON);
        if (isnum) {
            Number();
            outlist.add("<PrimaryExp>");  
        }
        else if(ischar) {
            Character();
            outlist.add("<PrimaryExp>"); 
        }
    }

    public void Number() {
        step();
        outlist.add("<Number>");
    }

    public void Character() {
        step();
        outlist.add("<Character>");
    }

    public boolean isLval() {
        Tokentype ty = gettoken(pos).gettype();
        if (!ty.equals(Tokentype.IDENFR)) return false;
        Tokentype next = gettoken(pos + 1).gettype();
        return !next.equals(Tokentype.LPARENT);
    }

    public void Lval() {
        consume_step(Tokentype.IDENFR, null);
        Tokentype ty = gettoken(pos).gettype();
        if (ty.equals(Tokentype.LBRACK)) {
            consume_step(Tokentype.LBRACK, null);
            Exp();
            consume_step(Tokentype.RBRACK, null);
        }
        outlist.add("<LVal>");  
    }

    public boolean isFunc() {
        Tokentype t1 = gettoken(pos).gettype();
        Tokentype t2 = gettoken(pos + 1).gettype();
        return t1.equals(Tokentype.IDENFR) && t2.equals(Tokentype.LPARENT);    
    }

    public void Func() {
        consume_step(Tokentype.IDENFR, null);
        consume_step(Tokentype.LPARENT, null);
        FuncRParams();
        consume_step(Tokentype.RPARENT, null);
    }

    public void FuncRParams() {
        int sum = 0;
        while (FuncRParam() == 1) {sum++;}
        if (sum > 0) outlist.add("<FuncRParams>");
    }

    public int FuncRParam() {
        if (gettoken(pos).gettype().equals(Tokentype.RPARENT)) return 0;
        if (isExp()) {            
            Exp();
            if (gettoken(pos).gettype().equals(Tokentype.COMMA)) {   
                step();
            }
            return 1;
        }
        else return 0;
        
    }

    public void Cond() {
        Lorexp();
        outlist.add("<Cond>");  
    }

    public void Lorexp() {
        while (isLandexp()) {
            Landexp();
            if (isorop()) {
                outlist.add("<LOrExp>");
                step();
            }
            else break;
        }
        outlist.add("<LOrExp>");
    }

    public boolean isorop() {
        Tokentype ty = gettoken(pos).gettype();
        return ty.equals(Tokentype.OR);
    }

    public boolean isLorexp() {
        return isLandexp();
    }

    public void Landexp() {
        while (isEqexp()) {
            Eqexp();
            if (isandop()) {
                outlist.add("<LAndExp>");
                step();
            }
            else break;
        }
        outlist.add("<LAndExp>");
    }

    public boolean isLandexp() {
        return isEqexp();
    }

    public boolean isandop() {
        Tokentype ty = gettoken(pos).gettype();
        return ty.equals(Tokentype.AND);
    } 

    public void Eqexp() {
        while (isRelexp()) {
            Relexp();
            if (iseqop()) {
                outlist.add("<EqExp>");
                step();
            }
            else break;
        }
        outlist.add("<EqExp>");
    }

    public boolean isEqexp() {
        return isRelexp();
    }

    public void Relexp() {
        while (isAddexp()) {
            Addexp();
            if (isRelop()) {
                outlist.add("<RelExp>");
                step();
            }
            else break;
        }
        outlist.add("<RelExp>");
    }

    public boolean isRelexp() {
        return isAddexp();
    }

    public boolean isRelop() {
        Tokentype ty = gettoken(pos).gettype();
        return ty.equals(Tokentype.LEQ) || ty.equals(Tokentype.LSS)
            || ty.equals(Tokentype.GEQ) || ty.equals(Tokentype.GRE);
    }

    public boolean iseqop() {
        Tokentype ty = gettoken(pos).gettype();
        return ty.equals(Tokentype.EQL) || ty.equals(Tokentype.NEQ);
    }

    public boolean isBlock() {
        return gettoken(pos).gettype().equals(Tokentype.LBRACE);
    }

    public void Block() {
        consume_step(Tokentype.LBRACE, null);
        while (BlockItem() == 1) {}
        consume_step(Tokentype.RBRACE, null);
        outlist.add("<Block>");
    }

    public int BlockItem() {
        if (gettoken(pos).gettype().equals(Tokentype.RBRACE)) return 0;
        if (isdecl()) decl();
        else if (isStmt()) Stmt();
        else return 0;

        return 1;
    }

    public boolean isBlockItem() {
        return isdecl() || isStmt();
    }

    public boolean isStmt() {
        Tokentype now = gettoken(pos).gettype();
        if (now.equals(Tokentype.SEMICN)) return true;
        if (now.equals(Tokentype.LBRACE)) return true;

        if (isExp()) return true;

        if (now.equals(Tokentype.IFTK)) return true;
        if (now.equals(Tokentype.FORTK)) return true;
        if (now.equals(Tokentype.BREAKTK)) return true;
        if (now.equals(Tokentype.RETURNTK)) return true;
        if (now.equals(Tokentype.CONTINUETK)) return true;
        if (now.equals(Tokentype.PRINTFTK)) return true;
        
        if (isLval()) return true;
        return false;
    }

    public void Stmt() {
        Tokentype now = gettoken(pos).gettype();
        if (now.equals(Tokentype.SEMICN)) {
            step(); 
            outlist.add("<Stmt>"); 
            return;
        }
        else if (now.equals(Tokentype.LBRACE)) Block();

        else if (now.equals(Tokentype.IFTK)) Ifstmt();
        
        else if (now.equals(Tokentype.FORTK)) Forstmt();
        
        else if (now.equals(Tokentype.RETURNTK)) Returnstmt();

        else if (now.equals(Tokentype.BREAKTK)) easystmt();
        
        else if (now.equals(Tokentype.CONTINUETK)) easystmt();

        else if (now.equals(Tokentype.PRINTFTK)) Printfstmt(); 
        
        else if (islvalassign()) {
            Lvalstmt(); 
        }
        else if (isExp()) {
            Exp();
            consume_step(Tokentype.SEMICN, null);
        }
        outlist.add("<Stmt>");       
    }

    public boolean islvalassign() {
        if (!isLval()) return false;
        int line = gettoken(pos).getline();
        for (int i = pos + 1;i < tokens.size();i++) {
            Token t = tokens.get(i);
            if (t.getline() > line) break;
            if (t.gettype().equals(Tokentype.ASSIGN)) return true;
        }
        return false;
    }

    public void Printfstmt() {
        step();
        consume_step(Tokentype.LPARENT, null);
        consume_step(Tokentype.STRCON, null);

        Tokentype now = gettoken(pos).gettype();
        while (now.equals(Tokentype.COMMA)) {
            step();
            Exp();
            now = gettoken(pos).gettype();
        }

        consume_step(Tokentype.RPARENT, null);
        consume_step(Tokentype.SEMICN, null);
    }

    public void easystmt() {
        step();
        consume_step(Tokentype.SEMICN, null);
    }

    public void Lvalstmt() {
        Lval();
        consume_step(Tokentype.ASSIGN, null);
        Tokentype lval = gettoken(pos).gettype();
        if (lval.equals(Tokentype.GETINTTK) || lval.equals(Tokentype.GETCHARTK)) {
            step();
            consume_step(Tokentype.LPARENT, null);
            consume_step(Tokentype.RPARENT, null);
        }
        else Exp();

        consume_step(Tokentype.SEMICN, null);
    }

    public void Ifstmt() {
        step();
        consume_step(Tokentype.LPARENT, null);
        Cond();
        consume_step(Tokentype.RPARENT, null);
        Stmt();
        
        Tokentype elsetk = gettoken(pos).gettype();
        if (elsetk.equals(Tokentype.ELSETK)) {
            step();
            Stmt();
        }
    }

    public void Forstmt() {
        step();
        consume_step(Tokentype.LPARENT, null);
        
        if (!issemicn()) for_stmt();
        consume_step(Tokentype.SEMICN, null);
        if (!issemicn()) Cond();
        consume_step(Tokentype.SEMICN, null);
        
        if (isfor_stmt()) for_stmt();

        consume_step(Tokentype.RPARENT, null);
        
        Stmt();
    }

    public boolean issemicn() {
        return gettoken(pos).gettype().equals(Tokentype.SEMICN);
    }

    public void for_stmt() {//for括号内部的两个语句（可以缺省）
        Lval();
        consume_step(Tokentype.ASSIGN, null);
        Exp();
        outlist.add("<ForStmt>");
    }

    public boolean isfor_stmt() {
        return isLval();
    }

    public void Returnstmt() {
        step();
        if (!issemicn()) Exp();
        consume_step(Tokentype.SEMICN, null); 
    }

    public void Mainfuncdef() {
        consume_step(Tokentype.INTTK, null);
        consume_step(Tokentype.MAINTK, null);
        consume_step(Tokentype.LPARENT, null);
        consume_step(Tokentype.RPARENT, null);
        Block();
        outlist.add("<MainFuncDef>");
    }

    public void ConstInitval() {
        Tokentype here = gettoken(pos).gettype();
        if (here.equals(Tokentype.LBRACE)) {
            Tokentype now;
            do {
                step();
                ConstExp();
                now = gettoken(pos).gettype();
            } while (now.equals(Tokentype.COMMA));
            consume_step(Tokentype.RBRACE, null);
        }
        else if (here.equals(Tokentype.STRCON)) {
            step();
        }
        else ConstExp();
        outlist.add("<ConstInitVal>");
    }

    public void Initval() {
        if (gettoken(pos).gettype().equals(Tokentype.STRCON)) {
            step();
            outlist.add("<InitVal>");
            return;
        }
        else if (gettoken(pos).gettype().equals(Tokentype.LBRACE)) {
            Tokentype now;
            do {
                step();
                Exp();
                now = gettoken(pos).gettype();
            } while (now.equals(Tokentype.COMMA));

            consume_step(Tokentype.RBRACE, null);
        }
        else Exp();
        outlist.add("<InitVal>");
    }

    public void ConstExp() {
        if (!isAddexp()) return;
        Addexp();
        outlist.add("<ConstExp>");
    }
}