import os
import cv2
from ultralytics import YOLO
from tkinter import Tk, filedialog, Button, Label
from PIL import Image, ImageTk

# Define the base directory
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

# Load the YOLOv8 model
model_path = os.path.join(BASE_DIR, 'best.pt')

model = YOLO(model_path)

def load_and_predict():
    # Open file dialog to select image
    img_path = filedialog.askopenfilename(title="Select an Image", filetypes=[("Image files", "*.jpg;*.jpeg;*.png")])
    if img_path:
        # Read and preprocess the image
        img = cv2.imread(img_path)
        img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

        # Make predictions
        results = model(img_rgb)
        for result in results:
            boxes = result.boxes
            for box in boxes:
                x1, y1, x2, y2 = map(int, box.xyxy[0])
                label = box.cls[0]
                confidence = box.conf[0]
                class_name = model.names[int(label)]
                cv2.rectangle(img, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.putText(img, f'{class_name} {confidence:.2f}', (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)

        # Convert to PIL Image for Tkinter
        img_pil = Image.fromarray(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
        img_tk = ImageTk.PhotoImage(img_pil)

        # Display in Tkinter
        result_label.config(image=img_tk)
        result_label.image = img_tk

# Create the main application window
root = Tk()
root.title("Strawberry Harvester Prediction")
root.geometry("800x600")

# Add a button to load and predict an image
load_button = Button(root, text="Select a Strawberry Image", command=load_and_predict)
load_button.pack(pady=30) 

# Add a label to display the results
result_label = Label(root)
result_label.pack()

# Start the Tkinter main loop
root.mainloop()