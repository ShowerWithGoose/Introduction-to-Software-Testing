package fronted.parser.statement;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Exp;
import fronted.parser.expression.LVal;
import fronted.parser.others.Block;

public class Stmt {

    /*
    Stmt → LVal '=' Exp ';' // i
| [Exp] ';' // i
| Block
| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
| 'break' ';' | 'continue' ';' // i
| 'return' [Exp] ';' // i
| LVal '=' 'getint''('')'';' // i j
| LVal '=' 'getchar''('')'';' // i j
| 'printf''('StringConst {','Exp}')'';' // i j
     */

    private AssignStmt assignStmt;
    // LVal '=' Exp ';' // i

    private ExpStmt expStmt;
    //[Exp] ';' // i

    private Block block;
    //Block

    private IfStmt ifStmt;
    //'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j

    private ForStatement forStatement;
    //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt

    private BreakStmt breakStmt;
    //'break' ';'//i

    private ContinueStmt continueStmt;
    //'continue' ';' // i

    private ReturnStmt returnStmt;
    //'return' [Exp] ';' // i

    private GetIntCharStmt getIntCharStmt;
    //LVal '=' 'getint''('')'';' // i j
    // LVal '=' 'getchar''('')'';' // i j

    private PrintfStmt printfStmt;
    //'printf''('StringConst {','Exp}')'';' // i j

    private int type;

    private static final String name = "<Stmt>\n";

    public Stmt(AssignStmt assignStmt,ExpStmt expStmt,Block block,
                IfStmt ifStmt,ForStatement forStatement,
                BreakStmt breakStmt,ContinueStmt continueStmt,ReturnStmt returnStmt,
                GetIntCharStmt getIntCharStmt,PrintfStmt printfStmt) {
        this.assignStmt = assignStmt;
        this.expStmt = expStmt;
        this.block = block;
        this.ifStmt = ifStmt;
        this.forStatement = forStatement;
        this.breakStmt = breakStmt;
        this.continueStmt = continueStmt;
        this.returnStmt = returnStmt;
        this.getIntCharStmt = getIntCharStmt;
        this.printfStmt = printfStmt;
        if (assignStmt != null) {
            type = 1;
        } else if (expStmt != null) {
            type = 2;
        } else if (block != null) {
            type = 3;
        } else if (ifStmt != null) {
            type = 4;
        } else if (forStatement != null) {
            type = 5;
        } else if (breakStmt != null) {
            type = 6;
        } else if (continueStmt != null) {
            type = 7;
        } else if (returnStmt != null) {
            type = 8;
        } else if (getIntCharStmt != null) {
            type = 9;
        } else {
            type = 10;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (type == 1) {
            sb.append(assignStmt.toString());
        } else if (type == 2) {
            sb.append(expStmt.toString());
        } else if (type == 3) {
            sb.append(block.toString());
        } else if (type == 4) {
            sb.append(ifStmt.toString());
        } else if (type == 5) {
            sb.append(forStatement.toString());
        } else if (type == 6) {
            sb.append(breakStmt.toString());
        } else if (type == 7) {
            sb.append(continueStmt.toString());
        } else if (type == 8) {
            sb.append(returnStmt.toString());
        } else if (type == 9) {
            sb.append(getIntCharStmt.toString());
        } else {
            sb.append(printfStmt.toString());
        }
        sb.append(name);
        return sb.toString();
    }

    public static Stmt parse(TokenList list) {
        Token first = list.now();
        AssignStmt assignStmt = null;
        ExpStmt expStmt = null;
        Block block = null;
        IfStmt ifStmt = null;
        ForStatement forStatement = null;
        BreakStmt breakStmt = null;
        ContinueStmt continueStmt = null;
        ReturnStmt returnStmt = null;
        GetIntCharStmt getIntCharStmt = null;
        PrintfStmt printfStmt = null;
        //System.out.println("Stmt parse first " + first.toString());
        if (first.getType().equals(TokenType.Type.LBRACE)) {
            block = Block.parse(list);
        } else if (first.getType().equals(TokenType.Type.IFTK)) {
            ifStmt = IfStmt.parse(list);
        } else if (first.getType().equals(TokenType.Type.FORTK)) {
            forStatement = ForStatement.parse(list);
        } else if (first.getType().equals(TokenType.Type.BREAKTK)) {
            breakStmt = BreakStmt.parse(list);
        } else if (first.getType().equals(TokenType.Type.CONTINUETK)) {
            continueStmt = ContinueStmt.parse(list);
        } else if (first.getType().equals(TokenType.Type.RETURNTK)) {
            returnStmt = ReturnStmt.parse(list);
        } else if (first.getType().equals(TokenType.Type.PRINTFTK)) {
            printfStmt = PrintfStmt.parse(list);
        } else {
            //assignStmt, expStmt, getIntCharStmt
            if (first.getType().equals(TokenType.Type.SEMICN) ||
                    first.getType().equals(TokenType.Type.LPARENT) ||
                    first.getType().equals(TokenType.Type.INTCON) ||
                    first.getType().equals(TokenType.Type.CHRCON) ||
                    (first.getType().equals(TokenType.Type.IDENFR) && list.hasAhead(1)
                            && list.getAheadOne(1).getType().equals(TokenType.Type.LPARENT)) ||
                    first.getType().equals(TokenType.Type.PLUS) ||
                    first.getType().equals(TokenType.Type.MINU) ||
                    first.getType().equals(TokenType.Type.NOT)) {
                expStmt = ExpStmt.parse(list);
                //除去LVal开头之外的一般情况
            } else {
                int pos = list.getPos();
                LVal lVal = LVal.parse(list);
                if (!list.now().getType().equals(TokenType.Type.ASSIGN)) {
                    //说明是exp里面的PrimaryExp
                    list.setPos(pos);
                    expStmt = ExpStmt.parse(list);
                } else {
                    //说明是assignStmt或者getIntCharStmt
                    list.next();
                    if (list.now().getType().equals(TokenType.Type.GETINTTK) ||
                            list.now().getType().equals(TokenType.Type.GETCHARTK)) {
                        //说明是getIntCharStmt
                        list.setPos(pos);
                        getIntCharStmt = GetIntCharStmt.parse(list);
                    } else {
                        //说明是assignStmt
                        list.setPos(pos);
                        assignStmt = AssignStmt.parse(list);
                    }
                }
            }
        }
        return new Stmt(assignStmt, expStmt, block, ifStmt, forStatement,
                 breakStmt, continueStmt, returnStmt, getIntCharStmt, printfStmt);
    }
}
