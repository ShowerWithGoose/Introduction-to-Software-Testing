package node;

import token.Token;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class VarDefNode {
    // VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='InitVal
    private Token ident;
    private Token leftBracket;
    private ConstExpNode constExpNode;
    private Token rightBracket;
    private Token assign;
    private InitValNode initValNode;

    public VarDefNode(Token ident,Token leftBracket, ConstExpNode constExpNode, Token rightBracket, Token assign, InitValNode initValNode) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExpNode = constExpNode;
        this.rightBracket = rightBracket;
        this.assign = assign;
        this.initValNode = initValNode;
    }
    
    public void print() throws IOException {
        ident.print();
        if (leftBracket!=null) {
            leftBracket.print();
            constExpNode.print();
            rightBracket.print();
        }
        if (assign!=null) {
            assign.print();
            initValNode.print();
        }
        Io.Text.printWord("<VarDef>");
    }

}
