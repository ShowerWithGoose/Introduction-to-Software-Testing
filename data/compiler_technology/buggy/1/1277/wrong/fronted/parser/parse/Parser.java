package fronted.parser.parse;

import fronted.lexer.Lexer;
import fronted.lexer.TokenType;
import fronted.parser.syntax.ErrorSyntax;
import fronted.parser.syntax.SynNode;

import java.util.ArrayList;

public abstract class Parser {
    private ArrayList<ErrorSyntax> errorList = new ArrayList<>();
    public abstract SynNode parse();
    public ArrayList<ErrorSyntax> getErrorList() {
        return errorList;
    }

    public void addError(ErrorSyntax error) {
        errorList.add(error);
    }
    public void updateError(ArrayList<ErrorSyntax> errorList) {
        for (ErrorSyntax error : errorList) {
            this.errorList.add(error);
        }
    }
    // Exp: (, Ident, IntConst, CharConst, Ident(, +, -, !
    public static boolean isExp(Lexer lexer) {
        TokenType t = lexer.getAndNext().getType();
        boolean is = false;
        if (t == TokenType.LPARENT || t == TokenType.IDENFR || t == TokenType.INTCON ||
                t == TokenType.CHRCON || t == TokenType.PLUS || t == TokenType.MINU || t == TokenType.NOT) {
            is = true;
        }
        lexer.move(-1);
        return is;
    }
}
