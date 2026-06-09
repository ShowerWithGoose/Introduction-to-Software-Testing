package struct;

import token.Token;

import java.util.List;

/* Stmt â†’ LVal '=' Exp ';'
* | LVal '=' 'getint' '(' ')' ';'
* | LVal '=' 'getchar' '(' ')' ';'
* | [ Exp ] ';'
* | Block
* | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
* | 'for' '(' [ ForStmt ] ';' [ Cond ] ';' [ ForStmt ] ')' Stmt
* | 'break' ';'
* | 'continue' ';'
* | 'return' [ Exp ] ';'
* | 'printf' '(' StringConst { ',' Exp } ')' ';'
*/
public class Stmt {
    private LVal lVal;
    private Token assignToken;
    private List<Exp> exp;
    private List<Token> semicnToken;
    private Token getintToken;
    private Token getcharToken;
    private Token lParentToken;
    private Token rParentToken;
    private Block block;
    private Token ifToken;
    private Cond cond;
    private Token elseToken;
    private List<Stmt> stmt;
    private Token forToken;
    private ForStmt forStmt_1;
    private ForStmt forStmt_2;
    private Token breakToken;
    private Token continueToken;
    private Token returnToken;
    private Token printfToken;
    private Token stringConst;
    private List<Token> commaToken;

