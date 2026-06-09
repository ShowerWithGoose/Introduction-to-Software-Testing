import java.io.BufferedInputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;

public class Read {
    private  String code;
    public Read() {
        this.code = null;
    }
    public void read(String filename) throws IOException {
        InputStream in = new BufferedInputStream(Files.newInputStream(Paths.get(filename)));
        Scanner scanner = new Scanner(in);
        while(scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if (this.code == null) {
                this.code = line + "\n";
            }
            else {
                this.code = this.code + line + "\n";
            }
        }
        delete();
    }

    //删除注释
    public void delete() {
        int flag = 0;
        for (int i = 0; i < this.code.length(); i++) {
            if (this.code.charAt(i) == '\"') {
                if (flag == 0) {
                    flag = 1;
                }
                else {
                    flag = 0;
                }
            }
            if (this.code.charAt(i) == '/' && i + 1 < this.code.length() && this.code.charAt(i + 1) == '*' && flag == 0) {
                String s = "";
                String next = "";
                for (; i < this.code.length(); i++) {
                    if (this.code.charAt(i) == '*' && i + 1 < this.code.length() && this.code.charAt(i + 1) == '/') {
                        s = s + "*/";
                        i++;
                        break;
                    }
                    if (this.code.charAt(i) == '\n') {
                        next = next + "\n";
                    }
                    s = s + this.code.charAt(i);
                }
                this.code = this.code.replace(s,next);
                i = i - s.length() + next.length();
                continue;
            }
            if (this.code.charAt(i) == '/' && i + 1 < this.code.length() && this.code.charAt(i + 1) == '/' && flag == 0) {
                String s = "";
                for (; i < this.code.length(); i++) {
                    s = s + this.code.charAt(i);
                    if (this.code.charAt(i) == '\n') {
                        break;
                    }
                }
                this.code = this.code.replace(s,"\n");
                i = i - s.length();
                continue;
            }
        }

    }

    public String getCode() {
        return this.code;
    }
}
