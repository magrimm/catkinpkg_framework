//
// Created by marius on 16.04.16.
//

#ifndef CATKINPKG_FRAMEWORK_PARAMETER_BAG_H
#define CATKINPKG_FRAMEWORK_PARAMETER_BAG_H

#include <string>

struct ParameterBag
{
  // Parameter specific to parameter bag
  std::string node_name;

  std::string subscribed_rostopic_img;
  int queue_size_subscriber_img;

  std::string subscribed_rostopic_cam;
  int queue_size_subscriber_cam;

  std::string pub_rostopic_objects;
  int queue_size_pub_objects;

  std::string subscribed_rostopic_calib;
  int queue_size_subscriber_calib;
};

#endif //CATKINPKG_FRAMEWORK_PARAMETER_BAG_H
