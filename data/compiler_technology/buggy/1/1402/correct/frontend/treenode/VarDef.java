package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

// 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
public class VarDef {
    public String nodeName;
    public Token identToken, lbrackToken, rbrackToken, assignToken;
    public ConstExp constExp;
    public InitVal initval;

    public VarDef(String nodeName, Token identToken, Token lbrackToken, ConstExp constExp, Token rbrackToken, Token assignToken, InitVal initval) {
        this.nodeName = nodeName;
        this.identToken = identToken;
        this.lbrackToken = lbrackToken;
        this.constExp = constExp;
        this.rbrackToken = rbrackToken;
        this.assignToken = assignToken;
        this.initval = initval;
    }

    // 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public void print() throws IOException {
        if (assignToken == null) { //没等号，说明是 Ident [ '[' ConstExp ']' ]
            writeParser(identToken.getTypeAndContent());
            if (lbrackToken != null) { //中括号内不为空
                writeParser(lbrackToken.getTypeAndContent());
                constExp.print();
                writeParser(rbrackToken.getTypeAndContent());
            }
        } else { // 是 Ident [ '[' ConstExp ']' ] '=' InitVal
            writeParser(identToken.getTypeAndContent());
            if (lbrackToken != null) { //中括号内不为空
                writeParser(lbrackToken.getTypeAndContent());
                constExp.print();
                writeParser(rbrackToken.getTypeAndContent());
            }
            writeParser(assignToken.getTypeAndContent());
            initval.print();
        }
        writeParser(nodeName);
    }
}
