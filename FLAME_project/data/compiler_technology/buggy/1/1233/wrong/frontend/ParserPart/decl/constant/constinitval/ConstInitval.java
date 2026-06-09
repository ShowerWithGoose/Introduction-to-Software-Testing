package frontend.ParserPart.decl.constant.constinitval;

import frontend.Factor;
import frontend.ParserPart.expr.ConstExp;
import frontend.ParserPart.term.StringConst;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class ConstInitval implements Factor {
    private String name = "<ConstInitVal>";
    private TokenList tokenList;
    private ConstInitValInterface constInitValInterface;
    public ConstInitval(TokenList tokenList){
        this.tokenList = tokenList;
        constInitValInterface = null;
    }
    public void parserConstInitval(){
        Token token = tokenList.peek();
        if (token.getType().equals(TokenType.LBRACE)){
            //{开头，对应Mul
            ConstInitValMul constInitValMul = new ConstInitValMul(tokenList);
            constInitValMul.parserConstExpMul();
            constInitValInterface = constInitValMul;
        } else if (token.getType().equals(TokenType.STRCON)) {
            //StringConst开头，对应该情况
            StringConst stringConst = new StringConst(tokenList);
            stringConst.parseStringConst();
            constInitValInterface = stringConst;
        }else {
            //对应ConstExp情况
            ConstExp constExp = new ConstExp(tokenList);
            constExp.parseConstExp();
            constInitValInterface = constExp;
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValInterface.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
