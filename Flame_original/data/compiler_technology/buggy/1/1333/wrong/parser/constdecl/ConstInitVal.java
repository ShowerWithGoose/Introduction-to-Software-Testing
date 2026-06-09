package parser.constdecl;

import java.util.ArrayList;

public class ConstInitVal {
    private final int type;  // 1. ConstExp; 2. '{' [ ConstExp { ',' ConstExp } ] '}'; 3. StringConst
    private final String stringConst;
    private final ArrayList<ConstExp> constExps;

    public ConstInitVal(int type) {
        this.type = type;
        this.stringConst = null;
        this.constExps = new ArrayList<>();
    }

    public ConstInitVal(int type, String stringConst) {
        this.stringConst = stringConst;
        this.type = type;
        this.constExps = null;
    }

    public void addConstExp(ConstExp constExp) {
        if (this.constExps != null) {
            this.constExps.add(constExp);
        }
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        if (this.constExps != null) {
            if (this.type == 1) {
                str.append(this.constExps.get(0).toString());
            } else if (this.type == 2) {
                str.append("LBRACE {\n");
                if (!this.constExps.isEmpty()) {
                    str.append(this.constExps.get(0).toString());
                    for (int i = 1; i < this.constExps.size(); i++) {
                        str.append("COMMA ,\n");
                        str.append(this.constExps.get(i).toString());
                    }
                }
                str.append("RBRACE }\n");
            }
        } else if (this.type == 3) {
            str.append("STRCON " + this.stringConst + "\n");
        }
        str.append("<ConstInitVal>\n");
        return str.toString();
    }
}
