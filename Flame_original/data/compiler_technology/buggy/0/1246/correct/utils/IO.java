package utils;

import java.io.*;

/**
 * @Description 利用Config 读写操作
 * @Author
 * @Date 2024/9/17
 */


public class IO {
    public enum IOType {
        LEXER, CHECKER
    }

    public static String read(String filePath) {
        // 需要根据当前类的路径
        File inputFile = new File(filePath);
        String inputText = "";
        System.out.println("读取输入文件：" + inputFile.getAbsolutePath());
        try {
            FileReader fileToRead = new FileReader(inputFile);
            StringBuilder stringBuilder = new StringBuilder();
            char[] buffer = new char[20];
            int size;
            while ((size = fileToRead.read(buffer)) != -1) {
                stringBuilder.append(buffer, 0, size);
            }
            inputText = stringBuilder.toString();
        } catch (Exception e) {
            System.out.println("文件读入失败！" + e);
        }
        return inputText;
    }

    /**
     * 将字符串写入指定路径的文件
     *
     * @param filePath  指定路径
     * @param content   要写入的内容
     * @param appending 是否追加输出
     * @param println   是否换行
     */
    public static void write(String filePath, String content, boolean appending, boolean println) {
        File file = new File(filePath);
        try {
            if (!file.exists()) {
                file.createNewFile();
            }
            if (!appending) {
                System.out.println("覆写至文件：" + file.getAbsolutePath());
                FileOutputStream fileToWrite = new FileOutputStream(file);
                fileToWrite.write(content.getBytes());
            } else {
                FileWriter fileWriter = new FileWriter(file, true);
                if (println) {
                    fileWriter.write(content + '\n');
                } else {
                    fileWriter.write(content);
                }
                fileWriter.flush();
                fileWriter.close();
            }
        } catch (IOException e) {
            System.out.println("文件输出失败" + e);
        }
    }

    /**
     * 根据当前输出类型写入已配置好的路径
     *
     * @param ioType    当前在写的步骤类型
     * @param content   要写入的内容
     * @param appending 是否追加输出
     * @param println   是否换行
     */
    public static void write(IOType ioType, String content, boolean appending, boolean println) {
        String filePath = getPath(true, ioType);
        write(filePath, content, appending, println);
    }

    // 默认读入已配置好的路径
    public static String read() {
        String filePath = getPath(false, IOType.LEXER);
        return read(filePath);
    }

    // 计算路径
    public static String getPath(boolean output, IOType ioType) {
        // 读取输出路径
        if (output) {
            switch (ioType) {
                case CHECKER -> {
                    return Config.atLocal ? Config.localOutputErrorFilePath : Config.outputErrorFilePath;
                }
                // LEXER, PARSER
                default -> {
                    return Config.atLocal ? Config.localOutputLexerFilePath : Config.outputLexerFilePath;
                }
            }
        }
        // 读取输入路径
        else {
            return Config.atLocal ? Config.localInputFilePath : Config.inputFilePath;
        }
    }
}
