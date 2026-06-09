package frontend.GrammaticalElements.declaration;

import frontend.GrammaticalElements.expression.Exp;
import frontend.Token;

import java.util.ArrayList;

public class InitVal {
    /*const string name = "<InitVal>";
    Exp* exp{};
    Token leftBrace; // {
    Exp* firstExp{};
    vector<Token> commas;
    vector<Exp> exps;
    Token rightBrace; // }
    Token stringConst;*/
    private final String name = "<InitVal>";
    private Exp exp;
    private Token leftBrace;
    private Exp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightBrace;
    private Token stringConst;

    public InitVal(Exp exp) {
        this.exp = exp;
    }

    public InitVal(Token leftBrace, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }

    public InitVal(Token leftBrace, Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> exps, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = exps;
        this.rightBrace = rightBrace;
    }

    public InitVal(Token stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.toString());
        } else if (this.leftBrace != null) {
            sb.append(leftBrace.toString());
            if (firstExp != null){
                sb.append(firstExp.toString());
                int len = commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(commas.get(i).toString());
                    sb.append(exps.get(i).toString());
                }
            }
            sb.append(rightBrace.toString());
        } else {
            sb.append(stringConst.toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
