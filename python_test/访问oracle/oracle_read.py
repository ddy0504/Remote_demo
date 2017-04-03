import sys
import csv
import cx_Oracle
#connection = raw_input("Enter Oracle DB connection (uid/pwd@database) : ")
orcl = cx_Oracle.connect('scott/tiger@ORCL')
curs = orcl.cursor()
printHeader = True # include column headers in each table output
sql = "select * from tab" # get a list of all tables
curs.execute(sql)
for row_data in curs:
    if not row_data[0].startswith('BIN$'): # skip recycle bin tables
        tableName = row_data[0]
        # output each table content to a separate CSV file
        csv_file_dest = tableName + ".csv"
        outputFile = open(csv_file_dest,'w') # 'wb'
        output = csv.writer(outputFile, dialect='excel')
        sql = "select * from " + tableName
        curs2 = orcl.cursor()
        curs2.execute(sql)#curs2返回所有查询结果
        if printHeader: # add column headers if requested
            cols = []
            for col in curs2.description:
                cols.append(col[0])#cols存储列名
            output.writerow(cols)
        for row_data in curs2: # add table rows
            output.writerow(row_data)
        outputFile.close()