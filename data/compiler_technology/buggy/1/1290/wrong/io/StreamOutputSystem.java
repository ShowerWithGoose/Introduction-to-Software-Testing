package io;

import error.CompilerError;
import lexical.Token;

import java.io.OutputStream;
import java.io.PrintStream;

/**
 * 默认流输出
 */
public class StreamOutputSystem implements OutputSystem {

    private OutputStream outputStream;

    private PrintStream printStream;

    public StreamOutputSystem() {
        this.outputStream = System.out;
        this.printStream = new PrintStream(outputStream);
    }

    public StreamOutputSystem(OutputStream outputStream) {
        this.outputStream = outputStream;
        this.printStream = new PrintStream(outputStream);
    }

    public void changeOutputStream(OutputStream outputStream) {
        this.outputStream = outputStream;
        this.printStream = new PrintStream(outputStream);
    }

    /**
     * 基本打印函数
     *
     * @param s 打印字符串
     */
    @Override
    public void print(String s) {
        printStream.print(s);
    }

    /**
     * 基本换行打印函数
     *
     * @param s 打印字符串
     */
    @Override
    public void println(String s) {
        printStream.println(s);
    }

    /**
     * 换行
     */
    @Override
    public void println() {
        printStream.println();
    }

    /**
     * 错误打印函数
     *
     * @param error 编译错误
     */
    @Override
    public void error(CompilerError error) {
        printStream.println(error.getLine() + " " + error.getMessage());
    }

    /**
     * Token打印函数
     *
     * @param token Token
     */
    @Override
    public void Token(Token token) {
        printStream.println(token.getType().toString() + " " + token.getValue());
    }
}
