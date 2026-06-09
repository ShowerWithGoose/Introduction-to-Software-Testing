package frontend.SyntaxError;

import frontend.SyntaxError.ErrorType;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

/**
 * SyntaxErrorHandler 类用于处理语法错误。
 * 该类采用单例模式，确保在程序中只存在一个语法错误处理器的实例。
 * 主要功能包括：记录错误、清空错误文件、对错误进行排序。
 */
public class SyntaxErrorHandler {
    // 单例模式中的唯一实例，确保整个程序只有一个 SyntaxErrorHandler 实例
    private static final SyntaxErrorHandler instance = new SyntaxErrorHandler();

    // 存储错误信息的文件名
    private final String ErrorFileName = "error.txt";

    /**
     * 私有构造函数，防止外部实例化该类。
     * 使用单例模式，只能通过 getInstance() 方法获取唯一实例。
     */
    private SyntaxErrorHandler() {
        // 私有构造函数，不允许外部实例化
    }

    /**
     * 获取 SyntaxErrorHandler 的唯一实例。
     * @return SyntaxErrorHandler 的实例
     */
    public static SyntaxErrorHandler getInstance() {
        return instance;  // 返回单例实例
    }

    /**
     * 清空错误文件 "error.txt" 的内容。
     * 如果文件存在，则清空内容；如果不存在则不做任何操作。
     */
    public void ClearError_txt() {
        // 检查错误文件是否存在
        if (new File(ErrorFileName).exists()) {
            try {
                // 使用 FileWriter 创建一个新的空文件，关闭文件即完成清空操作
                new FileWriter(ErrorFileName, false).close();
            } catch (IOException e) {
                // 捕获并打印异常
                e.printStackTrace();
            }
        }
    }

    /**
     * 将语法错误记录写入文件 "error.txt"。
     * 每条错误信息包含错误行号和错误类型。
     * @param errorType 错误的类型
     * @param line 错误发生的行号
     */
    public void WriteSyntaxError(ErrorType errorType, int line) {
        // 使用 BufferedWriter 以追加模式打开文件，写入新的错误信息
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(ErrorFileName, true))) {
            // 格式为：行号 + " " + 错误类型
            writer.write(line + " " + errorType);
            writer.newLine();  // 换行符，便于多条错误记录的分隔
        } catch (IOException e) {
            // 捕获并打印 IO 异常
            e.printStackTrace();
        }
    }

    /**
     * 对错误文件 "error.txt" 中的错误记录按行号进行排序。
     * 排序后会将排序结果覆盖写回文件。
     */
    public void SortError_txt() {
        // 读取错误文件中的所有行，存储在 ArrayList 中
        ArrayList<String> lines = readErrorLines();
        if (!lines.isEmpty()) {
            // 按行号进行排序
            Collections.sort(lines, this::compareLines);
            // 将排序后的结果写回错误文件
            writeSortedErrors(lines);
        }
        else{
            return;
        }
    }

    /**
     * 从错误文件 "error.txt" 中读取所有错误记录。
     * @return 包含错误记录的 ArrayList，每个元素为一行错误信息
     */
    private ArrayList<String> readErrorLines() {
        ArrayList<String> lines = new ArrayList<>();
        File file = new File(ErrorFileName);
        if (!file.exists()) {
            // 文件不存在，直接返回空列表
            return lines;
        }
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            // 捕获并处理 IO 异常，避免打印堆栈跟踪
            // 可以选择记录日志或给出友好的提示，但不建议打印堆栈跟踪
            // e.printStackTrace();
        }
        return lines;
    }


    /**
     * 比较两条错误记录，按照行号进行升序排序。
     * @param o1 第一条错误记录
     * @param o2 第二条错误记录
     * @return 比较结果，-1 表示 o1 小于 o2，0 表示相等，1 表示 o1 大于 o2
     */
    private int compareLines(String o1, String o2) {
        // 提取错误记录中的行号，并将其转换为整数
        int lineNum1 = Integer.parseInt(o1.split(" ")[0]);
        int lineNum2 = Integer.parseInt(o2.split(" ")[0]);
        // 比较两个行号的大小
        return Integer.compare(lineNum1, lineNum2);
    }

    /**
     * 将排序后的错误记录写回错误文件。
     * @param lines 包含已排序错误记录的 ArrayList
     */
    private void writeSortedErrors(ArrayList<String> lines) {
        // 使用 BufferedWriter 覆盖写入已排序的错误记录
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(ErrorFileName, false))) {
            for (String str : lines) {
                writer.write(str);  // 写入每条错误记录
                writer.newLine();   // 换行符
            }
        } catch (IOException e) {
            // 捕获并打印 IO 异常
        }
    }
}
