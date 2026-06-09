package parse;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class WrongList {
    private ArrayList<WrongType> wrongs;

    public WrongList(){
        wrongs = new ArrayList<>();
    }

    public void addWrong(WrongType wrong){
        wrongs.add(wrong);
    }


    public String printout(){
        Collections.sort(wrongs, new Comparator<WrongType>() {
            @Override
            public int compare(WrongType o1, WrongType o2) {
                return Integer.compare(o1.getLinenumber(), o2.getLinenumber());
            }
        });
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i< wrongs.size();i++){
            WrongType x = wrongs.get(i);
            sb.append(x.getLinenumber() +" " + x.getType() + "\n");
        }
        return sb.toString();
    }
}
