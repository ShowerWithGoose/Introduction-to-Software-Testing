package Paser;

import Reader.Token;
import Reader.TokenStream;

import java.util.ArrayList;

public class Paser {
    private TokenStream tokenStream;


    public Paser(TokenStream tokenStream) {
        this.tokenStream = tokenStream;
    }

    // public Node parseUnitNode() {
    //     ArrayList<Node> children = new ArrayList<>();
    //     Node node = null;
    //     while (true)
    //     {
    //         if (tokenStream.peek() == null )
    //         {
    //             break;
    //         }
    //
    //         else if (tokenStream.look(1).getType() == Token.TokenType.MAINTK) {
    //             node = parseMainFuncDef();
    //         }
    //         // parse FuncDef
    //         else if (tokenStream.look(2).getType() == Token.TokenType.LPARENT) {
    //             node = parseFuncDef();
    //         }
    //         // parse ConstDecl
    //         else if (tokenStream.peek().getType() == Token.TokenType.CONSTTK) {
    //             node = parseConstDecl();
    //         }
    //         // parse VarDecl
    //         else if (tokenStream.peek().getType() == Token.TokenType.INTTK) {
    //             node = parseVarDecl();
    //         }
    //         else break;
    //         children.add(node);
    //
    //     }
    //     int endLine = tokenStream.look(-1).getLineNumber();
    //     return NodeFactory.createNode(startLine, endLine, SyntaxVarType.COMP_UNIT, children);
    // }
    //
    // private Node parseVarDecl() {
    // }
    //
    // private Node parseConstDecl() {
    // }
    //
    // private Node parseFuncDef() {
    // }
    //
    // private Node parseMainFuncDef(){
    //     ArrayList<Node> children = new ArrayList<>();
    //     int startLine = tokenStream.peek().getLineNumber();
    //     Node node = null;
    //
    //
    // }
}
