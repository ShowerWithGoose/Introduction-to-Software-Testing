package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

/*  语句 Stmt → LVal '=' Exp ';'
    | [Exp] ';'
    | Block
    | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    | 'break' ';' | 'continue' ';'
    | 'return' [Exp] ';'
    | LVal '=' 'getint''('')'';'
    | LVal '=' 'getchar''('')'';'
    | 'printf''('StringConst {','Exp}')'';'  */
public class Stmt {
    private String nodeName;
    private LVal lVal;
    private Token assignToken, lparentToken, rparentToken;
    private Token semiToken1, semiToken2;
    private Block block;
    private Token ifToken, elseToken, forToken;
    private Cond cond;
    private Stmt stmt1, stmt2;
    private ForStmt forStmt1, forStmt2;
    private Token breakToken, continueToken, returnToken, printfToken;
    private Token getIntToken, getCharToken, stringToken;
    private List<Token> commaTokenList = new ArrayList<>();
    private List<Exp> expList = new ArrayList<>();

    public Stmt(String nodeName, LVal lVal, Token assignToken, Token lparentToken, Token rparentToken, Token semiToken1, Token semiToken2, Block block, Token ifToken, Token elseToken, Token forToken, Cond cond, Stmt stmt1, Stmt stmt2, ForStmt forStmt1, ForStmt forStmt2, Token breakToken, Token continueToken, Token returnToken, Token printfToken, Token getIntToken, Token getCharToken, Token stringToken, List<Token> commaTokenList, List<Exp> expList) {
        this.nodeName = nodeName;
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.lparentToken = lparentToken;
        this.rparentToken = rparentToken;
        this.semiToken1 = semiToken1;
        this.semiToken2 = semiToken2;
        this.block = block;
        this.ifToken = ifToken;
        this.elseToken = elseToken;
        this.forToken = forToken;
        this.cond = cond;
        this.stmt1 = stmt1;
        this.stmt2 = stmt2;
        this.forStmt1 = forStmt1;
        this.forStmt2 = forStmt2;
        this.breakToken = breakToken;
        this.continueToken = continueToken;
        this.returnToken = returnToken;
        this.printfToken = printfToken;
        this.getIntToken = getIntToken;
        this.getCharToken = getCharToken;
        this.stringToken = stringToken;
        this.commaTokenList = commaTokenList;
        this.expList = expList;
    }

    public void print() throws IOException {
        if (lVal != null) {
            if (getIntToken != null) { // LVal '=' 'getint''('')'';'
                lVal.print();
                writeParser(assignToken.toString());
                writeParser(getIntToken.toString());
                writeParser(lparentToken.toString());
                writeParser(rparentToken.toString());
                writeParser(semiToken1.toString());
            } else if (getCharToken != null) { // LVal '=' 'getchar''('')'';'
                lVal.print();
                writeParser(assignToken.toString());
                writeParser(getCharToken.toString());
                writeParser(lparentToken.toString());
                writeParser(rparentToken.toString());
                writeParser(semiToken1.toString());
            } else { // LVal '=' Exp ';'
                lVal.print();
                writeParser(assignToken.toString());
                expList.get(0).print();
                writeParser(semiToken1.toString());
            }
        } else if (block != null) { // Block
            block.print();
        } else if (breakToken != null) { // 'break' ';'
            writeParser(breakToken.toString());
            writeParser(semiToken1.toString());
        } else if (continueToken != null) { // 'continue' ';'
            writeParser(continueToken.toString());
            writeParser(semiToken1.toString());
        } else if (returnToken != null) { // 'return' [Exp] ';'
            writeParser(returnToken.toString());
            if (!expList.isEmpty())
                expList.get(0).print();
            writeParser(semiToken1.toString());
        } else if (printfToken != null) { // 'printf' '(' StringConst {','Exp} ')' ';'
            writeParser(printfToken.toString());
            writeParser(lparentToken.toString());
            writeParser(stringToken.toString());
            if (!commaTokenList.isEmpty()) {
                for (int i = 0; i < commaTokenList.size(); i++) {
                    writeParser(commaTokenList.get(i).toString());
                    expList.get(i).print();
                }
            }
            writeParser(rparentToken.toString());
            writeParser(semiToken1.toString());
        } else if (ifToken != null) { // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            writeParser(ifToken.toString());
            writeParser(lparentToken.toString());
            cond.print();
            writeParser(rparentToken.toString());
            stmt1.print();
            if (elseToken != null) {
                writeParser(elseToken.toString());
                stmt2.print();
            }
        } else if (forToken != null) { // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            writeParser(forToken.toString());
            writeParser(lparentToken.toString());
            if (forStmt1 != null) {
                forStmt1.print();
            }
            writeParser(semiToken1.toString());
            if (cond != null) {
                cond.print();
            }
            writeParser(semiToken2.toString());
            if (forStmt2 != null) {
                forStmt2.print();
            }
            writeParser(rparentToken.toString());
            stmt1.print();
        } else { // [Exp] ';'
            if(!expList.isEmpty())
                expList.get(0).print();
            writeParser(semiToken1.toString());
        }
        writeParser(nodeName);
    }
}
