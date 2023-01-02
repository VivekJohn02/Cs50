"""
Example tkinter and SQLite3 Database Application
Database Control Class (Containee Class)
26 September 2022
Raymond Schenk, Vivek John
"""

#imports Section
import sqlite3
#import tkinter as tk #(Vivek commented not needed)

class Lefty:

    def __init__(self):

        #Defining variables for the class we will access
        #both internally and as the contained class from the GUI

        #Connection Flag
        self.connected = False
        self.records = []
        #Holding variables for records to be inserted/updated
        self.insertRec = ["","",0]
        self.updateRec = [0,"","",0]
        #Administrative utility message variables for debugging
        self.alertMessage = "No message yet."
        self.query = "NO QUERY YET."

    def connect(self):
        #All database connections and queries should be try/excepted
        try:
            #Connection object to local database in SQLite3
            self.sqlConnection = sqlite3.connect("ctaern.db")

            #Cursor object for this database
            self.cursor = self.sqlConnection.cursor()

            return "Connected Properly."

        except sqlite3.Error as error:
            return "Error Connecting: ", error

    #Disconnecting from the database
    def disconnect(self):
        if(self.sqlConnection):
            self.sqlConnection.close()
            return "Connection Closed"

    #Query databae for all records and load into self.records
    # which is the list used to hold all records for the GUI/Controller
    #Read (cRud)
    def load(self):
        try:
            #Query everything SORTED (ORDER) by last name
            query = "SELECT * FROM lefties ORDER BY lastName;"
            self.cursor.execute(query) #(Vivek removed ;colin)

            #Retrieve all records into a list of tuples
            self.records = self.cursor.fetchall()
            return ""
        except sqlite3.Error as error:
            return "Error Loading: ", error

    #Inserting a new record into the database. We DO NOT NEED
    #to push an id, as this is given to us as the next number
    #in order because our id is an autoincremented Primary Key
    #Create (Crud)
    def insert(self):
        try:
            query = "INSERT INTO lefties (firstName, lastName, age) VALUES (?,?,?);"
            self.cursor.execute(query,self.insertRec)
            #Lazy loading should pull max int here and insert into list
            self.load()   #This forces the recent addition to now have its ID value in memory
            return "Insertion Complete."
        except sqlite3.Error as error:
            return "Error Inserting Record: ", error #(Vivek added)

    #Updating an existing record
    #Update  (crUd)
    def updateChangedRec(self):
        try:
            #Be VERY CAREFUL building this query. Note single apostrophes
            #for fields that need to be in query strings vs. numericals.
            print(str(self.updateRec[3]))
            print(str(self.updateRec[0]))

            #self.query = "UPDATE lefties SET firstName='" + self.updateRec[1]
            #self.query = self.query + "', lastName='"
            #self.query = self.query + self.updateRec[2] + "', age="
            #self.query = self.query + str(self.updateRec[3])
            #self.query = self.query + " WHERE id=" + str(self.updateRec[0]) + ";"
            self.query = "UPDATE lefties SET firstName='" + self.updateRec[1] + "', lastName='" + self.updateRec[2] + "', age=" + str(self.updateRec[3]) + " WHERE id=" + str(self.updateRec[0]) + ";"
            print(self.query)

            # UPDATE lefties set firstName='bob', lastName='Smith', age=34 WHERE id=7;

            self.cursor.execute(self.query)
            self.sqlConnection.commit()
            return "Record Updated Successfully."
        except sqlite3.Error as error:
            return "Error updating record: ", error #(Vivek added)

    #Deleting a record by id Number
    #Delete (cruD)
    def deleteRecord(self, row):
        try:
            query = "DELETE FROM lefties WHERE id=" + str(row) + ";"
            self.cursor.execute(query)
            self.sqlConnection.commit()
            self.load()
            return "Record Deleted."
        except sqlite3.Error as error:
            return "Error Deleting Record.: ", error #(Vivek added)
