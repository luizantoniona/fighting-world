import cv2
import os

def bmp_to_png(input_folder, output_folder):
    # Create the output folder if it doesn't exist
    os.makedirs(output_folder, exist_ok=True)
    
    # Get a list of all BMP files in the input folder
    bmp_files = [f for f in os.listdir(input_folder) if f.endswith('.bmp')]
    
    for bmp_file in bmp_files:
        # Read BMP file using OpenCV
        bmp_path = os.path.join(input_folder, bmp_file)
        img = cv2.imread(bmp_path)
        
        if img is not None:
            # Construct the output PNG file path
            png_file = os.path.splitext(bmp_file)[0] + '.png'
            png_path = os.path.join(output_folder, png_file)
            
            # Save the image as PNG using OpenCV
            cv2.imwrite(png_path, img, [cv2.IMWRITE_PNG_COMPRESSION, 9])
            
            print(f"Converted {bmp_file} to {png_file}")
        else:
            print(f"Error: Unable to read {bmp_file}")

# Example usage
input_folder = '.'
output_folder = './output'

bmp_to_png(input_folder, output_folder)