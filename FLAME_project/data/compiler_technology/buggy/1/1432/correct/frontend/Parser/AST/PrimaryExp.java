package frontend.Parser.AST;
import frontend.Lexer.TokenType;

public class PrimaryExp extends AstNode{

    public void parse() {
        if (getNowTokenType() == TokenType.LPARENT) {
            append(1);
            Exp exp = new Exp();
            exp.parse();
            j_error();
        } else if (getNowTokenType() == TokenType.INTCON){
            Number number = new Number();
            number.parse();
        } else if (getNowTokenType() == TokenType.CHRCON) {
            Character character = new Character();
            character.parse();
        } else {
            LVal lval = new LVal();
            lval.parse();
        }
        if (print == 1) {
            stringBuilder.append("<PrimaryExp>").append("\n");
        }
    }
}
