'''
Example tKinter and SQLite Database Application
GUI/Container Class
03 October 2022
Ray Schenk, Vivek John
CTAERN Class
'''

#Imports Section
#Preprocessor Directives Section
import tkinter as tk
from lefty import Lefty

class LeftyGui:

    #Utility Dialog Section

    #This method is for when I want to simply show a
    #Dialog box for places I have not done anything yet.
    #(Vivek commented not needed)
    #def showDialogAlert(self):
    #    tk.messagebox.showwarning(title="Button Clicked", message="This button click has not been handled yet.")

    def showAboutAlert(self):
        tk.messagebox.showwarning(title="About Lefties", message ="Example Database Program for CTAERN Class.")

    def showConfirmAlert(self):
        s = "Press OK to delete record for: \n" + self.entryFirstName.get() + " " + self.entryLastName.get()
        if (tk.messagebox.askyesnocancel(title="Confirm Delete", message = s)):
            answer = self.deleteRecord(self.id)  #We will come back to explain this
            self.lblFeedback.config(text=answer)
        else:
            self.lblFeedback.config(text="Deletion Cancelled")

    #(Vivek moved to change menubar when connected/disconnected)
    def addMenuBar (self):
        #**************Setting up the main menu*********
        self.menuBar = tk.Menu(self.mainWin)#(Vivek camelCased)
        self.connectMenu = tk.Menu(self.menuBar, tearoff=0)#(Vivek camelCased)
        if(self.leftyDb.connected):
            self.connectMenu.add_command(label="Disconnect", command=self.connectionManager)#(Vivek camelCased)
            self.connectMenu.add_command(label="Exit",command=self.mainWin.destroy)#(Vivek camelCased)
            self.menuBar.add_cascade(label="File", menu=self.connectMenu)#(Vivek camelCased)

            self.recordMenu = tk.Menu(self.menuBar, tearoff=0)#(Vivek camelCased)
            self.recordMenu.add_command(label="New Lefty", command=lambda:self.insertRec())#(Vivek camelCased)
            self.recordMenu.add_command(label="Save Lefty", command=self.saveChangedRecord)#(Vivek camelCased)
            self.recordMenu.add_command(label="Delete Current Lefty", command=self.showConfirmAlert)#(Vivek camelCased)
            self.menuBar.add_cascade(label="Records", menu=self.recordmenu)#(Vivek camelCased)

            self.navMenu = tk.Menu(self.menuBar, tearoff=0)#(Vivek camelCased)
            self.navMenu.add_command(label="First Record", command = lambda: [self.setToZero(), self.showRecord(0)])#(Vivek camelCased)
            self.navMenu.add_command(label="Prior Record", command = lambda: self.jumpRec(-1))#(Vivek camelCased)
            self.navMenu.add_command(label="Next Record", command = lambda: self.jumpRec(1))#(Vivek camelCased)
            self.navMenu.add_command(label="Last Record", command = lambda: self.jumpRec(len(self.leftyDb.records)-1))#(Vivek camelCased)
            self.menuBar.add_cascade(label="Navigate", menu=self.navmenu)#(Vivek camelCased)

            self.helpMenu = tk.Menu(self.menuBar, tearoff=0)#(Vivek camelCased)
            self.helpMenu.add_command(label="About", command=self.showAboutAlert)#(Vivek camelCased)
            self.menuBar.add_cascade(label="Help", menu=self.helpMenu)#(Vivek camelCased)

        else:
            self.connectMenu = tk.Menu(self.menuBar, tearoff=0)#(Vivek camelCased)
            self.connectMenu.add_command(label="Connect", command=self.connectionManager)
            self.connectMenu.add_command(label="Exit",command=self.mainWin.destroy)
            self.menuBar.add_cascade(label="File", menu=self.connectMenu)#(Vivek camelCased)

            self.helpmenu = tk.Menu(self.menuBar, tearoff=0)#(Vivek camelCased)
            self.helpmenu.add_command(label="About", command=self.showAboutAlert)
            self.menuBar.add_cascade(label="Help", menu=self.helpmenu)#(Vivek camelCased)

        #Mounting the menubar onto the main window
        self.mainWin.config(menu=self.menuBar)#(Vivek camelCased)


    #This section controlls our connection to the database
    def connectionManager(self):
        if(not self.leftyDb.connected):
            answer = self.leftyDb.connect()
            self.connectButton.config(activebackground = "green", fg = "black", text = "Disconnect")
            self.leftyDb.connected = True
            self.leftyDb.load()
            self.showRecord(0)
            self.lblFeedback.config(text = answer)
            #(Vivek added to show new/delete/save lefty buttons when connected)
            self.btnNew.place(x=325, y=15)
            self.btnDelete.place(x=445, y=15)
            self.btnSaveCommit.place(x=565, y=15)
            self.addMenuBar()
        else:
            answer = self.leftyDb.disconnect()
            self.connectButton.config(activebackground = "gray", fg = "black", text = "Connect")
            self.leftyDb.connected = False
            self.currentRec = 0
            self.lblFeedback.config(text = answer)
            #(Vivek added to hide new/delete/save lefty buttons when disconnected)
            self.btnNew.place_forget()
            self.btnSaveCommit.place_forget()
            self.btnDelete.place_forget()
            self.addMenuBar()


    #Create Read Update Delete (CRUD) Section

    #Create Part 1
    def setBlanks(self):
        self.entryFirstName.delete(0, tk.END)
        self.entryLastName.delete(0, tk.END)
        self.entryAge.delete(0, tk.END)

    #hide buttons
    def hide(x):
        x.pack_forget()

    #Create Part 2
    def insertRec(self):
        if (not self.midInsert):
            self.setBlanks()
            self.btnNew.config(text = "Commit Insertion")
            #(Vivek added to hide delete/save lefty buttons before commit)
            self.btnSaveCommit.place_forget()
            self.btnDelete.place_forget()
            self.midInsert = True
        else:
            self.retrieveRecord()
            answer = self.leftyDb.insert()
            self.btnNew.config(text = "New Lefty")
            #(Vivek added to show delete/save lefty buttons after commit)
            self.btnDelete.place(x=445, y=15)
            self.btnSaveCommit.place(x=565, y=15)
            self.midInsert = False
            self.lblFeedback.config(text=answer)

    #Read Section of CRUD
    def retrieveRecord(self):
        self.fn = self.entryFirstName.get()
        self.ln = self.entryLastName.get()
        self.a = self.entryAge.get()
        #Print Daemon to verify data
        print(self.fn)
        print(self.ln)
        print(self.a)
        print("END Daemon")
        self.leftyDb.insertRec = [self.fn, self.ln, self.a]

    def showRecord(self, recNum):
        self.holdRecord = self.leftyDb.records[recNum]
        (self.id, self.fn, self.ln, self.a) = self.holdRecord
        #Daemon print
        print(self.fn)

        self.entryFirstName.delete(0, tk.END)
        self.entryFirstName.insert(0, self.fn)

        self.entryLastName.delete(0, tk.END)
        self.entryLastName.insert(0, self.ln)

        self.entryAge.delete(0, tk.END)
        self.entryAge.insert(0, self.a)

        self.lblFeedback.config(text = "Record ID: " + str(self.id))

    #Update part of CRUD
    def saveChangedRecord(self):
        self.id = self.id
        self.fn = self.entryFirstName.get()
        self.ln = self.entryLastName.get()
        self.a = self.entryAge.get()

        self.leftyDb.updateRec = [self.id, self.fn, self.ln, self.a]
        self.answer = self.leftyDb.updateChangedRec()

        answer = self.leftyDb.load()
        self.showRecord(0)
        self.lblFeedback.config(text= self.answer)

    #Deleting a record
    def deleteRecord(self, id):
        #Piped dialog box to delete flow
        answer = self.result = self.leftyDb.deleteRecord(id)
        self.lblFeedback.config(text = self.answer)

        #Protects us from an out of bounds error on edge case
        self.currentRec = self.currentRec - 1

        self.lblFeedback.config(text=answer)

    #Navigation Section
    def jumpRec(self, jump):
        self.currentRec += jump
        if (self.currentRec >= len(self.leftyDb.records)):
            self.currentRec = len(self.leftyDb.records)-1
        if (self.currentRec < 0):
            self.currentRec = 0
        self.showRecord(self.currentRec)

    def setToZero(self):
        self.currentRec = 0

    #Nice to have for standing up a GUI
    def doNothing(self):
        pass

    #*****************************
    # Constructor Section
    #*****************************

    def __init__(self):

        #Initialization of variables
        self.currentRec = 0
        self.holdRecord = (0,"","",0)
        self.passRec = (0,"","",0)
        self.midInsert = False
        self.answer = ""

        #Instantiate containee database class into an object here,
        # and hold it as an object field of THIS class
        self.leftyDb = Lefty()

        #Initialize Tkinter and set the title and version
        self.mainWin = tk.Tk()
        self.mainWin.title("Lefty Tracking Db V1.0")
        #**************Setting up the main menu*********

        self.addMenuBar()

        #*********** Frame 1  "Frame Object in Tk() ***********"
        self.frame = tk.Frame(self.mainWin, width=1000, height=100)

        #Using canvas object to hold and display a background image in the top frame
        self.jetImage = tk.PhotoImage(file="plane.png")
        self.canvas = tk.Canvas(self.frame, width=1000, height=100)
        self.canvas.pack(fill="both", expand=True)
        self.canvas.create_image(0,0, image=self.jetImage, anchor="nw")

        #Label widget for the top frame
        #Pattern: Build, then Place
        self.lblWelcome = tk.Label(self.frame, text="Lefty Database", fg="black", bg="light gray")
        self.lblWelcome.place(x=440, y=82)

        #Connection button for the top frame
        self.connectButton = tk.Button(self.frame,
                                        text="Connect",
                                        width=10,
                                        height=2,
                                        bg="gray",
                                        fg="black",
                                        command=self.connectionManager)
        self.connectButton.place(x=100, y=20)
        #***********Second frame - the display frame
        self.displayFrame = tk.Frame(self.mainWin, width=1000, height=100)

        #FirstName
        self.lblFirstName = tk.Label(self.displayFrame,
                                    text="First Name")
        self.entryFirstName = tk.Entry(self.displayFrame, bd=3, relief="sunken")

        #LastName
        self.lblLastName = tk.Label(self.displayFrame,
                                    text="Last Name")
        self.entryLastName = tk.Entry(self.displayFrame, bd=3, relief="sunken")

        #Age
        self.lblAge = tk.Label(self.displayFrame,
                                    text="Age")
        self.entryAge = tk.Entry(self.displayFrame, bd=3, relief="sunken")

        #Widget placement for frame 2
        self.lblFirstName.place(x=20, y=20)
        self.entryFirstName.place(x=100, y=20)

        self.lblLastName.place(x=20, y=43)
        self.entryLastName.place(x=100, y=45)

        self.lblAge.place(x=358, y=25)
        self.entryAge.place(x=350, y=45, width=50)

        #***************Third Frame "Play Head"

        self.playHead = tk.Frame(self.mainWin, height=66, width=1000, bg="green")

        self.btnStart = tk.Button(self.playHead,
                                text="|<",
                                width=5,
                                height=2,
                                bg="gray",
                                fg="black",
                                command=lambda: [self.setToZero(), self.showRecord(0)])
        self.btnBackFast = tk.Button(self.playHead,
                                text="<<",
                                width=5,
                                height=2,
                                bg="gray",
                                fg="black",
                                command=lambda: self.jumpRec(-5))
        self.btnBack = tk.Button(self.playHead,
                                text="<",
                                width=5,
                                height=2,
                                bg="gray",
                                fg="black",
                                command=lambda: self.jumpRec(-1))
        self.btnFwd = tk.Button(self.playHead,
                                text=">",
                                width=5,
                                height=2,
                                bg="gray",
                                fg="black",
                                command=lambda: self.jumpRec(1))
        self.btnFwdFast = tk.Button(self.playHead,
                                text=">>",
                                width=5,
                                height=2,
                                bg="gray",
                                fg="black",
                                command=lambda: self.jumpRec(5))
        self.btnEnd = tk.Button(self.playHead,
                                text=">|",
                                width=5,
                                height=2,
                                bg="gray",
                                fg="black",
                                command=lambda: self.jumpRec(len(self.leftyDb.records)-1))

        #Display Feedback Label
        self.lblFeedback = tk.Label(self.playHead, text="Press Connect to Begin.",
                                                    width=20, bg="white", fg="brown", relief="sunken")
        self.lblFeedback.place(x=700, y=16)

        #Place the play head
        self.btnStart.place(x=350, y=15)
        self.btnBackFast.place(x=400, y=15)
        self.btnBack.place(x=450, y=15)
        self.btnFwd.place(x=500, y=15)
        self.btnFwdFast.place(x=550, y=15)
        self.btnEnd.place(x=600, y=15)

        #************Fourth Frame
        self.buttonFrame = tk.Frame(self.mainWin, width=1000, height=65, bg="yellow")
        self.btnNew = tk.Button(self.buttonFrame,
                                    text="New Lefty",
                                    width=12,
                                    height=2,
                                    bg="gray",
                                    fg="black",
                                    command=lambda: self.insertRec())
        self.btnSaveCommit = tk.Button(self.buttonFrame,
                                    text="Save Lefty",
                                    width=12,
                                    height=2,
                                    bg="gray",
                                    fg="black",
                                    command=self.saveChangedRecord)
        self.btnDelete = tk.Button(self.buttonFrame,
                                    text = "Delete Lefty",
                                    width=12,
                                    height=2,
                                    bg="gray",
                                    fg="black",
                                    command=self.showConfirmAlert)

        #Placing final buttons
        #self.btnNew.place(x=325, y=15) #(Vivek moved to connectionManager)
        #self.btnDelete.place(x=445, y=15) #(Vivek moved to connectionManager)
        #self.btnSaveCommit.place(x=565, y=15) #(Vivek moved to connectionManager)

        #***********FRAME GRID PLACEMENT IN MAIN WINDOW OBJECT
        self.frame.grid(row=1, column=0)
        self.displayFrame.grid(row=2, column=0)
        self.buttonFrame.grid(row=3, column=0)
        self.playHead.grid(row=4, column=0)

        #Run the Tk LOOP!!!!
        self.mainWin.mainloop()
