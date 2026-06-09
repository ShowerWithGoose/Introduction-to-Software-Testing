package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static frontend.executor.Parser.writeParser;

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
    public String nodeName;
    public LVal lVal;
    public Token assignToken, lparentToken, rparentToken;
    public Token semiToken1, semiToken2;
    public Block block;
    public Token ifToken, elseToken, forToken;
    public Cond cond;
    public Stmt stmt1, stmt2;
    public ForStmt forStmt1, forStmt2;
    public Token breakToken, continueToken, returnToken, printfToken;
    public Token getIntToken, getCharToken, stringToken;
    public List<Token> commaTokenList = new ArrayList<>();
    public List<Exp> expList = new ArrayList<>();

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
                writeParser(assignToken.getTypeAndContent());
                writeParser(getIntToken.getTypeAndContent());
                writeParser(lparentToken.getTypeAndContent());
                writeParser(rparentToken.getTypeAndContent());
                writeParser(semiToken1.getTypeAndContent());
            } else if (getCharToken != null) { // LVal '=' 'getchar''('')'';'
                lVal.print();
                writeParser(assignToken.getTypeAndContent());
                writeParser(getCharToken.getTypeAndContent());
                writeParser(lparentToken.getTypeAndContent());
                writeParser(rparentToken.getTypeAndContent());
                writeParser(semiToken1.getTypeAndContent());
            } else { // LVal '=' Exp ';'
                lVal.print();
                writeParser(assignToken.getTypeAndContent());
                expList.get(0).print();
                writeParser(semiToken1.getTypeAndContent());
            }
        } else if (block != null) { // Block
            block.print();
        } else if (breakToken != null) { // 'break' ';'
            writeParser(breakToken.getTypeAndContent());
            writeParser(semiToken1.getTypeAndContent());
        } else if (continueToken != null) { // 'continue' ';'
            writeParser(continueToken.getTypeAndContent());
            writeParser(semiToken1.getTypeAndContent());
        } else if (returnToken != null) { // 'return' [Exp] ';'
            writeParser(returnToken.getTypeAndContent());
            if (!expList.isEmpty())
                expList.get(0).print();
            writeParser(semiToken1.getTypeAndContent());
        } else if (printfToken != null) { // 'printf' '(' StringConst {','Exp} ')' ';'
            writeParser(printfToken.getTypeAndContent());
            writeParser(lparentToken.getTypeAndContent());
            writeParser(stringToken.getTypeAndContent());
            if (!commaTokenList.isEmpty()) {
                for (int i = 0; i < commaTokenList.size(); i++) {
                    writeParser(commaTokenList.get(i).getTypeAndContent());
                    expList.get(i).print();
                }
            }
            writeParser(rparentToken.getTypeAndContent());
            writeParser(semiToken1.getTypeAndContent());
        } else if (ifToken != null) { // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            writeParser(ifToken.getTypeAndContent());
            writeParser(lparentToken.getTypeAndContent());
            cond.print();
            writeParser(rparentToken.getTypeAndContent());
            stmt1.print();
            if (elseToken != null) {
                writeParser(elseToken.getTypeAndContent());
                stmt2.print();
            }
        } else if (forToken != null) { // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            writeParser(forToken.getTypeAndContent());
            writeParser(lparentToken.getTypeAndContent());
            if (forStmt1 != null) {
                forStmt1.print();
            }
            writeParser(semiToken1.getTypeAndContent());
            if (cond != null) {
                cond.print();
            }
            writeParser(semiToken2.getTypeAndContent());
            if (forStmt2 != null) {
                forStmt2.print();
            }
            writeParser(rparentToken.getTypeAndContent());
            stmt1.print();
        } else { // [Exp] ';'
            if(!expList.isEmpty())
                expList.get(0).print();
            writeParser(semiToken1.getTypeAndContent());
        }
        writeParser(nodeName);
    }
}
