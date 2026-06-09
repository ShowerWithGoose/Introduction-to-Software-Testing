package Syntax;

import Datas.Token;

/**
 * @author
 * @Description:
 * @date 2024/9/29 14:37
 */
public class CheckTools {
    public static boolean isBType(Token token) {
        return token.tokenType == Token.TokenType.INTTK || token.tokenType == Token.TokenType.CHARTK;
    }

    public static boolean isIdent(Token token) {
        return token.tokenType == Token.TokenType.IDENFR;
    }

    public static boolean isCharCon(Token token) {
        return token.tokenType == Token.TokenType.CHRCON;
    }

    public static boolean isIntCon(Token token) {
        return token.tokenType == Token.TokenType.INTCON;
    }

    public static boolean isStringCon(Token token) {
        return token.tokenType == Token.TokenType.STRCON;
    }

    // FOLLOW(Exp) = {',', '}', ';', ']', ')'}
    public static boolean isFirstExp(Token token) {
        return token.tokenType == Token.TokenType.PLUS || token.tokenType == Token.TokenType.MINU || token.tokenType == Token.TokenType.NOT
                || token.tokenType == Token.TokenType.LPARENT || isIdent(token) || isCharCon(token) || isIntCon(token);
//        return token.tokenType != Token.TokenType.COMMA && token.tokenType != Token.TokenType.RBRACE && token.tokenType != Token.TokenType.RBRACK
//                && token.tokenType != Token.TokenType.SEMICN && token.tokenType != Token.TokenType.RPARENT;
    }

}
