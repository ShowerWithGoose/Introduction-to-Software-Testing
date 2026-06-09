package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class FuncRParams {
    private Exp exp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private int lineCnt;

    public FuncRParams() {
        this.exp = null;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        exp = new Exp();
        exp.parser(lexer, errors);
        while (lexer.now().getType() == Token.Type.COMMA) {
            Token comma = lexer.now();
            commas.add(comma);
            lexer.move();
            Exp temptExp = new Exp();
            temptExp.parser(lexer, errors);
            exps.add(temptExp);
        }
        lineCnt = exp.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        exp.output(parserResult);
        for (int i = 0; i < exps.size(); i++) {
            parserResult.add(commas.get(i).getType().toString() + " " + commas.get(i).getContent());
            exps.get(i).output(parserResult);
        }
        parserResult.add("<FuncRParams>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
