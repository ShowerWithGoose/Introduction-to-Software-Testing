package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.function.functype.FuncType;
import frontend.parser.function.param.FuncFParams;
import frontend.parser.statement.Block;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

// FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
public class FuncDef extends Node {
    public FuncDef(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
