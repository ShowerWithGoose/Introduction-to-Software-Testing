package util;

import common.Token;
import common.TokenType;

/**
 * The type Reserve.
 *
 * @author
 * @Description： 保留字
 * @date
 */
public class Reserve {
    /**
     * 是否为保留字
     *
     * @param tokenValue token值
     * @param lineNum    行号
     * @return  token
     */
    public static Token isReservedWord(String tokenValue, int lineNum) {
        switch (tokenValue) {
            case "main":
                return new Token(tokenValue, TokenType.MAINTK, lineNum);
            case "const":
                return new Token(tokenValue, TokenType.CONSTTK, lineNum);
            case "int":
                return new Token(tokenValue, TokenType.INTTK, lineNum);
            case "char":
                return new Token(tokenValue, TokenType.CHARTK, lineNum);
            case "break":
                return new Token(tokenValue, TokenType.BREAKTK, lineNum);
            case "continue":
                return new Token(tokenValue, TokenType.CONTINUETK, lineNum);
            case "if":
                return new Token(tokenValue, TokenType.IFTK, lineNum);
            case "else":
                return new Token(tokenValue, TokenType.ELSETK, lineNum);
            case "for":
                return new Token(tokenValue, TokenType.FORTK, lineNum);
            case "getint":
                return new Token(tokenValue, TokenType.GETINTTK, lineNum);
            case "getchar":
                return new Token(tokenValue, TokenType.GETCHARTK, lineNum);
            case "printf":
                return new Token(tokenValue, TokenType.PRINTFTK, lineNum);
            case "return":
                return new Token(tokenValue, TokenType.RETURNTK, lineNum);
            case "void":
                return new Token(tokenValue, TokenType.VOIDTK, lineNum);
            default:
                return new Token(tokenValue, TokenType.IDENFR, lineNum);
        }
    }
}
