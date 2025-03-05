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
#include "std_msgs/msg/string.hpp"

namespace {
constexpr char kHelloWorldTopic[] = "/hello_world";
constexpr int kInfiniteSubscriberQueueSize = 0;
} // namespace 

class HelloWorldSubscriber : public rclcpp::Node {
 public:
  HelloWorldSubscriber(const std::string& name);
  ~HelloWorldSubscriber() = default;

 private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr hello_world_subscriber_ptr_;
  void HandleHelloWorldMessage(const std_msgs::msg::String::ConstSharedPtr& msg);   
};  // class HelloWorldSubscriber

HelloWorldSubscriber::HelloWorldSubscriber(const std::string& name) : Node(name) {
  RCLCPP_INFO(this->get_logger(), "The node is %s.", name.c_str());
  hello_world_subscriber_ptr_ = this->create_subscription<std_msgs::msg::String>
      (kHelloWorldTopic, kInfiniteSubscriberQueueSize, std::bind(&HelloWorldSubscriber::HandleHelloWorldMessage, this, std::placeholders::_1));
}

void HelloWorldSubscriber::HandleHelloWorldMessage(const std_msgs::msg::String::ConstSharedPtr& msg) {
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<HelloWorldSubscriber>("hello_world_subscriber");

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}