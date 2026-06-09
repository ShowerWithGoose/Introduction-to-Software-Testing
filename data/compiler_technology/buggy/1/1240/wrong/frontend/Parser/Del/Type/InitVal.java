package frontend.Parser.Del.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.Exp;
import frontend.Parser.Exp.Type.constExp;

import java.util.ArrayList;
import java.util.List;

public class InitVal {
    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private final List<Exp> exps;
    private final ArrayList<constExp> constExps;
    private final LexType left;
    private final LexType right;
    private final ArrayList<LexType> pauses;
    private final LexType str;
    private final boolean ifConst;

    public InitVal(LexType string,boolean ifConst) {
        this.str = string;
        this.ifConst = ifConst;
        exps = null;
        constExps = null;
        this.left = null;
        this.right = null;
        this.pauses = null;
    }

    public InitVal(List<Exp> exps) {
        this.exps = exps;
        this.constExps = null;
        this.str = null;
        this.left = null;
        this.right = null;
        this.pauses = null;
        this.ifConst = false;
    }

    public InitVal(ArrayList<constExp> constExps) {
        this.constExps = constExps;
        this.exps = null;
        this.str = null;
        this.left = null;
        this.right = null;
        this.ifConst = true;
        this.pauses = null;
    }

    public InitVal(LexType left, List<Exp> exps, ArrayList<LexType> pause,
                   LexType right) {
        this.exps = exps;
        this.left = left;
        this.right = right;
        this.pauses = pause;
        this.str = null;
        this.constExps = null;
        this.ifConst = false;
    }

    public InitVal(LexType left, ArrayList<constExp> constExps, ArrayList<LexType> pause,
                   LexType right) {
        this.constExps = constExps;
        this.left = left;
        this.right = right;
        this.pauses = pause;
        this.str = null;
        this.exps = null;
        this.ifConst = true;
    }

    @Override
    public String toString() {
        if (str != null) {
            return str + (ifConst ? "<ConstInitVal>\n" : "<InitVal>\n");
        }
        if (left != null) {
            StringBuilder sb = new StringBuilder();
            sb.append(left);
            if (ifConst) {
                if (constExps.isEmpty()) {
                    sb.append(right).append("<ConstInitVal>\n");
                } else {
                    sb.append(constExps.get(0));
                    int i = 1;
                    if (pauses != null) {
                        for (LexType pause : pauses) {
                            sb.append(pause).append(constExps.get(i++));
                        }
                    }
                    sb.append(right).append("<ConstInitVal>\n");
                }
            } else {
                if (exps.isEmpty()) {
                    sb.append(right).append("<InitVal>\n");
                } else {
                    sb.append(exps.get(0));
                    int i = 1;
                    if (pauses != null) {
                        for (LexType pause : pauses) {
                            sb.append(pause).append(exps.get(i++));
                        }
                    }
                    sb.append(right).append("<InitVal>\n");
                }
            }
            return sb.toString();
        } else {
            return (ifConst ? constExps : exps).get(0).toString() +
                    (ifConst ? "<ConstInitVal>\n" : "<InitVal>\n");
        }
    }
}
