package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class UnaryOp {
    private Token unaryOp;  //'+' | 'âˆ’' | '!'
    private int lineCnt;

    public UnaryOp() {
        this.unaryOp = null;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        unaryOp = lexer.now();
        lexer.move();
        lineCnt = unaryOp.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(unaryOp.getType().toString() + " " + unaryOp.getContent());
        parserResult.add("<UnaryOp>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
