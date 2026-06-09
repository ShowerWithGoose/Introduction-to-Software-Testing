package utils;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.ArrayList;

public class File {
    //READ FILE
    public static BufferedInputStream ReadFile(String file) {
        FileInputStream fis = null;
        try {
            fis = new FileInputStream(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        BufferedInputStream bis = null;
        if (fis != null) {
            bis = new BufferedInputStream(fis);
        }
        return bis;
    }

    public static void WriteFile(String file, ArrayList<String> content) {
        try (FileWriter writer = new FileWriter(file)) {
            for (String line : content) {
                writer.write(line);
                writer.write("\n");
            }
        } catch (java.io.IOException e) {
            e.printStackTrace();
        }
    }
}

/*
import os
import zipfile

def zip_files(file_list, output_zip):
with zipfile.ZipFile(output_zip, 'w') as zipf:
        for file in file_list:
        if os.path.isfile(file):
        zipf.write(file, os.path.basename(file))
elif os.path.isdir(file):
        for root, dirs, files in os.walk(file):
        for f in files:
        zipf.write(os.path.join(root, f), os.path.relpath(os.path.join(root, f), os.path.join(file, '..')))

def get_all_files_and_dirs(folder):
        return [os.path.join(folder, f) for f in os.listdir(folder)]

        if __name__ == "__main__":
        # 获取指定文件夹下的所有文件和文件夹
        folder_to_zip = 'src'
files_to_zip = get_all_files_and_dirs(folder_to_zip)
output_zip_file = 'output.zip'

zip_files(files_to_zip, output_zip_file)
print(f"打包完成: {output_zip_file}")
*/
