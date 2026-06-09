package frontend.Parser.declaration.variable;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.ConstExp;
import frontend.Parser.terminal.Ident;

public class VarDef implements GrammarNode {
    private final String grammarName = "<VarDef>";
    private Token ident;
    private Token lBrack;
    private ConstExp constExp;
    private Token rBrack;
    private Token equalAssign; //'='
    private InitVal initVal;

    public VarDef(Token ident){
        this.ident = ident;
    }
    public VarDef(Token ident,Token lBrack, ConstExp constExp,
                  Token rBrack, Token equalAssign, InitVal initVal){
        this(ident);
        this.lBrack = lBrack;
        this.constExp = constExp;
        this.rBrack = rBrack;
        this.equalAssign = equalAssign;
        this.initVal = initVal;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.grammarOutput());
        if(lBrack != null && rBrack != null && constExp!= null){
            sb.append(lBrack.grammarOutput());
            sb.append(constExp.grammarOutput());
            sb.append(rBrack.grammarOutput());
        }
        if(equalAssign != null && initVal != null){
            sb.append(equalAssign.grammarOutput());
            sb.append(initVal.grammarOutput());
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
