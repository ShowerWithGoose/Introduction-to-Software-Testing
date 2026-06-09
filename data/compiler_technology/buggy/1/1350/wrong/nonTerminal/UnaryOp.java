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

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(ArrayList<String> symbolTable, ArrayList<String> errors,
                        ArrayList<Integer> domainNums, int domainCnt) {

    }
}
