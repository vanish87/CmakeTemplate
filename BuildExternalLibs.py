import subprocess
import os
buildPath="Build/External"
if not os.path.exists(buildPath):
	os.makedirs(buildPath, exist_ok=True)
subprocess.run(["cmake", "../../Source/ExternalLibs", "-DCMAKE_BUILD_TYPE=Debug"], cwd=buildPath)
subprocess.run(["cmake", "--build", ".", "--target", "install"], cwd=buildPath)
os.system("pause")