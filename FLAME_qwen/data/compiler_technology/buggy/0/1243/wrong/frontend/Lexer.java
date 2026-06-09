package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lexer {
    private SourceFile source;
    private final String lineComment = "//";
    private final String blockCommentStart = "/*";
    private final String blockCommentEnd = "*/";

    public Lexer(SourceFile source) {
        this.source = source;
    }

    public boolean isEndOfInput() {
        return source.isEndOfInput();
    }

    public void skipWhiteSpace() {
        while (!isEndOfInput() && Character.isWhitespace(source.readCurrentChar())) {
            source.skipNextchar();
        }
    }

    public boolean skipComment() {
        if (lineComment.equals(source.readSubStr(2))) {
            while (!isEndOfInput() && source.readCurrentChar() != '\n') {
                source.skipNextchar();
            }
            source.skipNextchar(); // 跳过换行符
            return true;
        } else if (blockCommentStart.equals(source.readSubStr(2))) {
            source.skipNextSubStr(2);
            while (!isEndOfInput() && !blockCommentEnd.equals(source.readSubStr(2))) {
                source.skipNextchar();
            }
            if (blockCommentEnd.equals(source.readSubStr(2))) {
                source.skipNextSubStr(2);
                return true;
            }
        }
        return false;
    }

    public Token nextToken() {
        skipWhiteSpace();
        while (skipComment()) {
            skipWhiteSpace();
        }
        if (isEndOfInput()) {
            return null;
        }
        String currentWord = source.readCurrentWord();
        int currentLine = source.getLineNum();
        for (TokenType tokentype : TokenType.values()) {
            Pattern pattern = tokentype.getPattern();
            Matcher matcher = pattern.matcher(currentWord);

            if (matcher.find() && matcher.start() == 0) {
                String value = matcher.group(); // 会不会出现value和Word实际长度不一样的情况？
                return new Token(tokentype, value, currentLine);
            }
        }
        return null;
    }

    public void TokenLize(String outputFile, String errorFile) {
        StringBuilder sb_output = new StringBuilder();
        StringBuilder sb_error = new StringBuilder();
        while(!isEndOfInput()) {
            Token token = nextToken();
            // 错误处理
            if (token.getType().isError()) {
                sb_error.append(token.getLine()).append(" a").append("\n");
            }
            sb_output.append(token.toString()).append("\n");
        }
        try {
            // 写入文件
            FileWriter writer = new FileWriter(outputFile);
            writer.write(sb_output.toString());
            writer.close();
            writer = new FileWriter(errorFile);
            writer.write(sb_error.toString());
            writer.close();
        } catch (IOException e) {
            System.err.println("Can't write to" + outputFile + " or " + errorFile);
        }
        return;
    }
}
