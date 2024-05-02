import tkinter as tk

def draw_sierpinski(canvas, x1, y1, x2, y2, x3, y3, depth):
    if depth == 0:
        canvas.create_polygon(x1, y1, x2, y2, x3, y3, fill='red')
    else:
        x12 = (x1 + x2) / 2
        y12 = (y1 + y2) / 2
        x23 = (x2 + x3) / 2
        y23 = (y2 + y3) / 2
        x31 = (x3 + x1) / 2
        y31 = (y3 + y1) / 2
        draw_sierpinski(canvas, x1, y1, x12, y12, x31, y31, depth - 1)
        draw_sierpinski(canvas, x12, y12, x2, y2, x23, y23, depth - 1)
        draw_sierpinski(canvas, x31, y31, x23, y23, x3, y3, depth - 1)

def on_generate_clicked():
    depth = int(entry.get())
    canvas.delete(tk.ALL)
    draw_sierpinski(canvas, 10, 390, 390, 390, 200, 10, depth)

root = tk.Tk()
root.title("Sierpinski Triangle")

label = tk.Label(root, text="Enter depth:")
label.pack()

entry = tk.Entry(root)
entry.pack()

button = tk.Button(root, text="Generate", command=on_generate_clicked)
button.pack()

canvas = tk.Canvas(root, width=400, height=400)
canvas.pack()

root.mainloop()
