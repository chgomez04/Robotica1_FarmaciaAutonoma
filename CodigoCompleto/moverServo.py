#libreria interfaz
#from tkinter import Label, Tk, PhotoImage, Button

from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import tkinter as tk


#Libreria Arduino
import serial
import time
import datetime

class MainFrame(Frame):
    def __init__(self, master=None):
        super().__init__(master, width=1150, height=650,bg="gray7")                
        self.master = master 
        self.arduino = serial.Serial("COM10",9600,timeout=1.0)
        self.pack()
        time.sleep(1)
        self.value_mot0 = StringVar()
        self.value_mot1 = StringVar()
        self.value_mot2 = StringVar()
        self.value_mot3 = StringVar()
        

        

        self.create_widgets()

    def fEnviaMot0(self):
        #time.sleep(2)
        cad = ""
        cad = "mot0:" + self.value_mot0.get()
        self.arduino.write(cad.encode('ascii'))
        #self.txtres.insert(1.0,cad+"\n")
        print("cad", cad)

    def fEnviaMot1(self):
        #time.sleep(2)
        cad = ""
        cad = "mot1:" + self.value_mot1.get()
        self.arduino.write(cad.encode('ascii'))
        #self.txtres.insert(1.0,cad+"\n")

    def fEnviaMot2(self):
        #time.sleep(2)
        cad = ""
        cad = "mot2:" + self.value_mot2.get()
        self.arduino.write(cad.encode('ascii'))
        #self.txtres.insert(1.0,cad+"\n")

    def fEnviaMot3(self):
        #time.sleep(2)
        cad = ""
        cad = "mot3:" + self.value_mot3.get()
        self.arduino.write(cad.encode('ascii'))
        #self.txtres.insert(1.0,cad+"\n")

    def create_widgets(self):
        
        motores=Frame(self,width=350,height=620,bg='gray22')
        motores.place(x=10,y=10)

        Label(motores,text="MOTOR 0 ",fg="DeepSkyBlue",bg="gray22").place(x=10,y=30)
        self.scale0=Scale(motores, from_=0, to=180,orient='horizontal',tickinterval=30,
         length=220,variable=self.value_mot0,fg="white",bg="gray22")
        self.scale0.place(x=75,y=10)        
        self.m0=Button(motores,text="OK", command=self.fEnviaMot0,fg="white",bg="gray22")
        self.m0.place(x=310,y=30)

        Label(motores,text="MOTOR 1 ",fg="DeepSkyBlue",bg="gray22").place(x=10,y=100)
        self.scale1=Scale(motores, from_=0, to=180,orient='horizontal',tickinterval=30,
         length=220,variable=self.value_mot1,fg="white",bg="gray22")
        self.scale1.place(x=75,y=80)        
        self.m1=Button(motores,text="OK", command=self.fEnviaMot1,fg="white",bg="gray22")
        self.m1.place(x=310,y=100)

        Label(motores,text="MOTOR 2 ",fg="DeepSkyBlue",bg="gray22").place(x=10,y=170)
        self.scale2= Scale(motores, from_=0, to=180,orient='horizontal',tickinterval=30,
         length=220,variable=self.value_mot2,fg="white",bg="gray22")
        self.scale2.place(x=75,y=150)      
        self.m2=Button(motores,text="OK", command=self.fEnviaMot2,fg="white",bg="gray22")
        self.m2.place(x=310,y=170)

        Label(motores,text="MOTOR 3 ",fg="DeepSkyBlue",bg="gray22").place(x=10,y=240)
        self.scale3= Scale(motores, from_=0, to=180,orient='horizontal',tickinterval=30,
         length=220,variable=self.value_mot3,fg="white",bg="gray22")
        self.scale3.place(x=75,y=220)        
        self.m3=Button(motores,text="OK", command=self.fEnviaMot3,fg="white",bg="gray22")
        self.m3.place(x=310,y=240)

        

def main():
    root = Tk()
    root.wm_title("control de brazo robotico")
    app = MainFrame(root)
    #imagen=PhotoImage(file="E:/fiuna2_2021/R1/Proyecto/proyecto_V2/foto.gif")
    #Label(root,image=imagen).place(x=700,y=200)
    app.mainloop()
if __name__=="__main__":
    main()