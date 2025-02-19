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

#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace {
constexpr char kHelloWorldTopic[] = "/hello_world";
constexpr int kLatestOnlyPublisherQueueSize = 1;
} // namespace 

class HelloWorldPublisher : public rclcpp::Node {
 public:
  HelloWorldPublisher(const std::string& name);
  ~HelloWorldPublisher() = default;  

  void PublishInfo(const std_msgs::msg::String& msg); 
private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr hello_world_publisher_ptr_;  
};  // class HelloWorldPublisher

HelloWorldPublisher::HelloWorldPublisher(const std::string& name) : Node(name) {
  RCLCPP_INFO(this->get_logger(), "The node is %s.", name.c_str());
  hello_world_publisher_ptr_ = this->create_publisher<std_msgs::msg::String>(kHelloWorldTopic, kLatestOnlyPublisherQueueSize);
}

void HelloWorldPublisher::PublishInfo(const std_msgs::msg::String& msg) {
  hello_world_publisher_ptr_->publish(msg);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<HelloWorldPublisher>("hello_world_publisher");

  std_msgs::msg::String messgae;
  size_t count = 1;
  while (rclcpp::ok()) {
    messgae.data = "Hello world! " + std::to_string(++count);
    node->PublishInfo(messgae);

    std::this_thread::sleep_for(std::chrono::milliseconds(20)); // 20ms
  }

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}