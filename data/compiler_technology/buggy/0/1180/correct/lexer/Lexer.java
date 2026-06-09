package lexer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import token.Token;

public class Lexer {
    public static int arraySize = 100;
    public static int line = 0; // 所在行号
    public char err_code; // 错误代码
    public int err_line = 0; // 错误行号
    public boolean err_sym = true; // 错误符号
    public boolean inComment = false; // 是否在注释中

    public static String[] keyWords = {"main", "const", "int", "char", "break", "continue", "if", "else",
            "for", "getint", "getchar", "printf", "return", "void"};
    public static String[] keyNames = {"MAINTK", "CONSTTK", "INTTK", "CHARTK", "BREAKTK", "CONTINUETK", "IFTK",
            "ELSETK", "FORTK", "GETINTTK", "GETCHARTK", "PRINTFTK", "RETURNTK", "VOIDTK"};

    private StringBuilder outputBuilder = new StringBuilder(); // 用于存储输出内容

    public void run(String[] args) {
        //try (BufferedReader reader = new BufferedReader(new FileReader("C:/Users/sjn/Desktop/testfile1.txt"))) {
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

    private void processLine(String currentline, int line) {
        char[] chars = currentline.toCharArray();
        int p = 0;
        StringBuilder wordAph = new StringBuilder();
        StringBuilder wordDig = new StringBuilder();
        String stringConst = "";
        String charConst = "";
        int inString = 0;
        int inChar = 0;
        boolean inName = false;


        while (p < chars.length) {
            char currentChar = chars[p];

            if (!inComment) {
                // 检测到&
                if (currentChar == '&') {
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    if (p + 1 < chars.length && chars[p + 1] == '&') {
                        outputBuilder.append("AND &&\n");
                        p++;
                    } else {
                        err_sym = false;
                        this.err_line = line;
                        this.err_code = 'a';
                    }
                }
                // 检测到|
                else if (currentChar == '|') {
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    if (p + 1 < chars.length && chars[p + 1] == '|') {
                        outputBuilder.append("OR ||\n");
                        p++;
                    } else {
                        err_sym = false;
                        this.err_line = line;
                        this.err_code = 'a';
                    }
                }
                // 检测到双引号
              else if (currentChar == '"') {
                    inString = 1;
                    p++;
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    while (p < chars.length) {
                        if (chars[p] == '"' && chars[p - 1] != '\\') {
                            outputBuilder.append("STRCON \"").append(stringConst).append("\"\n");
                            stringConst = "";
                            inString = 0;
                            break;
                        }
                        stringConst += chars[p++];
                    }

                }
                // 检测到单引号
                else if (currentChar == '\'') {
                    inChar = 1;
                    p++;
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    while (p < chars.length && chars[p] != '\'' ) {
                        charConst += chars[p++];
                    }
                    if (p + 1< chars.length && chars[p] == '\'') {
                        if (chars[p - 1] != '\\') {
                            outputBuilder.append("CHRCON '").append(charConst).append("'\n");
                            charConst = "";
                            inChar = 0;
                        }
                        else {
                            charConst += chars[p++];
                            outputBuilder.append("CHRCON '").append(charConst).append("'\n");
                            charConst = "";
                            inChar = 0;
                        }
                    }
                }
                // 检测到注释
                else if (currentChar == '/') {
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    if (p + 1 < chars.length && chars[p + 1] == '/') {
                        while (p < chars.length && chars[p] != '\n') {
                            p++;
                        }
                        return;
                    } else if (p + 1 < chars.length && chars[p + 1] == '*') {
                        inComment = true;
                        if (p + 2 < chars.length) {
                            while (p < chars.length -1) {
                                if (chars[p] == '*' && chars[p + 1] == '/') {
                                    inComment = false;
                                    p += 2;
                                    break;
                                }
                                p++;
                            }
                            return;
                        }
                    } else if (p + 2 >= chars.length) {
                        inComment = true;
                        return;
                    } else {
                        outputBuilder.append("DIV /\n");
                    }
                }
                // 检测到>
                else if (currentChar == '>') {
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    if (p + 1 < chars.length && chars[p + 1] == '=') {
                        outputBuilder.append("GEQ >=\n");
                        p++;
                    } else {
                        outputBuilder.append("GRE >\n");
                    }
                }
                // 检测到<
                else if (currentChar == '<') {
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    if (p + 1 < chars.length && chars[p + 1] == '=') {
                        outputBuilder.append("LEQ <=\n");
                        p++;
                    } else {
                        outputBuilder.append("LSS <\n");
                    }
                }
                // 检测到=
                else if (currentChar == '=') {
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    if (p + 1 < chars.length && chars[p + 1] == '=') {
                        outputBuilder.append("EQL ==\n");
                        p++;
                    } else {
                        outputBuilder.append("ASSIGN =\n");
                    }
                }
                // 检测到!
                else if (currentChar == '!') {
                    inName = false;
                    processWord(wordAph, wordDig, inName);
                    if (p + 1 < chars.length && chars[p + 1] == '=') {
                        outputBuilder.append("NEQ !=\n");
                        p++;
                    } else {
                        outputBuilder.append("NOT !\n");
                    }
                }
                // 检测到字母
                else if (Character.isLetter(currentChar)) {
                    wordAph.append(currentChar);
                    inName = true;
                }
                //检测到下划线
                else if (currentChar == '_') {
                        wordAph.append(currentChar);
                        inName = true;
                }

                // 检测到数字
                else if (Character.isDigit(currentChar)) {
                    if (!inName) {
                        wordDig.append(currentChar);
                    } else {
                        wordAph.append(currentChar);
                    }
                }
                // 检测到单个分隔符，判断当前单词是否为关键字/数字
                else {
                    processWord(wordAph, wordDig, inName);
                    processSymbol(currentChar);
                    inName = false;
                }
                p++;

            } else {
                if (currentChar == '*' && p + 1 < chars.length && chars[p + 1] == '/') {
                    inComment = false;
                    p++;
                }
                p++;
            }
        }
        // 处理最后一个单词
        processWord(wordAph, wordDig, inName);
    }

    private void processWord(StringBuilder wordAph, StringBuilder wordDig, boolean inName) {
        if (wordAph.length() > 0) {
            String word = wordAph.toString();
            int flag = 0;
            for (int i = 0; i < keyWords.length; i++) {
                if (word.equals(keyWords[i])) {
                    outputBuilder.append(keyNames[i]).append(" ").append(word).append("\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                outputBuilder.append("IDENFR ").append(word).append("\n");
            }
            wordAph.setLength(0); // 清空
        } else if (wordDig.length() > 0) {
            outputBuilder.append("INTCON ").append(wordDig).append("\n");
            wordDig.setLength(0); // 清空
        }
    }

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
