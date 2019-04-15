import subprocess
import os
subprocess.run(["cmake", "../Source/ExternalLibs"], cwd="build/")
subprocess.run(["cmake", "--build", ".", "--target", "install"], cwd="build/")
os.system("pause")