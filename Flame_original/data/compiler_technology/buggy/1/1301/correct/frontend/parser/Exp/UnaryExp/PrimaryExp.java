package frontend.parser.Exp.UnaryExp;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;

public class PrimaryExp {
    //case 1
    private Token lparent;
    private Exp exp;
    private Token rparent;
    //case 2
    private LVal lVal;
    //case 3
    private Number number;
    //case 4
    private Character character;
    //share by all cases
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "PrimaryExp";

    public PrimaryExp(TokenList tokens) {
        this.lparent = null;
        this.exp = null;
        this.rparent = null;
        this.lVal = null;
        this.number = null;
        this.character = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        Token first = tokens.nextToken();
        if (first.equals(LexType.LPARENT)) { //case 1
            lparent = first;
            exp = new Exp(tokens);
            errorNum += exp.parse();
            first = tokens.nextToken();
            if (first.equals(LexType.RPARENT)) {
                rparent = first;
            } else {
                ErrorHandling.printError(tokens.preNonTerminalLineNum(),'j');
                errorNum++;
                tokens.rollBack(1);
            }
        } else if (first.equals(LexType.IDENFR)) { //case 2
            tokens.rollBack(1);
            lVal = new LVal(tokens);
            errorNum += lVal.parse();
        } else if (first.equals(LexType.INTCON)) { //case 3
            tokens.rollBack(1);
            number = new Number(tokens);
            errorNum += number.parse();
        } else { //case 4
            tokens.rollBack(1);
            character = new Character(tokens);
            errorNum += character.parse();
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        if (lparent != null) { //case 1
            sb.append(lparent).append(exp.toSyntaxTree());
            if (rparent != null) {
                sb.append(rparent);
            }
        } else if (lVal != null) { //case 2
            sb.append(lVal.toSyntaxTree());
        } else if (number != null) { //case 3
            sb.append(number.toSyntaxTree());
        } else { //case 4
            sb.append(character.toSyntaxTree());
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
