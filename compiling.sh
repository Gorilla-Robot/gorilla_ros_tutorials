#!/bin/bash
# env

# Desc: gorilla ros tutorials compiling and clear

case "$1" in
  make)
  	echo -e "\033[31m colcon build make... \033[0m"
    source /opt/ros/humble/setup.bash
    
    colcon build --cmake-args  -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON  
    ;;
  clear)
    echo -e "\033[31m clear... \033[0m"
    rm build -rf
    rm install -rf
    rm log -rf
    ;;
  *)
    echo "Usage: $0 {make|clear}"
    exit 1
esac

exit 0	
