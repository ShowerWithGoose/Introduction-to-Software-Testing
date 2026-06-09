package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

// MulExp -> UnaryExp { ('*'|'/'|'%') UnaryExp }
public class MulExp extends Node{
    public MulExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
