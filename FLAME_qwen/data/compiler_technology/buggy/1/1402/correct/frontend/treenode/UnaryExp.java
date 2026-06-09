package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

// 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
public class UnaryExp {
    public String nodeName;
    public PrimaryExp primaryExp;
    public Token identToken, lparentToken, rparentToken;
    public FuncRParams funcRParams;
    public UnaryOp unaryOp;
    public UnaryExp unaryExp;

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
            writeParser(identToken.getTypeAndContent());
            writeParser(lparentToken.getTypeAndContent());
            if (funcRParams != null)
                funcRParams.print();
            writeParser(rparentToken.getTypeAndContent());
        } else {
            unaryOp.print();
            unaryExp.print();
        }
        writeParser(nodeName);
    }
}
