import os


def remove_files_with_extension(extension):
    for root, dirs, files in os.walk('.'):
        if 'blank_project' in dirs:
            # Exclude the "blank_project" folder from processing
            dirs.remove('blank_project')
        for file in files:
            if file.endswith(extension):
                file_path = os.path.join(root, file)
                print(f"Removing: {file_path}")
                os.remove(file_path)


extensions = ['layout', 'cbp', 'depend', 'bmarks', 'bin']

for extension in extensions:
    remove_files_with_extension(f".{extension}")

print("File removal completed.")
