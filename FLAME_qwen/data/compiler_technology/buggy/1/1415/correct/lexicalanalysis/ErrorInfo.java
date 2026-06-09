package lexicalanalysis;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class ErrorInfo {
    private final ArrayList<Character> errorText;
    private final ArrayList<Integer> errorLine;

    public ErrorInfo()
    {
        errorText = new ArrayList<>();
        errorLine = new ArrayList<>();
    }

    public void addError(char error, int line) {
        errorText.add(error);
        errorLine.add(line);
    }

    public boolean isEmpty() {
        return errorText.isEmpty() && errorLine.isEmpty();
    }

    public void printError() {
        String filePath = "error.txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath, true))) {
            List<Integer> list1 = new ArrayList<>(errorLine);
            List<Character> list2 = new ArrayList<>(errorText);

            // 使用List<AbstractMap.SimpleEntry>来存储对应关系
            List<Map.Entry<Integer, Character>> entries = new ArrayList<>();
            for (int i = 0; i < list1.size(); i++) {
                entries.add(new AbstractMap.SimpleEntry<>(list1.get(i), list2.get(i)));
            }

            // 根据list1的值进行排序，这里需要处理重复元素的情况
            // 可以选择不改变重复元素的相对顺序，或者根据某种规则来改变
            entries.sort(Map.Entry.comparingByKey());

            // 创建排序后的新列表
            List<Integer> sortedList1 = new ArrayList<>();
            List<Character> sortedList2 = new ArrayList<>();
            for (Map.Entry<Integer, Character> entry : entries) {
                sortedList1.add(entry.getKey());
                sortedList2.add(entry.getValue());
            }
            for (int i = 0; i < errorText.size(); i++) {
                writer.write(sortedList1.get(i) + " " + sortedList2.get(i) + "\n");
            }
            //writer.write(errorLine + " " + errorText);
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("写入文件时发生错误。");
        }
    }
}
