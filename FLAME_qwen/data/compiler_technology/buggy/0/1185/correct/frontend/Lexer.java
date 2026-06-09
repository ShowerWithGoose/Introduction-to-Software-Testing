package frontend;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lexer {
    private String input;
    private int size;
    private ArrayList<Token> words = new ArrayList<>();
    private HashMap<Integer, Wrong> wrongs = new HashMap<>();
    private ArrayList<String> lines;
    private int posWord;
    private int posLine;
    private boolean flag;

    public Lexer() {
        this.posLine = 0;
        this.posWord = 0;
        this.lines = new ArrayList<>();
        this.flag = false;
    }

    public ArrayList<String> getFile() throws IOException {
        String inputFileName = "testfile.txt";
        InputStream in = null;
        try {
            in = new FileInputStream(inputFileName);
        } catch (FileNotFoundException e) {
            System.err.println("Can not open " + inputFileName);
        }
        InputStreamReader reader = new InputStreamReader(in, StandardCharsets.UTF_8);
        BufferedReader bufferedReader = new BufferedReader(reader);
        try {
            String line;
            while (true) {
                line = bufferedReader.readLine();
                if (line == null) {
                    break;
                }
                deleteWhite(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        reader.close();
        in.close();
        return lines;
    }

    public void printLine() {
        for (String line : lines) {
            System.out.print(line);
        }
    }

    public void deleteWhite(String string) {
        String string1 = string.trim();
        lines.add(string1);
    }

    public String getLine(int n) {
        return lines.get(n);
    }

    public String getSubstring(int pos, int len, String string) {
        if (pos + len > string.length()) {
            return string.substring(pos);
        } else {
            return string.substring(pos, pos + len);
        }
    }

    public void recognize() {
        while (posLine < lines.size()) {
            posWord = 0;
            //String s = getLine(posLine);
            while (posWord < getLine(posLine).length()) {
                char c = getLine(posLine).charAt(posWord);
                if (Character.isWhitespace(c)) {
                    skipChar(1);
                    continue;
                } else if (getSubstring(posWord, 2, getLine(posLine)) != null && getSubstring(posWord, 2, getLine(posLine)).equals("//")) {
                    //posWord = s.length() - 1;
                    break;
                } else if (getSubstring(posWord, 2, getLine(posLine)) != null && getSubstring(posWord, 2, getLine(posLine)).equals("/*")) {
                    posWord += 2;
                    findBack();
                    continue;
                }
                addWords();
            }
            posLine++;
        }
    }

    public void findBack() {
        while (posLine < lines.size()) {
            while (getSubstring(posWord, 2, getLine(posLine)) != null && !getSubstring(posWord, 2, getLine(posLine)).equals("*/")) {
                skipChar(1);
            }
            if (getSubstring(posWord, 2, getLine(posLine)) != null && getSubstring(posWord, 2, getLine(posLine)).equals("*/")) {
                skipChar(2);
                break;
            }
        }
    }

    public void skipChar(int count) {
        if (count + posWord < getLine(posLine).length()) {
            posWord = posWord + count;
        } else {
            if (posLine < lines.size() - 1) {
                posWord = count - (getLine(posLine).length() - posWord);
                posLine++;
            } else if (posLine == lines.size() - 1) {
                posWord = getLine(posLine).length();
            } else {
            }
        }
    }

    public boolean isLetter() {
        return Character.isLetter(getLine(posLine).charAt(posWord)) || getLine(posLine).charAt(posWord) == '_';
    }

    //判断当前字符是否为数字
    public boolean isDigit() {
        return Character.isDigit(getLine(posLine).charAt(posWord));
    }

    public boolean isChar() {
        return getLine(posLine).charAt(posWord) == '\'';
    }

    public boolean isString() {
        return getLine(posLine).charAt(posWord) == '"';
    }

    public void addWords() {
        if (isChar()) {
            if (posWord < getLine(posLine).length() - 3 && getLine(posLine).charAt(posWord + 1) == '\\') {
                Token token = new Token("CHRCON", getSubstring(posWord, 4, getLine(posLine)), posLine);
                words.add(token);
                addPos(4);
            } else {
                Token token = new Token("CHRCON", getSubstring(posWord, 3, getLine(posLine)), posLine);
                words.add(token);
                addPos(3);
            }
        } else if (isDigit() || isLetter() || isString()) {
            String s = null;
            if (posLine < lines.size() && posWord < getLine(posLine).length()) {
                s = getLine(posLine).substring(posWord);
            }
            if (s != null) {
                for (Type type : Type.values()) {
                    Pattern pattern = (new Match(type)).getPattern();
                    Matcher matcher = pattern.matcher(s);
                    if (matcher.find()) {
                        Token token = new Token(type.toString(), matcher.group(0), posLine);
                        words.add(token);
                        int len = matcher.group(0).length();
                        while (posLine < lines.size() && len != 0) {
                            int cnt = getLine(posLine).length();
                            if (posWord + len > cnt) {
                                posLine++;
                                posWord = 0;
                                len = cnt - (getLine(posLine).length() - 1 - posWord);
                            } else {
                                posWord = posWord + len;
                                len = 0;
                            }
                        }
                        break;
                    }
                }
            }
        } else {
            int len = 0;
            char c = getLine(posLine).charAt(posWord);
            if (c == '&') {
                if (posWord < getLine(posLine).length() - 1 && getLine(posLine).charAt(posWord + 1) == '&') {
                    words.add(new Token("AND", "&&", posLine));
                    len = 2;
                } else {
                    Wrong wrong = new Wrong("WRONGAND", posLine + 1);
                    wrongs.put(posLine + 1, wrong);
                    len = 1;
                    flag = true;
                }
            } else if (c == '|') {
                if (posWord < getLine(posLine).length() - 1 && getLine(posLine).charAt(posWord + 1) == '|') {
                    words.add(new Token("OR", "||", posLine));
                    len = 2;
                } else {
                    Wrong wrong = new Wrong("WRONGOR", posLine + 1);
                    wrongs.put(posLine + 1, wrong);
                    len = 1;
                    flag = true;
                }
            } else if (c == '+') {
                words.add(new Token("PLUS", "+", posLine));
                len = 1;
            } else if (c == '-') {
                words.add(new Token("MINU", "-", posLine));
                len = 1;
            } else if (c == '*') {
                words.add(new Token("MULT", "*", posLine));
                len = 1;
            } else if (c == '/') {
                words.add(new Token("DIV", "/", posLine));
                len = 1;
            } else if (c == '%') {
                words.add(new Token("MOD", "%", posLine));
                len = 1;
            } else if (c == '<') {
                if (posWord < getLine(posLine).length() - 1 && getLine(posLine).charAt(posWord + 1) == '=') {
                    words.add(new Token("LEQ", "<=", posLine));
                    len = 2;
                } else {
                    words.add(new Token("LSS", "<", posLine));
                    len = 1;
                }
            } else if (c == '>') {
                if (posWord < getLine(posLine).length() - 1 && getLine(posLine).charAt(posWord + 1) == '=') {
                    words.add(new Token("GEQ", ">=", posLine));
                    len = 2;
                } else {
                    words.add(new Token("GRE", ">", posLine));
                    len = 1;
                }
            } else if (c == '=') {
                if (posWord < getLine(posLine).length() - 1 && getLine(posLine).charAt(posWord + 1) == '=') {
                    words.add(new Token("EQL", "==", posLine));
                    len = 2;
                } else {
                    words.add(new Token("ASSIGN", "=", posLine));
                    len = 1;
                }
            } else if (c == '!') {
                if (posWord < getLine(posLine).length() - 1 && getLine(posLine).charAt(posWord + 1) == '=') {
                    words.add(new Token("NEQ", "!=", posLine));
                    len = 2;
                } else {
                    words.add(new Token("NOT", "!", posLine));
                    len = 1;
                }
            } else if (c == ',') {
                words.add(new Token("COMMA", ",", posLine));
                len = 1;
            } else if (c == ';') {
                words.add(new Token("SEMICN", ";", posLine));
                len = 1;
            } else if (c == '(') {
                words.add(new Token("LPARENT", "(", posLine));
                len = 1;
            } else if (c == ')') {
                words.add(new Token("RPARENT", ")", posLine));
                len = 1;
            } else if (c == '[') {
                words.add(new Token("LBRACK", "[", posLine));
                len = 1;
            } else if (c == ']') {
                words.add(new Token("RBRACK", "]", posLine));
                len = 1;
            } else if (c == '{') {
                words.add(new Token("LBRACE", "{", posLine));
                len = 1;
            } else if (c == '}') {
                words.add(new Token("RBRACE", "}", posLine));
                len = 1;
            } else {
            }
            addPos(len);
        }
    }

    public void addPos(int n) {
        int len = n;
        while (posLine < lines.size() && len != 0) {
            int cnt = getLine(posLine).length();
            if (posWord + len > cnt) {
                posLine++;
                posWord = 0;
                len = cnt - (getLine(posLine).length() - 1 - posWord);
            } else {
                posWord = posWord + len;
                len = 0;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (!flag) {
            for (Token token : words) {
                sb.append(token.getType() + " " + token.getString() + "\n");
            }
        } else {
            for (int i : wrongs.keySet()) {
                sb.append(i + " a");
            }
        }
        return sb.toString();
    }

    public void printWords() {
        String outputFileName;
        if (!flag) {
            outputFileName = "lexer.txt";
            try {
                OutputStream outputStream = new FileOutputStream(outputFileName);
                PrintStream ps = new PrintStream(outputStream);
                for (int i = 0; i < words.size(); i++) {
                    ps.println(words.get(i).getType() + " " + words.get(i).getString());
                }
                int x = words.size() - 1;
                //outputStream.write((words.get(x).getType() + " " + words.get(x).getString()).getBytes());
            } catch (FileNotFoundException e) {
                System.err.println("Can not open " + outputFileName);
            }
        } else {
            outputFileName = "error.txt";
            try {
                OutputStream outputStream = new FileOutputStream(outputFileName);
                PrintStream ps = new PrintStream(outputStream);
                for (int i : wrongs.keySet()) {
                    ps.println(i + " a");
                }
            } catch (FileNotFoundException e) {
                System.err.println("Can not open " + outputFileName);
            }
        }
    }

}
