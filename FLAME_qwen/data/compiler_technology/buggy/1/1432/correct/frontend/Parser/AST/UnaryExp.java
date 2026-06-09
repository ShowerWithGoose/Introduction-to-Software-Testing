package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class UnaryExp extends AstNode{

    public void parse() {
        if (getNowTokenType() == TokenType.PLUS ||
        getNowTokenType() == TokenType.MINU ||
        getNowTokenType() == TokenType.NOT) {
            UnaryOp unaryOp = new UnaryOp();
            unaryOp.parse();
            UnaryExp unaryExp = new UnaryExp();
            unaryExp.parse();
        } else if (getNowTokenType() == TokenType.IDENFR &&
                getPreTokenType(1) == TokenType.LPARENT) {
            append(2);
            if (isExp()) {
                FuncRParams funcRParams = new FuncRParams();
                funcRParams.parse();
            }
            j_error();
        } else {
            PrimaryExp primaryExp = new PrimaryExp();
            primaryExp.parse();
        }
        if (print == 1) {
            stringBuilder.append("<UnaryExp>").append("\n");
        }
    }
}
