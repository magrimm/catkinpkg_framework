//
// Created by marius on 16.04.16.
//

#include "catkinpkg_framework/framework_processor.h"

namespace framework {

void InitializeParameters(const ros::NodeHandle& nh, ParameterBag* parameter) {
  // Retrieve all parameters or set to default
  nh.param("subscribed_rostopic_img", parameter->sub_rostopic_img,
           kDefaultImageSubTopic);
  nh.param("queue_size_subscriber_img", parameter->queue_size_sub_img,
           kDefaultImageSubQueueSize);
  nh.param("subscribed_rostopic_cam", parameter->sub_rostopic_cam,
           kDefaultCamSubTopic);
  nh.param("queue_size_subscriber_cam", parameter->queue_size_sub_cam,
           kDefaultCamSubQueueSize);
  nh.param("pub_rostopic_objects", parameter->pub_rostopic_objects,
           kDefaultObjectsPubTopic);
  nh.param("queue_size_pub_objects", parameter->queue_size_pub_objects,
           kDefaultObjectsPubQueueSize);
  nh.param("pub_rostopic_img", parameter->pub_rostopic_img,
           kDefaultObjectsPubTopic);
  nh.param("queue_size_pub_img", parameter->queue_size_pub_img,
           kDefaultObjectsPubQueueSize);
}

} // namespace framework

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "catkinpkg_framework_node");
  ros::NodeHandle nh;

  // Initialize parameter structure
  framework::ParameterBag parameter;
  framework::InitializeParameters(nh, &parameter);

  // Construct class detection_processor with NodeHandle and parameter structure
  framework::FrameworkProcessor framework(nh, parameter);

  // Relative path to package
  std::string path = ros::package::getPath("catkinpkg_framework");

  // Spin
  ros::spin ();
}
