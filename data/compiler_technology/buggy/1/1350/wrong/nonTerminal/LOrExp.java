package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.util.ArrayList;

public class LOrExp {
    private LAndExp lAndExp;
    private LOrExp lOrExp;
    private Token operator;
    private LAndExp operatorExp;
    private int lineCnt;

    public LOrExp() {
        lAndExp = null;
        lOrExp = null;
        operator = null;
        operatorExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        lAndExp = new LAndExp();
        lAndExp.parser(lexer);
        if (lexer.now().getType() == Token.Type.OR) {
            lOrExp = new LOrExp();
            lOrExp.setlAndExp(lAndExp);
            lOrExp.setLineCnt(lAndExp.getLineCnt());
            lAndExp = null;
            operator = lexer.now();
            lexer.move();
            operatorExp = new LAndExp();
            operatorExp.parser(lexer);
        }
        while (lexer.now().getType() == Token.Type.OR) {
            LOrExp temptLOrExp = lOrExp;
            lOrExp = new LOrExp();
            lOrExp.setlOrExp(temptLOrExp);
            lOrExp.setOperator(operator);
            lOrExp.setOperatorExp(operatorExp);
            lOrExp.setLineCnt(temptLOrExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorExp = new LAndExp();
            operatorExp.parser(lexer);
        }
        if (lAndExp != null) {
            lineCnt = lAndExp.getLineCnt();
        } else {
            lineCnt = lOrExp.getLineCnt();
        }
    }

    public void setlAndExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }

    public void setlOrExp(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorExp(LAndExp operatorExp) {
        this.operatorExp = operatorExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (lAndExp != null) {
            lAndExp.analyze(symbolTable);
        } else {
            lOrExp.analyze(symbolTable);
            if (!operator.getIsCorrect()) {
                symbolTable.addError(operator.getLineCnt() + " a");
            }
            operatorExp.analyze(symbolTable);
        }
    }
}
