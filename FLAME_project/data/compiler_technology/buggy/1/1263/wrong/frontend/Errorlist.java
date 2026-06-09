package frontend;

import java.util.ArrayList;
import java.util.Collections;

public class Errorlist {
    private ArrayList<Error> list;

    public Errorlist() {
        this.list = new ArrayList<>();
    }

    public void adderror(Error e){
        list.add(e);
    }

    public void printall() {
        if (list.isEmpty()) return;

        Collections.sort(list);

        for (int i = 0;i < list.size();i++) {
            System.err.println(list.get(i));
        }
    }
}
