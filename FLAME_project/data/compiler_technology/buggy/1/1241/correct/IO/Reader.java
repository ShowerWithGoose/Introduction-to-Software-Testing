package IO;

import java.io.*;
import java.util.ArrayList;

/**
 * The type Reader.
 *
 * @author
 * @Description: 读取文件
 * @date
 */
public class Reader {

    /**
     * 读取代码
     *
     * @return 数组列表
     * @throws FileNotFoundException 文件未找到异常
     */
    public static ArrayList<String> readCode() throws FileNotFoundException {

        ArrayList<String> list = new ArrayList<>();

        StringBuffer text = new StringBuffer();;
        File file = new File("testfile.txt");
        FileReader reader = new FileReader(file);
        BufferedReader br = new BufferedReader(reader);
        try {



            String line;

            while ((line = br.readLine()) != null) {
                list.add(line);
                System.out.println(line);
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }



        return list;

    }
}
