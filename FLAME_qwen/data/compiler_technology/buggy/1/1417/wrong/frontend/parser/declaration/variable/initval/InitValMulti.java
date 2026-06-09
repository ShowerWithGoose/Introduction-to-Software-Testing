package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

// InitVal -> '{' [ Exp { ',' Exp } ] '}'
public class InitValMulti extends Node {
    public InitValMulti(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
