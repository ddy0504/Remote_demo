import cx_Oracle
conn=cx_Oracle.connect ('scott/tiger@ORCL')
curs=conn.cursor ()
sql='select ename,job from emp'
rr=curs.execute (sql)
row=curs.fetchone()

while row:
    (NAME,JOB)=(row[0],row[1])
    row=curs.fetchone ()
    print (NAME,JOB)