package frontend.lexer;

import frontend.SyntaxError.SyntaxErrorHandler; // 导入用于处理语法错误的类
import frontend.SyntaxError.ErrorType; // 导入错误类型的枚举类

import java.io.FileWriter; // 用于写入文件的类
import java.io.IOException; // 用于处理IO异常
import java.util.regex.Matcher; // 用于匹配正则表达式的类
import java.util.regex.Pattern; // 用于定义正则表达式的类
import java.util.ArrayList; // 用于创建动态数组的类
import java.util.List; // List接口，用于存储TokenType

// 词法分析器（Lexer）：从源文件中读取字符并识别出Token。
public class Lexer {
    private LexerState lexerState; // 用于维护Lexer的当前状态
    private List<TokenType> tokenTypes = new ArrayList<>(); // 存储所有Token类型的列表

    // 构造函数：初始化词法分析器并将源文件与LexerState绑定
    public Lexer(SourceFile sourceFile) {
        this.lexerState = new LexerState(sourceFile); // 创建一个新的Lexer状态实例
        // 初始化Token类型列表，将所有TokenType的枚举值添加到tokenTypes中
        for (TokenType tokenType : TokenType.values()) {
            tokenTypes.add(tokenType);
        }
    }

    // 跳过空白字符、换行符以及注释
    private void skipIgnoredTokens() {
        boolean shouldContinue; // 控制循环的布尔值，用于判断是否继续跳过字符
        do {
            shouldContinue = false; // 初始为false，如果发现注释或空白字符需要跳过时会设置为true
            // 跳过空白字符和换行符，直到遇到非空白字符或文件结束
            while (!lexerState.isEndOfInput() &&
                    (Character.isWhitespace(lexerState.currentChar()) || lexerState.EndOfLine())) {
                lexerState.advanceChar(); // 移动到下一个字符
            }
            // 检查是否遇到单行注释的开头符号 "//"
            if (lexerState.getSingleLineComment().equals(lexerState.peekAhead(2))) {
                skipSingleLineComment(); // 跳过单行注释
                shouldContinue = true; // 继续循环，因为可能还有其他需要跳过的字符
            }
            // 检查是否遇到多行注释的开头符号 "/*"
            else if (lexerState.getMultiLineCommentStart().equals(lexerState.peekAhead(2))) {
                skipMultiLineComment(); // 跳过多行注释
                shouldContinue = true; // 继续循环
            }
        } while (shouldContinue); // 只要有忽略的字符（空白或注释），继续循环
    }

    // 跳过单行注释
    private void skipSingleLineComment() {
        lexerState.advanceChars(2); // 跳过注释符号 "//"
        // 继续移动直到遇到换行符或文件结束
        while (!lexerState.isEndOfInput() && !lexerState.EndOfLine()) {
            lexerState.advanceChar();
        }
        lexerState.advanceChar(); // 跳过换行符，准备处理下一行
    }

    // 跳过多行注释
    private void skipMultiLineComment() {
        lexerState.advanceChars(2); // 跳过多行注释的开始符号 "/*"
        // 循环，直到遇到多行注释的结束符号 "*/" 或文件结束
        while (!lexerState.isEndOfInput() &&
                !lexerState.getMultiLineCommentEnd().equals(lexerState.peekAhead(2))) {
            lexerState.advanceChar(); // 移动到下一个字符
        }
        // 如果找到多行注释的结束符号 "*/"，则跳过它
        if (lexerState.getMultiLineCommentEnd().equals(lexerState.peekAhead(2))) {
            lexerState.advanceChars(2); // 跳过结束符号
        }
    }

    // 获取下一个Token
    public Token getNextToken() {
        skipIgnoredTokens(); // 首先跳过所有空白字符和注释
        int lineNumber = lexerState.getCurrentLine(); // 记录当前行号
        String remainingLine = lexerState.readRemainingLine(); // 获取当前行的剩余部分

        // 遍历所有可能的Token类型，尝试匹配每一个Token类型的正则表达式
        for (TokenType tokenType : tokenTypes) {
            Pattern tokenPattern = tokenType.getPattern(); // 获取Token类型的正则模式
            Matcher tokenMatcher = tokenPattern.matcher(remainingLine); // 在剩余行中查找匹配项

            // 如果匹配到Token
            if (tokenMatcher.lookingAt()) {
                String tokenValue = tokenMatcher.group(); // 获取匹配到的Token字符串
                lexerState.advanceChars(tokenValue.length()); // 移动Lexer的状态指针
                return new Token(tokenType, tokenValue, lineNumber); // 返回匹配到的Token
            }
        }
        // 如果没有匹配到任何Token类型，记录无法识别的字符
        logUnrecognizedCharacter(remainingLine);
        lexerState.advanceChar(); // 跳过无法识别的字符
        return null; // 返回null表示没有找到有效的Token
    }

