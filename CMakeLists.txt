# CMakeList.txt: edge-intelligent-camera 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("edge-intelligent-camera")

# 将源代码添加到此项目的可执行文件。
add_executable (edge-intelligent-camera "edge-intelligent-camera.cpp" "edge-intelligent-camera.h" "alarm/alarm.cpp" "algorithm/algorithm.cpp" "device/device.cpp" "rule/rule.cpp" "rule/base/context.cpp" "rule/common/gis/location.cpp" "rule/common/gis/point.cpp" "rule/rule.h" "rule/util/gisutils.h" "rule/util/readjsonutil.h" "rule/util/readjsonutil.cpp" "rule/common/gis/location.h" "rule/common/gis/point.h" "rule/base/context.h" "lib/OpenCV2.4.10/include/facedetect-dll.h" "lib/OpenCV2.4.10/include/opencv/cv.h" "lib/OpenCV2.4.10/include/opencv/cvaux.h" "lib/OpenCV2.4.10/include/opencv/cvwimage.h" "lib/OpenCV2.4.10/include/opencv/cxcore.h" "lib/OpenCV2.4.10/include/opencv/cxmisc.h" "lib/OpenCV2.4.10/include/opencv/highgui.h" "lib/OpenCV2.4.10/include/opencv/ml.h" "lib/OpenCV2.4.10/include/opencv2/cvconfig.h" "lib/OpenCV2.4.10/include/opencv2/photo_c.h" "lib/OpenCV2.4.10/include/opencv2/core/core_c.h" "lib/OpenCV2.4.10/include/opencv2/core/types_c.h" "lib/OpenCV2.4.10/include/opencv2/highgui/cap_ios.h" "lib/OpenCV2.4.10/include/opencv2/highgui/highgui_c.h" "lib/OpenCV2.4.10/include/opencv2/highgui/ios.h" "lib/OpenCV2.4.10/include/opencv2/imgproc/imgproc_c.h" "lib/OpenCV2.4.10/include/opencv2/imgproc/types_c.h" "lib/OpenCV2.4.10/include/opencv2/photo/photo_c.h" "include/json/allocator.h" "include/json/assertions.h" "include/json/config.h" "include/json/forwards.h" "include/json/json.h" "include/json/json_features.h" "include/json/reader.h" "include/json/value.h" "include/json/version.h" "include/json/writer.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET edge-intelligent-camera PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
