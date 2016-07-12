//
// Created by marius on 16.04.16.
//

#include "catkinpkg_framework/framework_processor.h"

namespace framework {

FrameworkProcessor::FrameworkProcessor(const ros::NodeHandle& nodehandle,
                                       const ParameterBag& params_bag):
    nh_(nodehandle),
    it_(nh_),
    parameter_(params_bag) {
  ROS_DEBUG("Framework Processor started!");

  // Create ROS subscriber
  sub_cam_ = nh_.subscribe(parameter_.sub_rostopic_cam,
                           parameter_.queue_size_sub_cam,
                           &FrameworkProcessor::CallbackImg, this);
  sub_img_ = it_.subscribe(parameter_.sub_rostopic_img,
                           parameter_.queue_size_sub_img,
                           &FrameworkProcessor::CallbackImg, this);

  // Create ROS publisher
  pub_objects_ = nh_.advertise<std_msgs::Float64>(
      parameter_.pub_rostopic_objects,
      parameter_.queue_size_pub_objects);
  pub_img_ = it_.advertise(parameter_.pub_rostopic_img,
                           parameter_.queue_size_pub_img);
}

FrameworkProcessor::~FrameworkProcessor(){
}

void FrameworkProcessor::CallbackImg(const sensor_msgs::ImageConstPtr &im_msg) {
  ROS_DEBUG("Image received!");
}

} // namespace framework