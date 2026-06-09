package frontend.Error;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * @author
 * @Description:
 * @date 2024/10/15 23:29
 */
public class ErrorList {
    public static ArrayList<Error> errorList = new ArrayList<>();
    public static void addErrorList(ArrayList<Error> list){
//        if(errorList.isEmpty()){
//            errorList = list;
//            return ;
//        }
        ArrayList<Error> mergedList = new ArrayList<>(errorList);
        mergedList.addAll(list);

        // 按照 int 进行排序
        Collections.sort(mergedList, new Comparator<Error>() {
            @Override
            public int compare(Error p1, Error p2) {
                return Integer.compare(p1.getLineNum(), p2.getLineNum());
            }
        });

        errorList = mergedList;
    }
}
