package frontend.parser.expression.primaryexp;

import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.unaryexp.UnaryExpIFace;
import frontend.parser.terminal.CharConst;

public class PrimaryExp implements UnaryExpIFace {
    private final String name = "<PrimaryExp>";
    private PrimaryExpIFace primaryExpIFace;

    private TokenList tokenList;

    public PrimaryExp(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parsePrimaryExp(){
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.LPARENT)){
            ParentExp parentExp = new ParentExp(tokenList);
            parentExp.parseParentExp();
            this.primaryExpIFace = parentExp;
        }else if (tokenList.seeAfterToken(0).getType().equals(TokenType.IDENFR)){
            LVal lVal = new LVal(tokenList);
            lVal.parseLVal();
            this.primaryExpIFace = lVal;
        } else if (tokenList.seeAfterToken(0).getType().equals(TokenType.INTCON)){
            Number number = new Number(tokenList);
            number.parseNumber();
            this.primaryExpIFace = number;
        } else if (tokenList.seeAfterToken(0).getType().equals(TokenType.CHRCON)){
            Character character = new Character(tokenList);
            character.parseCharacter();
            this.primaryExpIFace = character;
        } else {
            System.out.println("Exp error");
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.primaryExpIFace.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
