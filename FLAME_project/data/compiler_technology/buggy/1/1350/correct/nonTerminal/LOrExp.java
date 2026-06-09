package nonTerminal;

import frontend.Lexer;
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

    public void parser(Lexer lexer, ArrayList<String> errors) {
        lAndExp = new LAndExp();
        lAndExp.parser(lexer, errors);
        if (lexer.now().getType() == Token.Type.OR) {
            lOrExp = new LOrExp();
            lOrExp.setlAndExp(lAndExp);
            lOrExp.setLineCnt(lAndExp.getLineCnt());
            lAndExp = null;
            operator = lexer.now();
            if (!operator.getIsCorrect()) {
                errors.add(operator.getLineCnt() + " a");
            }
            lexer.move();
            operatorExp = new LAndExp();
            operatorExp.parser(lexer, errors);
        }
        while (lexer.now().getType() == Token.Type.OR) {
            LOrExp temptLOrExp = lOrExp;
            lOrExp = new LOrExp();
            lOrExp.setlOrExp(temptLOrExp);
            lOrExp.setOperator(operator);
            lOrExp.setOperatorExp(operatorExp);
            lOrExp.setLineCnt(temptLOrExp.getLineCnt());
            operator = lexer.now();
            if (!operator.getIsCorrect()) {
                errors.add(operator.getLineCnt() + " a");
            }
            lexer.move();
            operatorExp = new LAndExp();
            operatorExp.parser(lexer, errors);
        }
        if (lAndExp != null) {
            lineCnt = lAndExp.getLineCnt();
        } else {
            lineCnt = lOrExp.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (lAndExp != null) {
            lAndExp.output(parserResult);
        }
        if (lOrExp != null) {
            lOrExp.output(parserResult);
        }
        if (operator != null) {
            parserResult.add(operator.getType().toString() + " " + operator.getContent());
        }
        if (operatorExp != null) {
            operatorExp.output(parserResult);
        }
        parserResult.add("<LOrExp>");
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
}
