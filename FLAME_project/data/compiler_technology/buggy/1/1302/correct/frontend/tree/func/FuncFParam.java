package frontend.tree.func;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.semantic.BType;
import frontend.semantic.Type;
import frontend.tree.Node;

/**
 * 函数形参 FuncFParam → BType Ident ['[' ']']
 * error: b k
 */
public class FuncFParam extends Node {
    private BType bType;
    private Type type;
    private String name;
    private int lineNum;

    @Override
    public void semanticAnalysis() {
        if (((Token)children.get(0)).getLexType() == LexType.INTTK) {
            bType = BType.INT;
        } else {
            bType = BType.CHAR;
        }

        Token identifier = (Token)children.get(1);
        name = identifier.getValue();
        if (children.size() > 2 && ((Token)children.get(2)).getLexType() == LexType.LBRACK) { // 如果是'['开头，则是数组
            type = Type.ARRAY;
        } else {
            type = Type.VAR;
        }
        lineNum = identifier.getLineNum();
        // 暂时不加入符号表，等进入函数的Block后再加入
        super.semanticAnalysis();
    }

    public BType getBType() {
        return bType;
    }

    public Type getType() {
        return type;
    }

    public String getName() {
        return name;
    }

    public int getLineNum() {
        return lineNum;
    }
}
