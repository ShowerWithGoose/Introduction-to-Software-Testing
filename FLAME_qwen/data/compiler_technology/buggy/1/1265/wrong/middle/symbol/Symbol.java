package middle.symbol;

import java.util.HashMap;
import java.util.Map;

public class Symbol {
    public enum IdentifyType {
        VARIATE, FUNCTION, ARRAY, FPARAM, RPARAM, CONST, CONSTARRAY
    }

    public enum VariateType {
        INT, CHAR, PINT, PCHAR, VOID
    }

    public static class IdentifyInfo {
        private IdentifyType identifyType;
        private VariateType variateType;
        private int length;
        private long address;
        private int size;

        /**
         * 标识符信息
         *
         * @param identifyType 类型
         * @param variateType  变量类型（function对应返回值类型）
         * @param length       数组长度（只有数组有）
         * @param address      地址
         * @param size         内存大小
         */
        public IdentifyInfo(IdentifyType identifyType, VariateType variateType, int length, long address, int size) {
            this.identifyType = identifyType;
            this.variateType = variateType;
            this.length = length;
            this.address = address;
            this.size = size;
        }

        public IdentifyType getIdentifyType() {
            return identifyType;
        }

        public VariateType getVariateType() {
            return variateType;
        }

        public int getLength() {
            return length;
        }

        public long getAddress() {
            return address;
        }

        public int getSize() {
            return size;
        }
    }

    private static Map<String, IdentifyInfo> identifyMap = new HashMap<String, IdentifyInfo>();

    public static void addIdentify(String name, IdentifyInfo identifyInfo) {
        identifyMap.put(name, identifyInfo);
    }
}
