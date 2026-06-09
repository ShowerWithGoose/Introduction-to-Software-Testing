package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.ConstExp;

import java.util.ArrayList;

// ConstInitVal -> '{' [ConstExp { ',' ConstExp} ] '}'
public class ConstInitValMulti extends Node {
    public ConstInitValMulti(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
