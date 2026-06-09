package frontend.Tree;

import frontend.Lexer.LexType;

public class FuncFParam {
    private BType bType;
    private Ident ident;
    private boolean isArray;

    public FuncFParam(BType bType, Ident ident, boolean isArray) {
        this.bType = bType;
        this.ident = ident;
        this.isArray = isArray;
    }

    public Integer getType() {
        if (bType.getbType() == LexType.CHARTK) {
            if (!isArray) {
                return 0;
            } else {
                return 1;
            }
        }else{
            if (!isArray) {
                return 2;
            } else {
                return 3;
            }
        }
    }
}
