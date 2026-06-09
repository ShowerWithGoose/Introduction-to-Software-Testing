package frontend.lexer;

import frontend.check.ErrorMap;
import frontend.check.ErrorType;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lexer {
    private String input;
    private List<Token> tokens;
    private int currentLineNum;
    private boolean insideSingleQuote;
    private boolean insideDoubleQuote;
    private ErrorMap errorMap;
    public Lexer(InputStream inputStream, ErrorMap errorMap) throws IOException {
        byte[] inputBytes = inputStream.readAllBytes();
        this.input = new String(inputBytes, StandardCharsets.UTF_8);
        this.tokens = new ArrayList<>();
        this.currentLineNum = 1;
        this.insideSingleQuote = false;
        this.insideDoubleQuote = false;
        this.errorMap = errorMap;
    }

    public List<Token> tokenize() {
        String remainingInput = this.input;

        while (!remainingInput.isEmpty()) {

            while (!remainingInput.isEmpty() && (isIgnoredWhitespace(remainingInput.charAt(0)))) {
                remainingInput = remainingInput.substring(1);
            }

            if (remainingInput.startsWith("//")) {
                int endOfLine = remainingInput.indexOf('\n');
                if (endOfLine == -1) {
                    break;
                }
                currentLineNum++;
                remainingInput = remainingInput.substring(endOfLine + 1);
                continue;
            }

//            if (remainingInput.startsWith("/*")) {
//                int endOfComment = remainingInput.indexOf("*/");
//                if (endOfComment == -1) {
//                    break;
//                }
//                currentLineNum += remainingInput.substring(2, endOfComment).split("\n").length;
//                remainingInput = remainingInput.substring(endOfComment + 2);
//                continue;
//            }
            //这个位置，对于输入（/*/////*//1/*/*//1;）就会出问题，原因是符号（/*）和（*/）在匹配时用了同一个*

            if (remainingInput.startsWith("/*")) {
                Pattern pattern = Pattern.compile("/\\*.*?\\*/", Pattern.DOTALL);
                Matcher matcher = pattern.matcher(remainingInput);

                if (matcher.find()) {
                    String comment = matcher.group();
                    currentLineNum += comment.split("\n").length - 1; // 减去 1，因为注释本身是一行
                    remainingInput = remainingInput.substring(matcher.end()); // 更新 remainingInput
                    continue;
                } else {
                    break;
                }
            }

            if (remainingInput.startsWith("\n")) {
                currentLineNum++;
                remainingInput = remainingInput.substring(1);
                continue;
            }


            while (!remainingInput.isEmpty() && (isIgnoredWhitespace(remainingInput.charAt(0)))) {
                remainingInput = remainingInput.substring(1);
            }

            if (remainingInput.isEmpty()) {
                break;
            }

            boolean matched = false;

            if (remainingInput.startsWith("&&")) {
                tokens.add(new Token(TokenType.AND, currentLineNum, "&&"));
                remainingInput = remainingInput.substring(2);
                matched = true;
            } else if (remainingInput.startsWith("||")) {
                tokens.add(new Token(TokenType.OR, currentLineNum, "||"));
                remainingInput = remainingInput.substring(2);
                matched = true;
            } else if (remainingInput.startsWith("&")) {
                tokens.add(new Token(TokenType.AND, currentLineNum, "&&"));
                remainingInput = remainingInput.substring(1);
                errorMap.addError(currentLineNum, ErrorType.ILLEGAL_SYMBOL);
                matched = true;
            } else if (remainingInput.startsWith("|")) {
                tokens.add(new Token(TokenType.OR, currentLineNum, "||"));
                remainingInput = remainingInput.substring(1);
                errorMap.addError(currentLineNum, ErrorType.ILLEGAL_SYMBOL);
                matched = true;
            }

            if (!matched) {
                for (TokenType tokenType : TokenType.values()) {
                    Matcher matcher = tokenType.getPattern().matcher(remainingInput);
                    if (matcher.find()) {
                        String value = matcher.group();

                        updateInsideQuote(value);

                        if (!insideSingleQuote && !insideDoubleQuote && value.contains("\n")) {
                            currentLineNum += countNewlines(value);
                        }
                        Token token = new Token(tokenType, currentLineNum, value);
                        tokens.add(token);
                        remainingInput = matcher.replaceFirst("");
                        matched = true;
                        break;
                    }
                }
            }

            while (!remainingInput.isEmpty() && (isIgnoredWhitespace(remainingInput.charAt(0)))) {
                remainingInput = remainingInput.substring(1);
            }

            if (!matched) {
                System.out.println("Invalid input:" + remainingInput);
                System.out.println("Line number:" + currentLineNum);
            }

            if (!matched) {
                System.out.println("Error!!");
                break;
            }
            
        }
        return tokens;
    }

    private void updateInsideQuote(String value) {
        for (char c : value.toCharArray()) {
            if (c == '\'' && !insideDoubleQuote) {
                insideSingleQuote = !insideSingleQuote;
            } else if (c == '"' && !insideSingleQuote) {
                insideDoubleQuote = !insideDoubleQuote;
            }
        }
    }

    private int countNewlines(String value) {
        int count = 0;
        for (char c : value.toCharArray()) {
            if (c == '\n') {
                count++;
            }
        }
        return count;
    }

    public List<Token> getTokens() {
        return this.tokens;
    }

    public void printTokens(OutputStream outputStream) {
        for (Token token : tokens) {
            try {
                String tokenOutput = String.format("%s %s%n",
                        token.getType(), token.getContent());
                outputStream.write(tokenOutput.getBytes(StandardCharsets.UTF_8));
            } catch (IOException e) {
                System.err.println("Error!!");
            }
        }
    }
    
    private boolean isIgnoredWhitespace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\r' || (Character.isWhitespace(ch) && ch != '\n');
    }
    
}
