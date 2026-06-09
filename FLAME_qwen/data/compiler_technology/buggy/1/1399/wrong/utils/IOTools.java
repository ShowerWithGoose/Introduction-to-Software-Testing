package utils;

import java.io.*;

import config.Config;

public class IOTools {
    /**
     * 读取文件
     *
     * @param filePath 文件路径
     * @return 文件内容
     * @throws IOException 如果读取过程中发生错误
     */
    public static String readFile(String filePath) throws IOException {
        // 创建文件输入流
        FileInputStream fileInputStream = new FileInputStream(filePath);
        // 创建字符输入流，用于读取文件内容
        InputStreamReader inputStreamReader = new InputStreamReader(fileInputStream);
        // 创建缓冲读取器，用于逐行读取文件内容
        try (BufferedReader reader = new BufferedReader(inputStreamReader)) {
            // 创建一个用于存储文件内容的StringBuilder
            StringBuilder contentBuilder = new StringBuilder();
            // 逐行读取文件内容
            String currentLine;
            while ((currentLine = reader.readLine()) != null) {
                // 将读取的行添加到StringBuilder中，并添加换行符
                contentBuilder.append(currentLine).append(System.lineSeparator());
            }
            // 返回文件内容
            return contentBuilder.toString();
        } finally {
            // 确保关闭字符输入流
            inputStreamReader.close();
            // 确保关闭文件输入流
            fileInputStream.close();
        }
    }

    /**
     * 写入文件
     *
     * @param content   要写入的文件内容
     * @param filePath  文件路径
     * @param is_append 是否追加
     * @throws IOException 如果写入过程中发生错误
     */
    public static void writeFile(String content, String filePath, boolean is_append) {
        // 创建一个File对象，表示要写入的文件路径
        File file = new File(filePath);
        try {
            // 创建一个FileWriter对象，用于写入文件
            FileWriter writer = new FileWriter(file, is_append);
            // 将字符串内容写入文件
            writer.write(content);
            // 关闭文件写入流
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * 清空文件
     *
     * @param filePath 文件路径
     */
    public static void clearFile(String filePath) {
        if (!isFileExist(filePath)) return; // 文件不存在，直接返回
        IOTools.writeFile("", filePath, false);
    }

    /**
     * 删除文件
     *
     * @param filePath 文件路径
     * @ return true:删除成功，false:删除失败
     */
    public static boolean deleteFile(String filePath) {
        File file = new File(filePath);
        if (file.exists()) {
            file.delete();
            return true;
        }
        return false;
    }

    /**
     * 判断文件是否存在
     *
     * @param filePath 文件路径
     * @return true:文件存在，false:文件不存在
     */
    public static boolean isFileExist(String filePath) {
        File file = new File(filePath);
        return file.exists();
    }

    /**
     * 将词法分析器的结果（语法树）输出到指定文件中
     *
     * @param content 输出内容
     */
    public static void parserOutput(String content) {
        IOTools.writeFile(content + "\n", Config.OUTPUT_PARSER_FILE_PATH, true);
        if (Config.is_print_to_console) System.out.println(content);
    }
}
