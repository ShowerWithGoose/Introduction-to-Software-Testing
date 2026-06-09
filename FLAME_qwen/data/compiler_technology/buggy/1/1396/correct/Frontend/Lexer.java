package Frontend;

import java.io.Reader;

import Utils.Token;

public class Lexer {
    private Reader fileReader;
    private int line = 1;

    public Lexer(Reader fileReader) { this.fileReader = fileReader; }

    public Lexer(Reader fileReader, int line) {
        this.fileReader = fileReader;
        for (; this.line < line; this.line++)
            try { while (fileReader.read() != '\n'); }
            catch (Exception e) { e.printStackTrace(); }
    }

    public TokenList lex() {
        TokenList tokenList = new TokenList();
        try {
            char ch = (char) fileReader.read();
            while (ch != (char) -1) {
                if (isWhitespace(ch)) {
                    ch = (char) fileReader.read();
                    continue;
                } else if (ch == (char) -1) break;
                StringBuilder sb = new StringBuilder();
                if (Character.isDigit(ch)) {
                    while (Character.isDigit(ch)) {
                        sb.append(ch);
                        ch = (char) fileReader.read();
                    }
                } else if (Character.isAlphabetic(ch) || ch == '_') {
                    while (Character.isDigit(ch) || Character.isAlphabetic(ch) || ch == '_') {
                        sb.append(ch);
                        ch = (char) fileReader.read();
                    }
                } else {
                    switch (ch) {
                        case '"':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            while (ch != '"') {
                                if (ch == '\\') {
                                    sb.append(ch);
                                    ch = (char) fileReader.read();
                                }
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            }
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            break;
                        case '/':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '/') {
                                sb.append(ch);
                                while (ch != '\n' && ch != (char) -1) { ch = (char) fileReader.read(); }
                            } else if (ch == '*') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                                while (true) {
                                    if (ch == '*') {
                                        sb.append(ch);
                                        ch = (char) fileReader.read();
                                        if (ch == '/') {
                                            sb.append(ch);
                                            ch = (char) fileReader.read();
                                            break;
                                        } else {
                                            if (ch == '\n') { this.line++; }
                                            continue;
                                        }
                                    }
                                    if (ch == '\n') { this.line++; }
                                    ch = (char) fileReader.read();
                                }
                            } break;
                        case '=':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '=') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            } break;
                        case '!':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '=') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            } break;
                        case '<':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '=') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            } break;
                        case '>':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '=') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            } break;
                        case '&':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '&') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            } break;
                        case '|':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '|') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            } break;
                        case '\'':
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            if (ch == '\\') {
                                sb.append(ch);
                                ch = (char) fileReader.read();
                            }
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            break;
                        default:
                            sb.append(ch);
                            ch = (char) fileReader.read();
                            break;
                    }
                }
                Token token = new Token(sb.toString(), this.line);
                if (token.getType().equals(Token.Type.UNKNOWN) || token.getType().equals(Token.Type.COMMENT)) { continue; }
                tokenList.add(token);
            }
        } catch (Exception e) { System.err.println("Error when lexing."); }
        return tokenList;
    }

    private boolean isWhitespace(char c) {
        if (c == '\n') this.line++;
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }
}