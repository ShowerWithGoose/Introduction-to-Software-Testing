package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.expression.ConstExp;
import frontend.parser.init.InitVal;

public class VarDef implements SyntaxUnit {
    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    // 方括号表示可选项，0次或1次
    private final String name = "<VarDef>";
    private Boolean init = null;
    private Token ident = null;
    private Token leftBracket = null; //[
    private ConstExp constExp = null;
    private Token rightBracket = null; //]
    private Token assign = null; //=
    private InitVal initVal = null;

    public VarDef(Token ident, Token leftBracket, ConstExp constExp, Token rightBracket) {
        init = false;
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExp = constExp;
        this.rightBracket = rightBracket;
    }

    public VarDef(Token ident, Token leftBracket, ConstExp constExp, Token rightBracket,
                  Token assign, InitVal initVal) {
        init = true;
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExp = constExp;
        this.rightBracket = rightBracket;
        this.assign = assign;
        this.initVal = initVal;
    }

    public Boolean isInit() {
        return init;
    }

    @Override
    public String syntaxPrint() {
        //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxPrint());
        if (leftBracket != null && constExp != null && rightBracket != null) {
            sb.append(leftBracket.syntaxPrint());
            sb.append(constExp.syntaxPrint());
            sb.append(rightBracket.syntaxPrint());
        }
        if (init) {
            sb.append(assign.syntaxPrint());
            sb.append(initVal.syntaxPrint());
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}
