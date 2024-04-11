import cv2
import os
import numpy as np

def convert_to_transparent(img, bg_color=(0, 0, 0), tolerance=1):
    tmp = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    _,alpha = cv2.threshold(tmp,0,255,cv2.THRESH_BINARY)
    b, g, r = cv2.split(img)
    rgba = [b,g,r, alpha]
    dst = cv2.merge(rgba,4)
    
    return dst

def process_png_files(input_folder, output_folder, bg_color=(0, 0, 0), tolerance=30):
    # Create the output folder if it doesn't exist
    os.makedirs(output_folder, exist_ok=True)
    
    # Get a list of all PNG files in the input folder
    png_files = [f for f in os.listdir(input_folder) if f.endswith('.png')]
    
    for png_file in png_files:
        # Read PNG file using OpenCV
        png_path = os.path.join(input_folder, png_file)
        img = cv2.imread(png_path)
        
        if img is not None:
            # Convert specified background color to transparent
            img_with_alpha = convert_to_transparent(img, bg_color, tolerance)
            
            # Construct the output PNG file path
            output_path = os.path.join(output_folder, png_file)
            
            # Save the image with transparent background
            cv2.imwrite(output_path, img_with_alpha)
            
            print(f"Processed {png_file}")
        else:
            print(f"Error: Unable to read {png_file}")


# Example usage
input_folder = './output'
output_folder = './out'
background_color = (0, 0, 0)  # Specify the background color to remove (e.g., pure black)

process_png_files(input_folder, output_folder, background_color)