    public Stmt(LVal lVal, Token assignToken, List<Exp> exp, List<Token> semicnToken) {
        // LVal '=' Exp ';'
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    public Stmt(LVal lVal, Token assignToken, Token getintToken, Token getcharToken, Token lParentToken, Token rParentToken, List<Token> semicnToken) {
        // LVal '=' 'getint' '(' ')' ';'
        // LVal '=' 'getchar' '(' ')' ';'
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.getintToken = getintToken;
        this.getcharToken = getcharToken;
        this.lParentToken = lParentToken;
        this.rParentToken = rParentToken;
        this.semicnToken = semicnToken;
    }

    public Stmt(List<Exp> exp, List<Token> semicnToken) {
        // [ Exp ] ';'
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    public Stmt(Block block) {
        // Block
        this.block = block;
    }

    public Stmt(Token ifToken, Token lParentToken, Cond cond, Token rParentToken, List<Stmt> Stmt, Token elseToken) {
        // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        this.ifToken = ifToken;
        this.lParentToken = lParentToken;
        this.cond = cond;
        this.rParentToken = rParentToken;
        this.stmt = Stmt;
        this.elseToken = elseToken;
    }

    public Stmt(Token forToken, Token lParentToken, ForStmt forStmt_1, List<Token> semicnToken, Cond cond, ForStmt forStmt_2, Token rParentToken, List<Stmt> Stmt) {
        // 'for' '(' [ ForStmt ] ';' [ Cond ] ';' [ ForStmt ] ')' Stmt
        this.forToken = forToken;
        this.lParentToken = lParentToken;
        this.forStmt_1 = forStmt_1;
        this.semicnToken = semicnToken;
        this.cond = cond;
        this.forStmt_2 = forStmt_2;
        this.rParentToken = rParentToken;
        this.stmt = Stmt;
    }

    public Stmt(Token breakToken, Token continueToken, List<Token> semicnToken) {
        // 'break' ';'
        // 'continue' ';'
        this.breakToken = breakToken;
        this.continueToken = continueToken;
        this.semicnToken = semicnToken;
    }

    public Stmt(Token returnToken, List<Exp> exp, List<Token> semicnToken) {
        // 'return' [ Exp ] ';'
        this.returnToken = returnToken;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    public Stmt(Token printfToken, Token lParentToken, Token stringConst, List<Token> commaToken, List<Exp> exp, Token rParentToken, List<Token> semicnToken) {
        // 'printf' '(' StringConst { ',' Exp } ')' ';'
        this.printfToken = printfToken;
        this.lParentToken = lParentToken;
        this.rParentToken = rParentToken;
        this.stringConst = stringConst;
        this.commaToken = commaToken;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    public LVal getLVal() {
        return lVal;
    }

    public Token getAssignToken() {
        return assignToken;
    }

    public List<Exp> getExp() {
        return exp;
    }

    public List<Token> getSemicnToken() {
        return semicnToken;
    }

    public Token getGetintToken() {
        return getintToken;
    }

    public Token getGetcharToken() {
        return getcharToken;
    }

    public Token getLParentToken() {
        return lParentToken;
    }

    public Token getRParentToken() {
        return rParentToken;
    }

    public Token getStringConst() {
        return stringConst;
    }

    public Token getIfToken() {
        return ifToken;
    }

    public Token getBreakToken() {
        return breakToken;
    }

    public Token getContinueToken() {
        return continueToken;
    }

    public Token getReturnToken() {
        return returnToken;
    }

    public Token getPrintfToken() {
        return printfToken;
    }

    public Block getBlock() {
        return block;
    }

    public Cond getCond() {
        return cond;
    }

    public List<Stmt> getStmt() {
        return stmt;
    }

    public Token getForToken() {
        return forToken;
    }

    public ForStmt getForStmt_1() {
        return forStmt_1;
    }

    public ForStmt getForStmt_2() {
        return forStmt_2;
    }

    public Token getElseToken() {
        return elseToken;
    }

    public List<Token> getCommaToken() {
        return commaToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (ifToken != null) {
            sb.append(ifToken.toString());
            sb.append(lParentToken.toString());
            sb.append(cond.toString());
            sb.append(rParentToken.toString());
            sb.append(stmt.get(0).toString());
            if (elseToken != null) {
                sb.append(elseToken.toString());
                sb.append(stmt.get(1).toString());
            }
        } else if (forToken != null) {
            sb.append(forToken.toString());
            sb.append(lParentToken.toString());
            if (forStmt_1 != null) {
                sb.append(forStmt_1.toString());
            }
            sb.append(semicnToken.get(0).toString());
            if (cond != null) {
                sb.append(cond.toString());
            }
            sb.append(semicnToken.get(1).toString());
            if (forStmt_2 != null) {
                sb.append(forStmt_2.toString());
            }
            sb.append(rParentToken.toString());
            sb.append(stmt.get(0).toString());
        } else if (breakToken != null) {
            sb.append(breakToken.toString());
            sb.append(semicnToken.get(0).toString());
        } else if (continueToken != null) {
            sb.append(continueToken.toString());
            sb.append(semicnToken.get(0).toString());
        } else if (returnToken != null) {
            sb.append(returnToken.toString());
            if (!exp.isEmpty()) {
                sb.append(exp.get(0).toString());
            }
            sb.append(semicnToken.get(0).toString());
        } else if (printfToken != null) {
            sb.append(printfToken.toString());
            sb.append(lParentToken.toString());
            sb.append(stringConst.toString());
            for (int i = 0; i < exp.size(); i++) {
                sb.append(commaToken.get(i).toString());
                sb.append(exp.get(i).toString());
            }
            sb.append(rParentToken.toString());
            sb.append(semicnToken.get(0).toString());
        } else if (block != null) {
            sb.append(block.toString());
        } else if (assignToken != null) {
            sb.append(lVal.toString());
            sb.append(assignToken.toString());
            if (getintToken != null) {
                sb.append(getintToken.toString());
                sb.append(lParentToken.toString());
                sb.append(rParentToken.toString());
            } else if (getcharToken != null) {
                sb.append(getcharToken.toString());
                sb.append(lParentToken.toString());
                sb.append(rParentToken.toString());
            } else {
                sb.append(exp.get(0).toString());
            }
            sb.append(semicnToken.get(0).toString());
        } else {
            if (!exp.isEmpty()) {
                sb.append(exp.get(0).toString());
            }
            sb.append(semicnToken.get(0).toString());
        }
        sb.append("<Stmt>\n");
        return sb.toString();
    }
}
