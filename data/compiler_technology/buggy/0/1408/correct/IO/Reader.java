package IO;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Reader
{
    private final String path;
    private String content;

    public Reader(String filePath)
    {
        this.path = filePath;
    }

    public String readDoc() throws IOException
    {
        StringBuilder builder = new StringBuilder();
        String currentLine;
        BufferedReader bufferedReader = new BufferedReader(new FileReader(path));
        while ((currentLine = bufferedReader.readLine()) != null)
        {
            builder.append(currentLine);
            builder.append('\n');
        }
        content = builder.toString();
        return builder.toString();
    }

    public String readIn()
    {
        Scanner scanner = new Scanner(System.in);
        StringBuilder builder = new StringBuilder();
        String currentLine;
        while ((currentLine = scanner.nextLine()) != null)
        {
            builder.append(currentLine);
            builder.append('\n');
        }
        content = builder.toString();
        return builder.toString();
    }
}
