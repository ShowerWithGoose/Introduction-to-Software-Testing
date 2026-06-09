package frontend;
import java.util.ArrayList;

public class ErrList {
    static public ArrayList<ErrInfo> errList = new ArrayList<>();
    static public void print() {
        errList.sort((e1, e2) -> Integer.compare(e1.lineNum, e2.lineNum));
        for(int i = 0;i < errList.size();i++) {
            errList.get(i).print();
        }
    }

}
