import java.io.*;
import java.util.*;

public class Lexer {
    private int line; // 行号
    private int pos;  // 当前字符位置
    private String content; // 文件内容
    private List<Token> toks; // 存储正确的单词序列
    private List<String> errs; // 存储错误信息

    // 构造方法，初始化Lexer，读取指定文件
    public Lexer(String file) throws IOException {
        StringBuilder sb = new StringBuilder();
        BufferedReader reader = new BufferedReader(new FileReader(file));
        String ln;
        while ((ln = reader.readLine()) != null) {
            sb.append(ln).append("\n"); // 保留换行符
        }
        reader.close();
        content = sb.toString();
        toks = new ArrayList<>();
        errs = new ArrayList<>();
        line = 1; // 行号从1开始
        pos = 0;  // 从内容的第一个字符开始
    }

    // 主分析方法，处理整个内容
    public void run() throws IOException {
        while (pos < content.length()) {
            proc(); // 处理当前字符
        }
        writeOut(); // 写入输出文件
    }

    // 处理单个字符，识别单词或报告错误
    private void proc() {
        char ch = content.charAt(pos);

        // 更新行号
        if (ch == '\n') {
            line++;
            pos++;
            return;
        }

        // 跳过空白符
        if (Character.isWhitespace(ch)) {
            pos++;
            return;
        }

        // 识别标识符或关键字
        if (Character.isLetter(ch) || ch == '_') {
            StringBuilder id = new StringBuilder();
            while (pos < content.length() && (Character.isLetterOrDigit(content.charAt(pos)) || content.charAt(pos) == '_')) {
                id.append(content.charAt(pos));
                pos++;
            }
            handleId(id.toString());
        } else if (Character.isDigit(ch)) {
            // 识别无符号整数
            StringBuilder num = new StringBuilder();
            while (pos < content.length() && Character.isDigit(content.charAt(pos))) {
                num.append(content.charAt(pos));
                pos++;
            }
            toks.add(new Token(TokenType.INTCON, num.toString(), line));
        } else if (ch == '\"') {
            // 识别字符串常量
            StringBuilder str = new StringBuilder();
            str.append(ch);
            pos++;
            boolean err = false;
            while (pos < content.length()) {
                ch = content.charAt(pos);
                str.append(ch);
                pos++;
                if (ch == '\"') {
                    break;
                } else if (ch == '\\') {
                    // 处理转义字符
                    if (pos < content.length()) {
                        char nextChar = content.charAt(pos);
                        str.append(nextChar);
                        pos++;
                    } else {
                        err = true;
                        break;
                    }
                } else if (ch == '\n') {
                    line++;
                }
                if (pos >= content.length()) {
                    err = true;
                    break;
                }
            }
            if (err || str.charAt(str.length() - 1) != '\"') {
                errs.add(line + " a");  // 错误类别码 a 代表词法错误
            } else {
                toks.add(new Token(TokenType.STRCON, str.toString(), line));
            }
        } else if (ch == '\'') {
            // 识别字符常量
            StringBuilder chr = new StringBuilder();
            chr.append(ch);
            pos++;
            boolean err = false;
            if (pos < content.length()) {
                ch = content.charAt(pos);
                chr.append(ch);
                pos++;
                if (ch == '\\') {
                    // 处理转义字符
                    if (pos < content.length()) {
                        char nextChar = content.charAt(pos);
                        chr.append(nextChar);
                        pos++;
                    } else {
                        err = true;
                    }
                }
                if (pos < content.length() && content.charAt(pos) == '\'') {
                    chr.append('\'');
                    pos++;
                } else {
                    err = true;
                }
            } else {
                err = true;
            }
            if (err) {
                errs.add(line + " a"); // 错误符号
            } else {
                toks.add(new Token(TokenType.CHRCON, chr.toString(), line));
            }
        } else if (ch == '/') {
            // 处理注释和除号
            if (pos + 1 < content.length()) {
                char next = content.charAt(pos + 1);
                if (next == '/') { // 单行注释
                    pos += 2;
                    while (pos < content.length() && content.charAt(pos) != '\n') {
                        pos++;
                    }
                } else if (next == '*') { // 多行注释
                    pos += 2;
                    boolean endFound = false;
                    while (pos + 1 < content.length()) {
                        ch = content.charAt(pos);
                        if (ch == '\n') {
                            line++;
                        }
                        if (ch == '*' && content.charAt(pos + 1) == '/') {
                            pos += 2;
                            endFound = true;
                            break;
                        } else {
                            pos++;
                        }
                    }
                    if (!endFound) {
                        errs.add(line + " a"); // 未找到注释结束符
                    }
                } else {
                    // 除号
                    toks.add(new Token(TokenType.DIV, "/", line));
                    pos++;
                }
            } else {
                toks.add(new Token(TokenType.DIV, "/", line));
                pos++;
            }
        } else {
            // 处理特殊字符和操作符
            pos = handleChar(ch, pos);
        }
    }

