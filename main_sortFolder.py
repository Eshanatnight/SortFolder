from watchdog.observers import Observer
import time
from watchdog.events import FileSystemEventHandler
import os
import json

class MyHandler(FileSystemEventHandler):
    i = 1

    def on_modified(self, event):
        for filename in os.listdir(folder_to_track):
            src = folder_to_track + "/" + filename 
            new_destination = folder_destination + "/" + filename 
            os.rename(src, new_destination)

def main():
    folder_to_track = "/Users/kalle/Desktop/myFolde" #path to be changed
    folder_destination = "/Users/kalle/Desktop/newFolder" #path to be chnaged
    
    event_handler = MyHandler()
    
    observer = Observer()
    observer.schedule(event_handler, folder_to_track, recursive=True)
    observer.start()
    
    try: 
        while True:
            time.sleep(20)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()


if __name__ == "__main__":
    main()

