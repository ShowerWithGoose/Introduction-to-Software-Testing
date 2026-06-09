package frontend;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private final InputStream inputStream;
    private int lineNum;// 用于记录当前行号
    private StringBuilder context;
    private final HashMap<Integer, ArrayList<Pair>> tokens;

    public Lexer(InputStream inputStream) {
        this.context = new StringBuilder();
        this.inputStream = inputStream;
        this.tokens = new HashMap<>();
        this.lineNum = 0;
    }

    public void deal() {
        try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(this.inputStream))) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                this.context.append(line);
                this.context.append('\n');
            }
            analyse(deleteNotation());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public HashMap<Integer, ArrayList<Pair>> getTokens() {
        return tokens;
    }

    public StringBuilder deleteNotation() {
        StringBuilder result = new StringBuilder();
        int contextLength = this.context.length();
        boolean inString = false;
        for (int i = 0; i < contextLength; i++) {
            char c = context.charAt(i);
            char next = i + 1 < contextLength ? context.charAt(i + 1) : '\0';
            if (c == '\"') {
                inString = !inString;
            }
            if (!inString && c == '/' && next == '/') {
                for (int j = i + 2; j < contextLength; j++) {
                    if (context.charAt(j) == '\n') {
                        i = j - 1;
                        break;
                    }
                }
                continue;
            }
            if (!inString && c == '/' && next == '*') {
                for (int j = i + 2; j < contextLength - 1; j++) {
                    if (context.charAt(j) == '*' && context.charAt(j + 1) == '/') {
                        i = j + 1;
                        break;
                    } else if (context.charAt(j) == '\n') {
                        result.append('\n');
                    }
                }
                continue;
            }
            result.append(context.charAt(i));
        }
        return result;
    }

    public void analyse(StringBuilder stringBuilder) { // 将注释部分处理掉
        String[] stringArrayList = stringBuilder.toString().split("\n");
        for (int i = 0; i < stringArrayList.length; i++) {
            String line = stringArrayList[i];
            this.lineNum = i + 1;
            ArrayList<Pair> pairs = new ArrayList<>();
            line = deleteBlank(line);
            int pos = 0;
            while (pos < line.length()) {
                Pair pair = getToken(pos, line);
                if (!pair.getValue().equals(" ")) {
                    pairs.add(pair);
                }
                pos += pair.getValue().length();
            }
            this.tokens.put(this.lineNum, pairs);
        }

    }

    public String deleteBlank(String line) {
        int start = 0;
        int len = line.length();
        int end = len - 1;

        // 遍历字符串，找到第一个非空白符号的位置
        while (start < len && Character.isWhitespace(line.charAt(start))) {
            start++;
        }
        while (end > start && Character.isWhitespace(line.charAt(end))) {
            end--;
        }
        return line.substring(start, end + 1);
    }


    // 得到当前位置的单词
    public Pair getToken(int pos, String line) {
        Pair pair = new Pair(this.lineNum, " ");
        StringBuilder token = new StringBuilder();
        if (line.charAt(pos) == ' ' || line.charAt(pos) == '\n' || line.charAt(pos) == '\t') {
            pair = new Pair(this.lineNum, " ");
        } else if (Character.isDigit(line.charAt(pos))) {
            token.append(line.charAt(pos++));
            while (pos < line.length() && Character.isDigit(line.charAt(pos))) {
                token.append(line.charAt(pos++));
            }
            return new Pair(this.lineNum, LexType.INTCON, token.toString());
        } else if (isNotDigit(line.charAt(pos))) {
            if (isKeySymbol(line.charAt(pos))) {
                pair = parseKeySymbol(pos, line, token);
            } else if (line.charAt(pos) == '\"') {
                pair = parseStringConst(pos, line, token);
            } else if (line.charAt(pos) == '\'') {
                pair = parseCharConst(pos, line, token);
            } else {
                token.append(line.charAt(pos++));
                while (pos < line.length() && !isKeySymbol(line.charAt(pos)) &&
                        (isNotDigit(line.charAt(pos)) || Character.isDigit(line.charAt(pos)))) {
                    token.append(line.charAt(pos++));
                }
                pair = parseKeyWord(token.toString());
            }
        }
        return pair;
    }

    public boolean isNotDigit(char ch) {
        return (ch > 32 && ch <= 126) && !Character.isDigit(ch);
    }

    public boolean isKeySymbol(char ch) {
        return ch == '!' || ch == '&' || ch == '|' || ch == '+' || ch == '-' || ch == '*'
                || ch == '/' || ch == '%' || ch == '<' || ch == '>' || ch == '=' || ch == ';'
                || ch == ',' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}';
    }

    public Pair parseStringConst(int pos, String line, StringBuilder token) {
        token.append(line.charAt(pos++));
        while (pos < line.length() && line.charAt(pos) != '\"') {
            token.append(line.charAt(pos++));
        }
        token.append(line.charAt(pos));
        return new Pair(this.lineNum, LexType.STRCON, token.toString());
    }

    public Pair parseCharConst(int pos, String line, StringBuilder token) {
        token.append(line.charAt(pos++));
        while (pos < line.length() && line.charAt(pos) != '\'') {
            if (line.charAt(pos) == '\\') {
                token.append(line.charAt(pos++));
            }
            token.append(line.charAt(pos++));
        }
        token.append(line.charAt(pos));
        return new Pair(this.lineNum, LexType.CHRCON, token.toString());
    }

    public Pair parseKeySymbol(int pos, String line, StringBuilder token) {
        Pair result = null;
        char ch = line.charAt(pos++);
        token.append(ch);
        if (ch == '!') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                result = new Pair(this.lineNum, LexType.NEQ, token.toString());
            } else {
                result = new Pair(this.lineNum, LexType.NOT, token.toString());
            }
        } else if (ch == '&') {
            if (line.charAt(pos) == '&') {
                token.append(line.charAt(pos));
            }
            result = new Pair(this.lineNum, LexType.AND, token.toString());
        } else if (ch == '|') {
            if (line.charAt(pos) == '|') {
                token.append(line.charAt(pos));
            }
            result = new Pair(this.lineNum, LexType.OR, token.toString());
        } else if (ch == '<') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                result = new Pair(this.lineNum, LexType.LEQ, token.toString());
            } else {
                result = new Pair(this.lineNum, LexType.LSS, token.toString());
            }
        } else if (ch == '>') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                result = new Pair(this.lineNum, LexType.GEQ, token.toString());
            } else {
                result = new Pair(this.lineNum, LexType.GRE, token.toString());
            }
        } else if (ch == '=') {
            if (line.charAt(pos) == '=') {
                token.append(line.charAt(pos));
                result = new Pair(this.lineNum, LexType.EQL, token.toString());
            } else {
                result = new Pair(this.lineNum, LexType.ASSIGN, token.toString());
            }
        } else if (ch == '+') {
            result = new Pair(this.lineNum, LexType.PLUS, token.toString());
        } else if (ch == '-') {
            result = new Pair(this.lineNum, LexType.MINU, token.toString());
        } else if (ch == '*') {
            result = new Pair(this.lineNum, LexType.MULT, token.toString());
        } else if (ch == '/') {
            result = new Pair(this.lineNum, LexType.DIV, token.toString());
        } else if (ch == '%') {
            result = new Pair(this.lineNum, LexType.MOD, token.toString());
        } else if (ch == ';') {
            result = new Pair(this.lineNum, LexType.SEMICN, token.toString());
        } else if (ch == ',') {
            result = new Pair(this.lineNum, LexType.COMMA, token.toString());
        } else if (ch == '(') {
            result = new Pair(this.lineNum, LexType.LPARENT, token.toString());
        } else if (ch == ')') {
            result = new Pair(this.lineNum, LexType.RPARENT, token.toString());
        } else if (ch == '[') {
            result = new Pair(this.lineNum, LexType.LBRACK, token.toString());
        } else if (ch == ']') {
            result = new Pair(this.lineNum, LexType.RBRACK, token.toString());
        } else if (ch == '{') {
            result = new Pair(this.lineNum, LexType.LBRACE, token.toString());
        } else if (ch == '}') {
            result = new Pair(this.lineNum, LexType.RBRACE, token.toString());
        }
        return result;
    }

    public Pair parseKeyWord(String token) {
        Pair result;
        switch (token) {
            case "main" -> result = new Pair(this.lineNum, LexType.MAINTK, token);
            case "const" -> result = new Pair(this.lineNum, LexType.CONSTTK, token);
            case "int" -> result = new Pair(this.lineNum, LexType.INTTK, token);
            case "char" -> result = new Pair(this.lineNum, LexType.CHARTK, token);
            case "break" -> result = new Pair(this.lineNum, LexType.BREAKTK, token);
            case "continue" -> result = new Pair(this.lineNum, LexType.CONTINUETK, token);
            case "if" -> result = new Pair(this.lineNum, LexType.IFTK, token);
            case "else" -> result = new Pair(this.lineNum, LexType.ELSETK, token);
            case "for" -> result = new Pair(this.lineNum, LexType.FORTK, token);
            case "getint" -> result = new Pair(this.lineNum, LexType.GETINTTK, token);
            case "getchar" -> result = new Pair(this.lineNum, LexType.GETCHARTK, token);
            case "printf" -> result = new Pair(this.lineNum, LexType.PRINTFTK, token);
            case "return" -> result = new Pair(this.lineNum, LexType.RETURNTK, token);
            case "void" -> result = new Pair(this.lineNum, LexType.VOIDTK, token);
            default -> result = new Pair(this.lineNum, LexType.IDENFR, token);
        }
        return result;
    }
}
