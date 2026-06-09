package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// 语句 Stmt → LVal '=' Exp ';' // i
//| [Exp] ';' // i
//| Block
//| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
//| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
//| 'break' ';' | 'continue' ';' // i
//| 'return' [Exp] ';' // i
//| LVal '=' 'getint''('')'';' // i j
//| LVal '=' 'getchar''('')'';' // i j
//| 'printf''('StringConst {','Exp}')'';' // i j
public class Stmt {

    private static final String name = "<Stmt>";

    private LVal lVal = null;

    private Token assign = null;

    private ArrayList<Exp> expList = null;

    private Token semicolon = null;

    private Block block = null;

    private Token ifToken = null;

    private Token forToken = null;

    private Token lparent = null;

    private Cond cond = null;

    private Token rparent = null;

    private Stmt stmt1 = null;

    private Token elseToken = null;

    private Stmt stmt2 = null;

    private ForStmt forStmt1 = null;

    private ForStmt forStmt2 = null;

    private Token semicn1 = null;

    private Token semicn2 = null;

    private Token bOrcToken = null;

    private Token returnToken = null;

    private Token getiOrcToken = null;

    private Token printfToken = null;

    private Token strcon = null;

    private Token lbrace = null;

    private ArrayList<Token> commaList = null;

    private Token rbrace = null;

    private Token stringConst = null;

    public Stmt(LVal lVal, Token assign, ArrayList<Exp> expList, Token semicolon) {
        this.lVal = lVal;
        this.assign = assign;
        this.expList = expList;
        this.semicolon = semicolon;
    }

    public Stmt(ArrayList<Exp> expList, Token semicolon) {
        this.expList = expList;
        this.semicolon = semicolon;
    }

    public Stmt(Block block) {
        this.block = block;
    }

    public Stmt(Token ifToken, Token lparent, Cond cond, Token rparent, Stmt stmt1, Token elseToken, Stmt stmt2) {
        this.ifToken = ifToken;
        this.lparent = lparent;
        this.cond = cond;
        this.rparent = rparent;
        this.stmt1 = stmt1;
        this.elseToken = elseToken;
        this.stmt2 = stmt2;
    }

    public Stmt(Token forToken, Token lparent, ForStmt forStmt1, Token semicn1, Cond cond, Token semicn2, ForStmt forStmt2, Token rparent, Stmt stmt1) {
        this.forToken = forToken;
        this.lparent = lparent;
        this.forStmt1 = forStmt1;
        this.semicn1 = semicn1;
        this.cond = cond;
        this.semicn2 = semicn2;
        this.forStmt2 = forStmt2;
        this.rparent = rparent;
        this.stmt1 = stmt1;
    }

    public Stmt(Token bOrcToken, Token semicolon) {
        this.bOrcToken = bOrcToken;
        this.semicolon = semicolon;
    }


    public Stmt(Token returnToken, ArrayList<Exp> expList, Token semicolon) {
        this.returnToken = returnToken;
        this.expList = expList;
        this.semicolon = semicolon;
    }

    public Stmt(LVal lVal, Token assign, Token getiOrcToken, Token lparent, Token rparent, Token semicolon) {
        this.lVal = lVal;
        this.assign = assign;
        this.getiOrcToken = getiOrcToken;
        this.lparent = lparent;
        this.rparent = rparent;
        this.semicolon = semicolon;
    }

