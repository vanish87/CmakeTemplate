fmport subprocess
import os
buildPath="BuildLinux/External"
if not os.path.exists(buildPath):
	os.makedirs(buildPath, exist_ok=True)
subprocess.run(["cmake", "../../Source/ExternalLibs", "-DCMAKE_BUILD_TYPE=Debug"], cwd=buildPath)
subprocess.run(["cmake", "--build", ".", "--target", "install", "--config", "Debug"], cwd=buildPath)
subprocess.run(["cmake", "../../Source/ExternalLibs", "-DCMAKE_BUILD_TYPE=Release"], cwd=buildPath)
subprocess.run(["cmake", "--build", ".", "--target", "install", "--config", "Release"], cwd=buildPath)
os.system("pause")
