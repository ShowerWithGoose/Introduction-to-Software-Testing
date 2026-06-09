package pac;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Lexer {
    private String code = new String();
    private int line;
    private final Scanner in;
    private static final String[] symbol = {"", "IDENFR", "INTCON", "STRCON", "CHRCON", "MAINTK", "CONSTTK", "INTTK", "CHARTK", "BREAKTK", "CONTINUETK", "IFTK", "ELSETK", "NOT", "AND", "OR", "FORTK", "GETINTTK", "GETCHARTK", "PRINTFTK", "RETURNTK", "PLUS", "MINU", "VOIDTK", "MULT", "DIV", "MOD", "LSS", "LEQ", "GRE", "GEQ", "EQL", "NEQ", "ASSIGN", "SEMICN", "COMMA", "LPARENT", "RPARENT", "LBRACK", "RBRACK", "LBRACE", "RBRACE"};
    private final HashMap<String, Integer> wordMap = new HashMap<>();
    private final ArrayList<Pair<String, String>> lexer = new ArrayList<>();
    private final ArrayList<Pair<Integer, Character>> error = new ArrayList<>();

    public Lexer(InputStream in) {
        this.in = new Scanner(in);
        String[] words = {"main", "const", "int", "char", "break", "continue", "if", "else", "for", "getint", "getchar", "printf", "return", "void"};
        int[] num_of_words = {5, 6, 7, 8, 9, 10, 11, 12, 16, 17, 18, 19, 20, 23};
        for (int i = 0; i < 14; ++i)
            wordMap.put(words[i], num_of_words[i]);
    }

    private boolean checkChar(char c) {
        if (c == '_') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        return c >= '0' && c <= '9';
    }

    public void work() {
        int p, f;
        line = 1;
        while (code.isEmpty() && in.hasNextLine())
            code = in.nextLine();
        while (!code.isEmpty() || in.hasNextLine()) {
//            if (line == 36)
//                System.out.println(line);
            while (code.isEmpty() && in.hasNextLine()) {
                code = in.nextLine();
                line += 1;
            }
            if (code.isEmpty()) break;
            if (code.charAt(0) == '_' || (code.charAt(0) >= 'a' && code.charAt(0) <= 'z') || (code.charAt(0) >= 'A' && code.charAt(0) <= 'Z')) {
                for (p = 0; p < code.length(); ++p)
                    if (!checkChar(code.charAt(p))) break;
                String tmp = code.substring(0, p);
                if (!wordMap.containsKey(tmp))
                    wordMap.put(tmp, 1);
                int flag = wordMap.get(tmp);
                lexer.add(new Pair<>(symbol[flag], tmp));
                code = code.substring(p);
                continue;
            }
            if (code.charAt(0) >= '0' && code.charAt(0) <= '9') {
                for (p = 0; p < code.length(); ++p)
                    if (code.charAt(p) < '0' || code.charAt(p) > '9') break;
                lexer.add(new Pair<>(symbol[2], code.substring(0, p)));
                code = code.substring(p);
                continue;
            }
            if (code.charAt(0) == '\"') {
                for (p = 1, f = 0; p < code.length(); ++p)
                    if (code.charAt(p) == '\\' && f == 0) f = 1;
                    else if (code.charAt(p) == '\"' && f == 0) break;
                    else f = 0;
                ++p;
                lexer.add(new Pair<>(symbol[3], code.substring(0, p)));
                code = code.substring(p);
                continue;
            }
            if (code.charAt(0) == '\'') {
                for (p = 1, f = 0; p < code.length(); ++p)
                    if (code.charAt(p) == '\\' && f == 0) f = 1;
                    else if (code.charAt(p) == '\'' && f == 0) break;
                    else f = 0;
                ++p;
                lexer.add(new Pair<>(symbol[4], code.substring(0, p)));
                code = code.substring(p);
                continue;
            }
            int flag;
            switch (code.charAt(0)) {
                case '!':
                    if (code.charAt(1) != '=') {
                        p = 1;
                        flag = 13;
                    } else {
                        p = 2;
                        flag = 32;
                    }
                    break;
                case '&':
                    p = 1;
                    flag = 14;
                    if (code.charAt(1) == '&') p = 2;
                    else error.add(new Pair<>(line, 'a'));
                    break;
                case '|':
                    p = 1;
                    flag = 15;
                    if (code.charAt(1) == '|') p = 2;
                    else error.add(new Pair<>(line, 'a'));
                    break;
                case '+':
                    p = 1;
                    flag = 21;
                    break;
                case '-':
                    p = 1;
                    flag = 22;
                    break;
                case '*':
                    p = 1;
                    flag = 24;
                    break;
                case '/':
                    if (code.charAt(1) == '/') {
                        p = code.length();
                        flag = 0;
                    } else if (code.charAt(1) == '*') {
                        for (p = 2, f = 0; p < code.length() || in.hasNextLine(); ++p) {
                            if (p == code.length()) {
                                ++line;
                                code = code + " " + in.nextLine();
                            }
                            if (code.charAt(p) == '/' && f == 1) break;
                            else if (code.charAt(p) == '*') f = 1;
                            else f = 0;
                        }
                        ++p;
                        flag = 0;
                    } else {
                        p = 1;
                        flag = 25;
                    }
                    break;
                case '%':
                    p = 1;
                    flag = 26;
                    break;
                case '<':
                    if (code.charAt(1) != '=') {
                        p = 1;
                        flag = 27;
                    } else {
                        p = 2;
                        flag = 28;
                    }
                    break;
                case '>':
                    if (code.charAt(1) != '=') {
                        p = 1;
                        flag = 29;
                    } else {
                        p = 2;
                        flag = 30;
                    }
                    break;
                case '=':
                    if (code.charAt(1) == '=') {
                        p = 2;
                        flag = 31;
                    } else {
                        p = 1;
                        flag = 33;
                    }
                    break;
                case ';':
                    p = 1;
                    flag = 34;
                    break;
                case ',':
                    p = 1;
                    flag = 35;
                    break;
                case '(':
                    p = 1;
                    flag = 36;
                    break;
                case ')':
                    p = 1;
                    flag = 37;
                    break;
                case '[':
                    p = 1;
                    flag = 38;
                    break;
                case ']':
                    p = 1;
                    flag = 39;
                    break;
                case '{':
                    p = 1;
                    flag = 40;
                    break;
                case '}':
                    p = 1;
                    flag = 41;
                    break;
                default:
                    p = 1;
                    flag = 0;
            }
            if (flag > 0)
                lexer.add(new Pair<>(symbol[flag], code.substring(0, p)));
            code = code.substring(p);
        }
    }

    public void print(OutputStream out, OutputStream err) {
        PrintStream prt;
        if (error.isEmpty()) {
            prt = new PrintStream(out);
            for (Pair<String, String> t : lexer) {
                prt.println(t.first + " " + t.second);
            }
        } else {
            prt = new PrintStream(err);
            for (Pair<Integer, Character> t : error) {
                prt.println(t.first + " " + t.second);
            }
        }
    }
}
