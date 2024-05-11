import os
from PIL import Image

# Loop through each subdirectory in the trainingSet directory
for digit in range(10):
    directory = f"trainingSet/{digit}/"
    output_file = open(f"trainingSet_{digit}.matrix", "w")

    # Loop through each file in the subdirectory
    for filename in os.listdir(directory):
        if filename.endswith(".jpg"):
            img = Image.open(directory + filename)
            pixels = list(img.getdata())

            # Write each pixel value in a column
            for pixel in pixels:
                output_file.write(str(pixel) + "\n")

            # Add a line space after each column
            output_file.write("\n")

    output_file.close()