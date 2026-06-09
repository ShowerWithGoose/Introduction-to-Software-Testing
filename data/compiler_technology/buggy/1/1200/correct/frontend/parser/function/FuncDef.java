package frontend.parser.function;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.parser.block.Block;

public class FuncDef {
    private final String name;
    private FuncType funcType;
    private Token ident;
    private Token lParent;
    private FuncFParams funcFParams;
    private Token rParent;
    private Block block;
    private String errorLog;

    public FuncDef(FuncType funcType, Token ident, Token lParent,
                   FuncFParams funcFParams, Token rParent, Block block) {
        this.name = "<FuncDef>";
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = funcFParams;
        if (rParent != null) {
            this.rParent = rParent;
            this.errorLog = "";
        } else {
            this.rParent = null;
            this.errorLog = funcFParams.getLineno() + " j\n";
        }
        this.block = block;
    }

    public FuncDef(FuncType funcType, Token ident, Token lParent, Token rParent, Block block) {
        this.name = "<FuncDef>";
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = null;
        if (rParent != null) {
            this.rParent = rParent;
            this.errorLog = "";
        } else {
            this.rParent = null;
            this.errorLog = lParent.getLineno() + " j\n";
        }
        this.block = block;
    }

    public FuncDef(String name, FuncType funcType, Token ident,
                   Token lParent, Token rParent, Block block) {
        this.name = name;
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = null;
        if (rParent != null) {
            this.rParent = rParent;
            this.errorLog = "";
        } else {
            this.rParent = null;
            this.errorLog = lParent.getLineno() + " j\n";
        }
        this.block = block;
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        if (!ident.getType().equals(LexType.MAINTK)) {
            sb.append(funcType.getOutPut());
        } else {
            sb.append(funcType.getNoNameOutPut());
        }
        sb.append(ident.getOutPut());
        sb.append(lParent.getOutPut());
        if (funcFParams != null) {
            sb.append(funcFParams.getOutPut());
        }
        if (rParent != null) {
            sb.append(rParent.getOutPut());
        }
        sb.append(block.getOutPut());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        if (funcFParams != null) {
            sb.append(funcFParams.getError());
        }
        sb.append(errorLog);
        sb.append(block.getError());
        return sb.toString();
    }
}
