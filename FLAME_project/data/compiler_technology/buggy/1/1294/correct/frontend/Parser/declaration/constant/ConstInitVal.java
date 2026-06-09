package frontend.Parser.declaration.constant;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.ConstExp;
import frontend.Parser.terminal.StringConst;

public class ConstInitVal implements GrammarNode {
    private final String grammarName = "<ConstInitVal>";
    private ConstExp constExp; //ConstInitVal -> ConstExp

    private ConstExpArray constExpArray; //ConstInitVal ->'{' [ ConstExp { ',' ConstExp } ] '}'

    private StringConst stringConst; //ConstInitVal -> StringConst

    public ConstInitVal(ConstExp constExp, ConstExpArray constExpArray,StringConst stringConst) {
        this.constExp = constExp;
        this.constExpArray = constExpArray;
        this.stringConst = stringConst;
    }
    public String grammarOutput(){
        StringBuilder sb = new StringBuilder();
        if(this.constExp!= null){
            sb.append(this.constExp.grammarOutput());
        } else if(this.constExpArray != null){
            sb.append(this.constExpArray.grammarOutput());
        } else if(this.stringConst != null){
            sb.append(this.stringConst.getToken().grammarOutput());
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
