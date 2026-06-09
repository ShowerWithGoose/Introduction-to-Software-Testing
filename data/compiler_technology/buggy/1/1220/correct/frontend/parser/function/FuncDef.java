package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.block.Block;

public class FuncDef implements SyntaxUnit {
    //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    private final String name = "<FuncDef>";
    private FuncType funcType; //void,int,char
    private Token ident;
    private Token leftParent;
    private FuncFParams funcFParams;
    private Token rightParent;
    private Block block;

    public FuncDef(FuncType funcType, Token ident, Token leftParent,
                   FuncFParams funcFParams, Token rightParent,
                   Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParent = leftParent;
        this.funcFParams = funcFParams;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String syntaxPrint() {
        // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.syntaxPrint());
        sb.append(ident.syntaxPrint());
        sb.append(leftParent.syntaxPrint());
        if (funcFParams != null) {
            sb.append(funcFParams.syntaxPrint());
        }
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        sb.append(block.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
