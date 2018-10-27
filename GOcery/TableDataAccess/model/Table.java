package model;

import java.util.*;

public class Table {

    private final String file;
    private final Set<String> headers;
    private final Map<String, Map<String, String>> table;

    public Table(String filename) {
        file = filename;
        headers = new HashSet<>();
        table = new HashMap<>();
    }

    public String getFilename() {
        return file;
    }

    public Set<String> getPrimaryKeys() {
        return table.keySet();
    }

    public Set<String> getHeaders() {
        return headers;
    }

    public String getData(String primaryKey, String secondaryKey) throws RuntimeException {
        Set<String> primaryKeySet = table.keySet();

        if(primaryKeySet.contains(primaryKey)) {

            Set<String> secondaryKeySet = table.get(primaryKey).keySet();

            if(secondaryKeySet.contains(secondaryKey)) {

                if(table.get(primaryKey).get(secondaryKey).equals("")) {
                    return null;
                }

                return table.get(primaryKey).get(secondaryKey);
            } else {
                throw new RuntimeException(secondaryKey + " was not a valid secondary Key for the table.");
            }

        } else {
            throw new RuntimeException(primaryKey + " was not a valid primary Key for the table.");
        }
    }

    public void setData(String primaryKey, String secondaryKey, String data) {
        Set<String> primaryKeySet = table.keySet();

        if(!headers.contains(secondaryKey)) {
            addHeader(secondaryKey);
        }

        if(!primaryKeySet.contains(primaryKey)) {
            table.put(primaryKey, new HashMap<>());
            updateHeaders(primaryKey);
        }

        table.get(primaryKey).put(secondaryKey, data);
    }

    public void removePrimaryKey(String primaryKey) {
        if(table.keySet().contains(primaryKey)) {
            table.remove(primaryKey).clear();
        }
    }

    private void addHeader(String newHeader) {
        headers.add(newHeader);

        Set<String> primaryKeySet = table.keySet();

        for(String primaryKey : primaryKeySet) {
            updateHeaders(primaryKey);
        }
    }

    private void updateHeaders(String primaryKey) {
        Map<String, String> currentTable = table.get(primaryKey);

        for(String currentHeader : headers) {
            if(!currentTable.keySet().contains(currentHeader)){
                currentTable.put(currentHeader, "");
            }
        }
    }
}
