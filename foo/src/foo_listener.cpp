#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <foo_msgs/msg/foo.hpp>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("foo_talker");
  auto sub = rclcpp::create_subscription<foo_msgs::msg::Foo>(
    node,
    "foo",
    10,
    [node](const foo_msgs::msg::Foo::SharedPtr msg) {
      RCLCPP_INFO(node->get_logger(), "Message received: %d", msg->bar);
    });

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
