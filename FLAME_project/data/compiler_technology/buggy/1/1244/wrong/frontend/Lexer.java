package frontend;

import error.CompileError;
import token.Token;
import token.TokenType;

import java.io.FileReader;
import java.io.IOException;
import java.io.PushbackReader;
import java.util.ArrayList;

import static error.CompileErrorType.a;
import static java.lang.Character.*;

public class Lexer {
    private final PushbackReader input;
    private char curCh;
    private final StringBuilder curStr;
    private int curLine;
    private final ArrayList<Token> tokens;

    private final ArrayList<CompileError> compileErrors;

    private static final Lexer lexerInstance = new Lexer();

    private Lexer() {
        try {
            this.input = new PushbackReader(new FileReader("testfile.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        curLine = 1;
        tokens = new ArrayList<>();
        compileErrors = CompileError.getCompileErrors();
        curStr = new StringBuilder();
    }

    public static Lexer getInstance() {
        return lexerInstance;
    }

    public static ArrayList<Token> getTokens() {
        return lexerInstance.tokens;
    }

    public void lexicalAnalysis() throws IOException {
        while (input.ready())
            next();
        input.close();
    }

    private void next() throws IOException {
        curCh = (char) input.read();
        curStr.setLength(0);
        if (isWhitespace(curCh)) {
            do {
                if (curCh == '\n')
                    curLine++;
                curCh = (char) input.read();
            } while (isWhitespace(curCh));
            input.unread(curCh);
        } else if (curCh == '!') {
            curCh = (char) input.read();
            if (curCh == '=')
                tokens.add(new Token(TokenType.NEQ, "!=", curLine));
            else {
                tokens.add(new Token(TokenType.NOT, "!", curLine));
                input.unread(curCh);
            }
        } else if (curCh == '&') {
            curCh = (char) input.read();
            if (curCh == '&')
                tokens.add(new Token(TokenType.AND, "&&", curLine));
            else {
                tokens.add(new Token(TokenType.AND, "&", curLine));
                addCompileError();
                input.unread(curCh);
            }
        } else if (curCh == '|') {
            curCh = (char) input.read();
            if (curCh == '|')
                tokens.add(new Token(TokenType.OR, "||", curLine));
            else {
                tokens.add(new Token(TokenType.OR, "|", curLine));
                addCompileError();
                input.unread(curCh);
            }
        } else if (curCh == '+') {
            tokens.add(new Token(TokenType.PLUS, "+", curLine));
        } else if (curCh == '-') {
            tokens.add(new Token(TokenType.MINU, "-", curLine));
        } else if (curCh == '*') {
            tokens.add(new Token(TokenType.MULT, "*", curLine));
        } else if (curCh == '/') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh == '/') {
                do {
                    curCh = (char) input.read();
                } while (curCh != '\n' && curCh != '\uFFFF');
            } else if (curCh == '*') {
                do {
                    curCh = (char) input.read();
                    if (curCh == '*') {
                        curCh = (char) input.read();
                        if (curCh == '/')
                            break;
                        else
                            input.unread(curCh);
                    }
                } while (true);
            } else {
                tokens.add(new Token(TokenType.DIV, "/", curLine));
                input.unread(curCh);
            }
        } else if (curCh == '%') {
            tokens.add(new Token(TokenType.MOD, "%", curLine));
        } else if (curCh == '<') {
            curCh = (char) input.read();
            if (curCh == '=')
                tokens.add(new Token(TokenType.LEQ, "<=", curLine));
            else {
                tokens.add(new Token(TokenType.LSS, "<", curLine));
                input.unread(curCh);
            }
        } else if (curCh == '>') {
            curCh = (char) input.read();
            if (curCh == '=')
                tokens.add(new Token(TokenType.GEQ, ">=", curLine));
            else {
                tokens.add(new Token(TokenType.GRE, ">", curLine));
                input.unread(curCh);
            }
        } else if (curCh == '=') {
            curCh = (char) input.read();
            if (curCh == '=')
                tokens.add(new Token(TokenType.EQL, "==", curLine));
            else {
                tokens.add(new Token(TokenType.ASSIGN, "=", curLine));
                input.unread(curCh);
            }
        } else if (curCh == ';') {
            tokens.add(new Token(TokenType.SEMICN, ";", curLine));
        } else if (curCh == ',') {
            tokens.add(new Token(TokenType.COMMA, ",", curLine));
        } else if (curCh == '(') {
            tokens.add(new Token(TokenType.LPARENT, "(", curLine));
        } else if (curCh == ')') {
            tokens.add(new Token(TokenType.RPARENT, ")", curLine));
        } else if (curCh == '[') {
            tokens.add(new Token(TokenType.LBRACK, "[", curLine));
        } else if (curCh == ']') {
            tokens.add(new Token(TokenType.RBRACK, "]", curLine));
        } else if (curCh == '{') {
            tokens.add(new Token(TokenType.LBRACE, "{", curLine));
        } else if (curCh == '}') {
            tokens.add(new Token(TokenType.RBRACE, "}", curLine));
        } else if (isDigit(curCh)) {
            if (curCh == '0') {
                tokens.add(new Token(TokenType.INTCON, "0", curLine));
            } else {
                do {
                    curStr.append(curCh);
                    curCh = (char) input.read();
                } while (isDigit(curCh));
                input.unread(curCh);
                tokens.add(new Token(TokenType.INTCON, curStr.toString(), curLine));
            }
        } else if (curCh == '\"') {
            do {
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh == '\\') {
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    curStr.append(curCh);
                    curCh = (char) input.read();
                }
            } while (curCh != '\"');
            curStr.append(curCh);
            tokens.add(new Token(TokenType.STRCON, curStr.toString(), curLine));
        } else if (curCh == '\'') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh == '\\') {
                curStr.append(curCh);
                curCh = (char) input.read();
                curStr.append(curCh);
                curCh = (char) input.read();
            } else if (curCh != '\'') {
                curStr.append(curCh);
                curCh = (char) input.read();
            }
            curStr.append(curCh);
            tokens.add(new Token(TokenType.CHRCON, curStr.toString(), curLine));
        } else if (curCh == 'm') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'a') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'i') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'n') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                parseIDENFR();
            else {
                input.unread(curCh);
                tokens.add(new Token(TokenType.MAINTK, curStr.toString(), curLine));
            }
        } else if (curCh == 'c') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh == 'o') {
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 'n') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh == 's') {
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    if (curCh != 't') {
                        parseIDENFR();
                        return;
                    }
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                        parseIDENFR();
                    else {
                        input.unread(curCh);
                        tokens.add(new Token(TokenType.CONSTTK, curStr.toString(), curLine));
                    }
                } else if (curCh == 't') {
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    if (curCh != 'i') {
                        parseIDENFR();
                        return;
                    }
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    if (curCh != 'n') {
                        parseIDENFR();
                        return;
                    }
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    if (curCh != 'u') {
                        parseIDENFR();
                        return;
                    }
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    if (curCh != 'e') {
                        parseIDENFR();
                        return;
                    }
                    curStr.append(curCh);
                    curCh = (char) input.read();
                    if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                        parseIDENFR();
                    else {
                        input.unread(curCh);
                        tokens.add(new Token(TokenType.CONTINUETK, curStr.toString(), curLine));
                    }
                } else {
                    parseIDENFR();
                }
            } else if (curCh == 'h') {
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 'a') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 'r') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                    parseIDENFR();
                else {
                    input.unread(curCh);
                    tokens.add(new Token(TokenType.CHARTK, curStr.toString(), curLine));
                }
            } else {
                parseIDENFR();
            }
        } else if (curCh == 'i') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh == 'n') {
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 't') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                    parseIDENFR();
                else {
                    input.unread(curCh);
                    tokens.add(new Token(TokenType.INTTK, curStr.toString(), curLine));
                }
            } else if (curCh == 'f') {
                curStr.append(curCh);
                curCh = (char) input.read();
                if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                    parseIDENFR();
                else {
                    input.unread(curCh);
                    tokens.add(new Token(TokenType.IFTK, curStr.toString(), curLine));
                }
            } else {
                parseIDENFR();
            }
        } else if (curCh == 'b') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'r') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'e') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'a') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'k') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                parseIDENFR();
            else {
                input.unread(curCh);
                tokens.add(new Token(TokenType.BREAKTK, curStr.toString(), curLine));
            }
        } else if (curCh == 'e') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'l') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 's') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'e') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                parseIDENFR();
            else {
                input.unread(curCh);
                tokens.add(new Token(TokenType.ELSETK, curStr.toString(), curLine));
            }
        } else if (curCh == 'f') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'o') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'r') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                parseIDENFR();
            else {
                input.unread(curCh);
                tokens.add(new Token(TokenType.FORTK, curStr.toString(), curLine));
            }
        } else if (curCh == 'g') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'e') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 't') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh == 'i') {
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 'n') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 't') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                    parseIDENFR();
                else {
                    input.unread(curCh);
                    tokens.add(new Token(TokenType.GETINTTK, curStr.toString(), curLine));
                }
            } else if (curCh == 'c') {
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 'h') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 'a') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (curCh != 'r') {
                    parseIDENFR();
                    return;
                }
                curStr.append(curCh);
                curCh = (char) input.read();
                if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                    parseIDENFR();
                else {
                    input.unread(curCh);
                    tokens.add(new Token(TokenType.GETCHARTK, curStr.toString(), curLine));
                }
            } else {
                parseIDENFR();
            }
        } else if (curCh == 'p') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'r') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'i') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'n') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 't') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'f') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                parseIDENFR();
            else {
                input.unread(curCh);
                tokens.add(new Token(TokenType.PRINTFTK, curStr.toString(), curLine));
            }
        } else if (curCh == 'r') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'e') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 't') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'u') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'r') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'n') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                parseIDENFR();
            else {
                input.unread(curCh);
                tokens.add(new Token(TokenType.RETURNTK, curStr.toString(), curLine));
            }
        } else if (curCh == 'v') {
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'o') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'i') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (curCh != 'd') {
                parseIDENFR();
                return;
            }
            curStr.append(curCh);
            curCh = (char) input.read();
            if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_')
                parseIDENFR();
            else {
                input.unread(curCh);
                tokens.add(new Token(TokenType.VOIDTK, curStr.toString(), curLine));
            }
        } else if (isAlphabetic(curCh) || curCh == '_') {
            parseIDENFR();
        }
    }

    private void parseIDENFR() throws IOException {
        if (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_') {
            do {
                curStr.append(curCh);
                curCh = (char) input.read();
            } while (isAlphabetic(curCh) || isDigit(curCh) || curCh == '_');
        }
        input.unread(curCh);
        tokens.add(new Token(TokenType.IDENFR, curStr.toString(), curLine));
    }

    private void addCompileError(){
        compileErrors.add(new CompileError(a, curLine));
    }
}
