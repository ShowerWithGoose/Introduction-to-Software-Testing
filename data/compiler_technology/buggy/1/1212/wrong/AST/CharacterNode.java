package AST;

import Lexer.Token;

import IO.*;

import java.io.IOException;

public class CharacterNode extends ASTNode {

    ASTNodes type = ASTNodes.Character;
    private Token character;

    public CharacterNode(Token character) {
        this.character = character;
    }


    public ASTNodes getType() {
        return type;
    }

    public Token getCharacter() {
        return character;
    }


    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(character.getType() + " " + character.getToken() + "\n");
        io.getParserWriter().write("<Character>\n");
    }

    
    public void postOrderNoPrint() {

    }
}
