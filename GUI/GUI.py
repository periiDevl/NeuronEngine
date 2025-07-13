import Alert
import tkinter as tk
from tkinter import font
from tkinter import ttk  # For modern themed widgets

Alert.startingMessage()
root = tk.Tk()
root.title("Neuron Engine - Jonathan Peri")
root.geometry("900x620")
root.resizable(False, False) 
title_font = font.Font(weight="bold", size=20)
tk.Label(root,
                text="Neuron Engine - Graph test",
                font=title_font).pack()
create_btn = tk.Button(root,
                        text="Terminal",
                        font=("Arial", 8, "bold"),
                        bg="#000000",
                        fg="white",
                        activebackground="#353535",
                        activeforeground="white",
                        relief="flat",
                        borderwidth=0,
                        padx=10,
                        pady=10,
                        cursor="hand2",
                        command=root.destroy)
create_btn.place(x=0, y=80)

canvas_width = 600
canvas_height = 400
canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg="white")
canvas.pack(padx=20, pady=20)

tk.mainloop()