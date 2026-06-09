package frontend.parser.ast.decl;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.ast.block.Block;

public class FuncDef {
    private String type;
    private FuncType funcType;
    private Token ident;
    private Token lParent;
    private FuncFParams funcFParams;
    private Token rParent;
    private Block block;
    private String error;

    public FuncDef(FuncType funcType, Token ident, Token lParent, FuncFParams funcFParams, Token rParent, Block block) {
        this.type = "<FuncDef>";
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = funcFParams;
        this.rParent = rParent;
        this.block = block;
        this.error = "";

        if (rParent == null) {
            this.error = funcFParams.getLineno() + " j\n";
        }
    }

    public FuncDef(FuncType funcType, Token ident, Token lParent, Token rParent, Block block) {
        this.type = "<FuncDef>";
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = null;
        this.rParent = rParent;
        this.block = block;
        this.error = "";

        if (rParent == null) {
            this.error = lParent.getLineno() + " j\n";
        }
    }

    public FuncDef(String type, FuncType funcType, Token ident, Token lParent, Token rParent, Block block) {
        this.type = type;
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = null;
        this.rParent = rParent;
        this.block = block;
        this.error = "";

        if (rParent == null) {
            this.error = lParent.getLineno() + " j\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        if (ident.getType().equals(TokenType.MAINTK)) {
            out.append(funcType.getOutputMain());
        } else {
            out.append(funcType.getOutput());
        }
        out.append(ident.getOutput());
        out.append(lParent.getOutput());
        if (funcFParams != null) {
            out.append(funcFParams.getOutput());
        }
        if (rParent != null) {
            out.append(rParent.getOutput());
        }
        out.append(block.getOutput());
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (funcFParams != null) {
            out.append(funcFParams.getError());
        }
        out.append(error);
        out.append(block.getError());
        
        return out.toString();
    }

}
