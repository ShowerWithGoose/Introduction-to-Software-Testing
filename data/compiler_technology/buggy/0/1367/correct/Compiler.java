import javax.swing.plaf.IconUIResource;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        BufferedReader reader;
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<ErrorToken> errors = new ArrayList<>();
        String[] array = {"int", "main", "const", "char", "break", "continue", "if", "else",
                "for", "getint", "getchar", "printf", "return", "void"};

        try {
            reader = new BufferedReader(new FileReader("testfile.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        String line;
        int flag =0;
        int lineNum = 0;
        while (true) {
            lineNum++;
            try {
                if ((line = reader.readLine()) == null) break;
                else if (line.contains("*/")) {
                    flag = 0;
                    continue;
                }
                else if (line.contains("/*")) {
                    flag = 1;
                    continue;
                }
                if (flag == 1) {
                    continue;
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            getSym(lineNum, line, tokens, errors);
            try {
                FileWriter fileWriter1 = new FileWriter("lexer.txt");
                FileWriter fileWriter2 = new FileWriter("error.txt");
                BufferedWriter bufferedWriter1 = new BufferedWriter(fileWriter1);
                BufferedWriter bufferedWriter2 = new BufferedWriter(fileWriter2);
                for (Token token : tokens) {
                    bufferedWriter1.write(token.getType() + " " + token.getName() + "\n");
                }
                bufferedWriter1.flush();
                bufferedWriter1.close();
                for (ErrorToken errorToken : errors) {
                    bufferedWriter2.write(errorToken.getLine() + " " + errorToken.getType());
                }
                bufferedWriter2.flush();
                bufferedWriter2.close();

            } catch (IOException e) {
                throw new RuntimeException(e);
            }

        }
    }

    private static void getSym(int lineNum, String line, ArrayList<Token> tokens,
                               ArrayList<ErrorToken> errors) {
        String[] array1 = {"int", "main", "const", "char", "break", "continue", "if", "else",
                "for", "getint", "getchar", "printf", "return", "void"};
        Character[] array2 = {'+', '-', '*', '/', '%', ';', ',', '(', ')', '{', '}', '[', ']'};
        for (int i = 0; i < line.length(); ) {
            while (line.charAt(i) == ' ' || line.charAt(i) == '\t' || line.charAt(i) == '\n') {
                i++;
                if (i == line.length()) {
                    break;
                }
            }
            if (i >= line.length()) {
                break;
            }
            if (line.charAt(i) == '/') {
                i++;
                if (line.charAt(i) == '/') {
                    break;
                }  else {
                    Token token = new Token("DIV", "/");
                    tokens.add(token);
                }
            } else if (Character.isLetter(line.charAt(i)) || line.charAt(i) == '_') {
                String str = "";
                str += line.charAt(i);
                i++;
                while (Character.isLetter(line.charAt(i)) || Character.isDigit(line.charAt(i)) || line.charAt(i) == '_') {
                    str += line.charAt(i);
                    i++;
                    if (i == line.length()) {
                        break;
                    }
                }
                //i--;
                if (Arrays.asList(array1).contains(str)) {
                    Token token = new Token(str.toUpperCase() + "TK", str);
                    tokens.add(token);
                } else {
                    Token token = new Token("IDENFR", str);
                    tokens.add(token);
                }

            } else if (Character.isDigit(line.charAt(i))) {
                String str = "";
                str += line.charAt(i);
                i++;
                while (Character.isDigit(line.charAt(i))) {
                    str += line.charAt(i);
                    i++;
                }
                Token token = new Token("INTCON", str);
                tokens.add(token);
            } else if (Arrays.asList(array2).contains(line.charAt(i))) {
                if (line.charAt(i) == '+') {
                    Token token = new Token("PLUS", "+");
                    tokens.add(token);
                } else if (line.charAt(i) == '-') {
                    Token token = new Token("MINU", "-");
                    tokens.add(token);
                } else if (line.charAt(i) == '*') {
                    Token token = new Token("MULT", "*");
                    tokens.add(token);
                } else if (line.charAt(i) == '/') {
                    Token token = new Token("DIV", "/");
                    tokens.add(token);
                } else if (line.charAt(i) == '%') {
                    Token token = new Token("MOD", "%");
                    tokens.add(token);
                } else if (line.charAt(i) == ';') {
                    Token token = new Token("SEMICN", ";");
                    tokens.add(token);
                } else if (line.charAt(i) == ',') {
                    Token token = new Token("COMMA", ",");
                    tokens.add(token);
                } else if (line.charAt(i) == '(') {
                    Token token = new Token("LPARENT", "(");
                    tokens.add(token);
                } else if (line.charAt(i) == ')') {
                    Token token = new Token("RPARENT", ")");
                    tokens.add(token);
                } else if (line.charAt(i) == '[') {
                    Token token = new Token("LBRACK", "[");
                    tokens.add(token);
                } else if (line.charAt(i) == ']') {
                    Token token = new Token("RBRACK", "]");
                    tokens.add(token);
                } else if (line.charAt(i) == '{') {
                    Token token = new Token("LBRACE", "{");
                    tokens.add(token);
                } else if (line.charAt(i) == '}') {
                    Token token = new Token("RBRACE", "}");
                    tokens.add(token);
                }
                i++;
            } else if (line.charAt(i) == '!') {
                i++;
                if (line.charAt(i) == '=') {
                    i++;
                    Token token = new Token("NEQ", "!=");
                    tokens.add(token);
                } else {
                    Token token = new Token("NOT", "!");
                    tokens.add(token);
                }
            } else if (line.charAt(i) == '<') {
                i++;
                if (line.charAt(i) == '=') {
                    i++;
                    Token token = new Token("LEQ", "<=");
                    tokens.add(token);
                } else {
                    Token token = new Token("LSS", "<");
                    tokens.add(token);
                }
            } else if (line.charAt(i) == '>') {
                i++;
                if (line.charAt(i) == '=') {
                    i++;
                    Token token = new Token("GEQ", ">=");
                    tokens.add(token);
                } else {
                    Token token = new Token("GRE", ">");
                    tokens.add(token);
                }
            } else if (line.charAt(i) == '=') {
                i++;
                if (line.charAt(i) == '=') {
                    i++;
                    Token token = new Token("EQL", "==");
                    tokens.add(token);
                } else {
                    Token token = new Token("ASSIGN", "=");
                    tokens.add(token);
                }
            } else if (line.charAt(i) == '"') {
                String str = "";
                str += line.charAt(i);
                i++;
                while (line.charAt(i) != '"') {
                    str += line.charAt(i);
                    i++;
                }
                str += line.charAt(i);
                i++;
                Token token = new Token("STRCON", str);
                tokens.add(token);
            } else if (line.charAt(i) == '\'') {
                String str = "";
                str += line.charAt(i);
                i++;
                while (line.charAt(i) != '\'') {
                    str += line.charAt(i);
                    i++;
                    if (i == line.length()) {
                        break;
                    }
                }
                if (i == line.length()) {
                    break;
                }
                str += line.charAt(i);
                i++;
                Token token = new Token("CHRCON", str);
                tokens.add(token);
            } else if (line.charAt(i) == '&' || line.charAt(i) == '|') {
                char ch = line.charAt(i);
                i++;
                if (line.charAt(i) == ch) {
                    Token token;
                    if (ch == '&') {
                        token = new Token("AND", "&&");
                    } else {
                        token = new Token("OR", "||");
                    }
                    tokens.add(token);
                    i++;
                } else {
                    ErrorToken errorToken = new ErrorToken(lineNum, "a");
                    errors.add(errorToken);
                }
            }
        }
    }

}
