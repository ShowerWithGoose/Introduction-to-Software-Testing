package frontend;

import frontend.Error.ErrorHandler;
import frontend.Token.Token;
import frontend.Token.TokenType;

import java.io.IOException;
import java.io.PushbackReader;
import java.util.ArrayList;
import java.io.BufferedWriter;

public class Lexer {

    private PushbackReader reader = Config.TESTFILE_READER;

    private BufferedWriter stdWriter = Config.LEXER_WRITER;

    private final ArrayList<Token> tokens = new ArrayList<>();

    private int line_index = 1;

    private ErrorHandler errors;

    public Lexer(ErrorHandler errors) {
        this.errors = errors;
        lex();
    }

    public void printTokens() {
        try {
            for (Token token : tokens) {
                stdWriter.write(token.getType() + " " + token.getValue() + "\n");
            }
        } catch (IOException e) {
            System.out.println("Error writing to file");
        }
    }

    private void lex() {
        char c;
        while (true) {
            skipWhitespace();
            if ((c = getsym()) == '\0') {
                break;
            }
            try {
                if (isDigit(c)) {
                    reader.unread(c);
                    addNumberToken();
                } else if (isAlpha(c)) {
                    reader.unread(c);
                    addWordToken();
                } else if (isComparator(c)) {
                    reader.unread(c);
                    addComparatorToken();
                } else if (c == '/') {
                    reader.unread(c);
                    addDivTokenOrSkipComment();
                } else if (isSeparator(c)) {
                    reader.unread(c);
                    addSeparatorToken();
                } else if (c == '"') {
                    reader.unread(c);
                    addStringToken();
                } else if (c == '\'') {
                    reader.unread(c);
                    addCharToken();
                }
            } catch (IOException e) {
                System.out.println("Error reading file");
            }
        }
    }

    private char getsym() {
        try {
            if (reader.ready()) {
                return (char) reader.read();
            } else {
                return '\0';
            }
        } catch (IOException e) {
            System.out.println("Error reading file");
        }
        return '\0';
    }

