package lexer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import token.Token;

public class Lexer {
    public static int line = 0; // 所在行号
    public char errCode; // 错误代码
    public int errLine = 0; // 错误行号
    public boolean errSym = true; // 错误符号
    public boolean inComment = false; // 是否在注释中

    // 关键字和对应名称数组
    public static final String[] KEYWORDS = {
            "main", "const", "int", "char", "break",
            "continue", "if", "else", "for",
            "getint", "getchar", "printf", "return", "void"
    };

    public static final String[] KEY_NAMES = {
            "MAINTK", "CONSTTK", "INTTK", "CHARTK",
            "BREAKTK", "CONTINUETK", "IFTK", "ELSETK",
            "FORTK", "GETINTTK", "GETCHARTK", "PRINTFTK",
            "RETURNTK", "VOIDTK"
    };

    private final StringBuilder outputBuilder = new StringBuilder(); // 用于存储输出内容

    public void run(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"))) {
            String currentLine;

            while ((currentLine = reader.readLine()) != null) {
                line++;
                processLine(currentLine, line);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 处理每一行文本
    private void processLine(String currentLine, int line) {
        char[] chars = currentLine.toCharArray();
        int p = 0;
        StringBuilder wordAph = new StringBuilder();
        StringBuilder wordDig = new StringBuilder();
        boolean inName = false;

        while (p < chars.length) {
            char currentChar = chars[p];

            if (!inComment) {
                // 判断字符并处理
                handleNonCommentChar(currentChar, chars, p, wordAph, wordDig, inName, line);
            } else {
                // 如果在注释内处理注释字符
                handleCommentChar(currentChar, chars, p);
            }
            p++;
        }

        // 处理最后一个单词
        processWord(wordAph, wordDig, line);
    }

    // 处理非注释字符
    private void handleNonCommentChar(char currentChar, char[] chars, int p, StringBuilder wordAph,
                                      StringBuilder wordDig, boolean inName, int line) {
        StringBuilder stringConst = new StringBuilder();
        StringBuilder charConst = new StringBuilder();

        if (currentChar == '&') {
            processWord(wordAph, wordDig, line);
            if (p + 1 < chars.length && chars[p + 1] == '&') {
                outputBuilder.append("AND &&\n");
            } else {
                errSym = false;
                this.errLine = line;
                this.errCode = 'a';
            }
        } else if (currentChar == '|') {
            processWord(wordAph, wordDig, line);
            if (p + 1 < chars.length && chars[p + 1] == '|') {
                outputBuilder.append("OR ||\n");
            } else {
                errSym = false;
                this.errLine = line;
                this.errCode = 'a';
            }
        } else if (currentChar == '"') {
            p++;
            processWord(wordAph, wordDig, line);
            while (p < chars.length) {
                if (chars[p] == '"' && chars[p - 1] != '\\') {
                    outputBuilder.append("STRCON \"").append(stringConst).append("\"\n");
                    break;
                }
                stringConst.append(chars[p++]);
            }
        } else if (currentChar == '\'') {
            p++;
            processWord(wordAph, wordDig, line);
            while (p < chars.length && chars[p] != '\'') {
                charConst.append(chars[p++]);
            }
            if (p + 1 < chars.length && chars[p] == '\'') {
                if (chars[p - 1] != '\\') {
                    outputBuilder.append("CHRCON '").append(charConst).append("'\n");
                } else {
                    charConst.append(chars[p]);
                    outputBuilder.append("CHRCON '").append(charConst).append("'\n");
                }
            }
        } else if (currentChar == '/') {
            processWord(wordAph, wordDig, line);
            if (p + 1 < chars.length && chars[p + 1] == '/') {
                while (p < chars.length && chars[p] != '\n') {
                    p++;
                }
            } else if (p + 1 < chars.length && chars[p + 1] == '*') {
                inComment = true;
                if (p + 2 < chars.length) {
                    while (p < chars.length - 1) {
                        if (chars[p] == '*' && chars[p + 1] == '/') {
                            inComment = false;
                            break;
                        }
                        p++;
                    }
                }
            } else if (p + 2 >= chars.length) {
                inComment = true;
            } else {
                outputBuilder.append("DIV /\n");
            }
        } else if (currentChar == '>') {
            processWord(wordAph, wordDig, line);
            if (p + 1 < chars.length && chars[p + 1] == '=') {
                outputBuilder.append("GEQ >=\n");
            } else {
                outputBuilder.append("GRE >\n");
            }
        } else if (currentChar == '<') {
            processWord(wordAph, wordDig, line);
            if (p + 1 < chars.length && chars[p + 1] == '=') {
                outputBuilder.append("LEQ <=\n");
            } else {
                outputBuilder.append("LSS <\n");
            }
        } else if (currentChar == '=') {
            processWord(wordAph, wordDig, line);
            if (p + 1 < chars.length && chars[p + 1] == '=') {
                outputBuilder.append("EQL ==\n");
            } else {
                outputBuilder.append("ASSIGN =\n");
            }
        } else if (currentChar == '!') {
            processWord(wordAph, wordDig, line);
            if (p + 1 < chars.length && chars[p + 1] == '=') {
                outputBuilder.append("NEQ !=\n");
            } else {
                outputBuilder.append("NOT !\n");
            }
        } else if (Character.isLetter(currentChar)) {
            wordAph.append(currentChar);
        } else if (currentChar == '_') {
            wordAph.append(currentChar);
        } else if (Character.isDigit(currentChar)) {
            if (!inName) {
                wordDig.append(currentChar);
            } else {
                wordAph.append(currentChar);
            }
        } else {
            processWord(wordAph, wordDig, line);
            processSymbol(currentChar);
        }
    }

    // 处理注释字符
    private void handleCommentChar(char currentChar, char[] chars, int p) {
        if (currentChar == '*' && p + 1 < chars.length && chars[p + 1] == '/') {
            inComment = false;
        }
    }

    // 处理单词
    private void processWord(StringBuilder wordAph, StringBuilder wordDig, int line) {
        if (wordAph.length() > 0) {
            String word = wordAph.toString();
            int flag = 0;
            for (int i = 0; i < KEYWORDS.length; i++) {
                if (word.equals(KEYWORDS[i])) {
                    Token token = new Token(KEY_NAMES[i], word, line);
                    outputBuilder.append(token).append("\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                Token token = new Token("IDENFR", word, line);
                outputBuilder.append(token).append("\n");
            }
            wordAph.setLength(0); // 清空
        } else if (wordDig.length() > 0) {
            outputBuilder.append("INTCON ").append(wordDig).append("\n");
            wordDig.setLength(0); // 清空
        }
    }

    // 处理符号
    private void processSymbol(char currentChar) {
        switch (currentChar) {
            case ' ':
            case '\t':
            case '\r':
                break; // 无效符号不做处理
            case '+':
                outputBuilder.append("PLUS +\n");
                break;
            case '-':
                outputBuilder.append("MINU -\n");
                break;
            case '*':
                outputBuilder.append("MULT *\n");
                break;
            case '%':
                outputBuilder.append("MOD %\n");
                break;
            case ';':
                outputBuilder.append("SEMICN ;\n");
                break;
            case ',':
                outputBuilder.append("COMMA ,\n");
                break;
            case '(':
                outputBuilder.append("LPARENT (\n");
                break;
            case ')':
                outputBuilder.append("RPARENT )\n");
                break;
            case '[':
                outputBuilder.append("LBRACK [\n");
                break;
            case ']':
                outputBuilder.append("RBRACK ]\n");
                break;
            case '{':
                outputBuilder.append("LBRACE {\n");
                break;
            case '}':
                outputBuilder.append("RBRACE }\n");
                break;
            default:
                break;
        }
    }

    public void writeOutputToFile(String filePath) {
        try (FileWriter writer = new FileWriter(filePath)) {
            writer.write(outputBuilder.toString()); // 将结果写入文件
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
