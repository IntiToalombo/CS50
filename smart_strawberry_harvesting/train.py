'''
This file is used to train the model using the YOLOv8 library.
The library is used to train the model on the dataset and then test the model on the test dataset.
'''

import os
os.environ["KMP_DUPLICATE_LIB_OK"]="TRUE" 
from ultralytics import YOLO

# Define the base directory
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

# Define the path to the data.yaml file
datayml_path = os.path.join(BASE_DIR, 'Strawberry-pen.v1i.yolov8/data.yaml')

# Load the YOLOv8 model
model = YOLO('yolov8n.pt')

# Train the model on the strawberry dataset
model.train(data=datayml_path, epochs=1, imgsz=640, batch=16) 

# Save the model
model.save('strawberry_harvester1.pt')
