import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class Lexer {
    private BufferedReader reader;
    private String[] keywords = {"int", "main", "const", "char", "break", "continue", "if", "else",
            "for", "getint", "getchar", "printf", "return", "void"};
    private Character[] operators = {'+', '-', '*', '/', '%', ';', ',', '(', ')', '{', '}', '[', ']', '<', '>', '=', '!'};
    private int flag = 0;

    private int lineNum = 0;

    public Lexer(String filePath) throws FileNotFoundException {  // 声明抛出异常
        reader = new BufferedReader(new FileReader(filePath));
    }

    public void tokenize(ArrayList<Token> tokens, ArrayList<ErrorToken> errors) {
        String line;
        try {
            while ((line = reader.readLine()) != null) {
                lineNum++;
                processLine(lineNum, line, tokens, errors);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void processLine(int lineNum, String line, ArrayList<Token> tokens, ArrayList<ErrorToken> errors) {
        for (int i = 0; i < line.length(); ) {
            i = skipWhitespace(line, i);
            if (i >= line.length()) break;

            if (flag == 1) {
                for (; i < line.length();) {
                    if (line.charAt(i) == '*') {
                        i++;
                        if (i < line.length()) {
                            if (line.charAt(i) == '/') {
                                i++;
                                flag = 0;
                            }
                        }
                        if (i >= line.length() || flag == 0) {
                            break;
                        }
                    } else {
                        i++;
                    }
                }
            }
            if (i >= line.length()) break;
            if (flag == 0) {
                char currentChar = line.charAt(i);
                if (currentChar == '/') {
                    i = handleSlash(line, i, tokens);
                } else if (Character.isLetter(currentChar) || currentChar == '_') {
                    i = handleIdentifier(line, i, tokens);
                } else if (Character.isDigit(currentChar)) {
                    i = handleNumber(line, i, tokens);
                } else if (Arrays.asList(operators).contains(currentChar)) {
                    i = handleOperator(line, i, tokens);
                } else if (currentChar == '"') {
                    i = handleString(line, i, tokens);
                } else if (currentChar == '\'') {
                    i = handleCharacter(line, i, tokens);
                } else if (currentChar == '&' || currentChar == '|') {
                    i = handleLogicalOperators(line, i, tokens, errors, lineNum);
                }
            }
        }
    }


    // 处理空白字符
    private int skipWhitespace(String line, int i) {
        while (i < line.length() && (line.charAt(i) == ' ' || line.charAt(i) == '\t' || line.charAt(i) == '\n')) {
            i++;
        }
        return i;
    }

    private int handleSlash(String line, int i, ArrayList<Token> tokens) {
        i++;
        if (line.charAt(i) == '/') {
            i = line.length() + 1; //break用
        } else if (line.charAt(i) == '*') {
            i++;
            flag = 1;
        } else {
            Token token = new Token("DIV", "/", lineNum);
            tokens.add(token);
        }
        return i;
    }

    private int handleIdentifier(String line, int i, ArrayList<Token> tokens) {
        String str = "";
        str += line.charAt(i);
        i++;
        if (i < line.length()) {
            while (Character.isLetter(line.charAt(i)) || Character.isDigit(line.charAt(i)) || line.charAt(i) == '_') {
                str += line.charAt(i);
                i++;
                if (i == line.length()) break;
            }
        }
        Token token;
        if (Arrays.asList(keywords).contains(str)) {
            token = new Token(str.toUpperCase() + "TK", str, lineNum);
        } else {
            token = new Token("IDENFR", str, lineNum);
        }
        tokens.add(token);
        return i;
    }

    private int handleNumber(String line, int i, ArrayList<Token> tokens) {
        String str = "";
        str += line.charAt(i);
        i++;
        if (i < line.length()) {
            while (Character.isDigit(line.charAt(i))) {
                str += line.charAt(i);
                i++;
                if (i >= line.length()) {
                    break;
                }
            }
        }
        Token token = new Token("INTCON", str, lineNum);
        tokens.add(token);
        return i;
    }

    private int handleOperator(String line, int i, ArrayList<Token> tokens) {
        if (line.charAt(i) == '+') {
            Token token = new Token("PLUS", "+", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '-') {
            Token token = new Token("MINU", "-", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '*') {
            Token token = new Token("MULT", "*", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '/') {
            Token token = new Token("DIV", "/", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '%') {
            Token token = new Token("MOD", "%", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == ';') {
            Token token = new Token("SEMICN", ";", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == ',') {
            Token token = new Token("COMMA", ",", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '(') {
            Token token = new Token("LPARENT", "(", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == ')') {
            Token token = new Token("RPARENT", ")", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '[') {
            Token token = new Token("LBRACK", "[", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == ']') {
            Token token = new Token("RBRACK", "]", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '{') {
            Token token = new Token("LBRACE", "{", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '}') {
            Token token = new Token("RBRACE", "}", lineNum);
            tokens.add(token);
        } else if (line.charAt(i) == '!') {
            i++;
            if (line.charAt(i) == '=') {
                i++;
                Token token = new Token("NEQ", "!=", lineNum);
                tokens.add(token);
            } else {
                Token token = new Token("NOT", "!", lineNum);
                tokens.add(token);
            }
            i--;//最后会统一加1，提前先减1
        } else if (line.charAt(i) == '<') {
            i++;
            if (line.charAt(i) == '=') {
                i++;
                Token token = new Token("LEQ", "<=", lineNum);
                tokens.add(token);
            } else {
                Token token = new Token("LSS", "<", lineNum);
                tokens.add(token);
            }
            i--;//最后会统一加1，提前先减1
        } else if (line.charAt(i) == '>') {
            i++;
            if (line.charAt(i) == '=') {
                i++;
                Token token = new Token("GEQ", ">=", lineNum);
                tokens.add(token);
            } else {
                Token token = new Token("GRE", ">", lineNum);
                tokens.add(token);
            }
            i--;//最后会统一加1，提前先减1
        } else if (line.charAt(i) == '=') {
            i++;
            if (line.charAt(i) == '=') {
                i++;
                Token token = new Token("EQL", "==", lineNum);
                tokens.add(token);
            } else {
                Token token = new Token("ASSIGN", "=", lineNum);
                tokens.add(token);
            }
            i--;//最后会统一加1，提前先减1
        }
        i++;
        return i;
    }

    private int handleString(String line, int i, ArrayList<Token> tokens) {
        String str = "";
        str += line.charAt(i);
        i++;
        if (i < line.length()) {
            while (line.charAt(i) != '"') {
                str += line.charAt(i);
                i++;
            }
        }
        str += line.charAt(i);
        i++;
        Token token = new Token("STRCON", str, lineNum);
        tokens.add(token);
        return i;
    }

    private int handleCharacter(String line, int i, ArrayList<Token> tokens) {
        String str = "";
        str += line.charAt(i);
        i++;
        if (i < line.length()) {
            while (line.charAt(i) != '\'') {
                str += line.charAt(i);
                i++;
                if (i == line.length()) {
                    break;
                }
            }
        }
        if (i < line.length()) {
            str += line.charAt(i);
            i++;
            if (i < line.length()) {
                if (line.charAt(i) == '\'') {
                    str += line.charAt(i);
                    i++;
                }
            }
            Token token = new Token("CHRCON", str, lineNum);
            tokens.add(token);
        }
        return i;
    }

    private int handleLogicalOperators(String line, int i, ArrayList<Token> tokens, ArrayList<ErrorToken> errors, int lineNum) {
        char ch = line.charAt(i);
        i++;
        if (line.charAt(i) == ch) {
            Token token;
            if (ch == '&') {
                token = new Token("AND", "&&", lineNum);
            } else {
                token = new Token("OR", "||", lineNum);
            }
            tokens.add(token);
            i++;
        } else {
            Token token;
            if (ch == '&') {
                token = new Token("AND", "&&", lineNum);
            } else {
                token = new Token("OR", "||", lineNum);
            }
            tokens.add(token);
            ErrorToken errorToken = new ErrorToken(lineNum, "a");
            errors.add(errorToken);
        }
        return i;
    }
    // 其他处理方法如：handleSlash, handleIdentifier, handleNumber, handleOperator...
}


