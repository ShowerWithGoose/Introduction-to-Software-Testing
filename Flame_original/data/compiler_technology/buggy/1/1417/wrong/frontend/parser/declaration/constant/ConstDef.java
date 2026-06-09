package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.declaration.constant.constinitval.ConstInitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

public class ConstDef extends Node {
    public ConstDef(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
