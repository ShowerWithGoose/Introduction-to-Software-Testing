package parser.vardecl;

import parser.exp.Exp;

import java.util.ArrayList;

public class InitVal {
    private final int type;  // 1. Exp; 2. '{' [ Exp { ',' Exp } ] '}'; 3. StringConst
    private final String stringConst;
    private final ArrayList<Exp> exps;

    public InitVal(int type) {
        this.type = type;
        this.stringConst = null;
        this.exps = new ArrayList<>();
    }

    public InitVal(int type, String stringConst) {
        this.type = type;
        this.stringConst = stringConst;
        this.exps = null;
    }

    public void addExp(Exp exp) {
        if (this.exps != null) {
            this.exps.add(exp);
        }
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        if (this.exps != null) {
            if (this.type == 1) {
                str.append(this.exps.get(0).toString());
            } else if (this.type == 2) {
                str.append("LBRACE {\n");
                if (!this.exps.isEmpty()) {
                    str.append(this.exps.get(0).toString());
                    for (int i = 1; i < this.exps.size(); i++) {
                        str.append("COMMA ,\n");
                        str.append(this.exps.get(i).toString());
                    }
                }
                str.append("RBRACE }\n");
            }
        } else if (this.type == 3) {
            str.append("STRCON " + this.stringConst + "\n");
        }
        str.append("<InitVal>\n");
        return str.toString();
    }
}
