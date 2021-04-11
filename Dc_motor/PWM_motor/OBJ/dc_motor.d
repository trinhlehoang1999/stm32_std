{
    // See https://go.microsoft.com/fwlink/?LinkId=733558 
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "g++.exe build active file",
            "command": "C:\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\g++.exe",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe",
                "-I","C:\\opencv\\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\\include",
                "-L","C:\\opencv\\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\\x64\\mingw\\bin",                
                "-llibopencv_calib3d411",
                "-llibopencv_core411",
                "-llibopencv_dnn411",
                "-llibopencv_features2d411",
                "-llibopencv_flann411",
                "-llibopencv_highgui411",
                "-llibopencv_imgcodecs411",
                "-llibopencv_imgproc411",
                "-llibopencv_ml411",
                "-llibopencv_objdetect411",
                "-llibopencv_photo411",
                "-llibopencv_stitching411",
                "-llibopencv_video411",
                "-llibopencv_videoio411"
            ],
            "options": {
                "cwd": "C:\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
                                                                                                                                                                                                                                                                       