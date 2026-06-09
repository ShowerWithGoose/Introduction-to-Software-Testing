public class Lexer {
    private TokenStream tokenStream;
    public Lexer(){
        this.tokenStream = new TokenStream();
    }

    public void lexer_program(String string, ErrorList errorList) {
        int beginPos = 0;
        int endPos;
        int lineNum = 1;
        int len = string.length();
        String str;
        TokenType tokenType = null;
        boolean valueChar = true;
        while (beginPos < len) {
            endPos = beginPos + 1;
            if (this.isLower(string.charAt(beginPos)) || this.isUpper(string.charAt(beginPos)) || string.charAt(beginPos) == '_') {
                while (endPos < len && (this.isLower(string.charAt(endPos))
                        || this.isUpper(string.charAt(endPos))
                        || this.isDigit(string.charAt(endPos))
                        || string.charAt(endPos) == '_')) {
                    endPos += 1;
                }
                tokenType = lexerTK(string.substring(beginPos, endPos));
            } else if (this.isDigit(string.charAt(beginPos))) {
                while (endPos < len && (this.isDigit(string.charAt(endPos)))) {
                    endPos += 1;
                }
                tokenType = TokenType.INTCON;
            } else if (string.charAt(beginPos) == '\"') {
                while (!(string.charAt(endPos) == '\"' && string.charAt(endPos - 1) != '\\')) {
                    endPos += 1;
                }
                endPos += 1;
                tokenType = TokenType.STRCON;
            } else if (string.charAt(beginPos) == '\'') {
                if (string.charAt(endPos) == '\\') {
                    endPos += 2;
                } else {
                    endPos += 1;
                }
                endPos += 1;
                tokenType = TokenType.CHRCON;
            } else if (string.charAt(beginPos) == '!') {
                if (string.charAt(endPos) == '=') {
                    endPos += 1;
                    tokenType = TokenType.NEQ;
                } else {
                    tokenType = TokenType.NOT;
                }
            } else if (string.charAt(beginPos) == '&') {
                if (string.charAt(endPos) == '&') {
                    endPos += 1;
                } else {
                    errorList.addError(lineNum, "a");
                }
                tokenType = TokenType.AND;
            } else if (string.charAt(beginPos) == '|') {
                if (string.charAt(endPos) == '|') {
                    endPos += 1;
                } else {
                    errorList.addError(lineNum, "a");
                }
                tokenType = TokenType.OR;
            } else if (string.charAt(beginPos) == '-') {
                tokenType = TokenType.MINU;
            } else if (string.charAt(beginPos) == '+') {
                tokenType = TokenType.PLUS;
            } else if (string.charAt(beginPos) == '*') {
                tokenType = TokenType.MULT;
            } else if (string.charAt(beginPos) == ',') {
                tokenType = TokenType.COMMA;
            } else if (string.charAt(beginPos) == '(') {
                tokenType = TokenType.LPARENT;
            } else if (string.charAt(beginPos) == ')') {
                tokenType = TokenType.RPARENT;
            } else if (string.charAt(beginPos) == '/') {
                if (string.charAt(endPos) == '*') {
                    endPos += 1;
                    while (!(string.charAt(endPos) == '*' && string.charAt(endPos + 1) == '/')) {
                        if (string.charAt(endPos) == '\n') {
                            lineNum += 1;
                        }
                        endPos += 1;
                    }
                    endPos += 2;
                    valueChar = false;
                } else if (string.charAt(endPos) == '/') {
                    while (endPos < len && string.charAt(endPos) != '\n') {
                        endPos += 1;
                    }
                    endPos += 1;
                    valueChar = false;
                    lineNum += 1;
                } else {
                    tokenType = TokenType.DIV;
                }
            } else if (string.charAt(beginPos) == '%') {
                tokenType = TokenType.MOD;
            } else if (string.charAt(beginPos) == '<') {
                if (string.charAt(endPos) == '=') {
                    endPos += 1;
                    tokenType = TokenType.LEQ;
                } else {
                    tokenType = TokenType.LSS;
                }
            } else if (string.charAt(beginPos) == '>') {
                if (string.charAt(endPos) == '=') {
                    endPos += 1;
                    tokenType = TokenType.GEQ;
                } else {
                    tokenType = TokenType.GRE;
                }
            } else if (string.charAt(beginPos) == '=') {
                if (string.charAt(endPos) == '=') {
                    endPos += 1;
                    tokenType = TokenType.EQL;
                } else {
                    tokenType = TokenType.ASSIGN;
                }
            } else if (string.charAt(beginPos) == ';') {
                tokenType = TokenType.SEMICN;
            } else if (string.charAt(beginPos) == '[') {
                tokenType = TokenType.LBRACK;
            } else if (string.charAt(beginPos) == ']') {
                tokenType = TokenType.RBRACK;
            } else if (string.charAt(beginPos) == '{') {
                tokenType = TokenType.LBRACE;
            } else if (string.charAt(beginPos) == '}') {
                tokenType = TokenType.RBRACE;
            } else if (string.charAt(beginPos) == '\n') {
                valueChar = false;
                lineNum += 1;
            } else {
                valueChar = false;
            }
            if (valueChar) {
                str = string.substring(beginPos, endPos);
                this.tokenStream.addToken(new TokenStream.Token(tokenType, str));
            }
            beginPos = endPos;
            valueChar = true;
        }
    }

    public boolean isLower(char ch) {
        return ch <= 'z' && ch >= 'a';
    }

    public boolean isDigit(char ch) {
        return ch <= '9' && ch >= '0';
    }

    public boolean isUpper(char ch) {
        return ch <= 'Z' && ch >= 'A';
    }

    public TokenType lexerTK(String str) {
        if (str.compareTo("main") == 0) {
            return TokenType.MAINTK;
        } else if (str.compareTo("const") == 0) {
            return TokenType.CONSTTK;
        } else if (str.compareTo("int") == 0) {
            return TokenType.INTTK;
        } else if (str.compareTo("char") == 0) {
            return TokenType.CHARTK;
        } else if (str.compareTo("break") == 0) {
            return TokenType.BREAKTK;
        } else if (str.compareTo("continue") == 0) {
            return TokenType.CONTINUETK;
        } else if (str.compareTo("if") == 0) {
            return TokenType.IFTK;
        } else if (str.compareTo("else") == 0) {
            return TokenType.ELSETK;
        } else if (str.compareTo("for") == 0) {
            return TokenType.FORTK;
        } else if (str.compareTo("getint") == 0) {
            return TokenType.GETINTTK;
        } else if (str.compareTo("getchar") == 0) {
            return TokenType.GETCHARTK;
        } else if (str.compareTo("printf") == 0) {
            return TokenType.PRINTFTK;
        } else if (str.compareTo("return") == 0) {
            return TokenType.RETURNTK;
        } else if (str.compareTo("void") == 0) {
            return TokenType.VOIDTK;
        } else {
            return TokenType.IDENFR;
        }
    }

    public String toString() {
        return this.tokenStream.toString();
    }

}
