# FaceRecognition-OpenCV
My pet project for face recognition using OpenCV. You can just open `windows-assets` directory and run `FaceRecognition.exe`

## How To Use
Build project using command line:
```console
$ cmake -S <src> -B <build> -D OPEN_CV_LIB_PATH=<opencv_build_path>
$ cmake --build <build> --config Release
```
where:
* src - path to the source files
* build - path to the build directory
* opencv_build_path - path to opencv build directory

You can also use template of a script `script-build.bat` to build the project

Or just open `windows-assets` directory and run `FaceRecognition.exe`
