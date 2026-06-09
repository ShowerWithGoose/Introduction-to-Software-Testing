package frontend.parser.declaration.variable;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.declaration.constant.ConstDef;
import frontend.parser.declaration.variable.initval.InitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

public class VarDef extends Node {
    public VarDef(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }

}
