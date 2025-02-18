// Copyright (c) 2024 Gorilla
//
// Licensed under the Apache License, Version 2.0 (the "License");
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: Gorilla <gorilla_robot@126.com>

#include "rclcpp/rclcpp.hpp"

class HelloWorld : public rclcpp::Node {
 public:
  HelloWorld(const std::string& name);
  ~HelloWorld() = default;  
};  // class HelloWorld

HelloWorld::HelloWorld(const std::string& name) : Node(name) {
  RCLCPP_INFO(this->get_logger(), "The node is %s.", name.c_str());
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<HelloWorld>("hello_world");

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}