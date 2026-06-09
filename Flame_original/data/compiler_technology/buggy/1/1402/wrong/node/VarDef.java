package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
public class VarDef {
    private String nodeName;
    private Token identToken;
    private Token lbrackToken;
    private ConstExp constExp;
    private Token rbrackToken;
    private Token assignToken;
    private InitVal initval;

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
            writeParser(identToken.toString());
            if (lbrackToken != null) { //中括号内不为空
                writeParser(lbrackToken.toString());
                constExp.print();
                writeParser(rbrackToken.toString());
            }
        } else { // 是 Ident [ '[' ConstExp ']' ] '=' InitVal
            writeParser(identToken.toString());
            if (lbrackToken != null) { //中括号内不为空
                writeParser(lbrackToken.toString());
                constExp.print();
                writeParser(rbrackToken.toString());
            }
            writeParser(assignToken.toString());
            initval.print();
        }
        writeParser(nodeName);
    }
}
