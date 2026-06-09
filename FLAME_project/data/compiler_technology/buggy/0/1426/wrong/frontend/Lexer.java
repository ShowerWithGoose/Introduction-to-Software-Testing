package frontend;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;

public class Lexer {

    private String FileValue;

    private int currentIndex;

    private int currentLine;

    private ArrayList<Token> tokens;

    private final String lineComment = "//";

    private final String blockComment1 = "/*";

    private final String blockComment2 = "*/";

    public static String readFromStream(Reader reader) throws IOException {
        StringBuilder stringbuilder = new StringBuilder();
        try (BufferedReader bufferedReader = new BufferedReader(reader)) {
            String lineValue;
            while ((lineValue = bufferedReader.readLine()) != null) {
                stringbuilder.append(lineValue).append("\n");
            }
            if (stringbuilder.length() > 0 && stringbuilder.charAt(stringbuilder.length() - 1) == '\n') {
                stringbuilder.setLength(stringbuilder.length() - 1);
            }
        }
        return stringbuilder.toString();
    }
    public Lexer(String filevalue) {
        this.FileValue = filevalue;
        this.currentIndex = 0;
        this.currentLine = 1;
        this.tokens = new ArrayList<>();
        handletoken();
    }
    public Lexer(Reader reader) throws IOException {
        this(readFromStream(reader));
    }

    private boolean FileEnd() {
        return currentIndex >= FileValue.length();
    }

    private void handletoken() {
        while (!FileEnd()) {
            skipWhiteSpace();
            if (skipComment()) {
                continue;
            }
            addToken();
        }
//        for (Token token : tokens) {
//            System.out.println(token); // 调用 Token 的 toString 方法
//        }

    }

    private void skipWhiteSpace() {
        while (currentIndex < FileValue.length() && Character.isWhitespace(FileValue.charAt(currentIndex))) {
            if (FileValue.charAt(currentIndex) == '\n') {
                currentLine++;
            }
            currentIndex++;
        }
    }

    private boolean skipComment() {
        if (currentIndex + 1 < FileValue.length() && lineComment.equals(FileValue.substring(currentIndex, currentIndex + 2))) {
            currentIndex = FileValue.indexOf('\n', currentIndex);
            if (currentIndex == -1) {
                currentIndex = FileValue.length();
            } else {
                currentIndex++;
                currentLine++;
            }
            return true;
        } else if (currentIndex + 1 < FileValue.length() && blockComment1.equals(FileValue.substring(currentIndex, currentIndex + 2))) {
            currentIndex += blockComment1.length();
            while (!FileEnd() && !blockComment2.equals(FileValue.substring(currentIndex, currentIndex + 2))) {
                if (FileValue.charAt(currentIndex) == '\n') {
                    currentLine++;
                }
                currentIndex++;
            }
            if (!FileEnd() && blockComment2.equals(FileValue.substring(currentIndex, currentIndex + 2))) {
                currentIndex += blockComment2.length();
                return true;
            }
        }
        return false;
    }

    private void addToken() {
        String remainingString = FileValue.substring(currentIndex);

        // 首先检测是否为 IDENFR
        Pattern idenfrPattern = Pattern.compile("[_A-Za-z][_A-Za-z0-9]*");
        Matcher idenfrMatcher = idenfrPattern.matcher(remainingString);
        if (idenfrMatcher.lookingAt()) {
            String tokenStr = idenfrMatcher.group();
            Token token = new Token(tokenStr, TokenType.IDENFR, currentLine);
            //System.out.println(tokenStr);
            currentIndex += tokenStr.length();

            for (TokenType tokenType : TokenType.values()) {
                Pattern pattern = tokenType.getPattern();
                Matcher matcher = pattern.matcher(tokenStr);
                if (matcher.matches()) {
                    token.setType(tokenType);
                    break;
                }
            }
            this.tokens.add(token);
            return;
        }

        // 接下来检测其他符号和常量
        for (TokenType tokenType : TokenType.values()) {
            Matcher matcher = tokenType.getPattern().matcher(remainingString);
            if (matcher.lookingAt()) {
                String tokenStr = matcher.group();

                // 创建 Token 对象
                Token token = new Token(tokenStr, tokenType, currentLine);
                currentIndex += tokenStr.length();
                this.tokens.add(token);
                return; // 找到匹配后返回
            }
        }
        System.err.println("No valid token found at line " + currentLine + " at index " + currentIndex);
    }

    public ArrayList<Token> getTokens(){
        return tokens;
    }
    public String getFileValue(){
        return FileValue;
    }

    @Override
    public String toString() {
        StringBuilder stringbuilder = new StringBuilder();
        for (Token token : tokens) {
            stringbuilder.append(token + "\n");
        }
        return stringbuilder.toString();
    }

}