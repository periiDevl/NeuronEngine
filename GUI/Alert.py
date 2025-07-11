import tkinter as tk
from tkinter import font
from tkinter import ttk  # For modern themed widgets

root = tk.Tk()
root.title("Alert!")
root.geometry("400x280")
root.resizable(False, False) 

title_font = font.Font(weight="bold", size=10)
sub_title_font = font.Font(size=8)
contact_font = font.Font(weight="bold", size=8)
tk.Label(root,
        text="Neuron Engine is currently a work in progress.\nSome features may be unfinished,\nand you might encounter bugs or unexpected behavior.\n",
        font=title_font).pack()
tk.Label(root,
        text="Features that will be added in the future/release",
        font=sub_title_font).pack()

tk.Label(root,
        text="- Better optimized backpropagation", 
        font=sub_title_font).pack()
tk.Label(root,
        text="- Transformer Network", 
        font=sub_title_font).pack()
tk.Label(root,
        text="- Weights and parameter transfers to: C#/C++/Java/Python",
        font=sub_title_font).pack()
tk.Label(root,
        text="- Learning on different computers on LAN",
        font=sub_title_font).pack()
tk.Label(root,
        text="Contact: jonathan.peri56@gmail.com",
        font=title_font).pack()
custom_btn = tk.Button(root,
                      text="Understood",
                      font=("Arial", 12, "bold"),
                      bg="#be4242",
                      fg="white",
                      activebackground="#cc5959",
                      activeforeground="white",
                      relief="flat",
                      borderwidth=0,
                      padx=20,
                      pady=10,
                      cursor="hand2",
                    command=root.destroy)
custom_btn.pack(pady=10)
tk.mainloop()
