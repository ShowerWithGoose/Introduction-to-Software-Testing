import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Lexer {
    private static BufferedWriter os; // 输出正确的单词及其类型
    private static BufferedWriter error; // 输出错误信息
    private Token token;

    static {
        try {
            os = new BufferedWriter(new FileWriter("lexer.txt"));
            error = new BufferedWriter(new FileWriter("error.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Lexer(Token token) {
        this.token = token;
    }

    // 词法分析
        public void getAllTokens() {
        while (token.curPos < token.length) {
            getSym();
        }

        try {
            os.close();
            error.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 获取下一个单词
    public void getSym() {
        token.clearToken();
        char ch;

        // 跳过空白符
        while (token.curPos < token.length && Character.isWhitespace(ch = token.source.charAt(token.curPos))) {
            if (ch == '\n') {
                token.lineNum++;
            }
            token.curPos++;
        }

        if (token.curPos >= token.length) return; // 文件末尾

        ch = token.source.charAt(token.curPos);

        // 识别标识符
        if (Character.isLetter(ch) || ch == '_') {
            while (token.curPos < token.length && (Character.isLetterOrDigit(ch) || ch == '_')) {
                token.word += ch; // 构建当前单词
                token.curPos++;
                if (token.curPos < token.length) {
                    ch = token.source.charAt(token.curPos);
                }
            }
            token.type = isReserveWord(token.word) ? TokenType.valueOf(token.word.toUpperCase() + "TK") : TokenType.IDENFR;
            writeOutput(token.type, token.word); // Write to lexer.txt
        }
        // 识别数字
        else if (Character.isDigit(ch)) {
            while (token.curPos < token.length && Character.isDigit(ch)) {
                token.word += ch;
                token.curPos++;
                if (token.curPos < token.length) {
                    ch = token.source.charAt(token.curPos);
                }
            }
            token.type = TokenType.INTCON;
            writeOutput(token.type, token.word);
        }

        //处理字符常量
        else if (ch == '\'') {
            token.curPos++;
            token.word += "'";

            if (token.curPos < token.length) {
                ch = token.source.charAt(token.curPos);

                if (ch == '\\') {
                    token.curPos++;
                    if (token.curPos < token.length) {
                        char escapeChar = token.source.charAt(token.curPos);
                        switch (escapeChar) {
                            case 'n': token.word += "\\n"; break;
                            case 't': token.word += "\\t"; break;
                            case 'b': token.word += "\\b"; break;
                            case 'f': token.word += "\\f"; break;
                            case 'r': token.word += "\\r"; break;
                            case 'a': token.word += "\\a"; break;
                            case 'v': token.word += "\\v"; break;
                            case '\'': token.word += "\\'"; break;
                            case '\"': token.word += "\\\""; break;
                            case '\\': token.word += "\\\\"; break;
                            case '0': token.word += "\\0"; break;
                            default: writeError(token.lineNum, "UNKNOWN ESCAPE CHAR"); return;
                        }
                    }
                } else {
                    token.word += ch;
                }
                token.curPos++;
                if (token.curPos < token.length && token.source.charAt(token.curPos) == '\'') {
                    token.word += "'";
                    token.curPos++;
                    token.type = TokenType.CHRCON;
                    writeOutput(token.type, token.word);
                } else {
                    writeError(token.lineNum, "CharConst error");
                }
            } else {
                writeError(token.lineNum, "CharConst error");
            }
        }

        //处理字符串常量
        else if (ch == '"') {
            token.curPos++;
            token.word += '"';

            while (token.curPos < token.length) {
                ch = token.source.charAt(token.curPos);

                if (ch == '"') {
                    token.word += '"';
                    token.curPos++;
                    token.type = TokenType.STRCON;
                    writeOutput(token.type, token.word);
                    return;
                }

                if (ch == '\\') {
                    token.curPos++;
                    if (token.curPos < token.length && token.source.charAt(token.curPos) == 'n') {
                        token.word += "\\n";
                        token.curPos++;
                    } else {
                        writeError(token.lineNum, "String ERROR");
                        return;
                    }
                } else {
                    token.word += ch;
                    token.curPos++;
                }
            }

            writeError(token.lineNum, "String ERROR");
        }

        // 处理其他字符
        else {
            switch (ch) {
                case '+': token.type = TokenType.PLUS; token.word += "+";token.curPos++;break;
                case '-': token.type = TokenType.MINU;token.word += "-"; token.curPos++;break;
                case '*': token.type = TokenType.MULT;token.word += "*"; token.curPos++;break;
                case '%': token.type = TokenType.MOD; token.word += "%";token.curPos++;break;
                case ';': token.type = TokenType.SEMICN;token.word += ";";token.curPos++;break;
                case ',': token.type = TokenType.COMMA; token.word += ",";token.curPos++;break;
                case '(': token.type = TokenType.LPARENT;token.word += "(";token.curPos++;break;
                case ')': token.type = TokenType.RPARENT;token.word += ")";token.curPos++;break;
                case '[': token.type = TokenType.LBRACK;token.word += "["; token.curPos++;break;
                case ']': token.type = TokenType.RBRACK; token.word += "]";token.curPos++;break;
                case '{': token.type = TokenType.LBRACE;token.word += "{"; token.curPos++;break;
                case '}': token.type = TokenType.RBRACE; token.word += "}";token.curPos++;break;
                case '/':
                    token.curPos++;
                    if (token.curPos < token.length) {
                        char nextCh = token.source.charAt(token.curPos);
                        if (nextCh == '/') {
                            // 单行注释处理
                            while (token.curPos < token.length && token.source.charAt(token.curPos) != '\n') {
                                token.curPos++;
                            }
                        }
                        else if (nextCh == '*') {
                            // 多行注释处理
                            token.curPos++;
                            while (token.curPos < token.length) {
                                char currentCh = token.source.charAt(token.curPos);
                                if (currentCh == '*' && token.curPos + 1 < token.length && token.source.charAt(token.curPos + 1) == '/') {
                                    token.curPos=token.curPos+2;
                                    break;
                                }
                                token.curPos++;
                            }
                        }
                        else {
                            // 处理除号
                            token.type = TokenType.DIV;
                            token.word += "/";
                        }
                    }
                    break;
                case '<':
                    token.curPos++;
                    if (token.curPos < token.length && token.source.charAt(token.curPos) == '=') {
                        token.type = TokenType.LEQ;
                        token.word += "<=";
                        token.curPos++;
                    } else {
                        token.type = TokenType.LSS;
                        token.word += "<";
                    }
                    break;
                case '>':
                    token.curPos++;
                    if (token.curPos < token.length && token.source.charAt(token.curPos) == '=') {
                        token.type = TokenType.GEQ;
                        token.word += ">=";
                        token.curPos++;
                    } else {
                        token.type = TokenType.GRE;
                        token.word += ">";
                    }
                    break;
                case '=':
                    token.curPos++;
                    if (token.curPos < token.length && token.source.charAt(token.curPos) == '=') {
                        token.type = TokenType.EQL;
                        token.word += "==";
                        token.curPos++;
                    } else {
                        token.type = TokenType.ASSIGN;
                        token.word += "=";
                    }
                    break;
                case '!':
                    token.curPos++;
                    if (token.curPos < token.length && token.source.charAt(token.curPos) == '=') {
                        token.type = TokenType.NEQ;
                        token.word += "!=";
                        token.curPos++;
                    } else {
                        token.type = TokenType.NOT;
                        token.word += "!";
                    }
                    break;
                case '&':
                    token.curPos++;
                    if (token.curPos < token.length && token.source.charAt(token.curPos) == '&') {
                        token.type = TokenType.AND;
                        token.word += "&&";
                        token.curPos++;
                    } else {
                        writeError(token.lineNum, "a");
                    }
                    break;
                case '|':
                    token.curPos++;
                    if (token.curPos < token.length && token.source.charAt(token.curPos) == '|') {
                        token.type = TokenType.OR;
                        token.word += "||";
                        token.curPos++;
                    } else {
                        writeError(token.lineNum, "a");
                    }
                    break;
                default:
                    writeError(token.lineNum, "UNKNOWN");
                    break;
            }
            if(token.type!=null)
             writeOutput(token.type, token.word);
        }
    }

    // 是否为关键字
    private boolean isReserveWord(String word) {
        String[] reserveWordsWords = {"main", "const", "int", "char", "break", "continue", "if",
                "else", "for", "getint", "getchar", "printf", "return", "void"};
        for (String kw : reserveWordsWords) {
            if (kw.equals(word)) return true;
        }
        return false;
    }

    private void writeOutput(TokenType type, String word) {
        try {
            os.write(type + " " + word);
            os.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeError(int line, String message) {
        try {
            error.write(line + " " + message);
            error.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
