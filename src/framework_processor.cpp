//
// Created by marius on 16.04.16.
//

#include "catkinpkg_framework/framework_processor.h"

FrameworkProcessor::FrameworkProcessor(ros::NodeHandle nodehandle, ParameterBag params_bag):
    nh_(nodehandle),
    parameter_(params_bag) {
  ROS_DEBUG("Framework Processor started!");

  // Create Subscriber for the image
  sub_img_= nh_.subscribe(parameter_.subscribed_rostopic_img,
                                             parameter_.queue_size_subscriber_img,
                                             &FrameworkProcessor::CallbackImg,
                                             this);
}

FrameworkProcessor::~FrameworkProcessor(){
}

void FrameworkProcessor::CallbackImg(const sensor_msgs::ImageConstPtr &im_msg) {
  ROS_DEBUG("Image received!");
}
