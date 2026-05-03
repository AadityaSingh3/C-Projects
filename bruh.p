import tensorflow as tf
import numpy as np
import cv2
# ... (imports)

# ... (Configuration and Model Loading)

# Load and Preprocess Image
img_path = "test_image.jpg"
img = cv2.imread(img_path)

if img is None:
    print(f"Error: Could not read image from {img_path}")
    exit()

# **Crucial Fix:** Convert BGR (OpenCV) to RGB (Keras)
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

img = cv2.resize(img, (224, 224))
img = img / 255.0
img = np.expand_dims(img, axis=0) # Use expand_dims for clarity

# Prediction
prediction = model.predict(img)
# ... (Interpretation)