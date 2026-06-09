package fronted.lexer;

import fronted.ErrorList;

import java.io.*;

public class Lexer {

    private final String source;

    private int curPos;
    //indicate the first char which have not been read or is ready to read

    private int lineNum;

    private TokenList tokenList;

    private Token currentToken;

    private boolean ifCorrect;


    public Lexer(String source) {
        this.source = source;
        this.curPos = 0;
        this.lineNum = 1;
        this.tokenList = new TokenList();
        this.ifCorrect = true;
    }

    public TokenList getTokenList() {
        return tokenList;
    }

    public void LexicalAnalyse() {
        while (curPos < source.length()) {
            char c = source.charAt(curPos);
            if (isBlank(c)) {
                if (c == '\n') {
                    lineNum++;
                }
                curPos++;
            } else {
                Token token = nextToken();
                tokenList.addToken(token);
            }
        }

    }

    public Token nextToken() {
        if (curPos == source.length()) {
            return null;
        }
        while (isBlank(source.charAt(curPos))) {
            if (source.charAt(curPos) == '\n') {
                lineNum++;
            }
            curPos++;
        }
        char c = source.charAt(curPos);
        if (isDigit(c)) {
            return nextDigit();
        } else if (c == '\'') {
            return nextChar();
        } else if (c == '\"') {
            return nextString();
        } else if (isAlpha(c) || c == '_') {
            return nextIdentifier();
        } else {
            return nextSpecial();
        }
    } //it doesn't contain analysis of a blank char

