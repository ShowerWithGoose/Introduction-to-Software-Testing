package frontend.Lexer;

import frontend.Lexer.Token.Token;
import frontend.Lexer.Token.TokenType;
import frontend.Error;

import java.io.IOException;
import java.io.PushbackReader;
import java.util.ArrayList;

public class Lexer {
    private PushbackReader reader;
    private Character nextChar = null;
    private int lineNum = 1;
    private ArrayList<Token> tokens = new ArrayList<>();


    public Lexer(PushbackReader reader) {
        this.reader = reader;
        TokenType.initKeyWordMap();
    }

    private void getChar() throws IOException {
        int tmpChar = reader.read();
        if (tmpChar != -1) {
            if ((char) tmpChar == '\n') {
                lineNum++;
            }
            nextChar = (char) tmpChar;
        } else {
            nextChar = null;
        }
    }

    private void unGetChar() throws IOException {
        if (nextChar == '\n') {
            lineNum--;
        }
        reader.unread(nextChar);
    }

    private Token nextToken() throws IOException {
        skipWhitespace();
        if (nextChar == null) {
            return null;
        } else if (nextChar == '/') {
            return parseAnno();
        } else if (nextChar == '<' || nextChar == '>' || nextChar == '=' || nextChar == '!') {
            return parseRela();
        } else if (nextChar == '"') {
            return parseStrCon();
        } else if (nextChar == '\'') {
            return parseChrCon();
        } else if (nextChar == '&' || nextChar == '|') {
            return parseLogic();
        } else if (Character.isDigit(nextChar)) {
            return parseIntCon();
        } else if (Character.isLetter(nextChar) || nextChar == '_') {
            return parseIdent();
        } else {
            return new Token(nextChar.toString(), lineNum);
        }
    }

    private void skipWhitespace() throws IOException {
        do {
            getChar();
            if (nextChar == null) {
                return;
            }
        } while (nextChar == ' ' || nextChar == '\r' || nextChar == '\t' || nextChar == '\n');
    }

    private Token parseAnno() throws IOException {
        getChar();
        if (nextChar == '/') {
            while (true) {
                getChar();
                if (nextChar == null) {
                    return null;
                }
                if (nextChar == '\n') {
                    return nextToken();
                }
            }
        } else if (nextChar == '*') {
            while (true) {
                getChar();
                if (nextChar == null) {
                    return null;
                }
                if (nextChar == '*') {
                    getChar();
                    if (nextChar == '/') {
                        return nextToken();
                    }
                    unGetChar();
                }
            }
        } else {
            unGetChar();
            return new Token("/", lineNum);
        }
    }

    private Token parseRela() throws IOException {
        if (nextChar == '>') {
            getChar();
            if (nextChar == '=') {
                return new Token(">=", lineNum);
            } else {
                unGetChar();
                return new Token(">", lineNum);
            }
        } else if (nextChar == '<') {
            getChar();
            if (nextChar == '=') {
                return new Token("<=", lineNum);
            } else {
                unGetChar();
                return new Token("<", lineNum);
            }
        } else if (nextChar == '=') {
            getChar();
            if (nextChar == '=') {
                return new Token("==", lineNum);
            } else {
                unGetChar();
                return new Token("=", lineNum);
            }
        } else if (nextChar == '!') {
            getChar();
            if (nextChar == '=') {
                return new Token("!=", lineNum);
            } else {
                unGetChar();
                return new Token("!", lineNum);
            }
        }
        return null;
    }

    private Token parseStrCon() throws IOException {
        StringBuilder builder = new StringBuilder();
        while (nextChar != null) {
            getChar();
            if (nextChar == '"') {
                return new Token(TokenType.STRCON, "\"" + builder.toString() + "\"", lineNum);
            } else {
                builder.append(nextChar);
            }
        }
        return null;
    }

    private Token parseChrCon() throws IOException {
        getChar();
        String tmpChar = "";
        if (nextChar == '\\') {
            tmpChar += "\\";
            getChar();
        }
        tmpChar += nextChar;
        getChar();
        if (nextChar == '\'') {
            return new Token(TokenType.CHRCON, "'" + tmpChar + "'", lineNum);
        }
        return null;
    }

    private Token parseLogic() throws IOException {
        if (nextChar == '&') {
            getChar();
            if (nextChar != '&') {
                unGetChar();
                Error.addError(new Error(Error.ErrorType.a, lineNum));
            }
            return new Token("&&", lineNum);
        } else if (nextChar == '|') {
            getChar();
            if (nextChar != '|') {
                unGetChar();
                Error.addError(new Error(Error.ErrorType.a, lineNum));
            }
            return new Token("||", lineNum);
        }
        return null;
    }

    private Token parseIntCon() throws IOException {
        StringBuilder builder = new StringBuilder(nextChar.toString());
        while (nextChar != null) {
            getChar();
            if (Character.isDigit(nextChar)) {
                builder.append(nextChar);
            } else {
                unGetChar();
                return new Token(TokenType.INTCON, builder.toString(), lineNum);
            }
        }
        return null;
    }

    private Token parseIdent() throws IOException {
        StringBuilder builder = new StringBuilder(nextChar.toString());
        while (nextChar != null) {
            getChar();
            if (Character.isLetter(nextChar) || Character.isDigit(nextChar) || nextChar == '_') {
                builder.append(nextChar);
            } else {
                unGetChar();
                if (TokenType.keyWordMap.containsKey(builder.toString())) {
                    return new Token(builder.toString(), lineNum);
                } else {
                    return new Token(TokenType.IDENFR, builder.toString(), lineNum);
                }
            }
        }
        return null;
    }

    public ArrayList<Token> getTokens() throws IOException {
        Token tmpToken;
        while ((tmpToken = nextToken()) != null) {
            tokens.add(tmpToken);
        }
        return tokens;
    }
}
