package Reader;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class LexicalAnalyzer {
    private String strings;
    private ArrayList<Token> tokens = new ArrayList<>();

    public LexicalAnalyzer() {
        this.strings = getInput();
        getTokens();
    }

    public String getInput() {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line);
                sb.append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return sb.toString();
    }


    public void getTokens() {
        int num = 1;
        String s = strings;
        for (int i = 0; i < s.length(); ) {
            // System.out.println(s.charAt(i));
            if (s.charAt(i) == ' ' || s.charAt(i) == '\t') {
                i++;
            }
            if (s.charAt(i) == '\n') {
                num++;
                i++;
                continue;
            }
            if (s.startsWith("/*", i)) {
                i += 2;
                while (i < s.length() && !s.startsWith("*/", i)) {
                    if (s.charAt(i) == '\n') {
                        num++;
                    }
                    i++;
                }
                i = i + 2;
                continue;
            }

            if (s.startsWith("//", i)) {
                i += 2;
                while (i < s.length() && s.charAt(i) != '\n') {
                    i++;
                }
            } else if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                int j = getAnInt(s, i);
                tokens.add(new Token(s.substring(i, j), Token.TokenType.INTCON, num));
                i = j;
            } else if (s.startsWith("main", i) && (i + 4 >= s.length() || !isLetter(s.charAt(i + 4)))) {
                tokens.add(new Token("main", Token.TokenType.MAINTK, num));
                i += 4;
            } else if (s.startsWith("const", i) && (i + 5 >= s.length() || !isLetter(s.charAt(i + 5)))) {
                tokens.add(new Token("const", Token.TokenType.CONSTTK, num));
                i += 5;
            } else if (s.startsWith("int", i) && (i + 3 >= s.length() || !isLetter(s.charAt(i + 3)))) {
                tokens.add(new Token("int", Token.TokenType.INTTK, num));
                i += 3;
            } else if (s.startsWith("char", i) && (i + 4 >= s.length() || !isLetter(s.charAt(i + 4)))) {
                tokens.add(new Token("char", Token.TokenType.CHARTK, num));
                i += 4;
            } else if (s.startsWith("break", i) && (i + 5 >= s.length() || !isLetter(s.charAt(i + 5))))// break
            {
                tokens.add(new Token("break", Token.TokenType.BREAKTK, num));
                i += 5;
            } else if (s.startsWith("continue", i) && (i + 8 >= s.length() || !isLetter(s.charAt(i + 8)))) {
                tokens.add(new Token("continue", Token.TokenType.CONTINUETK, num));
                i += 8;
            } else if (s.startsWith("if", i) && (i + 2 >= s.length() || !isLetter(s.charAt(i + 2))))// if
            {
                tokens.add(new Token("if", Token.TokenType.IFTK, num));
                i += 2;
            } else if (s.startsWith("else", i) && (i + 4 >= s.length() || !isLetter(s.charAt(i + 4))))// else
            {
                tokens.add(new Token("else", Token.TokenType.ELSETK, num));
                i += 4;
            } else if (s.charAt(i) == '!' && (i + 1 >= s.length() || s.charAt(i + 1) != '=')) {
                tokens.add(new Token("!", Token.TokenType.NOT, num));
                i++;
            } else if (s.startsWith("&&", i)) {
                tokens.add(new Token("&&", Token.TokenType.AND, num));
                i += 2;
            } else if (s.startsWith("||", i)) {
                tokens.add(new Token("||", Token.TokenType.OR, num));
                i += 2;
            } else if (s.startsWith("for", i) && (i + 3 >= s.length() || !isLetter(s.charAt(i + 3)))) {
                tokens.add(new Token("for", Token.TokenType.FORTK, num));
                i += 3;
            } else if (s.startsWith("getint", i) && (i + 6 >= s.length() || !isLetter(s.charAt(i + 6)))) {
                tokens.add(new Token("getint", Token.TokenType.GETINTTK, num));
                i += 6;
            } else if (s.startsWith("getchar", i) && (i + 7 >= s.length() || !isLetter(s.charAt(i + 7)))) {
                tokens.add(new Token("getchar", Token.TokenType.GETCHARTK, num));
                i += 7;
            } else if (s.startsWith("printf", i) && (i + 6 >= s.length() || !isLetter(s.charAt(i + 6)))) {
                tokens.add(new Token("printf", Token.TokenType.PRINTFTK, num));
                i += 6;
            } else if (s.startsWith("return", i) && (i + 6 >= s.length() || !isLetter(s.charAt(i + 6)))) {
                tokens.add(new Token("return", Token.TokenType.RETURNTK, num));
                i += 6;
            } else if (s.charAt(i) == '=' && (i + 1 >= s.length() || s.charAt(i + 1) != '=')) {
                tokens.add(new Token("=", Token.TokenType.ASSIGN, num));
                i++;
            } else if (s.charAt(i) == '+') {
                tokens.add(new Token("+", Token.TokenType.PLUS, num));
                i++;
            } else if (s.charAt(i) == '-') {
                tokens.add(new Token("-", Token.TokenType.MINU, num));
                i++;
            } else if (s.startsWith("void", i) && (i + 4 >= s.length() || !isLetter(s.charAt(i + 4)))) {
                tokens.add(new Token("void", Token.TokenType.VOIDTK, num));
                i += 4;
            } else if (s.charAt(i) == '*') {
                tokens.add(new Token("*", Token.TokenType.MULT, num));
                i++;
            } else if (s.charAt(i) == '/') {
                tokens.add(new Token("/", Token.TokenType.DIV, num));
                i++;
            } else if (s.charAt(i) == '%') {
                tokens.add(new Token("%", Token.TokenType.MOD, num));
                i++;
            } else if (s.charAt(i) == '<' && (i + 1 >= s.length() || s.charAt(i + 1) != '=')) {
                tokens.add(new Token("<", Token.TokenType.LSS, num));
                i++;
            } else if (s.charAt(i) == '<' && s.charAt(i + 1) == '=') {
                tokens.add(new Token("<=", Token.TokenType.LEQ, num));
                i = i + 2;
            } else if (s.charAt(i) == '>' && (i + 1 >= s.length() || s.charAt(i + 1) != '=')) {
                tokens.add(new Token(">", Token.TokenType.GRE, num));
                i++;
            } else if (s.charAt(i) == '>' && s.charAt(i + 1) == '=') {
                tokens.add(new Token(">=", Token.TokenType.GEQ, num));
                i = i + 2;
            } else if (s.charAt(i) == '=' && s.charAt(i + 1) == '=') {
                tokens.add(new Token("==", Token.TokenType.EQL, num));
                i = i + 2;
            } else if (s.charAt(i) == '!' && s.charAt(i + 1) == '=') {
                tokens.add(new Token("!=", Token.TokenType.NEQ, num));
                i = i + 2;
            } else if (s.charAt(i) == ';') {
                tokens.add(new Token(";", Token.TokenType.SEMICN, num));
                i++;
            } else if (s.charAt(i) == ',') {
                tokens.add(new Token(",", Token.TokenType.COMMA, num));
                i++;
            } else if (s.charAt(i) == '(') {
                tokens.add(new Token("(", Token.TokenType.LPARENT, num));
                i++;
            } else if (s.charAt(i) == ')') {
                tokens.add(new Token(")", Token.TokenType.RPARENT, num));
                i++;
            } else if (s.charAt(i) == '[') {
                tokens.add(new Token("[", Token.TokenType.LBRACK, num));
                i++;
            } else if (s.charAt(i) == ']') {
                tokens.add(new Token("]", Token.TokenType.RBRACK, num));
                i++;
            } else if (s.charAt(i) == '{') {
                tokens.add(new Token("{", Token.TokenType.LBRACE, num));
                i++;
            } else if (s.charAt(i) == '}') {
                tokens.add(new Token("}", Token.TokenType.RBRACE, num));
                i++;
            } else if (s.charAt(i) == '"') {
                int j = getAString(s, i);
                tokens.add(new Token(s.substring(i, j + 1), Token.TokenType.STRCON, num));
                i = j + 1;
            } else if (s.charAt(i) == '\'') {
                if (s.charAt(i + 1) == '\\' && s.charAt(i + 3) == '\'') {
                    tokens.add(new Token(s.substring(i, i + 4), Token.TokenType.CHRCON, num));
                    i += 4;
                } else if (s.charAt(i + 2) == '\'') {
                    tokens.add(new Token(s.substring(i, i + 3), Token.TokenType.CHRCON, num));
                    i += 3;
                } else {
                    System.err.println("Invalid character constant.");
                    i++;
                }
            } else if (s.charAt(i) == '&' && s.charAt(i + 1) != '&') {
                Token tmptoken = new Token("&&", Token.TokenType.AND, num);
                tmptoken.setErr('a');
                tokens.add(tmptoken);
                i++;
            } else if (s.charAt(i) == '|' && s.charAt(i + 1) != '|') {
                Token tmptoken = new Token("||", Token.TokenType.OR, num);
                tmptoken.setErr('a');
                tokens.add(tmptoken);
                i++;
            } else {
                if (isLetter(s.charAt(i))) {
                    int j = i;
                    while (j < s.length() && isLetter(s.charAt(j))) {
                        j++;
                    }
                    // System.out.println(s.charAt(j));
                    tokens.add(new Token(s.substring(i, j), Token.TokenType.IDENFR, num));
                    i = j;
                } else {
                    // System.err.println(s.charAt(i) + " is not a valid character." + s + i);
                    i++;
                }
            }

        }
    }


    private static int getAnInt(String s, int i) {
        int j;
        j = i;
        while (j < s.length() && s.charAt(j) >= '0' && s.charAt(j) <= '9') {
            j++;
        }
        return j;
    }

    private int getAString(String s, int i) {
        int j = i + 1;
        while (j < s.length() && s.charAt(j) != '"') {
            j++;
        }
        if (j == s.length()) {
            System.err.println("String not closed.");
        }
        return j;
    }

    private boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9');
    }

    public TokenStream getWordTypes() {
        return new TokenStream(tokens);
    }
}