package frontend.tree.func;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.tree.Node;
import frontend.semantic.BType;

/**
 * 函数类型 FuncType → 'void' | 'int' | 'char'
 */
public class FuncType extends Node {
    public BType getBType() {
        Token token = (Token) children.get(0);
        if (token.getLexType() == LexType.VOIDTK) {
            return BType.VOID;
        } else if (token.getLexType() == LexType.INTTK) {
            return BType.INT;
        } else {
            return BType.CHAR;
        }
    }
}
