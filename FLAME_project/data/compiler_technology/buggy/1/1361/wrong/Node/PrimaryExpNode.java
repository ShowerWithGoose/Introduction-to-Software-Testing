package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class PrimaryExpNode {
    //基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    private Token leftBracket;
    private ExpNode exp;
    private Token rightBracket;
    private LValNode lval;
    private NumberNode number;
    private CharacterNode character;

    public PrimaryExpNode(Token leftBracket, ExpNode exp, Token rightBracket,
                          LValNode lval, NumberNode number, CharacterNode character) {
        this.lval = lval;
        this.leftBracket = leftBracket;
        this.exp = exp;
        this.rightBracket = rightBracket;
        this.number = number;
        this.character = character;
    }

    public void print() {
        if (leftBracket != null) {
            IO.ParserOutput(leftBracket);
            exp.print();
            IO.ParserOutput(rightBracket);
        }
        else if (lval != null) {
            lval.print();
        }
        else if (number != null) {
            number.print();
        }
        else {
            character.print();
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.PrimaryExp));
    }

}
