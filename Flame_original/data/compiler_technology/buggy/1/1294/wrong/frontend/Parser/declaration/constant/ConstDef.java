package frontend.Parser.declaration.constant;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.ConstExp;

import java.util.ArrayList;

public class ConstDef implements GrammarNode {
    private final String grammarName = "<ConstDef>";
    private Token ident;
    private Token lBrack;  //'['
    private ConstExp constExp;
    private Token rBrack;  //']'
    private Token equalAssign; //'='
    private ConstInitVal constInitVal;
    public ConstDef(Token ident, Token equalAssign, ConstInitVal constInitVal){
        this.ident = ident;
        this.equalAssign = equalAssign;
        this.constInitVal = constInitVal;
    }

    public ConstDef(Token ident, Token equalAssign,ConstInitVal constInitVal, ConstExp constExp, Token lBrack, Token rBrack){
        this(ident, equalAssign, constInitVal);
        this.lBrack = lBrack;
        this.rBrack = rBrack;
        this.constExp = constExp;
    }
    public String grammarOutput(){
        StringBuilder sb = new StringBuilder();
        sb.append(ident.grammarOutput());
        if(lBrack != null && rBrack != null && constExp != null){
            sb.append(lBrack.grammarOutput());
            sb.append(constExp.grammarOutput());
            sb.append(rBrack.grammarOutput());
        }
        sb.append(equalAssign.grammarOutput());
        sb.append(constInitVal.grammarOutput());
        sb.append(this.grammarName).append('\n');
        return sb.toString();
    }
}
