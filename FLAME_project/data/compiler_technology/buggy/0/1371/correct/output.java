import java.io.*;
import java.util.ArrayList;

public class output {
    public output(ArrayList<Token> tokens ,int sign) throws IOException {
        File f = new File("lexer.txt");
        File f2 = new File("error.txt");
        FileOutputStream fos1 = new FileOutputStream(f);
        FileOutputStream fos2 = new FileOutputStream(f2);
        OutputStreamWriter dos1 = new OutputStreamWriter(fos1);
        OutputStreamWriter dos2 = new OutputStreamWriter(fos2);
        for (int i = 0;i< tokens.size();i++) {
          if (tokens.get(i).getType().equals("KEYWORD") && sign==0){
              String s = tokens.get(i).getContent();
              StringBuilder sb = new StringBuilder();
              for (int j = 0;j <s.length();j++) {
                  char t = s.charAt(j);
                  sb.append((char)(t-32) );
              }
              sb.append('T');
              sb.append('K');
              dos1.write(sb+" "+tokens.get(i).getContent());
              dos1.write('\n');

          } else if(tokens.get(i).getType().equals("ERROR_A") && sign ==1){
              dos2.write(tokens.get(i).getContent() +" "+"a");
              dos2.write('\n');
          }
          else {
              if(sign ==0)
              {
                  dos1.write(tokens.get(i).getType() + " " + tokens.get(i).getContent());
                  dos1.write('\n');
              }
          }
      }
        dos1.close();
        dos2.close();
    }
}
