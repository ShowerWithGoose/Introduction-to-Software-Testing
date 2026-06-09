package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.block.Block;

public class MainFuncDef implements SyntaxUnit {
    //MainFuncDef → 'int' 'main' '(' ')' Block
    private final String name = "<MainFuncDef>";
    private Token intTk;
    private Token mainTk;
    private Token leftParent;
    private Token rightParent;
    private Block block;

    public MainFuncDef(Token intTk, Token mainTk, Token leftParent, Token rightParent,
                       Block block) {
        this.intTk = intTk;
        this.mainTk = mainTk;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String syntaxPrint() {
        // MainFuncDef → 'int' 'main' '(' ')' Block
        StringBuilder sb = new StringBuilder();
        sb.append(intTk.syntaxPrint());
        sb.append(mainTk.syntaxPrint());
        sb.append(leftParent.syntaxPrint());
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        sb.append(block.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
