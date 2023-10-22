git clone --recursive https://github.com/wangwenx190/framelesshelper.git

cmake -S . -B out -DCMAKE_PREFIX_PATH=C:\Qt\Qt5.14.2\5.14.2\msvc2017_64  -DCMAKE_INSTALL_PREFIX=C:\Users\17688\source\repos\karl-app\out\framelesshelper-install -DCMAKE_BUILD_TYPE=Release 

cmake --build out --config Release 
cmake --install out --config Release 

# YOUR_QT_SDK_DIR_PATH: the Qt SDK directory, something like "C:/Qt/6.5.1/msvc2019_64" or "/opt/Qt/6.5.1/gcc_64". Please change to your own path!
# WHERE_YOU_WANT_TO_INSTALL: the install directory of FramelessHelper, something like "../install". You can ignore this setting if you don't need to install the CMake package. Please change to your own path!
# PATH_TO_THE_REPOSITORY: the source code directory of FramelessHelper, something like "../framelesshelper". Please change to your own path!

in client:
cmake -S . -B out -DFramelessHelper_DIR=C:\Users\17688\source\repos\karl-app\out\framelesshelper-install\lib\cmake\FramelessHelper
