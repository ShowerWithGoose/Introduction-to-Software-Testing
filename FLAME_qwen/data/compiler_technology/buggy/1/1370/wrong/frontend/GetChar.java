package frontend;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class GetChar {
    private String filepath;
    private String line;
    private int cc;
    private int ll;
    private BufferedReader br;

    private int lineno=0;


    public GetChar(String filepath) throws FileNotFoundException {
        this.filepath = filepath;
        this.line = "";
        this.cc = 0;
        this.ll = 0;
        this.br = new BufferedReader(new FileReader(filepath));
    }

    public Character getAChar(){
        Character ans;
        if(cc == ll){
            try {
                line = br.readLine();
                if(line == null){
                    br.close();
                    return null;
                }
                lineno++;
                ll = line.length();
                cc = 0;
                line = line+'\n';
                ll++;
                //System.out.println("GetChar Error:the last char of line is not '\n' \n");

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        ans = line.charAt(cc);
        cc++;
        if(ans!=null){
            return ans;
        }
        return null;
    }

    public void unGetAChar(){
        if(cc>0){
            cc--;
            return;
        }
        System.out.println("GetChar Error:You Want to be back to the last line!\n");
    }

    public int getLineno(){
        return lineno;
    }


}
