package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class Character {
    private Token chrcon;
    private int lineCnt;

    public Character() {
        this.chrcon = null;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        chrcon = lexer.now();
        lexer.move();
        lineCnt = chrcon.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(ArrayList<String> symbolTable, ArrayList<String> errors,
                        ArrayList<Integer> domainNums, int domainCnt) {

    }
}
