import java.io.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;

public class output {
    public output(ArrayList<Token> tokens ,int sign,ArrayList<Error>errors) throws IOException {
        File f = new File("parser.txt");
        File f2 = new File("error.txt");
        FileOutputStream fos1 = new FileOutputStream(f);
        FileOutputStream fos2 = new FileOutputStream(f2);
        OutputStreamWriter dos1 = new OutputStreamWriter(fos1);
        OutputStreamWriter dos2 = new OutputStreamWriter(fos2);
        if(sign == 0 && errors.isEmpty()) {
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens.get(i).getType() == Token.Type.KEYWORD ) {
                String s = tokens.get(i).getContent();
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < s.length(); j++) {
                    char t = s.charAt(j);
                    sb.append((char) (t - 32));
                }
                sb.append('T');
                sb.append('K');
                dos1.write(sb + " " + tokens.get(i).getContent());
                dos1.write('\n');}
                else if (tokens.get(i).getType() == Token.Type.NAME ) {
                    dos1.write(tokens.get(i).getContent());
                    dos1.write('\n');
                } else {
                    dos1.write(tokens.get(i).getType().toString() + " " + tokens.get(i).getContent());
                    dos1.write('\n');
            }
        }
    }
        Collections.sort(errors, new Comparator<Error>() {
                @Override
                public int compare(Error o1, Error o2) {
                    return o1.getLine()- o2.getLine();
                }
            });
            for (int j = 0;j<errors.size();j++) {
                dos2.write(errors.get(j).getLine()+" "+errors.get(j).getContent());
                dos2.write('\n');
            }

        dos1.close();
        dos2.close();
}
}