    // 处理标识符或关键字
    private void handleId(String val) {
        switch (val) {
            case "int":
                toks.add(new Token(TokenType.INTTK, val, line));
                break;
            case "main":
                toks.add(new Token(TokenType.MAINTK, val, line));
                break;
            case "const":
                toks.add(new Token(TokenType.CONSTTK, val, line));
                break;
            case "char":
                toks.add(new Token(TokenType.CHARTK, val, line));
                break;
            case "break":
                toks.add(new Token(TokenType.BREAKTK, val, line));
                break;
            case "continue":
                toks.add(new Token(TokenType.CONTINUETK, val, line));
                break;
            case "if":
                toks.add(new Token(TokenType.IFTK, val, line));
                break;
            case "else":
                toks.add(new Token(TokenType.ELSETK, val, line));
                break;
            case "for":
                toks.add(new Token(TokenType.FORTK, val, line));
                break;
            case "getint":
                toks.add(new Token(TokenType.GETINTTK, val, line));
                break;
            case "getchar":
                toks.add(new Token(TokenType.GETCHARTK, val, line));
                break;
            case "printf":
                toks.add(new Token(TokenType.PRINTFTK, val, line));
                break;
            case "return":
                toks.add(new Token(TokenType.RETURNTK, val, line));
                break;
            case "void":
                toks.add(new Token(TokenType.VOIDTK, val, line));
                break;
            // 添加更多关键字处理
            default:
                toks.add(new Token(TokenType.IDENFR, val, line));
                break;
        }
    }

    // 处理特殊字符和运算符
    private int handleChar(char ch, int pos) {
        int nextPos = pos;
        switch (ch) {
            case '+':
                toks.add(new Token(TokenType.PLUS, "+", line));
                nextPos++;
                break;
            case '-':
                toks.add(new Token(TokenType.MINU, "-", line));
                nextPos++;
                break;
            case '*':
                toks.add(new Token(TokenType.MULT, "*", line));
                nextPos++;
                break;
            case '%':
                toks.add(new Token(TokenType.MOD, "%", line));
                nextPos++;
                break;
            case '<':
                if (nextPos + 1 < content.length() && content.charAt(nextPos + 1) == '=') {
                    toks.add(new Token(TokenType.LEQ, "<=", line));
                    nextPos += 2;
                } else {
                    toks.add(new Token(TokenType.LSS, "<", line));
                    nextPos++;
                }
                break;
            case '>':
                if (nextPos + 1 < content.length() && content.charAt(nextPos + 1) == '=') {
                    toks.add(new Token(TokenType.GEQ, ">=", line));
                    nextPos += 2;
                } else {
                    toks.add(new Token(TokenType.GRE, ">", line));
                    nextPos++;
                }
                break;
            case '=':
                if (nextPos + 1 < content.length() && content.charAt(nextPos + 1) == '=') {
                    toks.add(new Token(TokenType.EQL, "==", line));
                    nextPos += 2;
                } else {
                    toks.add(new Token(TokenType.ASSIGN, "=", line));
                    nextPos++;
                }
                break;
            case '!':
                if (nextPos + 1 < content.length() && content.charAt(nextPos + 1) == '=') {
                    toks.add(new Token(TokenType.NEQ, "!=", line));
                    nextPos += 2;
                } else {
                    toks.add(new Token(TokenType.NOT, "!", line));
                    nextPos++;
                }
                break;
            case ';':
                toks.add(new Token(TokenType.SEMICN, ";", line));
                nextPos++;
                break;
            case ',':
                toks.add(new Token(TokenType.COMMA, ",", line));
                nextPos++;
                break;
            case '(':
                toks.add(new Token(TokenType.LPARENT, "(", line));
                nextPos++;
                break;
            case ')':
                toks.add(new Token(TokenType.RPARENT, ")", line));
                nextPos++;
                break;
            case '[':
                toks.add(new Token(TokenType.LBRACK, "[", line));
                nextPos++;
                break;
            case ']':
                toks.add(new Token(TokenType.RBRACK, "]", line));
                nextPos++;
                break;
            case '{':
                toks.add(new Token(TokenType.LBRACE, "{", line));
                nextPos++;
                break;
            case '}':
                toks.add(new Token(TokenType.RBRACE, "}", line));
                nextPos++;
                break;
            case '&':
                if (nextPos + 1 < content.length() && content.charAt(nextPos + 1) == '&') {
                    toks.add(new Token(TokenType.AND, "&&", line));
                    nextPos += 2;
                } else {
                    errs.add(line + " a"); // 错误符号
                    nextPos++;
                }
                break;
            case '|':
                if (nextPos + 1 < content.length() && content.charAt(nextPos + 1) == '|') {
                    toks.add(new Token(TokenType.OR, "||", line));
                    nextPos += 2;
                } else {
                    errs.add(line + " a"); // 错误符号
                    nextPos++;
                }
                break;
            default:
                errs.add(line + " a"); // 未识别的字符
                nextPos++;
                break;
        }
        return nextPos;
    }

    // 写入输出文件
    private void writeOut() throws IOException {
        try (BufferedWriter lexOut = new BufferedWriter(new FileWriter("lexer.txt"));
             BufferedWriter errOut = new BufferedWriter(new FileWriter("error.txt"))) {

            for (Token tok : toks) {
                lexOut.write(tok.toString());
                lexOut.newLine();
            }

            for (String err : errs) {
                errOut.write(err);
                errOut.newLine();
            }
        }
    }
}
