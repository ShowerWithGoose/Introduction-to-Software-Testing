package lexicalanalysis;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ErrorInfo {
    private ArrayList<Character> errorText;
    private ArrayList<Integer> errorLine;

    public ErrorInfo()
    {
        errorText = new ArrayList<>();
        errorLine = new ArrayList<>();
    }

    public void addError(char error, int line)
    {
        errorText.add(error);
        errorLine.add(line);
    }

    public boolean isEmpty() {
        return errorText.isEmpty() && errorLine.isEmpty();
    }

    public void sort() {
        for (int i = 0; i < errorText.size() - 1; i++) {
            for (int j = 0; j < errorText.size() - 1 - i; j++) {
                if (errorLine.get(j) > errorLine.get(j + 1)) {
                    int tempLine = errorLine.get(j);
                    char tempText = errorText.get(j);
                    errorLine.set(j, errorLine.get(j + 1));
                    errorText.set(j, errorText.get(j + 1));
                }
            }
        }
    }

    public void printError()
    {
        String filePath = "error.txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath, true))) {
            sort();
            for (int i = 0; i < errorText.size(); i++) {
                writer.write(errorLine.get(i) + " " + errorText.get(i) + "\n");
            }
            //writer.write(errorLine + " " + errorText);
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("写入文件时发生错误。");
        }
    }
}
