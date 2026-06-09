import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class Lexer {

    // data
    private ArrayList<Token> tokensArray;
    private Scanner codes;
    private ErrorInfo errorInfo = new ErrorInfo(null, 0);

    public Lexer(Scanner codes) {
        tokensArray  = new ArrayList<>();
        this.codes = codes;
    }

    public ArrayList<Token> getTokensArray() {
        return tokensArray;
    }

    public int getTokens() {
        int normal; // 正常值为0
        int line   = 1;
        while (codes.hasNextLine()) { // 读一行
            String codeLine = codes.nextLine();
            codeLine += " ";
            normal = getSymbol(codeLine);
            if (normal < 0) {
                handlError("a", line);
                return line;
            }
            line++;
        }
        return 0;
    }

    public void printError() {
        errorInfo.printError();
    }

    private void handlError(String kind, int line) {
        errorInfo.setInfo(kind, line);
    }

    public int getSymbol(String codeLine) {
        int  pos    = 0; // initialize the line
        int  length = codeLine.length();
        char letter = codeLine.charAt(pos);
        String word = "";
        while (true) {
            while (letter == ' ' || letter == '\t') { // skip " " and "\t"
                pos++;
                if (pos == length) {
                    break;
                } else {
                    letter = codeLine.charAt(pos);
                }
            }
            if (pos == length) { // meet the ending
                break;
            }
            else if (isLetter(letter)) {
                word = "" + letter;
                pos++;
                letter = codeLine.charAt(pos);
                while (isIdent(letter)) {
                    word += letter;
                    pos++;
                    letter = codeLine.charAt(pos);
                }
                addToken(word);
            } else if (isDigit(letter)) {
                word = "" + letter;
                pos++;
                letter = codeLine.charAt(pos);
                while (isDigit(letter)) {
                    word += letter;
                    pos++;
                    letter = codeLine.charAt(pos);
                }
                addToken("IntConst", word, TokenKind.INTCON);
            } else if (letter == '\"') {
                word = "" + letter;
                pos++;
                letter = codeLine.charAt(pos);
                while (letter != '\"') {
                    if (letter == '\\') {
                        word += letter;
                        pos++;
                        letter = codeLine.charAt(pos);
                        word += letter;
                    } else {
                        word += letter;
                    }
                    pos++;
                    letter = codeLine.charAt(pos);
                }
                word += letter;
                addToken("StringConst", word, TokenKind.STRCON);
                pos++;
                letter = codeLine.charAt(pos);
            } else if (letter == '\'') {
                word = "" + letter;
                pos++;
                letter = codeLine.charAt(pos);
                if (letter == '\\') {
                    word += letter;
                    pos++;
                    letter = codeLine.charAt(pos);
                    word += letter;
                } else {
                    word += letter;
                }
                pos+=2;
                letter = codeLine.charAt(pos);
                word += '\'';
                addToken("CharConst", word, TokenKind.CHARTK);
            } else {
                if (letter == '+') {
                    addToken("+", "+", TokenKind.PLUS);
                }
                else if (letter == '-') {
                    addToken("-", "-", TokenKind.MINU);
                }
                else if (letter == '*') {
                    addToken("*", "*", TokenKind.MULT);
                }
                else if (letter == '/') {
                    addToken("/", "/", TokenKind.DIV);
                }
                else if (letter == '%') {
                    addToken("%", "%", TokenKind.MOD);
                }
                else if (letter == ';') {
                    addToken(";", ";", TokenKind.SEMICN);
                }
                else if (letter == ',') {
                    addToken(",", ",", TokenKind.COMMA);
                }
                else if (letter == '(') {
                    addToken("(", "(", TokenKind.LPARENT);
                }
                else if (letter == ')') {
                    addToken(")", ")", TokenKind.RPARENT);
                }
                else if (letter == '[') {
                    addToken("[", "[", TokenKind.LBRACK);
                }
                else if (letter == ']') {
                    addToken("]", "]", TokenKind.RBRACK);
                }
                else if (letter == '{') {
                    addToken("{", "{", TokenKind.LBRACE);
                }
                else if (letter == '}') {
                    addToken("}", "}", TokenKind.RBRACE);
                }
                else if (letter == '&') {
                    pos++;
                    letter = codeLine.charAt(pos);
                    if (letter == '&') {
                        word = "&&";
                        addToken(word, word, TokenKind.AND);
                    } else {
                        return -1;
                    }
                }
                else if (letter == '|') {
                    pos++;
                    letter = codeLine.charAt(pos);
                    if (letter == '|') {
                        word = "||";
                        addToken(word, word, TokenKind.OR);
                    } else {
                        return -1;
                    }
                }
                else if (letter == '!') {
                    word = "!";
                    pos++;
                    letter = codeLine.charAt(pos);
                    if (letter == '=') {
                        word += letter;
                        addToken(word, word, TokenKind.NEQ);
                    } else {
                        addToken(word, word, TokenKind.NOT);
                        pos--;
                    }
                }
                else if (letter == '<') {
                    word = "<";
                    pos++;
                    letter = codeLine.charAt(pos);
                    if (letter == '=') {
                        word += letter;
                        addToken(word, word, TokenKind.LEQ);
                    } else {
                        addToken(word, word, TokenKind.LSS);
                        pos--;
                    }
                }
                else if (letter == '>') {
                    word = ">";
                    pos++;
                    letter = codeLine.charAt(pos);
                    if (letter == '=') {
                        word += letter;
                        addToken(word, word, TokenKind.GEQ);
                    } else {
                        addToken(word, word, TokenKind.GRE);
                        pos--;
                    }
                }
                else if (letter == '=') {
                    word = "=";
                    pos++;
                    letter = codeLine.charAt(pos);
                    if (letter == '=') {
                        word += letter;
                        addToken(word, word, TokenKind.EQL);
                    } else {
                        addToken(word, word, TokenKind.ASSIGN);
                        pos--;
                    }
                }
                pos++;
                letter = codeLine.charAt(pos);
            }
        }
        return 0;
    }

    public void addToken(String name, String contents, TokenKind kind) {
        tokensArray.add(new Token(name, contents, kind));
    }

    public void addToken(String tokenStr) {
        if (Objects.equals(tokenStr, "main")) {
            tokensArray.add(new Token("main", "main", TokenKind.MAINTK));
        }
        else if (Objects.equals(tokenStr, "const")) {
            tokensArray.add(new Token("const", "const", TokenKind.CONSTTK));
        }
        else if (Objects.equals(tokenStr, "int")) {
            tokensArray.add(new Token("int", "int", TokenKind.INTTK));
        }
        else if (Objects.equals(tokenStr, "char")) {
            tokensArray.add(new Token("char", "char", TokenKind.CHARTK));
        }
        else if (Objects.equals(tokenStr, "break")) {
            tokensArray.add(new Token("break", "break", TokenKind.BREAKTK));
        }
        else if (Objects.equals(tokenStr, "continue")) {
            tokensArray.add(new Token("continue", "continue", TokenKind.CONTINUETK));
        }
        else if (Objects.equals(tokenStr, "if")) {
            tokensArray.add(new Token("if", "if", TokenKind.IFTK));
        }
        else if (Objects.equals(tokenStr, "else")) {
            tokensArray.add(new Token("else", "else", TokenKind.ELSETK));
        }
        else if (Objects.equals(tokenStr, "for")) {
            tokensArray.add(new Token("for", "for", TokenKind.FORTK));
        }
        else if (Objects.equals(tokenStr, "getint")) {
            tokensArray.add(new Token("getint", "getint", TokenKind.GETINTTK));
        }
        else if (Objects.equals(tokenStr, "getchar")) {
            tokensArray.add(new Token("getchar", "getchar", TokenKind.GETCHARTK));
        }
        else if (Objects.equals(tokenStr, "printf")) {
            tokensArray.add(new Token("printf", "printf", TokenKind.PRINTFTK));
        }
        else if (Objects.equals(tokenStr, "return")) {
            tokensArray.add(new Token("return", "return", TokenKind.RETURNTK));
        }
        else if (Objects.equals(tokenStr, "void")) {
            tokensArray.add(new Token("void", "void", TokenKind.VOIDTK));
        }
        else {
            tokensArray.add(new Token("Ident", tokenStr, TokenKind.IDENFR));
        }
    }

    public boolean isLetter(char letter) {
        return ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || letter == '_');
    }

    public boolean isIdent(char letter) {
        return ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || letter == '_'
        || (letter >= '0' && letter <= '9'));
    }

    public boolean isDigit(char letter) {
        return (letter >= '0' && letter <= '9');
    }
}
