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
        if (pos >= tokens.size()) {
            return tokens.get(tokens.size() - 1).getType();
        } else {
            return tokens.get(pos).getType();
        }
    }

    public Token getToken(Integer num) {
        if (pos + num >= tokens.size()) {
            return tokens.get(tokens.size() - 1);
        } else {
            return tokens.get(pos + num);
        }
    }

    public Token getNowToken() {
        if (pos >= tokens.size()) {
            return tokens.get(tokens.size() - 1);
        } else {
            return tokens.get(pos);
        }
    }

    public void next() {
        if (pos + 1 < tokens.size()) {
            pos++;
        }
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

    public void i_error() {
        if (getNowTokenType() != TokenType.SEMICN) {
            if (print == 1) {
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