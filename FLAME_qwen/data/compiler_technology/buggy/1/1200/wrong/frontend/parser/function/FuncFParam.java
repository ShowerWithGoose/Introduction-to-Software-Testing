package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.declaration.BType;

public class FuncFParam {
    private final String name = "<FuncFParam>";
    private BType bType;
    private Token ident;
    private Token lBracket;
    private Token rBracket;
    private String errorLog;

    public FuncFParam(BType bType, Token ident, Token lBracket, Token rBracket) {
        this.bType = bType;
        this.ident = ident;
        this.lBracket = lBracket;
        if (rBracket == null) {
            this.rBracket = null;
            this.errorLog = lBracket.getLineno() + " k\n";
        } else {
            this.rBracket = rBracket;
            this.errorLog = "";
        }
    }

    public FuncFParam(BType bType, Token ident) {
        this.bType = bType;
        this.ident = ident;
        this.lBracket = null;
        this.rBracket = null;
        this.errorLog = "";
    }

    public int getLineno() {
        if (lBracket == null) {
            return ident.getLineno();
        } else {
            return lBracket.getLineno();
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.getOutPut());
        sb.append(ident.getOutPut());
        if (lBracket != null) {
            sb.append(lBracket.getOutPut());
        }
        if (rBracket != null) {
            sb.append(rBracket.getOutPut());
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        return errorLog;
    }
}