    private Token nextDigit() {
        StringBuilder sb = new StringBuilder();
        sb.append(source.charAt(curPos));
        curPos++;
        while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
            sb.append(source.charAt(curPos));
            curPos++;
        }
        return new Token(TokenType.Type.INTCON,sb.toString(),lineNum);
    } // when the next char is a num

    private Token nextChar() {
        StringBuilder sb = new StringBuilder();
        sb.append(source.charAt(curPos));
        curPos++;
        while (curPos < source.length() && source.charAt(curPos) != '\'') {
            //System.out.println(source.charAt(curPos));
            if (source.charAt(curPos) == '\\') {
                sb.append(source.charAt(curPos));
                curPos++;
            }
            sb.append(source.charAt(curPos));
            curPos++;
        }
        sb.append(source.charAt(curPos));
        curPos++;
        return new Token(TokenType.Type.CHRCON, sb.toString(), lineNum);
    } // when the next char is \'

    private Token nextString() {
        StringBuilder sb = new StringBuilder();
        sb.append(source.charAt(curPos));
        curPos++;
        while (curPos < source.length() && source.charAt(curPos) != '\"') {
            sb.append(source.charAt(curPos));
            curPos++;
        }
        sb.append(source.charAt(curPos));
        curPos++;
        return new Token(TokenType.Type.STRCON, sb.toString(), lineNum);
    } //when the next char is \"

    private Token nextIdentifier() {
        StringBuilder sb = new StringBuilder();
        sb.append(source.charAt(curPos));
        curPos++;
        while (curPos < source.length() && isIdent(source.charAt(curPos))) {
            sb.append(source.charAt(curPos));
            curPos++;
        }
        String ident = sb.toString();
        //judge if it is reserveWords
        switch (ident) {
            case "main" :
                return new Token(TokenType.Type.MAINTK,ident,lineNum);
            case "const":
                return new Token(TokenType.Type.CONSTTK,ident,lineNum);
            case "int":
                return new Token(TokenType.Type.INTTK,ident,lineNum);
            case "char":
                return new Token(TokenType.Type.CHARTK,ident,lineNum);
            case "break":
                return new Token(TokenType.Type.BREAKTK,ident,lineNum);
            case "continue":
                return new Token(TokenType.Type.CONTINUETK,ident,lineNum);
            case "if":
                return new Token(TokenType.Type.IFTK,ident,lineNum);
            case "else":
                return new Token(TokenType.Type.ELSETK,ident,lineNum);
            case "for":
                return new Token(TokenType.Type.FORTK,ident,lineNum);
            case "getint":
                return new Token(TokenType.Type.GETINTTK,ident,lineNum);
            case "getchar":
                return new Token(TokenType.Type.GETCHARTK,ident,lineNum);
            case "printf":
                return new Token(TokenType.Type.PRINTFTK,ident,lineNum);
            case "return":
                return new Token(TokenType.Type.RETURNTK,ident,lineNum);
            case "void":
                return new Token(TokenType.Type.VOIDTK,ident,lineNum);
            default:
                return new Token(TokenType.Type.IDENFR,ident,lineNum);
        }
    }

    private Token nextSpecial() {
        char c = source.charAt(curPos);
        curPos++;
        switch (c){
            case '!':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    curPos++;
                    return new Token(TokenType.Type.NEQ,"!=",lineNum);
                } else {
                    return new Token(TokenType.Type.NOT,"!",lineNum);
                }

            case '&':
                if (curPos < source.length() && source.charAt(curPos) == '&') {
                    curPos++;
                    return new Token(TokenType.Type.AND,"&&",lineNum);
                } else {
                    Token token = new Token(TokenType.Type.AND,"&",lineNum);
                    token.setFalse();
                    this.ifCorrect = false;
                    ErrorList.addError(lineNum,'a');
                    return token;
                }
            case '|':
                if (curPos < source.length() && source.charAt(curPos) == '|') {
                    curPos++;
                    return new Token(TokenType.Type.OR,"||",lineNum);
                } else {
                    Token token = new Token(TokenType.Type.OR, "|", lineNum);
                    token.setFalse();
                    this.ifCorrect = false;
                    ErrorList.addError(lineNum,'a');
                    return token;
                }
            case '+':
                return new Token(TokenType.Type.PLUS,"+",lineNum);
            case '-':
                return new Token(TokenType.Type.MINU,"-",lineNum);
            case '*':
                return new Token(TokenType.Type.MULT,"*",lineNum);
            case '/':
                if (curPos < source.length() && source.charAt(curPos) == '/') {
                    curPos++;
                    StringBuilder sb = new StringBuilder();
                    // sb stores all the note
                    sb.append("//");
                    while (curPos < source.length() && source.charAt(curPos) != '\n') {
                        char now = source.charAt(curPos);
                        sb.append(now);
                        curPos++;
                    }
                    if (curPos < source.length()) {
                        // if it is ended by \n
                        char now = source.charAt(curPos);
                        sb.append(now);
                        curPos++;
                        lineNum++;
                    }
                    //System.out.println("i git" + sb);
                    return nextToken();
                } else if (curPos < source.length() && source.charAt(curPos) == '*') {
                    curPos++;
                    StringBuilder sb = new StringBuilder();
                    sb.append("/*");
                    while (curPos < source.length()) {
                        while (curPos < source.length() && source.charAt(curPos) != '*') {
                            char now = source.charAt(curPos);
                            curPos++;
                            sb.append(now);
                            if (now == '\n') lineNum++;
                        }
                        while (curPos < source.length() && source.charAt(curPos) == '*') {
                            char now = source.charAt(curPos);
                            curPos++;
                            sb.append(now);
                        }
                        if (curPos < source.length() && source.charAt(curPos) == '/') {
                            char now = source.charAt(curPos);
                            curPos++;
                            sb.append(now);
                            //System.out.print("i got the 注释："+ sb.toString());
                            return nextToken();
                        }
                    }
                } else {
                    return new Token(TokenType.Type.DIV,"/",lineNum);
                }
            case '%':
                return new Token(TokenType.Type.MOD,"%",lineNum);
            case '<':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    curPos++;
                    return new Token(TokenType.Type.LEQ,"<=",lineNum);
                } else {
                    return new Token(TokenType.Type.LSS,"<",lineNum);
                }
            case '>':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    curPos++;
                    return new Token(TokenType.Type.GEQ,">=",lineNum);
                } else {
                    return new Token(TokenType.Type.GRE,">",lineNum);
                }
            case '=':
                if (curPos < source.length() && source.charAt(curPos) == '=') {
                    curPos++;
                    return new Token(TokenType.Type.EQL,"==",lineNum);
                } else {
                    return new Token(TokenType.Type.ASSIGN,"=",lineNum);
                }
            case ';':
                return new Token(TokenType.Type.SEMICN,";",lineNum);
            case ',':
                return new Token(TokenType.Type.COMMA,",",lineNum);
            case '(':
                return new Token(TokenType.Type.LPARENT,"(",lineNum);
            case ')':
                return new Token(TokenType.Type.RPARENT,")",lineNum);
            case '[':
                return new Token(TokenType.Type.LBRACK,"[",lineNum);
            case ']':
                return new Token(TokenType.Type.RBRACK,"]",lineNum);
            case '{':
                return new Token(TokenType.Type.LBRACE,"{",lineNum);
            case '}':
                return new Token(TokenType.Type.RBRACE,"}",lineNum);
            default:
                System.out.print("i got some strange thing: it is:");
                System.out.println((int) c);
                return null;
        }

    }

    public Token getToken() {
        return currentToken;
    }

    public TokenType.Type getTokenType() {
        return currentToken.getType();
    }

    private boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    private boolean isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    private boolean isBlank(char c) {
        return Character.isWhitespace(c);
    }

    private boolean isIdent(char c) {
        return isAlpha(c) || isDigit(c) || c == '_';
    }

    public void printInformation() {
        if (ifCorrect) {
            //System.out.print(tokenList.printTrue());
            String outputFile = "lexer.txt";
            /*try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {
                writer.write(tokenList.printTrue()); // 将内容写入文件
            } catch (IOException e) {
                e.printStackTrace(); // 处理异常
            }*/
            try {
                OutputStream outputStream = new FileOutputStream(outputFile);
                try {
                    outputStream.write(tokenList.printTrue().getBytes());
                } catch (IOException e) {
                    System.err.println("Can not Write it!");
                }
            } catch (FileNotFoundException e) {
                System.err.println("Can not Open!");
            }
        } else {
            //System.out.print(tokenList.printFalse());
            String outputFile = "error.txt";
            /*try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {
                writer.write(tokenList.printFalse()); // 将内容写入文件
            } catch (IOException e) {
                e.printStackTrace(); // 处理异常
            }*/
            try {
                OutputStream outputStream = new FileOutputStream(outputFile);
                try {
                    outputStream.write(tokenList.printFalse().getBytes());
                } catch (IOException e) {
                    System.err.println("Can not Write it!");
                }
            } catch (FileNotFoundException e) {
                System.err.println("Can not Open!");
            }
        }
    }
}
