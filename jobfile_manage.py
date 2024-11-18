import csv
import os

# Global variable for delimiters
DELIMITERS = ['+_+']  # Add more delimiters if needed

def detect_delimiter(line):
    """Detects which delimiter is used in the line."""
    for delimiter in DELIMITERS:
        if delimiter in line:
            return delimiter
    return None

def convert_job_to_csv(job_file_path):
    """Converts a .JOB file to a CSV file."""
    # Generate CSV file path by replacing the .job extension with .csv
    csv_file_path = os.path.splitext(job_file_path)[0] + '.csv'
    
    with open(job_file_path, 'r', encoding='utf-8') as job_file:
        first_line = job_file.readline()
        delimiter = detect_delimiter(first_line)
        
        if not delimiter:
            raise ValueError("No valid delimiter found in the file.")
        
        job_file.seek(0)  # Reset file pointer to the beginning
        reader = csv.reader(job_file, delimiter=delimiter)
        
        with open(csv_file_path, 'w', newline='', encoding='utf-8') as csv_file:
            writer = csv.writer(csv_file)
            for row in reader:
                writer.writerow(row)

if __name__ == "__main__":
    # Example usage
    convert_job_to_csv('example.job')
