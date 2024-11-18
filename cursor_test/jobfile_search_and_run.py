import os
import subprocess

def find_and_convert_job_files(start_path):
    """Finds all .job files in the directory tree starting at start_path and converts them."""
    for root, dirs, files in os.walk(start_path):
        for file in files:
            if file.endswith('.job'):
                job_file_path = os.path.join(root, file)
                scv_file_path = os.path.join(root, file.replace('.job', '.scv'))
                # Check if the corresponding .scv file exists
                if not os.path.exists(scv_file_path):
                    # Run jobfile_manage.py with the found job file
                    subprocess.run(['python', 'jobfile_manage.py', job_file_path])

if __name__ == "__main__":
    # Start searching from the current directory
    find_and_convert_job_files('.')
