package frontend.Parser.AST;

import frontend.Error.Error;
import frontend.Error.ErrorLog;
import frontend.Lexer.Token;
import frontend.Lexer.TokenType;

import java.util.ArrayList;

public class AstNode {
    public static ArrayList<Token> tokens;
    public static StringBuilder stringBuilder = new StringBuilder();
    public static Integer pos = 0;
    public static Integer print;

    public TokenType getNowTokenType() {
        return tokens.get(pos).getType();
    }

    public Token getToken(Integer num) {
        return tokens.get(pos + num);
    }

    public Token getNowToken() {
        return tokens.get(pos);
    }

    public void next() {
        pos++;
    }

    public void append(int num) {
        for (int i = 1;i <= num;i++) {
            if (print == 1) {
                stringBuilder.append(getNowToken()).append("\n");
            }
            next();
        }
    }

    public TokenType getPreTokenType(int num) {
        return tokens.get(pos + num).getType();
    }

    public boolean isExp() {
        return getNowTokenType() == TokenType.LPARENT ||
                getNowTokenType() == TokenType.IDENFR ||
                getNowTokenType() == TokenType.INTCON ||
                getNowTokenType() == TokenType.CHRCON ||
                getNowTokenType() == TokenType.NOT ||
                getNowTokenType() == TokenType.PLUS ||
                getNowTokenType() == TokenType.MINU;
    }

    public void i_error() {
        if (getNowTokenType() != TokenType.SEMICN) {
            if (print == 1) {
                stringBuilder.append(new Token(TokenType.SEMICN, ";" , getToken(-1).getRow())).append("\n");
                ErrorLog.getInstance().addError(new Error(getToken(-1).getRow(), "i"));
            }
        } else {
            if (print == 1) {
                stringBuilder.append(getNowToken()).append("\n");
            }
            next();
        }
    }

    public void k_error() {
        if (getNowTokenType() != TokenType.RBRACK) {
            if (print == 1) {
                stringBuilder.append(new Token(TokenType.RBRACK, "]" , getToken(-1).getRow())).append("\n");
                ErrorLog.getInstance().addError(new Error(getToken(-1).getRow(), "k"));
            }
        } else {
            if (print == 1) {
                stringBuilder.append(getNowToken()).append("\n");
            }
            next();
        }
    }

    public void j_error() {
        if (getNowTokenType() != TokenType.RPARENT) {
            if (print == 1) {
                stringBuilder.append(new Token(TokenType.RPARENT, ")" , getToken(-1).getRow())).append("\n");
                ErrorLog.getInstance().addError(new Error(getToken(-1).getRow(), "j"));
            }
        } else {
            if (print == 1) {
                stringBuilder.append(getNowToken()).append("\n");
            }
            next();
        }
    }
}