    public Stmt(Token printfToken, Token lparent, Token strcon, ArrayList<Token> commaList, ArrayList<Exp> expList, Token rparent, Token semicolon) {
        this.printfToken = printfToken;
        this.lparent = lparent;
        this.strcon = strcon;
        this.commaList = commaList;
        this.expList = expList;
        this.rparent = rparent;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        if (lVal!= null) {
            out.append(lVal).append(assign);
            if (getiOrcToken != null)
                out.append(getiOrcToken).append(lparent).append(rparent);
            else out.append(expList.get(0));
            out.append(semicolon);
        } else if (block!= null) out.append(block);
        else if (ifToken != null) {
            out.append(ifToken).append(lparent).append(cond).append(rparent).append(stmt1);
            if (elseToken!= null) out.append(elseToken).append(stmt2);
        } else if (forToken != null) {
            out.append(forToken).append(lparent);
            if (forStmt1 != null) out.append(forStmt1);
            out.append(semicn1);
            if (cond != null) out.append(cond);
            out.append(semicn2);
            if (forStmt2 != null) out.append(forStmt2);
            out.append(rparent);
            out.append(stmt1);
        } else if (bOrcToken != null) {
            out.append(bOrcToken).append(semicolon);
        } else if (returnToken != null) {
            out.append(returnToken);
            if(!expList.isEmpty()) out.append(expList.get(0));
            out.append(semicolon);
        } else if (printfToken != null) {
            out.append(printfToken).append(lparent).append(strcon);
            for(int i = 0; i < commaList.size();i++){
                out.append(commaList.get(i));
                out.append(expList.get(i));
            }
            out.append(rparent).append(semicolon);
        } else {
            if(!expList.isEmpty()) out.append(expList.get(0));
            out.append(semicolon);
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getSemicolon() {
        return semicolon;
    }

    public Token getLbrace() {
        return lbrace;
    }

    public ArrayList<Token> getCommaList() {
        return commaList;
    }

    public Token getRbrace() {
        return rbrace;
    }

    public Token getStringConst() {
        return stringConst;
    }

    public Token getIfToken() {
        return ifToken;
    }

    public Token getForToken() {
        return forToken;
    }

    public Token getLparent() {
        return lparent;
    }

    public Cond getCond() {
        return cond;
    }

    public Token getRparent() {
        return rparent;
    }

    public Stmt getStmt1() {
        return stmt1;
    }

    public Token getElseToken() {
        return elseToken;
    }

    public Stmt getStmt2() {
        return stmt2;
    }

    public ForStmt getForStmt1() {
        return forStmt1;
    }

    public ForStmt getForStmt2() {
        return forStmt2;
    }

    public Token getBOrcToken() {
        return bOrcToken;
    }

    public Token getReturnToken() {
        return returnToken;
    }

    public Token getGetiOrcToken() {
        return getiOrcToken;
    }

    public Token getPrintfToken() {
        return printfToken;
    }

    public ArrayList<Exp> getExpList() {
        return expList;
    }

    public Token getAssign() {
        return assign;
    }

    public LVal getLVal() {
        return lVal;
    }

    public Token getStrcon() {
        return strcon;
    }

    public void setSemicolon(Token semicolon) {
        this.semicolon = semicolon;
    }

    public void setLbrace(Token lbrace) {
        this.lbrace = lbrace;
    }

    public void setCommaList(ArrayList<Token> commaList) {
        this.commaList = commaList;
    }

    public void setRbrace(Token rbrace) {
        this.rbrace = rbrace;
    }

    public void setStringConst(Token stringConst) {
        this.stringConst = stringConst;
    }

    public void setIfToken(Token ifToken) {
        this.ifToken = ifToken;
    }

    public void setForToken(Token forToken) {
        this.forToken = forToken;
    }

    public void setLparent(Token lparent) {
        this.lparent = lparent;
    }

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public void setRparent(Token rparent) {
        this.rparent = rparent;
    }

    public void setStmt1(Stmt stmt1) {
        this.stmt1 = stmt1;
    }

    public void setElseToken(Token elseToken) {
        this.elseToken = elseToken;
    }

    public void setStmt2(Stmt stmt2) {
        this.stmt2 = stmt2;
    }

    public void setForStmt1(ForStmt forStmt1) {
        this.forStmt1 = forStmt1;
    }

    public void setForStmt2(ForStmt forStmt2) {
        this.forStmt2 = forStmt2;
    }

    public void setBOrcToken(Token bOrcToken) {
        this.bOrcToken = bOrcToken;
    }

    public void setReturnToken(Token returnToken) {
        this.returnToken = returnToken;
    }

    public void setGetiOrcToken(Token getiOrcToken) {
        this.getiOrcToken = getiOrcToken;
    }

    public void setPrintfToken(Token printfToken) {
        this.printfToken = printfToken;
    }

    public void setExpList(ArrayList<Exp> expList) {
        this.expList = expList;
    }

    public void setAssign(Token assign) {
        this.assign = assign;
    }

    public void setLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setStrcon(Token strcon) {
        this.strcon = strcon;
    }
}
