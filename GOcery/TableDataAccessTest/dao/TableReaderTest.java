package dao;

import model.Table;
import org.junit.Assert;
import org.junit.Test;

import java.io.IOException;

public class TableReaderTest {

    private static final String TABLE_FILENAME = "/Users/kohlkuntze/Documents/Workspaces/GOcery/TableDataAccessTest/dao/data/sample_table1.tbl";

    @Test
    public void readTableFromFileOne() {
        try {
            Table table = TableReader.loadTableFromFile(TABLE_FILENAME);

            Assert.assertTrue(table.getPrimaryKeys().size() == 1);
            Assert.assertTrue(table.getHeaders().size() == 2);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
