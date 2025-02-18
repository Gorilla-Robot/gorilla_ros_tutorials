from launch import LaunchDescription
from launch_ros.actions import Node
 
def generate_launch_description():  
  hello_world_node = Node(
    package = 'hello_world',
    executable = 'hello_world',
    output = 'screen'
  )

  return LaunchDescription([
    hello_world_node
  ])
