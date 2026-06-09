import java.io.*;
import java.util.ArrayList;

public class Text {
    private ArrayList<String> lines;
    
    Text() throws IOException {
        lines = new ArrayList<>();
    }
    
    public ArrayList<String> getLines() throws IOException {
        String fileName = "testfile.txt";
        File file = new File(fileName);
        
        InputStreamReader input = new InputStreamReader(new FileInputStream(file));
        
        BufferedReader bufferedReader = new BufferedReader(input);
        
        String line = null;
        line = bufferedReader.readLine();
        
        while (line != null) {
            lines.add(line);
            line = bufferedReader.readLine();
        }
        return lines;
    }
    
    public void printError(int row,String error) throws IOException {
        FileWriter fw = new FileWriter("error.txt");
        BufferedWriter info = new BufferedWriter(fw);
        info.write(row + " " + error);
        info.flush();
        info.close();
    }
    
    public void printWord(ArrayList<Word> words) throws IOException {
        FileWriter fw = new FileWriter("lexer.txt");
        BufferedWriter info = new BufferedWriter(fw);
        for (Word word:words) {
            info.write(word.getType() + " " + word.getValue() + "\n");
            info.flush();
        }
        info.close();
    }

}
