import os
import time
import sys
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

folder_to_monitor = sys.argv[1]

file_folder_mapping = {
        '.png' : 'images',
        '.jpg' : 'images',
        '.jpeg' : 'images',
        '.gif' : 'images',
        '.pdf' : 'pdfs',
        '.mp4' : 'videos',
        '.mp3' : 'audio',
        '.zip' : 'bundles',
        '.c'    : 'Code',
        '.cpp'  : 'Code',
        '.py'   : 'Code',
        '.java' : 'Code',
        '.txt'  : 'Code',
        '.doc'  : 'documents',
        '.docx' : 'documents',
        '.xls'  : 'documents',
        '.xlsx' : 'documents',
        '.ppt'  : 'documents',
        '.pptx' : 'documents',
        '.exe'  : 'executables',
        '.msi'  : 'installers',
        '.iso'  : 'installers',
        '.deb'  : 'installers',
        '.rpm'  : 'installers',
        '.dmg'  : 'installers',
        '.apk'  : 'android',
        '.jar'  : 'java',
        '.class' : 'Code',
        '.jar'  : 'java',
        '.pyc'  : 'Code',
        '.o'    : 'Code',
        '.so'   : 'Code',
        '.a'    : 'Code',
        '.dll'  : 'Code\libs',

}


class DownloadedFileHandler(FileSystemEventHandler):

    def on_created(self, event):
        if any(event.src_path.endswith(x) for x in file_folder_mapping):
            parent = os.path.join(os.path.dirname(os.path.abspath(event.src_path)), file_folder_mapping.get(f".{event.src_path.split('.')[-1]}"))
            if not os.path.exists(parent):
                os.makedirs(parent)
            os.rename(event.src_path, os.path.join(parent, os.path.basename(event.src_path)))



event_handler = DownloadedFileHandler()

observer = Observer()
observer.schedule(event_handler, folder_to_monitor, recursive=True)
print("Monitoring started")
observer.start()

try:
    while True:
        time.sleep(10)
except KeyboardInterrupt:
    observer.stop()
observer.join()



def main():
    pass


if __name__ == '__main__':
    pass