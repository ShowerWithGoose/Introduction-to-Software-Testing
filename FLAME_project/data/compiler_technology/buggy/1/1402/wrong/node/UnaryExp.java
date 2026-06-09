package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
public class UnaryExp {
    private String nodeName;
    private PrimaryExp primaryExp;
    private Token identToken;
    private Token lparentToken;
    private FuncRParams funcRParams;
    private Token rparentToken;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp(String nodeName, PrimaryExp primaryExp, Token identToken, Token lparentToken, FuncRParams funcRParams, Token rparentToken, UnaryOp unaryOp, UnaryExp unaryExp) {
        this.nodeName = nodeName;
        this.primaryExp = primaryExp;
        this.identToken = identToken;
        this.lparentToken = lparentToken;
        this.funcRParams = funcRParams;
        this.rparentToken = rparentToken;
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    // 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public void print() throws IOException {
        if (primaryExp != null) {
            primaryExp.print();
        } else if (identToken != null) {
            writeParser(identToken.toString());
            writeParser(lparentToken.toString());
            if (funcRParams != null)
                funcRParams.print();
            writeParser(rparentToken.toString());
        } else {
            unaryOp.print();
            unaryExp.print();
        }
        writeParser(nodeName);
    }
}