    // 记录未识别的字符
    private void logUnrecognizedCharacter(String text) {
        // 如果文本不为空且长度大于0
        if (text != null && !text.isEmpty()) {
            // 将无法识别的字符写入日志文件
            try (FileWriter logWriter = new FileWriter("unrecognized_chars.log", true)) {
                logWriter.write("Line " + lexerState.getCurrentLine() +
                        ": Unrecognized character '" + text.charAt(0) + "'\n");
            } catch (IOException e) {
                e.printStackTrace(); // 捕获并打印IO异常
            }
        }
    }

    // 将Token添加到Token列表中
    public void TokenToList(TokenList tokens) {
        // 不再使用多线程处理，而是通过递归处理Token
        processTokens(tokens);
    }

    // 递归处理Token
    private void processTokens(TokenList tokens) {
        // 如果文件结束，则终止递归
        if (lexerState.isEndOfInput()) {
            return;
        }
        Token token = getNextToken(); // 获取下一个Token
        if (token != null) {
            // 如果Token类型是错误类型，则进行处理
            if (token.getType().isError()) {
                // 写入语法错误
                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.a, token.getLine());
                // 特定错误类型的修正
                switch (token.getType()) {
                    case ERROR_AND: // 处理逻辑与错误
                        token = new Token(TokenType.AND, "&&", token.getLine());
                        break;
                    case ERROR_OR: // 处理逻辑或错误
                        token = new Token(TokenType.OR, "||", token.getLine());
                        break;
                    default:
                        // 其他错误类型的处理（这里没有具体定义）
                        break;
                }
            }
            tokens.addToken(token); // 将Token添加到Token列表
            writeTokenToFile(token); // 将Token写入文件
        }
        processTokens(tokens); // 递归调用，处理下一个Token
    }

    // 将Token写入文件
    private void writeTokenToFile(Token token) {
        // 使用FileWriter将Token以特定的语法格式写入到 "lexer_output.txt" 文件中
        try (FileWriter fileWriter = new FileWriter("lexer_output.txt", true)) {
            fileWriter.write(token.toSyntaxString()); // 将Token转换为字符串并写入文件
            fileWriter.flush(); // 手动刷新输出缓冲区
        } catch (IOException e) {
            throw new RuntimeException(e); // 如果发生IO错误，抛出运行时异常
        }
    }
}

// 词法分析器的状态类，用于管理Lexer的状态和源文件的读取
class LexerState {
    private SourceFile sourceFile; // 源文件对象
    private final String singleLineComment = "//"; // 单行注释的标识符
    private final String multiLineCommentStart = "/*"; // 多行注释开始的标识符
    private final String multiLineCommentEnd = "*/"; // 多行注释结束的标识符

    // 构造函数：初始化Lexer状态与源文件关联
    public LexerState(SourceFile sourceFile) {
        this.sourceFile = sourceFile;
    }

    // 检查输入是否已经结束
    public boolean isEndOfInput() {
        return sourceFile.isEndOfInput();
    }

    // 检查当前是否是行尾
    public boolean EndOfLine() {
        return sourceFile.EndOfLine();
    }

    // 读取当前字符
    public char currentChar() {
        return sourceFile.readCurrentChar();
    }

    // 移动到下一个字符
    public void advanceChar() {
        sourceFile.advanceChar();
    }

    // 向前查看指定长度的字符串
    public String peekAhead(int length) {
        return sourceFile.readSubStr(length);
    }

    // 跳过指定数量的字符
    public void advanceChars(int length) {
        sourceFile.skipNextSubStr(length);
    }

    // 获取当前行号
    public int getCurrentLine() {
        return sourceFile.getLineNum();
    }

    // 读取当前行剩余部分
    public String readRemainingLine() {
        return sourceFile.readRemainingInput();
    }

    // 获取单行注释的标识符
    public String getSingleLineComment() {
        return singleLineComment;
    }

    // 获取多行注释开始标识符
    public String getMultiLineCommentStart() {
        return multiLineCommentStart;
    }

    // 获取多行注释结束标识符
    public String getMultiLineCommentEnd() {
        return multiLineCommentEnd;
    }
}
