package io;

import error.CompilerError;
import lexical.Token;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;

public class FileOutputSystem implements OutputSystem {

    private PrintStream printStream;

    public FileOutputSystem(File file) {
        try {
            this.printStream = new PrintStream(new FileOutputStream(file));
        } catch (FileNotFoundException e) {
            printStream = System.err;
            printStream.println("File not found: " + file.getAbsolutePath());
        }
    }

    @Override
    protected void finalize() throws Throwable {
        if (printStream != System.err) {
            printStream.close();
        }
        super.finalize();
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
