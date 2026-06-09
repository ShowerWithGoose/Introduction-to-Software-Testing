package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class EqExp {
    private RelExp relExp;
    private EqExp eqExp;
    private Token operator;
    private RelExp operatorRelExp;
    private int lineCnt;

    public EqExp() {
        relExp = null;
        eqExp = null;
        operator = null;
        operatorRelExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        relExp = new RelExp();
        relExp.parser(lexer, errors);
        if (lexer.now().getType() == Token.Type.EQL ||
                lexer.now().getType() == Token.Type.NEQ) {
            eqExp = new EqExp();
            eqExp.setRelExp(relExp);
            eqExp.setLineCnt(relExp.getLineCnt());
            relExp = null;
            operator = lexer.now();
            lexer.move();
            operatorRelExp = new RelExp();
            operatorRelExp.parser(lexer, errors);
        }
        while (lexer.now().getType() == Token.Type.EQL ||
                lexer.now().getType() == Token.Type.NEQ) {
            EqExp temptEqExp = eqExp;
            eqExp = new EqExp();
            eqExp.setEqExp(temptEqExp);
            eqExp.setOperator(operator);
            eqExp.setOperatorRelExp(operatorRelExp);
            eqExp.setLineCnt(temptEqExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorRelExp = new RelExp();
            operatorRelExp.parser(lexer, errors);
        }
        if (relExp != null) {
            lineCnt = relExp.getLineCnt();
        } else {
            lineCnt = eqExp.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (relExp != null) {
            relExp.output(parserResult);
        }
        if (eqExp != null) {
            eqExp.output(parserResult);
        }
        if (operator != null) {
            parserResult.add(operator.getType().toString() + " " + operator.getContent());
        }
        if (operatorRelExp != null) {
            operatorRelExp.output(parserResult);
        }
        parserResult.add("<EqExp>");
    }

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public void setEqExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorRelExp(RelExp operatorRelExp) {
        this.operatorRelExp = operatorRelExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }
}