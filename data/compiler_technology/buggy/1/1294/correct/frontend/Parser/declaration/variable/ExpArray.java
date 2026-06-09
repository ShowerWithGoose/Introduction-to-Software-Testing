package frontend.Parser.declaration.variable;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.ConstExp;
import frontend.Parser.expression.Exp;

import java.util.ArrayList;

public class ExpArray implements GrammarNode {
    private Token lBrace;
    private Exp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rBrace;

    public ExpArray(Token lBrace, Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> Exps, Token rBrace) {
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = Exps;
        this.rBrace = rBrace;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lBrace.grammarOutput());
        if (this.firstExp != null) {
            sb.append(this.firstExp.grammarOutput());
            if (this.commas != null && this.exps != null
                    && this.commas.size() == this.exps.size()) {
                for (int i = 0; i < this.exps.size(); i++) {
                    sb.append(this.commas.get(i).grammarOutput());
                    sb.append(this.exps.get(i).grammarOutput());
                }
            }
        }
        sb.append(this.rBrace.grammarOutput());
        return sb.toString();
    }
}
