package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class FuncDefNode extends ASTNode {

    ASTNodes type = ASTNodes.FuncDef;
    FuncType returnType;
    Token functionName;
    public FuncFParamsNode fpParams;

    public BlockNode block;


    public FuncDefNode(FuncType returnType, Token functionName, FuncFParamsNode funcFParamsNodes, BlockNode block) {
        this.returnType = returnType;
        this.functionName = functionName;
        this.fpParams = funcFParamsNodes;
        this.block = block;
    }

    public FuncDefNode(FuncType returnType, Token functionName, BlockNode block) {
        this.returnType = returnType;
        this.functionName = functionName;
        this.fpParams = null;
        this.block = block;
    }

    public ASTNodes getType() {
        return type;
    }

    public FuncFParamsNode getFpParams() {
        return fpParams;
    }

    public BlockNode getBlock() {
        return block;
    }

    public Token getFunctionName() {
        return functionName;
    }

    public FuncType getReturnType() {
        return returnType;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        returnType.postOrderTraversal(io);
        io.getParserWriter().write(functionName.getType() + " " + functionName.getToken() + "\n");
        io.getParserWriter().write("LPARENT (\n");
        if (fpParams!= null) fpParams.postOrderTraversal(io);
        io.getParserWriter().write("RPARENT )\n");
        block.postOrderTraversal(io);
        io.getParserWriter().write("<FuncDef>\n");
    }

    
    public void postOrderNoPrint() {
        returnType.postOrderNoPrint();
        if (fpParams!= null) fpParams.postOrderNoPrint();
        block.postOrderNoPrint();
    }
}