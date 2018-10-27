package dao;

import model.Table;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class TableReader {

    static final String NULL_DATA_STRING = "[DANNY_IS_A_BITCH]";

    private static final String REGEX = "\t";

    public static Table loadTableFromFile(String filename) throws IOException {

        if(filename.lastIndexOf(".tbl") == filename.length() - 4) {
            File file = new File(filename);
            Table table = new Table(file.getAbsolutePath());

            try {
                FileReader fileReader = new FileReader(file);
                BufferedReader bufferedReader = new BufferedReader(fileReader);
                String line;
                boolean headersRead = false;

                List<String> headers = new ArrayList<>();

                while ((line = bufferedReader.readLine()) != null) {

                    if(headersRead == false) {
                        headers = List.of(line.split(REGEX));
                        headersRead = true;
                    } else {
                        List<String> entry = List.of(line.split(REGEX));

                        String primaryKey = entry.get(0);

                        for(int index = 0; index < headers.size(); index++) {
                            String currentHeader = headers.get(index);
                            String currentData = entry.get(index + 1);

                            if(currentData.equals(NULL_DATA_STRING)) {
                                currentData = "";
                            }

                            table.setData(primaryKey, headers.get(index), currentData);
                        }
                    }

                }

                fileReader.close();
            } catch (Exception e) {
                e.printStackTrace();
            }

            return table;
        } else {
            throw new IOException(filename + " is not a .tbl file");
        }

    }
}
