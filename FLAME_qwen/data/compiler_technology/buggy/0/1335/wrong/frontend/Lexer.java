package frontend;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Lexer {
    private HashMap<Integer, String> allLines;

    private String curLine;
    private int curPos = 0;
    private int lineNum = 1;
    private ArrayList<Token> tokens;

    private boolean hasError;

    private ArrayList<Error> errorInformation;

    public Lexer() {
        this.allLines = new HashMap<>();
        this.tokens = new ArrayList<>();
        this.hasError = false;
        this.errorInformation = new ArrayList<>();
    }

    private Character nextChar() {
        if (curPos >= curLine.length()) {
            return '\n';
        }
        char ch = curLine.charAt(curPos);
        curPos++;
        return ch;
    }

    private Character peekChar() {
        if (curPos >= curLine.length()) {
            return '\n';
        }
        return curLine.charAt(curPos);
    }

    private void skipWhitespace() {
        while (peekChar() != null && (peekChar() == ' ' || peekChar() == '\t' || peekChar() == '\r')) {
            nextChar();
        }
        if (peekChar() != null && peekChar() == '\n') {
            lineNum++;
            nextChar();
        }
    }

    public void tokenize() {
        int flag = 0;
        for (Map.Entry<Integer, String> entry : allLines.entrySet()) {
            curLine = entry.getValue(); // 获取当前行字符串
            curPos = 0; // 重置当前字符位置
            lineNum = entry.getKey(); // 获取行号

            while (curPos < curLine.length()) {
                skipWhitespace(); // 跳过空白字符
                Character currentChar = nextChar(); // 获取下一个字符,curpos++了

                // 处理单行注释
                if (currentChar == '/' && curPos< curLine.length() && curLine.charAt(curPos) == '/') {
                    break; // 退出当前行的处理
                }

                // 检查是否为多行注释开始
                if (currentChar == '/'&& curPos< curLine.length() && curLine.charAt(curPos) == '*' ) {
                    // 进入多行注释
                    flag = 1;
                    curPos += 2; // 跳过开始标记
                    continue; // 继续下一个字符
                }

                // 如果当前在多行注释中，则跳过处理
                if (flag == 1) {
                    int endCommentIndex = curLine.indexOf("*/", curPos - 1); // 查找结束标记位置
                    if (endCommentIndex != -1) {
                        flag = 0; //找到结束标记，退出多行注释
                        break;
                    } else {
                        break; // 如果没有找到结束标记，退出
                    }
                }

                // 检查是否是字母
                if (Character.isLetter(currentChar)|| currentChar == '_') {
                    StringBuilder identifier = new StringBuilder(); // 创建标识符构建器
                    identifier.append(currentChar); // 添加当前字母

                    while (Character.isLetterOrDigit(peekChar()) || peekChar() == '_') {
                        identifier.append(nextChar());
                    }

                    String idStr = identifier.toString();
                    // 判断是否为保留字
                    if (Type.isReservedWord(idStr)) {
                        tokens.add(new Token(idStr, Type.valueOf(idStr.toUpperCase() + "TK"), lineNum));
                    } else {
                        tokens.add(new Token(idStr, Type.IDENFR, lineNum));
                    }
                }

                else if (Character.isDigit(currentChar)) {
                    StringBuilder number = new StringBuilder();
                    number.append(currentChar);

                    // 继续追加数字
                    while (Character.isDigit(peekChar())) {
                        number.append(nextChar());
                    }
                    tokens.add(new Token(number.toString(), Type.INTCON, lineNum));
                }

                // 检查是否是字符串常量
                else if (currentChar == '\"') {
                    StringBuilder stringBuilder = new StringBuilder();
                    while (peekChar() != '\"') {
                        char current = nextChar();
                        if (current == '\\') { // 检查转义字符
                            stringBuilder.append(current); // 读取下一个字符
                            current = nextChar();
                            stringBuilder.append(current);
                        } else {
                            stringBuilder.append(current); // 添加当前字符
                        }
                    }
                    // 跳过结束的双引号
                    if (peekChar() == '\"') nextChar();
                    // 加上双引号
                    String strWithQuotes = "\"" + stringBuilder.toString() + "\"";
                    tokens.add(new Token(strWithQuotes, Type.STRCON, lineNum));
                }


                // 检查是否是字符常量
                else if (currentChar == '\'') {
                    StringBuilder charBuilder = new StringBuilder();
                    while (peekChar() != '\'') {
                        char current = nextChar();
                        if (current == '\\') { // Check for escape character
                            charBuilder.append(current); // Read the next character
                            current = nextChar();
                            charBuilder.append(current);
                        } else {
                            charBuilder.append(current); // Append the current character
                        }
                    }
                    if (peekChar() == '\'') nextChar(); // Skip the ending single quote
                    String charWithQuotes = "'" + charBuilder.toString() + "'";
                    tokens.add(new Token(charWithQuotes, Type.CHRCON, lineNum));
                }


                // 检查是否是操作符
                else {
                    String operator = String.valueOf(currentChar);
                    // 处理多字符运算符
                    if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '%') {
                        tokens.add(new Token(operator, Type.valueOf(operator.equals("+") ? "PLUS" :
                                operator.equals("-") ? "MINU" :
                                        operator.equals("*") ? "MULT" :
                                                operator.equals("/") ? "DIV" : "MOD"), lineNum));
                    }
                    else if (currentChar == '&' && peekChar() == '&') {
                        nextChar(); // 跳过第二个字符
                        tokens.add(new Token("&&", Type.AND, lineNum));
                    } else if (currentChar == '|' && peekChar() == '|') {
                        nextChar(); // 跳过第二个字符
                        tokens.add(new Token("||", Type.OR, lineNum));
                    } else if (currentChar == '<' || currentChar == '>' || currentChar == '!') {
                        if (peekChar() == '=') {
                            nextChar(); // 跳过第二个字符
                            tokens.add(new Token(currentChar + "=", Type.valueOf(currentChar == '<' ? "LEQ" :
                                    currentChar == '>' ? "GEQ" :
                                            currentChar == '=' ? "EQL" : "NEQ"), lineNum));
                        } else {
                            tokens.add(new Token(operator, Type.valueOf(operator.equals("<") ? "LSS" :
                                    operator.equals(">") ? "GRE" :
                                            operator.equals("=") ? "EQL" : "NOT"), lineNum));
                        }
                    } else if (currentChar == '=') {
                        if (peekChar() == '=') {
                            nextChar(); // 跳过第二个字符
                            tokens.add(new Token("==", Type.EQL, lineNum));
                        } else {
                            tokens.add(new Token("=", Type.ASSIGN, lineNum));
                        }
                    }
                    // 检查分隔符
                    else if (currentChar == ';') {
                        tokens.add(new Token(";", Type.SEMICN, lineNum));
                    } else if (currentChar == ',') {
                        tokens.add(new Token(",", Type.COMMA, lineNum));
                    } else if (currentChar == '(') {
                        tokens.add(new Token("(", Type.LPARENT, lineNum));
                    } else if (currentChar == ')') {
                        tokens.add(new Token(")", Type.RPARENT, lineNum));
                    } else if (currentChar == '[') {
                        tokens.add(new Token("[", Type.LBRACK, lineNum));
                    } else if (currentChar == ']') {
                        tokens.add(new Token("]", Type.RBRACK, lineNum));
                    } else if (currentChar == '{') {
                        tokens.add(new Token("{", Type.LBRACE, lineNum));
                    } else if (currentChar == '}') {
                        tokens.add(new Token("}", Type.RBRACE, lineNum));
                    }

                    else if((currentChar == '&' && peekChar() != '&') || (currentChar == '|' && peekChar() == '|')) {
                        this.hasError = true;
                        Error error = new Error(lineNum,'a');
                        this.errorInformation.add(error);
                    }
                }
            }
        }
    }



    public boolean isHasError() {
        return hasError;
    }

    public ArrayList<Error> getErrorInformation() {
        return errorInformation;
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public void addLine(int lineNumber, String line) {
        allLines.put(lineNumber, line);
    }
}
