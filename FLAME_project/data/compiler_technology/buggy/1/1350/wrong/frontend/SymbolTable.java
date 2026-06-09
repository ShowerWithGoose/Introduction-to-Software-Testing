package frontend;

import java.util.ArrayList;

public class SymbolTable {
    public enum ReturnFuncType {
        VOID, INT, CHAR
    }

    private ArrayList<SymbolTableItem> items;

    private int domainCnt;

    private ArrayList<Integer> domainNums;

    private ArrayList<String> errors;

    private int circleCnt;

    private ReturnFuncType returnFuncType;

    private ArrayList<String> types;

    public SymbolTable() {
        items = new ArrayList<>();
        domainCnt = 0;
        domainNums = new ArrayList<>();
        errors = new ArrayList<>();
        circleCnt = 0;
        returnFuncType = ReturnFuncType.VOID;
        types = new ArrayList<>();
    }

    public ArrayList<SymbolTableItem> getItems() {
        return items;
    }

    public SymbolTableItem getItem(String name) {
        for (SymbolTableItem item : items) {
            if (item.getName().equals(name)) {
                return item;
            }
        }
        return null;
    }

    public void addItem(SymbolTableItem item) {
        items.add(item);
    }

    public void addDomainCnt() {
        domainCnt++;
    }

    public int getDomainCnt() {
        return domainCnt;
    }

    public void addDomainNum(int domainNum) {
        domainNums.add(domainNum);
    }

    public int getDomainNum() {
        int top = domainNums.size() - 1;
        return domainNums.get(top);
    }

    public void removeDomainNum() {
        int top = domainNums.size() - 1;
        domainNums.remove(top);
    }

    public void addError(String error) {
        errors.add(error);
    }

    public ArrayList<String> getErrors() {
        return errors;
    }

    public boolean containsName(String name, int domainNum) {
        for (SymbolTableItem item : items) {
            if (item.getName().equals(name) && item.getDomainNum() == domainNum) {
                return true;
            }
        }
        return false;
    }

    public String getType(String name) {
        for (int i = domainNums.size() - 1; i >= 0; i--) {
            int thisDomainNum = domainNums.get(i);
            for (SymbolTableItem item : items) {
                if (item.getName().equals(name) && item.getDomainNum() == thisDomainNum) {
                    return item.getType();
                }
            }
        }
        return null;
    }

    public boolean contains(String name) {
        for (Integer domainNum : domainNums) {
            for (SymbolTableItem item : items) {
                if (item.getName().equals(name) && item.getDomainNum() == domainNum) {
                    return true;
                }
            }
        }
        return false;
    }

    public void addCircleCnt() {
        circleCnt++;
    }

    public void subCircleCnt() {
        circleCnt--;
    }

    public int getCircleCnt() {
        return circleCnt;
    }

    public ReturnFuncType getReturnFuncType() {
        return returnFuncType;
    }

    public void setReturnFuncType(ReturnFuncType returnFuncType) {
        this.returnFuncType = returnFuncType;
    }

    public void clearTypes() {
        types.clear();
    }

    public void addType(String type) {
        types.add(type);
    }

    public ArrayList<String> getTypes() {
        return types;
    }
}
