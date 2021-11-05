import os
from typing import List, Dict
import shutil

class Dir:
    def __init__(self: "Dir", path: str):
        """
        Initializes the Directory
        @parem: path as string to the folder to be sorted
        """
        self.m_path: str = path
        self.m_object_list: list = os.listdir(self.m_path)

    def sort_directory(self: "Dir") -> None:
        self.m_dict_fileAndExtention: dict = self.split_extention()

        for name, extension in self.m_dict_fileAndExtention:
            if extension == "":
                continue

            if (os.path.exists(self.m_path + "/" + extension)):
                shutil.move(self.m_path + "/" + name + extension, self.m_path + "/" + extension + "/" + name + extension)

            else:
                os.mkdir(self.m_path + "/" + extension)
                shutil.move(self.m_path + "/" + name + extension, self.m_path + "/" + extension + "/" + name + extension)


    def split_extention(self: "Dir" ) -> map:
        """
        Splits the file name into name and extension
        @return: map with name and extension
        """
        return map(lambda x: os.path.splitext(x), self.m_object_list)


def main():
    dir = Dir("C:\Debloat")
    dir.sort_directory()



if __name__ == "__main__":
    main()