import sqlite3

def Create_table():
    conn.execute('''CREATE TABLE COMPANY
           (ID INT PRIMARY KEY     NOT NULL,
            NAME           TEXT    NOT NULL,
            AGE            INT     NOT NULL,
            ADDRESS        CHAR(50),
            SALARY         REAL);''')
    print ("Table created successfully")

def Insert():
    conn.execute("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) \
      VALUES (1, 'Paul', 32, 'California', 20000.00 )");
    conn.commit()
    print ("Insert successfully")

def Select():
    cursor = conn.execute("SELECT id, name, address, salary  from COMPANY")
    for row in cursor:
        print ("ID = ", row[0])
        print ("NAME = ", row[1])
        print ("ADDRESS = ", row[2])
        print ("SALARY = ", row[3], "\n")
    print ("Select done successfully")

def Update():
    conn.execute("UPDATE COMPANY set SALARY = 25000.00 where ID=1")
    conn.commit()
    print ("Total number of rows updated :", conn.total_changes)

    cursor = conn.execute("SELECT id, name, address, salary  from COMPANY")
    for row in cursor:
        print ("ID = ", row[0])
        print ("NAME = ", row[1])
        print ("ADDRESS = ", row[2])
        print ("SALARY = ", row[3], "\n")

    print ("Update done successfully")

def Delete():
    conn.execute("DELETE from COMPANY where ID=1;")
    conn.commit()
    print ("Total number of rows deleted :", conn.total_changes)

    cursor = conn.execute("SELECT id, name, address, salary  from COMPANY")
    for row in cursor:
        print ("ID = ", row[0])
        print ("NAME = ", row[1])
        print ("ADDRESS = ", row[2])
        print ("SALARY = ", row[3], "\n")

    print ("Operation done successfully")

def Close():
    conn.close()

if __name__ == "__main__":
    conn = sqlite3.connect('testDB.db')
    #Insert()
    #Select()
    #Update()
    Delete()
    Close()
