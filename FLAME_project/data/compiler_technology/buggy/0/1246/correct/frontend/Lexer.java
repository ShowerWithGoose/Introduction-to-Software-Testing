package frontend;

import error.Error;
import error.ErrorHandler;
import error.ErrorType;
import exception.LexerException;
import token.Token;
import token.TokenType;
import utils.Config;
import utils.Phases;

import java.util.ArrayList;
import java.util.Objects;

/**
 * @Description 词法分析
 * @Author
 * @Date 2024/9/19
 */
public class Lexer implements Phases {
    private final String inputText;
    private final int maxLength;
    private int pos;

    private int lineNum;
    private Token currentToken;

    private ArrayList<Token> tokenResult = new ArrayList<>();

    public ArrayList<Token> getTokenResult() {
        return tokenResult;
    }

    public Lexer(String inputText) {
        this.inputText = inputText;
        this.maxLength = inputText.length() - 1;
        this.pos = 0;
        this.lineNum = 1;
        this.currentToken = null;
    }

    @Override
    public void process() {
        Token token;
        try {
            do {
                token = next();
                if (token != null && Config.debuggingTokens) {
                    System.out.println(token);
                }
            } while (token != null);
        } catch (LexerException e) {
            System.out.println(e);
        }
    }

    @Override
    public void outputResult() {
        if (Config.outputLexer) {
            for (Token token : tokenResult) {
                token.print();
            }
        }
    }

    public void skipWhite() {
        while (pos <= maxLength && Character.isWhitespace(inputText.charAt(pos))) {
            if (inputText.charAt(pos) == '\n') {
                lineNum++;
            }
            pos++;
        }
    }

    public boolean skipComment() {
        if (pos >= maxLength) {
            return false;
        }
        if (inputText.charAt(pos) == '/' && inputText.charAt(pos + 1) == '*') {
            pos += 2;
            while (pos <= maxLength) {
                if (pos < maxLength && inputText.charAt(pos) == '*' && inputText.charAt(pos + 1) == '/') {
                    pos += 2;
                    return true;
                }
                if (inputText.charAt(pos) == '\n') {
                    lineNum++;
                }
                pos++;
            }
        } else if (inputText.charAt(pos) == '/' && inputText.charAt(pos + 1) == '/') {
            pos += 2;
            while (pos <= maxLength) {
                if (inputText.charAt(pos) == '\n') {
                    lineNum++;
                    pos++;
                    return true;
                }
                pos++;
            }
        }
        return pos >= maxLength;
    }

    public Token next() throws LexerException {
        currentToken = null;
        do {
            skipWhite();
        } while (skipComment());

        if (pos > maxLength) {
            return null;
        }

        char nowChar = inputText.charAt(pos);
        if (Character.isDigit(nowChar)) {
            int endPos = pos + 1;

            while (endPos <= maxLength && Character.isDigit(inputText.charAt(endPos))) {
                endPos++;
            }
            String str = inputText.substring(pos, endPos);

            // 更新pos
            pos = endPos;

            currentToken = new Token(str, lineNum, TokenType.INTCON);
        } else if (isIdentifierNondigit(nowChar)) {
            int endPos = pos + 1;
            while (endPos <= maxLength && isIdentifierDigit(inputText.charAt(endPos))) {
                endPos++;
            }
            String str = inputText.substring(pos, endPos);

            // 更新pos
            pos = endPos;

            // 判断是否为保留字
            TokenType type = TokenType.isReserved(str);

            currentToken = new Token(str, lineNum, Objects.requireNonNullElse(type, TokenType.IDENFR));
        } else if (nowChar == '\'') {
            int endPos = pos + 1;
            while (endPos <= maxLength && (inputText.charAt(endPos) != '\'' || (inputText.charAt(endPos) == '\'' && inputText.charAt(endPos - 1) == '\\'))) {
                endPos++;
            }

            //  检查'是否匹配
            if (endPos > maxLength) {
                throw new LexerException(lineNum);
            }

            endPos++;
            String str = inputText.substring(pos, endPos);

            pos = endPos;

            currentToken = new Token(str, lineNum, TokenType.CHRCON);
        } else if (nowChar == '\"') {
            int endPos = pos + 1;
            while (endPos <= maxLength && inputText.charAt(endPos) != '\"') {
                endPos++;
            }

            //  检查"是否匹配
            if (endPos > maxLength) {
                throw new LexerException(lineNum);
            }

            endPos++;
            String str = inputText.substring(pos, endPos);

            pos = endPos;

            currentToken = new Token(str, lineNum, TokenType.STRCON);
        } else {
            TokenType tokenType = null;
            int tokenLength = 0;
            String str = "";
            if (TokenType.singleCharList.contains(nowChar)) {
                tokenType = TokenType.getTokenType((str = inputText.substring(pos, pos + 1)));
                tokenLength = 1;
            }
            if (pos < maxLength && TokenType.doubleCharList.contains(nowChar)) {
                TokenType t = TokenType.getTokenType(inputText.substring(pos, pos + 2));
                if (t != null) {
                    tokenType = t;
                    tokenLength = 2;
                    str = inputText.substring(pos, pos + 2);
                } else if (isErrorA(inputText.charAt(pos))) {
                    System.out.println(inputText.charAt(pos) + " " + "我做了错饭");
                    ErrorHandler.addError(new Error(ErrorType.a, lineNum));
                    tokenType = TokenType.ERROR;
                    str = "errorA";
                    tokenLength = 1;
                }
            }
            if (tokenType != null) {
                currentToken = new Token(str, lineNum, tokenType);
                pos += tokenLength;
            }
        }

        if (currentToken != null) {
            tokenResult.add(currentToken);
        }

        return currentToken;
    }

    public boolean isIdentifierNondigit(char c) {
        return (Character.isLetter(c) || c == '_');
    }

    public boolean isIdentifierDigit(Character c) {
        return (Character.isDigit(c) || isIdentifierNondigit(c));
    }

    public boolean isErrorA(Character c) {
        return (c == '&' || c == '|');
    }
}
