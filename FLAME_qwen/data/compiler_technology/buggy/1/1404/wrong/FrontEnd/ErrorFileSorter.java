package FrontEnd;

import java.io.*;
import java.util.*;

public class ErrorFileSorter {
    // 静态方法：排序文件并写回文件
    public static void sortErrorFile(String filePath) {
        File file = new File("error.txt");

        // 检查文件是否存在
        if (!file.exists()) {
//            System.out.println("文件不存在: " + filePath);
            return;  // 文件不存在，退出方法
        }

        List<String[]> errorList = new ArrayList<>();  // 存储行号和错误代码

        // 读取文件并将数据存入列表
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\\s+"); // 假设行号和错误代码由空格分隔
                if (parts.length == 2) {
                    errorList.add(parts);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // 对列表进行排序，先按行号（数值），再按错误代码（字母顺序）
        /*每行最多一个错误*/
        errorList.sort((a, b) -> {
            int lineNumCompare = Integer.compare(Integer.parseInt(a[0]), Integer.parseInt(b[0]));
            if (lineNumCompare != 0) {
                return lineNumCompare;  // 如果行号不同，按行号排序
            }
            return 0;  // 如果行号相同，保持原顺序（即不做任何进一步的比较）
        });

        // 将排序后的结果写回文件
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            for (String[] error : errorList) {
                bw.write(error[0] + " " + error[1]);
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

//        System.out.println("文件已排序并写回: " + filePath);
    }
}
