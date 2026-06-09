package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class Stmt implements Node {
    private int type;
    private LVal lVal;
    private Exp exp;
    private Token assign;
    private Token semicn;
    private Block block;
    private Token token;
    private Token elseToken;
    private Token lParent;
    private Token rParent;
    private Cond cond;
    private Stmt stmt;
    private Stmt elseStmt;
    private ForStmt forStmt1;
    private ForStmt forStmt2;
    private Token forSemicn1;
    private Token forSemicn2;
    private Token stringConst;
    private List<Token> commaList;
    private List<Exp> expList;

    public Stmt() {
        this.commaList = new ArrayList<>();
        this.expList = new ArrayList<>();
        this.type = 0;
        this.lVal = null;
        this.exp = null;
        this.assign = null;
        this.semicn = null;
        this.block = null;
        this.token = null;
        this.elseToken = null;
        this.lParent = null;
        this.rParent = null;
        this.cond = null;
        this.stmt = null;
        this.elseStmt = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.forSemicn1 = null;
        this.forSemicn2 = null;
        this.stringConst = null;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void addCommaList(Token token) {
        this.commaList.add(token);
    }

    public void addExpList(Exp exp) {
        this.expList.add(exp);
    }

    public void addLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void addExp(Exp exp) {
        this.exp = exp;
    }

    public void addAssign(Token assign) {
        this.assign = assign;
    }

    public void addSemicn(Token semicn) {
        this.semicn = semicn;
    }

    public void addBlock(Block block) {
        this.block = block;
    }

    public void addToken(Token token) {
        this.token = token;
    }

    public void addElseToken(Token elseToken) {
        this.elseToken = elseToken;
    }

    public void addLParent(Token lParent) {
        this.lParent = lParent;
    }

    public void addRParent(Token rParent) {
        this.rParent = rParent;
    }

    public void addCond(Cond cond) {
        this.cond = cond;
    }

    public void addStmt(Stmt stmt) {
        this.stmt = stmt;
    }

    public void addElseStmt(Stmt elseStmt) {
        this.elseStmt = elseStmt;
    }

    public void addForStmt1(ForStmt forStmt1) {
        this.forStmt1 = forStmt1;
    }

    public void addForStmt2(ForStmt forStmt2) {
        this.forStmt2 = forStmt2;
    }

    public void addForSemicn1(Token forSemicn1) {
        this.forSemicn1 = forSemicn1;
    }

    public void addForSemicn2(Token forSemicn2) {
        this.forSemicn2 = forSemicn2;
    }

    public void addStringConst(Token stringConst) {
        this.stringConst = stringConst;
    }

    public int getType() {
        return type;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                if (lVal != null) {
                    sb.append(lVal.error());
                }
                if (assign != null) {
                    sb.append(assign.error());
                }
                if (exp != null) {
                    sb.append(exp.error());
                }
                if (semicn != null) {
                    sb.append(semicn.error());
                }
                break;
            case 2:
                if (exp != null) {
                    sb.append(exp.error());
                }
                if (semicn != null) {
                    sb.append(semicn.error());
                }
                break;
            case 3:
                if (block != null) {
                    sb.append(block.error());
                }
                break;
            case 4:
                if (token != null) {
                    sb.append(token.error());
                }
                if (lParent != null) {
                    sb.append(lParent.error());
                }
                if (cond != null) {
                    sb.append(cond.error());
                }
                if (rParent != null) {
                    sb.append(rParent.error());
                }
                if (stmt != null) {
                    sb.append(stmt.error());
                }
                if (elseToken != null) {
                    sb.append(elseToken.error());
                }
                if (elseStmt != null) {
                    sb.append(elseStmt.error());
                }
                break;
            case 5:
                if (token != null) {
                    sb.append(token.error());
                }
                if (lParent != null) {
                    sb.append(lParent.error());
                }
                if (forStmt1 != null) {
                    sb.append(forStmt1.error());
                }
                if (forSemicn1 != null) {
                    sb.append(forSemicn1.error());
                }
                if (cond != null) {
                    sb.append(cond.error());
                }
                if (forSemicn2 != null) {
                    sb.append(forSemicn2.error());
                }
                if (forStmt2 != null) {
                    sb.append(forStmt2.error());
                }
                if (rParent != null) {
                    sb.append(rParent.error());
                }
                if (stmt != null) {
                    sb.append(stmt.error());
                }
                break;
            case 6:
            case 7:
                if (token != null) {
                    sb.append(token.error());
                }
                if (semicn != null) {
                    sb.append(semicn.error());
                }
                break;
            case 8:
                if (token != null) {
                    sb.append(token.error());
                }
                if (exp != null) {
                    sb.append(exp.error());
                }
                if (semicn != null) {
                    sb.append(semicn.error());
                }
                break;
            case 9:
            case 10:
                if (lVal != null) {
                    sb.append(lVal.error());
                }
                if (assign != null) {
                    sb.append(assign.error());
                }
                if (token != null) {
                    sb.append(token.error());
                }
                if (lParent != null) {
                    sb.append(lParent.error());
                }
                if (rParent != null) {
                    sb.append(rParent.error());
                }
                if (semicn != null) {
                    sb.append(semicn.error());
                }
                break;
            case 11:
                if (token != null) {
                    sb.append(token.error());
                }
                if (lParent != null) {
                    sb.append(lParent.error());
                }
                if (stringConst != null) {
                    sb.append(stringConst.error());
                }
                for (int i = 0; i < commaList.size(); i++) {
                    sb.append(commaList.get(i).error());
                    sb.append(expList.get(i).error());
                }
                if (rParent != null) {
                    sb.append(rParent.error());
                }
                if (semicn != null) {
                    sb.append(semicn.error());
                }
                break;
            default:
                break;
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                if (lVal != null) {
                    sb.append(lVal.toString());
                }
                if (assign != null) {
                    sb.append(assign.toString());
                }
                if (exp != null) {
                    sb.append(exp.toString());
                }
                if (semicn != null) {
                    sb.append(semicn.toString());
                }
                break;
            case 2:
                if (exp != null) {
                    sb.append(exp.toString());
                }
                if (semicn != null) {
                    sb.append(semicn.toString());
                }
                break;
            case 3:
                if (block != null) {
                    sb.append(block.toString());
                }
                break;
            case 4:
                if (token != null) {
                    sb.append(token.toString());
                }
                if (lParent != null) {
                    sb.append(lParent.toString());
                }
                if (cond != null) {
                    sb.append(cond.toString());
                }
                if (rParent != null) {
                    sb.append(rParent.toString());
                }
                if (stmt != null) {
                    sb.append(stmt.toString());
                }
                if (elseToken != null) {
                    sb.append(elseToken.toString());
                }
                if (elseStmt != null) {
                    sb.append(elseStmt.toString());
                }
                break;
            case 5:
                if (token != null) {
                    sb.append(token.toString());
                }
                if (lParent != null) {
                    sb.append(lParent.toString());
                }
                if (forStmt1 != null) {
                    sb.append(forStmt1.toString());
                }
                if (forSemicn1 != null) {
                    sb.append(forSemicn1.toString());
                }
                if (cond != null) {
                    sb.append(cond.toString());
                }
                if (forSemicn2 != null) {
                    sb.append(forSemicn2.toString());
                }
                if (forStmt2 != null) {
                    sb.append(forStmt2.toString());
                }
                if (rParent != null) {
                    sb.append(rParent.toString());
                }
                if (stmt != null) {
                    sb.append(stmt.toString());
                }
                break;
            case 6:
            case 7:
                if (token != null) {
                    sb.append(token.toString());
                }
                if (semicn != null) {
                    sb.append(semicn.toString());
                }
                break;
            case 8:
                if (token != null) {
                    sb.append(token.toString());
                }
                if (exp != null) {
                    sb.append(exp.toString());
                }
                if (semicn != null) {
                    sb.append(semicn.toString());
                }
                break;
            case 9:
            case 10:
                if (lVal != null) {
                    sb.append(lVal.toString());
                }
                if (assign != null) {
                    sb.append(assign.toString());
                }
                if (token != null) {
                    sb.append(token.toString());
                }
                if (lParent != null) {
                    sb.append(lParent.toString());
                }
                if (rParent != null) {
                    sb.append(rParent.toString());
                }
                if (semicn != null) {
                    sb.append(semicn.toString());
                }
                break;
            case 11:
                if (token != null) {
                    sb.append(token.toString());
                }
                if (lParent != null) {
                    sb.append(lParent.toString());
                }
                if (stringConst != null) {
                    sb.append(stringConst.toString());
                }
                for (int i = 0; i < commaList.size(); i++) {
                    sb.append(commaList.get(i).toString());
                    sb.append(expList.get(i).toString());
                }
                if (rParent != null) {
                    sb.append(rParent.toString());
                }
                if (semicn != null) {
                    sb.append(semicn.toString());
                }
                break;
            default:
                break;
        }
        sb.append("<Stmt>\n");
        return sb.toString();
    }
}
