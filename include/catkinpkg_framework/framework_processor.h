//
// Created by marius on 16.04.16.
//

#ifndef CATKINPKG_FRAMEWORK_FRAMEWORKPROCESSOR_H
#define CATKINPKG_FRAMEWORK_FRAMEWORK_PROCESSOR_H

#include <ros/ros.h>
#include <ros/package.h>
#include <sensor_msgs/Image.h>

#include <iostream>
#include <vector>

#include "catkinpkg_framework/parameter/parameter_bag.h"

// Default values
static const std::string kDefaultImageSubTopic = "/camX/image_raw";
static const int kDefaultImageSubQueueSize = 1;
static const std::string kDefaultObjectsPubTopic = "detection_result";
static const int kDefaultObjectsPubQueueSize = 500;
static const std::string kDefaultCamSubTopic = "camera_info";
static const int kDefaultCamSubQueueSize = 1;
static const std::string kDefaultImagePath = "/Data/circles_rectangles.jpg";

class FrameworkProcessor
{
public:
  // Constructor with nodehandle and parameters
  FrameworkProcessor (ros::NodeHandle nh, ParameterBag parameter);
  virtual ~FrameworkProcessor();

  // Callback
  void CallbackImg (const sensor_msgs::ImageConstPtr &a_image_msg);

private:
  ros::NodeHandle nh_;
  ParameterBag parameter_;
  ros::Subscriber sub_img_;
};


#endif //CATKINPKG_FRAMEWORK_FRAMEWORKPROCESSOR_H
