package fault;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * 错误处理类
 */
public class Fault {
    /**
     * 内部错误码，供程序内传递错误信息
     */
    static public final int INNER_ERROR = -2;
    /**
     * end of file
     */
    static public final char EOF = (char) -1;
    /**
     * 错误列表，记录所有的错误信息
     */
    private List<FaultInfo> faultList = new ArrayList<>();

    /**
     * 限制初始化方法的作用域为 private
     */
    private Fault() {
    }

    /**
     * Fault 单例
     */
    private static Fault fault;

    /**
     * 获取错误处理单例
     *
     * @return 错误处理单例
     */
    public static Fault getFault() {
        if (fault == null) {
            fault = new Fault();
        }
        return fault;
    }

    /**
     * 错误 code a 的封装
     *
     * @param line 发生错误的行数
     */
    public void illegalSymbol(int line) {
        faultList.add(new FaultInfo('a', line));
    }

    /**
     * 错误 code b 的封装
     *
     * @param line 发生错误的行数
     */
    public void redefinedName(int line) {
        faultList.add(new FaultInfo('b', line));
    }

    /**
     * 错误 code c 的封装
     *
     * @param line 发生错误的行数
     */
    public void undefinedName(int line) {
        faultList.add(new FaultInfo('c', line));
    }

    /**
     * 错误 code d 的封装
     *
     * @param line 发生错误的行数
     */
    public void unmatchedParamCount(int line) {
        faultList.add(new FaultInfo('d', line));
    }

    /**
     * 错误 code e 的封装
     *
     * @param line 发生错误的行数
     */
    public void unmatchedParamType(int line) {
        faultList.add(new FaultInfo('e', line));
    }

    /**
     * 错误 code f 的封装
     *
     * @param line 发生错误的行数
     */
    public void returnValueInVoid(int line) {
        faultList.add(new FaultInfo('f', line));
    }

    /**
     * 错误 code g 的封装
     *
     * @param line 发生错误的行数
     */
    public void noReturnInNotVoid(int line) {
        faultList.add(new FaultInfo('g', line));
    }

    /**
     * 错误 code h 的封装
     *
     * @param line 发生错误的行数
     */
    public void changeConst(int line) {
        faultList.add(new FaultInfo('h', line));
    }

    /**
     * 错误 code i 的封装
     *
     * @param line 发生错误的行数
     */
    public void lackFen(int line) {
        faultList.add(new FaultInfo('i', line));
    }

    /**
     * 错误 code j 的封装
     *
     * @param line 发生错误的行数
     */
    public void lackRXiao(int line) {
        faultList.add(new FaultInfo('j', line));
    }

    /**
     * 错误 code k 的封装
     *
     * @param line 发生错误的行数
     */
    public void lackRZhong(int line) {
        faultList.add(new FaultInfo('k', line));
    }

    /**
     * 错误 code l 的封装
     *
     * @param line 发生错误的行数
     */
    public void unmatchedPrintf(int line) {
        faultList.add(new FaultInfo('l', line));
    }

    /**
     * 错误 code m 的封装
     *
     * @param line 发生错误的行数
     */
    public void breakOrContinueInNotLoop(int line) {
        faultList.add(new FaultInfo('m', line));
    }

    /**
     * 其他词法分析错误的封装（不应该出现）
     *
     * @param line 发生错误的行数
     */
    public void otherInLexer(int line) {
        faultList.add(new FaultInfo('1', line));
    }

    /**
     * 其他无法分析错误的封装（不应该出现）
     *
     * @param line 发生错误的行数
     */
    public void otherInParse(int line) {
        faultList.add(new FaultInfo('2', line));
    }

    /**
     * 输出错误信息
     *
     * @param printStream 输出流
     */
    public void printFault(PrintStream printStream) {
        faultList.sort(new Comparator<FaultInfo>() {
            @Override
            public int compare(FaultInfo o1, FaultInfo o2) {
                return o1.line - o2.line;
            }
        });
        for (FaultInfo faultInfo : faultList) {
            printStream.println(faultInfo);
        }
    }

    /**
     * 是否有错误
     *
     * @return 是否有错误
     */
    public boolean hasFault() {
        return !faultList.isEmpty();
    }
}
