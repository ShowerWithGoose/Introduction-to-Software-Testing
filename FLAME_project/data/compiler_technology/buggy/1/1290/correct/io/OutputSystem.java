package io;

import error.CompilerError;
import lexical.Token;

public interface OutputSystem {

    /**
     * 基本打印函数
     * @param s 打印字符串
     */
    public void print(String s);

    /**
     * 基本换行打印函数
     * @param s 打印字符串
     */
    public void println(String s);

    /**
     * 换行
     */
    public void println();

    /**
     * 错误打印函数
     * @param error 编译错误
     */
    public void error(CompilerError error);

    /**
     * Token打印函数
     * @param token Token
     */
    public void Token(Token token);

}
