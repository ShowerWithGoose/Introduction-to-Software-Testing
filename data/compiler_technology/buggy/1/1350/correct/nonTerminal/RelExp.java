package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class RelExp {
    private AddExp addExp;
    private RelExp relExp;
    private Token operator;
    private AddExp operatorExp;
    private int lineCnt;

    public RelExp() {
        addExp = null;
        relExp = null;
        operator = null;
        operatorExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        addExp = new AddExp();
        addExp.parser(lexer, errors);
        if (lexer.now().getType() == Token.Type.LSS ||
                lexer.now().getType() == Token.Type.GRE ||
                lexer.now().getType() == Token.Type.LEQ ||
                lexer.now().getType() == Token.Type.GEQ) {
            relExp = new RelExp();
            relExp.setAddExp(addExp);
            relExp.setLineCnt(addExp.getLineCnt());
            addExp = null;
            operator = lexer.now();
            lexer.move();
            operatorExp = new AddExp();
            operatorExp.parser(lexer, errors);
        }
        while (lexer.now().getType() == Token.Type.LSS ||
                lexer.now().getType() == Token.Type.GRE ||
                lexer.now().getType() == Token.Type.LEQ ||
                lexer.now().getType() == Token.Type.GEQ) {
            RelExp temptRelExp = relExp;
            relExp = new RelExp();
            relExp.setRelExp(temptRelExp);
            relExp.setOperator(operator);
            relExp.setOperatorExp(operatorExp);
            relExp.setLineCnt(temptRelExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorExp = new AddExp();
            operatorExp.parser(lexer, errors);
        }
        if (addExp != null) {
            lineCnt = addExp.getLineCnt();
        } else {
            lineCnt = relExp.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (addExp != null) {
            addExp.output(parserResult);
        }
        if (relExp != null) {
            relExp.output(parserResult);
        }
        if (operator != null) {
            parserResult.add(operator.getType().toString() + " " + operator.getContent());
        }
        if (operatorExp != null) {
            operatorExp.output(parserResult);
        }
        parserResult.add("<RelExp>");
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorExp(AddExp operatorExp) {
        this.operatorExp = operatorExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
