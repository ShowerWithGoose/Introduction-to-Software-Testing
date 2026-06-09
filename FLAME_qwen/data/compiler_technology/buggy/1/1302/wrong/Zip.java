import java.io.*;
import java.nio.file.*;
import java.util.zip.*;

public class Zip {
    public static void main(String[] args) {
        String zipFileName = "src/src.zip";
        String[] filesToZip = {"src/Compiler.java", "src/config.json", "src/frontend", "src/Zip.java", "src/Test.java"};

        try (ZipOutputStream zipOut = new ZipOutputStream(new FileOutputStream(zipFileName))) {
            for (String filePath : filesToZip) {
                File fileToZip = new File(filePath);
                if (fileToZip.exists()) {
                    if (fileToZip.isFile()) {
                        zipFile(fileToZip, zipOut, "");
                    } else {
                        zipDirectory(fileToZip, zipOut, fileToZip.getName() + "/");
                    }
                } else {
                    System.out.println("文件或目录 " + filePath + " 不存在");
                }
            }
            System.out.println("压缩完成: " + zipFileName);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void zipFile(File fileToZip, ZipOutputStream zipOut, String basePath) throws IOException {
        try (FileInputStream fis = new FileInputStream(fileToZip)) {
            ZipEntry zipEntry = new ZipEntry(basePath + fileToZip.getName());
            zipOut.putNextEntry(zipEntry);

            byte[] bytes = new byte[1024];
            int length;
            while ((length = fis.read(bytes)) >= 0) {
                zipOut.write(bytes, 0, length);
            }
        }
    }

    private static void zipDirectory(File dirToZip, ZipOutputStream zipOut, String basePath) throws IOException {
        for (File file : dirToZip.listFiles()) {
            if (file.isFile()) {
                zipFile(file, zipOut, basePath);
            } else {
                zipDirectory(file, zipOut, basePath + file.getName() + "/");
            }
        }
    }
}
