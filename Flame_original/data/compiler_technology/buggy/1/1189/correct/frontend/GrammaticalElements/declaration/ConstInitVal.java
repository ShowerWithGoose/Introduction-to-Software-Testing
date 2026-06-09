package frontend.GrammaticalElements.declaration;

import frontend.GrammaticalElements.expression.ConstExp;
import frontend.Token;

import java.util.ArrayList;

public class ConstInitVal {
    /*const string name = "<ConstInitVal>";
    ConstExp* constExp{};
    Token leftBrace; // {
    ConstExp* firstExp{};
    vector<Token> commas;
    vector<ConstExp> constExps;
    Token rightBrace; // }
    Token stringConst;*/
    private final String name = "<ConstInitVal>";
    private ConstExp constExp;
    private Token leftBrace;
    private ConstExp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExps;
    private Token rightBrace;
    private Token stringConst;

    public ConstInitVal(ConstExp constExp) {
        this.constExp = constExp;
    }

    public ConstInitVal(Token leftBrace, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }

    public ConstInitVal(Token leftBrace, ConstExp firstExp, ArrayList<Token> commas, ArrayList<ConstExp> constExps, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.firstExp = firstExp;
        this.commas = commas;
        this.constExps = constExps;
        this.rightBrace = rightBrace;
    }

    public ConstInitVal(Token stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (constExp != null) {
            sb.append(constExp.toString());
        } else if (this.leftBrace != null) {
            sb.append(leftBrace.toString());
            if (firstExp != null){
                sb.append(firstExp.toString());
                int len = commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(commas.get(i).toString());
                    sb.append(constExps.get(i).toString());
                }
            }
            sb.append(rightBrace.toString());
        } else if (stringConst != null) {
            sb.append(stringConst.toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