    private boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    private boolean isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }

    private boolean isComparator(char c) {
        return c == '<' || c == '>' || c == '=' || c == '!' || c == '&' || c == '|';
    }

    private boolean isSeparator(char c) {
        return c == ';' || c == ',' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' ||
                c == '+' || c == '-' || c == '*' || c == '%';
    }


    private void addNumberToken() {
        String number = "";
        char c;
        try {
            while ((c = getsym()) != '\0') {
                if (isDigit(c)) {
                    number += c;
                } else {
                    reader.unread(c);
                    break;
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file");
        }
        tokens.add(new Token(TokenType.INTCON, number, this.line_index));
    }

    private void addWordToken() {
        String word = "";
        char c;
        try {
            while ((c = getsym()) != '\0') {
                if (isAlpha(c) || isDigit(c)) {
                    word += c;
                } else {
                    reader.unread(c);
                    break;
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file");
        }
        switch (word) {
            case "main" -> tokens.add(new Token(TokenType.MAINTK, word, this.line_index));
            case "const" -> tokens.add(new Token(TokenType.CONSTTK, word, this.line_index));
            case "int" -> tokens.add(new Token(TokenType.INTTK, word, this.line_index));
            case "char" -> tokens.add(new Token(TokenType.CHARTK, word, this.line_index));
            case "break" -> tokens.add(new Token(TokenType.BREAKTK, word, this.line_index));
            case "continue" -> tokens.add(new Token(TokenType.CONTINUETK, word, this.line_index));
            case "if" -> tokens.add(new Token(TokenType.IFTK, word, this.line_index));
            case "else" -> tokens.add(new Token(TokenType.ELSETK, word, this.line_index));
            case "for" -> tokens.add(new Token(TokenType.FORTK, word, this.line_index));
            case "getint" -> tokens.add(new Token(TokenType.GETINTTK, word, this.line_index));
            case "getchar" -> tokens.add(new Token(TokenType.GETCHARTK, word, this.line_index));
            case "printf" -> tokens.add(new Token(TokenType.PRINTFTK, word, this.line_index));
            case "return" -> tokens.add(new Token(TokenType.RETURNTK, word, this.line_index));
            case "void" -> tokens.add(new Token(TokenType.VOIDTK, word, this.line_index));
            default -> tokens.add(new Token(TokenType.IDENFR, word, this.line_index));
        }
    }

    private void addDivTokenOrSkipComment() {
        char c;
        char ch;
        try {
            if ((c = getsym()) == '/') {
                ch = getsym();
                if (ch == '/') {
                    while ((c = getsym()) != '\0') {
                        if (c == '\n') {
                            this.line_index++;
                            break;
                        }
                    }
                } else if (ch == '*') {
                    while ((c = getsym()) != '\0') {
                        if (c == '\n') {
                            this.line_index++;
                        } else if (c == '*') {
                            if ((c = getsym()) == '/') {
                                break;
                            } else {
                                reader.unread(c);
                            }
                        }
                    }
                } else {
                    reader.unread(ch);
                    tokens.add(new Token(TokenType.DIV, "/", this.line_index));
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file");
        }
    }

    private void addComparatorToken() {
        char c;
        char ch;
        try {
            c = getsym();
            if (c == '!') {
                ch = getsym();
                if (ch == '=') {
                    tokens.add(new Token(TokenType.NEQ, "!=", this.line_index));
                } else {
                    reader.unread(ch);
                    tokens.add(new Token(TokenType.NOT, "!", this.line_index));
                }
            } else if (c == '&') {
                ch = getsym();
                if (ch != '&') {
                    tokens.add(new Token(TokenType.AND, "&", this.line_index));
                    reader.unread(ch);
                    errors.addError('a', this.line_index);
                } else {
                    tokens.add(new Token(TokenType.AND, "&&", this.line_index));
                }
            } else if (c == '|') {
                ch = getsym();
                if (ch != '|') {
                    tokens.add(new Token(TokenType.OR, "|", this.line_index));
                    reader.unread(ch);
                    errors.addError('a', this.line_index);
                } else {
                    tokens.add(new Token(TokenType.OR, "||", this.line_index));
                }
            } else if (c == '<') {
                ch = getsym();
                if (ch == '=') {
                    tokens.add(new Token(TokenType.LEQ, "<=", this.line_index));
                } else {
                    reader.unread(ch);
                    tokens.add(new Token(TokenType.LSS, "<", this.line_index));
                }
            } else if (c == '>') {
                ch = getsym();
                if (ch == '=') {
                    tokens.add(new Token(TokenType.GEQ, ">=", this.line_index));
                } else {
                    reader.unread(ch);
                    tokens.add(new Token(TokenType.GRE, ">", this.line_index));
                }
            } else if (c == '=') {
                ch = getsym();
                if (ch == '=') {
                    tokens.add(new Token(TokenType.EQL, "==", this.line_index));
                } else {
                    reader.unread(ch);
                    tokens.add(new Token(TokenType.ASSIGN, "=", this.line_index));
                }

            } else {
                reader.unread(c);
            }
        } catch (IOException e) {
            System.out.println("Error reading file");
        }
    }

    private void addSeparatorToken() {
        switch (getsym()) {
            case ';' -> tokens.add(new Token(TokenType.SEMICN, ";", this.line_index));
            case ',' -> tokens.add(new Token(TokenType.COMMA, ",", this.line_index));
            case '(' -> tokens.add(new Token(TokenType.LPARENT, "(", this.line_index));
            case ')' -> tokens.add(new Token(TokenType.RPARENT, ")", this.line_index));
            case '[' -> tokens.add(new Token(TokenType.LBRACK, "[", this.line_index));
            case ']' -> tokens.add(new Token(TokenType.RBRACK, "]", this.line_index));
            case '{' -> tokens.add(new Token(TokenType.LBRACE, "{", this.line_index));
            case '}' -> tokens.add(new Token(TokenType.RBRACE, "}", this.line_index));
            case '+' -> tokens.add(new Token(TokenType.PLUS, "+", this.line_index));
            case '-' -> tokens.add(new Token(TokenType.MINU, "-", this.line_index));
            case '*' -> tokens.add(new Token(TokenType.MULT, "*", this.line_index));
            case '%' -> tokens.add(new Token(TokenType.MOD, "%", this.line_index));
        }
    }

    private void addStringToken() {
        String str = "";
        char c = getsym();
        str += c;
        while ((c = getsym()) != '\0') {
            str += c;
            if (c == '"') {
                break;
            }
        }
        tokens.add(new Token(TokenType.STRCON, str, this.line_index));
    }

    private void addCharToken() {
        String chr = "";
        char c = getsym();
        chr += c;
        c = getsym();
        if (c == '\\') {
            chr += c;
            c = getsym();
        }
        chr += c;
        c = getsym();
        if (c == '\'') {
            chr += c;
        }      // 也许需要额外报错
        tokens.add(new Token(TokenType.CHRCON, chr, this.line_index));
    }

    private void skipWhitespace() {
        char c;
        try {
            while ((c = getsym()) != '\0') {
                if (c != ' ' && c != '\t' && c != '\n' && c != '\r') {
                    reader.unread(c);
                    break;
                } else if (c == '\n') {
                    this.line_index++;
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file");
        }
    }

    public ArrayList<Token> getTokens() {
        return this.tokens;
    }

}
