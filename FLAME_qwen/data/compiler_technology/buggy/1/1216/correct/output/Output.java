package output;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
// 负责结果输出
public class Output<T> {
    T data;
    public Output(T data) {
        this.data = data;
    }
    public void printToFile(String outputPath, boolean append) {
        // 打印分析结果
        File f = new File(outputPath);
        try (OutputStream out = new FileOutputStream(f, append)){
            if (data != null) {
                out.write(data.toString().getBytes());
            }
        } catch (IOException e) {
            System.out.printf("failed printing to file %s\n", outputPath);
        }
    }
}
