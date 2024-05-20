import os
import random
from PIL import Image

# Store all image paths and labels
image_paths = []
for digit in range(10):
    directory = f"trainingSet/{digit}/"
    for filename in os.listdir(directory):
        if filename.endswith(".jpg"):
            image_paths.append((directory + filename, digit))

# Shuffle the image paths
random.shuffle(image_paths)

# Open a single output file
output_file = open("trainingSet.matrix", "w")

# Loop through each image path
for image_path, label in image_paths:
    img = Image.open(image_path)
    pixels = list(img.getdata())

    # Write the label as the first entry
    output_file.write(str(label) + "\n")

    # Write each pixel value in a column, normalized to [0, 1]
    for pixel in pixels:
        output_file.write(str(pixel / 255.0) + "\n")

    # Add a line space after each column
    output_file.write("\n")

output_file.close()