package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class MulExp {
    private UnaryExp unaryExp;
    private MulExp mulExp;
    private Token operator;
    private UnaryExp operatorExp;
    private int lineCnt;

    public MulExp() {
        unaryExp = null;
        mulExp = null;
        operator = null;
        operatorExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        unaryExp = new UnaryExp();
        unaryExp.parser(lexer, errors);
        if (lexer.now().getType() == Token.Type.MULT ||
                lexer.now().getType() == Token.Type.DIV ||
                lexer.now().getType() == Token.Type.MOD) {
            mulExp = new MulExp();
            mulExp.setUnaryExp(unaryExp);
            mulExp.setLineCnt(unaryExp.getLineCnt());
            unaryExp = null;
            operator = lexer.now();
            lexer.move();
            operatorExp = new UnaryExp();
            operatorExp.parser(lexer, errors);
        }
        while (lexer.now().getType() == Token.Type.MULT ||
                lexer.now().getType() == Token.Type.DIV ||
                lexer.now().getType() == Token.Type.MOD) {
            MulExp temptMulExp = mulExp;
            mulExp = new MulExp();
            mulExp.setMulExp(temptMulExp);
            mulExp.setOperator(operator);
            mulExp.setOperatorExp(operatorExp);
            mulExp.setLineCnt(temptMulExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorExp = new UnaryExp();
            operatorExp.parser(lexer, errors);
        }
        if (unaryExp != null) {
            lineCnt = unaryExp.getLineCnt();
        } else {
            lineCnt = mulExp.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (unaryExp != null) {
            unaryExp.output(parserResult);
        }
        if (mulExp != null) {
            mulExp.output(parserResult);
        }
        if (operator != null) {
            parserResult.add(operator.getType().toString() + " " + operator.getContent());
        }
        if (operatorExp != null) {
            operatorExp.output(parserResult);
        }
        parserResult.add("<MulExp>");
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorExp(UnaryExp operatorExp) {
        this.operatorExp = operatorExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }
}